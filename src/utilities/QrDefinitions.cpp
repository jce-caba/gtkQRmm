#include "QrDefinitions.hpp"


using namespace GtkQR;

QRDataContainer::QRDataContainer()
{
    correction_level = QRErrorCorrectionLevel ::QR_ERROR_CORRECTION_LEVEL_MEDIUM;
    isMicro=false;
    enable_UTF8=true;

    qrversion_number = QR_NO_VERSION;
    qrversion = QRVersion::QR_VERSION_NULL;
    mask = QR_NO_MASK;

}

QRDataContainer::QRDataContainer(const QRDataContainer &other)
{
    copyparameters(const_cast<QRDataContainer &>(other));
    copylist(other);
}

QRDataContainer::QRDataContainer(QRDataContainer &&other)
{
    unsigned short aux = num_modules;
    copyparameters(other);
    std::swap(eci_mode,other.eci_mode);
    other.num_modules =aux;
}

QRDataContainer& QRDataContainer::operator=(const QRDataContainer &other)
{
    copyparameters(const_cast<QRDataContainer &>(other));
    copylist(other);
    return *this;
}

QRDataContainer& QRDataContainer::operator=(QRDataContainer &&other)
{
    unsigned short aux = num_modules;
    copyparameters(other);
    std::swap(eci_mode,other.eci_mode);
    other.num_modules =aux;
    return *this;
}


void QRDataContainer::copyparameters(QRDataContainer &other)
{
    enable_UTF8= other.enable_UTF8;
    isMicro= other.isMicro;
    isMicro= other.isMicro;
    correction_level= other.correction_level;
    qrversion= other.qrversion;
    qrversion_number= other.qrversion_number;
    num_modules= other.num_modules;
    mask= other.mask;
    num_eci_mode= other.num_eci_mode;
    data_coding= other.data_coding;
    error= other.error;
    warning= other.warning;

}

void QRDataContainer::copylist(const QRDataContainer &other)
{
   eci_mode.clear();

   for (std::list<QREciMode>::const_iterator it=other.eci_mode.begin(); it != other.eci_mode.end(); ++it)
       eci_mode.push_back (*it);


}

QRDataContainer::~QRDataContainer()
{

}
QRVersion QRDataContainer::getqrversion()
{
    return qrversion;
}
short QRDataContainer::getqrversion_number()
{
    return qrversion_number;
}
unsigned short QRDataContainer::getnum_modules()
{
    return num_modules;
}
unsigned short QRDataContainer::getnum_mask()
{
    return mask;
}
QREciMode QRDataContainer::geteci_mode(int position)
{
    QREciMode eci=QREciMode::QR_ECI_MODE_ISO_8859_1;
    int i=0;
    bool finded=false;
    std::list<QREciMode>::const_iterator it=eci_mode.begin();

    while(it != eci_mode.end() && !finded)
    {
        if(i==position)
        {
            eci= *it;
            finded=true;
        }
        else
        {
            i++;
            ++it;
        }
    }


    return eci;
}
unsigned short QRDataContainer::getnum_eci_mode()
{
    return num_eci_mode;
}
QRData QRDataContainer::getdata_coding()
{
    return data_coding;
}
std:: string & QRDataContainer::geterror()
{
    return error;
}
std:: string & QRDataContainer::getwarning()
{
    return warning;
}
