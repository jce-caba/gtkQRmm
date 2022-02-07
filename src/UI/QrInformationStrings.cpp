#include "QrInformationStrings.hpp"

using namespace GtkQR;



 const char * QrInformationStrings::getFormatInformation(QRDataContainer *data)
 {
     QRVersion version = data->getqrversion();
     short mask = data->getnum_mask();

    if(data->isMicro)
    {

        if  ( version == QRVersion::QR_VERSION_M1 ){
            if  ( mask ==1 )
                return "100010001000101";
            else if  ( mask ==4 )
                return "100000101110010";
            else if  ( mask ==6 )
                return "100111000101011";
            else if  ( mask ==7 )
                return "100101100011100";

        }
        else if  ( version == QRVersion::QR_VERSION_M2 && data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW ) {

            if  ( mask ==1 )
                return "101010110101110";
            else if  ( mask ==4 )
                return "101000010011001";
            else if  ( mask ==6 )
                return "101111111000000";
            else if  ( mask ==7 )
               return  "101101011110111";
        }
        else if  ( version == QRVersion::QR_VERSION_M2 && data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM ) {
            if  ( mask ==1 )
                return "110011110010011";
            else if  ( mask ==4 )
                return "110001010100100";
            else if  ( mask ==6 )
                return "110110111111101";
            else if  ( mask ==7 )
                return "110100011001010";

        }
        else if  ( version == QRVersion::QR_VERSION_M3 && data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW ) {

            if  ( mask ==1 )
                return "111011001111000";
            else if  ( mask ==4 )
                return "111001101001111";
            else if  ( mask ==6 )
                return "111110000010110";
            else if  ( mask ==7 )
                return "111100100100001";

        }
        else if  ( version == QRVersion::QR_VERSION_M3 && data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM ) {

            if  ( mask ==1 )
                return "000011011011110";
            else if  ( mask ==4 )
                return "000001111101001";
            else if  ( mask ==6 )
                return "000110010110000";
            else if  ( mask ==7 )
                return "000100110000111";

        }
        else if  ( version ==QRVersion::QR_VERSION_M4 && data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW ) {

            if  ( mask ==1 )
                return "001011100110101";
            else if  ( mask ==4 )
                return "001001000000010";
            else if  ( mask ==6 )
                return "001110101011011";
            else if  ( mask ==7 )
                return "001100001101100";

        }
        else if  ( version == QRVersion::QR_VERSION_M4 && data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM ) {

            if  ( mask ==1 )
                return "010010100001000";
            else if  ( mask ==4 )
                return "010000000111111";
            else if  ( mask ==6 )
                return "010111101100110";
            else if  ( mask ==7 )
                return "010101001010001";

        }
        else if  ( version == QRVersion::QR_VERSION_M4 && data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY ) {

            if  ( mask ==1 )
                return "011010011100011";
            else if  ( mask ==4 )
                return "011000111010100";
            else if  ( mask ==6 )
                return "011111010001101";
            else if  ( mask ==7 )
                return "011101110111010";

        }
    }
    else
    {
        if  ( data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW )
        {
            if  ( mask ==0 )
                return "111011111000100";
            else if  ( mask ==1 )
                return "111001011110011";
            else if  ( mask ==2 )
                return "111110110101010";
            else if  ( mask ==3 )
                return "111100010011101";
            else if  ( mask ==4 )
                return "110011000101111";
            else if  ( mask ==5 )
                return "110001100011000";
            else if  ( mask ==6 )
                return "110110001000001";
            else if  ( mask ==7 )
                return "110100101110110";
        }
        else if  ( data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM )
        {
            if  ( mask ==0 )
                return "101010000010010";
            else if  ( mask ==1 )
                return "101000100100101";
            else if  ( mask ==2 )
                return "101111001111100";
            else if  ( mask ==3 )
                return "101101101001011";
            else if  ( mask ==4 )
                return "100010111111001";
            else if  ( mask ==5 )
                return "100000011001110";
            else if  ( mask ==6 )
                return "100111110010111";
            else if  ( mask ==7 )
                return "100101010100000";
        }
        else if  ( data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY )
        {
            if  ( mask ==0 )
                return "011010101011111";
            else if  ( mask ==1 )
                return "011000001101000";
            else if  ( mask ==2 )
                return "011111100110001";
            else if  ( mask ==3 )
                return "011101000000110";
            else if  ( mask ==4 )
                return "010010010110100";
            else if  ( mask ==5 )
                return "010000110000011";
            else if  ( mask ==6 )
                return "010111011011010";
            else if  ( mask ==7 )
                return "010101111101101";
        }
        else if  ( data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH )
        {
            if  ( mask ==0 )
                return "001011010001001";
            else if  ( mask ==1 )
                return "001001110111110";
            else if  ( mask ==2 )
                return "001110011100111";
            else if  ( mask ==3 )
                return "001100111010000";
            else if  ( mask ==4 )
                return "000011101100010";
            else if  ( mask ==5 )
                return "000001001010101";
            else if  ( mask ==6 )
                return "000110100001100";
            else if  ( mask ==7 )
                return "000100000111011";
        }

    }

    return "";
 }

 const char * QrInformationStrings::getVersionInformation(QRDataContainer *data)
 {
         short version = data->getqrversion_number();


         if  ( version == 7 )
                return "000111110010010100";
         else if  ( version == 8 )
                return "001000010110111100";
         else if  ( version == 9 )
                return "001001101010011001";
         else if  ( version == 10 )
                return "001010010011010011";
         else if  ( version == 11 )
                return "001011101111110110";
         else if  ( version == 12 )
                return "001100011101100010";
         else if  ( version == 13 )
                return "001101100001000111";
         else if  ( version == 14 )
                return "001110011000001101";
         else if  ( version == 15 )
                return "001111100100101000";
         else if  ( version == 16 )
                return "010000101101111000";
         else if  ( version == 17 )
                return "010001010001011101";
         else if  ( version == 18 )
                return "010010101000010111";
         else if  ( version == 19 )
                return "010011010100110010";
         else if  ( version == 20 )
                return "010100100110100110";
         else if  ( version == 21 )
                return "010101011010000011";
         else if  ( version == 22 )
                return "010110100011001001";
         else if  ( version == 23 )
                return "010111011111101100";
         else if  ( version == 24 )
                return "011000111011000100";
         else if  ( version == 25 )
                return "011001000111100001";
         else if  ( version == 26 )
                return "011010111110101011";
         else if  ( version == 27 )
                return "011011000010001110";
         else if  ( version == 28 )
                return "011100110000011010";
         else if  ( version == 29 )
                return "011101001100111111";
         else if  ( version == 30 )
                return "011110110101110101";
         else if  ( version == 31 )
                return "011111001001010000";
         else if  ( version == 32 )
                return "100000100111010101";
         else if  ( version == 33 )
                return "100001011011110000";
         else if  ( version == 34 )
                return "100010100010111010";
         else if  ( version == 35 )
                return "100011011110011111";
         else if  ( version == 36 )
                return "100100101100001011";
         else if  ( version == 37 )
                return "100101010000101110";
         else if  ( version == 38 )
                return "100110101001100100";
         else if  ( version == 39 )
                return "100111010101000001";
         else if  ( version == 40 )
                return "101000110001101001";

    return "";

 }
