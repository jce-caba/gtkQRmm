#ifndef QRCALCULATEMASK_HPP
#define QRCALCULATEMASK_HPP
#include "QrDefinitions.hpp"

namespace GtkQR
{
   class QrcalculateMask
   {
      public:
        QrcalculateMask(QRDataContainer *);
        ~QrcalculateMask();

        long getpointMask_micro_QR(const char **);
        long getpointMask(const char **);

      protected:

      private:

         const char **_matrix;
         QRDataContainer *data;
         int num_modules;


         long getCondition3();
         int  getCondition4();
         long getCondition2();
         long getCondition1();


   };


}



#endif // QRCALCULATEMASK_HPP
