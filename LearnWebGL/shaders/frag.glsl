precision mediump float;
void main(void) {

    float x = 0.;
    if (1 < 0)
        x = 1.;
        
    gl_FragColor = vec4(x, 1.0, 1.0, 1.0);
}