#ifndef QRPARITY_HPP
#define QRPARITY_HPP
#include "QrDefinitions.hpp"

namespace GtkQR
{
  class QrParity
  {
    public:
        QrParity()= delete;

        static int getparity (QRDataContainer *data);

    protected:

    private:
  };
}



#endif // QRPARITY_HPP
