#include "8859_14_character_set.hpp"

using namespace GtkQR;

int _8859_14_character_set::get_character(int unicode)
{
         if  ( unicode >= 0 && unicode <= 126)
                return unicode;
         else if  ( unicode == 160)
                return 160;
         else if  ( unicode == 173)
                return 173;
         else if  ( unicode == 7682)
                return 161;
         else if  ( unicode == 7683)
                return 162;
         else if  ( unicode == 163)
                return 163;
         else if  ( unicode == 266)
                return 164;
         else if  ( unicode == 267)
                return 165;
         else if  ( unicode == 7690)
                return 166;
         else if  ( unicode == 167)
                return 167;
         else if  ( unicode == 7808)
                return 168;
         else if  ( unicode == 169)
                return 169;
         else if  ( unicode == 7810)
                return 170;
         else if  ( unicode == 7691)
                return 171;
         else if  ( unicode == 7922)
                return 172;
         else if  ( unicode == 174)
                return 174;
         else if  ( unicode == 376)
                return 175;
         else if  ( unicode == 7710)
                return 176;
         else if  ( unicode == 7711)
                return 177;
         else if  ( unicode == 288)
                return 178;
         else if  ( unicode == 289)
                return 179;
         else if  ( unicode == 7744)
                return 180;
         else if  ( unicode == 7745)
                return 181;
         else if  ( unicode == 182)
                return 182;
         else if  ( unicode == 7766)
                return 183;
         else if  ( unicode == 7809)
                return 184;
         else if  ( unicode == 7767)
                return 185;
         else if  ( unicode == 7811)
                return 186;
         else if  ( unicode == 7776)
                return 187;
         else if  ( unicode == 7923)
                return 188;
         else if  ( unicode == 7812)
                return 189;
         else if  ( unicode == 7813)
                return 190;
         else if  ( unicode == 7777)
                return 191;
         else if  ( unicode >= 192 && unicode <= 207)
                return unicode;
         else if  ( unicode == 372)
                return 208;
         else if  ( unicode >= 209 && unicode <= 214)
                return unicode;
         else if  ( unicode == 7786)
                return 215;
         else if  ( unicode >= 216 && unicode <= 221)
                return unicode;
         else if  ( unicode == 374)
                return 222;
         else if  ( unicode >= 223 && unicode <= 239)
                return unicode;
         else if  ( unicode == 373)
                return 240;
         else if  ( unicode >= 241 && unicode <= 246)
                return unicode;
         else if  ( unicode == 7787)
                return 247;
         else if  ( unicode >= 248 && unicode <= 253)
                return unicode;
         else if  ( unicode == 375)
                return 254;
         else if  ( unicode == 255)
                return 255;
  return -1;
}
