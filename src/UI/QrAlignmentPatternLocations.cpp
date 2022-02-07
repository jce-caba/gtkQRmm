#include "QrAlignmentPatternLocations.hpp"

using namespace GtkQR;

void  QrAlignmentPatternLocations::getAlignment(QRDataContainer *data,char **matrix)
{
  int aux=0;
  int aux2 =0;
  int aux3 =0;
  int aux4 =0;
  int aux5 =0;
  int aux6 =0;
  short qrversion_number=data->getqrversion_number();

  if(data->isMicro )
    return;

  if (qrversion_number >= 2 && qrversion_number <= 6 )
  {

      if (qrversion_number == 2)
                aux = 18;
      else if (qrversion_number == 3)
                aux = 22;
      else if (qrversion_number == 4)
                aux = 26;
      else if (qrversion_number == 5)
                aux = 30;
      else if (qrversion_number == 6) //
                aux = 34;

      setpointmatrix(matrix,aux,aux);

  }
  else if (qrversion_number >= 7 && qrversion_number <= 13 )
  {

     if (qrversion_number == 7)
     {
        aux =22; aux2 =38;
     }
     else if (qrversion_number == 8)
     {
        aux =24; aux2 =42;
     }
     else if (qrversion_number == 9)
     {
        aux =26; aux2 =46;
     }
     else if (qrversion_number == 10)
     {
        aux =28; aux2 =50;
     }
     else if (qrversion_number == 11)
     {
        aux =30; aux2 =54;
     }
     else if (qrversion_number == 12)
     {
        aux =32; aux2 =58;
     }
     else if (qrversion_number == 13)
     {
        aux =34; aux2 =62;
     }

     setpointmatrix(matrix,6,aux);
     setpointmatrix(matrix,aux,6);
     setpointmatrix(matrix,aux,aux);
     setpointmatrix(matrix,aux2,aux2);
     setpointmatrix(matrix,aux,aux2);
     setpointmatrix(matrix,aux2,aux);

  }
  else if (qrversion_number >= 14 && qrversion_number <= 20 )
  {

     if (qrversion_number == 14) //
     {
        aux =26; aux2 =46; aux3 =66;
     }
     else if (qrversion_number == 15)
     {
        aux =26; aux2 =48; aux3 =70;
     }
     else if (qrversion_number == 16)
     {
        aux =26; aux2 =50; aux3 =74;
     }
     else if (qrversion_number == 17)
     {
        aux =30; aux2 =54; aux3 =78;
     }
     else if (qrversion_number == 18)
     {
        aux =30; aux2 =56; aux3 =82;
     }
     else if (qrversion_number == 19)
     {
        aux =30; aux2 =58; aux3 =86;
     }
     else if (qrversion_number == 20)
     {
        aux =34; aux2 =62; aux3 =90;
     }

     setpointmatrix(matrix,6,aux);
     setpointmatrix(matrix,6,aux2);
     setpointmatrix(matrix,aux,6);
     setpointmatrix(matrix,aux,aux);
     setpointmatrix(matrix,aux,aux2);
     setpointmatrix(matrix,aux,aux3);
     setpointmatrix(matrix,aux2,6);
     setpointmatrix(matrix,aux2,aux);
     setpointmatrix(matrix,aux2,aux2);
     setpointmatrix(matrix,aux2,aux3);
     setpointmatrix(matrix,aux3,aux3);
     setpointmatrix(matrix,aux3,aux);
     setpointmatrix(matrix,aux3,aux2);

  }
  else if (qrversion_number >= 21 && qrversion_number <= 27 )
  {

     if (qrversion_number == 21) // 6	28	50	72	94
     {
        aux =28; aux2 =50; aux3 =72; aux4 =94;
     }
     else if (qrversion_number == 22)
     {
        aux =26; aux2 =50; aux3 =74; aux4 =98;
     }
     else if (qrversion_number == 23)
     {
        aux =30; aux2 =54; aux3 =78; aux4 =102;
     }
     else if (qrversion_number == 24)
     {
        aux =28; aux2 =54; aux3 =80; aux4 =106;
     }
     else if (qrversion_number == 25)
     {
        aux =32; aux2 =58; aux3 =84; aux4 =110;
     }
     else if (qrversion_number == 26)
     {
        aux =30; aux2 =58; aux3 =86; aux4 =114;
     }
     else if (qrversion_number == 27)
     {
        aux =34; aux2 =62; aux3 =90; aux4 =118;
     }

     setpointmatrix(matrix,6,aux);
     setpointmatrix(matrix,6,aux2);
     setpointmatrix(matrix,6,aux3);
     setpointmatrix(matrix,aux,6);
     setpointmatrix(matrix,aux,aux);
     setpointmatrix(matrix,aux,aux2);
     setpointmatrix(matrix,aux,aux3);
     setpointmatrix(matrix,aux,aux4);
     setpointmatrix(matrix,aux2,6);
     setpointmatrix(matrix,aux2,aux);
     setpointmatrix(matrix,aux2,aux2);
     setpointmatrix(matrix,aux2,aux3);
     setpointmatrix(matrix,aux2,aux4);
     setpointmatrix(matrix,aux3,6);
     setpointmatrix(matrix,aux3,aux);
     setpointmatrix(matrix,aux3,aux2);
     setpointmatrix(matrix,aux3,aux3);
     setpointmatrix(matrix,aux3,aux4);
     setpointmatrix(matrix,aux4,aux);
     setpointmatrix(matrix,aux4,aux2);
     setpointmatrix(matrix,aux4,aux3);
     setpointmatrix(matrix,aux4,aux4);

  }
  else if (qrversion_number >= 28 && qrversion_number <= 34 )
  {


     if (qrversion_number == 28) // 6	26	50	74	98	122
     {
        aux =26; aux2 =50; aux3 =74; aux4 =98; aux5 = 122;
     }
     else if (qrversion_number == 29)// 6	30	54	78	102	126
     {
        aux =30; aux2 =54; aux3 =78; aux4 =102; aux5 = 126;
     }
     else if (qrversion_number == 30)// 6	26	52	78	104	130
     {
        aux =26; aux2 =52; aux3 =78; aux4 =104; aux5 = 130;
     }
     else if (qrversion_number == 31)// 6	30	56	82	108	134
     {
        aux =30; aux2 =56; aux3 =82; aux4 =108; aux5 = 134;
     }
     else if (qrversion_number == 32)// 6	34	60	86	112	138
     {
        aux =34; aux2 =60; aux3 =86; aux4 =112; aux5 = 138;
     }
     else if (qrversion_number == 33)// 6	30	58	86	114	142
     {
        aux =30; aux2 =58; aux3 =86; aux4 =114; aux5 = 142;
     }
     else if (qrversion_number == 34)// 6	34	62	90	118	146
     {
        aux =34; aux2 =62; aux3 =90; aux4 =118; aux5 = 146;
     }

     setpointmatrix(matrix,aux,6);
     setpointmatrix(matrix,aux2,6);
     setpointmatrix(matrix,aux3,6);
     setpointmatrix(matrix,aux4,6);

     // ----------------------------------------------------
        setpointmatrix(matrix,6,aux);
        setpointmatrix(matrix,aux,aux);
        setpointmatrix(matrix,aux2,aux);
        setpointmatrix(matrix,aux3,aux);
        setpointmatrix(matrix,aux4,aux);
        setpointmatrix(matrix,aux5,aux);

     // ----------------------------------------------------
        setpointmatrix(matrix,6,aux2);
        setpointmatrix(matrix,aux,aux2);
        setpointmatrix(matrix,aux2,aux2);
        setpointmatrix(matrix,aux3,aux2);
        setpointmatrix(matrix,aux4,aux2);
        setpointmatrix(matrix,aux5,aux2);

     // ----------------------------------------------------
        setpointmatrix(matrix,6,aux3);
        setpointmatrix(matrix,aux,aux3);
        setpointmatrix(matrix,aux2,aux3);
        setpointmatrix(matrix,aux3,aux3);
        setpointmatrix(matrix,aux4,aux3);
        setpointmatrix(matrix,aux5,aux3);

     // ----------------------------------------------------

        setpointmatrix(matrix,6,aux4);
        setpointmatrix(matrix,aux,aux4);
        setpointmatrix(matrix,aux2,aux4);
        setpointmatrix(matrix,aux3,aux4);
        setpointmatrix(matrix,aux4,aux4);
        setpointmatrix(matrix,aux5,aux4);

     // ----------------------------------------------------
        setpointmatrix(matrix,aux,aux5);
        setpointmatrix(matrix,aux2,aux5);
        setpointmatrix(matrix,aux3,aux5);
        setpointmatrix(matrix,aux4,aux5);
        setpointmatrix(matrix,aux5,aux5);


  }
  else if (qrversion_number >= 35 && qrversion_number <= 40 )
  {


     if (qrversion_number == 35)
     {
        aux =30; aux2 =54; aux3 =78; aux4 =102; aux5 = 126; aux6 =150;
     }
     else if (qrversion_number == 36)
     {
        aux =24; aux2 =50; aux3 =76; aux4 =102; aux5 = 128; aux6 =154;
     }
     else if (qrversion_number == 37)
     {
        aux =28; aux2 =54; aux3 =80; aux4 =106; aux5 = 132; aux6 =158;
     }
     else if (qrversion_number == 38)
     {
        aux =32; aux2 =58; aux3 =84; aux4 =110; aux5 = 136; aux6 =162;
     }
     else if (qrversion_number == 39)
     {
        aux =26; aux2 =54; aux3 =82; aux4 =110; aux5 = 138; aux6 =166;
     }
     else if (qrversion_number == 40)
     {
        aux =30; aux2 =58; aux3 =86; aux4 =114; aux5 = 142; aux6 =170;
     }

     setpointmatrix(matrix,aux,6);
     setpointmatrix(matrix,aux2,6);
     setpointmatrix(matrix,aux3,6);
     setpointmatrix(matrix,aux4,6);
     setpointmatrix(matrix,aux5,6);

     // -------------------------------------
     setpointmatrix(matrix,6,aux);
     setpointmatrix(matrix,aux,aux);
     setpointmatrix(matrix,aux2,aux);
     setpointmatrix(matrix,aux3,aux);
     setpointmatrix(matrix,aux4,aux);
     setpointmatrix(matrix,aux5,aux);
     setpointmatrix(matrix,aux6,aux);

      // -------------------------------------
     setpointmatrix(matrix,6,aux2);
     setpointmatrix(matrix,aux,aux2);
     setpointmatrix(matrix,aux2,aux2);
     setpointmatrix(matrix,aux3,aux2);
     setpointmatrix(matrix,aux4,aux2);
     setpointmatrix(matrix,aux5,aux2);
     setpointmatrix(matrix,aux6,aux2);

      // -------------------------------------
     setpointmatrix(matrix,6,aux3);
     setpointmatrix(matrix,aux,aux3);
     setpointmatrix(matrix,aux2,aux3);
     setpointmatrix(matrix,aux3,aux3);
     setpointmatrix(matrix,aux4,aux3);
     setpointmatrix(matrix,aux5,aux3);
     setpointmatrix(matrix,aux6,aux3);

      // -------------------------------------

     setpointmatrix(matrix,6,aux4);
     setpointmatrix(matrix,aux,aux4);
     setpointmatrix(matrix,aux2,aux4);
     setpointmatrix(matrix,aux3,aux4);
     setpointmatrix(matrix,aux4,aux4);
     setpointmatrix(matrix,aux5,aux4);
     setpointmatrix(matrix,aux6,aux4);
     // -------------------------------------
     setpointmatrix(matrix,6,aux5);
     setpointmatrix(matrix,aux,aux5);
     setpointmatrix(matrix,aux2,aux5);
     setpointmatrix(matrix,aux3,aux5);
     setpointmatrix(matrix,aux4,aux5);
     setpointmatrix(matrix,aux5,aux5);
     setpointmatrix(matrix,aux6,aux5);

     // -------------------------------------

     setpointmatrix(matrix,aux,aux6);
     setpointmatrix(matrix,aux2,aux6);
     setpointmatrix(matrix,aux3,aux6);
     setpointmatrix(matrix,aux4,aux6);
     setpointmatrix(matrix,aux5,aux6);
     setpointmatrix(matrix,aux6,aux6);

  }



}

