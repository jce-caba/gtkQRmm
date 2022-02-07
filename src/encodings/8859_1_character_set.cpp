#include "8859_1_character_set.hpp"

using namespace GtkQR;

int _8859_1_character_set::get_character(int unicode)
{
     if( unicode > 0 && unicode <= 127)
                          return unicode;
   else if( unicode > 161 && unicode <= 255)
                          return unicode;

    return -1;
}
