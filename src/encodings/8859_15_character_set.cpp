#include "8859_15_character_set.hpp"

using namespace GtkQR;


int _8859_15_character_set::get_character(int unicode)
{
    if  ( unicode >= 0 && unicode <= 126)
        return unicode;
    else if  ( unicode >= 161 && unicode <= 163)
        return unicode;
    else if  ( unicode == 8364)
        return 164;
    else if  ( unicode == 165)
        return 165;
    else if  ( unicode == 352)
        return 166;
    else if  ( unicode == 167)
        return 167;
    else if  ( unicode == 353)
        return 168;
    else if  ( unicode >= 169 && unicode <= 172)
        return unicode;
    else if  ( unicode >= 174 && unicode <= 179)
        return unicode;
    else if  ( unicode == 381)
        return 180;
    else if  ( unicode >= 181 && unicode <= 187)
        return unicode;
    else if  ( unicode == 338)
        return 188;
    else if  ( unicode == 339)
        return 189;
    else if  ( unicode == 376)
        return 190;
    else if  ( unicode >= 191 && unicode <= 255)
        return unicode;
    else if  ( unicode == 382)
        return 184;

    return -1;
}
