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
 158;
 -0.92192;0.93335;0.00000;,
 -0.66982;0.86242;-0.25211;,
 -0.92192;0.86242;-0.35653;,
 -0.92192;0.93335;0.00000;,
 -0.56539;0.86242;0.00000;,
 -0.92192;0.93335;0.00000;,
 -0.66982;0.86242;0.25211;,
 -0.92192;0.93335;0.00000;,
 -0.92192;0.86242;0.35653;,
 -0.92192;0.93335;0.00000;,
 -1.17403;0.86242;0.25211;,
 -0.92192;0.93335;0.00000;,
 -1.27846;0.86242;-0.00000;,
 -0.92192;0.93335;0.00000;,
 -1.17403;0.86242;-0.25211;,
 -0.92192;0.93335;0.00000;,
 -0.92192;0.86242;-0.35653;,
 -0.45609;0.66046;-0.46583;,
 -0.92192;0.66046;-0.65879;,
 -0.26314;0.66046;0.00000;,
 -0.45609;0.66046;0.46583;,
 -0.92192;0.66046;0.65879;,
 -1.38776;0.66046;0.46583;,
 -1.58071;0.66046;-0.00000;,
 -1.38776;0.66046;-0.46583;,
 -0.92192;0.66046;-0.65879;,
 -0.31328;0.35821;-0.60864;,
 -0.92192;0.35821;-0.86075;,
 -0.06118;0.35821;0.00000;,
 -0.31328;0.35821;0.60864;,
 -0.92192;0.35821;0.86075;,
 -1.53056;0.35821;0.60864;,
 -1.78267;0.35821;-0.00000;,
 -1.53056;0.35821;-0.60864;,
 -0.92192;0.35821;-0.86075;,
 -0.26314;0.00168;-0.65879;,
 -0.92192;0.00168;-0.93167;,
 0.00974;0.00168;0.00000;,
 -0.26314;0.00168;0.65879;,
 -0.92192;0.00168;0.93167;,
 -1.58071;0.00168;0.65879;,
 -1.85359;0.00168;-0.00000;,
 -1.58071;0.00168;-0.65879;,
 -0.92192;0.00168;-0.93167;,
 -0.31328;-0.35486;-0.60864;,
 -0.92192;-0.35486;-0.86075;,
 -0.06118;-0.35486;0.00000;,
 -0.31328;-0.35486;0.60864;,
 -0.92192;-0.35486;0.86075;,
 -1.53056;-0.35486;0.60864;,
 -1.78267;-0.35486;-0.00000;,
 -1.53056;-0.35486;-0.60864;,
 -0.92192;-0.35486;-0.86075;,
 -0.45609;-0.65711;-0.46583;,
 -0.92192;-0.65711;-0.65879;,
 -0.26314;-0.65711;0.00000;,
 -0.45609;-0.65711;0.46583;,
 -0.92192;-0.65711;0.65879;,
 -1.38776;-0.65711;0.46583;,
 -1.58071;-0.65711;-0.00000;,
 -1.38776;-0.65711;-0.46583;,
 -0.92192;-0.65711;-0.65879;,
 -0.66982;-0.85907;-0.25211;,
 -0.92192;-0.85907;-0.35653;,
 -0.56539;-0.85907;0.00000;,
 -0.66982;-0.85907;0.25211;,
 -0.92192;-0.85907;0.35653;,
 -1.17403;-0.85907;0.25211;,
 -1.27846;-0.85907;-0.00000;,
 -1.17403;-0.85907;-0.25211;,
 -0.92192;-0.85907;-0.35653;,
 -0.92192;-0.92999;0.00000;,
 -0.92192;-0.92999;0.00000;,
 -0.92192;-0.92999;0.00000;,
 -0.92192;-0.92999;0.00000;,
 -0.92192;-0.92999;0.00000;,
 -0.92192;-0.92999;0.00000;,
 -0.92192;-0.92999;0.00000;,
 -0.92192;-0.92999;0.00000;,
 -1.76735;1.24104;0.00000;,
 -1.65553;0.98805;-0.31871;,
 -1.76735;0.98805;-0.45072;,
 -1.76735;1.24104;0.00000;,
 -1.60921;0.98805;0.00000;,
 -1.76735;1.24104;0.00000;,
 -1.65553;0.98805;0.31871;,
 -1.76735;1.24104;0.00000;,
 -1.76735;0.98805;0.45072;,
 -1.76735;1.24104;0.00000;,
 -1.87916;0.98805;0.31871;,
 -1.76735;1.24104;0.00000;,
 -1.92548;0.98805;-0.00000;,
 -1.76735;1.24104;0.00000;,
 -1.87916;0.98805;-0.31871;,
 -1.76735;1.24104;0.00000;,
 -1.76735;0.98805;-0.45072;,
 -1.56073;0.26759;-0.58889;,
 -1.76735;0.26759;-0.83282;,
 -1.47515;0.26759;0.00000;,
 -1.56073;0.26759;0.58889;,
 -1.76735;0.26759;0.83282;,
 -1.97396;0.26759;0.58889;,
 -2.05954;0.26759;-0.00000;,
 -1.97396;0.26759;-0.58889;,
 -1.76735;0.26759;-0.83282;,
 -1.49739;-0.81067;-0.76942;,
 -1.76735;-0.81067;-1.08813;,
 -1.38557;-0.81067;0.00000;,
 -1.49739;-0.81067;0.76942;,
 -1.76735;-0.81067;1.08813;,
 -2.03730;-0.81067;0.76942;,
 -2.14912;-0.81067;-0.00000;,
 -2.03730;-0.81067;-0.76942;,
 -1.76735;-0.81067;-1.08813;,
 -1.47515;-2.08255;-0.83282;,
 -1.76735;-2.08255;-1.17778;,
 -1.35411;-2.08255;0.00000;,
 -1.47515;-2.08255;0.83282;,
 -1.76735;-2.08255;1.17778;,
 -2.05954;-2.08255;0.83282;,
 -2.18058;-2.08255;-0.00000;,
 -2.05954;-2.08255;-0.83282;,
 -1.76735;-2.08255;-1.17778;,
 -1.49739;-3.35443;-0.76942;,
 -1.76735;-3.35443;-1.08813;,
 -1.38557;-3.35443;0.00000;,
 -1.49739;-3.35443;0.76942;,
 -1.76735;-3.35443;1.08813;,
 -2.03730;-3.35443;0.76942;,
 -2.14912;-3.35443;-0.00000;,
 -2.03730;-3.35443;-0.76942;,
 -1.76735;-3.35443;-1.08813;,
 -1.56073;-4.43268;-0.58889;,
 -1.76735;-4.43268;-0.83282;,
 -1.47515;-4.43268;0.00000;,
 -1.56073;-4.43268;0.58889;,
 -1.76735;-4.43268;0.83282;,
 -1.97396;-4.43268;0.58889;,
 -2.05954;-4.43268;-0.00000;,
 -1.97396;-4.43268;-0.58889;,
 -1.76735;-4.43268;-0.83282;,
 -1.65553;-5.15314;-0.31871;,
 -1.76735;-5.15314;-0.45072;,
 -1.60921;-5.15314;0.00000;,
 -1.65553;-5.15314;0.31871;,
 -1.76735;-5.15314;0.45072;,
 -1.87916;-5.15314;0.31871;,
 -1.92548;-5.15314;-0.00000;,
 -1.87916;-5.15314;-0.31871;,
 -1.76735;-5.15314;-0.45072;,
 -1.76735;-5.40613;0.00000;,
 -1.76735;-5.40613;0.00000;,
 -1.76735;-5.40613;0.00000;,
 -1.76735;-5.40613;0.00000;,
 -1.76735;-5.40613;0.00000;,
 -1.76735;-5.40613;0.00000;,
 -1.76735;-5.40613;0.00000;,
 -1.76735;-5.40613;0.00000;;
 
 128;
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
 3;69,70,78;,
 3;79,80,81;,
 3;82,83,80;,
 3;84,85,83;,
 3;86,87,85;,
 3;88,89,87;,
 3;90,91,89;,
 3;92,93,91;,
 3;94,95,93;,
 4;81,80,96,97;,
 4;80,83,98,96;,
 4;83,85,99,98;,
 4;85,87,100,99;,
 4;87,89,101,100;,
 4;89,91,102,101;,
 4;91,93,103,102;,
 4;93,95,104,103;,
 4;97,96,105,106;,
 4;96,98,107,105;,
 4;98,99,108,107;,
 4;99,100,109,108;,
 4;100,101,110,109;,
 4;101,102,111,110;,
 4;102,103,112,111;,
 4;103,104,113,112;,
 4;106,105,114,115;,
 4;105,107,116,114;,
 4;107,108,117,116;,
 4;108,109,118,117;,
 4;109,110,119,118;,
 4;110,111,120,119;,
 4;111,112,121,120;,
 4;112,113,122,121;,
 4;115,114,123,124;,
 4;114,116,125,123;,
 4;116,117,126,125;,
 4;117,118,127,126;,
 4;118,119,128,127;,
 4;119,120,129,128;,
 4;120,121,130,129;,
 4;121,122,131,130;,
 4;124,123,132,133;,
 4;123,125,134,132;,
 4;125,126,135,134;,
 4;126,127,136,135;,
 4;127,128,137,136;,
 4;128,129,138,137;,
 4;129,130,139,138;,
 4;130,131,140,139;,
 4;133,132,141,142;,
 4;132,134,143,141;,
 4;134,135,144,143;,
 4;135,136,145,144;,
 4;136,137,146,145;,
 4;137,138,147,146;,
 4;138,139,148,147;,
 4;139,140,149,148;,
 3;142,141,150;,
 3;141,143,151;,
 3;143,144,152;,
 3;144,145,153;,
 3;145,146,154;,
 3;146,147,155;,
 3;147,148,156;,
 3;148,149,157;;
 
 MeshMaterialList {
  2;
  128;
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
  0,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.103529;0.225882;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  132;
  -0.000000;1.000000;0.000000;,
  -0.000000;0.924733;-0.380616;,
  0.269136;0.924733;-0.269136;,
  0.380616;0.924733;-0.000000;,
  0.269136;0.924733;0.269136;,
  -0.000000;0.924733;0.380616;,
  -0.269136;0.924733;0.269136;,
  -0.380616;0.924733;0.000000;,
  -0.269136;0.924733;-0.269136;,
  -0.000000;0.709230;-0.704977;,
  0.498495;0.709230;-0.498493;,
  0.704978;0.709229;-0.000000;,
  0.498495;0.709230;0.498493;,
  -0.000000;0.709230;0.704977;,
  -0.498494;0.709230;0.498494;,
  -0.704977;0.709230;0.000000;,
  -0.498494;0.709230;-0.498494;,
  -0.000000;0.384551;-0.923104;,
  0.652734;0.384550;-0.652732;,
  0.923105;0.384549;0.000000;,
  0.652734;0.384550;0.652732;,
  -0.000000;0.384551;0.923104;,
  -0.652733;0.384551;0.652733;,
  -0.923104;0.384551;0.000000;,
  -0.652733;0.384551;-0.652733;,
  0.000000;0.000000;-1.000000;,
  0.707108;0.000000;-0.707106;,
  1.000000;0.000000;0.000000;,
  0.707108;0.000000;0.707106;,
  -0.000000;0.000000;1.000000;,
  -0.707107;0.000000;0.707106;,
  -1.000000;0.000000;0.000000;,
  -0.707107;0.000000;-0.707106;,
  -0.000000;-0.384551;-0.923104;,
  0.652734;-0.384550;-0.652732;,
  0.923105;-0.384549;0.000000;,
  0.652734;-0.384550;0.652732;,
  -0.000000;-0.384550;0.923104;,
  -0.652733;-0.384551;0.652733;,
  -0.923104;-0.384551;0.000000;,
  -0.652733;-0.384551;-0.652733;,
  -0.000000;-0.709229;-0.704978;,
  0.498496;-0.709229;-0.498494;,
  0.704980;-0.709227;-0.000000;,
  0.498496;-0.709229;0.498494;,
  -0.000000;-0.709229;0.704978;,
  -0.498495;-0.709229;0.498495;,
  -0.704979;-0.709229;-0.000000;,
  -0.498495;-0.709229;-0.498495;,
  -0.000000;-0.924734;-0.380614;,
  0.269136;-0.924734;-0.269135;,
  0.380615;-0.924733;-0.000000;,
  0.269136;-0.924734;0.269135;,
  -0.000000;-0.924734;0.380614;,
  -0.269135;-0.924734;0.269135;,
  -0.380615;-0.924734;-0.000000;,
  -0.269136;-0.924734;-0.269135;,
  -0.000000;-1.000000;0.000000;,
  0.723319;0.690514;0.000000;,
  0.632793;0.558819;-0.535999;,
  0.808731;0.475716;-0.345903;,
  0.931765;0.363062;0.000000;,
  0.808731;0.475716;0.345903;,
  0.632793;0.558819;0.535999;,
  -0.808732;0.475715;0.345903;,
  -0.931765;0.363062;0.000000;,
  -0.808732;0.475715;-0.345903;,
  0.740993;0.238721;-0.627648;,
  0.895913;0.192601;-0.400306;,
  0.991111;0.133040;0.000000;,
  0.895913;0.192600;0.400306;,
  0.740993;0.238721;0.627648;,
  -0.895913;0.192601;0.400306;,
  -0.991110;0.133041;0.000000;,
  -0.895913;0.192601;-0.400306;,
  0.759341;0.098535;-0.643189;,
  0.909056;0.078926;-0.409131;,
  0.998553;0.053781;0.000000;,
  0.909056;0.078926;0.409131;,
  0.759341;0.098535;0.643189;,
  -0.909056;0.078927;0.409131;,
  -0.998553;0.053781;0.000000;,
  -0.909056;0.078927;-0.409131;,
  0.763055;0.000000;-0.646334;,
  0.911681;0.000000;-0.410898;,
  1.000000;0.000000;0.000000;,
  0.911681;0.000000;0.410898;,
  0.763055;0.000000;0.646334;,
  -0.911681;0.000000;0.410898;,
  -1.000000;0.000000;0.000000;,
  -0.911681;0.000000;-0.410898;,
  0.759341;-0.098535;-0.643189;,
  0.909056;-0.078927;-0.409131;,
  0.998553;-0.053781;0.000000;,
  0.909056;-0.078927;0.409131;,
  0.759341;-0.098535;0.643189;,
  -0.909056;-0.078927;0.409131;,
  -0.998553;-0.053781;0.000000;,
  -0.909056;-0.078927;-0.409131;,
  0.740993;-0.238721;-0.627648;,
  0.895913;-0.192601;-0.400306;,
  0.991111;-0.133041;0.000000;,
  0.895913;-0.192601;0.400306;,
  0.740993;-0.238721;0.627648;,
  -0.895913;-0.192601;0.400306;,
  -0.991111;-0.133041;-0.000000;,
  -0.895913;-0.192601;-0.400306;,
  0.632793;-0.558819;-0.535999;,
  0.808731;-0.475716;-0.345903;,
  0.931765;-0.363062;0.000000;,
  0.808731;-0.475716;0.345903;,
  0.632793;-0.558819;0.535999;,
  -0.808732;-0.475715;0.345903;,
  -0.931765;-0.363062;-0.000000;,
  -0.808732;-0.475715;-0.345903;,
  0.723319;-0.690514;-0.000000;,
  -0.723321;0.690512;0.000000;,
  -0.632795;0.558818;0.535997;,
  -0.632795;0.558818;-0.535997;,
  -0.740994;0.238720;0.627646;,
  -0.740994;0.238720;-0.627647;,
  -0.759341;0.098535;0.643188;,
  -0.759342;0.098535;-0.643188;,
  -0.763055;0.000000;0.646334;,
  -0.763055;0.000000;-0.646334;,
  -0.759341;-0.098535;0.643188;,
  -0.759342;-0.098535;-0.643188;,
  -0.740994;-0.238721;0.627646;,
  -0.740994;-0.238721;-0.627646;,
  -0.632795;-0.558818;0.535997;,
  -0.632795;-0.558818;-0.535997;,
  -0.723321;-0.690512;0.000000;;
  128;
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,6,5;,
  3;0,7,6;,
  3;0,8,7;,
  3;0,1,8;,
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,8,16,15;,
  4;8,1,9,16;,
  4;9,10,18,17;,
  4;10,11,19,18;,
  4;11,12,20,19;,
  4;12,13,21,20;,
  4;13,14,22,21;,
  4;14,15,23,22;,
  4;15,16,24,23;,
  4;16,9,17,24;,
  4;17,18,26,25;,
  4;18,19,27,26;,
  4;19,20,28,27;,
  4;20,21,29,28;,
  4;21,22,30,29;,
  4;22,23,31,30;,
  4;23,24,32,31;,
  4;24,17,25,32;,
  4;25,26,34,33;,
  4;26,27,35,34;,
  4;27,28,36,35;,
  4;28,29,37,36;,
  4;29,30,38,37;,
  4;30,31,39,38;,
  4;31,32,40,39;,
  4;32,25,33,40;,
  4;33,34,42,41;,
  4;34,35,43,42;,
  4;35,36,44,43;,
  4;36,37,45,44;,
  4;37,38,46,45;,
  4;38,39,47,46;,
  4;39,40,48,47;,
  4;40,33,41,48;,
  4;41,42,50,49;,
  4;42,43,51,50;,
  4;43,44,52,51;,
  4;44,45,53,52;,
  4;45,46,54,53;,
  4;46,47,55,54;,
  4;47,48,56,55;,
  4;48,41,49,56;,
  3;49,50,57;,
  3;50,51,57;,
  3;51,52,57;,
  3;52,53,57;,
  3;53,54,57;,
  3;54,55,57;,
  3;55,56,57;,
  3;56,49,57;,
  3;58,60,59;,
  3;58,61,60;,
  3;58,62,61;,
  3;58,63,62;,
  3;116,64,117;,
  3;116,65,64;,
  3;116,66,65;,
  3;116,118,66;,
  4;59,60,68,67;,
  4;60,61,69,68;,
  4;61,62,70,69;,
  4;62,63,71,70;,
  4;117,64,72,119;,
  4;64,65,73,72;,
  4;65,66,74,73;,
  4;66,118,120,74;,
  4;67,68,76,75;,
  4;68,69,77,76;,
  4;69,70,78,77;,
  4;70,71,79,78;,
  4;119,72,80,121;,
  4;72,73,81,80;,
  4;73,74,82,81;,
  4;74,120,122,82;,
  4;75,76,84,83;,
  4;76,77,85,84;,
  4;77,78,86,85;,
  4;78,79,87,86;,
  4;121,80,88,123;,
  4;80,81,89,88;,
  4;81,82,90,89;,
  4;82,122,124,90;,
  4;83,84,92,91;,
  4;84,85,93,92;,
  4;85,86,94,93;,
  4;86,87,95,94;,
  4;123,88,96,125;,
  4;88,89,97,96;,
  4;89,90,98,97;,
  4;90,124,126,98;,
  4;91,92,100,99;,
  4;92,93,101,100;,
  4;93,94,102,101;,
  4;94,95,103,102;,
  4;125,96,104,127;,
  4;96,97,105,104;,
  4;97,98,106,105;,
  4;98,126,128,106;,
  4;99,100,108,107;,
  4;100,101,109,108;,
  4;101,102,110,109;,
  4;102,103,111,110;,
  4;127,104,112,129;,
  4;104,105,113,112;,
  4;105,106,114,113;,
  4;106,128,130,114;,
  3;107,108,115;,
  3;108,109,115;,
  3;109,110,115;,
  3;110,111,115;,
  3;129,112,131;,
  3;112,113,131;,
  3;113,114,131;,
  3;114,130,131;;
 }
 MeshTextureCoords {
  158;
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
  0.937500;1.000000;,
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
