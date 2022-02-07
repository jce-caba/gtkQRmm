#include "QrMatrixUtils.hpp"

using namespace GtkQR;

void QrMatrixUtils::sumMatrix(char **matrix1,const char **matrix2,QRDataContainer *data)
{
   const short num_modules = data->getnum_modules();

   for(int i =0 ; i < num_modules ; i++)
   {

      for(int a =0 ; a < num_modules ; a++)
      {
          if(matrix1[i][a] == '1' ||  matrix2[i][a]== '1')
                                          matrix1[i][a]= '1';
          else
                                          matrix1[i][a]= '0';

      }
   }


}

char ** QrMatrixUtils::createMatrix(const char **matrix,QRDataContainer *data)
{
   char **_copy;
   const short num_modules = data->getnum_modules();


   _copy=new char*[num_modules +1 ];

   for(int i =0 ; i < num_modules ; i++)
   {
      _copy[i] =  new char[num_modules +1 ];
      for(int a =0 ; a < num_modules ; a++)
                                    _copy[i][a] = matrix[i][a];

      _copy[i][num_modules] = '\0';
   }

    _copy[num_modules]=  NULL;


    return _copy;
}


void QrMatrixUtils::copyMatrix(char **matrix1,const char **matrix2,QRDataContainer *data)
{
   const short num_modules = data->getnum_modules();

   for(int i =0 ; i < num_modules ; i++)
   {
      for(int a =0 ; a < num_modules ; a++)
                                    matrix1[i][a] = matrix2[i][a];

   }

}

void QrMatrixUtils::freeMatrix(char **matrix)
{

   int a =0;

   do
   {
     delete [] matrix[a];
     a++;
   }while(matrix[a] !=NULL);

   delete [] matrix;



}
