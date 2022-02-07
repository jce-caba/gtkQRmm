#include "QrErrorCorrection.hpp"


using namespace GtkQR;

 QrErrorCorrection::QrErrorCorrection (QRDataContainer *_data)
 {
     data=_data;
     version = data->getqrversion();
 }

 QrErrorCorrection::~QrErrorCorrection()
 {
    //dtor
 }


 int QrErrorCorrection::getDataBits()
 {


     if(version == QRVersion::QR_VERSION_M1 && data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_NOTHING )
              return 20;
     else if (version == QRVersion::QR_VERSION_M3){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
            return 84;

        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
            return 68;

     }

    return  8 * geterrorcorrection ();
 }

 int QrErrorCorrection::geterrorcorrection ()
 {

    if(version == QRVersion::QR_VERSION_M1 && data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_NOTHING )
        return 3;
    else if (version == QRVersion::QR_VERSION_M2){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
            return 5;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
            return 4;

    }
    else if (version == QRVersion::QR_VERSION_M3){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
            return 11;

        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
            return 9;

    }
    else if (version == QRVersion::QR_VERSION_M4){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
            return 16;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
            return 14;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
            return 10;
    }
    else if(version == QRVersion::QR_VERSION_1){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 19;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 16;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 13;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 9;
    }
    else if(version == QRVersion::QR_VERSION_2){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 34;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 22;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16;
    }
    else if(version == QRVersion::QR_VERSION_3){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 55;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 44;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 34;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 26;
    }
    else if(version == QRVersion::QR_VERSION_4){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 80;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 64;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 48;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 36;
    }
    else if(version == QRVersion::QR_VERSION_5){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 108;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 86;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 62;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 46;
    }
    else if(version == QRVersion::QR_VERSION_6){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 136;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 108;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 76;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 60;
    }
    else if(version == QRVersion::QR_VERSION_7){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 156;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 124;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 88;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 66;
    }
    else if(version == QRVersion::QR_VERSION_8){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 194;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 154;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 110;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 86;
    }
    else if(version == QRVersion::QR_VERSION_9){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 232;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 182;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 132;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 100;
    }
    else if(version == QRVersion::QR_VERSION_10){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 274;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 216;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 154;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 122;
    }
    else if(version == QRVersion::QR_VERSION_11){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 324;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 254;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 180;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 140;
    }
    else if(version == QRVersion::QR_VERSION_12){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 370;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 290;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 206;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 158;
    }
    else if(version == QRVersion::QR_VERSION_13){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 428;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 334;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 244;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 180;
    }
    else if(version == QRVersion::QR_VERSION_14){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 461;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 365;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 261;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 197;
    }
    else if(version == QRVersion::QR_VERSION_15){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 523;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 415;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 295;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 223;
    }
    else if(version == QRVersion::QR_VERSION_16){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 589;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 453;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 325;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 253;
    }
    else if(version == QRVersion::QR_VERSION_17){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 647;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 507;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 367;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 283;
    }
    else if(version == QRVersion::QR_VERSION_18){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 721;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 563;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 397;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 313;
    }
    else if(version == QRVersion::QR_VERSION_19){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 795;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 627;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 445;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 341;
    }
    else if(version == QRVersion::QR_VERSION_20){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 861;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 669;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 485;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 385;
    }
    else if(version == QRVersion::QR_VERSION_21){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 932;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 714;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 512;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 406;
    }
    else if(version == QRVersion::QR_VERSION_22){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1006;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 782;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 568;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 442;
    }
    else if(version == QRVersion::QR_VERSION_23){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1094;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 860;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 614;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 464;
    }
    else if(version == QRVersion::QR_VERSION_24){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1174;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 914;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 664;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 514;
    }
    else if(version == QRVersion::QR_VERSION_25){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1276;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 1000;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 718;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 538;
    }
    else if(version == QRVersion::QR_VERSION_26){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1370;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 1062;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 754;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 596;
    }
    else if(version == QRVersion::QR_VERSION_27){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1468;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 1128;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 808;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 628;
    }
    else if(version == QRVersion::QR_VERSION_28){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1531;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 1193;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 871;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 661;
    }
    else if(version == QRVersion::QR_VERSION_29){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1631;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 1267;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 911;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 701;
    }
    else if(version == QRVersion::QR_VERSION_30){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1735;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 1373;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 985;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 745;
    }
    else if(version == QRVersion::QR_VERSION_31){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1843;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 1455;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 1033;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 793;
    }
    else if(version == QRVersion::QR_VERSION_32){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1955;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 1541;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 1115;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 845;
    }
    else if(version == QRVersion::QR_VERSION_33){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 2071;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 1631;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 1171;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 901;
    }
    else if(version == QRVersion::QR_VERSION_34){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 2191;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 1725;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 1231;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 961;
    }
    else if(version == QRVersion::QR_VERSION_35){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 2306;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 1812;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 1286;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 986;
    }
    else if(version == QRVersion::QR_VERSION_36){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 2434;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 1914;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 1354;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 1054;
    }
    else if(version == QRVersion::QR_VERSION_37){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 2566;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 1992;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 1426;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 1096;
    }
    else if(version == QRVersion::QR_VERSION_38){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 2702;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 2102;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 1502;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 1142;
    }
    else if(version == QRVersion::QR_VERSION_39){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 2812;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 2216;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 1582;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 1222;
    }
    else if(version == QRVersion::QR_VERSION_40){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 2956;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 2334;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 1666;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 1276;
    }


     return 0;
 }

 int QrErrorCorrection::getECCodewords ()
 {

    if(version ==  QRVersion::QR_VERSION_M1 && data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_NOTHING )
        return 2;
    else if (version ==  QRVersion::QR_VERSION_M2){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
            return 5;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
            return 6;

    }
    else if (version ==  QRVersion::QR_VERSION_M3){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
            return 6;

        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
            return 8;

    }
    else if (version ==  QRVersion::QR_VERSION_M4){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
            return 8;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
            return 10;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
            return 14;
    }
    else if(version == QRVersion::QR_VERSION_1){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 7;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 10;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 13;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 17;
    }
    else if(version == QRVersion::QR_VERSION_2){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 10;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 16;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 22;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 28;
    }
    else if(version == QRVersion::QR_VERSION_3){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 15;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 26;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 18;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 22;
    }
    else if(version == QRVersion::QR_VERSION_4){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 20;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 18;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 26;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16;
    }
    else if(version == QRVersion::QR_VERSION_5){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 26;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 18;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 22;
    }
    else if(version == QRVersion::QR_VERSION_6){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 18;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 16;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 28;
    }
    else if(version == QRVersion::QR_VERSION_7){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 20;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 18;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 18;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 26;
    }
    else if(version == QRVersion::QR_VERSION_8){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 22;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 22;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 26;
    }
    else if(version == QRVersion::QR_VERSION_9){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 22;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 20;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 24;
    }
    else if(version == QRVersion::QR_VERSION_10){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 18;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 26;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 28;
    }
    else if(version == QRVersion::QR_VERSION_11){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 20;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 24;
    }
    else if(version == QRVersion::QR_VERSION_12){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 22;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 26;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 28;
    }
    else if(version == QRVersion::QR_VERSION_13){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 26;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 22;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 22;
    }
    else if(version == QRVersion::QR_VERSION_14){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 20;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 24;
    }
    else if(version == QRVersion::QR_VERSION_15){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 22;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 24;
    }
    else if(version == QRVersion::QR_VERSION_16){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 30;
    }
    else if(version == QRVersion::QR_VERSION_17){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 28;
    }
    else if(version == QRVersion::QR_VERSION_18){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 26;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 28;
    }
    else if(version == QRVersion::QR_VERSION_19){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 26;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 26;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 26;
    }
    else if(version == QRVersion::QR_VERSION_20){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 26;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 28;
    }
    else if(version == QRVersion::QR_VERSION_21){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 26;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 30;
    }
    else if(version == QRVersion::QR_VERSION_22){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 24;
    }
    else if(version == QRVersion::QR_VERSION_23){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 30;
    }
    else if(version == QRVersion::QR_VERSION_24){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 30;
    }
    else if(version == QRVersion::QR_VERSION_25){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 26;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 30;
    }
    else if(version == QRVersion::QR_VERSION_26){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 30;
    }
    else if(version == QRVersion::QR_VERSION_27){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 30;
    }
    else if(version == QRVersion::QR_VERSION_28){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 30;
    }
    else if(version == QRVersion::QR_VERSION_29){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 30;
    }
    else if(version == QRVersion::QR_VERSION_30){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 30;
    }
    else if(version == QRVersion::QR_VERSION_31){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 30;
    }
    else if(version == QRVersion::QR_VERSION_32){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 30;
    }
    else if(version == QRVersion::QR_VERSION_33){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 30;
    }
    else if(version == QRVersion::QR_VERSION_34){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 30;
    }
    else if(version == QRVersion::QR_VERSION_35){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 30;
    }
    else if(version == QRVersion::QR_VERSION_36){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 30;
    }
    else if(version == QRVersion::QR_VERSION_37){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 30;
    }
    else if(version == QRVersion::QR_VERSION_38){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 30;
    }
    else if(version == QRVersion::QR_VERSION_39){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 30;
    }
    else if(version == QRVersion::QR_VERSION_40){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 30;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 30;
    }


   return 0;
 }

 int QrErrorCorrection::getNumberBlocks1 ()
 {
    if(version ==  QRVersion::QR_VERSION_M1 && data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_NOTHING )
        return 1;
    else if (version ==  QRVersion::QR_VERSION_M2) {
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
            return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
            return 1;

    }
    else if (version ==  QRVersion::QR_VERSION_M3) {
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
            return 1;

        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
            return 1;

    }
    else if (version ==  QRVersion::QR_VERSION_M4) {
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
               return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
               return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
               return 1;
  }
    else if(version == QRVersion::QR_VERSION_1){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 1;
    }
    else if(version == QRVersion::QR_VERSION_2){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 1;
    }
    else if(version == QRVersion::QR_VERSION_3){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 2;
    }
    else if(version == QRVersion::QR_VERSION_4){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 4;
    }
    else if(version == QRVersion::QR_VERSION_5){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 2;
    }
    else if(version == QRVersion::QR_VERSION_6){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 4;
    }
    else if(version == QRVersion::QR_VERSION_7){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 4;
    }
    else if(version == QRVersion::QR_VERSION_8){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 4;
    }
    else if(version == QRVersion::QR_VERSION_9){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 3;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 4;
    }
    else if(version == QRVersion::QR_VERSION_10){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 6;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 6;
    }
    else if(version == QRVersion::QR_VERSION_11){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 3;
    }
    else if(version == QRVersion::QR_VERSION_12){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 6;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 7;
    }
    else if(version == QRVersion::QR_VERSION_13){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 8;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 8;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 12;
    }
    else if(version == QRVersion::QR_VERSION_14){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 3;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 11;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 11;
    }
    else if(version == QRVersion::QR_VERSION_15){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 5;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 5;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 5;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 11;
    }
    else if(version == QRVersion::QR_VERSION_16){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 5;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 7;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 15;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 3;
    }
    else if(version == QRVersion::QR_VERSION_17){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 10;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 2;
    }
    else if(version == QRVersion::QR_VERSION_18){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 5;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 9;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 17;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 2;
    }
    else if(version == QRVersion::QR_VERSION_19){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 3;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 3;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 17;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 9;
    }
    else if(version == QRVersion::QR_VERSION_20){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 3;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 3;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 15;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15;
    }
    else if(version == QRVersion::QR_VERSION_21){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 17;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 17;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 19;
    }
    else if(version == QRVersion::QR_VERSION_22){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 17;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 7;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 34;
    }
    else if(version == QRVersion::QR_VERSION_23){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 11;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16;
    }
    else if(version == QRVersion::QR_VERSION_24){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 6;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 6;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 11;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 30;
    }
    else if(version == QRVersion::QR_VERSION_25){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 8;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 8;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 7;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 22;
    }
    else if(version == QRVersion::QR_VERSION_26){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 10;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 19;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 33;
    }
    else if(version == QRVersion::QR_VERSION_27){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 8;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 22;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 8;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 12;
    }
    else if(version == QRVersion::QR_VERSION_28){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 3;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 3;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 11;
    }
    else if(version == QRVersion::QR_VERSION_29){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 7;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 21;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 19;
    }
    else if(version == QRVersion::QR_VERSION_30){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 5;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 19;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 15;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 23;
    }
    else if(version == QRVersion::QR_VERSION_31){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 13;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 42;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 23;
    }
    else if(version == QRVersion::QR_VERSION_32){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 17;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 10;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 10;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 19;
    }
    else if(version == QRVersion::QR_VERSION_33){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 17;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 14;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 29;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 11;
    }
    else if(version == QRVersion::QR_VERSION_34){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 13;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 14;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 44;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 59;
    }
    else if(version == QRVersion::QR_VERSION_35){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 12;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 12;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 39;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 22;
    }
    else if(version == QRVersion::QR_VERSION_36){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 6;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 6;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 46;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 2;
    }
    else if(version == QRVersion::QR_VERSION_37){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 17;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 29;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 49;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 24;
    }
    else if(version == QRVersion::QR_VERSION_38){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 13;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 48;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 42;
    }
    else if(version == QRVersion::QR_VERSION_39){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 20;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 40;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 43;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 10;
    }
    else if(version == QRVersion::QR_VERSION_40){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 19;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 18;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 34;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 20;
    }

     return 0;
 }

 int QrErrorCorrection::getNumberDataBlocks1 ()
 {

    if(version == QRVersion::QR_VERSION_M1 && data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_NOTHING )
        return 3;
    else if (version == QRVersion::QR_VERSION_M2)
    {
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
            return 5;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
            return 4;

    }
    else if (version == QRVersion::QR_VERSION_M3)
    {
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
            return 11;

        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
            return 9;

    }
    else if (version == QRVersion::QR_VERSION_M4)
    {
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
            return 16;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
            return 14;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
            return 10;
    }
    else if(version == QRVersion::QR_VERSION_1){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 19;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 16;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 13;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 9;
    }
    else if(version == QRVersion::QR_VERSION_2){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 34;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 28;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 22;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16;
    }
    else if(version == QRVersion::QR_VERSION_3){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 55;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 44;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 17;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 13;
    }
    else if(version == QRVersion::QR_VERSION_4){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 80;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 32;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 9;
    }
    else if(version == QRVersion::QR_VERSION_5){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 108;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 43;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 15;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 11;
    }
    else if(version == QRVersion::QR_VERSION_6){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 68;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 27;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 19;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15;
    }
    else if(version == QRVersion::QR_VERSION_7){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 78;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 31;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 14;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 13;
    }
    else if(version == QRVersion::QR_VERSION_8){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 97;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 38;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 18;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 14;
    }
    else if(version == QRVersion::QR_VERSION_9){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 116;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 36;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 16;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 12;
    }
    else if(version == QRVersion::QR_VERSION_10){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 68;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 43;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 19;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15;
    }
    else if(version == QRVersion::QR_VERSION_11){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 81;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 50;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 22;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 12;
    }
    else if(version == QRVersion::QR_VERSION_12){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 92;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 36;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 20;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 14;
    }
    else if(version == QRVersion::QR_VERSION_13){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 107;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 37;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 20;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 11;
    }
    else if(version == QRVersion::QR_VERSION_14){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 115;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 40;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 16;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 12;
    }
    else if(version == QRVersion::QR_VERSION_15){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 87;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 41;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 12;
    }
    else if(version == QRVersion::QR_VERSION_16){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 98;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 45;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 19;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15;
    }
    else if(version == QRVersion::QR_VERSION_17){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 107;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 46;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 22;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 14;
    }
    else if(version == QRVersion::QR_VERSION_18){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 120;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 43;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 22;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 14;
    }
    else if(version == QRVersion::QR_VERSION_19){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 113;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 44;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 21;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 13;
    }
    else if(version == QRVersion::QR_VERSION_20){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 107;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 41;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15;
    }
    else if(version == QRVersion::QR_VERSION_21){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 116;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 42;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 22;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16;
    }
    else if(version == QRVersion::QR_VERSION_22){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 111;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 46;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 13;
    }
    else if(version == QRVersion::QR_VERSION_23){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 121;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 47;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15;
    }
    else if(version == QRVersion::QR_VERSION_24){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 117;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 45;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16;
    }
    else if(version == QRVersion::QR_VERSION_25){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 106;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 47;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15;
    }
    else if(version == QRVersion::QR_VERSION_26){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 114;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 46;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 22;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16;
    }
    else if(version == QRVersion::QR_VERSION_27){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 122;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 45;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 23;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15;
    }
    else if(version == QRVersion::QR_VERSION_28){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 117;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 45;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15;
    }
    else if(version == QRVersion::QR_VERSION_29){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 116;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 45;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 23;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15;
    }
    else if(version == QRVersion::QR_VERSION_30){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 115;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 47;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15;
    }
    else if(version == QRVersion::QR_VERSION_31){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 115;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 46;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15;
    }
    else if(version == QRVersion::QR_VERSION_32){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 115;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 46;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15;
    }
    else if(version == QRVersion::QR_VERSION_33){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 115;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 46;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15;
    }
    else if(version == QRVersion::QR_VERSION_34){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 115;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 46;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16;
    }
    else if(version == QRVersion::QR_VERSION_35){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 121;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 47;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15;
    }
    else if(version == QRVersion::QR_VERSION_36){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 121;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 47;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15;
    }
    else if(version == QRVersion::QR_VERSION_37){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 122;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 46;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15;
    }
    else if(version == QRVersion::QR_VERSION_38){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 122;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 46;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15;
    }
    else if(version == QRVersion::QR_VERSION_39){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 117;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 47;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15;
    }
    else if(version == QRVersion::QR_VERSION_40){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 118;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 47;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15;
    }

     return 0;
 }

 int QrErrorCorrection::getNumberBlocks2 ()
 {

    if(version == QRVersion::QR_VERSION_1){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 0;
    }
    else if(version == QRVersion::QR_VERSION_2){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 0;
    }
    else if(version == QRVersion::QR_VERSION_3){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 0;
    }
    else if(version == QRVersion::QR_VERSION_4){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 0;
    }
    else if(version == QRVersion::QR_VERSION_5){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 2;
    }
    else if(version == QRVersion::QR_VERSION_6){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 0;
    }
    else if(version == QRVersion::QR_VERSION_7){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 1;
    }
    else if(version == QRVersion::QR_VERSION_8){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 2;
    }
    else if(version == QRVersion::QR_VERSION_9){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 4;
    }
    else if(version == QRVersion::QR_VERSION_10){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 2 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 1 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 2;
    }
    else if(version == QRVersion::QR_VERSION_11){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 8;
    }
    else if(version == QRVersion::QR_VERSION_12){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 6;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 4;
    }
    else if(version == QRVersion::QR_VERSION_13){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 4;
    }
    else if(version == QRVersion::QR_VERSION_14){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 5;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 5;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 5;
    }
    else if(version == QRVersion::QR_VERSION_15){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 5;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 7;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 7;
    }
    else if(version == QRVersion::QR_VERSION_16){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 3;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 13;
    }
    else if(version == QRVersion::QR_VERSION_17){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 5;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 15;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 17;
    }
    else if(version == QRVersion::QR_VERSION_18){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 19;
    }
    else if(version == QRVersion::QR_VERSION_19){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 11;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16;
    }
    else if(version == QRVersion::QR_VERSION_20){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 5;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 13;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 5;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 10;
    }
    else if(version == QRVersion::QR_VERSION_21){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 6;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 6;
    }
    else if(version == QRVersion::QR_VERSION_22){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 7;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 16;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 0;
    }
    else if(version == QRVersion::QR_VERSION_23){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 5;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 14;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 14;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 14;
    }
    else if(version == QRVersion::QR_VERSION_24){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 14;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 16;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 2;
    }
    else if(version == QRVersion::QR_VERSION_25){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 13;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 22;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 13;
    }
    else if(version == QRVersion::QR_VERSION_26){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 2;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 6;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 4;
    }
    else if(version == QRVersion::QR_VERSION_27){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 3;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 26;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 28;
    }
    else if(version == QRVersion::QR_VERSION_28){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 10;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 23;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 31;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 31;
    }
    else if(version == QRVersion::QR_VERSION_29){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 7;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 7;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 37;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 26;
    }
    else if(version == QRVersion::QR_VERSION_30){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 10;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 10;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 25;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 25;
    }
    else if(version == QRVersion::QR_VERSION_31){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 3;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 29;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 28;
    }
    else if(version == QRVersion::QR_VERSION_32){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 23;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 35;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 35;
    }
    else if(version == QRVersion::QR_VERSION_33){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 1;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 21;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 19;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 46;
    }
    else if(version == QRVersion::QR_VERSION_34){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 6;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 23;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 7;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 1;
    }
    else if(version == QRVersion::QR_VERSION_35){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 7;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 26;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 14;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 41;
    }
    else if(version == QRVersion::QR_VERSION_36){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 14;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 34;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 10;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 64;
    }
    else if(version == QRVersion::QR_VERSION_37){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 14;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 10;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 46;
    }
    else if(version == QRVersion::QR_VERSION_38){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 18;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 32;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 14;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 32;
    }
    else if(version == QRVersion::QR_VERSION_39){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 4;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 7;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 22;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 67;
    }
    else if(version == QRVersion::QR_VERSION_40){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 6;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 31;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 34;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 61;
    }

     return 0;
 }

 int QrErrorCorrection::getNumberDataBlocks2 ()
 {
    if(version == QRVersion::QR_VERSION_1){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 0;
    }
    else if(version == QRVersion::QR_VERSION_2){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 0;
    }
    else if(version == QRVersion::QR_VERSION_3){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 0;
    }
    else if(version == QRVersion::QR_VERSION_4){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 0;
    }
    else if(version == QRVersion::QR_VERSION_5){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 16 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 12 ;
    }
    else if(version == QRVersion::QR_VERSION_6){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 0;
    }
    else if(version == QRVersion::QR_VERSION_7){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 15 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 14 ;
    }
    else if(version == QRVersion::QR_VERSION_8){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 39 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 19 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15 ;
    }
    else if(version == QRVersion::QR_VERSION_9){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 37 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 17 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 13 ;
    }
    else if(version == QRVersion::QR_VERSION_10){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 69;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 44;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 20 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16 ;
    }
    else if(version == QRVersion::QR_VERSION_11){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 51 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 23 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 13 ;
    }
    else if(version == QRVersion::QR_VERSION_12){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 93 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 37 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 21 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15 ;
    }
    else if(version == QRVersion::QR_VERSION_13){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 38 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 21 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 12 ;
    }
    else if(version == QRVersion::QR_VERSION_14){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 116 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 41 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 17 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 13 ;
    }
    else if(version == QRVersion::QR_VERSION_15){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 88 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 42 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 25 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 13 ;
    }
    else if(version == QRVersion::QR_VERSION_16){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 99 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 46 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 20 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16 ;
    }
    else if(version == QRVersion::QR_VERSION_17){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 108 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 47 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 23 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15 ;
    }
    else if(version == QRVersion::QR_VERSION_18){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 121 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 44 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 23 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 15 ;
    }
    else if(version == QRVersion::QR_VERSION_19){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 114 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 45 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 22 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 14 ;
    }
    else if(version == QRVersion::QR_VERSION_20){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 108 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 42 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 25 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16 ;
    }
    else if(version == QRVersion::QR_VERSION_21){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 117 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 23 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 17 ;
    }
    else if(version == QRVersion::QR_VERSION_22){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 112 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 25 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 0;
    }
    else if(version == QRVersion::QR_VERSION_23){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 122 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 48 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 25 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16 ;
    }
    else if(version == QRVersion::QR_VERSION_24){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 118 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 46 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 25 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 17 ;
    }
    else if(version == QRVersion::QR_VERSION_25){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 107 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 48 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 25 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16 ;
    }
    else if(version == QRVersion::QR_VERSION_26){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 115 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 47 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 23 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 17 ;
    }
    else if(version == QRVersion::QR_VERSION_27){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 123 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 46 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16 ;
    }
    else if(version == QRVersion::QR_VERSION_28){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 118 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 46 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 25 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16 ;
    }
    else if(version == QRVersion::QR_VERSION_29){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 117 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 46 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 24 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16 ;
    }
    else if(version == QRVersion::QR_VERSION_30){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 116 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 48 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 25 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16 ;
    }
    else if(version == QRVersion::QR_VERSION_31){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 116 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 47 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 25 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16 ;
    }
    else if(version == QRVersion::QR_VERSION_32){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 0;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 47 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 25 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16 ;
    }
    else if(version == QRVersion::QR_VERSION_33){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 116 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 47 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 25 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16 ;
    }
    else if(version == QRVersion::QR_VERSION_34){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 116 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 47 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 25 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 17 ;
    }
    else if(version == QRVersion::QR_VERSION_35){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 122 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 48 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 25 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16 ;
    }
    else if(version == QRVersion::QR_VERSION_36){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 122 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 48 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 25 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16 ;
    }
    else if(version == QRVersion::QR_VERSION_37){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 123 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 47 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 25 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16 ;
    }
    else if(version == QRVersion::QR_VERSION_38){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 123 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 47 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 25 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16 ;
    }
    else if(version == QRVersion::QR_VERSION_39){

        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 118 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 48 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 25 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16 ;
    }
    else if(version == QRVersion::QR_VERSION_40){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
           return 119 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
           return 48 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY)
           return 25 ;
        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
           return 16 ;
    }

     return 0;
 }


