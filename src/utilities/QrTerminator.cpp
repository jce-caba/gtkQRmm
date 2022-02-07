#include "QrTerminator.hpp"

using namespace GtkQR;

int QrTerminator::getTerminator(QRDataContainer *data)
 {
     QRVersion version=data->getqrversion();

     if(version== QRVersion::QR_VERSION_M1)
             return 3;
     else if(version==QRVersion::QR_VERSION_M2)
             return 5;
     else if(version==QRVersion::QR_VERSION_M3)
             return 7;
     else if(version==QRVersion::QR_VERSION_M4)
             return 9;
     else
             return 4;

 }
