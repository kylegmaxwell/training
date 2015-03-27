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
    
    vec4 col = vNormal;
    col += vec4(1,1,1,1);
    col *= vec4(0.5,0.5,0.5,0.5);
    
    gl_FragColor = col;
    
    float d = vDepth*0.05+0.1;
    //gl_FragColor = vec4(d,d,d,1);
    
}