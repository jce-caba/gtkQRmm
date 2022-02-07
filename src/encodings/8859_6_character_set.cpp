#include "8859_6_character_set.hpp"

using namespace GtkQR;

int _8859_6_character_set::get_character(int unicode)
{
         if  ( unicode >= 0 && unicode <= 126)
                return unicode;
         else if  ( unicode == 160)
                return 160;
         else if  ( unicode == 173)
                return 173;
         else if  ( unicode >= 1632 && unicode <= 1641)
                return unicode - 1584;
         else if  ( unicode >= 1569 && unicode <= 1594)
                return unicode - 1376;
         else if  ( unicode >= 1600 && unicode <= 1618)
                return unicode - 1376;
         else if  ( unicode == 164 )
                return unicode ;
         else if  ( unicode == 1548 )
                return 172 ;
         else if  ( unicode == 1563 )
                return 187 ;
         else if  ( unicode == 1567 )
                return 191 ;





    return -1;
}
