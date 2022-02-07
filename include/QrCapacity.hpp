#ifndef QRCAPACITY_H_INCLUDED
#define QRCAPACITY_H_INCLUDED
#include "QrDefinitions.hpp"

namespace GtkQR{

  class Capacity
  {
    public:
           Capacity(QRDataContainer *data);
           QRVersion getMinimumVersion(unsigned int);

    private:

        QRDataContainer *data;

        int getCapacity(QRVersion);
        int getCapacity_micro_QR(QRVersion);
        QRVersion getMinimumVersion_QR (unsigned int);
        QRVersion getMinimumVersion_micro_QR (unsigned int);

  };

}



#endif // QRCAPACITY_H_INCLUDED
