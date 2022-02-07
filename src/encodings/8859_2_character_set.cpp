#include "8859_2_character_set.hpp"

 using namespace GtkQR;

int _8859_2_character_set::get_character(int unicode)
{
         if  ( unicode >=0 && unicode <=126)
                return unicode;
         else if  ( unicode == 160)
                return 160;
         else if  ( unicode == 173)
                return 173;
         else if  ( unicode == 260)
                return 161;
         else if  ( unicode == 728)
                return 162;
         else if  ( unicode == 321)
                return 163;
         else if  ( unicode == 164)
                return 164;
         else if  ( unicode == 317)
                return 165;
         else if  ( unicode == 346)
                return 166;
         else if  ( unicode == 167)
                return 167;
         else if  ( unicode == 168)
                return 168;
         else if  ( unicode == 352)
                return 169;
         else if  ( unicode == 350)
                return 170;
         else if  ( unicode == 356)
                return 171;
         else if  ( unicode == 377)
                return 172;
         else if  ( unicode == 381)
                return 174;
         else if  ( unicode == 379)
                return 175;
         else if  ( unicode == 176)
                return 176;
         else if  ( unicode == 261)
                return 177;
         else if  ( unicode == 731)
                return 178;
         else if  ( unicode == 322)
                return 179;
         else if  ( unicode == 180)
                return 180;
         else if  ( unicode == 318)
                return 181;
         else if  ( unicode == 347)
                return 182;
         else if  ( unicode == 711)
                return 183;
         else if  ( unicode == 184)
                return 184;
         else if  ( unicode == 353)
                return 185;
         else if  ( unicode == 351)
                return 186;
         else if  ( unicode == 357)
                return 187;
         else if  ( unicode == 378)
                return 188;
         else if  ( unicode == 733)
                return 189;
         else if  ( unicode == 382)
                return 190;
         else if  ( unicode == 380)
                return 191;
         else if  ( unicode == 340)
                return 192;
         else if  ( unicode == 193)
                return 193;
         else if  ( unicode == 194)
                return 194;
         else if  ( unicode == 258)
                return 195;
         else if  ( unicode == 196)
                return 196;
         else if  ( unicode == 313)
                return 197;
         else if  ( unicode == 262)
                return 198;
         else if  ( unicode == 199)
                return 199;
         else if  ( unicode == 268)
                return 200;
         else if  ( unicode == 201)
                return 201;
         else if  ( unicode == 280)
                return 202;
         else if  ( unicode == 203)
                return 203;
         else if  ( unicode == 282)
                return 204;
         else if  ( unicode == 205)
                return 205;
         else if  ( unicode == 206)
                return 206;
         else if  ( unicode == 270)
                return 207;
         else if  ( unicode == 272)
                return 208;
         else if  ( unicode == 323)
                return 209;
         else if  ( unicode == 327)
                return 210;
         else if  ( unicode == 211)
                return 211;
         else if  ( unicode == 212)
                return 212;
         else if  ( unicode == 336)
                return 213;
         else if  ( unicode == 214)
                return 214;
         else if  ( unicode == 215)
                return 215;
         else if  ( unicode == 344)
                return 216;
         else if  ( unicode == 366)
                return 217;
         else if  ( unicode == 218)
                return 218;
         else if  ( unicode == 368)
                return 219;
         else if  ( unicode == 220)
                return 220;
         else if  ( unicode == 221)
                return 221;
         else if  ( unicode == 354)
                return 222;
         else if  ( unicode == 223)
                return 223;
         else if  ( unicode == 341)
                return 224;
         else if  ( unicode == 225)
                return 225;
         else if  ( unicode == 226)
                return 226;
         else if  ( unicode == 259)
                return 227;
         else if  ( unicode == 228)
                return 228;
         else if  ( unicode == 314)
                return 229;
         else if  ( unicode == 263)
                return 230;
         else if  ( unicode == 231)
                return 231;
         else if  ( unicode == 269)
                return 232;
         else if  ( unicode == 233)
                return 233;
         else if  ( unicode == 281)
                return 234;
         else if  ( unicode == 235)
                return 235;
         else if  ( unicode == 283)
                return 236;
         else if  ( unicode == 237)
                return 237;
         else if  ( unicode == 238)
                return 238;
         else if  ( unicode == 271)
                return 239;
         else if  ( unicode == 273)
                return 240;
         else if  ( unicode == 324)
                return 241;
         else if  ( unicode == 328)
                return 242;
         else if  ( unicode == 243)
                return 243;
         else if  ( unicode == 244)
                return 244;
         else if  ( unicode == 337)
                return 245;
         else if  ( unicode == 246)
                return 246;
         else if  ( unicode == 247)
                return 247;
         else if  ( unicode == 345)
                return 248;
         else if  ( unicode == 367)
                return 249;
         else if  ( unicode == 250)
                return 250;
         else if  ( unicode == 369)
                return 251;
         else if  ( unicode == 252)
                return 252;
         else if  ( unicode == 253)
                return 253;
         else if  ( unicode == 355)
                return 254;
         else if  ( unicode == 729)
                return 255;


    return -1;
}
