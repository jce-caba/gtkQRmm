#include "8859_3_character_set.hpp"

 using namespace GtkQR;

int _8859_3_character_set::get_character(int unicode)
{
         if  ( unicode >= 0 && unicode <= 126)
                return unicode;
         else if  ( unicode == 160)
                return 160;
         else if  ( unicode == 173)
                return 173;
         else if  ( unicode == 294)
                return 161;
         else if  ( unicode == 728)
                return 162;
         else if  ( unicode == 163)
                return 163;
         else if  ( unicode == 164)
                return 164;
         else if  ( unicode == 292)
                return 166;
         else if  ( unicode == 167)
                return 167;
         else if  ( unicode == 168)
                return 168;
         else if  ( unicode == 304)
                return 169;
         else if  ( unicode == 350)
                return 170;
         else if  ( unicode == 286)
                return 171;
         else if  ( unicode == 308)
                return 172;
         else if  ( unicode == 379)
                return 175;
         else if  ( unicode == 176)
                return 176;
         else if  ( unicode == 295)
                return 177;
         else if  ( unicode >= 178 && unicode <= 181)
                return unicode;
         else if  ( unicode == 293)
                return 182;
         else if  ( unicode == 183)
                return 183;
         else if  ( unicode == 184)
                return 184;
         else if  ( unicode == 305)
                return 185;
         else if  ( unicode == 351)
                return 186;
         else if  ( unicode == 287)
                return 187;
         else if  ( unicode == 309)
                return 188;
         else if  ( unicode == 189)
                return 189;
         else if  ( unicode == 380)
                return 191;
         else if  ( unicode >= 209 && unicode <= 212)
                return unicode;
         else if  ( unicode == 288)
                return 213;
         else if  ( unicode == 214)
                return 214;
         else if  ( unicode == 215)
                return 215;
         else if  ( unicode == 284)
                return 216;
         else if  ( unicode >= 217 && unicode <= 220)
                return unicode;
         else if  ( unicode == 364)
                return 221;
         else if  ( unicode == 348)
                return 222;
         else if  ( unicode == 223)
                return 223;
         else if  ( unicode >= 224 && unicode <= 226)
                return unicode;
         else if  ( unicode == 228)
                return 228;
         else if  ( unicode == 267)
                return 229;
         else if  ( unicode == 265)
                return 230;
         else if  ( unicode >= 231 && unicode <= 239)
                return unicode;
         else if  ( unicode >= 241 && unicode <= 244)
                return unicode;
         else if  ( unicode == 289)
                return 245;
         else if  ( unicode >= 246 && unicode <= 247)
                return unicode;
         else if  ( unicode == 285)
                return 248;
         else if  ( unicode >= 249 && unicode <= 252)
                return unicode;
         else if  ( unicode == 365)
                return 253;
         else if  ( unicode == 349)
                return 254;
         else if  ( unicode == 729)
                return 255;
         else if  ( unicode >= 192 && unicode <= 194)
                return unicode;
         else if  ( unicode == 196)
                return 196;
         else if  ( unicode == 266)
                return 197;
         else if  ( unicode == 264)
                return 198;
         else if  ( unicode >= 199 && unicode <= 207)
                return unicode;


   return -1;
}
