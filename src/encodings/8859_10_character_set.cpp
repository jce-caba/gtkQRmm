#include "8859_10_character_set.hpp"

 using namespace GtkQR;


int _8859_10_character_set::get_character(int unicode)
{
         if  ( unicode >= 0 && unicode <= 126)
                return unicode;
         else if  ( unicode == 160)
                return 160;
         else if  ( unicode == 173)
                return 173;
         else if  ( unicode == 260)
                return 161;
         else if  ( unicode == 274)
                return 162;
         else if  ( unicode == 290)
                return 163;
         else if  ( unicode == 298)
                return 164;
         else if  ( unicode == 296)
                return 165;
         else if  ( unicode == 310)
                return 166;
         else if  ( unicode == 167)
                return 167;
         else if  ( unicode == 315)
                return 168;
         else if  ( unicode == 272)
                return 169;
         else if  ( unicode == 352)
                return 170;
         else if  ( unicode == 358)
                return 171;
         else if  ( unicode == 381)
                return 172;
         else if  ( unicode == 362)
                return 174;
         else if  ( unicode == 330)
                return 175;
         else if  ( unicode == 176)
                return 176;
         else if  ( unicode == 261)
                return 177;
         else if  ( unicode == 275)
                return 178;
         else if  ( unicode == 291)
                return 179;
         else if  ( unicode == 299)
                return 180;
         else if  ( unicode == 297)
                return 181;
         else if  ( unicode == 311)
                return 182;
         else if  ( unicode == 183)
                return 183;
         else if  ( unicode == 316)
                return 184;
         else if  ( unicode == 273)
                return 185;
         else if  ( unicode == 353)
                return 186;
         else if  ( unicode == 359)
                return 187;
         else if  ( unicode == 382)
                return 188;
         else if  ( unicode == 8213)
                return 189;
         else if  ( unicode == 363)
                return 190;
         else if  ( unicode == 331)
                return 191;
         else if  ( unicode == 256)
                return 192;
         else if  ( unicode >= 193 && unicode <= 198)
                return unicode;
         else if  ( unicode == 302)
                return 199;
         else if  ( unicode == 268)
                return 200;
         else if  ( unicode == 201)
                return 201;
         else if  ( unicode == 280)
                return 202;
         else if  ( unicode == 203)
                return 203;
         else if  ( unicode == 278)
                return 204;
         else if  ( unicode >= 205 && unicode <= 208)
                return unicode;
         else if  ( unicode == 325)
                return 209;
         else if  ( unicode == 332)
                return 210;
          else if  ( unicode >= 211 && unicode <= 214)
                return unicode;
         else if  ( unicode == 360)
                return 215;
         else if  ( unicode == 216)
                return 216;
         else if  ( unicode == 370)
                return 217;
         else if  ( unicode >= 218 && unicode <= 223)
                return unicode;
         else if  ( unicode == 257)
                return 224;
         else if  ( unicode >= 225 && unicode <= 230)
                return unicode;
         else if  ( unicode == 303)
                return 231;
         else if  ( unicode == 269)
                return 232;
         else if  ( unicode == 233)
                return 233;
         else if  ( unicode == 281)
                return 234;
         else if  ( unicode == 235)
                return 235;
         else if  ( unicode == 279)
                return 236;
         else if  ( unicode >= 237 && unicode <= 240)
                return unicode;
         else if  ( unicode == 326)
                return 241;
         else if  ( unicode == 333)
                return 242;
         else if  ( unicode >= 243 && unicode <= 246)
                return unicode;
         else if  ( unicode == 361)
                return 247;
         else if  ( unicode == 248)
                return 248;
         else if  ( unicode == 371)
                return 249;
         else if  ( unicode >= 250 && unicode <= 254)
                return unicode;
         else if  ( unicode == 312)
                return 255;


       return -1;
}
