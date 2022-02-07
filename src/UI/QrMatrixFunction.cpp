#include "QrMatrixFunction.hpp"


using namespace GtkQR;

char ** QrMatrixFunction::getMatrixFunction(QRDataContainer *data)
{
   if(data->isMicro )
        return getMatrixFunction_micro_QR (data);
    else
        return getMatrixFunction_QR (data);
}

char ** QrMatrixFunction::getMatrixFunction_micro_QR(QRDataContainer *data)
{
   short num_modules = data->getnum_modules();

   char **matrix = new char*[num_modules +1 ];


   for(int i =0 ; i < num_modules ; i++)
   {
      matrix[i] = new char[num_modules +1 ];
      for(int a =0 ; a < num_modules ; a++)
                                    matrix[i][a] = '0';

      matrix[i][num_modules] = '\0';
   }

   matrix[num_modules]=  NULL;

    /* finder patterns */
    matrix[0][0] = '1';matrix[1][0] = '1';matrix[2][0] = '1';matrix[3][0] = '1';matrix[4][0] = '1';matrix[5][0] = '1';matrix[6][0] = '1';
    matrix[0][6] = '1';matrix[1][6] = '1';matrix[2][6] = '1';matrix[3][6] = '1';matrix[4][6] = '1';matrix[5][6] = '1';matrix[6][6] = '1';
    matrix[0][1] = '1'; matrix[0][2] = '1';matrix[0][3] = '1';matrix[0][4] = '1'; matrix[0][5] = '1';
    matrix[6][1] = '1'; matrix[6][2] = '1';matrix[6][3] = '1';matrix[6][4] = '1'; matrix[6][5] = '1';
    matrix[2][2] = '1'; matrix[3][2] = '1'; matrix[4][2] = '1';
    matrix[2][3] = '1'; matrix[3][3] = '1'; matrix[4][3] = '1';
    matrix[2][4] = '1'; matrix[3][4] = '1'; matrix[4][4] = '1';

    for(int i =8 ; i < num_modules ; i=i+2)
                                   matrix[0][i] = '1';

    for(int i =8 ; i < num_modules ; i=i+2)
                                   matrix[i][0] = '1';


 return matrix;
}


char ** QrMatrixFunction::getMatrixFunction_QR(QRDataContainer *data)
{
   char **matrix;
   short num_modules = data->getnum_modules();
   int aux;

   matrix = new char*[num_modules +1 ];

   for(int i =0 ; i < num_modules ; i++)
   {
      matrix[i] = new char[num_modules +1 ];
      for(int a =0 ; a < num_modules ; a++)
                                    matrix[i][a] = '0';

      matrix[i][num_modules] = '\0';
   }

    matrix[num_modules]=  NULL;


    /* finder patterns */
    matrix[0][0] = '1';matrix[1][0] = '1';matrix[2][0] = '1';matrix[3][0] = '1';matrix[4][0] = '1';matrix[5][0] = '1';matrix[6][0] = '1';
    matrix[0][6] = '1';matrix[1][6] = '1';matrix[2][6] = '1';matrix[3][6] = '1';matrix[4][6] = '1';matrix[5][6] = '1';matrix[6][6] = '1';
    matrix[0][1] = '1'; matrix[0][2] = '1';matrix[0][3] = '1';matrix[0][4] = '1'; matrix[0][5] = '1';
    matrix[6][1] = '1'; matrix[6][2] = '1';matrix[6][3] = '1';matrix[6][4] = '1'; matrix[6][5] = '1';
    matrix[2][2] = '1'; matrix[3][2] = '1'; matrix[4][2] = '1';
    matrix[2][3] = '1'; matrix[3][3] = '1'; matrix[4][3] = '1';
    matrix[2][4] = '1'; matrix[3][4] = '1'; matrix[4][4] = '1';

    aux = num_modules-1;
    matrix[0][aux] = '1';matrix[1][aux] = '1';matrix[2][aux] = '1';matrix[3][aux] = '1';matrix[4][aux] = '1';matrix[5][aux] = '1';matrix[6][aux] = '1';
    matrix[0][aux - 1] = '1'; matrix[0][aux -2] = '1';matrix[0][aux -3] = '1';matrix[0][aux -4] = '1'; matrix[0][aux -5] = '1';
    matrix[6][aux - 1] = '1'; matrix[6][aux -2] = '1';matrix[6][aux -3] = '1';matrix[6][aux -4] = '1'; matrix[6][aux -5] = '1';
    matrix[aux][1] = '1'; matrix[aux][2] = '1';matrix[aux][3] = '1';matrix[aux][4] = '1'; matrix[aux][5] = '1';
    aux = num_modules-5;
    matrix[2][aux] = '1'; matrix[3][aux] = '1'; matrix[4][aux] = '1';
    aux = num_modules-4;
    matrix[2][aux] = '1'; matrix[3][aux] = '1'; matrix[4][aux] = '1';
    aux = num_modules-3;
    matrix[2][aux] = '1'; matrix[3][aux] = '1'; matrix[4][aux] = '1';

    aux = num_modules-7;
    matrix[0][aux] = '1';matrix[1][aux] = '1';matrix[2][aux] = '1';matrix[3][aux] = '1';matrix[4][aux] = '1';matrix[5][aux] = '1';matrix[6][aux] = '1';
    matrix[aux][0] = '1';matrix[aux+1][0] = '1';matrix[aux+2][0] = '1';matrix[aux+3][0] = '1';matrix[aux+4][0] = '1';matrix[aux+5][0] = '1';matrix[aux+6][0] = '1';
    matrix[aux][6] = '1';matrix[aux+1][6] = '1';matrix[aux+2][6] = '1';matrix[aux+3][6] = '1';matrix[aux+4][6] = '1';matrix[aux+5][6] = '1';matrix[aux+6][6] = '1';
    matrix[aux][1] = '1'; matrix[aux][2] = '1'; matrix[aux][3] = '1';matrix[aux][4] = '1'; matrix[aux][5] = '1';
    aux = aux + 2 ;
    matrix[aux][2] = '1'; matrix[aux+1][2] = '1'; matrix[aux+2][2] = '1';
    matrix[aux][3] = '1'; matrix[aux+1][3] = '1'; matrix[aux+2][3] = '1';
    matrix[aux][4] = '1'; matrix[aux+1][4] = '1'; matrix[aux+2][4] = '1';

    /* Timing Patterns */

    aux =  num_modules - 16 ;

    for (int i = 8 ; i < 8 + aux ; i =i +2 )
                  matrix[i][6] = '1';

    for (int i = 8 ; i < 8 + aux ; i =i +2 )
                  matrix[6][i] = '1';


     /* Dark Module */
     matrix[8][num_modules-8] = '1';


   return matrix;
}

