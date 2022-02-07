#include "QrMask.hpp"
#include "iostream"

using namespace GtkQR;

QrMask::QrMask()
{
    matrix=nullptr;
    functions_matrix = nullptr;
    data = nullptr;
}

QrMask::~QrMask()
{
    //dtor
}

void QrMask::setParameters( const char **_m,const char **_f_m,QRDataContainer *_d)
{
    matrix=_m;
    functions_matrix = _f_m;
    data =_d;
}


  char ** QrMask::getMaskMatrix()
  {
     if(data->isMicro )
         return  getMaskMatrix_micro_QR();
     else
         return getMaskMatrix_QR();


    return 0;
  }


  char ** QrMask::getMaskMatrix_micro_QR()
  {
    QrcalculateMask calculate(data);

   long points[4];
   long max;
   mask = QrMatrixUtils::createMatrix(matrix,data);


   setmask_1();
   points[0] = calculate.getpointMask_micro_QR(const_cast<const char **>(mask));
   max=points[0];



   setmask_4();
   points[1] = calculate.getpointMask_micro_QR(const_cast<const char **>(mask));

   if(max < points[1])
              max = points[1];



   setmask_6();
   points[2] = calculate.getpointMask_micro_QR(const_cast<const char **>(mask));

   if(max < points[2])
              max = points[2];


   setmask_7();
   points[3] = calculate.getpointMask_micro_QR(const_cast<const char **>(mask));

    if(max < points[3])
        max = points[3];

    for(int a=0; a<4; a++){
        if(points[a] == max)
        {
            data->mask = a;
            a=4;
        }
    }

  switch(data->mask)
  {
        case 0:
             setmask_1();
             QrMatrixUtils::sumMatrix(mask,functions_matrix,data);
             data->mask=1;
        break;
        case 1:
             setmask_4();
             QrMatrixUtils::sumMatrix(mask,functions_matrix,data);
             data->mask=4;
        break;
        case 2:
             setmask_6();
             QrMatrixUtils::sumMatrix(mask,functions_matrix,data);
             data->mask=6;
        break;
        case 3:
             setmask_7();
             QrMatrixUtils::sumMatrix(mask,functions_matrix,data);
             data->mask=7;
        break;
        default:

        break;

  }


    return mask;
  }

char ** QrMask::getMaskMatrix_QR()
{
   QrcalculateMask calculate(data);

   long points[8];
   long min;
   mask = QrMatrixUtils::createMatrix(matrix,data);


   setmask_0();
   QrMatrixUtils::sumMatrix(mask,functions_matrix,data);
   points[0] = calculate.getpointMask(const_cast<const char **>(mask));

   min=points[0];


   setmask_1();
   QrMatrixUtils::sumMatrix(mask,functions_matrix,data);
   points[1] = calculate.getpointMask(const_cast<const char **>(mask));


   if(min > points[1])
              min = points[1];



   setmask_2();
   QrMatrixUtils::sumMatrix(mask,functions_matrix,data);
   points[2] = calculate.getpointMask(const_cast<const char **>(mask));


   if(min > points[2])
              min = points[2];



   setmask_3();
   QrMatrixUtils::sumMatrix(mask,functions_matrix,data);
   points[3] = calculate.getpointMask(const_cast<const char **>(mask));


   if(min > points[3])
              min = points[3];



   setmask_4();
   QrMatrixUtils::sumMatrix(mask,functions_matrix,data);
   points[4] = calculate.getpointMask(const_cast<const char **>(mask));


   if(min > points[4])
              min = points[4];




   setmask_5();
   QrMatrixUtils::sumMatrix(mask,functions_matrix,data);
   points[5] = calculate.getpointMask(const_cast<const char **>(mask));


   if(min > points[5])
              min = points[5];



   setmask_6();
   QrMatrixUtils::sumMatrix(mask,functions_matrix,data);
   points[6] = calculate.getpointMask(const_cast<const char **>(mask));


   if(min > points[6])
              min = points[6];



   setmask_7();
   QrMatrixUtils::sumMatrix(mask,functions_matrix,data);
   points[7] = calculate.getpointMask(const_cast<const char **>(mask));

   if(min > points[7])
              min = points[7];


  for(int a=0;a<8;a++)
  {
      if(points[a] == min)
      {
         data->mask = a;
         a=8;
      }
  }



  switch(data->mask)
  {
        case 0:
             setmask_0();
             QrMatrixUtils::sumMatrix(mask,functions_matrix,data);
        break;
        case 1:
             setmask_1();
             QrMatrixUtils::sumMatrix(mask,functions_matrix,data);
        break;
        case 2:
             setmask_2();
             QrMatrixUtils::sumMatrix(mask,functions_matrix,data);
        break;
        case 3:
             setmask_3();
             QrMatrixUtils::sumMatrix(mask,functions_matrix,data);
        break;
        case 4:
             setmask_4();
             QrMatrixUtils::sumMatrix(mask,functions_matrix,data);
        break;
        case 5:
             setmask_5();
             QrMatrixUtils::sumMatrix(mask,functions_matrix,data);
        break;
        case 6:
             setmask_6();
             QrMatrixUtils::sumMatrix(mask,functions_matrix,data);
        break;
        default:

        break;

  }


   return mask;
}

