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
 35;
 4.02357;13.19325;-7.17066;,
 4.02357;0.14348;-7.17066;,
 -5.83800;0.14348;-3.76662;,
 -5.83800;10.66222;-3.76662;,
 4.65756;0.14348;6.67711;,
 4.65756;10.11062;6.67711;,
 -2.75756;8.54845;3.39076;,
 -2.73950;0.14348;3.39076;,
 4.65756;10.11062;6.67711;,
 4.02357;13.19325;-7.17066;,
 -5.83800;10.66222;-3.76662;,
 -2.75756;8.54845;3.39076;,
 4.65756;0.14348;6.67711;,
 4.02357;0.14348;-7.17066;,
 4.02357;13.19325;-7.17066;,
 -5.24738;8.96778;-3.35115;,
 -5.24738;1.02047;-3.35115;,
 -13.65548;1.02047;-3.31782;,
 -13.65547;9.05216;-3.31782;,
 -5.24738;1.02047;-3.35115;,
 -2.72133;1.02046;3.35793;,
 -13.63167;1.02047;3.02818;,
 -13.65548;1.02047;-3.31782;,
 -2.72133;1.02046;3.35793;,
 -2.72133;8.36649;3.35793;,
 -13.63166;8.93505;3.02818;,
 -13.63167;1.02047;3.02818;,
 -2.72133;8.36649;3.35793;,
 -5.24738;8.96778;-3.35115;,
 -13.65547;9.05216;-3.31782;,
 -13.63166;8.93505;3.02818;,
 -2.73705;8.54551;3.42411;,
 -0.67460;8.99020;4.32142;,
 -1.06436;10.30011;1.22620;,
 -3.70044;9.20161;1.22620;;
 
 9;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;8,12,13,14;,
 4;15,16,17,18;,
 4;19,20,21,22;,
 4;23,24,25,26;,
 4;27,28,29,30;,
 4;31,32,33,34;;
 
 MeshMaterialList {
  3;
  9;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1;;
  Material {
   0.023550;0.117000;0.004650;1.000000;;
   0.000000;
   0.060000;0.060000;0.060000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.012800;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   1.000000;0.016000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   0.000000;
   0.060000;0.060000;0.060000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  9;
  -0.326290;0.000000;-0.945270;,
  -0.405598;-0.000436;0.914051;,
  -0.003964;0.000000;-0.999992;,
  -0.000001;-1.000000;-0.000001;,
  -0.030209;0.000000;0.999544;,
  -0.354108;0.843499;0.403878;,
  -0.210901;0.937475;0.276879;,
  0.998954;0.000000;-0.045735;,
  0.029962;0.998560;0.044502;;
  9;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;8,8,8,8;,
  4;5,5,5,5;;
 }
 MeshTextureCoords {
  35;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;;
 }
}
