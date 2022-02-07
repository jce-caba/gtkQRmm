#include "QrParity.hpp"

using namespace GtkQR ;

int QrParity::getparity(QRDataContainer *data)
{
    QRVersion version =data->getqrversion();

    if(version==QRVersion:: QR_VERSION_M1 || version==   QRVersion:: QR_VERSION_M3 )
        return 4;
     else
        return 8;
}
