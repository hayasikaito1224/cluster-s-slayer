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
 82;
 0.07459;0.10660;-6.16682;,
 3.98824;0.10660;-7.21952;,
 0.05405;0.10660;-52.09397;,
 -3.78478;0.10660;-7.20652;,
 -2.99536;-0.02049;-7.43645;,
 0.06108;-0.02049;-48.34563;,
 3.15258;-0.02049;-7.43645;,
 0.07860;0.01863;-6.50253;,
 0.06108;-0.02049;-48.34563;,
 0.06133;0.17920;-48.15813;,
 3.15271;0.17920;-7.41393;,
 3.15258;-0.02049;-7.43645;,
 0.06133;0.17920;-48.15813;,
 -2.99522;0.17920;-7.41393;,
 0.07874;0.17106;-6.47996;,
 3.15271;0.17920;-7.41393;,
 -2.99522;0.17920;-7.41393;,
 0.06108;-0.02049;-48.34563;,
 -2.99536;-0.02049;-7.43645;,
 0.12886;0.10660;-6.14088;,
 -3.78476;0.10660;-7.21952;,
 0.05535;0.10660;-52.09397;,
 3.98824;0.10660;-7.30475;,
 -2.65619;-0.18820;-7.41641;,
 0.10014;-0.05451;-37.81845;,
 2.79817;-0.19586;-7.41641;,
 0.07098;-0.18820;-7.21623;,
 0.10014;-0.05451;-37.81845;,
 0.10014;0.17698;-37.81845;,
 2.79817;0.37521;-7.41641;,
 2.79817;-0.19586;-7.41641;,
 0.10014;0.17698;-37.81845;,
 -2.65619;0.36755;-7.41641;,
 0.07098;0.36755;-7.21623;,
 2.79817;0.37521;-7.41641;,
 -2.65619;0.36755;-7.41641;,
 0.10014;-0.05451;-37.81845;,
 -2.65619;-0.18820;-7.41641;,
 -3.98718;-0.19052;-7.83903;,
 0.04718;-0.25432;-7.27042;,
 0.04718;-0.25432;-6.26722;,
 -3.98718;-0.19052;-6.83579;,
 4.08157;-0.19052;-7.83903;,
 4.08157;-0.19052;-6.83579;,
 4.08157;-0.19052;-7.83903;,
 4.08157;0.40372;-7.83903;,
 4.08157;0.40373;-6.83579;,
 4.08157;-0.19052;-6.83579;,
 4.08157;0.40372;-7.83903;,
 0.04718;0.46750;-7.27042;,
 0.04718;0.46750;-6.26722;,
 4.08157;0.40373;-6.83579;,
 -3.98718;0.40372;-7.83903;,
 -3.98718;0.40373;-6.83579;,
 -3.98718;0.40372;-7.83903;,
 -3.98718;-0.19052;-7.83903;,
 -3.98718;-0.19052;-6.83579;,
 -3.98718;0.40373;-6.83579;,
 0.04718;-0.25432;-7.27042;,
 -3.98718;-0.19052;-7.83903;,
 4.08157;-0.19052;-7.83903;,
 -3.98718;-0.19052;-6.83579;,
 0.04718;-0.25432;-6.26722;,
 4.08157;-0.19052;-6.83579;,
 -1.01274;-0.14542;-6.57582;,
 1.10711;-0.14542;-6.57582;,
 0.73740;-0.27465;8.34065;,
 -0.64302;-0.27465;8.34065;,
 1.10711;-0.14542;-6.57582;,
 1.10711;0.35862;-6.57582;,
 0.73740;0.48785;8.34065;,
 0.73740;-0.27465;8.34065;,
 1.10711;0.35862;-6.57582;,
 -1.01274;0.35862;-6.57582;,
 -0.64302;0.48785;8.34065;,
 0.73740;0.48785;8.34065;,
 -1.01274;0.35862;-6.57582;,
 -1.01274;-0.14542;-6.57582;,
 -0.64302;-0.27465;8.34065;,
 -0.64302;0.48785;8.34065;,
 -0.64302;-0.27465;8.34065;,
 0.73740;-0.27465;8.34065;;
 
 25;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;16,9,17,18;,
 4;19,20,21,22;,
 4;23,24,25,26;,
 4;27,28,29,30;,
 4;31,32,33,34;,
 4;35,28,36,37;,
 4;38,39,40,41;,
 4;39,42,43,40;,
 4;44,45,46,47;,
 4;48,49,50,51;,
 4;49,52,53,50;,
 4;54,55,56,57;,
 4;54,49,58,59;,
 4;49,45,60,58;,
 4;61,62,50,57;,
 4;62,63,46,50;,
 4;64,65,66,67;,
 4;68,69,70,71;,
 4;72,73,74,75;,
 4;76,77,78,79;,
 4;80,81,70,79;;
 
 MeshMaterialList {
  7;
  25;
  6,
  0,
  0,
  0,
  0,
  6,
  2,
  2,
  2,
  2,
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
  0;;
  Material {
   0.432800;0.432800;0.432800;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
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
  Material {
   0.664800;0.266400;0.019200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.125600;0.480000;0.019200;0.840000;;
   100.000000;
   1.000000;1.000000;1.000000;;
   0.157000;0.600000;0.024000;;
  }
 }
 MeshNormals {
  29;
  0.000000;1.000000;0.000000;,
  0.000002;-1.000000;0.000935;,
  0.996401;0.038629;-0.075449;,
  0.000000;1.000000;0.000195;,
  0.000000;-1.000000;0.000000;,
  -0.001404;-0.999990;-0.004370;,
  0.996085;0.000000;-0.088398;,
  -0.001404;0.999980;-0.006229;,
  -0.015812;-0.999875;0.000000;,
  -0.000000;-1.000000;0.000000;,
  0.015812;-0.999875;-0.000000;,
  1.000000;0.000000;0.000000;,
  -0.000000;1.000000;-0.000002;,
  -0.015807;0.999875;-0.000002;,
  0.000000;-0.999962;-0.008663;,
  0.999693;0.000000;0.024778;,
  0.000000;0.999962;-0.008663;,
  -0.996407;0.040100;-0.074597;,
  -0.995915;0.000000;-0.090292;,
  0.015807;0.999875;-0.000002;,
  -1.000000;0.000000;0.000000;,
  0.139562;0.000000;-0.990213;,
  0.000001;0.000000;-1.000000;,
  -0.139561;0.000000;-0.990213;,
  -0.139553;0.000000;0.990215;,
  -0.000001;0.000000;1.000000;,
  0.139552;0.000000;0.990215;,
  -0.999693;0.000000;0.024778;,
  0.000000;0.000000;1.000000;;
  25;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;17,17,17,17;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;18,18,18,18;,
  4;8,9,9,8;,
  4;9,10,10,9;,
  4;11,11,11,11;,
  4;19,12,12,19;,
  4;12,13,13,12;,
  4;20,20,20,20;,
  4;21,22,22,21;,
  4;22,23,23,22;,
  4;24,25,25,24;,
  4;25,26,26,25;,
  4;14,14,14,14;,
  4;15,15,15,15;,
  4;16,16,16,16;,
  4;27,27,27,27;,
  4;28,28,28,28;;
 }
 MeshTextureCoords {
  82;
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
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  1.000000;0.000000;,
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
  1.000000;0.000000;;
 }
}
