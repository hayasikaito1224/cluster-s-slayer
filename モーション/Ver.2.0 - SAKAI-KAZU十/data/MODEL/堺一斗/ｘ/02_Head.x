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
 40;
 10.30441;20.44160;-6.08711;,
 1.91594;25.91689;-6.08711;,
 1.91594;25.91689;-0.01630;,
 10.30441;20.44160;-0.01630;,
 9.76324;7.81923;-6.08711;,
 9.76324;7.81923;-0.01630;,
 6.75846;3.05312;-6.08711;,
 6.75846;3.05312;-0.01630;,
 -6.27914;24.21801;-6.08711;,
 -6.27914;24.21801;-0.01630;,
 -10.40353;16.68627;-6.08711;,
 -10.40353;16.68627;-0.01630;,
 -10.40353;16.68635;-6.08711;,
 -10.79033;15.98005;-6.08711;,
 -10.79033;15.98005;-0.01630;,
 -10.40353;16.68635;-0.01630;,
 10.30441;20.44160;6.05451;,
 10.30441;20.44160;-0.01630;,
 1.91594;25.91689;-0.01630;,
 1.91594;25.91689;6.05451;,
 9.76324;7.81923;6.05451;,
 9.76324;7.81923;-0.01630;,
 6.75846;3.05312;6.05451;,
 6.75846;3.05312;-0.01630;,
 -6.27914;24.21801;-0.01630;,
 -6.27914;24.21801;6.05451;,
 -10.40353;16.68627;6.05451;,
 -10.40353;16.68627;-0.01630;,
 -10.40353;16.68635;6.05451;,
 -10.40353;16.68635;-0.01630;,
 -10.79033;15.98005;-0.01630;,
 -10.79033;15.98005;6.05451;,
 10.88022;-0.22108;-6.08711;,
 10.69548;-0.07432;-0.01630;,
 -7.56846;-0.35909;-6.08712;,
 -7.59763;-0.21116;-0.01630;,
 10.69548;-0.07432;-0.01630;,
 10.51078;0.07241;6.05451;,
 -7.59763;-0.21116;-0.01630;,
 -7.62679;-0.06326;6.05452;;
 
 24;
 4;0,1,2,3;,
 4;4,0,3,5;,
 4;6,4,5,7;,
 4;1,0,4,6;,
 4;1,8,9,2;,
 4;10,6,7,11;,
 4;8,10,11,9;,
 4;8,1,6,10;,
 4;12,13,14,15;,
 4;16,17,18,19;,
 4;20,21,17,16;,
 4;22,23,21,20;,
 4;19,22,20,16;,
 4;19,18,24,25;,
 4;26,27,23,22;,
 4;25,24,27,26;,
 4;25,26,22,19;,
 4;28,29,30,31;,
 4;32,12,15,33;,
 4;34,35,14,13;,
 4;32,34,13,12;,
 4;36,29,28,37;,
 4;38,39,31,30;,
 4;39,37,28,31;;
 
 MeshMaterialList {
  5;
  24;
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
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "C:\\Users\\student\\Pictures\\���Ɖۑ莑��\\jpg\\���l.jpg";
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
  18;
  0.845921;-0.533308;-0.000000;,
  0.954542;-0.298077;-0.000000;,
  0.889369;0.457190;0.000000;,
  0.185850;0.982578;0.000000;,
  -0.622008;-0.783011;0.000000;,
  -0.877087;0.480331;0.000000;,
  -0.594869;0.803822;0.000000;,
  -0.988292;0.152573;-0.000000;,
  -0.988292;0.152573;0.000000;,
  0.622009;0.783010;-0.000000;,
  -0.981108;-0.193462;-0.000000;,
  0.622009;0.783010;-0.000000;,
  -0.981108;-0.193462;0.000000;,
  0.000000;0.000000;-1.000000;,
  -0.877103;0.480303;0.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;1.000000;;
  24;
  4;2,3,3,2;,
  4;1,2,2,1;,
  4;0,1,1,0;,
  4;13,13,13,13;,
  4;3,6,6,3;,
  4;4,4,4,4;,
  4;6,14,14,6;,
  4;13,13,13,13;,
  4;5,7,7,5;,
  4;2,2,3,3;,
  4;1,1,2,2;,
  4;0,0,1,1;,
  4;15,15,15,15;,
  4;3,3,6,6;,
  4;4,4,4,4;,
  4;6,6,14,14;,
  4;15,15,15,15;,
  4;5,5,8,8;,
  4;9,9,9,9;,
  4;10,10,7,7;,
  4;16,16,16,16;,
  4;11,11,11,11;,
  4;12,12,8,8;,
  4;17,17,17,17;;
 }
 MeshTextureCoords {
  40;
  0.639530;0.256380;,
  0.554940;0.209850;,
  0.554940;0.209850;,
  0.639530;0.256380;,
  0.634080;0.363640;,
  0.634080;0.363640;,
  0.603770;0.404140;,
  0.603770;0.404140;,
  0.472290;0.224290;,
  0.472290;0.224290;,
  0.430700;0.288290;,
  0.430700;0.288290;,
  0.430700;0.288290;,
  0.426800;0.294290;,
  0.426800;0.294290;,
  0.430700;0.288290;,
  0.639530;0.256380;,
  0.639530;0.256380;,
  0.554940;0.209850;,
  0.554940;0.209850;,
  0.634080;0.363640;,
  0.634080;0.363640;,
  0.603770;0.404140;,
  0.603770;0.404140;,
  0.472290;0.224290;,
  0.472290;0.224290;,
  0.430700;0.288290;,
  0.430700;0.288290;,
  0.430700;0.288290;,
  0.430700;0.288290;,
  0.426800;0.294290;,
  0.426800;0.294290;,
  0.645340;0.431960;,
  0.643480;0.430710;,
  0.459290;0.433130;,
  0.459000;0.431870;,
  0.643480;0.430710;,
  0.641620;0.429460;,
  0.459000;0.431870;,
  0.458700;0.430620;;
 }
}
