#ifndef QRMATRIXFUNCTION_HPP
#define QRMATRIXFUNCTION_HPP
#include <string>
#include "QrDefinitions.hpp"

namespace GtkQR
{
   class QrMatrixFunction
   {
      public:
        QrMatrixFunction() = delete;
        ~QrMatrixFunction() = delete;

        static char ** getMatrixFunction(QRDataContainer *);
        static void    setMatrixFunctionFormat(char **,QRDataContainer *,std::string &);
        static void    setMatrixFunctionVersion(char **,QRDataContainer *,std::string &);

      protected:

      private:

       static char ** getMatrixFunction_micro_QR(QRDataContainer *);
       static char ** getMatrixFunction_QR(QRDataContainer *);
       static void    setMatrixFunctionFormat_micro_QR(char **,QRDataContainer *,std::string &);
       static void    setMatrixFunctionFormat_QR(char **,QRDataContainer *,std::string &);


   };

}


#endif // QRMATRIXFUNCTION_HPP
