#include "QrCapacity.hpp"

using namespace GtkQR;

Capacity::Capacity(QRDataContainer *_data)
{
   data=_data;
}

QRVersion Capacity::getMinimumVersion(unsigned int length)
{
    if(data->isMicro)
        return getMinimumVersion_micro_QR (length);
    else
        return getMinimumVersion_QR (length);
}


QRVersion Capacity::getMinimumVersion_micro_QR (unsigned int length)
{
  unsigned int value=0;
  QRVersion types[]={QRVersion::QR_VERSION_M1,QRVersion::QR_VERSION_M2,QRVersion::QR_VERSION_M3,QRVersion::QR_VERSION_M4};
  int a =-1;


  while(a < 3 && value<length)
  {
      a++;
      value = getCapacity_micro_QR(types[a]);
  }

  if(value >= length )
      return types[a];
  else
      return QRVersion::QR_VERSION_NULL;

}

QRVersion Capacity::getMinimumVersion_QR (unsigned int length)
{
   int a=0;
   unsigned int value=0;
   QRVersion types[]={QRVersion::QR_VERSION_1,QRVersion::QR_VERSION_2,QRVersion::QR_VERSION_3,QRVersion::QR_VERSION_4,QRVersion::QR_VERSION_5,QRVersion::QR_VERSION_6,QRVersion::QR_VERSION_7
  ,QRVersion::QR_VERSION_8,QRVersion::QR_VERSION_9,QRVersion::QR_VERSION_10,QRVersion::QR_VERSION_11,QRVersion::QR_VERSION_12,QRVersion::QR_VERSION_13,QRVersion::QR_VERSION_14,QRVersion::QR_VERSION_15,QRVersion::QR_VERSION_16,QRVersion::QR_VERSION_17,QRVersion::QR_VERSION_18,QRVersion::QR_VERSION_19,
  QRVersion::QR_VERSION_20,QRVersion::QR_VERSION_21,QRVersion::QR_VERSION_22,QRVersion::QR_VERSION_23,QRVersion::QR_VERSION_24,QRVersion::QR_VERSION_25,QRVersion::QR_VERSION_26,QRVersion::QR_VERSION_27,QRVersion::QR_VERSION_28,QRVersion::QR_VERSION_29,QRVersion::QR_VERSION_30,
  QRVersion::QR_VERSION_31,QRVersion::QR_VERSION_32,QRVersion::QR_VERSION_33,QRVersion::QR_VERSION_34,QRVersion::QR_VERSION_35,QRVersion::QR_VERSION_36,QRVersion::QR_VERSION_37,QRVersion::QR_VERSION_38,QRVersion::QR_VERSION_39,QRVersion::QR_VERSION_40,QRVersion::QR_VERSION_NULL};


   while( types[a] != QRVersion::QR_VERSION_NULL  && value<length)
   {
      value = getCapacity(types[a]);
      a ++;

   }

  if(value >= length )
      return types[a-1];
  else
      return QRVersion::QR_VERSION_NULL;
}

