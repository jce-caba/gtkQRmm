#include "8859_8_character_set.hpp"

using namespace GtkQR;

int _8859_8_character_set::get_character(int unicode)
{
         if  ( unicode >= 0 && unicode <= 126)
                return unicode;
         else if  ( unicode == 160)
                return 160;
         else if  ( unicode >= 162 && unicode <= 169)
                return unicode;
         else if  ( unicode == 215)
                return 170;
         else if  ( unicode >= 171 && unicode <= 185)
                return unicode;
         else if  ( unicode == 247)
                return 186;
         else if  ( unicode >= 187 && unicode <= 190)
                return unicode;
         else if  ( unicode == 78)
                return 191;
         else if  ( unicode >= 1488 && unicode <= 1514)
                return unicode - 1264;
         else if  ( unicode == 8215)
                return 223;

    return -1;
}
