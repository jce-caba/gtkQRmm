#include "QrUtils.hpp"
#include "QrProcesses.hpp"
#include <utility>

using namespace GtkQR;

QrMatrix::QrMatrix()
{
   matrix=nullptr;
   num_modules=0;
}

QrMatrix::~QrMatrix()
{
    destroy();
}

QrMatrix::QrMatrix(const QrMatrix &other)
{
   copy(other);
}

QrMatrix& QrMatrix::operator=(const QrMatrix &other)
{
  destroy();
  copy(other);
  return *this;
}

QrMatrix::QrMatrix(QrMatrix &&other)
{
   unsigned short aux = other.num_modules;
   std::swap(matrix,other.matrix);
   other.num_modules = num_modules;
   num_modules = aux;
}


QrMatrix& QrMatrix::operator=(QrMatrix &&other)
{
   unsigned short aux = other.num_modules;
   std::swap(matrix,other.matrix);
   other.num_modules = num_modules;
   num_modules = aux;

  return *this;
}


QrMatrix QrMatrix::GetQrMatrix(std::string &text ,QRDataContainer *data )
{
  QrMatrix qrmatrix;
  QrProcesses pr(data);

  qrmatrix.matrix = pr.calculateMatrix(text);

  if(qrmatrix.matrix != nullptr)
  {
     qrmatrix.num_modules =data->getnum_modules();
  }


  return qrmatrix;

}

void QrMatrix::destroy()
{

    if(matrix !=nullptr)
    {
        for(int i =0 ; i <= num_modules ; i++)
            delete [] matrix[i];

        delete [] matrix;
        matrix =nullptr;
        num_modules = 0;
    }

}

void QrMatrix::copy(const QrMatrix &other)
{
   num_modules=other.num_modules;

   if(other.matrix !=nullptr)
   {
       matrix  = new char *[num_modules+1 ];
       for(unsigned short i= 0; i < num_modules ; i++ )
       {
            matrix[i]  = new char [num_modules+1 ];
            for(unsigned short a= 0; a < num_modules ; a++ )
                        matrix[i][a] = other.matrix[i][a];

            matrix[i][num_modules] = '\0';
       }
       matrix[num_modules]=  nullptr;
   }


}

bool QrMatrix::getValue(unsigned short x ,unsigned short y)
{
  if(x<num_modules && y<num_modules)
             return matrix[x][y] == '1';
  else
             return false;
}

void QrMatrix::iterate(std::function<void(unsigned short,unsigned short,bool)> const& _function){

    if(matrix != nullptr)
    {
       for(unsigned short i= 0; i < num_modules ; i++ )
       {
           for(unsigned short a= 0; a < num_modules ; a++ )
           {
               _function(i,a,matrix[i][a] == '1');
           }
       }
    }

}


