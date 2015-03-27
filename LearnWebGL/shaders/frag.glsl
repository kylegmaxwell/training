precision mediump float;

varying vec4 vColor;
varying vec4 vNormal;
varying float vDepth;

void main(void)
{
    float x = 0.;
    if (1 < 0)
        x = 1.;
        
    //gl_FragColor = vec4(x, 1.0, 1.0, 1.0);
    
    //gl_FragColor = vColor;
    
    gl_FragColor = vNormal;
    
    float d = vDepth*0.05+0.1;
    //gl_FragColor = vec4(d,d,d,1);
    
}