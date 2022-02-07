#include "QrVersion.hpp"

using namespace GtkQR;


 int QrVersion::getnumbermodule(QRDataContainer *data)
 {
     int version;

    if (data->isMicro)
    {
        switch(data->getqrversion())
        {
        case QRVersion::QR_VERSION_M1:
            version = 11;
            break;
        case QRVersion::QR_VERSION_M2:
            version = 13;
            break;
        case QRVersion::QR_VERSION_M3:
            version = 15;
            break;
        default:
            version = 17;
            break;
        }
    }
    else
    {
      version = 21 + (data->getqrversion_number() -1) *4;

      if (version > 177)
             version = 177;
      else if (version < 21)
             version = 21;
    }

     return version;
 }

 int QrVersion::version_to_int(QRVersion version)
 {
     if(version==QRVersion::QR_VERSION_1)
             return 1;
     else if(version==QRVersion::QR_VERSION_2)
             return 2;
     else if(version==QRVersion::QR_VERSION_3)
             return 3;
     else if(version==QRVersion::QR_VERSION_4)
             return 4;
     else if(version==QRVersion::QR_VERSION_5)
             return 5;
     else if(version==QRVersion::QR_VERSION_6)
             return 6;
     else if(version==QRVersion::QR_VERSION_7)
             return 7;
     else if(version==QRVersion::QR_VERSION_8)
             return 8;
     else if(version==QRVersion::QR_VERSION_9)
             return 9;
     else if(version==QRVersion::QR_VERSION_10)
             return 10;
     else if(version==QRVersion::QR_VERSION_11)
             return 11;
     else if(version==QRVersion::QR_VERSION_12)
             return 12;
     else if(version==QRVersion::QR_VERSION_13)
             return 13;
     else if(version==QRVersion::QR_VERSION_14)
             return 14;
     else if(version==QRVersion::QR_VERSION_15)
             return 15;
     else if(version==QRVersion::QR_VERSION_16)
             return 16;
     else if(version==QRVersion::QR_VERSION_17)
             return 17;
     else if(version==QRVersion::QR_VERSION_18)
             return 18;
     else if(version==QRVersion::QR_VERSION_19)
             return 19;
     else if(version==QRVersion::QR_VERSION_20)
             return 20;
     else if(version==QRVersion::QR_VERSION_21)
             return 21;
     else if(version==QRVersion::QR_VERSION_22)
             return 22;
     else if(version==QRVersion::QR_VERSION_23)
             return 23;
     else if(version==QRVersion::QR_VERSION_24)
             return 24;
     else if(version==QRVersion::QR_VERSION_25)
             return 25;
     else if(version==QRVersion::QR_VERSION_26)
             return 26;
     else if(version==QRVersion::QR_VERSION_27)
             return 27;
     else if(version==QRVersion::QR_VERSION_28)
             return 28;
     else if(version==QRVersion::QR_VERSION_29)
             return 29;
     else if(version==QRVersion::QR_VERSION_30)
             return 30;
     else if(version==QRVersion::QR_VERSION_31)
             return 31;
     else if(version==QRVersion::QR_VERSION_32)
             return 32;
     else if(version==QRVersion::QR_VERSION_33)
             return 33;
     else if(version==QRVersion::QR_VERSION_34)
             return 34;
     else if(version==QRVersion::QR_VERSION_35)
             return 35;
     else if(version==QRVersion::QR_VERSION_36)
             return 36;
     else if(version==QRVersion::QR_VERSION_37)
             return 37;
     else if(version==QRVersion::QR_VERSION_38)
             return 38;
     else if(version==QRVersion::QR_VERSION_39)
             return 39;
     else if(version==QRVersion::QR_VERSION_40)
             return 40;
     else if(version==QRVersion::QR_VERSION_NULL)
             return 41;
     else if(version==QRVersion::QR_VERSION_M1)
             return QR_VERSION_NUMBER_M1;
     else if(version==QRVersion::QR_VERSION_M2)
             return QR_VERSION_NUMBER_M2;
     else if(version==QRVersion::QR_VERSION_M3)
             return QR_VERSION_NUMBER_M3;
     else if(version==QRVersion::QR_VERSION_M4)
             return QR_VERSION_NUMBER_M4;


     return QR_NO_VERSION;
 }
