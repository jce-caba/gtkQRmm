#ifndef QRPROCESSES_HPP
#define QRPROCESSES_HPP
#include "QrDefinitions.hpp"
#include "QrDefinitions_Internal.hpp"
#include <string>
#include "QrMatrixFunction.hpp"
#include "QrAlignmentPatternLocations.hpp"
#include "QrMatrixData.hpp"
#include "QrMask.hpp"
#include "QrInformationStrings.hpp"
#include "QrErrorCorrection.hpp"
#include <memory>


namespace GtkQR
{

   class QrProcesses
   {
     public:
         QrProcesses(QRDataContainer *);
         ~QrProcesses();

         void QR_GetData(std::string &);
         char ** calculateMatrix(std::string & );


         void  encodeproces(std::shared_ptr<Dictionaries> );

     protected:

     private:

         void padding (QrErrorCorrection *);
         void  errorproces();

         QRDataContainer *data;
         std::string result;
         bool error;

   };



}


#endif // QRPROCESSES_HPP
