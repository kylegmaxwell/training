precision mediump float;

varying vec4 vPosition;
varying vec4 vColor;
varying vec4 vNormal;
varying float vDepth;
varying vec2 vTextureCoord;

uniform sampler2D uSampler0; // Normal
uniform sampler2D uSampler1; // Depth

uniform int uOutputType;

// Pixel width for samplers
uniform float uDx;
uniform float uDy;

#define filterSize 2
vec4 boxSample(vec2 uv) {

    vec4 color = vec4(0., 0., 0., 1.);
    
    float dy = uDy;
    float dx = uDx;
    vec2 scale = vec2(dx, dy);
    
    float count = 0.0;
    for (int i = -filterSize; i <= filterSize; i++) {
        for (int j = -filterSize; j <= filterSize; j++) {
            color += texture2D(uSampler1, uv + scale * vec2(i, j));
            count++;
        }
    }
    color /= count;
    
    return color;
}

vec4 sampleOcclusion(vec2 uv) {

    vec4 color = vec4(0., 0., 0., 1.);
    return color;
    
}

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
    
    vec4 dColor = vec4(d,d,d,1);
    
    //gl_FragColor = 0.5*dColor + 0.5*nColor;
    
    vec4 texColor0 = texture2D(uSampler0, vec2(vTextureCoord.s, vTextureCoord.t));
    vec4 texColor1 = texture2D(uSampler1, vec2(vTextureCoord.s, vTextureCoord.t));
    
    vec4 color;
    color = vec4(0.0, 0.0, 0.0, 1.0);
    
    if (uOutputType==0) { // default use texture
        color = texColor0;
    }
        
    if (uOutputType==1) // output normals
        color = nColor;
        
    if (uOutputType==2) // output depth
        color = dColor;     
  
    if (uOutputType==3) { // occlusion
        
        //color = 1.0*texColor0 + 1.0*texColor1;
        //color = vec4(1., 1., 1., 1.);
        //color = vec4(uDx, uDy, 0., 1.);
        color = boxSample(vTextureCoord.st);
    }
    
    gl_FragColor = color;
}