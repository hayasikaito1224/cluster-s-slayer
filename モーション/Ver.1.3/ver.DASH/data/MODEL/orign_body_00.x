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
 79;
 0.34390;72.03453;0.30950;,
 7.11200;73.31263;-4.86060;,
 0.34390;73.31263;-7.00210;,
 0.34390;72.03453;0.30950;,
 9.91540;73.31263;0.30950;,
 0.34390;72.03453;0.30950;,
 7.11200;73.31263;5.47960;,
 0.34390;72.03453;0.30950;,
 0.34390;73.31263;7.62120;,
 0.34390;72.03453;0.30950;,
 -6.42420;73.31263;5.47960;,
 0.34390;72.03453;0.30950;,
 -9.22760;73.31263;0.30950;,
 0.34390;72.03453;0.30950;,
 -6.42420;73.31263;-4.86060;,
 0.34390;72.03453;0.30950;,
 0.34390;73.31263;-7.00210;,
 12.84970;75.97183;-9.24360;,
 0.34390;75.97183;-13.20060;,
 18.02980;75.97183;0.30950;,
 12.84970;75.97183;9.86260;,
 0.34390;75.97183;13.81960;,
 -12.16190;75.97183;9.86260;,
 -17.34190;75.97183;0.30950;,
 -12.16190;75.97183;-9.24360;,
 0.34390;75.97183;-13.20060;,
 16.68350;61.50023;-12.17220;,
 0.34390;61.50023;-17.34230;,
 16.50780;61.50023;0.30950;,
 16.68350;61.50023;12.79120;,
 0.34390;61.50023;17.96140;,
 -15.99570;61.50023;12.79120;,
 -15.82370;61.50023;0.30950;,
 -15.99570;61.50023;-12.17220;,
 0.34390;61.50023;-17.34230;,
 18.02980;44.42983;-13.20060;,
 0.34390;44.42983;-16.26710;,
 25.35550;44.42983;0.30950;,
 18.02980;44.42983;13.81960;,
 0.34390;44.42983;19.41570;,
 -17.34190;44.42983;13.81960;,
 -24.66760;44.42983;0.30950;,
 -17.34190;44.42983;-13.20060;,
 0.34390;44.42983;-16.26710;,
 16.68350;27.35943;-12.17220;,
 0.34390;27.35943;-17.34230;,
 23.45160;27.35943;0.30950;,
 16.68350;27.35943;12.79120;,
 0.34390;27.35943;17.96140;,
 -15.99570;27.35943;12.79120;,
 -22.76370;27.35943;0.30950;,
 -15.99570;27.35943;-12.17220;,
 0.34390;27.35943;-17.34230;,
 12.84970;12.88783;-9.24360;,
 0.34390;12.88783;-13.20060;,
 13.07980;12.88783;0.30950;,
 12.84970;12.88783;9.86260;,
 0.34390;12.88783;13.81960;,
 -12.16190;12.88783;9.86260;,
 -12.39620;12.88783;0.30950;,
 -12.16190;12.88783;-9.24360;,
 0.34390;12.88783;-13.20060;,
 7.11200;3.21823;-4.86060;,
 0.34390;3.21823;-7.00210;,
 9.91540;3.21823;0.30950;,
 7.11200;3.21823;5.47960;,
 0.34390;3.21823;7.62120;,
 -6.42420;3.21823;5.47960;,
 -9.22760;3.21823;0.30950;,
 -6.42420;3.21823;-4.86060;,
 0.34390;3.21823;-7.00210;,
 0.34390;-0.17727;0.30950;,
 0.34390;-0.17727;0.30950;,
 0.34390;-0.17727;0.30950;,
 0.34390;-0.17727;0.30950;,
 0.34390;-0.17727;0.30950;,
 0.34390;-0.17727;0.30950;,
 0.34390;-0.17727;0.30950;,
 0.34390;-0.17727;0.30950;;
 
 64;
 3;0,1,2;,
 3;3,4,1;,
 3;5,6,4;,
 3;7,8,6;,
 3;9,10,8;,
 3;11,12,10;,
 3;13,14,12;,
 3;15,16,14;,
 4;2,1,17,18;,
 4;1,4,19,17;,
 4;4,6,20,19;,
 4;6,8,21,20;,
 4;8,10,22,21;,
 4;10,12,23,22;,
 4;12,14,24,23;,
 4;14,16,25,24;,
 4;18,17,26,27;,
 4;17,19,28,26;,
 4;19,20,29,28;,
 4;20,21,30,29;,
 4;21,22,31,30;,
 4;22,23,32,31;,
 4;23,24,33,32;,
 4;24,25,34,33;,
 4;27,26,35,36;,
 4;26,28,37,35;,
 4;28,29,38,37;,
 4;29,30,39,38;,
 4;30,31,40,39;,
 4;31,32,41,40;,
 4;32,33,42,41;,
 4;33,34,43,42;,
 4;36,35,44,45;,
 4;35,37,46,44;,
 4;37,38,47,46;,
 4;38,39,48,47;,
 4;39,40,49,48;,
 4;40,41,50,49;,
 4;41,42,51,50;,
 4;42,43,52,51;,
 4;45,44,53,54;,
 4;44,46,55,53;,
 4;46,47,56,55;,
 4;47,48,57,56;,
 4;48,49,58,57;,
 4;49,50,59,58;,
 4;50,51,60,59;,
 4;51,52,61,60;,
 4;54,53,62,63;,
 4;53,55,64,62;,
 4;55,56,65,64;,
 4;56,57,66,65;,
 4;57,58,67,66;,
 4;58,59,68,67;,
 4;59,60,69,68;,
 4;60,61,70,69;,
 3;63,62,71;,
 3;62,64,72;,
 3;64,65,73;,
 3;65,66,74;,
 3;66,67,75;,
 3;67,68,76;,
 3;68,69,77;,
 3;69,70,78;;
 
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
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  90;
  -0.054403;0.983604;0.171938;,
  -0.156163;0.966708;0.202706;,
  -0.089749;0.954719;0.283648;,
  -0.132018;0.988659;0.071584;,
  -0.222313;0.974975;0.000000;,
  -0.132018;0.988659;-0.071584;,
  -0.156164;0.966707;-0.202706;,
  -0.054405;0.983605;-0.171936;,
  0.000000;0.958588;-0.284797;,
  0.054405;0.983605;-0.171936;,
  0.156165;0.966707;-0.202706;,
  0.132018;0.988659;-0.071584;,
  0.222314;0.974975;0.000000;,
  0.132018;0.988659;0.071584;,
  0.156164;0.966707;0.202706;,
  0.054403;0.983604;0.171938;,
  0.089749;0.954719;0.283648;,
  -0.217749;0.934418;0.281867;,
  -0.123789;0.911931;0.391226;,
  -0.311419;0.950273;0.000000;,
  -0.217750;0.934417;-0.281868;,
  -0.000000;0.918998;-0.394261;,
  0.217752;0.934417;-0.281868;,
  0.311421;0.950272;-0.000000;,
  0.217750;0.934418;0.281867;,
  0.123789;0.911931;0.391226;,
  0.707694;0.177882;-0.683760;,
  0.266319;0.136030;-0.954238;,
  0.984258;0.176737;0.000000;,
  0.716858;0.196974;0.668816;,
  -0.000000;0.181018;0.983480;,
  -0.716806;0.196982;0.668870;,
  -0.984252;0.176773;0.000000;,
  -0.707641;0.177890;-0.683813;,
  -0.266319;0.136030;-0.954238;,
  0.486853;-0.035229;-0.872773;,
  0.236821;0.000000;-0.971553;,
  0.996128;0.087915;0.000000;,
  0.680924;0.045144;0.730962;,
  -0.000000;0.000000;1.000000;,
  -0.680901;0.045120;0.730985;,
  -0.996132;0.087872;0.000000;,
  -0.775141;0.058080;-0.629113;,
  -0.236821;0.000000;-0.971553;,
  0.635587;-0.234009;-0.735709;,
  0.266319;-0.136030;-0.954238;,
  0.951148;-0.308735;-0.000000;,
  0.645662;-0.251940;0.720865;,
  -0.000000;-0.181018;0.983480;,
  -0.645648;-0.251902;0.720891;,
  -0.951167;-0.308677;0.000000;,
  -0.635572;-0.233971;-0.735735;,
  -0.266319;-0.136030;-0.954238;,
  0.634688;-0.461679;-0.619696;,
  0.276972;-0.396299;-0.875348;,
  0.892839;-0.450377;-0.000000;,
  0.634690;-0.461679;0.619695;,
  -0.000000;-0.412435;0.910987;,
  -0.634624;-0.461686;0.619757;,
  -0.892804;-0.450445;-0.000000;,
  -0.634623;-0.461686;-0.619758;,
  -0.276972;-0.396299;-0.875348;,
  0.444558;-0.767852;-0.461272;,
  0.202908;-0.739992;-0.641280;,
  0.670085;-0.742284;-0.000000;,
  0.444560;-0.767851;0.461270;,
  -0.000000;-0.755714;0.654902;,
  -0.444500;-0.767873;0.461292;,
  -0.669983;-0.742376;-0.000000;,
  -0.444497;-0.767874;-0.461293;,
  -0.202908;-0.739992;-0.641280;,
  0.132103;-0.899021;-0.417505;,
  0.328974;-0.927338;-0.178381;,
  0.328974;-0.927338;0.178381;,
  0.132108;-0.899023;0.417500;,
  -0.132108;-0.899023;0.417500;,
  -0.328974;-0.927338;0.178381;,
  -0.328974;-0.927338;-0.178381;,
  -0.132103;-0.899021;-0.417504;,
  0.291033;0.263237;-0.919786;,
  0.719874;0.199149;-0.664922;,
  0.996184;0.087273;0.000000;,
  0.719875;0.199150;0.664921;,
  0.000000;0.275151;0.961401;,
  -0.719812;0.199223;0.664967;,
  -0.996171;0.087424;0.000000;,
  -0.719811;0.199221;-0.664969;,
  -0.291033;0.263237;-0.919786;,
  0.940861;0.257831;-0.219783;,
  -0.236817;0.006376;-0.971533;;
  64;
  3;0,1,2;,
  3;3,4,1;,
  3;5,6,4;,
  3;7,8,6;,
  3;9,10,8;,
  3;11,12,10;,
  3;13,14,12;,
  3;15,16,14;,
  4;2,1,17,18;,
  4;1,4,19,17;,
  4;4,6,20,19;,
  4;6,8,21,20;,
  4;8,10,22,21;,
  4;10,12,23,22;,
  4;12,14,24,23;,
  4;14,16,25,24;,
  4;79,80,26,27;,
  4;80,81,28,26;,
  4;81,82,29,28;,
  4;82,83,30,29;,
  4;83,84,31,30;,
  4;84,85,32,31;,
  4;85,86,33,32;,
  4;86,87,34,33;,
  4;27,26,35,36;,
  4;26,28,37,88;,
  4;28,29,38,37;,
  4;29,30,39,38;,
  4;30,31,40,39;,
  4;31,32,41,40;,
  4;32,33,42,41;,
  4;33,34,43,89;,
  4;36,35,44,45;,
  4;35,37,46,44;,
  4;37,38,47,46;,
  4;38,39,48,47;,
  4;39,40,49,48;,
  4;40,41,50,49;,
  4;41,42,51,50;,
  4;42,43,52,51;,
  4;45,44,53,54;,
  4;44,46,55,53;,
  4;46,47,56,55;,
  4;47,48,57,56;,
  4;48,49,58,57;,
  4;49,50,59,58;,
  4;50,51,60,59;,
  4;51,52,61,60;,
  4;54,53,62,63;,
  4;53,55,64,62;,
  4;55,56,65,64;,
  4;56,57,66,65;,
  4;57,58,67,66;,
  4;58,59,68,67;,
  4;59,60,69,68;,
  4;60,61,70,69;,
  3;63,62,71;,
  3;62,64,72;,
  3;64,65,73;,
  3;65,66,74;,
  3;66,67,75;,
  3;67,68,76;,
  3;68,69,77;,
  3;69,70,78;;
 }
 MeshTextureCoords {
  79;
  0.062500;0.000000;,
  0.125000;0.125000;,
  0.000000;0.125000;,
  0.187500;0.000000;,
  0.250000;0.125000;,
  0.312500;0.000000;,
  0.375000;0.125000;,
  0.437500;0.000000;,
  0.500000;0.125000;,
  0.562500;0.000000;,
  0.625000;0.125000;,
  0.687500;0.000000;,
  0.750000;0.125000;,
  0.812500;0.000000;,
  0.875000;0.125000;,
  0.937500;0.000000;,
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
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;;
 }
}