int Capacity::getCapacity(QRVersion _qrversion)
{
    QRData coding = data->getdata_coding();

    if(_qrversion==QRVersion::QR_VERSION_1){

        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 41;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 25;
          else if(coding==QRData::QR_DATA_BYTE)
                return 17;
          else if(coding==QRData::QR_DATA_KANJI)
                return 10;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 34;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 20;
          else if(coding==QRData::QR_DATA_BYTE)
                return 14;
          else if(coding==QRData::QR_DATA_KANJI)
                return 8;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 27;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 16;
          else if(coding==QRData::QR_DATA_BYTE)
                return 11;
          else if(coding==QRData::QR_DATA_KANJI)
                return 7;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 17;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 10;
          else if(coding==QRData::QR_DATA_BYTE)
                return 7;
          else if(coding==QRData::QR_DATA_KANJI)
                return 4;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_2){

        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 77;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 47;
          else if(coding==QRData::QR_DATA_BYTE)
                return 32;
          else if(coding==QRData::QR_DATA_KANJI)
                return 20;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 63;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 38;
          else if(coding==QRData::QR_DATA_BYTE)
                return 26;
          else if(coding==QRData::QR_DATA_KANJI)
                return 16;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 48;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 29;
          else if(coding==QRData::QR_DATA_BYTE)
                return 20;
          else if(coding==QRData::QR_DATA_KANJI)
                return 12;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 34;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 20;
          else if(coding==QRData::QR_DATA_BYTE)
                return 14;
          else if(coding==QRData::QR_DATA_KANJI)
                return 8;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_3){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 127;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 77;
          else if(coding==QRData::QR_DATA_BYTE)
                return 53;
          else if(coding==QRData::QR_DATA_KANJI)
                return 32;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 101;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 61;
          else if(coding==QRData::QR_DATA_BYTE)
                return 42;
          else if(coding==QRData::QR_DATA_KANJI)
                return 26;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 77;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 47;
          else if(coding==QRData::QR_DATA_BYTE)
                return 32;
          else if(coding==QRData::QR_DATA_KANJI)
                return 20;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 58;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 35;
          else if(coding==QRData::QR_DATA_BYTE)
                return 24;
          else if(coding==QRData::QR_DATA_KANJI)
                return 15;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_4){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 187;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 114;
          else if(coding==QRData::QR_DATA_BYTE)
                return 78;
          else if(coding==QRData::QR_DATA_KANJI)
                return 48;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 149;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 90;
          else if(coding==QRData::QR_DATA_BYTE)
                return 62;
          else if(coding==QRData::QR_DATA_KANJI)
                return 38;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 111;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 67;
          else if(coding==QRData::QR_DATA_BYTE)
                return 46;
          else if(coding==QRData::QR_DATA_KANJI)
                return 28;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 82;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 50;
          else if(coding==QRData::QR_DATA_BYTE)
                return 34;
          else if(coding==QRData::QR_DATA_KANJI)
                return 21;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_5){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 255;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 154;
          else if(coding==QRData::QR_DATA_BYTE)
                return 106;
          else if(coding==QRData::QR_DATA_KANJI)
                return 65;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 202;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 122;
          else if(coding==QRData::QR_DATA_BYTE)
                return 84;
          else if(coding==QRData::QR_DATA_KANJI)
                return 52;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 144;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 87;
          else if(coding==QRData::QR_DATA_BYTE)
                return 60;
          else if(coding==QRData::QR_DATA_KANJI)
                return 37;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 106;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 64;
          else if(coding==QRData::QR_DATA_BYTE)
                return 44;
          else if(coding==QRData::QR_DATA_KANJI)
                return 27;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_6){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 322;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 195;
          else if(coding==QRData::QR_DATA_BYTE)
                return 134;
          else if(coding==QRData::QR_DATA_KANJI)
                return 82;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 255;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 154;
          else if(coding==QRData::QR_DATA_BYTE)
                return 106;
          else if(coding==QRData::QR_DATA_KANJI)
                return 65;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 178;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 108;
          else if(coding==QRData::QR_DATA_BYTE)
                return 74;
          else if(coding==QRData::QR_DATA_KANJI)
                return 45;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 139;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 84;
          else if(coding==QRData::QR_DATA_BYTE)
                return 58;
          else if(coding==QRData::QR_DATA_KANJI)
                return 36;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_7){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 370;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 224;
          else if(coding==QRData::QR_DATA_BYTE)
                return 154;
          else if(coding==QRData::QR_DATA_KANJI)
                return 95;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 293;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 178;
          else if(coding==QRData::QR_DATA_BYTE)
                return 122;
          else if(coding==QRData::QR_DATA_KANJI)
                return 75;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 207;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 125;
          else if(coding==QRData::QR_DATA_BYTE)
                return 86;
          else if(coding==QRData::QR_DATA_KANJI)
                return 53;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 154;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 93;
          else if(coding==QRData::QR_DATA_BYTE)
                return 64;
          else if(coding==QRData::QR_DATA_KANJI)
                return 39;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_8){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 461;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 279;
          else if(coding==QRData::QR_DATA_BYTE)
                return 192;
          else if(coding==QRData::QR_DATA_KANJI)
                return 118;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 365;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 221;
          else if(coding==QRData::QR_DATA_BYTE)
                return 152;
          else if(coding==QRData::QR_DATA_KANJI)
                return 93;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 259;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 157;
          else if(coding==QRData::QR_DATA_BYTE)
                return 108;
          else if(coding==QRData::QR_DATA_KANJI)
                return 66;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 202;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 122;
          else if(coding==QRData::QR_DATA_BYTE)
                return 84;
          else if(coding==QRData::QR_DATA_KANJI)
                return 52;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_9){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 552;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 335;
          else if(coding==QRData::QR_DATA_BYTE)
                return 230;
          else if(coding==QRData::QR_DATA_KANJI)
                return 141;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 432;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 262;
          else if(coding==QRData::QR_DATA_BYTE)
                return 180;
          else if(coding==QRData::QR_DATA_KANJI)
                return 111;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 312;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 189;
          else if(coding==QRData::QR_DATA_BYTE)
                return 130;
          else if(coding==QRData::QR_DATA_KANJI)
                return 80;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 235;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 143;
          else if(coding==QRData::QR_DATA_BYTE)
                return 98;
          else if(coding==QRData::QR_DATA_KANJI)
                return 60;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_10){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 652;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 395;
          else if(coding==QRData::QR_DATA_BYTE)
                return 271;
          else if(coding==QRData::QR_DATA_KANJI)
                return 167;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 513;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 311;
          else if(coding==QRData::QR_DATA_BYTE)
                return 213;
          else if(coding==QRData::QR_DATA_KANJI)
                return 131;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 364;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 221;
          else if(coding==QRData::QR_DATA_BYTE)
                return 151;
          else if(coding==QRData::QR_DATA_KANJI)
                return 93;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 288;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 174;
          else if(coding==QRData::QR_DATA_BYTE)
                return 119;
          else if(coding==QRData::QR_DATA_KANJI)
                return 74;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_11){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 772;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 468;
          else if(coding==QRData::QR_DATA_BYTE)
                return 321;
          else if(coding==QRData::QR_DATA_KANJI)
                return 198;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 604;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 366;
          else if(coding==QRData::QR_DATA_BYTE)
                return 251;
          else if(coding==QRData::QR_DATA_KANJI)
                return 155;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 427;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 259;
          else if(coding==QRData::QR_DATA_BYTE)
                return 177;
          else if(coding==QRData::QR_DATA_KANJI)
                return 109;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 331;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 200;
          else if(coding==QRData::QR_DATA_BYTE)
                return 137;
          else if(coding==QRData::QR_DATA_KANJI)
                return 85;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_12){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 883;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 535;
          else if(coding==QRData::QR_DATA_BYTE)
                return 367;
          else if(coding==QRData::QR_DATA_KANJI)
                return 226;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 691;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 419;
          else if(coding==QRData::QR_DATA_BYTE)
                return 287;
          else if(coding==QRData::QR_DATA_KANJI)
                return 177;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 489;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 296;
          else if(coding==QRData::QR_DATA_BYTE)
                return 203;
          else if(coding==QRData::QR_DATA_KANJI)
                return 125;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 374;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 227;
          else if(coding==QRData::QR_DATA_BYTE)
                return 155;
          else if(coding==QRData::QR_DATA_KANJI)
                return 96;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_13){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1022;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 619;
          else if(coding==QRData::QR_DATA_BYTE)
                return 425;
          else if(coding==QRData::QR_DATA_KANJI)
                return 262;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 796;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 483;
          else if(coding==QRData::QR_DATA_BYTE)
                return 331;
          else if(coding==QRData::QR_DATA_KANJI)
                return 204;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 580;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 352;
          else if(coding==QRData::QR_DATA_BYTE)
                return 241;
          else if(coding==QRData::QR_DATA_KANJI)
                return 149;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 427;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 259;
          else if(coding==QRData::QR_DATA_BYTE)
                return 177;
          else if(coding==QRData::QR_DATA_KANJI)
                return 109;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_14){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1101;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 667;
          else if(coding==QRData::QR_DATA_BYTE)
                return 458;
          else if(coding==QRData::QR_DATA_KANJI)
                return 282;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 871;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 528;
          else if(coding==QRData::QR_DATA_BYTE)
                return 362;
          else if(coding==QRData::QR_DATA_KANJI)
                return 223;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 621;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 376;
          else if(coding==QRData::QR_DATA_BYTE)
                return 258;
          else if(coding==QRData::QR_DATA_KANJI)
                return 159;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 468;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 283;
          else if(coding==QRData::QR_DATA_BYTE)
                return 194;
          else if(coding==QRData::QR_DATA_KANJI)
                return 120;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_15){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1250;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 758;
          else if(coding==QRData::QR_DATA_BYTE)
                return 520;
          else if(coding==QRData::QR_DATA_KANJI)
                return 320;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 991;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 600;
          else if(coding==QRData::QR_DATA_BYTE)
                return 412;
          else if(coding==QRData::QR_DATA_KANJI)
                return 254;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 703;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 426;
          else if(coding==QRData::QR_DATA_BYTE)
                return 292;
          else if(coding==QRData::QR_DATA_KANJI)
                return 180;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 530;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 321;
          else if(coding==QRData::QR_DATA_BYTE)
                return 220;
          else if(coding==QRData::QR_DATA_KANJI)
                return 136;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_16){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1408;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 854;
          else if(coding==QRData::QR_DATA_BYTE)
                return 586;
          else if(coding==QRData::QR_DATA_KANJI)
                return 361;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1082;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 656;
          else if(coding==QRData::QR_DATA_BYTE)
                return 450;
          else if(coding==QRData::QR_DATA_KANJI)
                return 277;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 775;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 470;
          else if(coding==QRData::QR_DATA_BYTE)
                return 322;
          else if(coding==QRData::QR_DATA_KANJI)
                return 198;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 602;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 365;
          else if(coding==QRData::QR_DATA_BYTE)
                return 250;
          else if(coding==QRData::QR_DATA_KANJI)
                return 154;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_17){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1548;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 938;
          else if(coding==QRData::QR_DATA_BYTE)
                return 644;
          else if(coding==QRData::QR_DATA_KANJI)
                return 397;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1212;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 734;
          else if(coding==QRData::QR_DATA_BYTE)
                return 504;
          else if(coding==QRData::QR_DATA_KANJI)
                return 310;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 876;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 531;
          else if(coding==QRData::QR_DATA_BYTE)
                return 364;
          else if(coding==QRData::QR_DATA_KANJI)
                return 224;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 674;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 408;
          else if(coding==QRData::QR_DATA_BYTE)
                return 280;
          else if(coding==QRData::QR_DATA_KANJI)
                return 173;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_18){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1725;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1046;
          else if(coding==QRData::QR_DATA_BYTE)
                return 718;
          else if(coding==QRData::QR_DATA_KANJI)
                return 442;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1346;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 816;
          else if(coding==QRData::QR_DATA_BYTE)
                return 560;
          else if(coding==QRData::QR_DATA_KANJI)
                return 345;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 948;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 574;
          else if(coding==QRData::QR_DATA_BYTE)
                return 394;
          else if(coding==QRData::QR_DATA_KANJI)
                return 243;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 746;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 452;
          else if(coding==QRData::QR_DATA_BYTE)
                return 310;
          else if(coding==QRData::QR_DATA_KANJI)
                return 191;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_19){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1903;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1153;
          else if(coding==QRData::QR_DATA_BYTE)
                return 792;
          else if(coding==QRData::QR_DATA_KANJI)
                return 488;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1500;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 909;
          else if(coding==QRData::QR_DATA_BYTE)
                return 624;
          else if(coding==QRData::QR_DATA_KANJI)
                return 384;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1063;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 644;
          else if(coding==QRData::QR_DATA_BYTE)
                return 442;
          else if(coding==QRData::QR_DATA_KANJI)
                return 272;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 813;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 493;
          else if(coding==QRData::QR_DATA_BYTE)
                return 338;
          else if(coding==QRData::QR_DATA_KANJI)
                return 208;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_20){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2061;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1249;
          else if(coding==QRData::QR_DATA_BYTE)
                return 858;
          else if(coding==QRData::QR_DATA_KANJI)
                return 528;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1600;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 970;
          else if(coding==QRData::QR_DATA_BYTE)
                return 666;
          else if(coding==QRData::QR_DATA_KANJI)
                return 410;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1159;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 702;
          else if(coding==QRData::QR_DATA_BYTE)
                return 482;
          else if(coding==QRData::QR_DATA_KANJI)
                return 297;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 919;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 557;
          else if(coding==QRData::QR_DATA_BYTE)
                return 382;
          else if(coding==QRData::QR_DATA_KANJI)
                return 235;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_21){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2232;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1352;
          else if(coding==QRData::QR_DATA_BYTE)
                return 929;
          else if(coding==QRData::QR_DATA_KANJI)
                return 572;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1708;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1035;
          else if(coding==QRData::QR_DATA_BYTE)
                return 711;
          else if(coding==QRData::QR_DATA_KANJI)
                return 438;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1224;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 742;
          else if(coding==QRData::QR_DATA_BYTE)
                return 509;
          else if(coding==QRData::QR_DATA_KANJI)
                return 314;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 969;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 587;
          else if(coding==QRData::QR_DATA_BYTE)
                return 403;
          else if(coding==QRData::QR_DATA_KANJI)
                return 248;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_22){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2409;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1460;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1003;
          else if(coding==QRData::QR_DATA_KANJI)
                return 618;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1872;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1134;
          else if(coding==QRData::QR_DATA_BYTE)
                return 779;
          else if(coding==QRData::QR_DATA_KANJI)
                return 480;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1358;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 823;
          else if(coding==QRData::QR_DATA_BYTE)
                return 565;
          else if(coding==QRData::QR_DATA_KANJI)
                return 348;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1056;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 640;
          else if(coding==QRData::QR_DATA_BYTE)
                return 439;
          else if(coding==QRData::QR_DATA_KANJI)
                return 270;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_23){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2620;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1588;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1091;
          else if(coding==QRData::QR_DATA_KANJI)
                return 672;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2059;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1248;
          else if(coding==QRData::QR_DATA_BYTE)
                return 857;
          else if(coding==QRData::QR_DATA_KANJI)
                return 528;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1468;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 890;
          else if(coding==QRData::QR_DATA_BYTE)
                return 611;
          else if(coding==QRData::QR_DATA_KANJI)
                return 376;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1108;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 672;
          else if(coding==QRData::QR_DATA_BYTE)
                return 461;
          else if(coding==QRData::QR_DATA_KANJI)
                return 284;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_24){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2812;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1704;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1171;
          else if(coding==QRData::QR_DATA_KANJI)
                return 721;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2188;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1326;
          else if(coding==QRData::QR_DATA_BYTE)
                return 911;
          else if(coding==QRData::QR_DATA_KANJI)
                return 561;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1588;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 963;
          else if(coding==QRData::QR_DATA_BYTE)
                return 661;
          else if(coding==QRData::QR_DATA_KANJI)
                return 407;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1228;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 744;
          else if(coding==QRData::QR_DATA_BYTE)
                return 511;
          else if(coding==QRData::QR_DATA_KANJI)
                return 315;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_25){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 3057;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1853;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1273;
          else if(coding==QRData::QR_DATA_KANJI)
                return 784;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2395;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1451;
          else if(coding==QRData::QR_DATA_BYTE)
                return 997;
          else if(coding==QRData::QR_DATA_KANJI)
                return 614;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1718;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1041;
          else if(coding==QRData::QR_DATA_BYTE)
                return 715;
          else if(coding==QRData::QR_DATA_KANJI)
                return 440;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1286;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 779;
          else if(coding==QRData::QR_DATA_BYTE)
                return 535;
          else if(coding==QRData::QR_DATA_KANJI)
                return 330;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_26){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 3283;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1990;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1367;
          else if(coding==QRData::QR_DATA_KANJI)
                return 842;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2544;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1542;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1059;
          else if(coding==QRData::QR_DATA_KANJI)
                return 652;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1804;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1094;
          else if(coding==QRData::QR_DATA_BYTE)
                return 751;
          else if(coding==QRData::QR_DATA_KANJI)
                return 462;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1425;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 864;
          else if(coding==QRData::QR_DATA_BYTE)
                return 593;
          else if(coding==QRData::QR_DATA_KANJI)
                return 365;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_27){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 3517;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 2132;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1465;
          else if(coding==QRData::QR_DATA_KANJI)
                return 902;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2701;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1637;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1125;
          else if(coding==QRData::QR_DATA_KANJI)
                return 692;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1933;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1172;
          else if(coding==QRData::QR_DATA_BYTE)
                return 805;
          else if(coding==QRData::QR_DATA_KANJI)
                return 496;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1501;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 910;
          else if(coding==QRData::QR_DATA_BYTE)
                return 625;
          else if(coding==QRData::QR_DATA_KANJI)
                return 385;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_28){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 3669;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 2223;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1528;
          else if(coding==QRData::QR_DATA_KANJI)
                return 940;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2857;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1732;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1190;
          else if(coding==QRData::QR_DATA_KANJI)
                return 732;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2085;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1263;
          else if(coding==QRData::QR_DATA_BYTE)
                return 868;
          else if(coding==QRData::QR_DATA_KANJI)
                return 534;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1581;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 958;
          else if(coding==QRData::QR_DATA_BYTE)
                return 658;
          else if(coding==QRData::QR_DATA_KANJI)
                return 405;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_29){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 3909;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 2369;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1628;
          else if(coding==QRData::QR_DATA_KANJI)
                return 1002;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 3035;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1839;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1264;
          else if(coding==QRData::QR_DATA_KANJI)
                return 778;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2181;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1322;
          else if(coding==QRData::QR_DATA_BYTE)
                return 908;
          else if(coding==QRData::QR_DATA_KANJI)
                return 559;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1677;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1016;
          else if(coding==QRData::QR_DATA_BYTE)
                return 698;
          else if(coding==QRData::QR_DATA_KANJI)
                return 430;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_30){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 4158;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 2520;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1732;
          else if(coding==QRData::QR_DATA_KANJI)
                return 1066;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 3289;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1994;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1370;
          else if(coding==QRData::QR_DATA_KANJI)
                return 843;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2358;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1429;
          else if(coding==QRData::QR_DATA_BYTE)
                return 982;
          else if(coding==QRData::QR_DATA_KANJI)
                return 604;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1782;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1080;
          else if(coding==QRData::QR_DATA_BYTE)
                return 742;
          else if(coding==QRData::QR_DATA_KANJI)
                return 457;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_31){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 4417;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 2677;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1840;
          else if(coding==QRData::QR_DATA_KANJI)
                return 1132;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 3486;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 2113;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1452;
          else if(coding==QRData::QR_DATA_KANJI)
                return 894;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2473;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1499;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1030;
          else if(coding==QRData::QR_DATA_KANJI)
                return 634;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 1897;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1150;
          else if(coding==QRData::QR_DATA_BYTE)
                return 790;
          else if(coding==QRData::QR_DATA_KANJI)
                return 486;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_32){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 4686;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 2840;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1952;
          else if(coding==QRData::QR_DATA_KANJI)
                return 1201;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 3693;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 2238;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1538;
          else if(coding==QRData::QR_DATA_KANJI)
                return 947;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2670;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1618;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1112;
          else if(coding==QRData::QR_DATA_KANJI)
                return 684;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2022;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1226;
          else if(coding==QRData::QR_DATA_BYTE)
                return 842;
          else if(coding==QRData::QR_DATA_KANJI)
                return 518;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_33){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 4965;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 3009;
          else if(coding==QRData::QR_DATA_BYTE)
                return 2068;
          else if(coding==QRData::QR_DATA_KANJI)
                return 1273;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 3909;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 2369;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1628;
          else if(coding==QRData::QR_DATA_KANJI)
                return 1002;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2805;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1700;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1168;
          else if(coding==QRData::QR_DATA_KANJI)
                return 719;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2157;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1307;
          else if(coding==QRData::QR_DATA_BYTE)
                return 898;
          else if(coding==QRData::QR_DATA_KANJI)
                return 553;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_34){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 5253;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 3183;
          else if(coding==QRData::QR_DATA_BYTE)
                return 2188;
          else if(coding==QRData::QR_DATA_KANJI)
                return 1347;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 4134;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 2506;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1722;
          else if(coding==QRData::QR_DATA_KANJI)
                return 1060;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2949;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1787;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1228;
          else if(coding==QRData::QR_DATA_KANJI)
                return 756;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2301;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1394;
          else if(coding==QRData::QR_DATA_BYTE)
                return 958;
          else if(coding==QRData::QR_DATA_KANJI)
                return 590;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_35){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 5529;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 3351;
          else if(coding==QRData::QR_DATA_BYTE)
                return 2303;
          else if(coding==QRData::QR_DATA_KANJI)
                return 1417;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 4343;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 2632;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1809;
          else if(coding==QRData::QR_DATA_KANJI)
                return 1113;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 3081;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1867;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1283;
          else if(coding==QRData::QR_DATA_KANJI)
                return 790;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2361;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1431;
          else if(coding==QRData::QR_DATA_BYTE)
                return 983;
          else if(coding==QRData::QR_DATA_KANJI)
                return 605;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_36){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 5836;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 3537;
          else if(coding==QRData::QR_DATA_BYTE)
                return 2431;
          else if(coding==QRData::QR_DATA_KANJI)
                return 1496;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 4588;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 2780;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1911;
          else if(coding==QRData::QR_DATA_KANJI)
                return 1176;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 3244;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1966;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1351;
          else if(coding==QRData::QR_DATA_KANJI)
                return 832;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2524;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1530;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1051;
          else if(coding==QRData::QR_DATA_KANJI)
                return 647;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_37){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 6153;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 3729;
          else if(coding==QRData::QR_DATA_BYTE)
                return 2563;
          else if(coding==QRData::QR_DATA_KANJI)
                return 1577;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 4775;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 2894;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1989;
          else if(coding==QRData::QR_DATA_KANJI)
                return 1224;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 3417;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 2071;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1423;
          else if(coding==QRData::QR_DATA_KANJI)
                return 876;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2625;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1591;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1093;
          else if(coding==QRData::QR_DATA_KANJI)
                return 673;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_38){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 6479;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 3927;
          else if(coding==QRData::QR_DATA_BYTE)
                return 2699;
          else if(coding==QRData::QR_DATA_KANJI)
                return 1661;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 5039;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 3054;
          else if(coding==QRData::QR_DATA_BYTE)
                return 2099;
          else if(coding==QRData::QR_DATA_KANJI)
                return 1292;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 3599;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 2181;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1499;
          else if(coding==QRData::QR_DATA_KANJI)
                return 923;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2735;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1658;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1139;
          else if(coding==QRData::QR_DATA_KANJI)
                return 701;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_39){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 6743;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 4087;
          else if(coding==QRData::QR_DATA_BYTE)
                return 2809;
          else if(coding==QRData::QR_DATA_KANJI)
                return 1729;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 5313;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 3220;
          else if(coding==QRData::QR_DATA_BYTE)
                return 2213;
          else if(coding==QRData::QR_DATA_KANJI)
                return 1362;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 3791;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 2298;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1579;
          else if(coding==QRData::QR_DATA_KANJI)
                return 972;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 2927;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1774;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1219;
          else if(coding==QRData::QR_DATA_KANJI)
                return 750;
        }
    }
    else if(_qrversion==QRVersion::QR_VERSION_40){
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 7089;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 4296;
          else if(coding==QRData::QR_DATA_BYTE)
                return 2953;
          else if(coding==QRData::QR_DATA_KANJI)
                return 1817;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 5596;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 3391;
          else if(coding==QRData::QR_DATA_BYTE)
                return 2331;
          else if(coding==QRData::QR_DATA_KANJI)
                return 1435;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 3993;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 2420;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1663;
          else if(coding==QRData::QR_DATA_KANJI)
                return 1024;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 3057;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 1852;
          else if(coding==QRData::QR_DATA_BYTE)
                return 1273;
          else if(coding==QRData::QR_DATA_KANJI)
                return 784;
        }
    }


  return 0;
}

