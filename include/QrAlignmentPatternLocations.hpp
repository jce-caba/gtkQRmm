#ifndef QRALIGNMENTPATTERNLOCATIONS_HPP
#define QRALIGNMENTPATTERNLOCATIONS_HPP
#include "QrDefinitions.hpp"

namespace GtkQR
{

   class QrAlignmentPatternLocations
   {
      public:
        QrAlignmentPatternLocations();
        ~QrAlignmentPatternLocations();

        static void  getAlignment(QRDataContainer *data,char **matrix);
        static int   getNumberElements(int);
        static void  getSeparation(int,int *);

      protected:


      private:

        static void  setpointmatrix(char **,int,int);


   };

}



#endif // QRALIGNMENTPATTERNLOCATIONS_HPP
