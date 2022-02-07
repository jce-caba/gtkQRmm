#ifndef QRENCODE_HPP
#define QRENCODE_HPP
#include <string>
#include "QrConversions.hpp"

namespace GtkQR{

   class QrEncode
   {
     public:
        QrEncode();
        ~QrEncode();

        static  std::string encondeNumeric(std::string *);
        static  std::string encondeAlphaNumeric(std::string *);
        static  std::string encondeISO_8859_1(int *,int);
        static  std::string encondeKanji(int *,int);

     protected:

     private:

         static int  getAlphaNumericValue(char);
   };

}



#endif // QRENCODE_HPP
