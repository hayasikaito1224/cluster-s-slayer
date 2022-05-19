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
 130;
 -5.48065;11.95210;-4.18500;,
 -3.91230;11.95210;-4.18500;,
 -3.91230;9.89610;-4.18500;,
 -6.00397;11.29581;-4.18500;,
 -1.82064;11.95210;-4.18500;,
 -1.82064;9.89610;-4.18500;,
 0.27103;11.95210;-4.18500;,
 0.27103;9.89610;-4.18500;,
 2.36270;11.95210;-4.18500;,
 2.36270;9.89610;-4.18500;,
 4.45436;11.95210;-4.18500;,
 4.45436;9.89610;-4.18500;,
 5.48065;11.95210;-4.18500;,
 6.54603;11.29581;-4.18500;,
 -3.91230;7.84010;-4.18500;,
 -6.00397;7.84010;-4.18500;,
 -1.82064;7.84010;-4.18500;,
 0.27103;7.84010;-4.18500;,
 2.36270;7.84010;-4.18500;,
 4.45436;7.84010;-4.18500;,
 6.54603;7.84010;-4.18500;,
 -3.91230;5.78410;-4.18500;,
 -6.00397;5.78410;-4.18500;,
 -1.82064;5.78410;-4.18500;,
 0.27103;5.78410;-4.18500;,
 2.36270;5.78410;-4.18500;,
 4.45436;5.78410;-4.18500;,
 6.54603;5.78410;-4.18500;,
 -3.91230;3.72810;-4.18500;,
 -6.00397;3.72810;-4.18500;,
 -1.82064;3.72810;-4.18500;,
 0.27103;3.72810;-4.18500;,
 2.36270;3.72810;-4.18500;,
 4.45436;3.72810;-4.18500;,
 6.54603;3.72810;-4.18500;,
 -3.91230;0.19417;-4.18500;,
 -6.00397;0.19417;-4.18500;,
 -1.82064;0.19417;-4.18500;,
 0.27103;0.19417;-4.18500;,
 2.36270;0.19417;-4.18500;,
 4.45436;0.19417;-4.18500;,
 6.54603;0.19417;-4.18500;,
 5.48065;11.95210;-4.18500;,
 5.48065;11.95210;4.18500;,
 6.54603;11.29581;4.18500;,
 6.54603;11.29581;-4.18500;,
 6.54603;7.84010;4.18500;,
 6.54603;7.84010;-4.18500;,
 6.54603;5.78410;4.18500;,
 6.54603;5.78410;-4.18500;,
 6.54603;3.72810;4.18500;,
 6.54603;3.72810;-4.18500;,
 6.54603;0.19417;4.18500;,
 6.54603;0.19417;-4.18500;,
 5.48065;11.95210;4.18500;,
 4.45436;11.95210;4.18500;,
 4.45436;9.89610;4.18500;,
 6.54603;11.29581;4.18500;,
 2.36270;11.95210;4.18500;,
 2.36270;9.89610;4.18500;,
 0.27103;11.95210;4.18500;,
 0.27103;9.89610;4.18500;,
 -1.82064;11.95210;4.18500;,
 -1.82064;9.89610;4.18500;,
 -3.91230;11.95210;4.18500;,
 -3.91230;9.89610;4.18500;,
 -5.48065;11.95210;4.18500;,
 -6.00397;11.29581;4.18500;,
 4.45436;7.84010;4.18500;,
 6.54603;7.84010;4.18500;,
 2.36270;7.84010;4.18500;,
 0.27103;7.84010;4.18500;,
 -1.82064;7.84010;4.18500;,
 -3.91230;7.84010;4.18500;,
 -6.00397;7.84010;4.18500;,
 4.45436;5.78410;4.18500;,
 6.54603;5.78410;4.18500;,
 2.36270;5.78410;4.18500;,
 0.27103;5.78410;4.18500;,
 -1.82064;5.78410;4.18500;,
 -3.91230;5.78410;4.18500;,
 -6.00397;5.78410;4.18500;,
 4.45436;3.72810;4.18500;,
 6.54603;3.72810;4.18500;,
 2.36270;3.72810;4.18500;,
 0.27103;3.72810;4.18500;,
 -1.82064;3.72810;4.18500;,
 -3.91230;3.72810;4.18500;,
 -6.00397;3.72810;4.18500;,
 4.45436;0.19417;4.18500;,
 6.54603;0.19417;4.18500;,
 2.36270;0.19417;4.18500;,
 0.27103;0.19417;4.18500;,
 -1.82064;0.19417;4.18500;,
 -3.91230;0.19417;4.18500;,
 -6.00397;0.19417;4.18500;,
 -5.48065;11.95210;4.18500;,
 -5.48065;11.95210;-4.18500;,
 -6.00397;11.29581;-4.18500;,
 -6.00397;11.29581;4.18500;,
 -6.00397;7.84010;-4.18500;,
 -6.00397;7.84010;4.18500;,
 -6.00397;5.78410;-4.18500;,
 -6.00397;5.78410;4.18500;,
 -6.00397;3.72810;-4.18500;,
 -6.00397;3.72810;4.18500;,
 -6.00397;0.19417;-4.18500;,
 -6.00397;0.19417;4.18500;,
 -3.91230;11.95210;4.18500;,
 -3.91230;11.95210;-4.18500;,
 -5.48065;11.95210;-4.18500;,
 -1.82064;11.95210;4.18500;,
 -1.82064;11.95210;-4.18500;,
 0.27103;11.95210;-4.18500;,
 2.36270;11.95210;4.18500;,
 2.36270;11.95210;-4.18500;,
 4.45436;11.95210;4.18500;,
 4.45436;11.95210;-4.18500;,
 5.48065;11.95210;-4.18500;,
 -6.00397;0.19417;-4.18500;,
 -3.91230;0.19417;-4.18500;,
 -3.91230;0.19417;4.18500;,
 -1.82064;0.19417;-4.18500;,
 -1.82064;0.19417;4.18500;,
 0.27103;0.19417;-4.18500;,
 2.36270;0.19417;-4.18500;,
 2.36270;0.19417;4.18500;,
 4.45436;0.19417;-4.18500;,
 4.45436;0.19417;4.18500;,
 6.54603;0.19417;-4.18500;;
 
 82;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;3,2,14,15;,
 4;2,5,16,14;,
 4;5,7,17,16;,
 4;7,9,18,17;,
 4;9,11,19,18;,
 4;11,13,20,19;,
 4;15,14,21,22;,
 4;14,16,23,21;,
 4;16,17,24,23;,
 4;17,18,25,24;,
 4;18,19,26,25;,
 4;19,20,27,26;,
 4;22,21,28,29;,
 4;21,23,30,28;,
 4;23,24,31,30;,
 4;24,25,32,31;,
 4;25,26,33,32;,
 4;26,27,34,33;,
 4;29,28,35,36;,
 4;28,30,37,35;,
 4;30,31,38,37;,
 4;31,32,39,38;,
 4;32,33,40,39;,
 4;33,34,41,40;,
 4;42,43,44,45;,
 4;45,44,46,47;,
 4;47,46,48,49;,
 4;49,48,50,51;,
 4;51,50,52,53;,
 4;54,55,56,57;,
 4;55,58,59,56;,
 4;58,60,61,59;,
 4;60,62,63,61;,
 4;62,64,65,63;,
 4;64,66,67,65;,
 4;57,56,68,69;,
 4;56,59,70,68;,
 4;59,61,71,70;,
 4;61,63,72,71;,
 4;63,65,73,72;,
 4;65,67,74,73;,
 4;69,68,75,76;,
 4;68,70,77,75;,
 4;70,71,78,77;,
 4;71,72,79,78;,
 4;72,73,80,79;,
 4;73,74,81,80;,
 4;76,75,82,83;,
 4;75,77,84,82;,
 4;77,78,85,84;,
 4;78,79,86,85;,
 4;79,80,87,86;,
 4;80,81,88,87;,
 4;83,82,89,90;,
 4;82,84,91,89;,
 4;84,85,92,91;,
 4;85,86,93,92;,
 4;86,87,94,93;,
 4;87,88,95,94;,
 4;96,97,98,99;,
 4;99,98,100,101;,
 4;101,100,102,103;,
 4;103,102,104,105;,
 4;105,104,106,107;,
 4;96,108,109,110;,
 4;108,111,112,109;,
 4;111,60,113,112;,
 4;60,114,115,113;,
 4;114,116,117,115;,
 4;116,43,118,117;,
 4;119,120,121,107;,
 4;120,122,123,121;,
 4;122,124,92,123;,
 4;124,125,126,92;,
 4;125,127,128,126;,
 4;127,129,52,128;;
 
 MeshMaterialList {
  3;
  82;
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
  1,
  1;;
  Material {
   0.511200;0.300800;0.021600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "C:\\Users\\student\\Downloads\\��.png";
   }
  }
  Material {
   0.800000;0.088000;0.112800;0.540000;;
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
  10;
  0.000000;0.000000;-1.000000;,
  0.272563;0.962138;0.000000;,
  0.000000;0.000000;1.000000;,
  0.873065;0.487603;0.000000;,
  1.000000;0.000000;0.000000;,
  -0.433906;0.900958;0.000000;,
  -0.943892;0.330255;0.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;;
  82;
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
  4;1,1,3,3;,
  4;3,3,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;5,5,6,6;,
  4;6,6,7,7;,
  4;7,7,7,7;,
  4;7,7,7,7;,
  4;7,7,7,7;,
  4;5,8,8,5;,
  4;8,8,8,8;,
  4;8,8,8,8;,
  4;8,8,8,8;,
  4;8,8,8,8;,
  4;8,1,1,8;,
  4;9,9,9,9;,
  4;9,9,9,9;,
  4;9,9,9,9;,
  4;9,9,9,9;,
  4;9,9,9,9;,
  4;9,9,9,9;;
 }
 MeshTextureCoords {
  130;
  0.000000;0.000000;,
  0.166670;0.000000;,
  0.166670;0.200000;,
  0.000000;0.200000;,
  0.333330;0.000000;,
  0.333330;0.200000;,
  0.500000;0.000000;,
  0.500000;0.200000;,
  0.666670;0.000000;,
  0.666670;0.200000;,
  0.833330;0.000000;,
  0.833330;0.200000;,
  1.000000;0.000000;,
  1.000000;0.200000;,
  0.166670;0.400000;,
  0.000000;0.400000;,
  0.333330;0.400000;,
  0.500000;0.400000;,
  0.666670;0.400000;,
  0.833330;0.400000;,
  1.000000;0.400000;,
  0.166670;0.600000;,
  0.000000;0.600000;,
  0.333330;0.600000;,
  0.500000;0.600000;,
  0.666670;0.600000;,
  0.833330;0.600000;,
  1.000000;0.600000;,
  0.166670;0.800000;,
  0.000000;0.800000;,
  0.333330;0.800000;,
  0.500000;0.800000;,
  0.666670;0.800000;,
  0.833330;0.800000;,
  1.000000;0.800000;,
  0.166670;1.000000;,
  0.000000;1.000000;,
  0.333330;1.000000;,
  0.500000;1.000000;,
  0.666670;1.000000;,
  0.833330;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.200000;,
  0.000000;0.200000;,
  1.000000;0.400000;,
  0.000000;0.400000;,
  1.000000;0.600000;,
  0.000000;0.600000;,
  1.000000;0.800000;,
  0.000000;0.800000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.166670;0.000000;,
  0.166670;0.200000;,
  0.000000;0.200000;,
  0.333330;0.000000;,
  0.333330;0.200000;,
  0.500000;0.000000;,
  0.500000;0.200000;,
  0.666670;0.000000;,
  0.666670;0.200000;,
  0.833330;0.000000;,
  0.833330;0.200000;,
  1.000000;0.000000;,
  1.000000;0.200000;,
  0.166670;0.400000;,
  0.000000;0.400000;,
  0.333330;0.400000;,
  0.500000;0.400000;,
  0.666670;0.400000;,
  0.833330;0.400000;,
  1.000000;0.400000;,
  0.166670;0.600000;,
  0.000000;0.600000;,
  0.333330;0.600000;,
  0.500000;0.600000;,
  0.666670;0.600000;,
  0.833330;0.600000;,
  1.000000;0.600000;,
  0.166670;0.800000;,
  0.000000;0.800000;,
  0.333330;0.800000;,
  0.500000;0.800000;,
  0.666670;0.800000;,
  0.833330;0.800000;,
  1.000000;0.800000;,
  0.166670;1.000000;,
  0.000000;1.000000;,
  0.333330;1.000000;,
  0.500000;1.000000;,
  0.666670;1.000000;,
  0.833330;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.200000;,
  0.000000;0.200000;,
  1.000000;0.400000;,
  0.000000;0.400000;,
  1.000000;0.600000;,
  0.000000;0.600000;,
  1.000000;0.800000;,
  0.000000;0.800000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.166670;0.000000;,
  0.166670;1.000000;,
  0.000000;1.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.500000;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  0.833330;0.000000;,
  0.833330;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.166670;0.000000;,
  0.166670;1.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.500000;0.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  0.833330;0.000000;,
  0.833330;1.000000;,
  1.000000;0.000000;;
 }
}
