#ifndef QRTERMINATOR_HPP
#define QRTERMINATOR_HPP
#include "QrDefinitions.hpp"

namespace GtkQR
{
   class QrTerminator
   {
    public:
        QrTerminator();
        ~QrTerminator();
        static int getTerminator(QRDataContainer *);

    protected:

    private:
   };


}



#endif // QRTERMINATOR_HPP
