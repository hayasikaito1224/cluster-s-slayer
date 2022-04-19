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
 340;
 -1.57292;0.01732;6.70048;,
 -1.57292;0.01732;-0.86168;,
 -1.43325;-0.64017;-0.86168;,
 -1.43325;-0.64017;6.70048;,
 -1.28382;-0.57365;6.70048;,
 -1.28382;-0.57365;-0.86168;,
 -1.40951;0.01738;-0.86168;,
 -1.40951;0.01738;6.70048;,
 -1.03820;-1.18407;-0.86168;,
 -1.03820;-1.18407;6.70048;,
 -0.92870;-1.06250;6.70048;,
 -0.92870;-1.06250;-0.86170;,
 -0.45592;-1.52010;-0.86168;,
 -0.45592;-1.52010;6.70048;,
 -0.40553;-1.36469;6.70048;,
 -0.40553;-1.36469;-0.86168;,
 0.21245;-1.59038;-0.86168;,
 0.21245;-1.59038;6.70048;,
 0.19555;-1.42787;6.70048;,
 0.19555;-1.42787;-0.86168;,
 0.85194;-1.38272;-0.86168;,
 0.85194;-1.38272;6.70048;,
 0.77007;-1.24106;6.70048;,
 0.77007;-1.24106;-0.86168;,
 1.35142;-0.93284;-0.86168;,
 1.35142;-0.93284;6.70048;,
 1.21913;-0.83682;6.70048;,
 1.21914;-0.83681;-0.86168;,
 1.62467;-0.31877;-0.86168;,
 1.62467;-0.31877;6.70048;,
 1.46492;-0.28475;6.70048;,
 1.46492;-0.28475;-0.86168;,
 1.62477;0.35352;-0.86168;,
 1.62477;0.35352;6.70048;,
 1.46487;0.31948;6.70048;,
 1.46487;0.31948;-0.86168;,
 1.35136;0.96757;-0.86168;,
 1.35136;0.96757;6.70048;,
 1.21917;0.87144;6.70048;,
 1.21922;0.87146;-0.86168;,
 0.85191;1.41738;-0.86168;,
 0.85191;1.41738;6.70048;,
 0.77007;1.27575;6.70048;,
 0.77007;1.27575;-0.86168;,
 0.21258;1.62511;-0.86168;,
 0.21258;1.62511;6.70048;,
 0.19555;1.46253;6.70048;,
 0.19555;1.46253;-0.86168;,
 -0.45588;1.55480;-0.86168;,
 -0.45588;1.55480;6.70048;,
 -0.40544;1.39938;6.70048;,
 -0.40544;1.39938;-0.86168;,
 -1.03814;1.21873;-0.86168;,
 -1.03814;1.21873;6.70048;,
 -0.92873;1.09720;6.70048;,
 -0.92873;1.09720;-0.86170;,
 -1.43316;0.67491;-0.86168;,
 -1.43316;0.67491;6.70048;,
 -1.28390;0.60842;6.70048;,
 -1.28390;0.60842;-0.86168;,
 -1.57292;0.01732;-0.86168;,
 -1.57292;0.01732;6.70048;,
 -1.40951;0.01738;6.70048;,
 -1.40951;0.01738;-0.86168;,
 -1.43325;-0.64017;6.70048;,
 -1.28382;-0.57365;6.70048;,
 -1.57292;0.01732;-0.86168;,
 -1.40951;0.01738;-0.86168;,
 -1.28382;-0.57365;-0.86168;,
 -1.43325;-0.64017;-0.86168;,
 -1.03820;-1.18407;6.70048;,
 -0.92870;-1.06250;6.70048;,
 -0.92870;-1.06250;-0.86170;,
 -1.03820;-1.18407;-0.86168;,
 -0.45592;-1.52010;6.70048;,
 -0.40553;-1.36469;6.70048;,
 -0.40553;-1.36469;-0.86168;,
 -0.45592;-1.52010;-0.86168;,
 0.21245;-1.59038;6.70048;,
 0.19555;-1.42787;6.70048;,
 0.19555;-1.42787;-0.86168;,
 0.21245;-1.59038;-0.86168;,
 0.85194;-1.38272;6.70048;,
 0.77007;-1.24106;6.70048;,
 0.77007;-1.24106;-0.86168;,
 0.85194;-1.38272;-0.86168;,
 1.35142;-0.93284;6.70048;,
 1.21913;-0.83682;6.70048;,
 1.21914;-0.83681;-0.86168;,
 1.35142;-0.93284;-0.86168;,
 1.62467;-0.31877;6.70048;,
 1.46492;-0.28475;6.70048;,
 1.46492;-0.28475;-0.86168;,
 1.62467;-0.31877;-0.86168;,
 1.62477;0.35352;6.70048;,
 1.46487;0.31948;6.70048;,
 1.46487;0.31948;-0.86168;,
 1.62477;0.35352;-0.86168;,
 1.35136;0.96757;6.70048;,
 1.21917;0.87144;6.70048;,
 1.21922;0.87146;-0.86168;,
 1.35136;0.96757;-0.86168;,
 0.85191;1.41738;6.70048;,
 0.77007;1.27575;6.70048;,
 0.77007;1.27575;-0.86168;,
 0.85191;1.41738;-0.86168;,
 0.21258;1.62511;6.70048;,
 0.19555;1.46253;6.70048;,
 0.19555;1.46253;-0.86168;,
 0.21258;1.62511;-0.86168;,
 -0.45588;1.55480;6.70048;,
 -0.40544;1.39938;6.70048;,
 -0.40544;1.39938;-0.86168;,
 -0.45588;1.55480;-0.86168;,
 -1.03814;1.21873;6.70048;,
 -0.92873;1.09720;6.70048;,
 -0.92873;1.09720;-0.86170;,
 -1.03814;1.21873;-0.86168;,
 -1.43316;0.67491;6.70048;,
 -1.28390;0.60842;6.70048;,
 -1.28390;0.60842;-0.86168;,
 -1.43316;0.67491;-0.86168;,
 1.08556;1.07407;4.11946;,
 1.19058;0.96901;4.11946;,
 -0.89265;-1.11438;4.11946;,
 -0.99776;-1.00930;4.11946;,
 -0.99776;-1.00930;4.11946;,
 -0.89265;-1.11438;4.11946;,
 -0.89265;-1.11438;6.66890;,
 -0.99776;-1.00930;6.66890;,
 -0.99776;-1.00930;6.66890;,
 -0.89265;-1.11438;6.66890;,
 1.19058;0.96901;6.66890;,
 1.08556;1.07407;6.66890;,
 1.08556;1.07407;6.66890;,
 1.19058;0.96901;6.66890;,
 1.19058;0.96901;4.11946;,
 1.08556;1.07407;4.11946;,
 1.08556;1.07407;4.11946;,
 -0.99776;-1.00930;4.11946;,
 1.19058;0.96901;4.11946;,
 -0.89265;-1.11438;4.11946;,
 9.72388;5.90648;2.87827;,
 0.30004;1.63723;2.87827;,
 0.30004;1.63723;4.76882;,
 9.72388;5.90648;4.76882;,
 10.01072;3.12848;4.76882;,
 1.58506;-0.84233;4.76882;,
 1.58506;-0.84233;2.87827;,
 10.01072;3.12848;2.87827;,
 9.72388;5.90648;0.98772;,
 0.30004;1.63723;0.98772;,
 10.01072;3.12848;0.98772;,
 1.58506;-0.84233;0.98772;,
 23.83531;5.14467;2.87827;,
 23.83531;5.14467;4.76882;,
 22.76188;2.56639;4.76882;,
 22.76188;2.56639;2.87827;,
 23.83531;5.14467;0.98772;,
 22.76188;2.56639;0.98772;,
 37.51310;-2.84372;2.87827;,
 37.51310;-2.84372;4.76882;,
 35.33969;-4.59739;4.76882;,
 35.33969;-4.59739;2.87827;,
 37.51310;-2.84372;0.98772;,
 35.33969;-4.59739;0.98772;,
 8.91880;-4.77536;6.62418;,
 1.64966;-0.17955;6.62418;,
 0.68228;-1.84931;6.62418;,
 8.54779;-6.66907;6.62418;,
 8.91880;-4.77536;4.76882;,
 1.64966;-0.17955;4.76882;,
 8.54779;-6.66907;4.76882;,
 0.68228;-1.84931;4.76882;,
 8.54783;-6.66890;-0.86764;,
 0.68233;-1.84928;-0.86764;,
 1.64967;-0.17952;-0.86764;,
 8.91880;-4.77514;-0.86764;,
 8.54783;-6.66890;0.98772;,
 0.68233;-1.84928;0.98772;,
 8.91880;-4.77514;0.98772;,
 1.64967;-0.17952;0.98772;,
 19.83105;-6.44534;6.62418;,
 20.04662;-8.36301;6.62418;,
 19.83105;-6.44534;4.76882;,
 20.04662;-8.36301;4.76882;,
 20.04662;-8.36260;-0.86764;,
 19.83105;-6.44498;-0.86764;,
 20.04662;-8.36260;0.98772;,
 19.83105;-6.44498;0.98772;,
 35.58200;-4.20818;6.62418;,
 36.63066;-5.82821;6.62418;,
 35.58200;-4.20818;4.76882;,
 36.63066;-5.82821;4.76882;,
 36.63034;-5.82770;-0.86764;,
 35.58166;-4.20772;-0.86764;,
 36.63034;-5.82770;0.98772;,
 35.58166;-4.20772;0.98772;,
 35.60147;-4.34721;6.60734;,
 35.60147;-4.34721;-0.76855;,
 35.74110;-5.00473;-0.76856;,
 35.74110;-5.00473;6.60735;,
 35.89058;-4.93818;6.60735;,
 35.89058;-4.93818;-0.76856;,
 35.76499;-4.34715;-0.76856;,
 35.76499;-4.34715;6.60735;,
 36.13626;-5.54856;-0.76856;,
 36.13626;-5.54856;6.60735;,
 36.24577;-5.42701;6.60735;,
 36.24577;-5.42701;-0.76856;,
 36.71844;-5.88470;-0.76856;,
 36.71844;-5.88470;6.60735;,
 36.76891;-5.72923;6.60734;,
 36.76891;-5.72923;-0.76856;,
 37.38687;-5.95497;-0.76856;,
 37.38687;-5.95497;6.60735;,
 37.36986;-5.79239;6.60734;,
 37.36986;-5.79239;-0.76856;,
 38.02626;-5.74729;-0.76856;,
 38.02626;-5.74729;6.60734;,
 37.94455;-5.60566;6.60734;,
 37.94455;-5.60566;-0.76856;,
 38.52587;-5.29740;-0.76855;,
 38.52587;-5.29740;6.60735;,
 38.39344;-5.20133;6.60734;,
 38.39347;-5.20130;-0.76855;,
 38.79919;-4.68334;-0.76856;,
 38.79919;-4.68334;6.60735;,
 38.63926;-4.64931;6.60735;,
 38.63926;-4.64931;-0.76855;,
 38.79925;-4.01104;-0.76856;,
 38.79925;-4.01104;6.60735;,
 38.63925;-4.04510;6.60735;,
 38.63925;-4.04510;-0.76855;,
 38.52581;-3.39702;-0.76855;,
 38.52581;-3.39702;6.60735;,
 38.39352;-3.49305;6.60734;,
 38.39352;-3.49305;-0.76855;,
 38.02621;-2.94715;-0.76856;,
 38.02621;-2.94715;6.60734;,
 37.94455;-3.08882;6.60734;,
 37.94455;-3.08882;-0.76856;,
 37.38702;-2.73946;-0.76856;,
 37.38702;-2.73946;6.60735;,
 37.36986;-2.90208;6.60734;,
 37.36986;-2.90208;-0.76856;,
 36.71846;-2.80973;-0.76856;,
 36.71846;-2.80973;6.60735;,
 36.76905;-2.96520;6.60734;,
 36.76905;-2.96520;-0.76856;,
 36.13633;-3.14584;-0.76856;,
 36.13633;-3.14584;6.60735;,
 36.24577;-3.26733;6.60735;,
 36.24577;-3.26733;-0.76856;,
 35.74119;-3.68964;-0.76856;,
 35.74119;-3.68964;6.60735;,
 35.89049;-3.75612;6.60735;,
 35.89049;-3.75612;-0.76856;,
 35.60147;-4.34721;-0.76855;,
 35.60147;-4.34721;6.60734;,
 35.76499;-4.34715;6.60735;,
 35.76499;-4.34715;-0.76856;,
 35.74110;-5.00473;6.60735;,
 35.89058;-4.93818;6.60735;,
 35.60147;-4.34721;-0.76855;,
 35.76499;-4.34715;-0.76856;,
 35.89058;-4.93818;-0.76856;,
 35.74110;-5.00473;-0.76856;,
 36.13626;-5.54856;6.60735;,
 36.24577;-5.42701;6.60735;,
 36.24577;-5.42701;-0.76856;,
 36.13626;-5.54856;-0.76856;,
 36.71844;-5.88470;6.60735;,
 36.76891;-5.72923;6.60734;,
 36.76891;-5.72923;-0.76856;,
 36.71844;-5.88470;-0.76856;,
 37.38687;-5.95497;6.60735;,
 37.36986;-5.79239;6.60734;,
 37.36986;-5.79239;-0.76856;,
 37.38687;-5.95497;-0.76856;,
 38.02626;-5.74729;6.60734;,
 37.94455;-5.60566;6.60734;,
 37.94455;-5.60566;-0.76856;,
 38.02626;-5.74729;-0.76856;,
 38.52587;-5.29740;6.60735;,
 38.39344;-5.20133;6.60734;,
 38.39347;-5.20130;-0.76855;,
 38.52587;-5.29740;-0.76855;,
 38.79919;-4.68334;6.60735;,
 38.63926;-4.64931;6.60735;,
 38.63926;-4.64931;-0.76855;,
 38.79919;-4.68334;-0.76856;,
 38.79925;-4.01104;6.60735;,
 38.63925;-4.04510;6.60735;,
 38.63925;-4.04510;-0.76855;,
 38.79925;-4.01104;-0.76856;,
 38.52581;-3.39702;6.60735;,
 38.39352;-3.49305;6.60734;,
 38.39352;-3.49305;-0.76855;,
 38.52581;-3.39702;-0.76855;,
 38.02621;-2.94715;6.60734;,
 37.94455;-3.08882;6.60734;,
 37.94455;-3.08882;-0.76856;,
 38.02621;-2.94715;-0.76856;,
 37.38702;-2.73946;6.60735;,
 37.36986;-2.90208;6.60734;,
 37.36986;-2.90208;-0.76856;,
 37.38702;-2.73946;-0.76856;,
 36.71846;-2.80973;6.60735;,
 36.76905;-2.96520;6.60734;,
 36.76905;-2.96520;-0.76856;,
 36.71846;-2.80973;-0.76856;,
 36.13633;-3.14584;6.60735;,
 36.24577;-3.26733;6.60735;,
 36.24577;-3.26733;-0.76856;,
 36.13633;-3.14584;-0.76856;,
 35.74119;-3.68964;6.60735;,
 35.89049;-3.75612;6.60735;,
 35.89049;-3.75612;-0.76856;,
 35.74119;-3.68964;-0.76856;,
 38.25993;-3.29047;4.08991;,
 38.36507;-3.39557;4.08991;,
 36.28171;-5.47899;4.08991;,
 36.17663;-5.37391;4.08991;,
 36.17663;-5.37391;4.08991;,
 36.28171;-5.47899;4.08991;,
 36.28171;-5.47899;6.57654;,
 36.17663;-5.37391;6.57654;,
 36.17663;-5.37391;6.57654;,
 36.28171;-5.47899;6.57654;,
 38.36507;-3.39557;6.57654;,
 38.25993;-3.29047;6.57654;,
 38.25993;-3.29047;6.57654;,
 38.36507;-3.39557;6.57654;,
 38.36507;-3.39557;4.08991;,
 38.25993;-3.29047;4.08991;,
 38.25993;-3.29047;4.08991;,
 36.17663;-5.37391;4.08991;,
 38.36507;-3.39557;4.08991;,
 36.28171;-5.47899;4.08991;;
 
 178;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;3,2,8,9;,
 4;10,11,5,4;,
 4;9,8,12,13;,
 4;14,15,11,10;,
 4;13,12,16,17;,
 4;18,19,15,14;,
 4;17,16,20,21;,
 4;22,23,19,18;,
 4;21,20,24,25;,
 4;26,27,23,22;,
 4;25,24,28,29;,
 4;30,31,27,26;,
 4;29,28,32,33;,
 4;34,35,31,30;,
 4;33,32,36,37;,
 4;38,39,35,34;,
 4;37,36,40,41;,
 4;42,43,39,38;,
 4;41,40,44,45;,
 4;46,47,43,42;,
 4;45,44,48,49;,
 4;50,51,47,46;,
 4;49,48,52,53;,
 4;54,55,51,50;,
 4;53,52,56,57;,
 4;58,59,55,54;,
 4;57,56,60,61;,
 4;62,63,59,58;,
 4;0,64,65,7;,
 4;66,67,68,69;,
 4;64,70,71,65;,
 4;69,68,72,73;,
 4;70,74,75,71;,
 4;73,72,76,77;,
 4;74,78,79,75;,
 4;77,76,80,81;,
 4;78,82,83,79;,
 4;81,80,84,85;,
 4;82,86,87,83;,
 4;85,84,88,89;,
 4;86,90,91,87;,
 4;89,88,92,93;,
 4;90,94,95,91;,
 4;93,92,96,97;,
 4;94,98,99,95;,
 4;97,96,100,101;,
 4;98,102,103,99;,
 4;101,100,104,105;,
 4;102,106,107,103;,
 4;105,104,108,109;,
 4;106,110,111,107;,
 4;109,108,112,113;,
 4;110,114,115,111;,
 4;113,112,116,117;,
 4;114,118,119,115;,
 4;117,116,120,121;,
 4;118,0,7,119;,
 4;121,120,67,66;,
 4;122,123,124,125;,
 4;126,127,128,129;,
 4;130,131,132,133;,
 4;134,135,136,137;,
 4;134,138,139,129;,
 4;140,135,128,141;,
 4;142,143,144,145;,
 4;146,147,148,149;,
 4;145,144,147,146;,
 4;150,151,143,142;,
 4;152,153,151,150;,
 4;149,148,153,152;,
 4;154,142,145,155;,
 4;156,146,149,157;,
 4;155,145,146,156;,
 4;158,150,142,154;,
 4;159,152,150,158;,
 4;157,149,152,159;,
 4;160,154,155,161;,
 4;162,156,157,163;,
 4;161,155,156,162;,
 4;161,162,163,160;,
 4;164,158,154,160;,
 4;165,159,158,164;,
 4;163,157,159,165;,
 4;160,163,165,164;,
 4;166,167,168,169;,
 4;170,171,167,166;,
 4;172,173,171,170;,
 4;169,168,173,172;,
 4;174,175,176,177;,
 4;178,179,175,174;,
 4;180,181,179,178;,
 4;177,176,181,180;,
 4;182,166,169,183;,
 4;184,170,166,182;,
 4;185,172,170,184;,
 4;183,169,172,185;,
 4;186,174,177,187;,
 4;188,178,174,186;,
 4;189,180,178,188;,
 4;187,177,180,189;,
 4;190,182,183,191;,
 4;192,184,182,190;,
 4;193,185,184,192;,
 4;191,183,185,193;,
 4;191,193,192,190;,
 4;194,186,187,195;,
 4;196,188,186,194;,
 4;197,189,188,196;,
 4;195,187,189,197;,
 4;195,197,196,194;,
 4;198,199,200,201;,
 4;202,203,204,205;,
 4;201,200,206,207;,
 4;208,209,203,202;,
 4;207,206,210,211;,
 4;212,213,209,208;,
 4;211,210,214,215;,
 4;216,217,213,212;,
 4;215,214,218,219;,
 4;220,221,217,216;,
 4;219,218,222,223;,
 4;224,225,221,220;,
 4;223,222,226,227;,
 4;228,229,225,224;,
 4;227,226,230,231;,
 4;232,233,229,228;,
 4;231,230,234,235;,
 4;236,237,233,232;,
 4;235,234,238,239;,
 4;240,241,237,236;,
 4;239,238,242,243;,
 4;244,245,241,240;,
 4;243,242,246,247;,
 4;248,249,245,244;,
 4;247,246,250,251;,
 4;252,253,249,248;,
 4;251,250,254,255;,
 4;256,257,253,252;,
 4;255,254,258,259;,
 4;260,261,257,256;,
 4;198,262,263,205;,
 4;264,265,266,267;,
 4;262,268,269,263;,
 4;267,266,270,271;,
 4;268,272,273,269;,
 4;271,270,274,275;,
 4;272,276,277,273;,
 4;275,274,278,279;,
 4;276,280,281,277;,
 4;279,278,282,283;,
 4;280,284,285,281;,
 4;283,282,286,287;,
 4;284,288,289,285;,
 4;287,286,290,291;,
 4;288,292,293,289;,
 4;291,290,294,295;,
 4;292,296,297,293;,
 4;295,294,298,299;,
 4;296,300,301,297;,
 4;299,298,302,303;,
 4;300,304,305,301;,
 4;303,302,306,307;,
 4;304,308,309,305;,
 4;307,306,310,311;,
 4;308,312,313,309;,
 4;311,310,314,315;,
 4;312,316,317,313;,
 4;315,314,318,319;,
 4;316,198,205,317;,
 4;319,318,265,264;,
 4;320,321,322,323;,
 4;324,325,326,327;,
 4;328,329,330,331;,
 4;332,333,334,335;,
 4;332,336,337,327;,
 4;338,333,326,339;;
 
 MeshMaterialList {
  3;
  178;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
   0.113190;0.234220;0.024990;1.000000;;
   45.000000;
   0.120000;0.120000;0.120000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.110880;0.110880;0.110880;1.000000;;
   70.000000;
   0.520000;0.520000;0.520000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.788000;0.396000;0.000000;1.000000;;
   100.000000;
   1.000000;1.000000;1.000000;;
   0.788000;0.396000;0.000000;;
  }
 }
 MeshNormals {
  137;
  -1.000000;0.000047;0.000000;,
  -0.913600;-0.406615;0.000000;,
  -0.669112;-0.743161;0.000000;,
  -0.308946;-0.951080;0.000000;,
  0.104418;-0.994534;-0.000000;,
  0.499999;-0.866026;-0.000000;,
  0.809125;-0.587637;-0.000000;,
  0.978153;-0.207887;-0.000000;,
  0.978160;0.207852;0.000000;,
  0.809044;0.587749;0.000000;,
  0.500043;0.866000;0.000000;,
  0.104485;0.994526;0.000000;,
  -0.308987;0.951066;0.000000;,
  -0.669122;0.743153;0.000000;,
  -0.913572;0.406676;0.000000;,
  1.000000;0.000059;0.000000;,
  0.913539;0.406752;0.000000;,
  0.669226;0.743059;0.000000;,
  0.309118;0.951024;0.000000;,
  -0.104633;0.994511;0.000000;,
  -0.500044;0.866000;0.000000;,
  -0.808988;0.587826;-0.000000;,
  -0.978158;0.207861;-0.000000;,
  -0.978151;-0.207896;-0.000002;,
  -0.809016;-0.587786;-0.000003;,
  -0.500026;-0.866010;-0.000001;,
  -0.104627;-0.994512;0.000000;,
  0.309045;-0.951047;-0.000000;,
  0.669140;-0.743137;-0.000000;,
  0.913540;-0.406750;-0.000000;,
  0.000000;0.000000;-1.000000;,
  -0.707004;-0.707209;0.000000;,
  0.000000;-0.000000;1.000000;,
  -0.412656;0.910887;0.000000;,
  -0.412656;0.910887;0.000000;,
  0.426306;-0.904579;-0.000000;,
  0.426306;-0.904579;-0.000000;,
  -0.184652;0.982804;0.000000;,
  -0.184652;0.982804;0.000000;,
  0.196881;-0.980427;-0.000000;,
  0.287166;0.957881;0.000000;,
  -0.277214;-0.960808;0.000000;,
  -0.277214;-0.960808;0.000000;,
  0.504327;0.863513;0.000000;,
  0.504327;0.863513;0.000000;,
  -0.494913;-0.868943;0.000000;,
  -0.494913;-0.868943;0.000000;,
  0.534389;0.845238;0.000000;,
  -0.522469;-0.852658;0.000000;,
  0.350235;0.936662;0.000000;,
  -0.341012;-0.940059;0.000000;,
  0.005385;0.999986;0.000000;,
  0.002719;-0.999996;-0.000000;,
  -0.140621;0.990063;0.000000;,
  0.151100;-0.988518;-0.000000;,
  -1.000000;0.000056;0.000000;,
  -0.913572;-0.406677;0.000000;,
  -0.669120;-0.743154;0.000000;,
  -0.309043;-0.951048;0.000000;,
  0.104462;-0.994529;-0.000000;,
  0.499974;-0.866040;-0.000000;,
  0.809063;-0.587722;-0.000000;,
  0.978150;-0.207901;-0.000000;,
  0.978149;0.207906;0.000000;,
  0.809002;0.587806;0.000000;,
  0.500018;0.866015;0.000000;,
  0.104529;0.994522;0.000000;,
  -0.309032;0.951051;0.000000;,
  -0.669116;0.743157;0.000000;,
  -0.913548;0.406731;0.000000;,
  1.000000;0.000068;0.000000;,
  0.913549;0.406728;0.000000;,
  0.669211;0.743073;0.000000;,
  0.309140;0.951017;0.000000;,
  -0.104535;0.994521;0.000000;,
  -0.500081;0.865979;-0.000000;,
  -0.809051;0.587738;-0.000001;,
  -0.978143;0.207932;-0.000001;,
  -0.978155;-0.207878;0.000000;,
  -0.809033;-0.587764;0.000000;,
  -0.499996;-0.866027;0.000000;,
  -0.104568;-0.994518;0.000000;,
  0.309006;-0.951060;-0.000000;,
  0.669068;-0.743201;-0.000000;,
  0.913547;-0.406734;-0.000000;,
  -0.707127;-0.707086;0.000000;,
  -0.000025;-0.000010;-1.000000;,
  -0.000032;-0.000036;-1.000000;,
  -0.000007;-0.000026;-1.000000;,
  -0.000007;0.000026;-1.000000;,
  -0.000030;0.000034;-1.000000;,
  -0.000023;0.000008;-1.000000;,
  0.707230;0.706983;0.000000;,
  -0.707114;0.707100;0.000000;,
  0.707136;-0.707078;-0.000000;,
  0.426306;-0.904579;-0.000000;,
  0.196881;-0.980427;-0.000000;,
  -0.277214;-0.960808;0.000000;,
  0.627952;-0.778252;-0.000000;,
  0.627952;-0.778252;-0.000000;,
  -0.341027;-0.940053;0.000000;,
  -0.522480;-0.852651;0.000000;,
  0.350221;0.936667;0.000000;,
  0.534374;0.845248;0.000000;,
  0.002705;-0.999996;-0.000000;,
  0.005374;0.999986;0.000000;,
  0.151091;-0.988520;-0.000000;,
  0.839474;0.543399;0.000000;,
  -0.140631;0.990062;0.000000;,
  0.839462;0.543418;0.000000;,
  -0.000044;-0.000000;1.000000;,
  -0.000022;0.000000;1.000000;,
  -0.000056;-0.000000;-1.000000;,
  -0.000028;0.000000;-1.000000;,
  0.000015;0.000016;1.000000;,
  0.000020;0.000056;1.000000;,
  0.000002;0.000062;1.000000;,
  -0.000020;0.000034;1.000000;,
  0.000010;0.000009;-1.000000;,
  -0.000040;0.000016;1.000000;,
  -0.000018;0.000014;-1.000000;,
  -0.000022;0.000004;1.000000;,
  -0.000079;0.000005;-1.000000;,
  -0.000022;-0.000004;1.000000;,
  -0.000079;-0.000005;-1.000000;,
  -0.000038;-0.000015;1.000000;,
  -0.000018;-0.000014;-1.000000;,
  -0.000018;-0.000033;1.000000;,
  0.000010;-0.000009;-1.000000;,
  0.000002;-0.000062;1.000000;,
  0.000018;-0.000054;1.000000;,
  0.000014;-0.000014;1.000000;,
  -0.000022;-0.000000;1.000000;,
  -0.000028;-0.000000;-1.000000;,
  0.706984;0.707230;0.000000;,
  -0.707130;0.707084;0.000000;,
  0.707116;-0.707097;-0.000000;;
  178;
  4;0,0,1,1;,
  4;16,16,15,15;,
  4;1,1,2,2;,
  4;17,17,16,16;,
  4;2,2,3,3;,
  4;18,18,17,17;,
  4;3,3,4,4;,
  4;19,19,18,18;,
  4;4,4,5,5;,
  4;20,20,19,19;,
  4;5,5,6,6;,
  4;21,21,20,20;,
  4;6,6,7,7;,
  4;22,22,21,21;,
  4;7,7,8,8;,
  4;23,23,22,22;,
  4;8,8,9,9;,
  4;24,24,23,23;,
  4;9,9,10,10;,
  4;25,25,24,24;,
  4;10,10,11,11;,
  4;26,26,25,25;,
  4;11,11,12,12;,
  4;27,27,26,26;,
  4;12,12,13,13;,
  4;28,28,27,27;,
  4;13,13,14,14;,
  4;29,29,28,28;,
  4;14,14,0,0;,
  4;15,15,29,29;,
  4;32,32,32,32;,
  4;30,30,86,86;,
  4;32,32,32,32;,
  4;86,86,87,87;,
  4;32,32,32,32;,
  4;87,87,88,88;,
  4;32,32,32,32;,
  4;88,88,30,30;,
  4;32,32,32,32;,
  4;30,30,30,30;,
  4;32,32,32,32;,
  4;30,30,30,30;,
  4;32,32,32,32;,
  4;30,30,30,30;,
  4;32,32,32,32;,
  4;30,30,30,30;,
  4;32,32,32,32;,
  4;30,30,30,30;,
  4;32,32,32,32;,
  4;30,30,30,30;,
  4;32,32,32,32;,
  4;30,30,30,30;,
  4;32,32,32,32;,
  4;30,30,89,89;,
  4;32,32,32,32;,
  4;89,89,90,90;,
  4;32,32,32,32;,
  4;90,90,91,91;,
  4;32,32,32,32;,
  4;91,91,30,30;,
  4;30,30,30,30;,
  4;31,31,31,31;,
  4;32,32,32,32;,
  4;92,92,92,92;,
  4;93,93,93,93;,
  4;94,94,94,94;,
  4;37,33,33,37;,
  4;39,35,36,39;,
  4;32,32,32,32;,
  4;38,34,33,37;,
  4;30,30,30,30;,
  4;39,36,95,96;,
  4;40,37,37,40;,
  4;41,39,39,42;,
  4;32,32,32,32;,
  4;40,38,37,40;,
  4;30,30,30,30;,
  4;42,39,96,97;,
  4;44,40,40,43;,
  4;45,41,42,46;,
  4;32,32,32,32;,
  4;98,98,98,98;,
  4;43,40,40,44;,
  4;30,30,30,30;,
  4;46,42,97,46;,
  4;98,98,99,99;,
  4;32,32,32,32;,
  4;49,47,47,49;,
  4;30,30,30,30;,
  4;100,101,101,100;,
  4;30,30,30,30;,
  4;50,48,48,50;,
  4;32,32,32,32;,
  4;102,103,103,102;,
  4;32,32,32,32;,
  4;51,49,49,51;,
  4;30,30,30,30;,
  4;104,100,100,104;,
  4;30,30,30,30;,
  4;52,50,50,52;,
  4;32,32,32,32;,
  4;105,102,102,105;,
  4;32,32,32,32;,
  4;53,51,51,53;,
  4;30,30,30,30;,
  4;106,104,104,106;,
  4;107,107,107,107;,
  4;30,30,30,30;,
  4;54,52,52,54;,
  4;32,32,32,32;,
  4;108,105,105,108;,
  4;109,109,109,109;,
  4;55,55,56,56;,
  4;71,71,70,70;,
  4;56,56,57,57;,
  4;72,72,71,71;,
  4;57,57,58,58;,
  4;73,73,72,72;,
  4;58,58,59,59;,
  4;74,74,73,73;,
  4;59,59,60,60;,
  4;75,75,74,74;,
  4;60,60,61,61;,
  4;76,76,75,75;,
  4;61,61,62,62;,
  4;77,77,76,76;,
  4;62,62,63,63;,
  4;78,78,77,77;,
  4;63,63,64,64;,
  4;79,79,78,78;,
  4;64,64,65,65;,
  4;80,80,79,79;,
  4;65,65,66,66;,
  4;81,81,80,80;,
  4;66,66,67,67;,
  4;82,82,81,81;,
  4;67,67,68,68;,
  4;83,83,82,82;,
  4;68,68,69,69;,
  4;84,84,83,83;,
  4;69,69,55,55;,
  4;70,70,84,84;,
  4;110,111,111,110;,
  4;112,112,113,113;,
  4;111,114,114,111;,
  4;113,113,30,30;,
  4;114,115,115,114;,
  4;30,30,30,30;,
  4;115,116,116,115;,
  4;30,30,30,30;,
  4;116,117,117,116;,
  4;30,30,118,118;,
  4;117,119,119,117;,
  4;118,118,120,120;,
  4;119,121,121,119;,
  4;120,120,122,122;,
  4;121,123,123,121;,
  4;122,122,124,124;,
  4;123,125,125,123;,
  4;124,124,126,126;,
  4;125,127,127,125;,
  4;126,126,128,128;,
  4;127,129,129,127;,
  4;128,128,30,30;,
  4;129,130,130,129;,
  4;30,30,30,30;,
  4;130,131,131,130;,
  4;30,30,30,30;,
  4;131,132,132,131;,
  4;30,30,133,133;,
  4;132,110,110,132;,
  4;133,133,112,112;,
  4;30,30,30,30;,
  4;85,85,85,85;,
  4;32,32,32,32;,
  4;134,134,134,134;,
  4;135,135,135,135;,
  4;136,136,136,136;;
 }
 MeshTextureCoords {
  340;
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.066670;1.000000;,
  0.066670;0.000000;,
  0.066670;0.000000;,
  0.066670;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.133330;1.000000;,
  0.133330;0.000000;,
  0.133330;0.000000;,
  0.133330;1.000000;,
  0.200000;1.000000;,
  0.200000;0.000000;,
  0.200000;0.000000;,
  0.200000;1.000000;,
  0.266670;1.000000;,
  0.266670;0.000000;,
  0.266670;0.000000;,
  0.266670;1.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.400000;1.000000;,
  0.400000;0.000000;,
  0.400000;0.000000;,
  0.400000;1.000000;,
  0.466670;1.000000;,
  0.466670;0.000000;,
  0.466670;0.000000;,
  0.466670;1.000000;,
  0.533330;1.000000;,
  0.533330;0.000000;,
  0.533330;0.000000;,
  0.533330;1.000000;,
  0.600000;1.000000;,
  0.600000;0.000000;,
  0.600000;0.000000;,
  0.600000;1.000000;,
  0.666670;1.000000;,
  0.666670;0.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  0.733330;1.000000;,
  0.733330;0.000000;,
  0.733330;0.000000;,
  0.733330;1.000000;,
  0.800000;1.000000;,
  0.800000;0.000000;,
  0.800000;0.000000;,
  0.800000;1.000000;,
  0.866670;1.000000;,
  0.866670;0.000000;,
  0.866670;0.000000;,
  0.866670;1.000000;,
  0.933330;1.000000;,
  0.933330;0.000000;,
  0.933330;0.000000;,
  0.933330;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
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
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.500000;0.250000;,
  0.500000;0.250000;,
  0.250000;0.250000;,
  0.250000;0.250000;,
  0.250000;0.500000;,
  0.250000;0.500000;,
  0.500000;0.500000;,
  0.500000;0.500000;,
  0.750000;0.250000;,
  0.750000;0.250000;,
  0.750000;0.500000;,
  0.750000;0.500000;,
  0.500000;0.250000;,
  0.250000;0.250000;,
  0.250000;0.500000;,
  0.500000;0.500000;,
  0.750000;0.250000;,
  0.750000;0.500000;,
  0.500000;0.250000;,
  0.250000;0.250000;,
  0.250000;0.500000;,
  0.500000;0.500000;,
  0.750000;0.250000;,
  0.750000;0.500000;,
  0.250000;0.750000;,
  0.250000;0.750000;,
  0.250000;1.000000;,
  0.250000;1.000000;,
  0.250000;0.750000;,
  0.250000;0.750000;,
  0.250000;1.000000;,
  0.250000;1.000000;,
  0.750000;1.000000;,
  0.750000;1.000000;,
  0.750000;0.750000;,
  0.750000;0.750000;,
  0.750000;1.000000;,
  0.750000;1.000000;,
  0.750000;0.750000;,
  0.750000;0.750000;,
  0.250000;0.750000;,
  0.250000;1.000000;,
  0.250000;0.750000;,
  0.250000;1.000000;,
  0.750000;1.000000;,
  0.750000;0.750000;,
  0.750000;1.000000;,
  0.750000;0.750000;,
  0.250000;0.750000;,
  0.250000;1.000000;,
  0.250000;0.750000;,
  0.250000;1.000000;,
  0.750000;1.000000;,
  0.750000;0.750000;,
  0.750000;1.000000;,
  0.750000;0.750000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.066670;1.000000;,
  0.066670;0.000000;,
  0.066670;0.000000;,
  0.066670;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.133330;1.000000;,
  0.133330;0.000000;,
  0.133330;0.000000;,
  0.133330;1.000000;,
  0.200000;1.000000;,
  0.200000;0.000000;,
  0.200000;0.000000;,
  0.200000;1.000000;,
  0.266670;1.000000;,
  0.266670;0.000000;,
  0.266670;0.000000;,
  0.266670;1.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.400000;1.000000;,
  0.400000;0.000000;,
  0.400000;0.000000;,
  0.400000;1.000000;,
  0.466670;1.000000;,
  0.466670;0.000000;,
  0.466670;0.000000;,
  0.466670;1.000000;,
  0.533330;1.000000;,
  0.533330;0.000000;,
  0.533330;0.000000;,
  0.533330;1.000000;,
  0.600000;1.000000;,
  0.600000;0.000000;,
  0.600000;0.000000;,
  0.600000;1.000000;,
  0.666670;1.000000;,
  0.666670;0.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  0.733330;1.000000;,
  0.733330;0.000000;,
  0.733330;0.000000;,
  0.733330;1.000000;,
  0.800000;1.000000;,
  0.800000;0.000000;,
  0.800000;0.000000;,
  0.800000;1.000000;,
  0.866670;1.000000;,
  0.866670;0.000000;,
  0.866670;0.000000;,
  0.866670;1.000000;,
  0.933330;1.000000;,
  0.933330;0.000000;,
  0.933330;0.000000;,
  0.933330;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
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
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;;
 }
}
