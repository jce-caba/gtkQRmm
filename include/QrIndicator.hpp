#ifndef QRINDICATOR_HPP
#define QRINDICATOR_HPP
#include "QrDefinitions_Internal.hpp"
#include "QrDefinitions.hpp"


namespace GtkQR
{

   class QrIndicator
   {
     public:
        QrIndicator(QRDataContainer *);
        virtual ~QrIndicator();

        const char * getModeIndicator();
        const char * getEciAssignament(Dictionary *,int);
        const char * getEciIndicator(Dictionary *,int);

     protected:

     private:
         QRDataContainer    *data;

   };


}



#endif // QRINDICATOR_HPP
