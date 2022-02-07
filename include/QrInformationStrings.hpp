#ifndef QRINFORMATIONSTRINGS_HPP
#define QRINFORMATIONSTRINGS_HPP
#include "QrDefinitions.hpp"

namespace GtkQR{

   class QrInformationStrings
   {
      public:
        QrInformationStrings()=delete;
        ~QrInformationStrings() = delete;

        static const char * getVersionInformation(QRDataContainer *);
        static const char * getFormatInformation(QRDataContainer *);

      protected:

      private:
   };


}



#endif // QRINFORMATIONSTRINGS_HPP
