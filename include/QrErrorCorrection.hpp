#ifndef QRERRORCORRECTION_HPP
#define QRERRORCORRECTION_HPP
#include "QrDefinitions.hpp"

namespace GtkQR
{
    class QrErrorCorrection
    {
      public:
         QrErrorCorrection(QRDataContainer *);
         ~QrErrorCorrection();

         int getDataBits();
         int geterrorcorrection ();
         int getECCodewords ();
         int getNumberBlocks1 ();
         int getNumberDataBlocks1 ();
         int getNumberBlocks2 ();
         int getNumberDataBlocks2 ();

      protected:

      private:

          QRDataContainer *data;
          QRVersion version;
   };

}




#endif // QRERRORCORRECTION_HPP