void QrMask::setmask_0()
{
   for(int i =0 ; i < data->num_modules ; i++)
   {

      for(int a =0 ; a < data->num_modules ; a++)
      {
          if((i+a)  % 2 == 0)
          {
             if (matrix[i][a] == '0')
                        mask[i][a] = '1';
             else if (matrix[i][a] == '1')
                         mask[i][a] = '0';
             else
                      mask[i][a] = matrix[i][a];
          }
          else
                      mask[i][a] = matrix[i][a];
      }
   }
}

void QrMask::setmask_1()
{
   for(int i =0 ; i < data->num_modules ; i++)
   {

      for(int a =0 ; a < data->num_modules ; a++)
      {
          if(a % 2 == 0)
          {
             if (matrix[i][a] == '0')
                        mask[i][a] = '1';
             else if (matrix[i][a] == '1')
                         mask[i][a] = '0';
             else
                      mask[i][a] = matrix[i][a];

          }
          else
                      mask[i][a] = matrix[i][a];
      }
   }
}

void QrMask::setmask_2()
{
   for(int i =0 ; i < data->num_modules ; i++)
   {

      for(int a =0 ; a < data->num_modules ; a++)
      {
          if(i % 3 == 0)
          {
             if (matrix[i][a] == '0')
                        mask[i][a] = '1';
             else if (matrix[i][a] == '1')
                         mask[i][a] = '0';
             else
                      mask[i][a] = matrix[i][a];

          }
          else
                      mask[i][a] = matrix[i][a];
      }
   }
}


void QrMask::setmask_3()
{
   for(int i =0 ; i < data->num_modules ; i++)
   {

      for(int a =0 ; a < data->num_modules ; a++)
      {
          if((i+a)  % 3 == 0)
          {
             if (matrix[i][a] == '0')
                        mask[i][a] = '1';
             else if (matrix[i][a] == '1')
                         mask[i][a] = '0';
             else
                      mask[i][a] = matrix[i][a];

          }
          else
                      mask[i][a] = matrix[i][a];
      }
   }
}

void QrMask::setmask_4()
{
   int aux;
   int aux2;

   for(int i =0 ; i < data->num_modules ; i++)
   {

      for(int a =0 ; a < data->num_modules ; a++)
      {
          aux = a /2 ;
          aux2 = i / 3;


          if((aux+aux2)  % 2 == 0)
          {
             if (matrix[i][a] == '0')
                        mask[i][a] = '1';
             else if (matrix[i][a] == '1')
                         mask[i][a] = '0';
             else
                      mask[i][a] = matrix[i][a];

          }
          else
                      mask[i][a] = matrix[i][a];
      }
   }
}

void QrMask::setmask_5()
{
   long aux;
   int  aux2;

   for(int i =0 ; i < data->num_modules ; i++)
   {
      for(int a =0 ; a < data->num_modules ; a++)
      {
          aux = i * a  ;
          aux2 = aux % 2;
          if(aux2 == 0)
          {
             aux2 = aux % 3;
             if(aux2 == 0)
             {
               if (matrix[i][a] == '0')
                        mask[i][a] = '1';
               else if (matrix[i][a] == '1')
                         mask[i][a] = '0';
               else
                      mask[i][a] = matrix[i][a];
             }
             else
                mask[i][a] = matrix[i][a];


          }
          else
              mask[i][a] = matrix[i][a];

      }
   }
}

void QrMask::setmask_6()
{
   long aux;
   int aux2;
   int aux3;

   for(int i =0 ; i < data->num_modules ; i++)
   {

      for(int a =0 ; a < data->num_modules ; a++)
      {
          aux = a * i ;
          aux2 = aux % 2;
          aux3 = aux % 3;

          if((aux3+aux2)  % 2 == 0)
          {
             if (matrix[i][a] == '0')
                        mask[i][a] = '1';
             else if (matrix[i][a] == '1')
                         mask[i][a] = '0';
             else
                     mask[i][a] = matrix[i][a];

          }
          else
                     mask[i][a] = matrix[i][a];
      }
   }
}

void QrMask::setmask_7()
{
   long aux;
   int aux2;
   int aux3;

   for(int i =0 ; i < data->num_modules ; i++)
   {

      for(int a =0 ; a < data->num_modules ; a++)
      {
          aux = a + i ;
          aux2 = aux % 2;
          aux = a * i ;
          aux3 = aux % 3;

          if((aux3+aux2)  % 2 == 0) {

             if (matrix[i][a] == '0')
                        mask[i][a] = '1';
             else if (matrix[i][a] == '1')
                         mask[i][a] = '0';
             else
                    mask[i][a] = matrix[i][a];

          }
          else
                   mask[i][a] = matrix[i][a];


      }
   }
}

