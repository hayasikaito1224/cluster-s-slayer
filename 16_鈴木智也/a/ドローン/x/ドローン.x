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
 124;
 -2.25905;8.66264;-12.46425;,
 -2.25905;2.96415;-8.56632;,
 -6.77715;4.62671;-7.52091;,
 -6.77715;10.53045;-5.54555;,
 2.25905;8.66264;-12.46425;,
 2.25905;2.96415;-8.56632;,
 6.77715;10.53045;-5.54555;,
 6.77715;4.62671;-7.52091;,
 4.77715;8.88638;11.34006;,
 2.25905;11.57535;9.02997;,
 2.25905;3.07121;10.87193;,
 4.77715;3.26738;8.65994;,
 -2.25905;11.57535;9.02997;,
 -2.25905;3.07121;10.87193;,
 -4.77715;8.88638;11.34006;,
 -4.77715;3.26738;8.65994;,
 -2.25905;11.57535;9.02997;,
 -2.25905;8.66264;-12.46425;,
 -6.77715;10.53045;-5.54555;,
 -4.77715;8.88638;11.34006;,
 2.25905;11.57535;9.02997;,
 2.25905;8.66264;-12.46425;,
 4.77715;8.88638;11.34006;,
 6.77715;10.53045;-5.54555;,
 -2.25905;2.96415;-8.56632;,
 -2.25905;3.07121;10.87193;,
 -4.77715;3.26738;8.65994;,
 -6.77715;4.62671;-7.52091;,
 2.25905;2.96415;-8.56632;,
 2.25905;3.07121;10.87193;,
 6.77715;4.62671;-7.52091;,
 4.77715;3.26738;8.65994;,
 1.21166;7.23427;-11.48759;,
 1.21166;6.87725;-11.26014;,
 0.78834;6.87725;-11.26014;,
 0.78834;7.23427;-11.48759;,
 7.04927;9.26689;-2.93937;,
 6.77715;10.53045;-5.54555;,
 5.72927;8.18181;8.20513;,
 5.72927;4.47327;6.43625;,
 6.77715;4.62671;-7.52091;,
 7.04927;5.37042;-4.24311;,
 -5.72927;8.18181;8.20513;,
 -6.77715;10.53045;-5.54555;,
 -7.04927;9.26689;-2.93937;,
 -6.77715;4.62671;-7.52091;,
 -7.04927;5.37042;-4.24311;,
 -5.72927;4.47327;6.43625;,
 -0.78834;7.23427;-11.48759;,
 -0.78834;6.87725;-11.26014;,
 -1.21166;6.87725;-11.26014;,
 -1.21166;7.23427;-11.48759;,
 -0.78834;5.22914;-10.12414;,
 -0.78834;4.88238;-9.88133;,
 -1.21166;4.88238;-9.88133;,
 -1.21166;5.22914;-10.12414;,
 1.21166;5.22914;-10.12414;,
 1.21166;4.88238;-9.88133;,
 0.78834;4.88238;-9.88133;,
 0.78834;5.22914;-10.12414;,
 16.84669;3.75028;-9.72675;,
 16.84669;-0.06826;-7.13016;,
 10.12525;0.87381;-5.63023;,
 10.12525;9.10515;-5.13901;,
 16.84669;3.75028;10.00000;,
 16.84669;-0.06826;7.99212;,
 16.84669;-0.06826;-7.13016;,
 16.84669;3.75028;-9.72675;,
 16.84669;3.75028;10.00000;,
 7.41048;9.10515;13.45832;,
 7.41048;3.23500;11.85396;,
 16.84669;-0.06826;7.99212;,
 16.84669;3.75028;-9.72675;,
 10.12525;9.10515;-5.13901;,
 7.41048;9.10515;13.45832;,
 10.12525;0.87381;-5.63023;,
 16.84669;-0.06826;-7.13016;,
 7.41048;3.23500;11.85396;,
 7.26199;7.73007;9.82831;,
 10.12525;9.10515;-5.13901;,
 9.05374;7.73007;-2.44593;,
 10.12525;0.87381;-5.63023;,
 9.05374;2.29739;-3.91881;,
 7.26199;3.85578;8.76943;,
 -10.12525;0.87381;-5.63023;,
 -16.84669;-0.06826;-7.13016;,
 -16.84669;3.75028;-9.72675;,
 -10.12525;9.10515;-5.13901;,
 -16.84669;-0.06826;-7.13016;,
 -16.84669;-0.06826;7.99212;,
 -16.84669;3.75028;10.00000;,
 -16.84669;3.75028;-9.72675;,
 -16.84669;3.75028;10.00000;,
 -16.84669;-0.06826;7.99212;,
 -7.41048;3.23500;11.85396;,
 -7.41048;9.10515;13.45832;,
 -10.12525;9.10515;-5.13901;,
 -16.84669;3.75028;-9.72675;,
 -7.41048;9.10515;13.45832;,
 -10.12525;0.87381;-5.63023;,
 -7.41048;3.23500;11.85396;,
 -16.84669;-0.06826;-7.13016;,
 -4.18903;6.63661;4.89602;,
 -4.18903;4.98465;4.89602;,
 -10.29162;4.98465;0.62294;,
 -10.29162;6.63661;0.62294;,
 -5.57327;6.63661;6.87291;,
 -4.18903;6.63661;4.89602;,
 -10.29162;6.63661;0.62294;,
 -11.67586;6.63661;2.59984;,
 -7.26060;3.85398;8.77844;,
 -10.12525;0.87381;-5.63023;,
 -9.05513;2.29318;-3.92946;,
 -10.12525;9.10515;-5.13901;,
 -9.05513;7.73428;-2.45430;,
 -7.26060;7.73428;9.83896;,
 10.29162;4.98465;0.62294;,
 4.18903;4.98465;4.89602;,
 4.18903;6.63661;4.89602;,
 10.29162;6.63661;0.62294;,
 10.29162;6.63661;0.62294;,
 4.18903;6.63661;4.89602;,
 5.57327;6.63661;6.87291;,
 11.67586;6.63661;2.59984;;
 
 92;
 3;0,1,2;,
 3;0,2,3;,
 3;4,5,1;,
 3;4,1,0;,
 3;4,6,7;,
 3;4,7,5;,
 3;8,9,10;,
 3;8,10,11;,
 3;12,13,10;,
 3;12,10,9;,
 3;14,15,13;,
 3;14,13,12;,
 3;16,17,18;,
 3;16,18,19;,
 3;20,21,17;,
 3;20,17,16;,
 3;20,22,23;,
 3;20,23,21;,
 3;24,25,26;,
 3;24,26,27;,
 3;28,29,25;,
 3;28,25,24;,
 3;28,30,31;,
 3;28,31,29;,
 3;32,33,34;,
 3;32,34,35;,
 3;36,37,22;,
 3;36,22,38;,
 3;39,31,40;,
 3;39,40,41;,
 3;41,40,37;,
 3;41,37,36;,
 3;36,38,39;,
 3;36,39,41;,
 3;42,19,43;,
 3;42,43,44;,
 3;44,43,45;,
 3;44,45,46;,
 3;46,45,26;,
 3;46,26,47;,
 3;44,46,47;,
 3;44,47,42;,
 3;48,49,50;,
 3;48,50,51;,
 3;52,53,54;,
 3;52,54,55;,
 3;56,57,58;,
 3;56,58,59;,
 3;60,61,62;,
 3;60,62,63;,
 3;64,65,66;,
 3;64,66,67;,
 3;68,69,70;,
 3;68,70,71;,
 3;64,72,73;,
 3;64,73,74;,
 3;75,76,65;,
 3;75,65,77;,
 3;78,74,79;,
 3;78,79,80;,
 3;80,79,81;,
 3;80,81,82;,
 3;82,81,77;,
 3;82,77,83;,
 3;80,82,83;,
 3;80,83,78;,
 3;84,85,86;,
 3;84,86,87;,
 3;88,89,90;,
 3;88,90,91;,
 3;92,93,94;,
 3;92,94,95;,
 3;96,97,90;,
 3;96,90,98;,
 3;99,100,89;,
 3;99,89,101;,
 3;102,103,104;,
 3;102,104,105;,
 3;106,107,108;,
 3;106,108,109;,
 3;110,100,111;,
 3;110,111,112;,
 3;112,111,113;,
 3;112,113,114;,
 3;115,114,113;,
 3;115,113,98;,
 3;110,112,114;,
 3;110,114,115;,
 3;116,117,118;,
 3;116,118,119;,
 3;120,121,122;,
 3;120,122,123;;
 
 MeshMaterialList {
  3;
  92;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
  2;;
  Material {
   0.181600;0.225600;0.357600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   1.000000;0.047000;0.000000;0.820000;;
   100.000000;
   1.000000;1.000000;1.000000;;
   1.000000;0.047000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  85;
  -0.904650;0.423630;-0.046328;,
  -0.446030;-0.342823;-0.826759;,
  0.125457;-0.560121;-0.818856;,
  -0.921755;-0.190733;-0.337622;,
  -0.153149;-0.872266;-0.464432;,
  0.150938;-0.941299;-0.301951;,
  0.940541;0.324968;-0.098884;,
  0.893103;-0.328700;-0.307120;,
  -0.556932;0.175818;0.811735;,
  -0.291069;0.202521;0.935021;,
  0.193056;0.207705;0.958952;,
  0.547692;-0.810431;0.207929;,
  -0.193056;0.207705;0.958952;,
  -0.032208;0.022379;0.999231;,
  -0.637026;-0.331856;0.695751;,
  -0.728347;-0.651461;0.212389;,
  0.000000;-0.537305;-0.843388;,
  -0.994650;0.094546;0.041621;,
  -0.955704;-0.291954;0.037315;,
  0.977088;0.192003;0.091832;,
  0.990390;-0.138298;-0.000845;,
  0.963813;0.229006;0.136455;,
  0.946211;-0.310977;0.089316;,
  -0.935854;0.322407;0.142237;,
  -0.969867;-0.222538;0.099174;,
  0.797317;0.191512;-0.572371;,
  0.637026;-0.331856;0.695751;,
  0.556932;0.175818;0.811735;,
  -0.165615;0.985281;-0.042349;,
  0.066938;0.988720;-0.133983;,
  0.199910;0.970940;-0.131573;,
  -0.765593;0.625219;0.151554;,
  0.121804;0.990281;-0.067143;,
  -0.100463;0.985929;-0.133605;,
  0.798669;0.582438;0.151307;,
  -0.199910;0.970940;-0.131573;,
  -0.027507;-0.999606;0.005506;,
  -0.082459;-0.996579;0.005489;,
  -0.352256;-0.935248;-0.035029;,
  0.041265;-0.999133;0.005503;,
  0.352256;-0.935248;-0.035029;,
  0.000000;-0.537305;-0.843388;,
  0.000000;-0.573586;-0.819145;,
  0.000000;-0.573586;-0.819145;,
  -0.880959;0.257568;-0.396951;,
  -0.762834;-0.198497;-0.615373;,
  -0.418349;-0.261296;-0.869890;,
  -0.221774;-0.864676;-0.450724;,
  0.886239;0.462745;0.021154;,
  1.000000;0.000000;0.000000;,
  0.199806;-0.258323;0.945170;,
  0.198763;-0.359413;0.911765;,
  -0.945856;0.146416;-0.289686;,
  -0.942181;-0.233999;-0.239876;,
  -0.940271;0.311531;-0.137257;,
  -0.981772;-0.146944;-0.120545;,
  0.900864;0.434101;0.000000;,
  0.195467;-0.456428;0.868024;,
  0.569592;0.821070;0.037535;,
  0.512774;0.855254;0.074853;,
  -0.219969;-0.974639;0.041133;,
  -0.702671;-0.711431;-0.010922;,
  -0.889216;0.438687;-0.129804;,
  0.876421;0.225603;-0.425429;,
  0.765634;-0.357935;-0.534496;,
  0.418349;-0.261296;-0.869890;,
  0.221774;-0.864676;-0.450724;,
  -0.886239;0.462745;0.021154;,
  -1.000000;0.000000;0.000000;,
  -0.199806;-0.258323;0.945170;,
  -0.198763;-0.359413;0.911765;,
  0.573577;0.000000;-0.819152;,
  0.000000;1.000000;0.000000;,
  0.969432;0.154733;-0.190419;,
  0.952559;-0.107194;-0.284851;,
  0.940039;0.312243;-0.137224;,
  0.959001;-0.263423;-0.104521;,
  -0.573577;0.000000;-0.819152;,
  -0.900864;0.434101;0.000000;,
  -0.195467;-0.456428;0.868024;,
  -0.569592;0.821070;0.037535;,
  -0.512774;0.855254;0.074853;,
  0.219969;-0.974639;0.041133;,
  0.617437;-0.786552;0.010352;,
  0.888731;0.439688;-0.129734;;
  92;
  3;1,4,3;,
  3;1,3,0;,
  3;2,5,4;,
  3;2,4,1;,
  3;25,6,7;,
  3;2,7,5;,
  3;8,9,12;,
  3;26,26,11;,
  3;10,13,12;,
  3;10,12,9;,
  3;14,15,13;,
  3;27,13,10;,
  3;28,29,30;,
  3;28,0,31;,
  3;32,33,29;,
  3;32,29,28;,
  3;32,34,6;,
  3;32,35,33;,
  3;4,36,37;,
  3;4,15,38;,
  3;5,39,36;,
  3;5,36,4;,
  3;5,40,11;,
  3;5,11,39;,
  3;16,16,16;,
  3;16,16,16;,
  3;19,6,34;,
  3;19,34,21;,
  3;22,11,7;,
  3;22,7,20;,
  3;20,7,6;,
  3;20,6,19;,
  3;19,21,22;,
  3;19,22,20;,
  3;23,31,0;,
  3;23,0,17;,
  3;17,0,3;,
  3;17,3,18;,
  3;18,3,15;,
  3;18,15,24;,
  3;17,18,24;,
  3;17,24,23;,
  3;41,41,41;,
  3;41,41,41;,
  3;42,42,42;,
  3;42,42,42;,
  3;43,43,43;,
  3;43,43,43;,
  3;46,47,45;,
  3;46,45,44;,
  3;48,49,49;,
  3;48,49,56;,
  3;51,50,51;,
  3;51,51,57;,
  3;48,56,58;,
  3;48,58,59;,
  3;60,47,60;,
  3;60,60,61;,
  3;54,62,44;,
  3;54,44,52;,
  3;52,44,45;,
  3;52,45,53;,
  3;53,45,61;,
  3;53,61,55;,
  3;52,53,55;,
  3;52,55,54;,
  3;64,66,65;,
  3;64,65,63;,
  3;68,68,67;,
  3;68,67,78;,
  3;70,79,70;,
  3;70,70,69;,
  3;80,78,67;,
  3;80,67,81;,
  3;82,83,82;,
  3;82,82,66;,
  3;71,71,71;,
  3;71,71,71;,
  3;72,72,72;,
  3;72,72,72;,
  3;76,83,64;,
  3;76,64,74;,
  3;74,64,63;,
  3;74,63,73;,
  3;75,73,63;,
  3;75,63,84;,
  3;76,74,73;,
  3;76,73,75;,
  3;77,77,77;,
  3;77,77,77;,
  3;72,72,72;,
  3;72,72,72;;
 }
 MeshTextureCoords {
  124;
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
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
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;;
 }
}
