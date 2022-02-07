#include "Qrremainderbits.hpp"

 using namespace GtkQR;

int Qrremainderbits::getremainderbits(int version)
{


   if (version >= 2 && version <= 6)
                              return 7;
   else if (version >= 14 && version <= 20)
                              return 3;
   else if (version >= 21 && version <= 27)
                              return 4;
   else if (version >= 28 && version <= 34)
                              return 3;

  return 0;
}
