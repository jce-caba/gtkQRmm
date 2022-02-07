#include "QrIndicator.hpp"
#include "Qrlistutils.hpp"

using namespace GtkQR;

QrIndicator::QrIndicator(QRDataContainer *_data)
{
    data=_data;
}

QrIndicator::~QrIndicator()
{
    //dtor
}

 const char * QrIndicator::getEciIndicator(Dictionary *dictionary,int num_it)
 {
   const char *txt ="";
   QRData coding = data->getdata_coding();

   if (num_it == 0 && coding == QRData::QR_DATA_BYTE && dictionary->eci_mode != QREciMode::QR_ECI_MODE_ISO_8859_1)
                                 txt ="0111";
   else if (num_it > 0 && coding == QRData::QR_DATA_BYTE )
                                 txt ="0111";

    return txt;
 }

 const char * QrIndicator::getEciAssignament(Dictionary *dictionary,int num_it)
 {
   const char *txt ="";


   if(data->getdata_coding() !=QRData::QR_DATA_BYTE)
           return txt;


   switch(dictionary->eci_mode)
   {
      case QREciMode::QR_ECI_MODE_ISO_8859_1:
             if (num_it > 0 )
                          txt ="00000011";
      break;
      case QREciMode::QR_ECI_MODE_ISO_8859_2:
            txt ="00000100";
      break;
      case QREciMode::QR_ECI_MODE_ISO_8859_3:
            txt ="00000101";
      break;
      case QREciMode::QR_ECI_MODE_ISO_8859_4:
            txt ="00000110";
      break;
      case QREciMode::QR_ECI_MODE_ISO_8859_5:
            txt ="00000111";
      break;
      case QREciMode::QR_ECI_MODE_ISO_8859_6:
            txt ="00001000";
      break;
      case QREciMode::QR_ECI_MODE_ISO_8859_7:
            txt ="00001001";
      break;
      case QREciMode::QR_ECI_MODE_ISO_8859_8:
            txt ="00010000";
      break;
      case QREciMode::QR_ECI_MODE_ISO_8859_9:
            txt ="00010001";
      break;
      case QREciMode::QR_ECI_MODE_ISO_8859_10:
            txt ="00010010";
      break;
      case QREciMode::QR_ECI_MODE_ISO_8859_11:
            txt ="00010011";
      break;
      case QREciMode::QR_ECI_MODE_ISO_8859_13:
            txt ="00010101";
      break;
      case QREciMode::QR_ECI_MODE_ISO_8859_14:
            txt ="00010110";
      break;
      case QREciMode::QR_ECI_MODE_ISO_8859_15:
            txt ="00010111";
      break;
      case QREciMode::QR_ECI_MODE_ISO_8859_16:
            txt ="00011000";
      break;
      case QREciMode::Shift_JIS:
            txt ="00100000";
      break;
      case QREciMode::UTF_8:
            txt ="00100110";
      break;
      default:
        break;
   }

   return txt;
 }

 const char * QrIndicator::getModeIndicator()
{
   QRVersion version = data->getqrversion();
   QRData coding = data->getdata_coding();

    if(data->isMicro )
    {
        if(version == QRVersion::QR_VERSION_M2 && coding == QRData::QR_DATA_NUMERIC)
            return "0";
        else if(version == QRVersion::QR_VERSION_M2 && coding==QRData::QR_DATA_ALPHANUMERIC)
            return "1";
        else if(version == QRVersion::QR_VERSION_M3 && coding == QRData::QR_DATA_NUMERIC)
            return "00";
        else if(version == QRVersion::QR_VERSION_M3 && coding==QRData::QR_DATA_ALPHANUMERIC)
            return "01";
        else if(version == QRVersion::QR_VERSION_M3 && coding== QRData::QR_DATA_BYTE)
            return "10";
        else if(version == QRVersion::QR_VERSION_M3 && coding==QRData::QR_DATA_KANJI)
            return "11";

        else if(version == QRVersion::QR_VERSION_M4 && coding == QRData::QR_DATA_NUMERIC)
            return "000";
        else if(version == QRVersion::QR_VERSION_M4 && coding==QRData::QR_DATA_ALPHANUMERIC)
            return "001";
        else if(version == QRVersion::QR_VERSION_M4 && coding== QRData::QR_DATA_BYTE)
            return "010";
        else if(version == QRVersion::QR_VERSION_M4 && coding==QRData::QR_DATA_KANJI)
            return "011";


        return "";
    }
    else
    {
        if(coding == QRData::QR_DATA_NUMERIC)
        {
            return "0001";
        }
        else if(coding==QRData::QR_DATA_ALPHANUMERIC)
        {
            return "0010";
        }
        else if(coding== QRData::QR_DATA_BYTE)
        {
            return "0100";
        }
        else if(coding==QRData::QR_DATA_KANJI)
        {
            return "1000";
        }
    }




   return "0001";
}
