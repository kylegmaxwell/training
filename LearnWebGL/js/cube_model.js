
// box
var cubeVertexPositions = [
    // Front face
    -1.0, -1.0,  1.0,
    1.0, -1.0,  1.0,
    1.0,  1.0,  1.0,
    -1.0,  1.0,  1.0,

    // Back face
    -1.0, -1.0, -1.0,
    -1.0,  1.0, -1.0,
    1.0,  1.0, -1.0,
    1.0, -1.0, -1.0,

    // Top face
    -1.0,  1.0, -1.0,
    -1.0,  1.0,  1.0,
    1.0,  1.0,  1.0,
    1.0,  1.0, -1.0,

    // Bottom face
    -1.0, -1.0, -1.0,
    1.0, -1.0, -1.0,
    1.0, -1.0,  1.0,
    -1.0, -1.0,  1.0,
    
    // Right face
     1.0, -1.0, -1.0,
     1.0,  1.0, -1.0,
     1.0,  1.0,  1.0,
     1.0, -1.0,  1.0,

    // Left face
    -1.0, -1.0, -1.0,
    -1.0, -1.0,  1.0,
    -1.0,  1.0,  1.0,
    -1.0,  1.0, -1.0
    
];


//---- Normal
/*
normals = []
for (var i=0; i < vertCount; i++) {
  normals = normals.concat([i==4, 0.0, 0.0]);
}*/
var cubeVertexNormals = [
    // Front face
    0.0, 0.0,  1.0,
    0.0, 0.0,  1.0,
    0.0, 0.0,  1.0,
    0.0, 0.0,  1.0,

    // Back face
    0.0, 0.0,  -1.0,
    0.0, 0.0,  -1.0,
    0.0, 0.0,  -1.0,
    0.0, 0.0,  -1.0,

    // Top face
    0.0,  1.0, 0.0,
    0.0,  1.0, 0.0,
    0.0,  1.0, 0.0,
    0.0,  1.0, 0.0,

    // Bottom face
    0.0,  -1.0, 0.0,
    0.0,  -1.0, 0.0,
    0.0,  -1.0, 0.0,
    0.0,  -1.0, 0.0,
    
    // Right face
     -1.0, 0.0, 0.0,
     -1.0, 0.0, 0.0,
     -1.0, 0.0, 0.0,
     -1.0, 0.0, 0.0,

    // Left face
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0
    
];

// This array specifies which vertices make up the triangles
var cubeVertexIndices = [
0,  1,  2,      0,  2,  3,    // front
4,  5,  6,      4,  6,  7,    // back
8,  9,  10,     8,  10, 11,   // top
12, 13, 14,     12, 14, 15,   // bottom
16, 17, 18,     16, 18, 19,   // right
20, 21, 22,     20, 22, 23    // left
]