void QrMatrixFunction::setMatrixFunctionFormat(char **matrix,QRDataContainer *data,std::string & text)
{
   if(data->isMicro )
         setMatrixFunctionFormat_micro_QR (matrix,data,text);
    else
         setMatrixFunctionFormat_QR (matrix,data,text);

}

void QrMatrixFunction::setMatrixFunctionFormat_micro_QR(char **matrix,QRDataContainer *data,std::string & text)
{
    int b = 0;
    int lg =text.size() -1;

    if(lg < 0)
        return;



    for(int a=1 ; a < 9 ; a ++)
    {
        matrix[a][8] = text[b];
        b++;
    }

    for(int a=1 ; a < 8 ; a ++)
    {
        matrix[8][a] = text[lg];
        lg--;
    }


}

void QrMatrixFunction::setMatrixFunctionFormat_QR(char **matrix,QRDataContainer *data,std::string & text)
{
     int b = 0;
     short num_modules = data->getnum_modules();

     for(int a=0 ; a < 9 ; a ++)
     {
         if( a != 6)
         {
           matrix[a][8] = text[b];
           b++;
         }
     }

     for(int a=7 ; a >=0 ; a --)
     {
         if( a != 6)
         {
           matrix[8][a] = text[b];
           b++;
         }
     }

     b = 0;

     for(int a=num_modules - 1 ; a >= num_modules - 7 ; a --)
     {
           matrix[8][a] = text[b];
           b++;
     }

     for(int a=num_modules - 8 ; a <= num_modules - 1 ; a ++)
     {
           matrix[a][8] = text[b];
           b++;
     }

}

void QrMatrixFunction::setMatrixFunctionVersion(char **matrix,QRDataContainer *data,std::string & text)
{
    int lg ;
    int b ;
    int aux  ;
    short num_modules = data->getnum_modules();

    lg = text.size() - 1;
    b = lg;

    aux = num_modules-11;

    for(int i=0 ; i < 6 ; i ++)
    {
        for(int a=0 ; a < 3 ; a ++)
        {
          matrix[i][aux+a] = text[b];
          b -- ;
        }
    }


     b = lg;

    for(int i=0 ; i < 6 ; i ++)
    {
        for(int a=0 ; a < 3 ; a ++)
        {
           matrix[aux+a][i] = text[b];
           b -- ;
        }
    }
}

