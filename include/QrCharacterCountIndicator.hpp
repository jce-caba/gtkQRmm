#ifndef QRCHARACTERCOUNTINDICATOR_HPP
#define QRCHARACTERCOUNTINDICATOR_HPP
#include "QrDefinitions.hpp"

namespace GtkQR
{

   class QrCharacterCountIndicator
   {
      public:
        QrCharacterCountIndicator() = delete;
        ~QrCharacterCountIndicator() = delete;

       static int getCharacterCountIndicator(QRDataContainer *);

      protected:

      private:
   };

}



#endif // QRCHARACTERCOUNTINDICATOR_HPP
