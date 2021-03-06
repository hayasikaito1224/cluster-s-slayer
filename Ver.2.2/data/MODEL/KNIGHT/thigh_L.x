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
 30;
 -2.80803;-32.79096;-3.09256;,
 -4.31559;0.01315;-3.71104;,
 0.00000;0.01315;-4.98215;,
 0.00000;-32.79096;-3.88992;,
 0.00000;0.01315;5.04520;,
 -4.31559;0.01315;3.77409;,
 -2.80803;-32.79096;3.15562;,
 0.00000;-32.79096;3.95298;,
 4.31559;0.01315;-3.71104;,
 2.80803;-32.79096;-3.09256;,
 2.80803;-32.79096;3.15562;,
 4.31559;0.01315;3.77409;,
 4.31558;0.01315;-3.71104;,
 2.60626;-32.79096;-3.09256;,
 4.31558;0.01315;3.77410;,
 2.60626;-32.79096;3.15562;,
 -4.31558;0.01315;-3.71104;,
 -2.60626;-32.79096;-3.09256;,
 -4.31558;0.01315;3.77410;,
 -2.60626;-32.79096;3.15562;,
 -4.32723;-32.79096;0.03153;,
 -6.44010;0.01315;0.03153;,
 6.44010;0.01315;0.03153;,
 4.32723;-32.79096;0.03153;,
 4.31559;0.01315;0.03153;,
 2.60626;-32.79096;0.03153;,
 -2.60626;-32.79096;0.03153;,
 -4.31559;0.01315;0.03153;,
 0.00000;-32.79096;0.03153;,
 0.00000;0.01315;0.03153;;
 
 32;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;2,8,9,3;,
 4;10,11,4,7;,
 4;3,2,12,13;,
 4;14,4,7,15;,
 4;16,2,3,17;,
 4;7,4,18,19;,
 4;20,21,1,0;,
 4;5,21,20,6;,
 4;8,22,23,9;,
 4;23,22,11,10;,
 4;24,25,13,12;,
 4;15,25,24,14;,
 4;17,26,27,16;,
 4;27,26,19,18;,
 4;0,3,28,20;,
 4;28,7,6,20;,
 4;28,3,9,23;,
 4;10,7,28,23;,
 4;25,28,3,13;,
 4;7,28,25,15;,
 4;3,28,26,17;,
 4;26,28,7,19;,
 4;2,1,21,29;,
 4;21,5,4,29;,
 4;22,8,2,29;,
 4;4,11,22,29;,
 4;12,2,29,24;,
 4;29,4,14,24;,
 4;29,2,16,27;,
 4;18,4,29,27;;
 
 MeshMaterialList {
  1;
  32;
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
   0.640000;0.640000;0.640000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  20;
  -0.631049;-0.045794;-0.774390;,
  -0.631049;-0.045793;0.774390;,
  0.631049;-0.045794;-0.774390;,
  0.631049;-0.045793;0.774390;,
  0.287401;-0.032307;-0.957265;,
  0.287400;-0.032307;0.957266;,
  -0.287401;-0.032307;-0.957265;,
  -0.287400;-0.032307;0.957266;,
  0.000000;-0.033277;-0.999446;,
  0.000000;-0.033277;0.999446;,
  -0.998223;-0.059582;0.000000;,
  0.998223;-0.059582;0.000000;,
  0.998645;-0.052036;-0.000000;,
  -0.998645;-0.052036;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;1.000000;0.000000;,
  0.998645;-0.052036;-0.000001;,
  0.998645;-0.052036;0.000001;,
  -0.998645;-0.052036;-0.000001;,
  -0.998645;-0.052036;0.000001;;
  32;
  4;0,0,8,8;,
  4;9,1,1,9;,
  4;8,2,2,8;,
  4;3,3,9,9;,
  4;8,8,4,4;,
  4;5,9,9,5;,
  4;6,8,8,6;,
  4;9,9,7,7;,
  4;10,10,0,0;,
  4;1,10,10,1;,
  4;2,11,11,2;,
  4;11,11,3,3;,
  4;12,12,16,16;,
  4;17,12,12,17;,
  4;18,13,13,18;,
  4;13,13,19,19;,
  4;14,14,14,14;,
  4;14,14,14,14;,
  4;14,14,14,14;,
  4;14,14,14,14;,
  4;14,14,14,14;,
  4;14,14,14,14;,
  4;14,14,14,14;,
  4;14,14,14,14;,
  4;15,15,15,15;,
  4;15,15,15,15;,
  4;15,15,15,15;,
  4;15,15,15,15;,
  4;15,15,15,15;,
  4;15,15,15,15;,
  4;15,15,15,15;,
  4;15,15,15,15;;
 }
 MeshTextureCoords {
  30;
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
  0.000000;0.000000;;
 }
}
