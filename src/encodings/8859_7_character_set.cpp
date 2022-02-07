#include "8859_7_character_set.hpp"

using namespace GtkQR;

int _8859_7_character_set::get_character(int unicode)
{
    if  ( unicode >= 0 && unicode <= 126)
        return unicode;
    else if  ( unicode == 160)
                return 160;
    else if  ( unicode == 173)
                return 173;
    else if  ( unicode == 8216)
        return 161;
    else if  ( unicode == 8217)
        return 162;
    else if  ( unicode == 163)
        return 163;
    else if  ( unicode == 8364)
        return 164;
    else if  ( unicode == 8367)
        return 165;
    else if  ( unicode >= 166 && unicode <= 169)
        return unicode;
    else if  ( unicode == 890)
        return 170;
    else if  ( unicode == 171)
        return 171;
    else if  ( unicode == 172)
        return 172;
    else if  ( unicode == 8213)
        return 175;
    else if  ( unicode >= 176 && unicode <= 179)
        return unicode;
    else if  ( unicode >= 900 && unicode <= 902)
        return unicode-20;
    else if  ( unicode == 183)
        return 183;
    else if  ( unicode >= 904 && unicode <= 906)
        return unicode-20;
    else if  ( unicode == 187)
        return 187;
    else if  ( unicode == 908)
        return 188;
    else if  ( unicode == 189)
        return 189;
    else if  ( unicode >= 910 && unicode <= 929)
        return unicode-20;
    else if  ( unicode >= 931 && unicode <= 974)
        return unicode-20;

    return -1;
}

