#include "8859_5_character_set.hpp"

 using namespace GtkQR;

int _8859_5_character_set::get_character(int unicode)
{
         if  ( unicode >= 0 && unicode <= 126)
                return unicode;
         else if  ( unicode == 160)
                return 160;
         else if  ( unicode == 173)
                return 173;
         else if  ( unicode >= 1025 && unicode <= 1036)
                return unicode - 864;
         else if  ( unicode >= 1038 && unicode <= 1103)
                return unicode - 864;
         else if  ( unicode == 8470)
                return 240;
         else if  ( unicode >= 1105 && unicode <= 1116)
                return unicode - 864;
         else if  ( unicode == 167)
                return 253;
         else if  ( unicode == 1118)
                return 254;
         else if  ( unicode == 1119)
                return 255;

    return -1;
}
