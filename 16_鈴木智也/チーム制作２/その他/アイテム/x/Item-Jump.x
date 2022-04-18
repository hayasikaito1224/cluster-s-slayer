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
 450;
 -8.86901;50.36675;-8.44537;,
 8.02173;50.36675;-8.44537;,
 8.02173;6.35849;-8.44537;,
 -8.86901;6.35849;-8.44537;,
 8.02173;50.36675;-8.44537;,
 8.02173;50.36675;8.44537;,
 8.02173;6.35849;8.44537;,
 8.02173;6.35849;-8.44537;,
 8.02173;50.36675;8.44537;,
 -8.86901;50.36675;8.44537;,
 -8.86901;6.35849;8.44537;,
 8.02173;6.35849;8.44537;,
 -8.86901;50.36675;8.44537;,
 -8.86901;50.36675;-8.44537;,
 -8.86901;6.35849;-8.44537;,
 -8.86901;6.35849;8.44537;,
 -10.42973;8.26579;-10.00609;,
 9.58245;8.26579;-10.00609;,
 9.58245;-0.01176;-10.00609;,
 -10.42973;-0.01176;-10.00609;,
 9.58245;8.26579;-10.00609;,
 9.58245;8.26579;10.00609;,
 9.58245;-0.01176;10.00609;,
 9.58245;-0.01176;-10.00609;,
 9.58245;8.26579;10.00609;,
 -10.42973;8.26579;10.00609;,
 -10.42973;-0.01176;10.00609;,
 9.58245;-0.01176;10.00609;,
 -10.42973;8.26579;10.00609;,
 -10.42973;8.26579;-10.00609;,
 -10.42973;-0.01176;-10.00609;,
 -10.42973;-0.01176;10.00609;,
 9.58245;8.26579;-10.00609;,
 -10.42973;8.26579;-10.00609;,
 -10.42973;-0.01176;-10.00609;,
 9.58245;-0.01176;-10.00609;,
 -10.42973;51.07209;-10.00609;,
 9.58245;51.07209;-10.00609;,
 9.58245;42.79454;-10.00609;,
 -10.42973;42.79454;-10.00609;,
 9.58245;51.07209;-10.00609;,
 9.58245;51.07209;10.00609;,
 9.58245;42.79454;10.00609;,
 9.58245;42.79454;-10.00609;,
 9.58245;51.07209;10.00609;,
 -10.42973;51.07209;10.00609;,
 -10.42973;42.79454;10.00609;,
 9.58245;42.79454;10.00609;,
 -10.42973;51.07209;10.00609;,
 -10.42973;51.07209;-10.00609;,
 -10.42973;42.79454;-10.00609;,
 -10.42973;42.79454;10.00609;,
 9.58245;51.07209;-10.00609;,
 -10.42973;51.07209;-10.00609;,
 -10.42973;42.79454;-10.00609;,
 9.58245;42.79454;-10.00609;,
 -8.49150;2.35443;-10.00682;,
 -7.64632;1.50927;-10.00682;,
 -8.49150;0.66410;-10.00682;,
 -9.33669;1.50927;-10.00682;,
 7.64422;2.35443;-10.00682;,
 8.48941;1.50927;-10.00682;,
 7.64422;0.66410;-10.00682;,
 6.79904;1.50927;-10.00682;,
 -8.49150;2.35443;10.00682;,
 -9.33669;1.50927;10.00682;,
 -8.49150;0.66410;10.00682;,
 -7.64632;1.50927;10.00682;,
 7.64422;2.35443;10.00682;,
 6.79904;1.50927;10.00682;,
 7.64422;0.66410;10.00682;,
 8.48941;1.50927;10.00682;,
 -8.49150;7.53588;-10.00682;,
 -7.64632;6.69072;-10.00682;,
 -8.49150;5.84555;-10.00682;,
 -9.33669;6.69072;-10.00682;,
 7.64422;7.53588;-10.00682;,
 8.48941;6.69072;-10.00682;,
 7.64422;5.84555;-10.00682;,
 6.79904;6.69072;-10.00682;,
 -8.49150;7.53588;10.00682;,
 -9.33669;6.69072;10.00682;,
 -8.49150;5.84555;10.00682;,
 -7.64632;6.69072;10.00682;,
 7.64422;7.53588;10.00682;,
 6.79904;6.69072;10.00682;,
 7.64422;5.84555;10.00682;,
 8.48941;6.69072;10.00682;,
 -8.49150;45.11672;-10.00682;,
 -7.64632;44.27156;-10.00682;,
 -8.49150;43.42639;-10.00682;,
 -9.33669;44.27156;-10.00682;,
 7.64422;45.11672;-10.00682;,
 8.48941;44.27156;-10.00682;,
 7.64422;43.42639;-10.00682;,
 6.79904;44.27156;-10.00682;,
 -8.49150;45.11672;10.00682;,
 -9.33669;44.27156;10.00682;,
 -8.49150;43.42639;10.00682;,
 -7.64632;44.27156;10.00682;,
 7.64422;45.11672;10.00682;,
 6.79904;44.27156;10.00682;,
 7.64422;43.42639;10.00682;,
 8.48941;44.27156;10.00682;,
 -8.49150;50.29818;-10.00682;,
 -7.64632;49.45301;-10.00682;,
 -8.49150;48.60784;-10.00682;,
 -9.33669;49.45301;-10.00682;,
 7.64422;50.29818;-10.00682;,
 8.48941;49.45301;-10.00682;,
 7.64422;48.60784;-10.00682;,
 6.79904;49.45301;-10.00682;,
 -8.49150;50.29818;10.00682;,
 -9.33669;49.45301;10.00682;,
 -8.49150;48.60784;10.00682;,
 -7.64632;49.45301;10.00682;,
 7.64422;50.29818;10.00682;,
 6.79904;49.45301;10.00682;,
 7.64422;48.60784;10.00682;,
 8.48941;49.45301;10.00682;,
 -10.43046;2.35443;8.06786;,
 -10.43046;1.50927;7.22268;,
 -10.43046;0.66410;8.06786;,
 -10.43046;1.50927;8.91305;,
 -10.43046;2.35443;-8.06786;,
 -10.43046;1.50927;-8.91305;,
 -10.43046;0.66410;-8.06786;,
 -10.43046;1.50927;-7.22268;,
 9.58318;2.35443;8.06786;,
 9.58318;1.50927;8.91305;,
 9.58318;0.66410;8.06786;,
 9.58318;1.50927;7.22268;,
 9.58318;2.35443;-8.06786;,
 9.58318;1.50927;-7.22268;,
 9.58318;0.66410;-8.06786;,
 9.58318;1.50927;-8.91305;,
 -10.43046;7.53588;8.06786;,
 -10.43046;6.69072;7.22268;,
 -10.43046;5.84555;8.06786;,
 -10.43046;6.69072;8.91305;,
 -10.43046;7.53588;-8.06786;,
 -10.43046;6.69072;-8.91305;,
 -10.43046;5.84555;-8.06786;,
 -10.43046;6.69072;-7.22268;,
 9.58318;7.53588;8.06786;,
 9.58318;6.69072;8.91305;,
 9.58318;5.84555;8.06786;,
 9.58318;6.69072;7.22268;,
 9.58318;7.53588;-8.06786;,
 9.58318;6.69072;-7.22268;,
 9.58318;5.84555;-8.06786;,
 9.58318;6.69072;-8.91305;,
 -10.43046;45.11672;8.06786;,
 -10.43046;44.27156;7.22268;,
 -10.43046;43.42639;8.06786;,
 -10.43046;44.27156;8.91305;,
 -10.43046;45.11672;-8.06786;,
 -10.43046;44.27156;-8.91305;,
 -10.43046;43.42639;-8.06786;,
 -10.43046;44.27156;-7.22268;,
 9.58318;45.11672;8.06786;,
 9.58318;44.27156;8.91305;,
 9.58318;43.42639;8.06786;,
 9.58318;44.27156;7.22268;,
 9.58318;45.11672;-8.06786;,
 9.58318;44.27156;-7.22268;,
 9.58318;43.42639;-8.06786;,
 9.58318;44.27156;-8.91305;,
 -10.43046;50.29818;8.06786;,
 -10.43046;49.45301;7.22268;,
 -10.43046;48.60784;8.06786;,
 -10.43046;49.45301;8.91305;,
 -10.43046;50.29818;-8.06786;,
 -10.43046;49.45301;-8.91305;,
 -10.43046;48.60784;-8.06786;,
 -10.43046;49.45301;-7.22268;,
 9.58318;50.29818;8.06786;,
 9.58318;49.45301;8.91305;,
 9.58318;48.60784;8.06786;,
 9.58318;49.45301;7.22268;,
 9.58318;50.29818;-8.06786;,
 9.58318;49.45301;-7.22268;,
 9.58318;48.60784;-8.06786;,
 9.58318;49.45301;-8.91305;,
 -8.87378;42.83879;-8.49556;,
 -7.81862;42.83879;-8.49556;,
 -7.81862;8.30772;-8.49558;,
 -8.87378;8.30772;-8.49558;,
 -8.87378;42.83879;8.49556;,
 -8.87378;8.30772;8.49558;,
 -7.81862;8.30772;8.49558;,
 -7.81862;42.83879;8.49556;,
 8.02650;42.83879;-8.49556;,
 8.02650;8.30772;-8.49558;,
 6.97134;8.30772;-8.49558;,
 6.97134;42.83879;-8.49556;,
 8.02650;42.83879;8.49556;,
 6.97134;42.83879;8.49556;,
 6.97134;8.30772;8.49558;,
 8.02650;8.30772;8.49558;,
 -8.91920;42.83879;8.45014;,
 -8.91920;42.83879;7.39498;,
 -8.91922;8.30772;7.39498;,
 -8.91922;8.30772;8.45014;,
 8.07192;42.83879;8.45014;,
 8.07194;8.30772;8.45014;,
 8.07194;8.30772;7.39498;,
 8.07192;42.83879;7.39498;,
 -8.91920;42.83879;-8.45014;,
 -8.91922;8.30772;-8.45014;,
 -8.91922;8.30772;-7.39498;,
 -8.91920;42.83879;-7.39498;,
 8.07192;42.83879;-8.45014;,
 8.07192;42.83879;-7.39498;,
 8.07194;8.30772;-7.39498;,
 8.07194;8.30772;-8.45014;,
 -7.80498;54.66993;-7.38134;,
 6.95770;54.66993;-7.38134;,
 8.23499;49.24806;-8.65863;,
 -9.08227;49.24806;-8.65863;,
 6.95770;54.66993;-7.38134;,
 6.95770;54.66993;7.38134;,
 8.23499;49.24806;8.65863;,
 8.23499;49.24806;-8.65863;,
 6.95770;54.66993;7.38134;,
 -7.80498;54.66993;7.38134;,
 -9.08227;49.24806;8.65863;,
 8.23499;49.24806;8.65863;,
 -7.80498;54.66993;7.38134;,
 -7.80498;54.66993;-7.38134;,
 -9.08227;49.24806;-8.65863;,
 -9.08227;49.24806;8.65863;,
 6.95770;54.66993;-7.38134;,
 -7.80498;54.66993;-7.38134;,
 5.96044;48.77325;-9.52159;,
 12.31677;48.77325;-9.52159;,
 12.31677;2.52961;-9.52159;,
 5.96044;2.52961;-9.52159;,
 12.31677;48.77325;-9.52159;,
 12.31677;48.77325;9.52159;,
 12.31677;2.52961;9.52159;,
 12.31677;2.52961;-9.52159;,
 12.31677;48.77325;9.52159;,
 5.96044;48.77325;9.52159;,
 5.96044;2.52961;9.52159;,
 12.31677;2.52961;9.52159;,
 5.96044;48.77325;9.52159;,
 5.96044;48.77325;-9.52159;,
 5.96044;2.52961;-9.52159;,
 5.96044;2.52961;9.52159;,
 12.31677;48.77325;-9.52159;,
 5.96044;48.77325;-9.52159;,
 5.96044;2.52961;-9.52159;,
 12.31677;2.52961;-9.52159;,
 -10.23447;19.32129;-9.81083;,
 9.38719;19.32129;-9.81083;,
 9.38719;16.44519;-9.81083;,
 -10.23447;16.44519;-9.81083;,
 9.38719;19.32129;9.81083;,
 -10.23447;19.32129;9.81083;,
 -10.23447;16.44519;9.81083;,
 9.38719;16.44519;9.81083;,
 -10.23447;19.32129;9.81083;,
 -10.23447;19.32129;-9.81083;,
 -10.23447;16.44519;-9.81083;,
 -10.23447;16.44519;9.81083;,
 9.38719;19.32129;9.81083;,
 9.38719;19.32129;-9.81083;,
 -10.23447;19.32129;-9.81083;,
 -10.23447;16.44519;-9.81083;,
 9.38719;16.44519;-9.81083;,
 9.38719;16.44519;9.81083;,
 -10.23447;34.31689;-9.81083;,
 9.38719;34.31689;-9.81083;,
 9.38719;31.44081;-9.81083;,
 -10.23447;31.44081;-9.81083;,
 9.38719;34.31689;9.81083;,
 -10.23447;34.31689;9.81083;,
 -10.23447;31.44081;9.81083;,
 9.38719;31.44081;9.81083;,
 -10.23447;34.31689;9.81083;,
 -10.23447;34.31689;-9.81083;,
 -10.23447;31.44081;-9.81083;,
 -10.23447;31.44081;9.81083;,
 9.38719;34.31689;9.81083;,
 9.38719;34.31689;-9.81083;,
 -10.23447;34.31689;-9.81083;,
 -10.23447;31.44081;-9.81083;,
 9.38719;31.44081;-9.81083;,
 9.38719;31.44081;9.81083;,
 12.34463;45.96957;6.51761;,
 12.34463;5.12256;6.51761;,
 12.34463;5.12256;-6.51761;,
 12.34463;45.96957;-6.51761;,
 7.64422;33.69925;-9.82068;,
 8.48941;32.85408;-9.82068;,
 7.64422;32.00891;-9.82068;,
 6.79904;32.85408;-9.82068;,
 7.64422;33.69925;9.82068;,
 6.79904;32.85408;9.82068;,
 7.64422;32.00891;9.82068;,
 8.48941;32.85408;9.82068;,
 7.64422;18.67645;-9.82068;,
 8.48941;17.83128;-9.82068;,
 7.64422;16.98611;-9.82068;,
 6.79904;17.83128;-9.82068;,
 7.64422;18.67645;9.82068;,
 6.79904;17.83128;9.82068;,
 7.64422;16.98611;9.82068;,
 8.48941;17.83128;9.82068;,
 12.85126;44.88359;-5.00947;,
 12.85126;44.38532;-5.50773;,
 12.85126;44.88359;-6.00600;,
 12.85126;45.38186;-5.50773;,
 12.85126;44.88359;5.00947;,
 12.85126;45.38186;5.50773;,
 12.85126;44.88359;6.00600;,
 12.85126;44.38532;5.50773;,
 12.85126;6.08011;-5.00947;,
 12.85126;5.58184;-5.50773;,
 12.85126;6.08011;-6.00600;,
 12.85126;6.57837;-5.50773;,
 12.85126;6.08011;5.00947;,
 12.85126;6.57837;5.50773;,
 12.85126;6.08011;6.00600;,
 12.85126;5.58184;5.50773;,
 12.36253;22.58576;-4.54033;,
 12.36253;17.55770;-4.54033;,
 12.36253;17.55770;-4.74590;,
 12.36253;22.58576;-4.74590;,
 12.36253;22.58576;4.54033;,
 12.36253;22.58576;4.74590;,
 12.36253;17.55770;4.74590;,
 12.36253;17.55770;4.54033;,
 12.36253;17.56297;4.71902;,
 12.36253;17.56297;-4.64112;,
 12.36253;17.76855;-4.64112;,
 12.36253;17.76855;4.71902;,
 12.36253;22.38449;4.71902;,
 12.36253;22.38449;-4.64112;,
 12.36253;22.59006;-4.64112;,
 12.36253;22.59006;4.71902;,
 12.36253;21.41279;-3.52833;,
 12.36253;18.73068;-3.52833;,
 12.36253;18.73068;-3.86181;,
 12.36253;21.41279;-3.86181;,
 12.36253;21.41279;-3.06485;,
 12.36253;18.73068;-3.06485;,
 12.36253;18.73068;-3.39833;,
 12.36253;21.41279;-3.39833;,
 12.36253;21.41279;-2.57502;,
 12.36253;18.73068;-2.57502;,
 12.36253;18.73068;-2.90849;,
 12.36253;21.41279;-2.90849;,
 12.36253;21.41279;-1.91649;,
 12.36253;18.73068;-1.91649;,
 12.36253;18.73068;-2.24996;,
 12.36253;21.41279;-2.24996;,
 12.36253;21.41279;-1.42665;,
 12.36253;18.73068;-1.42665;,
 12.36253;18.73068;-1.76013;,
 12.36253;21.41279;-1.76013;,
 12.36253;21.41279;-0.63347;,
 12.36253;18.73068;-0.63347;,
 12.36253;18.73068;-0.96695;,
 12.36253;21.41279;-0.96695;,
 12.36253;21.41279;0.02507;,
 12.36253;18.73068;0.02507;,
 12.36253;18.73068;-0.30841;,
 12.36253;21.41279;-0.30841;,
 12.36253;21.41279;0.47878;,
 12.36253;18.73068;0.47878;,
 12.36253;18.73068;0.14530;,
 12.36253;21.41279;0.14530;,
 12.36253;21.41279;0.93254;,
 12.36253;18.73068;0.93254;,
 12.36253;18.73068;0.59906;,
 12.36253;21.41279;0.59906;,
 12.36253;21.41279;1.38568;,
 12.36253;18.73068;1.38568;,
 12.36253;18.73068;1.05220;,
 12.36253;21.41279;1.05220;,
 12.36253;21.41279;2.18379;,
 12.36253;18.73068;2.18379;,
 12.36253;18.73068;1.85031;,
 12.36253;21.41279;1.85031;,
 12.36253;21.41279;2.64727;,
 12.36253;18.73068;2.64727;,
 12.36253;18.73068;2.31379;,
 12.36253;21.41279;2.31379;,
 12.36253;21.41279;3.13710;,
 12.36253;18.73068;3.13710;,
 12.36253;18.73068;2.80363;,
 12.36253;21.41279;2.80363;,
 12.36253;21.41279;3.95127;,
 12.36253;18.73068;3.95127;,
 12.36253;18.73068;3.61780;,
 12.36253;21.41279;3.61780;,
 12.41080;30.80003;2.19098;,
 12.41080;29.00112;-0.48264;,
 12.41080;29.48482;-0.88850;,
 12.41080;31.27798;1.12680;,
 12.41080;32.41964;3.33553;,
 12.41080;30.95378;2.27210;,
 12.41080;31.40235;1.21533;,
 12.41080;34.23275;2.69184;,
 12.41080;30.21318;4.46113;,
 12.41080;27.20883;2.08204;,
 12.41080;27.55733;1.55551;,
 12.41080;30.36918;3.30503;,
 12.41080;32.59363;5.37845;,
 12.41080;30.38363;4.49525;,
 12.41080;30.51358;3.35460;,
 12.41080;32.34026;3.60549;,
 12.41080;34.41382;4.76168;,
 12.41080;32.70160;5.35993;,
 12.41080;32.46621;3.46194;,
 12.41080;34.30192;2.87889;,
 12.41080;37.20827;3.53658;,
 12.41080;34.55990;4.74373;,
 12.41080;34.44580;2.88265;,
 12.41080;37.09638;2.02709;,
 12.41080;37.02946;1.94398;,
 12.41080;35.61169;2.38535;,
 12.41080;36.80793;0.55382;,
 12.41080;37.47736;0.48583;,
 12.41080;37.51667;0.34446;,
 12.41080;36.86277;0.42775;,
 12.41080;37.63283;-1.49233;,
 12.41080;38.03227;-1.34771;,
 12.41080;38.71018;3.09109;,
 12.41080;37.50595;3.43370;,
 12.41080;37.23885;2.32375;,
 12.41080;38.40384;1.75090;,
 12.41080;38.70113;2.45426;,
 12.41080;38.51472;1.71481;,
 12.41080;39.44849;0.67250;,
 12.41080;39.84268;1.02033;,
 12.36131;27.00592;0.35761;,
 12.36131;23.91351;-0.86052;,
 12.36131;24.09205;-1.31380;,
 12.36131;27.18446;-0.09567;,
 12.36131;27.65854;-0.33770;,
 12.36131;24.75019;-5.93723;,
 12.36131;25.13667;-6.23381;,
 12.36131;28.04502;-0.63429;,
 12.36131;29.19508;-4.90535;,
 12.36131;29.13707;-1.58216;,
 12.36131;28.64996;-1.59066;,
 12.36131;28.70797;-4.91384;;
 
 117;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;16,17,18,19;,
 4;20,21,22,23;,
 4;24,25,26,27;,
 4;28,29,30,31;,
 4;28,21,32,33;,
 4;34,35,22,31;,
 4;36,37,38,39;,
 4;40,41,42,43;,
 4;44,45,46,47;,
 4;48,49,50,51;,
 4;48,41,52,53;,
 4;54,55,42,51;,
 4;56,57,58,59;,
 4;60,61,62,63;,
 4;64,65,66,67;,
 4;68,69,70,71;,
 4;72,73,74,75;,
 4;76,77,78,79;,
 4;80,81,82,83;,
 4;84,85,86,87;,
 4;88,89,90,91;,
 4;92,93,94,95;,
 4;96,97,98,99;,
 4;100,101,102,103;,
 4;104,105,106,107;,
 4;108,109,110,111;,
 4;112,113,114,115;,
 4;116,117,118,119;,
 4;120,121,122,123;,
 4;124,125,126,127;,
 4;128,129,130,131;,
 4;132,133,134,135;,
 4;136,137,138,139;,
 4;140,141,142,143;,
 4;144,145,146,147;,
 4;148,149,150,151;,
 4;152,153,154,155;,
 4;156,157,158,159;,
 4;160,161,162,163;,
 4;164,165,166,167;,
 4;168,169,170,171;,
 4;172,173,174,175;,
 4;176,177,178,179;,
 4;180,181,182,183;,
 4;184,185,186,187;,
 4;188,189,190,191;,
 4;192,193,194,195;,
 4;196,197,198,199;,
 4;200,201,202,203;,
 4;204,205,206,207;,
 4;208,209,210,211;,
 4;212,213,214,215;,
 4;216,217,218,219;,
 4;220,221,222,223;,
 4;224,225,226,227;,
 4;228,229,230,231;,
 4;228,221,232,233;,
 4;234,235,236,237;,
 4;238,239,240,241;,
 4;242,243,244,245;,
 4;246,247,248,249;,
 4;246,239,250,251;,
 4;252,253,240,249;,
 4;254,255,256,257;,
 4;258,259,260,261;,
 4;262,263,264,265;,
 4;262,266,267,268;,
 4;269,270,271,265;,
 4;272,273,274,275;,
 4;276,277,278,279;,
 4;280,281,282,283;,
 4;280,284,285,286;,
 4;287,288,289,283;,
 4;290,291,292,293;,
 4;294,295,296,297;,
 4;298,299,300,301;,
 4;302,303,304,305;,
 4;306,307,308,309;,
 4;310,311,312,313;,
 4;314,315,316,317;,
 4;318,319,320,321;,
 4;322,323,324,325;,
 4;326,327,328,329;,
 4;330,331,332,333;,
 4;334,335,336,337;,
 4;338,339,340,341;,
 4;342,343,344,345;,
 4;346,347,348,349;,
 4;350,351,352,353;,
 4;354,355,356,357;,
 4;358,359,360,361;,
 4;362,363,364,365;,
 4;366,367,368,369;,
 4;370,371,372,373;,
 4;374,375,376,377;,
 4;378,379,380,381;,
 4;382,383,384,385;,
 4;386,387,388,389;,
 4;390,391,392,393;,
 4;394,395,396,397;,
 4;398,399,400,401;,
 4;402,403,404,405;,
 4;406,407,408,409;,
 4;410,411,412,413;,
 4;414,415,416,417;,
 4;418,419,420,421;,
 4;422,423,424,425;,
 4;426,427,428,429;,
 4;430,431,432,433;,
 4;434,435,436,437;,
 4;438,439,440,441;,
 4;442,443,444,445;,
 4;446,447,448,449;;
 
 MeshMaterialList {
  5;
  117;
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
  3,
  3,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
  3,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  4,
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
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3;;
  Material {
   0.361000;0.478000;0.337000;1.000000;;
   51.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   1.000000;0.702000;0.000000;1.000000;;
   100.000000;
   1.000000;1.000000;1.000000;;
   1.000000;0.702000;0.000000;;
  }
  Material {
   1.000000;1.000000;1.000000;0.430000;;
   100.000000;
   1.000000;1.000000;1.000000;;
   0.280000;0.280000;0.280000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "af18.jpg";
   }
  }
  Material {
   1.000000;0.494000;0.000000;1.000000;;
   100.000000;
   1.000000;1.000000;1.000000;;
   1.000000;0.494000;0.000000;;
  }
 }
 MeshNormals {
  37;
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000001;-1.000000;,
  0.000000;0.000001;1.000000;,
  -1.000000;0.000001;0.000000;,
  1.000000;0.000001;0.000000;,
  0.000000;0.229304;-0.973355;,
  0.973355;0.229304;0.000000;,
  0.000000;0.229304;0.973355;,
  -0.973355;0.229304;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;;
  117;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;9,9,9,9;,
  4;10,10,10,10;,
  4;11,11,11,11;,
  4;12,12,12,12;,
  4;13,13,13,13;,
  4;14,14,14,14;,
  4;15,15,15,15;,
  4;16,16,16,16;,
  4;16,16,16,16;,
  4;17,17,17,17;,
  4;17,17,17,17;,
  4;16,16,16,16;,
  4;16,16,16,16;,
  4;17,17,17,17;,
  4;17,17,17,17;,
  4;16,16,16,16;,
  4;16,16,16,16;,
  4;17,17,17,17;,
  4;17,17,17,17;,
  4;16,16,16,16;,
  4;16,16,16,16;,
  4;17,17,17,17;,
  4;17,17,17,17;,
  4;18,18,18,18;,
  4;18,18,18,18;,
  4;19,19,19,19;,
  4;19,19,19,19;,
  4;18,18,18,18;,
  4;18,18,18,18;,
  4;19,19,19,19;,
  4;19,19,19,19;,
  4;18,18,18,18;,
  4;18,18,18,18;,
  4;19,19,19,19;,
  4;19,19,19,19;,
  4;18,18,18,18;,
  4;18,18,18,18;,
  4;19,19,19,19;,
  4;19,19,19,19;,
  4;20,20,20,20;,
  4;21,21,21,21;,
  4;20,20,20,20;,
  4;21,21,21,21;,
  4;22,22,22,22;,
  4;23,23,23,23;,
  4;22,22,22,22;,
  4;23,23,23,23;,
  4;24,24,24,24;,
  4;25,25,25,25;,
  4;26,26,26,26;,
  4;27,27,27,27;,
  4;28,28,28,28;,
  4;29,29,29,29;,
  4;30,30,30,30;,
  4;31,31,31,31;,
  4;32,32,32,32;,
  4;33,33,33,33;,
  4;34,34,34,34;,
  4;29,29,29,29;,
  4;31,31,31,31;,
  4;32,32,32,32;,
  4;33,33,33,33;,
  4;34,34,34,34;,
  4;29,29,29,29;,
  4;31,31,31,31;,
  4;32,32,32,32;,
  4;33,33,33,33;,
  4;34,34,34,34;,
  4;30,30,30,30;,
  4;29,29,29,29;,
  4;31,31,31,31;,
  4;29,29,29,29;,
  4;31,31,31,31;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;35,35,35,35;,
  4;35,35,35,35;,
  4;35,35,35,35;,
  4;35,35,35,35;,
  4;35,35,35,35;,
  4;35,35,35,35;,
  4;35,35,35,35;,
  4;35,35,35,35;,
  4;35,35,35,35;,
  4;35,35,35,35;,
  4;36,36,36,36;,
  4;36,36,36,36;,
  4;36,36,36,36;;
 }
 MeshTextureCoords {
  450;
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
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
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
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
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
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
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
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
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
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
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
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
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
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
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
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
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
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
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
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
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
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
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
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
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
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
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
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
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
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
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
  0.000000;1.000000;;
 }
}
