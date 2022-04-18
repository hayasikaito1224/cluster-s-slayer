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
 24;
 -1.26586;-2.61620;2.69025;,
 -3.10917;-11.67951;-2.77807;,
 -0.81641;-15.64041;2.69025;,
 -1.26586;-2.61620;-2.77807;,
 2.35914;4.74126;2.69025;,
 -0.81641;-15.64041;2.69025;,
 2.35914;-15.64041;2.69025;,
 -1.26586;-2.61620;2.69025;,
 2.35911;4.74126;-2.77805;,
 2.35914;-15.64041;2.69025;,
 2.35911;-11.67951;-2.77805;,
 2.35914;4.74126;2.69025;,
 -1.26586;-2.61620;-2.77807;,
 2.35911;-11.67951;-2.77805;,
 -3.10917;-11.67951;-2.77807;,
 2.35911;4.74126;-2.77805;,
 -1.26586;-2.61620;-2.77807;,
 -1.26586;-2.61620;2.69025;,
 2.35911;-17.63310;2.50356;,
 -0.81641;-15.64041;2.69025;,
 -0.81641;-17.63310;2.50356;,
 2.35911;-13.54336;-2.50718;,
 -3.10917;-13.54336;-2.50718;,
 -3.10917;-11.67951;-2.77807;;
 
 16;
 3;0,1,2;,
 3;0,3,1;,
 3;4,5,6;,
 3;4,7,5;,
 3;8,9,10;,
 3;8,11,9;,
 3;12,13,14;,
 3;12,15,13;,
 3;4,16,17;,
 3;4,15,16;,
 4;18,6,19,20;,
 4;21,13,6,18;,
 3;20,21,18;,
 4;22,23,13,21;,
 4;20,19,23,22;,
 3;20,22,21;;
 
 MeshMaterialList {
  4;
  16;
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
  1;;
  Material {
   0.800000;0.200800;0.220000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.128800;0.128800;0.128800;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.332800;0.000000;0.840000;;
   85.000000;
   0.290000;0.290000;0.290000;;
   1.000000;0.416000;0.000000;;
  }
 }
 MeshNormals {
  24;
  -0.931499;0.363744;0.000002;,
  -0.962555;0.061276;0.264070;,
  -0.969383;0.210393;0.126618;,
  -0.921863;-0.009807;0.387393;,
  0.000000;0.000000;1.000000;,
  0.000000;-0.046690;0.998909;,
  1.000000;0.000000;-0.000006;,
  1.000000;-0.000004;-0.000007;,
  0.000001;-0.492788;-0.870150;,
  0.000000;-0.093279;0.995640;,
  1.000000;-0.000008;-0.000009;,
  0.000000;-0.031123;0.999516;,
  1.000000;-0.000003;-0.000007;,
  1.000000;0.000000;-0.000006;,
  0.000005;-0.000000;-1.000000;,
  0.000004;-0.048052;-0.998845;,
  0.000003;-0.072099;-0.997397;,
  0.000005;0.000000;-1.000000;,
  -0.897033;0.441963;0.000003;,
  -0.897034;0.441962;0.000005;,
  0.000000;-0.774711;-0.632315;,
  0.000001;-0.600583;-0.799562;,
  0.000000;-0.774711;-0.632315;,
  -0.912992;0.012482;0.407787;;
  16;
  3;2,1,3;,
  3;2,0,1;,
  3;4,11,5;,
  3;4,4,11;,
  3;6,12,7;,
  3;6,13,12;,
  3;14,15,16;,
  3;14,17,15;,
  3;18,0,2;,
  3;18,19,0;,
  4;9,5,11,9;,
  4;10,7,12,10;,
  3;20,21,22;,
  4;8,16,15,21;,
  4;23,3,1,23;,
  3;20,8,21;;
 }
 MeshTextureCoords {
  24;
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;;
 }
}
