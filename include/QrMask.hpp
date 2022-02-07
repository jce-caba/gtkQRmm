#ifndef QRMASK_HPP
#define QRMASK_HPP
#include "QrDefinitions.hpp"
#include "QrMatrixUtils.hpp"
#include "QrcalculateMask.hpp"

namespace GtkQR
{
   class QrMask
   {
      public:
        QrMask();
        ~QrMask();

        void setParameters(const char **,const char **,QRDataContainer *);
        char ** getMaskMatrix();

    protected:

    private:

          char **mask;
          const char **matrix;
          const char **functions_matrix;
          QRDataContainer *data;

          char ** getMaskMatrix_micro_QR();
          char ** getMaskMatrix_QR();



          void setmask_0();
          void setmask_1();
          void setmask_2();
          void setmask_3();
          void setmask_4();
          void setmask_5();
          void setmask_6();
          void setmask_7();

    };


}



#endif // QRMASK_HPP
