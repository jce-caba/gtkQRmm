#include "QrGeneratorPolynomial.hpp"

using namespace GtkQR;

int * QrGeneratorPolynomial::getGeneratorPolynomial(int value,int extra_space)
{
    int _size=value +1;
    int *res = 0;


    if (value==2){
           res = new int[3 + extra_space];
           res[2] =1 ; res[1] = 25 ;res[0] = 0;
    }
    else if (value==3){
           res = new int[4 + extra_space];
           res[3] = 3; res[2] = 199 ;res[1] = 198;res[0] = 0;
    }
    else if (value==5){
           res = new int[6 + extra_space];
           res[5] = 10;res[4] = 119;
           res[3] = 166;res[2] = 164;res[1] = 113; res[0] = 0;
    }
    else if (value==6){
           res = new int[7 + extra_space];
           res[6] = 15 ;res[5] = 176;res[4] = 5;
           res[3] = 134;res[2] = 0;res[1] = 166; res[0] = 0;
    }
    else if (value==7){
           res = new int[8 + extra_space];
           res[7] = 21; res[6] = 102 ;res[5] = 238;res[4] = 149;
           res[3] = 146;res[2] = 229;res[1] = 87; res[0] = 0;
    }
    else if (value==8){
           res = new int[9 + extra_space];
           res[8] = 28;
           res[7] = 196; res[6] = 252 ;res[5] = 215;res[4] = 249;
           res[3] = 208;res[2] = 238;res[1] = 175; res[0] = 0;
    }
    else if (value==10){
           res = new int[11 + extra_space];
           res[10] = 45; res[9] = 32 ;res[8] = 94;res[7] = 64;
           res[6] = 70;  res[5] = 118;res[4] = 61;res[3] = 46;
           res[2] = 67; res[1] = 251;res[0] = 0;

    }
    else if (value==13){ //ok

           res = new int[14 + extra_space];
           res[13] = 78;  res[12] = 140 ;res[11] = 206;res[10] = 218;
           res[9] = 130; res[8] = 104; res[7] = 106;res[6] = 100;
           res[5] = 86;  res[4] = 100; res[3] = 176; res[2] = 152;
           res[1] = 74; res[0] = 0;

    }
    else if (value==14){
           res = new int[15 + extra_space];
           res[14] = 91 ;res[13] = 22; res[12] = 59;
           res[11] = 207; res[10] = 87; res[9] = 216;res[8] = 137;
           res[7] = 218;  res[6] = 124; res[5] = 190;  res[4] = 48;
           res[3] = 155; res[2] = 249; res[1] = 199; res[0] = 0;
    }
    else if (value==15){
           res = new int[16 + extra_space];
           res[15] = 105;  res[14] = 99 ;res[13] = 5; res[12] = 124;
           res[11] = 140; res[10] = 237; res[9] = 58;res[8] = 58;
           res[7] = 51;  res[6] = 37; res[5] = 202; res[4] = 91;
           res[3] = 61; res[2] = 183; res[1] = 8; res[0] = 0;
    }
    else if (value==16){
           res = new int[17 + extra_space];
           res[16] = 120;  res[15] = 225 ;res[14] = 194; res[13] = 182;
           res[12] = 169; res[11] = 147; res[10] = 191;res[9] = 91;
           res[8] = 3;  res[7] = 76; res[6] = 161; res[5] = 102;
           res[4] = 109; res[3] = 107; res[2] = 104; res[1] = 120;res[0] = 0;

    }
    else if (value==17){
           res = new int[18 + extra_space];
           res[17] = 136;  res[16] = 163 ;res[15] = 243; res[14] = 39;
           res[13] = 150; res[12] = 99; res[11] = 24;res[10] = 147;
           res[9] = 214;  res[8] = 206; res[7] = 123; res[6] = 239;
           res[5] = 43; res[4] = 78; res[3] = 206; res[2] = 139;res[1] = 43;
           res[0] = 0;

    }
    else if (value==18){
          res = new int[19 + extra_space];
          res[18] = 153;  res[17] = 96 ;res[16] = 98; res[15] = 5;
           res[14] = 179;  res[13] = 252; res[12] = 148; res[11] = 152;
           res[10] = 187;  res[9] = 79; res[8] = 170; res[7] = 118;
           res[6] = 97; res[5] = 184; res[4] = 94; res[3] = 158;res[2] = 234;
           res[1] = 215; res[0] =0;

    }
    else if (value==20){
           res = new int[21 + extra_space];
           res[20] = 190;  res[19] = 188 ;res[18] = 212; res[17] = 212;
           res[16] = 164;  res[15] = 156; res[14] = 239; res[13] = 83;
           res[12] = 225;  res[11] = 221; res[10] = 180; res[9] = 202;
           res[8] = 187; res[7] = 26; res[6] = 163; res[5] = 61;res[4] = 50;
           res[3] = 79; res[2] = 60; res[1] = 17; res[0] = 0;

    }
    else if (value==22){ //check OK
           res = new int[23 + extra_space];
           res[22] = 231;  res[21] = 165 ;res[20] = 105; res[19] = 160;
           res[18] = 134;  res[17] = 219; res[16] = 80; res[15] = 98;
           res[14] = 172;  res[13] = 8; res[12] = 74; res[11] = 200;
           res[10] = 53; res[9] = 221; res[8] = 109; res[7] = 14;res[6] = 230;
           res[5] = 93; res[4] = 242; res[3] = 247; res[2] = 171;res[1] = 210;res[0] = 0;


    }
    else if (value==24){
           res = new int[25 + extra_space];
           res[24] = 21;  res[23] = 227 ;res[22] = 96; res[21] = 87;
           res[20] = 232;  res[19] = 117; res[18] = 0; res[17] = 111;
           res[16] = 218;  res[15] = 228; res[14] = 226; res[13] = 192;
           res[12] = 152; res[11] = 169; res[10] = 180; res[9] = 159;res[8] = 126;
           res[7] = 251; res[6] = 117; res[5] = 211; res[4] = 48;res[3] = 135;res[2] = 121;
           res[1] = 229;res[0] = 0;


    }
    else if (value==26){
           res = new int[27 + extra_space];
           res[26] = 70;  res[25] = 218 ;res[24] = 145; res[23] = 153;
           res[22] = 227;  res[21] = 48; res[20] = 102; res[19] = 13;
           res[18] = 142;  res[17] = 245; res[16] = 21; res[15] = 161;
           res[14] = 53; res[13] = 165; res[12] = 28; res[11] = 111;res[10] = 201;
           res[9] = 145; res[8] = 17; res[7] = 118; res[6] = 182;res[5] = 103;res[4] = 2;
           res[3] = 158;res[2] = 125;  res[1] = 173; res[0] = 0;

    }
    else if (value==28){
           res = new int[29 + extra_space];
           res[28] = 123;  res[27] = 9 ;res[26] = 37; res[25] = 242;
           res[24] = 119;  res[23] = 212; res[22] = 195;  res[21] = 42;
           res[20] = 87;  res[19] = 245; res[18] = 43; res[17] = 21;
           res[16] = 201; res[15] = 232; res[14] = 27; res[13] = 205;res[12] = 147;
           res[11] = 195; res[10] = 190; res[9] = 110; res[8] = 180;res[7] = 108;res[6] = 234;
           res[5] = 224;res[4] = 104;  res[3] = 200; res[2] = 223;res[1] = 168;res[0] = 0;


    }
    else if (value==30){ //OK
           res = new int[31 + extra_space];
           res[30] = 180;  res[29] = 192 ;res[28] = 40; res[27] = 238;
           res[26] = 216; res[25] = 251; res[24] = 37;res[23] = 156;
           res[22] = 130;  res[21] = 224; res[20] = 193; res[19] = 226;
           res[18] = 173; res[17] = 42; res[16] = 125; res[15] = 222;res[14] = 96;
           res[13] = 239; res[12] = 86; res[11] = 110; res[10] = 48;res[9] = 50;res[8] = 182;
           res[7] = 179;res[6] = 31;res[5] = 216;   res[4] = 152;res[3] = 145;res[2] = 173;
           res[1] = 41; res[0] = 0;
    }

    for (int i = _size ; i < _size + extra_space; i =i + 1)
                 res[i] = -1;

    return res;
}
