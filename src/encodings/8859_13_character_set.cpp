#include "8859_13_character_set.hpp"

 using namespace GtkQR;

int _8859_13_character_set::get_character(int unicode)
{
         if  ( unicode >= 0 && unicode <= 126)
                return unicode;
         else if  ( unicode == 160)
                return 160;
         else if  ( unicode == 173)
                return 173;
         else if  ( unicode == 8221)
                return 161;
         else if  ( unicode >= 162 && unicode <= 164)
                return unicode;
         else if  ( unicode == 8222)
                return 165;
         else if  ( unicode == 166)
                return 166;
         else if  ( unicode == 167)
                return 167;
         else if  ( unicode == 216)
                return 168;
         else if  ( unicode == 169)
                return 169;
         else if  ( unicode == 342)
                return 170;
         else if  ( unicode == 171)
                return 171;
         else if  ( unicode == 172)
                return 172;
         else if  ( unicode == 174)
                return 174;
         else if  ( unicode == 198)
                return 175;
         else if  ( unicode >= 176 && unicode <= 179)
                return unicode;
         else if  ( unicode == 8220)
                return 180;
         else if  ( unicode >= 181 && unicode <= 183)
                return unicode;
         else if  ( unicode == 248)
                return 184;
         else if  ( unicode == 185)
                return 185;
         else if  ( unicode == 343)
                return 186;
         else if  ( unicode >= 187 && unicode <= 190)
                return unicode;
         else if  ( unicode == 230)
                return 191;
         else if  ( unicode == 260)
                return 192;
         else if  ( unicode == 302)
                return 193;
         else if  ( unicode == 256)
                return 194;
         else if  ( unicode == 262)
                return 195;
         else if  ( unicode == 196)
                return 196;
         else if  ( unicode == 197)
                return 197;
         else if  ( unicode == 280)
                return 198;
         else if  ( unicode == 274)
                return 199;
         else if  ( unicode == 268)
                return 200;
         else if  ( unicode == 201)
                return 201;
         else if  ( unicode == 377)
                return 202;
         else if  ( unicode == 278)
                return 203;
         else if  ( unicode == 290)
                return 204;
         else if  ( unicode == 310)
                return 205;
         else if  ( unicode == 298)
                return 206;
         else if  ( unicode == 315)
                return 207;
         else if  ( unicode == 352)
                return 208;
         else if  ( unicode == 323)
                return 209;
         else if  ( unicode == 325)
                return 210;
         else if  ( unicode == 211)
                return 211;
         else if  ( unicode == 332)
                return 212;
         else if  ( unicode >= 213 && unicode <= 215)
                return unicode;
         else if  ( unicode == 370)
                return 216;
         else if  ( unicode == 321)
                return 217;
         else if  ( unicode == 346)
                return 218;
         else if  ( unicode == 362)
                return 219;
         else if  ( unicode == 220)
                return 220;
         else if  ( unicode == 379)
                return 221;
         else if  ( unicode == 381)
                return 222;
         else if  ( unicode == 223)
                return 223;
         else if  ( unicode == 261)
                return 224;
         else if  ( unicode == 303)
                return 225;
         else if  ( unicode == 257)
                return 226;
         else if  ( unicode == 263)
                return 227;
         else if  ( unicode == 228)
                return 228;
         else if  ( unicode == 229)
                return 229;
         else if  ( unicode == 281)
                return 230;
         else if  ( unicode == 275)
                return 231;
         else if  ( unicode == 269)
                return 232;
         else if  ( unicode == 233)
                return 233;
         else if  ( unicode == 378)
                return 234;
         else if  ( unicode == 279)
                return 235;
         else if  ( unicode == 291)
                return 236;
         else if  ( unicode == 311)
                return 237;
         else if  ( unicode == 299)
                return 238;
         else if  ( unicode == 316)
                return 239;
         else if  ( unicode == 353)
                return 240;
         else if  ( unicode == 324)
                return 241;
         else if  ( unicode == 326)
                return 242;
         else if  ( unicode == 243)
                return 243;
         else if  ( unicode == 333)
                return 244;
         else if  ( unicode >= 245 && unicode <= 247)
                return unicode;
         else if  ( unicode == 371)
                return 248;
         else if  ( unicode == 322)
                return 249;
         else if  ( unicode == 347)
                return 250;
         else if  ( unicode == 363)
                return 251;
         else if  ( unicode == 252)
                return 252;
         else if  ( unicode == 380)
                return 253;
         else if  ( unicode == 382)
                return 254;
         else if  ( unicode == 8217)
                return 255;




  return -1;
}
