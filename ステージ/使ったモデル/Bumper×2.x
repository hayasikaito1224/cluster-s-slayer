xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 75;
 0.00000;3.80818;-20.00000;,
 14.14214;3.80818;-14.14214;,
 12.72792;-0.19182;-12.72792;,
 0.00000;-0.19182;-18.00000;,
 20.00000;3.80818;0.00000;,
 18.00000;-0.19182;-0.00000;,
 14.14214;3.80818;14.14214;,
 12.72792;-0.19182;12.72792;,
 0.00000;3.80818;20.00000;,
 0.00000;-0.19182;18.00000;,
 -14.14214;3.80818;14.14214;,
 -12.72792;-0.19182;12.72792;,
 -20.00000;3.80818;0.00000;,
 -18.00000;-0.19182;0.00000;,
 -14.14214;3.80818;-14.14214;,
 -12.72792;-0.19182;-12.72792;,
 0.00000;3.80818;-20.00000;,
 0.00000;-0.19182;-18.00000;,
 0.00000;9.80818;-16.00000;,
 11.31370;9.80818;-11.31370;,
 14.14214;3.80818;-14.14214;,
 16.00000;9.80818;0.00000;,
 20.00000;3.80818;0.00000;,
 11.31370;9.80818;11.31370;,
 14.14214;3.80818;14.14214;,
 0.00000;9.80818;16.00000;,
 0.00000;3.80818;20.00000;,
 -11.31372;9.80818;11.31370;,
 -14.14214;3.80818;14.14214;,
 -16.00000;9.80818;0.00000;,
 -20.00000;3.80818;0.00000;,
 -11.31372;9.80818;-11.31370;,
 -14.14214;3.80818;-14.14214;,
 11.31370;9.80818;-11.31370;,
 16.00000;9.80818;0.00000;,
 11.31370;9.80818;11.31370;,
 0.00000;9.80818;16.00000;,
 -11.31372;9.80818;11.31370;,
 -16.00000;9.80818;0.00000;,
 -11.31372;9.80818;-11.31370;,
 0.00000;9.80818;-16.00000;,
 0.00000;11.80818;-10.00000;,
 7.07106;11.80818;-7.07106;,
 10.00000;11.80818;0.00000;,
 7.07106;11.80818;7.07106;,
 0.00000;11.80818;10.00000;,
 -7.07106;11.80818;7.07106;,
 -10.00000;11.80818;0.00000;,
 -7.07106;11.80818;-7.07106;,
 0.00000;14.08630;-10.00000;,
 7.07106;14.08630;-7.07106;,
 7.07106;-0.25976;-7.07106;,
 0.00000;-0.25976;-10.00000;,
 10.00000;14.08630;0.00000;,
 10.00000;-0.25976;-0.00000;,
 7.07106;14.08630;7.07106;,
 7.07106;-0.25976;7.07106;,
 0.00000;14.08630;10.00000;,
 0.00000;-0.25976;10.00000;,
 -7.07106;14.08630;7.07106;,
 -7.07106;-0.25976;7.07106;,
 -10.00000;14.08630;0.00000;,
 -10.00000;-0.25976;0.00000;,
 -7.07106;14.08630;-7.07106;,
 -7.07106;-0.25976;-7.07106;,
 0.00000;14.08630;-10.00000;,
 0.00000;-0.25976;-10.00000;,
 0.00000;14.08630;0.00000;,
 0.00000;14.08630;0.00000;,
 0.00000;14.08630;0.00000;,
 0.00000;14.08630;0.00000;,
 0.00000;14.08630;0.00000;,
 0.00000;14.08630;0.00000;,
 0.00000;14.08630;0.00000;,
 0.00000;14.08630;0.00000;;
 
 48;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 4;0,18,19,20;,
 4;20,19,21,22;,
 4;22,21,23,24;,
 4;24,23,25,26;,
 4;26,25,27,28;,
 4;28,27,29,30;,
 4;30,29,31,32;,
 4;32,31,18,0;,
 4;18,33,2,3;,
 4;33,34,5,2;,
 4;34,35,7,5;,
 4;35,36,9,7;,
 4;36,37,11,9;,
 4;37,38,13,11;,
 4;38,39,15,13;,
 4;39,40,17,15;,
 4;18,41,42,19;,
 4;19,42,43,21;,
 4;21,43,44,23;,
 4;23,44,45,25;,
 4;25,45,46,27;,
 4;27,46,47,29;,
 4;29,47,48,31;,
 4;31,48,41,18;,
 4;49,50,51,52;,
 4;50,53,54,51;,
 4;53,55,56,54;,
 4;55,57,58,56;,
 4;57,59,60,58;,
 4;59,61,62,60;,
 4;61,63,64,62;,
 4;63,65,66,64;,
 3;67,50,49;,
 3;68,53,50;,
 3;69,55,53;,
 3;70,57,55;,
 3;71,59,57;,
 3;72,61,59;,
 3;73,63,61;,
 3;74,65,63;;
 
 MeshMaterialList {
  4;
  48;
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.062400;0.037600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.370400;0.800000;0.232000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  49;
  0.000000;-0.447214;-0.894427;,
  0.632455;-0.447214;-0.632455;,
  0.894427;-0.447214;-0.000000;,
  0.632455;-0.447214;0.632455;,
  0.000000;-0.447214;0.894427;,
  -0.632455;-0.447214;0.632455;,
  -0.894427;-0.447214;0.000000;,
  -0.632455;-0.447214;-0.632455;,
  0.000000;-0.134780;-0.990876;,
  0.700655;-0.134780;-0.700655;,
  0.990876;-0.134780;-0.000000;,
  0.700655;-0.134780;0.700655;,
  0.000000;-0.134780;0.990876;,
  -0.700655;-0.134781;0.700655;,
  -0.990875;-0.134781;0.000000;,
  -0.700655;-0.134781;-0.700655;,
  0.000000;0.633999;-0.773334;,
  0.546830;0.633999;-0.546830;,
  0.773334;0.633999;0.000000;,
  0.546830;0.633999;0.546830;,
  0.000000;0.633999;0.773334;,
  -0.546830;0.633999;0.546830;,
  -0.773334;0.633999;0.000000;,
  -0.546830;0.633999;-0.546830;,
  0.000000;0.948683;-0.316228;,
  0.223607;0.948683;-0.223607;,
  0.316228;0.948683;0.000000;,
  0.223607;0.948683;0.223607;,
  0.000000;0.948683;0.316228;,
  -0.223607;0.948683;0.223607;,
  -0.316227;0.948683;0.000000;,
  -0.223607;0.948683;-0.223607;,
  0.000000;0.000000;-1.000000;,
  0.707107;0.000000;-0.707107;,
  1.000000;0.000000;0.000000;,
  0.707107;0.000000;0.707107;,
  0.000000;0.000000;1.000000;,
  -0.707107;0.000000;0.707107;,
  -1.000000;0.000000;0.000000;,
  -0.707107;0.000000;-0.707107;,
  0.000000;1.000000;0.000000;,
  0.000000;0.554701;-0.832050;,
  0.588348;0.554701;-0.588348;,
  0.832050;0.554701;0.000000;,
  0.588348;0.554701;0.588348;,
  0.000000;0.554701;0.832050;,
  -0.588349;0.554701;0.588348;,
  -0.832050;0.554700;0.000000;,
  -0.588349;0.554701;-0.588348;;
  48;
  4;0,1,9,8;,
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,0,8,15;,
  4;41,16,17,42;,
  4;42,17,18,43;,
  4;43,18,19,44;,
  4;44,19,20,45;,
  4;45,20,21,46;,
  4;46,21,22,47;,
  4;47,22,23,48;,
  4;48,23,16,41;,
  4;16,17,9,8;,
  4;17,18,10,9;,
  4;18,19,11,10;,
  4;19,20,12,11;,
  4;20,21,13,12;,
  4;21,22,14,13;,
  4;22,23,15,14;,
  4;23,16,8,15;,
  4;16,24,25,17;,
  4;17,25,26,18;,
  4;18,26,27,19;,
  4;19,27,28,20;,
  4;20,28,29,21;,
  4;21,29,30,22;,
  4;22,30,31,23;,
  4;23,31,24,16;,
  4;32,33,33,32;,
  4;33,34,34,33;,
  4;34,35,35,34;,
  4;35,36,36,35;,
  4;36,37,37,36;,
  4;37,38,38,37;,
  4;38,39,39,38;,
  4;39,32,32,39;,
  3;40,40,40;,
  3;40,40,40;,
  3;40,40,40;,
  3;40,40,40;,
  3;40,40,40;,
  3;40,40,40;,
  3;40,40,40;,
  3;40,40,40;;
 }
 MeshTextureCoords {
  75;
  0.000000;0.000000;,
  0.125000;0.000000;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.375000;0.000000;,
  0.375000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.625000;0.000000;,
  0.625000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.125000;0.000000;,
  0.250000;0.000000;,
  0.375000;0.000000;,
  0.500000;0.000000;,
  0.625000;0.000000;,
  0.750000;0.000000;,
  0.875000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.125000;0.000000;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.375000;0.000000;,
  0.375000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.625000;0.000000;,
  0.625000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.062500;0.000000;,
  0.187500;0.000000;,
  0.312500;0.000000;,
  0.437500;0.000000;,
  0.562500;0.000000;,
  0.687500;0.000000;,
  0.812500;0.000000;,
  0.937500;0.000000;;
 }
}
