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
 18;
 -9.16311;-3.97859;-6.04943;,
 -9.12972;-25.47084;-6.04943;,
 -9.12972;-25.47084;0.02139;,
 -9.16311;-3.97859;0.02139;,
 -9.16311;-26.26536;6.09221;,
 -9.16311;-3.97859;0.02139;,
 -9.12972;-25.47084;0.02139;,
 -9.12972;-25.47084;6.09221;,
 -7.55544;0.31916;-6.04943;,
 -7.57995;0.25361;0.02139;,
 -4.33088;0.20893;-6.04943;,
 -7.57995;0.25361;0.02139;,
 -7.60447;0.18802;6.09221;,
 -4.36209;0.07719;6.09221;,
 9.31662;-0.25756;-6.04943;,
 9.03208;-18.30540;-6.04943;,
 9.03522;-0.38083;6.09221;,
 8.75089;-18.41629;6.09221;;
 
 8;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,0,3,9;,
 4;8,10,1,0;,
 4;11,5,4,12;,
 4;13,12,4,7;,
 4;10,14,15,1;,
 4;16,13,7,17;;
 
 MeshMaterialList {
  5;
  8;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "C:\\Users\\student\\Pictures\\éˆã∆â€ëËéëóø\\jpg\\ç‰àÍìl.jpg";
   }
  }
  Material {
   0.800000;0.000000;0.065600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.031200;0.031200;0.031200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.248000;0.248000;0.248000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.615200;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  8;
  -0.999999;-0.001554;0.000000;,
  -0.984164;0.177261;0.000000;,
  -0.078983;-0.271094;-0.959307;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;1.000000;,
  -0.936614;0.350363;0.000001;,
  -0.972357;0.207375;0.107317;,
  0.000000;0.000000;0.000000;;
  8;
  4;1,0,0,1;,
  4;2,2,2,2;,
  4;5,1,1,5;,
  4;3,3,3,3;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;3,3,3,3;,
  4;4,4,4,4;;
 }
 MeshTextureCoords {
  18;
  0.256190;0.733740;,
  0.256410;0.870400;,
  0.256410;0.870400;,
  0.256190;0.733740;,
  0.256190;0.733740;,
  0.256190;0.733740;,
  0.256410;0.870400;,
  0.256410;0.870400;,
  0.266850;0.697220;,
  0.266690;0.697780;,
  0.288240;0.698160;,
  0.266690;0.697780;,
  0.266530;0.698330;,
  0.288030;0.699280;,
  0.378770;0.702120;,
  0.376880;0.809510;,
  0.376900;0.703170;,
  0.375010;0.810460;;
 }
}
