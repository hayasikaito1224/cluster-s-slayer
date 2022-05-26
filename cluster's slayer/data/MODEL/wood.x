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
 175;
 51.49302;173.11226;-5.37812;,
 22.43527;129.38202;-10.53589;,
 17.27749;129.38202;-12.67231;,
 51.49302;173.11226;-5.37812;,
 24.57165;129.38202;-5.37812;,
 51.49302;173.11226;-5.37812;,
 22.43527;129.38202;-0.22036;,
 51.49302;173.11226;-5.37812;,
 17.27749;129.38202;1.91607;,
 51.49302;173.11226;-5.37812;,
 12.11967;129.38202;-0.22036;,
 51.49302;173.11226;-5.37812;,
 9.98328;129.38202;-5.37812;,
 51.49302;173.11226;-5.37812;,
 12.11967;129.38202;-10.53589;,
 51.49302;173.11226;-5.37812;,
 17.27749;129.38202;-12.67231;,
 4.00797;97.21978;-17.15203;,
 12.33339;97.21978;-13.70354;,
 12.98621;-0.59632;-14.48552;,
 3.87881;-0.59632;-18.25793;,
 4.00797;97.21978;-17.15203;,
 3.87881;-0.59632;-18.25793;,
 -5.22858;-0.59632;-14.48552;,
 -4.31741;97.21978;-13.70351;,
 15.78188;97.21978;-5.37812;,
 16.75861;-0.59632;-5.37812;,
 -9.00100;-0.59632;-5.37812;,
 -7.76590;97.21978;-5.37812;,
 12.33339;97.21978;2.94729;,
 12.98621;-0.59632;3.72927;,
 -5.22858;-0.59632;3.72927;,
 -4.31741;97.21978;2.94726;,
 4.00797;97.21978;6.39579;,
 3.87881;-0.59632;7.50169;,
 2.20122;127.19160;49.45649;,
 7.84029;132.59912;35.38204;,
 8.52037;134.14844;35.18553;,
 2.20122;127.19160;49.45649;,
 6.30999;131.90985;35.09064;,
 2.20122;127.19160;49.45649;,
 4.82621;132.48412;34.48232;,
 2.20122;127.19160;49.45649;,
 4.25805;133.98572;33.91307;,
 2.20122;127.19160;49.45649;,
 4.93834;135.53504;33.71656;,
 2.20122;127.19160;49.45649;,
 6.46851;136.22442;34.00787;,
 2.20122;127.19160;49.45649;,
 7.95238;135.65009;34.61628;,
 2.20122;127.19160;49.45649;,
 8.52037;134.14844;35.18553;,
 12.78004;135.73711;25.49535;,
 11.68199;133.23639;25.81244;,
 20.43875;125.79579;-1.73459;,
 21.64002;128.53153;-2.08145;,
 12.78004;135.73711;25.49535;,
 21.64002;128.53153;-2.08145;,
 20.63675;131.18306;-3.08652;,
 11.86301;138.16090;24.57658;,
 9.21197;132.12362;25.34225;,
 17.73679;124.57852;-2.24891;,
 18.01685;132.19712;-4.16088;,
 9.46803;139.08800;23.59445;,
 6.81697;133.05072;24.36011;,
 15.11680;125.59271;-3.32331;,
 15.31483;130.97998;-4.67524;,
 6.99801;137.97531;23.12426;,
 5.89993;135.47445;23.44146;,
 14.11357;128.24419;-4.32838;,
 49.89417;147.31374;-43.46041;,
 38.55031;145.61138;-32.16668;,
 37.56248;146.89495;-31.63905;,
 49.89417;147.31374;-43.46041;,
 39.96765;144.86549;-31.58650;,
 49.89417;147.31374;-43.46041;,
 40.98403;145.09398;-30.23882;,
 49.89417;147.31374;-43.46041;,
 41.00414;146.16310;-28.91286;,
 49.89417;147.31374;-43.46041;,
 40.01620;147.44661;-28.38538;,
 49.89417;147.31374;-43.46041;,
 38.59891;148.19252;-28.96541;,
 49.89417;147.31374;-43.46041;,
 37.58244;147.96406;-30.31314;,
 49.89417;147.31374;-43.46041;,
 37.56248;146.89495;-31.63905;,
 29.81778;143.82963;-24.91671;,
 31.41245;141.75796;-25.76797;,
 14.73610;122.43828;-10.29126;,
 12.99154;124.70473;-9.35997;,
 29.81778;143.82963;-24.91671;,
 12.99154;124.70473;-9.35997;,
 13.02703;126.59256;-7.01861;,
 29.85017;145.55543;-22.77635;,
 33.70018;140.55369;-24.83178;,
 17.23867;121.12107;-9.26710;,
 14.82167;126.99607;-4.63886;,
 31.49070;145.92421;-20.60097;,
 35.34072;140.92268;-22.65624;,
 19.03334;121.52457;-6.88732;,
 17.32431;125.67882;-3.61462;,
 33.77846;144.72020;-19.66469;,
 35.37321;142.64834;-20.51609;,
 19.06879;123.41243;-4.54594;,
 -55.81751;152.23881;-15.20865;,
 -35.26295;147.05425;-11.63371;,
 -33.69771;148.56527;-10.96888;,
 -55.81751;152.23881;-15.20865;,
 -35.86539;146.13303;-13.62461;,
 -55.81751;152.23881;-15.20865;,
 -35.15260;146.34105;-15.77480;,
 -55.81751;152.23881;-15.20865;,
 -33.54163;147.55637;-16.82498;,
 -55.81751;152.23881;-15.20865;,
 -31.97647;149.06721;-16.15986;,
 -55.81751;152.23881;-15.20865;,
 -31.37393;149.98874;-14.16915;,
 -55.81751;152.23881;-15.20865;,
 -32.08683;149.78067;-12.01888;,
 -55.81751;152.23881;-15.20865;,
 -33.69771;148.56527;-10.96888;,
 -21.08223;142.65847;-7.76192;,
 -23.60849;140.21977;-8.83550;,
 2.27040;110.52838;-2.70695;,
 5.03403;113.19641;-1.53245;,
 -21.08223;142.65847;-7.76192;,
 5.03403;113.19641;-1.53245;,
 7.87840;115.34271;-3.38678;,
 -18.48200;144.62039;-9.45700;,
 -24.58122;138.73242;-12.04883;,
 1.20629;108.90165;-6.22204;,
 9.13735;115.70980;-7.18348;,
 -17.33129;144.95595;-12.92764;,
 -23.43033;139.06809;-15.51957;,
 2.46519;109.26891;-10.01880;,
 8.07333;114.08296;-10.69869;,
 -18.30388;143.46892;-16.14103;,
 -20.83033;141.02993;-17.21461;,
 5.30967;111.41489;-11.87310;,
 -37.11073;155.87763;-30.26465;,
 -31.95075;149.50227;-27.72231;,
 -31.65396;148.85080;-28.28189;,
 -37.11073;155.87763;-30.26465;,
 -32.62237;149.56970;-27.11401;,
 -37.11073;155.87763;-30.26465;,
 -33.27522;149.01395;-26.81330;,
 -37.11073;155.87763;-30.26465;,
 -33.52693;148.16020;-26.99628;,
 -37.11073;155.87763;-30.26465;,
 -33.23007;147.50880;-27.55590;,
 -37.11073;155.87763;-30.26465;,
 -32.55849;147.44127;-28.16427;,
 -37.11073;155.87763;-30.26465;,
 -31.90558;147.99716;-28.46496;,
 -37.11073;155.87763;-30.26465;,
 -31.65396;148.85080;-28.28189;,
 -27.80637;145.37644;-25.88926;,
 -28.28558;146.42785;-24.98602;,
 -18.41239;141.23694;-13.62495;,
 -17.88818;140.08675;-14.61320;,
 -27.80637;145.37644;-25.88926;,
 -17.88818;140.08675;-14.61320;,
 -18.33265;138.57926;-14.93648;,
 -28.21265;143.99828;-26.18477;,
 -29.36958;146.53693;-24.00401;,
 -19.59829;141.35633;-12.55092;,
 -19.48545;137.59777;-14.40553;,
 -29.26638;143.10125;-25.69922;,
 -30.42339;145.63957;-23.51865;,
 -20.75105;140.37478;-12.01989;,
 -20.67130;137.71713;-13.33131;,
 -30.35044;143.21030;-24.71734;,
 -30.82972;144.26179;-23.81407;,
 -21.19549;138.86742;-12.34302;;
 
 120;
 3;0,1,2;,
 3;3,4,1;,
 3;5,6,4;,
 3;7,8,6;,
 3;9,10,8;,
 3;11,12,10;,
 3;13,14,12;,
 3;15,16,14;,
 4;17,2,1,18;,
 4;17,18,19,20;,
 4;21,22,23,24;,
 4;21,24,14,16;,
 4;18,1,4,25;,
 4;18,25,26,19;,
 4;24,23,27,28;,
 4;24,28,12,14;,
 4;25,4,6,29;,
 4;25,29,30,26;,
 4;28,27,31,32;,
 4;28,32,10,12;,
 4;29,6,8,33;,
 4;29,33,34,30;,
 4;32,31,34,33;,
 4;32,33,8,10;,
 3;35,36,37;,
 3;38,39,36;,
 3;40,41,39;,
 3;42,43,41;,
 3;44,45,43;,
 3;46,47,45;,
 3;48,49,47;,
 3;50,51,49;,
 4;52,37,36,53;,
 4;52,53,54,55;,
 4;56,57,58,59;,
 4;56,59,49,51;,
 4;53,36,39,60;,
 4;53,60,61,54;,
 4;59,58,62,63;,
 4;59,63,47,49;,
 4;60,39,41,64;,
 4;60,64,65,61;,
 4;63,62,66,67;,
 4;63,67,45,47;,
 4;64,41,43,68;,
 4;64,68,69,65;,
 4;67,66,69,68;,
 4;67,68,43,45;,
 3;70,71,72;,
 3;73,74,71;,
 3;75,76,74;,
 3;77,78,76;,
 3;79,80,78;,
 3;81,82,80;,
 3;83,84,82;,
 3;85,86,84;,
 4;87,72,71,88;,
 4;87,88,89,90;,
 4;91,92,93,94;,
 4;91,94,84,86;,
 4;88,71,74,95;,
 4;88,95,96,89;,
 4;94,93,97,98;,
 4;94,98,82,84;,
 4;95,74,76,99;,
 4;95,99,100,96;,
 4;98,97,101,102;,
 4;98,102,80,82;,
 4;99,76,78,103;,
 4;99,103,104,100;,
 4;102,101,104,103;,
 4;102,103,78,80;,
 3;105,106,107;,
 3;108,109,106;,
 3;110,111,109;,
 3;112,113,111;,
 3;114,115,113;,
 3;116,117,115;,
 3;118,119,117;,
 3;120,121,119;,
 4;122,107,106,123;,
 4;122,123,124,125;,
 4;126,127,128,129;,
 4;126,129,119,121;,
 4;123,106,109,130;,
 4;123,130,131,124;,
 4;129,128,132,133;,
 4;129,133,117,119;,
 4;130,109,111,134;,
 4;130,134,135,131;,
 4;133,132,136,137;,
 4;133,137,115,117;,
 4;134,111,113,138;,
 4;134,138,139,135;,
 4;137,136,139,138;,
 4;137,138,113,115;,
 3;140,141,142;,
 3;143,144,141;,
 3;145,146,144;,
 3;147,148,146;,
 3;149,150,148;,
 3;151,152,150;,
 3;153,154,152;,
 3;155,156,154;,
 4;157,142,141,158;,
 4;157,158,159,160;,
 4;161,162,163,164;,
 4;161,164,154,156;,
 4;158,141,144,165;,
 4;158,165,166,159;,
 4;164,163,167,168;,
 4;164,168,152,154;,
 4;165,144,146,169;,
 4;165,169,170,166;,
 4;168,167,171,172;,
 4;168,172,150,152;,
 4;169,146,148,173;,
 4;169,173,174,170;,
 4;172,171,174,173;,
 4;172,173,148,150;;
 
 MeshMaterialList {
  1;
  120;
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
   0.615200;0.266400;0.097600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  140;
  0.644839;-0.348233;-0.680380;,
  0.012438;0.143014;-0.989643;,
  0.673475;-0.249726;-0.695750;,
  0.916957;-0.398986;0.000000;,
  0.673475;-0.249726;0.695750;,
  0.012438;0.143014;0.989643;,
  -0.601404;0.485111;0.634808;,
  -0.806254;0.591570;0.000000;,
  -0.601404;0.485111;-0.634808;,
  0.000001;0.011305;-0.999936;,
  0.707070;0.010372;-0.707068;,
  0.999950;0.009985;0.000000;,
  0.707070;0.010372;0.707068;,
  0.000001;0.011305;0.999936;,
  -0.707053;0.012239;0.707054;,
  -0.999920;0.012626;0.000000;,
  -0.707053;0.012239;-0.707054;,
  0.003992;0.072820;-0.997337;,
  0.703194;-0.069329;-0.707609;,
  -0.686561;0.206818;-0.697037;,
  0.991723;-0.128398;0.000000;,
  -0.966228;0.257689;0.000000;,
  0.703194;-0.069329;0.707609;,
  -0.686561;0.206818;0.697037;,
  0.003992;0.072820;0.997337;,
  0.644839;-0.348233;0.680380;,
  -0.670023;0.667699;0.324417;,
  -0.348514;0.413030;-0.841394;,
  0.728149;-0.684820;0.028627;,
  0.906306;0.058910;0.418496;,
  0.713668;-0.688074;0.131272;,
  0.081416;-0.985815;-0.146764;,
  -0.618792;-0.738957;-0.266533;,
  -0.988995;-0.013471;-0.147334;,
  -0.725186;0.677683;0.121864;,
  -0.140455;0.925333;0.352180;,
  0.490585;0.724073;0.484814;,
  0.954278;0.039289;0.296327;,
  0.648910;-0.657008;0.383740;,
  -0.038481;-0.966831;0.252501;,
  -0.705225;-0.708686;-0.020512;,
  -0.960745;-0.033803;-0.275365;,
  -0.655359;0.662496;-0.362772;,
  0.032024;0.972301;-0.231530;,
  0.698741;0.714172;0.041470;,
  0.934055;0.050290;0.353570;,
  0.672365;-0.672604;0.309080;,
  0.632781;0.741241;0.223942;,
  0.001382;-0.992501;0.122229;,
  -0.039263;0.999222;0.003805;,
  -0.682808;-0.724331;-0.095482;,
  -0.702147;0.690299;-0.174575;,
  -0.975990;-0.022624;-0.216638;,
  -0.574876;-0.734589;-0.360412;,
  -0.477740;0.799935;0.363137;,
  0.700027;0.468940;0.538570;,
  -0.520923;-0.594229;-0.612806;,
  -0.682046;0.245500;-0.688871;,
  -0.469368;-0.549714;-0.691020;,
  0.060712;-0.942199;-0.329508;,
  0.606544;-0.778524;0.161258;,
  0.848333;-0.079983;0.523388;,
  0.574942;0.657398;0.487104;,
  0.080158;0.983401;0.162778;,
  -0.406720;0.866130;-0.290512;,
  -0.766876;0.171670;-0.618410;,
  -0.323527;-0.405580;-0.854889;,
  0.313030;-0.740999;-0.594081;,
  0.769888;-0.638080;0.011248;,
  0.779424;-0.157134;0.606471;,
  0.336055;0.420131;0.842946;,
  -0.300485;0.755533;0.582133;,
  -0.757327;0.652624;-0.023165;,
  -0.729527;0.207863;-0.651601;,
  -0.369345;-0.453886;-0.810908;,
  -0.635365;0.760896;-0.131713;,
  0.233760;-0.823919;-0.516250;,
  -0.154208;0.888079;0.433054;,
  0.724912;-0.686570;0.055890;,
  0.442526;0.531700;0.722126;,
  0.812758;-0.120102;0.570088;,
  0.531211;-0.818002;0.220654;,
  0.415118;0.877234;0.241117;,
  -0.528682;0.664646;-0.527959;,
  -0.277185;-0.561119;0.779945;,
  -0.128985;0.266046;0.955292;,
  -0.363690;-0.504008;0.783394;,
  -0.431686;-0.890790;0.141919;,
  -0.327141;-0.740205;-0.587431;,
  -0.077012;-0.069932;-0.994575;,
  0.153570;0.642260;-0.750945;,
  0.221999;0.961863;-0.159798;,
  0.120217;0.857737;0.499835;,
  -0.033671;0.178091;0.983438;,
  -0.559608;-0.330918;0.759824;,
  -0.762080;-0.641177;0.090151;,
  -0.522469;-0.570930;-0.633297;,
  0.018852;-0.161330;-0.986720;,
  0.544799;0.347695;-0.763087;,
  0.747255;0.657937;-0.093425;,
  0.507660;0.587695;0.629997;,
  -0.076871;0.220714;0.972305;,
  -0.504524;-0.387443;0.771585;,
  0.365080;0.717065;0.593747;,
  -0.665285;-0.738518;0.109490;,
  0.561402;0.817904;-0.125940;,
  -0.467363;-0.627642;-0.622605;,
  0.401694;0.480467;-0.779611;,
  -0.024491;-0.117837;-0.992731;,
  -0.241427;-0.792113;-0.560598;,
  0.077759;0.874925;-0.477974;,
  -0.029113;0.675282;0.736985;,
  0.733168;0.659523;0.165813;,
  0.692504;0.346779;-0.632600;,
  0.684041;0.722593;0.099739;,
  0.220287;0.688582;0.690889;,
  -0.413574;0.317912;0.853164;,
  -0.868799;-0.228845;0.439111;,
  -0.782434;-0.561565;-0.269151;,
  -0.341534;-0.524975;-0.779587;,
  0.219089;-0.192284;-0.956570;,
  0.781838;0.294627;-0.549476;,
  0.532359;0.842965;-0.077487;,
  -0.033044;0.899741;0.435171;,
  -0.583149;0.431683;0.688176;,
  -0.795724;-0.287023;0.533330;,
  -0.546238;-0.835383;0.061320;,
  0.019115;-0.892165;-0.451304;,
  0.569240;-0.424128;-0.704331;,
  0.741912;0.318000;-0.590290;,
  0.581832;0.812998;-0.022508;,
  0.441315;-0.343603;-0.828962;,
  0.052142;0.846090;0.530484;,
  -0.132252;-0.780024;-0.611615;,
  -0.534526;0.401411;0.743741;,
  -0.658353;-0.749047;-0.074159;,
  -0.831550;-0.262123;0.489711;,
  -0.340172;0.263779;0.902609;,
  -0.647853;-0.471747;-0.598115;,
  0.419528;0.070424;-0.905007;;
  120;
  3;0,2,1;,
  3;0,3,2;,
  3;25,4,3;,
  3;25,5,4;,
  3;26,6,5;,
  3;26,7,6;,
  3;26,8,7;,
  3;27,1,8;,
  4;17,1,2,18;,
  4;17,18,10,9;,
  4;17,9,16,19;,
  4;17,19,8,1;,
  4;18,2,3,20;,
  4;18,20,11,10;,
  4;19,16,15,21;,
  4;19,21,7,8;,
  4;20,3,4,22;,
  4;20,22,12,11;,
  4;21,15,14,23;,
  4;21,23,6,7;,
  4;22,4,5,24;,
  4;22,24,13,12;,
  4;23,14,13,24;,
  4;23,24,5,6;,
  3;28,30,29;,
  3;28,31,30;,
  3;53,32,31;,
  3;53,33,32;,
  3;54,34,33;,
  3;54,35,34;,
  3;54,36,35;,
  3;55,29,36;,
  4;45,29,30,46;,
  4;45,46,38,37;,
  4;45,37,44,47;,
  4;45,47,36,29;,
  4;46,30,31,48;,
  4;46,48,39,38;,
  4;47,44,43,49;,
  4;47,49,35,36;,
  4;48,31,32,50;,
  4;48,50,40,39;,
  4;49,43,42,51;,
  4;49,51,34,35;,
  4;50,32,33,52;,
  4;50,52,41,40;,
  4;51,42,41,52;,
  4;51,52,33,34;,
  3;56,58,57;,
  3;56,59,58;,
  3;81,60,59;,
  3;81,61,60;,
  3;82,62,61;,
  3;82,63,62;,
  3;82,64,63;,
  3;83,57,64;,
  4;73,57,58,74;,
  4;73,74,66,65;,
  4;73,65,72,75;,
  4;73,75,64,57;,
  4;74,58,59,76;,
  4;74,76,67,66;,
  4;75,72,71,77;,
  4;75,77,63,64;,
  4;76,59,60,78;,
  4;76,78,68,67;,
  4;77,71,70,79;,
  4;77,79,62,63;,
  4;78,60,61,80;,
  4;78,80,69,68;,
  4;79,70,69,80;,
  4;79,80,61,62;,
  3;84,86,85;,
  3;84,87,86;,
  3;109,88,87;,
  3;109,89,88;,
  3;110,90,89;,
  3;110,91,90;,
  3;110,92,91;,
  3;111,85,92;,
  4;101,85,86,102;,
  4;101,102,94,93;,
  4;101,93,100,103;,
  4;101,103,92,85;,
  4;102,86,87,104;,
  4;102,104,95,94;,
  4;103,100,99,105;,
  4;103,105,91,92;,
  4;104,87,88,106;,
  4;104,106,96,95;,
  4;105,99,98,107;,
  4;105,107,90,91;,
  4;106,88,89,108;,
  4;106,108,97,96;,
  4;107,98,97,108;,
  4;107,108,89,90;,
  3;112,114,113;,
  3;112,115,114;,
  3;137,116,115;,
  3;137,117,116;,
  3;138,118,117;,
  3;138,119,118;,
  3;138,120,119;,
  3;139,113,120;,
  4;129,113,114,130;,
  4;129,130,122,121;,
  4;129,121,128,131;,
  4;129,131,120,113;,
  4;130,114,115,132;,
  4;130,132,123,122;,
  4;131,128,127,133;,
  4;131,133,119,120;,
  4;132,115,116,134;,
  4;132,134,124,123;,
  4;133,127,126,135;,
  4;133,135,118,119;,
  4;134,116,117,136;,
  4;134,136,125,124;,
  4;135,126,125,136;,
  4;135,136,117,118;;
 }
 MeshTextureCoords {
  175;
  0.062500;0.000000;,
  0.125000;0.000000;,
  0.000000;0.000000;,
  0.187500;0.000000;,
  0.250000;0.000000;,
  0.312500;0.000000;,
  0.375000;0.000000;,
  0.437500;0.000000;,
  0.500000;0.000000;,
  0.562500;0.000000;,
  0.625000;0.000000;,
  0.687500;0.000000;,
  0.750000;0.000000;,
  0.812500;0.000000;,
  0.875000;0.000000;,
  0.937500;0.000000;,
  1.000000;0.000000;,
  0.000000;0.599560;,
  0.125000;0.599560;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.599560;,
  1.000000;1.000000;,
  0.875000;1.000000;,
  0.875000;0.599560;,
  0.250000;0.599560;,
  0.250000;1.000000;,
  0.750000;1.000000;,
  0.750000;0.599560;,
  0.375000;0.599560;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.625000;0.599560;,
  0.500000;0.599560;,
  0.500000;1.000000;,
  0.062500;0.000000;,
  0.125000;0.000000;,
  0.000000;0.000000;,
  0.187500;0.000000;,
  0.250000;0.000000;,
  0.312500;0.000000;,
  0.375000;0.000000;,
  0.437500;0.000000;,
  0.500000;0.000000;,
  0.562500;0.000000;,
  0.625000;0.000000;,
  0.687500;0.000000;,
  0.750000;0.000000;,
  0.812500;0.000000;,
  0.875000;0.000000;,
  0.937500;0.000000;,
  1.000000;0.000000;,
  0.000000;0.599560;,
  0.125000;0.599560;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.599560;,
  1.000000;1.000000;,
  0.875000;1.000000;,
  0.875000;0.599560;,
  0.250000;0.599560;,
  0.250000;1.000000;,
  0.750000;1.000000;,
  0.750000;0.599560;,
  0.375000;0.599560;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.625000;0.599560;,
  0.500000;0.599560;,
  0.500000;1.000000;,
  0.062500;0.000000;,
  0.125000;0.000000;,
  0.000000;0.000000;,
  0.187500;0.000000;,
  0.250000;0.000000;,
  0.312500;0.000000;,
  0.375000;0.000000;,
  0.437500;0.000000;,
  0.500000;0.000000;,
  0.562500;0.000000;,
  0.625000;0.000000;,
  0.687500;0.000000;,
  0.750000;0.000000;,
  0.812500;0.000000;,
  0.875000;0.000000;,
  0.937500;0.000000;,
  1.000000;0.000000;,
  0.000000;0.599560;,
  0.125000;0.599560;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.599560;,
  1.000000;1.000000;,
  0.875000;1.000000;,
  0.875000;0.599560;,
  0.250000;0.599560;,
  0.250000;1.000000;,
  0.750000;1.000000;,
  0.750000;0.599560;,
  0.375000;0.599560;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.625000;0.599560;,
  0.500000;0.599560;,
  0.500000;1.000000;,
  0.062500;0.000000;,
  0.125000;0.000000;,
  0.000000;0.000000;,
  0.187500;0.000000;,
  0.250000;0.000000;,
  0.312500;0.000000;,
  0.375000;0.000000;,
  0.437500;0.000000;,
  0.500000;0.000000;,
  0.562500;0.000000;,
  0.625000;0.000000;,
  0.687500;0.000000;,
  0.750000;0.000000;,
  0.812500;0.000000;,
  0.875000;0.000000;,
  0.937500;0.000000;,
  1.000000;0.000000;,
  0.000000;0.599560;,
  0.125000;0.599560;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.599560;,
  1.000000;1.000000;,
  0.875000;1.000000;,
  0.875000;0.599560;,
  0.250000;0.599560;,
  0.250000;1.000000;,
  0.750000;1.000000;,
  0.750000;0.599560;,
  0.375000;0.599560;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.625000;0.599560;,
  0.500000;0.599560;,
  0.500000;1.000000;,
  0.062500;0.000000;,
  0.125000;0.000000;,
  0.000000;0.000000;,
  0.187500;0.000000;,
  0.250000;0.000000;,
  0.312500;0.000000;,
  0.375000;0.000000;,
  0.437500;0.000000;,
  0.500000;0.000000;,
  0.562500;0.000000;,
  0.625000;0.000000;,
  0.687500;0.000000;,
  0.750000;0.000000;,
  0.812500;0.000000;,
  0.875000;0.000000;,
  0.937500;0.000000;,
  1.000000;0.000000;,
  0.000000;0.599560;,
  0.125000;0.599560;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.599560;,
  1.000000;1.000000;,
  0.875000;1.000000;,
  0.875000;0.599560;,
  0.250000;0.599560;,
  0.250000;1.000000;,
  0.750000;1.000000;,
  0.750000;0.599560;,
  0.375000;0.599560;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.625000;0.599560;,
  0.500000;0.599560;,
  0.500000;1.000000;;
 }
}