void  QrAlignmentPatternLocations::setpointmatrix(char **_matrix,int x,int y)
{
  int aux;

  _matrix[x][y] = '1';
  aux = y - 2;
  _matrix[x-2][aux] = '1'; _matrix[x-1][aux] = '1'; _matrix[x][aux] = '1';_matrix[x+1][aux] = '1';_matrix[x+2][aux] = '1';
  aux = y + 2;
  _matrix[x-2][aux] = '1'; _matrix[x-1][aux] = '1'; _matrix[x][aux] = '1';_matrix[x+1][aux] = '1';_matrix[x+2][aux] = '1';
  aux = x - 2;
  _matrix[aux][y-1] = '1'; _matrix[aux][y] = '1';_matrix[aux][y+1] = '1';
  aux = x + 2;
  _matrix[aux][y-1] = '1'; _matrix[aux][y] = '1';_matrix[aux][y+1] = '1';

}

void  QrAlignmentPatternLocations::getSeparation(int version ,int *separation)
{
    if (version >= 7 && version <= 13 ){

         separation[2] =9;

     if (version == 7)
     {
        separation[1] =25; separation[0] =41;
     }
     else if (version == 8)
     {
        separation[1] =27; separation[0] =45;
     }
     else if (version == 9)
     {
        separation[1] =29; separation[0] =49;
     }
     else if (version == 10)
     {
        separation[1] =31; separation[0] =53;
     }
     else if (version == 11)
     {
        separation[1] =33; separation[0] =57;
     }
     else if (version == 12)
     {
        separation[1] =35; separation[0] =61;
     }
     else if (version == 13)
     {
        separation[1] =37; separation[0] =65;
     }
    }
    else if (version >= 14 && version <= 20 ){

        separation[3] =9;

        if (version == 14) // OK
        {
            separation[2] =29;
            separation[1]=49;
            separation[0]=69;
        }
        else if (version == 15) // OK
        {
            separation[2] =29;
            separation[1]=51;
            separation[0]=73;
        }
        else if (version == 16) //OK
        {
            separation[2]  =29;
            separation[1] =53;
            separation[0] =77;
        }
        else if (version == 17) //OK
        {
            separation[2] =33;
            separation[1] =57;
            separation[0] =81;
        }
        else if (version ==18) //OK
        {
            separation[2] =33;
            separation[1] =59;
            separation[0] =85;
        }
        else if (version ==19) //ok
        {
            separation[2] = 33;
            separation[1] =61;
            separation[0] =89;
        }
        else if (version == 20) // ok
        {
            separation[2] =37;
            separation[1] =65;
            separation[0] =93;
        }
    }
    else if (version >= 21 && version <= 27 )  {

     separation[4] =9;

     if (version == 21) // 6	28	50	72	94
     {
        separation[3] =31; separation[2] =53; separation[1]=75; separation[0]=97;
     }
     else if (version == 22)
     {
        separation[3] =29; separation[2] =53; separation[1]=77; separation[0]=101;
     }
     else if (version == 23)
     {
        separation[3] =33; separation[2] =57; separation[1]=81; separation[0]=105;
     }
     else if (version == 24)
     {
        separation[3] =31; separation[2] =57; separation[1]=83; separation[0]=109;
     }
     else if (version == 25)
     {
        separation[3] =35; separation[2] =61; separation[1]=87; separation[0]=113;
     }
     else if (version == 26)
     {
        separation[3] =33; separation[2] =61; separation[1]=89; separation[0]=117;
     }
     else if (version == 27)
     {
        separation[3] =37; separation[2] =65; separation[1]=93; separation[0]=121;
     }

  }
    else if (version >= 28 && version <= 34 ){
      separation[5] =9;

     if (version == 28)
     {
        separation[4] =29; separation[3] =53; separation[2] =77; separation[1]=101; separation[0]= 125;
     }
     else if (version == 29)
     {
        separation[4] =33; separation[3] =57; separation[2] =81; separation[1]=105; separation[0]= 129;
     }
     else if (version == 30)// 6	26	52	78	104	130
     {
        separation[4] =29; separation[3] =55; separation[2] =81; separation[1]=107; separation[0]= 133;
     }
     else if (version == 31)// 6	30	56	82	108	134
     {
        separation[4] =33; separation[3] =59; separation[2] =85; separation[1]=111; separation[0]= 137;
     }
     else if (version == 32)// 6	34	60	86	112	138
     {
        separation[4] =37; separation[3] =63; separation[2] =89; separation[1]=115; separation[0]= 141;
     }
     else if (version == 33)// 6	30	58	86	114	142
     {
        separation[4] =33; separation[3] =61; separation[2] =89; separation[1]=117; separation[0]= 145;
     }
     else if (version == 34)// 6	34	62	90	118	146
     {
        separation[4] =37; separation[3] =65; separation[2] =93; separation[1]=121; separation[0]= 149;
     }
   }
    else if (version >= 35 && version <= 40 ){

     separation[6] =9;

     if (version == 35)
     {
        separation[5]=33; separation[4]=57; separation[3]=81; separation[2]=105; separation[1]= 129; separation[0]=153;
     }
     else if (version == 36)
     {
        separation[5]=27; separation[4]=53; separation[3]=79; separation[2]=105; separation[1]= 131; separation[0]=157;
     }
     else if (version == 37)
     {
        separation[5]=31; separation[4]=57; separation[3]=83; separation[2]=109; separation[1]= 135; separation[0]=161;
     }
     else if (version == 38)
     {
        separation[5]=35; separation[4]=61; separation[3]=87; separation[2]=113; separation[1]= 139; separation[0]=165;
     }
     else if (version == 39)
     {
        separation[5]=29; separation[4]=57; separation[3]=85; separation[2]=113; separation[1]= 141; separation[0]=169;
     }
     else if (version == 40)
     {
        separation[5]=33; separation[4]=61; separation[3]=89; separation[2]=117; separation[1]= 145; separation[0]=173;
     }

  }
}

int  QrAlignmentPatternLocations::getNumberElements(int version)
{
    if (version >= 14 && version <= 20 )
                  return 4;
    else if (version >= 21 && version <= 27 )
                  return 5;
    else if (version >= 7 && version <= 13 )
                  return 3;
    else if (version >= 28 && version <= 34 )
                   return 6;
    else if (version >= 35 && version <= 40 )
                   return 7;

    return 0;
}
