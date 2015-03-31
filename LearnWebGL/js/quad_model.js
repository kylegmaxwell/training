
// box
var quadVertexPositions = [
    // Front face
    -1.0, -1.0,  1.0,
    1.0, -1.0,  1.0,
    1.0,  1.0,  1.0,
    -1.0,  1.0,  1.0
    
];


//---- Normal
var quadVertexNormals = [
    // Front face
    0.0, 0.0,  1.0,
    0.0, 0.0,  1.0,
    0.0, 0.0,  1.0,
    0.0, 0.0,  1.0,
];

var quadTextureCoords = [
  // Front face
  0.0, 0.0,
  1.0, 0.0,
  1.0, 1.0,
  0.0, 1.0,
];

// This array specifies which vertices make up the triangles
var quadVertexIndices = [
    0,  1,  2,      0,  2,  3,    // front
];
