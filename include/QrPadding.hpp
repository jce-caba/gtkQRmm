#ifndef QRDATATABLES_H_INCLUDED
#define QRDATATABLES_H_INCLUDED
#include <stdlib.h>
#include <string>
#include "QrDefinitions.hpp"
#include "QrParity.hpp"

namespace GtkQR
{
    class PadBytes
    {
        public :

          PadBytes() =delete;
          static std::string pad(QRDataContainer *data,unsigned int);

        private:

          static void padBytesQR(int,std::string &);
          static void padBytesMicro(int,std::string &);
    };


}




#endif // QRDATATABLES_H_INCLUDED
