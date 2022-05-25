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
 81;
 -27.63089;0.75896;17.67331;,
 -20.65913;0.75896;19.58143;,
 -24.51493;0.75896;14.58279;,
 -33.88938;0.75896;14.58279;,
 -13.53115;0.75896;21.21742;,
 -15.14044;0.75896;14.58279;,
 -5.76597;0.75896;23.95727;,
 -5.76597;0.75896;14.58279;,
 1.36045;0.75896;26.69030;,
 1.36045;0.75896;17.31582;,
 8.97133;0.75896;31.88399;,
 8.97133;0.75896;22.50951;,
 13.19126;0.75896;31.88399;,
 13.19126;0.75896;22.50951;,
 19.98697;0.75896;28.73045;,
 19.98697;0.75896;19.35598;,
 27.90989;0.75896;24.06191;,
 29.36142;0.75896;19.35598;,
 -26.76296;0.75896;7.94138;,
 -36.77336;0.75896;7.94138;,
 -17.38847;0.75896;7.94138;,
 -8.01402;0.75896;7.94138;,
 1.36045;0.75896;7.94138;,
 8.97133;0.75896;13.13506;,
 13.19126;0.75896;13.13506;,
 22.56574;0.75896;13.13506;,
 31.94019;0.75896;13.13506;,
 -28.52654;0.75896;3.76060;,
 -37.90100;0.75896;3.76060;,
 -19.15205;0.75896;3.76060;,
 -9.77760;0.75896;3.76060;,
 -0.40314;0.75896;3.76060;,
 8.97133;0.75896;3.76060;,
 18.34579;0.75896;3.76060;,
 27.72025;0.75896;3.76060;,
 37.09474;0.75896;3.76060;,
 -28.52654;0.75896;-0.44455;,
 -37.90100;0.75896;-0.44455;,
 -19.15205;0.75896;-0.44455;,
 -9.77760;0.75896;-0.44455;,
 -0.40314;0.75896;-0.44455;,
 8.97133;0.75896;-0.44455;,
 18.34579;0.75896;-0.44455;,
 27.72025;0.75896;-0.44455;,
 38.19422;0.75896;-0.44455;,
 -28.52654;0.75896;-6.30193;,
 -36.96769;0.75896;-6.56322;,
 -19.15205;0.75896;-6.30193;,
 -9.77760;0.75896;-6.30193;,
 -0.40314;0.75896;-6.30193;,
 8.97133;0.75896;-6.30193;,
 18.34579;0.75896;-6.30193;,
 27.72025;0.75896;-6.30193;,
 37.09474;0.75896;-6.30193;,
 -28.52654;0.75896;-12.95834;,
 -33.28616;0.75896;-9.70254;,
 -19.15205;0.75896;-12.95834;,
 -9.77760;0.75896;-15.67640;,
 -0.40314;0.75896;-15.67640;,
 5.13076;0.75896;-10.09552;,
 14.50521;0.75896;-10.09552;,
 23.87970;0.75896;-10.09552;,
 33.25414;0.75896;-10.09552;,
 -24.98724;0.75896;-15.93364;,
 -30.51489;0.75896;-13.09725;,
 -15.61279;0.75896;-15.93364;,
 -8.24566;0.75896;-20.91480;,
 -0.40314;0.75896;-25.05085;,
 5.13076;0.75896;-19.46999;,
 14.50521;0.75896;-19.46999;,
 18.84589;0.75896;-17.01889;,
 29.75469;0.75896;-19.22958;,
 -23.76397;0.75896;-23.24085;,
 -28.52359;0.75896;-19.98505;,
 -14.38952;0.75896;-25.17926;,
 -8.24566;0.75896;-30.25017;,
 -0.40314;0.75896;-31.56065;,
 5.13076;0.75896;-26.86693;,
 9.47141;0.75896;-26.39336;,
 18.84589;0.75896;-22.78361;,
 23.18888;0.75896;-22.78361;;
 
 64;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 4;3,2,18,19;,
 4;2,5,20,18;,
 4;5,7,21,20;,
 4;7,9,22,21;,
 4;9,11,23,22;,
 4;11,13,24,23;,
 4;13,15,25,24;,
 4;15,17,26,25;,
 4;19,18,27,28;,
 4;18,20,29,27;,
 4;20,21,30,29;,
 4;21,22,31,30;,
 4;22,23,32,31;,
 4;23,24,33,32;,
 4;24,25,34,33;,
 4;25,26,35,34;,
 4;28,27,36,37;,
 4;27,29,38,36;,
 4;29,30,39,38;,
 4;30,31,40,39;,
 4;31,32,41,40;,
 4;32,33,42,41;,
 4;33,34,43,42;,
 4;34,35,44,43;,
 4;37,36,45,46;,
 4;36,38,47,45;,
 4;38,39,48,47;,
 4;39,40,49,48;,
 4;40,41,50,49;,
 4;41,42,51,50;,
 4;42,43,52,51;,
 4;43,44,53,52;,
 4;46,45,54,55;,
 4;45,47,56,54;,
 4;47,48,57,56;,
 4;48,49,58,57;,
 4;49,50,59,58;,
 4;50,51,60,59;,
 4;51,52,61,60;,
 4;52,53,62,61;,
 4;55,54,63,64;,
 4;54,56,65,63;,
 4;56,57,66,65;,
 4;57,58,67,66;,
 4;58,59,68,67;,
 4;59,60,69,68;,
 4;60,61,70,69;,
 4;61,62,71,70;,
 4;64,63,72,73;,
 4;63,65,74,72;,
 4;65,66,75,74;,
 4;66,67,76,75;,
 4;67,68,77,76;,
 4;68,69,78,77;,
 4;69,70,79,78;,
 4;70,71,80,79;;
 
 MeshMaterialList {
  1;
  64;
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
  0,
  0,
  0,
  0;;
  Material {
   0.000000;0.600000;0.600000;0.800000;;
   30.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.200000;0.200000;;
  }
 }
 MeshNormals {
  1;
  0.000000;1.000000;0.000000;;
  64;
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;;
 }
 MeshTextureCoords {
  81;
  0.000000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.125000;,
  0.000000;0.125000;,
  0.250000;0.000000;,
  0.250000;0.125000;,
  0.375000;0.000000;,
  0.375000;0.125000;,
  0.500000;0.000000;,
  0.500000;0.125000;,
  0.625000;0.000000;,
  0.625000;0.125000;,
  0.750000;0.000000;,
  0.750000;0.125000;,
  0.875000;0.000000;,
  0.875000;0.125000;,
  1.000000;0.000000;,
  1.000000;0.125000;,
  0.125000;0.250000;,
  0.000000;0.250000;,
  0.250000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  1.000000;0.250000;,
  0.125000;0.375000;,
  0.000000;0.375000;,
  0.250000;0.375000;,
  0.375000;0.375000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.750000;0.375000;,
  0.875000;0.375000;,
  1.000000;0.375000;,
  0.125000;0.500000;,
  0.000000;0.500000;,
  0.250000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.750000;0.500000;,
  0.875000;0.500000;,
  1.000000;0.500000;,
  0.125000;0.625000;,
  0.000000;0.625000;,
  0.250000;0.625000;,
  0.375000;0.625000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.750000;0.625000;,
  0.875000;0.625000;,
  1.000000;0.625000;,
  0.125000;0.750000;,
  0.000000;0.750000;,
  0.250000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.750000;0.750000;,
  0.875000;0.750000;,
  1.000000;0.750000;,
  0.125000;0.875000;,
  0.000000;0.875000;,
  0.250000;0.875000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.750000;0.875000;,
  0.875000;0.875000;,
  1.000000;0.875000;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  0.250000;1.000000;,
  0.375000;1.000000;,
  0.500000;1.000000;,
  0.625000;1.000000;,
  0.750000;1.000000;,
  0.875000;1.000000;,
  1.000000;1.000000;;
 }
}
