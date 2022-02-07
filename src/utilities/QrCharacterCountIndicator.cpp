#include "QrCharacterCountIndicator.hpp"

 using namespace GtkQR;

 int QrCharacterCountIndicator::getCharacterCountIndicator(QRDataContainer *data)
 {
    QRVersion version = data->getqrversion();
    QRData coding = data->getdata_coding();
    short version_number = data->getqrversion_number();

    if(data->isMicro)
    {
        if(version == QRVersion::QR_VERSION_M1)
        {
            if (coding == QRData::QR_DATA_NUMERIC)
                return 3;

        }
        else if(version == QRVersion::QR_VERSION_M2)
        {
            if (coding == QRData::QR_DATA_NUMERIC)
                return 4;
            else  if (coding == QRData::QR_DATA_ALPHANUMERIC)
                return 3;
        }
        else if(version == QRVersion::QR_VERSION_M3)
        {
            if (coding == QRData::QR_DATA_NUMERIC)
                return 5;
            else  if (coding == QRData::QR_DATA_ALPHANUMERIC)
                return 4;
            else  if (coding == QRData::QR_DATA_BYTE)
                return 4;
            else  if (coding == QRData::QR_DATA_KANJI)
                return 3;
        }
        else if(version == QRVersion::QR_VERSION_M4)
        {
            if (coding == QRData::QR_DATA_NUMERIC)
                return 6;
            else  if (coding == QRData::QR_DATA_ALPHANUMERIC)
                return 5;
            else  if (coding == QRData::QR_DATA_BYTE)
                return 5;
            else  if (coding == QRData::QR_DATA_KANJI)
                return 4;
        }


    }
    else
    {
        if(version_number >=1 && version_number <=9)
        {
            if (coding == QRData::QR_DATA_NUMERIC)
                return 10;
            else  if (coding == QRData::QR_DATA_ALPHANUMERIC)
                return 9;
            else  if (coding == QRData::QR_DATA_BYTE)
                return 8;
            else  if (coding == QRData::QR_DATA_KANJI)
                return 8;

        }
        else if(version_number >=10 && version_number <= 26)
        {

            if (coding == QRData::QR_DATA_NUMERIC)
                return 12;
            else  if (coding == QRData::QR_DATA_ALPHANUMERIC)
                return 11;
            else  if (coding == QRData::QR_DATA_BYTE)
                return 16;
            else  if (coding == QRData::QR_DATA_KANJI)
                return 10;

        }
        else if(version_number >=27 && version_number <= 40)
        {

            if (coding == QRData::QR_DATA_NUMERIC)
                return 14;
            else  if (coding == QRData::QR_DATA_ALPHANUMERIC)
                return 13;
            else  if (coding == QRData::QR_DATA_BYTE)
                return 16;
            else  if (coding == QRData::QR_DATA_KANJI)
                return 12;

        }
    }

    return 0;
 }

