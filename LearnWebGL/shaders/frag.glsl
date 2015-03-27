precision mediump float;

varying vec4 vPosition;
varying vec4 vColor;
varying vec4 vNormal;
varying float vDepth;

void main(void)
{
    vec4 nColor = vNormal;
    nColor += vec4(1,1,1,1);
    nColor *= vec4(0.5,0.5,0.5,0.5);
    
    
    float depth = vDepth;
    
    float zmin = 0.1;
    float zmax = 10.0;
    float d = depth - zmin;
    d /= (zmax - zmin);
    
    if (d > 1.0) d = 1.0;
    if (d < 0.0) d = 0.0;
    
    float wave = 0.5*(sin(d*50.0)+1.0);
    
    vec4 dColor = vec4(d,wave,0,1);
    
    gl_FragColor = 0.5*dColor + 0.5*nColor;
    
}