    
var gl;
function initGL(canvas) {
    try {
        gl = canvas.getContext("webgl");
        gl.viewportWidth = canvas.width;
        gl.viewportHeight = canvas.height;
    } catch (e) {
    }
    if (!gl) {
        alert("There was a problem initializing WebGL.");
    }
}

// warning, this function must run on an HTTP server for chrome to access external files via jquery
function getShader(gl, type, shaderUrl) {
    var shader_str = ";";
    var shader;
    if (type == "fragment") {
        shader_str = $.ajax({ async: false, url: shaderUrl}).responseText;
        shader = gl.createShader(gl.FRAGMENT_SHADER);
    } else if (type == "vertex") {
        shader_str = $.ajax({ async: false, url: shaderUrl}).responseText;
        shader = gl.createShader(gl.VERTEX_SHADER);
    } else {
        alert("Unknown type: " + type);
        return null;
    }

    gl.shaderSource(shader, shader_str);
    gl.compileShader(shader);

    if (!gl.getShaderParameter(shader, gl.COMPILE_STATUS)) {
        alert(gl.getShaderInfoLog(shader));
        return null;
    }

    return shader;
}


function Renderable (iShape) {
    
    this.shape = iShape;
    
    this.vertexPositionBuffer = undefined;
    this.vertexIndexBuffer = undefined;
    this.vertexColorBuffer = undefined;
    this.vertexNormalBuffer = undefined;
    this.vertexTextureCoordBuffer = undefined;
    
    this.init = function () {
        //---- Position
        
        this.vertexPositionBuffer = gl.createBuffer();
        gl.bindBuffer(gl.ARRAY_BUFFER, this.vertexPositionBuffer);
        gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(this.shape.vertexPositions), gl.STATIC_DRAW);
        
        this.vertexPositionBuffer.itemSize = 3;
        var vertCount = this.shape.vertexPositions.length / this.vertexPositionBuffer.itemSize;
        this.vertexPositionBuffer.numItems = vertCount;
        
        //---- Topology 
        
        // Now send the element array to GL
        this.vertexIndexBuffer = gl.createBuffer();
        gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, this.vertexIndexBuffer);
        gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, new Uint16Array(this.shape.vertexIndices), gl.STATIC_DRAW);
        this.vertexIndexBuffer.numItems = this.shape.vertexIndices.length;
                
        //---- Color
        
        this.vertexColorBuffer = gl.createBuffer();
        gl.bindBuffer(gl.ARRAY_BUFFER, this.vertexColorBuffer);
        colors = []
        for (var i=0; i < vertCount; i++) {
          colors = colors.concat([1.0, 1.0, 1.0, 1.0]);
        }
        gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(colors), gl.STATIC_DRAW);
        this.vertexColorBuffer.itemSize = 4;
        this.vertexColorBuffer.numItems = vertCount;
        
        //---- Normal
        
        this.vertexNormalBuffer = gl.createBuffer();
        gl.bindBuffer(gl.ARRAY_BUFFER, this.vertexNormalBuffer);
        gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(this.shape.vertexNormals), gl.STATIC_DRAW);
        this.vertexNormalBuffer.itemSize = 3;
        this.vertexNormalBuffer.numItems = vertCount;
        
        //---- Texture
        this.vertexTextureCoordBuffer = gl.createBuffer();
        gl.bindBuffer(gl.ARRAY_BUFFER, this.vertexTextureCoordBuffer);
        gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(this.shape.vertexTextureCoords), gl.STATIC_DRAW);
        this.vertexTextureCoordBuffer.itemSize = 2;
        this.vertexTextureCoordBuffer.numItems = vertCount;//cubeTextureCoords.length / this.vertexTextureCoordBuffer.itemSize;
    }
    
    this.bindBuffers = function (shaderProgram) {
        
        // position
        gl.bindBuffer(gl.ARRAY_BUFFER, this.vertexPositionBuffer);
        gl.vertexAttribPointer(shaderProgram.vertexPositionAttribute, this.vertexPositionBuffer.itemSize, gl.FLOAT, false, 0, 0);
    
        // topology
        gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, this.vertexIndexBuffer);
        
        // color
        gl.bindBuffer(gl.ARRAY_BUFFER, this.vertexColorBuffer);
        gl.vertexAttribPointer(shaderProgram.vertexColorAttribute, this.vertexColorBuffer.itemSize, gl.FLOAT, false, 0, 0);

        //normals
        gl.bindBuffer(gl.ARRAY_BUFFER, this.vertexNormalBuffer);
        gl.vertexAttribPointer(shaderProgram.vertexNormalAttribute, this.vertexNormalBuffer.itemSize, gl.FLOAT, false, 0, 0);

        //texture
        gl.bindBuffer(gl.ARRAY_BUFFER, this.vertexTextureCoordBuffer);
        gl.vertexAttribPointer(shaderProgram.textureCoordAttribute, this.vertexTextureCoordBuffer.itemSize, gl.FLOAT, false, 0, 0);

    }
    
    this.draw = function () {
        gl.drawElements(gl.TRIANGLES, this.vertexIndexBuffer.numItems, gl.UNSIGNED_SHORT, 0);
    }
}