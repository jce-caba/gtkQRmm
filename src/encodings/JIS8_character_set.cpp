#include "JIS8_character_set.hpp"

using namespace GtkQR;

int JIS8_character_set::get_character(int unicode)
{

         if  ( unicode >= 0 && unicode <= 125)
                return unicode;
         else if  ( unicode == 8254)
                return 126;
         else if  ( unicode == 9249)
                return 127;
         else if  ( unicode == 78)
                return 160;
         else if  ( unicode == 65378)
                return 161;
         else if  ( unicode == 65379)
                return 162;
         else if  ( unicode == 65380)
                return 163;
         else if  ( unicode == 65381)
                return 164;
         else if  ( unicode == 65382)
                return 165;
         else if  ( unicode == 65383)
                return 166;
         else if  ( unicode == 65384)
                return 167;
         else if  ( unicode == 65385)
                return 168;
         else if  ( unicode == 65386)
                return 169;
         else if  ( unicode == 65387)
                return 170;
         else if  ( unicode == 65388)
                return 171;
         else if  ( unicode == 65389)
                return 172;
         else if  ( unicode == 65390)
                return 173;
         else if  ( unicode == 65391)
                return 174;
         else if  ( unicode == 65391)
                return 175;
         else if  ( unicode == 65392)
                return 176;
         else if  ( unicode == 65393)
                return 177;
         else if  ( unicode == 65394)
                return 178;
         else if  ( unicode == 65395)
                return 179;
         else if  ( unicode == 65396)
                return 180;
         else if  ( unicode == 65397)
                return 181;
         else if  ( unicode == 65398)
                return 182;
         else if  ( unicode == 65399)
                return 183;
         else if  ( unicode == 65400)
                return 184;
         else if  ( unicode == 65401)
                return 185;
         else if  ( unicode == 65402)
                return 186;
         else if  ( unicode == 65403)
                return 187;
         else if  ( unicode == 65404)
                return 188;
         else if  ( unicode == 65405)
                return 189;
         else if  ( unicode == 65406)
                return 190;
         else if  ( unicode == 65407)
                return 191;
         else if  ( unicode == 65408)
                return 192;
         else if  ( unicode == 65409)
                return 193;
         else if  ( unicode == 65410)
                return 194;
         else if  ( unicode == 65411)
                return 195;
         else if  ( unicode == 65412)
                return 196;
         else if  ( unicode == 65413)
                return 197;
         else if  ( unicode == 65414)
                return 198;
         else if  ( unicode == 65415)
                return 199;
         else if  ( unicode == 65416)
                return 200;
         else if  ( unicode == 65417)
                return 201;
         else if  ( unicode == 65418)
                return 202;
         else if  ( unicode == 65419)
                return 203;
         else if  ( unicode == 65420)
                return 204;
         else if  ( unicode == 65421)
                return 205;
         else if  ( unicode == 65422)
                return 206;
         else if  ( unicode == 65423)
                return 207;
         else if  ( unicode == 65424)
                return 208;
         else if  ( unicode == 65425)
                return 209;
         else if  ( unicode == 65426)
                return 210;
         else if  ( unicode == 65427)
                return 211;
         else if  ( unicode == 65428)
                return 212;
         else if  ( unicode == 65429)
                return 213;
         else if  ( unicode == 65430)
                return 214;
         else if  ( unicode == 65431)
                return 215;
         else if  ( unicode == 65432)
                return 216;
         else if  ( unicode == 65433)
                return 217;
         else if  ( unicode == 65434)
                return 218;
         else if  ( unicode == 65435)
                return 219;
         else if  ( unicode == 65436)
                return 220;
         else if  ( unicode == 65437)
                return 221;
         else if  ( unicode == 65438)
                return 222;
         else if  ( unicode == 65439)
                return 223;
         else if  ( unicode == 165)
                return 92;
         else if  ( unicode == 65377)
                return 161;

    return -1;
}
