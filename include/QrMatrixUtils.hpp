#ifndef QRMATRIXUTILS_HPP
#define QRMATRIXUTILS_HPP
#include "QrDefinitions.hpp"

namespace GtkQR
{
   class QrMatrixUtils
   {
     public:
        QrMatrixUtils();
        ~QrMatrixUtils();

        static void sumMatrix(char **,const char **,QRDataContainer *);
        static char ** createMatrix(const char **,QRDataContainer *);
        static void copyMatrix(char **,const char **,QRDataContainer *);
        static void freeMatrix(char **);

     protected:

     private:

   };


}



#endif // QRMATRIXUTILS_HPP
