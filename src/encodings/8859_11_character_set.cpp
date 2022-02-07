#include "8859_11_character_set.hpp"

using namespace GtkQR;

int _8859_11_character_set::get_character(int unicode)
{
    if  ( unicode >= 0 && unicode <= 126)
        return unicode;
    else if  ( unicode == 160)
        return 160;
    else if  ( unicode >= 3585 && unicode <= 3642)
        return unicode -3424;
    else if  ( unicode >= 3647 && unicode <= 3675)
        return unicode -3425;



    return -1;
}
