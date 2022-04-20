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
 104;
 -6.26141;-2.16872;-4.73690;,
 -9.38167;-1.36599;-6.20349;,
 -9.38167;1.15407;-6.20349;,
 -6.26143;1.41392;-4.73690;,
 -9.38279;-1.38607;-6.21173;,
 -16.67035;-0.23113;-3.54082;,
 -16.67035;1.86183;-3.54082;,
 -9.34125;1.14949;-6.21173;,
 -23.73886;-0.23369;-3.44068;,
 -23.73886;1.43072;-3.44068;,
 -6.26143;1.41392;-4.73690;,
 -9.38167;1.15407;-6.20349;,
 -9.21522;2.81261;3.02384;,
 -6.86267;2.42300;4.02919;,
 -9.34125;1.14949;-6.21173;,
 -16.67035;1.86183;-3.54082;,
 -20.12990;1.86184;-0.13841;,
 -9.19084;2.80237;3.07206;,
 -23.73886;1.43072;-3.44068;,
 -24.20193;1.43073;-1.50084;,
 -6.86267;2.42300;4.02919;,
 -9.21522;2.81261;3.02384;,
 -9.21524;-2.01719;3.02384;,
 -6.86265;-2.97352;4.02919;,
 -9.19084;2.80237;3.07206;,
 -20.12990;1.86184;-0.13841;,
 -20.12990;-0.23113;-0.13841;,
 -9.23237;-2.01719;3.07206;,
 -24.20193;1.43073;-1.50084;,
 -24.20193;-0.23368;-1.50084;,
 -6.86265;-2.97352;4.02919;,
 -9.21524;-2.01719;3.02384;,
 -9.38167;-1.36599;-6.20349;,
 -6.26141;-2.16872;-4.73690;,
 -9.23237;-2.01719;3.07206;,
 -20.12990;-0.23113;-0.13841;,
 -16.67035;-0.23113;-3.54082;,
 -9.38279;-1.38607;-6.21173;,
 -6.26141;-2.16872;-4.73690;,
 -6.26143;1.41392;-4.73690;,
 -7.45703;2.15819;-0.60251;,
 -7.21810;1.55685;-4.27983;,
 -9.34676;1.40530;-5.28094;,
 -15.66100;1.86893;-3.02586;,
 -9.53816;2.55476;1.20176;,
 -7.79044;2.27287;-0.12718;,
 -16.22162;1.68011;-2.69583;,
 -18.49814;1.83980;-1.78252;,
 -9.42106;-1.98190;3.02265;,
 -7.62292;-2.73340;3.70528;,
 -7.62296;2.55227;3.70528;,
 -9.42105;2.87009;3.02265;,
 -7.62293;2.26866;0.75263;,
 -9.42104;2.82768;2.09947;,
 -9.32327;2.51020;1.01642;,
 -9.05531;2.51022;0.81701;,
 -17.67503;1.88253;-2.10327;,
 -18.08887;1.88255;-1.88957;,
 -8.62160;-2.33498;3.33310;,
 -8.31088;-2.48112;3.44909;,
 -8.31086;2.67932;3.44909;,
 -8.62160;2.74658;3.33310;,
 -8.45754;2.52992;1.38930;,
 -8.66607;2.59386;1.51037;,
 -5.56421;-1.38641;-1.30124;,
 -6.98648;-1.62913;-1.54397;,
 -6.98649;1.48300;-1.54397;,
 -5.56424;1.24027;-1.30124;,
 -5.56424;1.24027;-1.30124;,
 -6.98649;1.48300;-1.54397;,
 -6.98649;1.48300;1.56814;,
 -5.56424;1.24027;1.32544;,
 -5.56424;1.24027;1.32544;,
 -6.98649;1.48300;1.56814;,
 -6.98648;-1.62913;1.56814;,
 -5.56421;-1.38641;1.32544;,
 -0.99909;1.89188;-2.26895;,
 -0.99909;-1.90765;-2.26895;,
 -4.79864;-1.90765;-2.26895;,
 -4.79864;1.89188;-2.26895;,
 -0.99909;-1.90765;-2.26895;,
 -0.34911;-2.55764;-0.02929;,
 -5.44863;-2.55764;-0.02929;,
 -4.79864;-1.90765;-2.26895;,
 -0.99909;-1.90765;2.21037;,
 -4.79864;-1.90765;2.21037;,
 -0.99909;-1.90765;2.21037;,
 -0.99909;1.89188;2.21037;,
 -4.79864;1.89188;2.21037;,
 -4.79864;-1.90765;2.21037;,
 -0.99909;1.89188;2.21037;,
 -0.34911;2.54188;-0.02929;,
 -5.44863;2.54188;-0.02929;,
 -4.79864;1.89188;2.21037;,
 -0.99909;1.89188;-2.26895;,
 -4.79864;1.89188;-2.26895;,
 -0.34911;-2.55764;-0.02929;,
 -0.34911;2.54188;-0.02929;,
 -0.99909;-1.90765;-2.26895;,
 -0.99909;1.89188;-2.26895;,
 -5.44863;2.54188;-0.02929;,
 -5.44863;-2.55764;-0.02929;,
 -4.79864;1.89188;-2.26895;,
 -4.79864;-1.90765;-2.26895;;
 
 32;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;5,8,9,6;,
 4;10,11,12,13;,
 4;14,15,16,17;,
 4;15,18,19,16;,
 4;20,21,22,23;,
 4;24,25,26,27;,
 4;25,28,29,26;,
 4;30,31,32,33;,
 4;34,35,36,37;,
 4;30,38,39,13;,
 4;40,41,42,43;,
 4;44,45,46,47;,
 4;48,49,50,51;,
 4;51,50,52,53;,
 4;54,55,56,57;,
 4;58,59,60,61;,
 4;61,60,62,63;,
 4;64,65,66,67;,
 4;68,69,70,71;,
 4;72,73,74,75;,
 4;76,77,78,79;,
 4;80,81,82,83;,
 4;81,84,85,82;,
 4;86,87,88,89;,
 4;90,91,92,93;,
 4;91,94,95,92;,
 4;90,84,96,97;,
 4;97,96,98,99;,
 4;100,101,85,93;,
 4;102,103,101,100;;
 
 MeshMaterialList {
  5;
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
  2,
  2,
  2,
  2,
  1,
  1,
  1,
  2,
  2,
  2,
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
 }
 MeshNormals {
  39;
  0.425378;0.000001;-0.905016;,
  -0.342864;0.002812;-0.939381;,
  -0.181061;0.001426;-0.983471;,
  -0.014166;0.000000;-0.999900;,
  0.102856;0.985024;-0.138380;,
  -0.017206;0.992419;-0.121690;,
  -0.048475;0.995416;-0.082449;,
  -0.079621;0.995897;-0.043000;,
  -0.392964;0.000000;0.919554;,
  -0.281919;0.001216;0.959437;,
  -0.299658;0.000608;0.954046;,
  -0.317294;0.000001;0.948327;,
  0.009610;0.986635;-0.162660;,
  -0.007752;0.978462;-0.206282;,
  -0.354921;-0.000001;0.934896;,
  0.211027;0.975037;-0.069068;,
  -0.046638;0.996051;-0.075546;,
  -0.349716;0.000000;0.936856;,
  0.243454;0.965986;-0.087183;,
  0.168233;0.000001;-0.985747;,
  0.168234;0.985747;0.000000;,
  0.168212;0.000001;0.985751;,
  -0.277590;-0.956755;-0.086974;,
  -0.151690;-0.983842;-0.095108;,
  0.997656;0.000004;0.068427;,
  0.000000;0.000000;-1.000000;,
  -0.000000;-1.000000;0.000000;,
  -0.000000;-0.960373;0.278718;,
  0.000000;0.000000;1.000000;,
  -0.000000;1.000000;0.000000;,
  -0.000000;-0.960373;-0.278718;,
  -0.000000;0.960372;0.278721;,
  -0.000000;0.960372;-0.278721;,
  0.960375;0.000000;0.278712;,
  1.000000;0.000000;0.000000;,
  0.960375;0.000000;-0.278712;,
  -1.000000;0.000000;0.000000;,
  -0.960373;0.000000;0.278717;,
  -0.960373;0.000000;-0.278717;;
  32;
  4;0,0,0,0;,
  4;1,2,2,1;,
  4;2,3,3,2;,
  4;4,4,4,4;,
  4;5,6,6,5;,
  4;6,7,7,6;,
  4;8,8,8,8;,
  4;9,10,10,9;,
  4;10,11,11,10;,
  4;22,22,22,22;,
  4;23,23,23,23;,
  4;24,24,24,24;,
  4;12,12,12,12;,
  4;13,13,13,13;,
  4;14,14,14,14;,
  4;15,15,15,15;,
  4;16,16,16,16;,
  4;17,17,17,17;,
  4;18,18,18,18;,
  4;19,19,19,19;,
  4;20,20,20,20;,
  4;21,21,21,21;,
  4;25,25,25,25;,
  4;30,26,26,30;,
  4;26,27,27,26;,
  4;28,28,28,28;,
  4;31,29,29,31;,
  4;29,32,32,29;,
  4;33,33,34,34;,
  4;34,34,35,35;,
  4;36,36,37,37;,
  4;38,38,36,36;;
 }
 MeshTextureCoords {
  104;
  0.000000;0.000000;,
  0.000000;0.200000;,
  1.000000;0.200000;,
  1.000000;0.000000;,
  0.000000;0.600000;,
  0.000000;0.800000;,
  1.000000;0.800000;,
  1.000000;0.600000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.200000;,
  1.000000;0.200000;,
  1.000000;0.000000;,
  0.000000;0.600000;,
  0.000000;0.800000;,
  1.000000;0.800000;,
  1.000000;0.600000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.200000;,
  1.000000;0.200000;,
  1.000000;0.000000;,
  0.000000;0.600000;,
  0.000000;0.800000;,
  1.000000;0.800000;,
  1.000000;0.600000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.200000;,
  1.000000;0.200000;,
  1.000000;0.000000;,
  0.000000;0.600000;,
  0.000000;0.800000;,
  1.000000;0.800000;,
  1.000000;0.600000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.666670;1.000000;,
  0.666670;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.666670;1.000000;,
  0.666670;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
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
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.500000;,
  0.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.500000;,
  1.000000;0.500000;,
  0.000000;0.000000;,
  1.000000;0.000000;;
 }
}