int Capacity::getCapacity_micro_QR(QRVersion _qrversion)
{
  QRData coding = data->getdata_coding();

  if(_qrversion ==QRVersion::QR_VERSION_M1 && coding==QRData::QR_DATA_NUMERIC && data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_NOTHING )
               return 5;
  else if (_qrversion ==QRVersion::QR_VERSION_M2)
  {
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){

          if(coding==QRData::QR_DATA_NUMERIC)
                return 10;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 6;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){

          if(coding==QRData::QR_DATA_NUMERIC)
                return 8;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 5;

        }

  }
  else if (_qrversion ==QRVersion::QR_VERSION_M3)
  {
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 23;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 14;
          else if(coding==QRData::QR_DATA_BYTE)
                return 9;
          else if(coding==QRData::QR_DATA_KANJI)
                return 6;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 18;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 11;
          else if(coding==QRData::QR_DATA_BYTE)
                return 7;
          else if(coding==QRData::QR_DATA_KANJI)
                return 4;
        }
  }
  else if (_qrversion ==QRVersion::QR_VERSION_M4)
  {
        if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 35;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 21;
          else if(coding==QRData::QR_DATA_BYTE)
                return 15;
          else if(coding==QRData::QR_DATA_KANJI)
                return 9;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 30;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 18;
          else if(coding==QRData::QR_DATA_BYTE)
                return 13;
          else if(coding==QRData::QR_DATA_KANJI)
                return 8;
        }
        else if(data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY){
          if(coding==QRData::QR_DATA_NUMERIC)
                return 21;
          else if(coding== QRData::QR_DATA_ALPHANUMERIC)
                return 13;
          else if(coding==QRData::QR_DATA_BYTE)
                return 9;
          else if(coding==QRData::QR_DATA_KANJI)
                return 5;
        }

  }



  return 0;
}
