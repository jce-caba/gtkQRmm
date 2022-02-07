#ifndef QRREEDSOLOMON_HPP
#define QRREEDSOLOMON_HPP
#include "QrDefinitions.hpp"
#include "QrErrorCorrection.hpp"
#include "QrGeneratorPolynomial.hpp"
#include "QrConversions.hpp"
#include "Qrlog.hpp"

namespace GtkQR
{

   class QrReedSolomon
  {
       public:
        QrReedSolomon(char **,QRDataContainer *,QrErrorCorrection *);
        ~QrReedSolomon();


        void   setBlocks(char **);
        int *  getErrorCorrectionCodewords();
        int    getCountarray();

       protected:

       private:

           int countarray;
           QRDataContainer *data;
           char **allblocks;
           QrErrorCorrection *error_correction;

           int *  copyarray (int *,int);
           void   multiply(int,int,int *,int *);
           int *  discardfirstterm (int *,int);
           void   Xor(int,int *,int *);
   };

}



#endif // QRREEDSOLOMON_HPP
