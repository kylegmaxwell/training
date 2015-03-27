attribute vec3 aVertexPosition;
attribute vec4 aVertexNormal;
attribute vec4 aVertexColor;

uniform mat4 uMVMatrix;
uniform mat4 uPMatrix;

varying vec4 vPosition;
varying vec4 vColor;
varying vec4 vNormal;
varying float vDepth;
 
void main(void)
{
    vec4 pos = uPMatrix * uMVMatrix * vec4(aVertexPosition, 1.0);
    
    
    vColor = aVertexColor;
    vNormal = aVertexNormal;
    vDepth = pos.z;
    
    gl_Position = pos;
    vPosition = gl_Position;
}