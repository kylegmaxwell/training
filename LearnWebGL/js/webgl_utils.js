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