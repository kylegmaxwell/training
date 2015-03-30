// inputs
attribute vec3 aVertexPosition;
attribute vec4 aVertexNormal;
attribute vec4 aVertexColor;
attribute vec2 aTextureCoord;

uniform mat4 uMVMatrix;
uniform mat4 uPMatrix;

// outputs
varying vec4 vPosition;
varying vec4 vColor;
varying vec4 vNormal;
varying float vDepth;
varying vec2 vTextureCoord;
 
void main(void)
{
    vec4 pos = uPMatrix * uMVMatrix * vec4(aVertexPosition, 1.0);
    
    
    vColor = aVertexColor;
    vNormal = aVertexNormal;
    vDepth = pos.z;
    vTextureCoord = aTextureCoord;
    
    gl_Position = pos;
    vPosition = gl_Position;
}