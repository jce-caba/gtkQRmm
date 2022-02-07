#ifndef QRVERSION_HPP
#define QRVERSION_HPP
#include "QrDefinitions.hpp"
namespace GtkQR
{
    class QrVersion
    {
     public:
         QrVersion()=delete;
         ~QrVersion() =delete;

         static int getnumbermodule(QRDataContainer *data);
         static int version_to_int(QRVersion);

     protected:

     private:
    };


}



#endif // QRVERSION_HPP
