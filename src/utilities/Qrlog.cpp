#include "Qrlog.hpp"

 using namespace GtkQR;

int Qrlog::getLog(int exp)
{
    if  ( exp <= 120 )
    {
        if  ( exp <= 12 )
        {
            if  ( exp == 1 )
                return 0;
            else if  ( exp == 2 )
                return 1;
            else if  ( exp == 3 )
                return 25;
            else if  ( exp == 4 )
                return 2;
            else if  ( exp == 5 )
                return 50;
            else if  ( exp == 6 )
                return 26;
            else if  ( exp == 7 )
                return 198;
            else if  ( exp == 8 )
                return 3;
            else if  ( exp == 9 )
                return 223;
            else if  ( exp == 10 )
                return 51;
            else if  ( exp == 11 )
                return 238;
            else if  ( exp == 12 )
                return 27;
        }
        else if  ( exp <= 24 )
        {
            if  ( exp == 13 )
                return 104;
            else if  ( exp == 14 )
                return 199;
            else if  ( exp == 15 )
                return 75;
            else if  ( exp == 16 )
                return 4;
            else if  ( exp == 17 )
                return 100;
            else if  ( exp == 18 )
                return 224;
            else if  ( exp == 19 )
                return 14;
            else if  ( exp == 20 )
                return 52;
            else if  ( exp == 21 )
                return 141;
            else if  ( exp == 22 )
                return 239;
            else if  ( exp == 23 )
                return 129;
            else if  ( exp == 24 )
                return 28;
        }
        else if  ( exp <= 36 )
        {
            if  ( exp == 25 )
                return 193;
            else if  ( exp == 26 )
                return 105;
            else if  ( exp == 27 )
                return 248;
            else if  ( exp == 28 )
                return 200;
            else if  ( exp == 29 )
                return 8;
            else if  ( exp == 30 )
                return 76;
            else if  ( exp == 31 )
                return 113;
            else if  ( exp == 32 )
                return 5;
            else if  ( exp == 33 )
                return 138;
            else if  ( exp == 34 )
                return 101;
            else if  ( exp == 35 )
                return 47;
            else if  ( exp == 36 )
                return 225;
        }
        else if  ( exp <= 48 )
        {
            if  ( exp == 37 )
                return 36;
            else if  ( exp == 38 )
                return 15;
            else if  ( exp == 39 )
                return 33;
            else if  ( exp == 40 )
                return 53;
            else if  ( exp == 41 )
                return 147;
            else if  ( exp == 42 )
                return 142;
            else if  ( exp == 43 )
                return 218;
            else if  ( exp == 44 )
                return 240;
            else if  ( exp == 45 )
                return 18;
            else if  ( exp == 46 )
                return 130;
            else if  ( exp == 47 )
                return 69;
            else if  ( exp == 48 )
                return 29;
        }
        else if  ( exp <= 60 )
        {
            if  ( exp == 49 )
                return 181;
            else if  ( exp == 50 )
                return 194;
            else if  ( exp == 51 )
                return 125;
            else if  ( exp == 52 )
                return 106;
            else if  ( exp == 53 )
                return 39;
            else if  ( exp == 54 )
                return 249;
            else if  ( exp == 55 )
                return 185;
            else if  ( exp == 56 )
                return 201;
            else if  ( exp == 57 )
                return 154;
            else if  ( exp == 58 )
                return 9;
            else if  ( exp == 59 )
                return 120;
            else if  ( exp == 60 )
                return 77;
        }
        else if  ( exp <= 72 )
        {
            if  ( exp == 61 )
                return 228;
            else if  ( exp == 62 )
                return 114;
            else if  ( exp == 63 )
                return 166;
            else if  ( exp == 64 )
                return 6;
            else if  ( exp == 65 )
                return 191;
            else if  ( exp == 66 )
                return 139;
            else if  ( exp == 67 )
                return 98;
            else if  ( exp == 68 )
                return 102;
            else if  ( exp == 69 )
                return 221;
            else if  ( exp == 70 )
                return 48;
            else if  ( exp == 71 )
                return 253;
            else if  ( exp == 72 )
                return 226;
        }
        else if  ( exp <= 84 )
        {
            if  ( exp == 73 )
                return 152;
            else if  ( exp == 74 )
                return 37;
            else if  ( exp == 75 )
                return 179;
            else if  ( exp == 76 )
                return 16;
            else if  ( exp == 77 )
                return 145;
            else if  ( exp == 78 )
                return 34;
            else if  ( exp == 79 )
                return 136;
            else if  ( exp == 80 )
                return 54;
            else if  ( exp == 81 )
                return 208;
            else if  ( exp == 82 )
                return 148;
            else if  ( exp == 83 )
                return 206;
            else if  ( exp == 84 )
                return 143;
        }
        else if  ( exp <= 96 )
        {
            if  ( exp == 85 )
                return 150;
            else if  ( exp == 86 )
                return 219;
            else if  ( exp == 87 )
                return 189;
            else if  ( exp == 88 )
                return 241;
            else if  ( exp == 89 )
                return 210;
            else if  ( exp == 90 )
                return 19;
            else if  ( exp == 91 )
                return 92;
            else if  ( exp == 92 )
                return 131;
            else if  ( exp == 93 )
                return 56;
            else if  ( exp == 94 )
                return 70;
            else if  ( exp == 95 )
                return 64;
            else if  ( exp == 96 )
                return 30;
        }
        else if  ( exp <= 108 )
        {
            if  ( exp == 97 )
                return 66;
            else if  ( exp == 98 )
                return 182;
            else if  ( exp == 99 )
                return 163;
            else if  ( exp == 100 )
                return 195;
            else if  ( exp == 101 )
                return 72;
            else if  ( exp == 102 )
                return 126;
            else if  ( exp == 103 )
                return 110;
            else if  ( exp == 104 )
                return 107;
            else if  ( exp == 105 )
                return 58;
            else if  ( exp == 106 )
                return 40;
            else if  ( exp == 107 )
                return 84;
            else if  ( exp == 108 )
                return 250;
        }
        else if  ( exp <= 120 )
        {
            if  ( exp == 109 )
                return 133;
            else if  ( exp == 110 )
                return 186;
            else if  ( exp == 111 )
                return 61;
            else if  ( exp == 112 )
                return 202;
            else if  ( exp == 113 )
                return 94;
            else if  ( exp == 114 )
                return 155;
            else if  ( exp == 115 )
                return 159;
            else if  ( exp == 116 )
                return 10;
            else if  ( exp == 117 )
                return 21;
            else if  ( exp == 118 )
                return 121;
            else if  ( exp == 119 )
                return 43;
            else if  ( exp == 120 )
                return 78;
        }

    }
    else
    {
        if  ( exp <= 132 )
        {
            if  ( exp == 121 )
                return 212;
            else if  ( exp == 122 )
                return 229;
            else if  ( exp == 123 )
                return 172;
            else if  ( exp == 124 )
                return 115;
            else if  ( exp == 125 )
                return 243;
            else if  ( exp == 126 )
                return 167;
            else if  ( exp == 127 )
                return 87;
            else if  ( exp == 128 )
                return 7;
            else if  ( exp == 129 )
                return 112;
            else if  ( exp == 130 )
                return 192;
            else if  ( exp == 131 )
                return 247;
            else if  ( exp == 132 )
                return 140;
        }
        else if  ( exp <= 144 )
        {
            if  ( exp == 133 )
                return 128;
            else if  ( exp == 134 )
                return 99;
            else if  ( exp == 135 )
                return 13;
            else if  ( exp == 136 )
                return 103;
            else if  ( exp == 137 )
                return 74;
            else if  ( exp == 138 )
                return 222;
            else if  ( exp == 139 )
                return 237;
            else if  ( exp == 140 )
                return 49;
            else if  ( exp == 141 )
                return 197;
            else if  ( exp == 142 )
                return 254;
            else if  ( exp == 143 )
                return 24;
            else if  ( exp == 144 )
                return 227;
        }
        else if  ( exp <= 156 )
        {
            if  ( exp == 145 )
                return 165;
            else if  ( exp == 146 )
                return 153;
            else if  ( exp == 147 )
                return 119;
            else if  ( exp == 148 )
                return 38;
            else if  ( exp == 149 )
                return 184;
            else if  ( exp == 150 )
                return 180;
            else if  ( exp == 151 )
                return 124;
            else if  ( exp == 152 )
                return 17;
            else if  ( exp == 153 )
                return 68;
            else if  ( exp == 154 )
                return 146;
            else if  ( exp == 155 )
                return 217;
            else if  ( exp == 156 )
                return 35;
        }
        else if  ( exp <= 168 )
        {
            if  ( exp == 157 )
                return 32;
            else if  ( exp == 158 )
                return 137;
            else if  ( exp == 159 )
                return 46;
            else if  ( exp == 160 )
                return 55;
            else if  ( exp == 161 )
                return 63;
            else if  ( exp == 162 )
                return 209;
            else if  ( exp == 163 )
                return 91;
            else if  ( exp == 164 )
                return 149;
            else if  ( exp == 165 )
                return 188;
            else if  ( exp == 166 )
                return 207;
            else if  ( exp == 167 )
                return 205;
            else if  ( exp == 168 )
                return 144;
        }
        else if  ( exp <= 180 )
        {
            if  ( exp == 169 )
                return 135;
            else if  ( exp == 170 )
                return 151;
            else if  ( exp == 171 )
                return 178;
            else if  ( exp == 172 )
                return 220;
            else if  ( exp == 173 )
                return 252;
            else if  ( exp == 174 )
                return 190;
            else if  ( exp == 175 )
                return 97;
            else if  ( exp == 176 )
                return 242;
            else if  ( exp == 177 )
                return 86;
            else if  ( exp == 178 )
                return 211;
            else if  ( exp == 179 )
                return 171;
            else if  ( exp == 180 )
                return 20;
        }
        else if  ( exp <= 192 )
        {
            if  ( exp == 181 )
                return 42;
            else if  ( exp == 182 )
                return 93;
            else if  ( exp == 183 )
                return 158;
            else if  ( exp == 184 )
                return 132;
            else if  ( exp == 185 )
                return 60;
            else if  ( exp == 186 )
                return 57;
            else if  ( exp == 187 )
                return 83;
            else if  ( exp == 188 )
                return 71;
            else if  ( exp == 189 )
                return 109;
            else if  ( exp == 190 )
                return 65;
            else if  ( exp == 191 )
                return 162;
            else if  ( exp == 192 )
                return 31;
        }
        else if  ( exp <= 204 )
        {
            if  ( exp == 193 )
                return 45;
            else if  ( exp == 194 )
                return 67;
            else if  ( exp == 195 )
                return 216;
            else if  ( exp == 196 )
                return 183;
            else if  ( exp == 197 )
                return 123;
            else if  ( exp == 198 )
                return 164;
            else if  ( exp == 199 )
                return 118;
            else if  ( exp == 200 )
                return 196;
            else if  ( exp == 201 )
                return 23;
            else if  ( exp == 202 )
                return 73;
            else if  ( exp == 203 )
                return 236;
            else if  ( exp == 204 )
                return 127;
        }
        else if  ( exp <= 216 )
        {
            if  ( exp == 205 )
                return 12;
            else if  ( exp == 206 )
                return 111;
            else if  ( exp == 207 )
                return 246;
            else if  ( exp == 208 )
                return 108;
            else if  ( exp == 209 )
                return 161;
            else if  ( exp == 210 )
                return 59;
            else if  ( exp == 211 )
                return 82;
            else if  ( exp == 212 )
                return 41;
            else if  ( exp == 213 )
                return 157;
            else if  ( exp == 214 )
                return 85;
            else if  ( exp == 215 )
                return 170;
            else if  ( exp == 216 )
                return 251;
        }
        else if  ( exp <= 228 )
        {
            if  ( exp == 217 )
                return 96;
            else if  ( exp == 218 )
                return 134;
            else if  ( exp == 219 )
                return 177;
            else if  ( exp == 220 )
                return 187;
            else if  ( exp == 221 )
                return 204;
            else if  ( exp == 222 )
                return 62;
            else if  ( exp == 223 )
                return 90;
            else if  ( exp == 224 )
                return 203;
            else if  ( exp == 225 )
                return 89;
            else if  ( exp == 226 )
                return 95;
            else if  ( exp == 227 )
                return 176;
            else if  ( exp == 228 )
                return 156;
        }
        else if  ( exp <= 240 )
        {
            if  ( exp == 229 )
                return 169;
            else if  ( exp == 230 )
                return 160;
            else if  ( exp == 231 )
                return 81;
            else if  ( exp == 232 )
                return 11;
            else if  ( exp == 233 )
                return 245;
            else if  ( exp == 234 )
                return 22;
            else if  ( exp == 235 )
                return 235;
            else if  ( exp == 236 )
                return 122;
            else if  ( exp == 237 )
                return 117;
            else if  ( exp == 238 )
                return 44;
            else if  ( exp == 239 )
                return 215;
            else if  ( exp == 240 )
                return 79;
        }
        else if  ( exp <= 252 )
        {
            if  ( exp == 241 )
                return 174;
            else if  ( exp == 242 )
                return 213;
            else if  ( exp == 243 )
                return 233;
            else if  ( exp == 244 )
                return 230;
            else if  ( exp == 245 )
                return 231;
            else if  ( exp == 246 )
                return 173;
            else if  ( exp == 247 )
                return 232;
            else if  ( exp == 248 )
                return 116;
            else if  ( exp == 249 )
                return 214;
            else if  ( exp == 250 )
                return 244;
            else if  ( exp == 251 )
                return 234;
            else if  ( exp == 252 )
                return 168;
        }
        else if  ( exp <= 255 )
        {
            if  ( exp == 253 )
                return 80;
            else if  ( exp == 254 )
                return 88;
            else if  ( exp == 255 )
                return 175;
        }
    }




    return -1;
}



