#include "8859_9_character_set.hpp"

using namespace GtkQR;

int _8859_9_character_set::get_character(int unicode)
{
         if  ( unicode >= 0 && unicode <= 126)
                return unicode;
         else  if  ( unicode >= 160 && unicode <= 220)
                return unicode;
         else if  ( unicode == 304)
                return 221;
         else if  ( unicode == 350)
                return 222;
         else  if  ( unicode >= 223 && unicode <= 239)
                return unicode;
         else if  ( unicode == 287)
                return 240;
         else  if  ( unicode >= 241 && unicode <= 252)
                return unicode;
         else if  ( unicode == 305)
                return 253;
         else if  ( unicode == 351)
                return 254;
         else if  ( unicode == 255)
                return 255;
         else if  ( unicode == 286)
                return 208;


    return -1;
}
