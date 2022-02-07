#ifndef QRCONVERSIONS_H_INCLUDED
#define QRCONVERSIONS_H_INCLUDED
#include <stdlib.h>
#include <string>
#include <math.h>


namespace GtkQR{

   class Conversion
   {
      public:
           Conversion() = delete;

           static std::string toBinary(int);
           static std::string fillzeros(unsigned int,std::string &);
           static std::string fillzerosafter(unsigned int,std::string &);
           static void most_significant_byte(std::string &,std::string &);
           static void least_significant_byte(std::string &,std::string &);
           static int toDecimal(std::string &);
           static int* toDecimalarray(int,char **,int);
           static void toBinary_n_bits(std::string &,int,int);
           static std::string number_to_char(int);
           static int  number_to_int(std::string &);

      private :

   };
}




#endif // QRCONVERSIONS_H_INCLUDED