int Qrlog::getIntegerNotation(int base2exp)
{

    if(base2exp>=256)
        base2exp = base2exp % 255 ;

    if  ( base2exp <= 120 )
    {
        if  ( base2exp <= 12 )
        {
            if  ( base2exp == 0 )
                return 1;
            else if  ( base2exp == 1 )
                return 2;
            else if  ( base2exp == 2 )
                return 4;
            else if  ( base2exp == 3 )
                return 8;
            else if  ( base2exp == 4 )
                return 16;
            else if  ( base2exp == 5 )
                return 32;
            else if  ( base2exp == 6 )
                return 64;
            else if  ( base2exp == 7 )
                return 128;
            else if  ( base2exp == 8 )
                return 29;
            else if  ( base2exp == 9 )
                return 58;
            else if  ( base2exp == 10 )
                return 116;
            else if  ( base2exp == 11 )
                return 232;
            else if  ( base2exp == 12 )
                return 205;
        }
        else if  ( base2exp <= 24 )
        {
            if  ( base2exp == 13 )
                return 135;
            else if  ( base2exp == 14 )
                return 19;
            else if  ( base2exp == 15 )
                return 38;
            else if  ( base2exp == 16 )
                return 76;
            else if  ( base2exp == 17 )
                return 152;
            else if  ( base2exp == 18 )
                return 45;
            else if  ( base2exp == 19 )
                return 90;
            else if  ( base2exp == 20 )
                return 180;
            else if  ( base2exp == 21 )
                return 117;
            else if  ( base2exp == 22 )
                return 234;
            else if  ( base2exp == 23 )
                return 201;
            else if  ( base2exp == 24 )
                return 143;
        }
        else if  ( base2exp <= 36 )
        {
            if  ( base2exp == 25 )
                return 3;
            else if  ( base2exp == 26 )
                return 6;
            else if  ( base2exp == 27 )
                return 12;
            else if  ( base2exp == 28 )
                return 24;
            else if  ( base2exp == 29 )
                return 48;
            else if  ( base2exp == 30 )
                return 96;
            else if  ( base2exp == 31 )
                return 192;
            else if  ( base2exp == 32 )
                return 157;
            else if  ( base2exp == 33 )
                return 39;
            else if  ( base2exp == 34 )
                return 78;
            else if  ( base2exp == 35 )
                return 156;
            else if  ( base2exp == 36 )
                return 37;
        }
        else if  ( base2exp <= 48 )
        {
            if  ( base2exp == 37 )
                return 74;
            else if  ( base2exp == 38 )
                return 148;
            else if  ( base2exp == 39 )
                return 53;
            else if  ( base2exp == 40 )
                return 106;
            else if  ( base2exp == 41 )
                return 212;
            else if  ( base2exp == 42 )
                return 181;
            else if  ( base2exp == 43 )
                return 119;
            else if  ( base2exp == 44 )
                return 238;
            else if  ( base2exp == 45 )
                return 193;
            else if  ( base2exp == 46 )
                return 159;
            else if  ( base2exp == 47 )
                return 35;
            else if  ( base2exp == 48 )
                return 70;
        }
        else if  ( base2exp <= 60 )
        {
            if  ( base2exp == 49 )
                return 140;
            else if  ( base2exp == 50 )
                return 5;
            else if  ( base2exp == 51 )
                return 10;
            else if  ( base2exp == 52 )
                return 20;
            else if  ( base2exp == 53 )
                return 40;
            else if  ( base2exp == 54 )
                return 80;
            else if  ( base2exp == 55 )
                return 160;
            else if  ( base2exp == 56 )
                return 93;
            else if  ( base2exp == 57 )
                return 186;
            else if  ( base2exp == 58 )
                return 105;
            else if  ( base2exp == 59 )
                return 210;
            else if  ( base2exp == 60 )
                return 185;
        }
        else if  ( base2exp <= 72 )
        {
            if  ( base2exp == 61 )
                return 111;
            else if  ( base2exp == 62 )
                return 222;
            else if  ( base2exp == 63 )
                return 161;
            else if  ( base2exp == 64 )
                return 95;
            else if  ( base2exp == 65 )
                return 190;
            else if  ( base2exp == 66 )
                return 97;
            else if  ( base2exp == 67 )
                return 194;
            else if  ( base2exp == 68 )
                return 153;
            else if  ( base2exp == 69 )
                return 47;
            else if  ( base2exp == 70 )
                return 94;
            else if  ( base2exp == 71 )
                return 188;
            else if  ( base2exp == 72 )
                return 101;
        }
        else if  ( base2exp <= 84 )
        {
            if  ( base2exp == 73 )
                return 202;
            else if  ( base2exp == 74 )
                return 137;
            else if  ( base2exp == 75 )
                return 15;
            else if  ( base2exp == 76 )
                return 30;
            else if  ( base2exp == 77 )
                return 60;
            else if  ( base2exp == 78 )
                return 120;
            else if  ( base2exp == 79 )
                return 240;
            else if  ( base2exp == 80 )
                return 253;
            else if  ( base2exp == 81 )
                return 231;
            else if  ( base2exp == 82 )
                return 211;
            else if  ( base2exp == 83 )
                return 187;
            else if  ( base2exp == 84 )
                return 107;
        }
        else if  ( base2exp <= 96 )
        {
            if  ( base2exp == 85 )
                return 214;
            else if  ( base2exp == 86 )
                return 177;
            else if  ( base2exp == 87 )
                return 127;
            else if  ( base2exp == 88 )
                return 254;
            else if  ( base2exp == 89 )
                return 225;
            else if  ( base2exp == 90 )
                return 223;
            else if  ( base2exp == 91 )
                return 163;
            else if  ( base2exp == 92 )
                return 91;
            else if  ( base2exp == 93 )
                return 182;
            else if  ( base2exp == 94 )
                return 113;
            else if  ( base2exp == 95 )
                return 226;
            else if  ( base2exp == 96 )
                return 217;
        }
        else if  ( base2exp <= 108 )
        {
            if  ( base2exp == 97 )
                return 175;
            else if  ( base2exp == 98 )
                return 67;
            else if  ( base2exp == 99 )
                return 134;
            else if  ( base2exp == 100 )
                return 17;
            else if  ( base2exp == 101 )
                return 34;
            else if  ( base2exp == 102 )
                return 68;
            else if  ( base2exp == 103 )
                return 136;
            else if  ( base2exp == 104 )
                return 13;
            else if  ( base2exp == 105 )
                return 26;
            else if  ( base2exp == 106 )
                return 52;
            else if  ( base2exp == 107 )
                return 104;
            else if  ( base2exp == 108 )
                return 208;
        }
        else if  ( base2exp <= 120 )
        {
            if  ( base2exp == 109 )
                return 189;
            else if  ( base2exp == 110 )
                return 103;
            else if  ( base2exp == 111 )
                return 206;
            else if  ( base2exp == 112 )
                return 129;
            else if  ( base2exp == 113 )
                return 31;
            else if  ( base2exp == 114 )
                return 62;
            else if  ( base2exp == 115 )
                return 124;
            else if  ( base2exp == 116 )
                return 248;
            else if  ( base2exp == 117 )
                return 237;
            else if  ( base2exp == 118 )
                return 199;
            else if  ( base2exp == 119 )
                return 147;
            else if  ( base2exp == 120 )
                return 59;
        }

    }
    else
    {
        if  ( base2exp <= 132 )
        {
            if  ( base2exp == 121 )
                return 118;
            else if  ( base2exp == 122 )
                return 236;
            else if  ( base2exp == 123 )
                return 197;
            else if  ( base2exp == 124 )
                return 151;
            else if  ( base2exp == 125 )
                return 51;
            else if  ( base2exp == 126 )
                return 102;
            else if  ( base2exp == 127 )
                return 204;
            else if  ( base2exp == 128 )
                return 133;
            else if  ( base2exp == 129 )
                return 23;
            else if  ( base2exp == 130 )
                return 46;
            else if  ( base2exp == 131 )
                return 92;
            else if  ( base2exp == 132 )
                return 184;
        }
        else if  ( base2exp <= 144 )
        {
            if  ( base2exp == 133 )
                return 109;
            else if  ( base2exp == 134 )
                return 218;
            else if  ( base2exp == 135 )
                return 169;
            else if  ( base2exp == 136 )
                return 79;
            else if  ( base2exp == 137 )
                return 158;
            else if  ( base2exp == 138 )
                return 33;
            else if  ( base2exp == 139 )
                return 66;
            else if  ( base2exp == 140 )
                return 132;
            else if  ( base2exp == 141 )
                return 21;
            else if  ( base2exp == 142 )
                return 42;
            else if  ( base2exp == 143 )
                return 84;
            else if  ( base2exp == 144 )
                return 168;
        }
        else if  ( base2exp <= 156 )
        {
            if  ( base2exp == 145 )
                return 77;
            else if  ( base2exp == 146 )
                return 154;
            else if  ( base2exp == 147 )
                return 41;
            else if  ( base2exp == 148 )
                return 82;
            else if  ( base2exp == 149 )
                return 164;
            else if  ( base2exp == 150 )
                return 85;
            else if  ( base2exp == 151 )
                return 170;
            else if  ( base2exp == 152 )
                return 73;
            else if  ( base2exp == 153 )
                return 146;
            else if  ( base2exp == 154 )
                return 57;
            else if  ( base2exp == 155 )
                return 114;
            else if  ( base2exp == 156 )
                return 228;
        }
        else if  ( base2exp <= 168 )
        {
            if  ( base2exp == 157 )
                return 213;
            else if  ( base2exp == 158 )
                return 183;
            else if  ( base2exp == 159 )
                return 115;
            else if  ( base2exp == 160 )
                return 230;
            else if  ( base2exp == 161 )
                return 209;
            else if  ( base2exp == 162 )
                return 191;
            else if  ( base2exp == 163 )
                return 99;
            else if  ( base2exp == 164 )
                return 198;
            else if  ( base2exp == 165 )
                return 145;
            else if  ( base2exp == 166 )
                return 63;
            else if  ( base2exp == 167 )
                return 126;
            else if  ( base2exp == 168 )
                return 252;
        }
        else if  ( base2exp <= 180 )
        {
            if  ( base2exp == 169 )
                return 229;
            else if  ( base2exp == 170 )
                return 215;
            else if  ( base2exp == 171 )
                return 179;
            else if  ( base2exp == 172 )
                return 123;
            else if  ( base2exp == 173 )
                return 246;
            else if  ( base2exp == 174 )
                return 241;
            else if  ( base2exp == 175 )
                return 255;
            else if  ( base2exp == 176 )
                return 227;
            else if  ( base2exp == 177 )
                return 219;
            else if  ( base2exp == 178 )
                return 171;
            else if  ( base2exp == 179 )
                return 75;
            else if  ( base2exp == 180 )
                return 150;
        }
        else if  ( base2exp <= 192 )
        {
            if  ( base2exp == 181 )
                return 49;
            else if  ( base2exp == 182 )
                return 98;
            else if  ( base2exp == 183 )
                return 196;
            else if  ( base2exp == 184 )
                return 149;
            else if  ( base2exp == 185 )
                return 55;
            else if  ( base2exp == 186 )
                return 110;
            else if  ( base2exp == 187 )
                return 220;
            else if  ( base2exp == 188 )
                return 165;
            else if  ( base2exp == 189 )
                return 87;
            else if  ( base2exp == 190 )
                return 174;
            else if  ( base2exp == 191 )
                return 65;
            else if  ( base2exp == 192 )
                return 130;
        }
        else if  ( base2exp <= 204 )
        {
            if  ( base2exp == 193 )
                return 25;
            else if  ( base2exp == 194 )
                return 50;
            else if  ( base2exp == 195 )
                return 100;
            else if  ( base2exp == 196 )
                return 200;
            else if  ( base2exp == 197 )
                return 141;
            else if  ( base2exp == 198 )
                return 7;
            else if  ( base2exp == 199 )
                return 14;
            else if  ( base2exp == 200 )
                return 28;
            else if  ( base2exp == 201 )
                return 56;
            else if  ( base2exp == 202 )
                return 112;
            else if  ( base2exp == 203 )
                return 224;
            else if  ( base2exp == 204 )
                return 221;
        }
        else if  ( base2exp <= 216 )
        {
            if  ( base2exp == 205 )
                return 167;
            else if  ( base2exp == 206 )
                return 83;
            else if  ( base2exp == 207 )
                return 166;
            else if  ( base2exp == 208 )
                return 81;
            else if  ( base2exp == 209 )
                return 162;
            else if  ( base2exp == 210 )
                return 89;
            else if  ( base2exp == 211 )
                return 178;
            else if  ( base2exp == 212 )
                return 121;
            else if  ( base2exp == 213 )
                return 242;
            else if  ( base2exp == 214 )
                return 249;
            else if  ( base2exp == 215 )
                return 239;
            else if  ( base2exp == 216 )
                return 195;
        }
        else if  ( base2exp <= 228 )
        {
            if  ( base2exp == 217 )
                return 155;
            else if  ( base2exp == 218 )
                return 43;
            else if  ( base2exp == 219 )
                return 86;
            else if  ( base2exp == 220 )
                return 172;
            else if  ( base2exp == 221 )
                return 69;
            else if  ( base2exp == 222 )
                return 138;
            else if  ( base2exp == 223 )
                return 9;
            else if  ( base2exp == 224 )
                return 18;
            else if  ( base2exp == 225 )
                return 36;
            else if  ( base2exp == 226 )
                return 72;
            else if  ( base2exp == 227 )
                return 144;
            else if  ( base2exp == 228 )
                return 61;
        }
        else if  ( base2exp <= 240 )
        {
            if  ( base2exp == 229 )
                return 122;
            else if  ( base2exp == 230 )
                return 244;
            else if  ( base2exp == 231 )
                return 245;
            else if  ( base2exp == 232 )
                return 247;
            else if  ( base2exp == 233 )
                return 243;
            else if  ( base2exp == 234 )
                return 251;
            else if  ( base2exp == 235 )
                return 235;
            else if  ( base2exp == 236 )
                return 203;
            else if  ( base2exp == 237 )
                return 139;
            else if  ( base2exp == 238 )
                return 11;
            else if  ( base2exp == 239 )
                return 22;
            else if  ( base2exp == 240 )
                return 44;
        }
        else if  ( base2exp <= 252 )
        {
            if  ( base2exp == 241 )
                return 88;
            else if  ( base2exp == 242 )
                return 176;
            else if  ( base2exp == 243 )
                return 125;
            else if  ( base2exp == 244 )
                return 250;
            else if  ( base2exp == 245 )
                return 233;
            else if  ( base2exp == 246 )
                return 207;
            else if  ( base2exp == 247 )
                return 131;
            else if  ( base2exp == 248 )
                return 27;
            else if  ( base2exp == 249 )
                return 54;
            else if  ( base2exp == 250 )
                return 108;
            else if  ( base2exp == 251 )
                return 216;
            else if  ( base2exp == 252 )
                return 173;
        }
        else if  ( base2exp <= 255 )
        {
            if  ( base2exp == 253 )
                return 71;
            else if  ( base2exp == 254 )
                return 142;
            else if  ( base2exp == 255 )
                return 1;
        }
    }


    return -1;
}
