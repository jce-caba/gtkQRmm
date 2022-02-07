#include "QrProcesses.hpp"
#include "QrDataAnalysis.hpp"
#include "QrCapacity.hpp"
#include "QrVersion.hpp"
#include "QrIndicator.hpp"
#include "Qrlistutils.hpp"
#include "QrCharacterCountIndicator.hpp"
#include "QrConversions.hpp"
#include "QrEncode.hpp"
#include "QrErrorCorrection.hpp"
#include "QrTerminator.hpp"
#include "QrParity.hpp"
#include "QrPadding.hpp"
#include "Qrerrorcorrectioncoding.hpp"

using namespace GtkQR;

QrProcesses::QrProcesses(QRDataContainer *_data)
{
    data = _data;
    error =false;
}

QrProcesses::~QrProcesses()
{
    //dtor
}

char ** QrProcesses::calculateMatrix(std::string &text )
{
   QrMask qrmask;
   QrMatrixData matrdata(nullptr,nullptr);

   char **matrix_function_QR;
   char **matrix_QR;
   char **final_matrix_QR;
   std ::string format;

   QR_GetData(text);

   if(error)
        return nullptr;

   matrdata.setParameters(result.c_str(),data);

   matrix_function_QR = QrMatrixFunction::getMatrixFunction(data);

   QrAlignmentPatternLocations::getAlignment(data,matrix_function_QR);
   matrix_QR = matrdata.getMatrixData();

   qrmask.setParameters(const_cast<const char **>(matrix_QR),const_cast<const char **>(matrix_function_QR),data);
   final_matrix_QR =qrmask.getMaskMatrix();
   QrMatrixUtils::freeMatrix(matrix_QR);
   QrMatrixUtils::freeMatrix(matrix_function_QR);

    if(data->qrversion_number >= 7)
    {
        format = QrInformationStrings::getVersionInformation(data);
        QrMatrixFunction::setMatrixFunctionVersion(final_matrix_QR,data,format);
    }


    format = QrInformationStrings::getFormatInformation(data);
    QrMatrixFunction::setMatrixFunctionFormat(final_matrix_QR,data,format);

    return final_matrix_QR;
}


void QrProcesses::QR_GetData(std::string &text )
{

    QrDataAnalysis analysis(data);
    Capacity capacity(data);
    std::list<Dictionary *>::iterator it;
    std::shared_ptr<Dictionaries> dictionary;


    dictionary = std::shared_ptr<Dictionaries> (analysis.analyze_data(text));



    if (dictionary->error )
    {
       data->qrversion = QRVersion::QR_VERSION_NULL;
       data->qrversion_number = QR_NO_VERSION;
       data->error = "character set invalid";
       data->warning.clear();
       data->eci_mode.clear() ;
       data->num_eci_mode = 0;
       error =true;
       return ;
    }
    else if(dictionary->total_data==0)
    {
       data->qrversion_number = QR_NO_VERSION;
       data->qrversion = QRVersion::QR_VERSION_NULL;
       data->error = "No data input";
       data->warning.clear();
       data->eci_mode.clear() ;
       data->num_eci_mode = 0;
       error =true;
       return;
    }

    if(data->isMicro && data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH)
    {
        data->correction_level = QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY;
        data->warning = "change correction level H to Q";
    }
    else if(!data->isMicro && data->correction_level == QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_NOTHING)
    {
        data->correction_level = QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW;
        data->warning = "change correction level Nothing to Low";
    }


    it = dictionary->dictionaries.begin();

    data->data_coding = (*it)->coding;
    data->qrversion = capacity.getMinimumVersion(dictionary->total_data);

    if (data->qrversion == QRVersion::QR_VERSION_NULL ) {
       data->qrversion_number = QR_NO_VERSION;
       data->error = "too many characters";
       data->warning.clear() ;
       data->eci_mode.clear() ;
       data->num_eci_mode = 0;

       error =true;
       return ;
    }


    if(dictionary->_num_dictionaries==1 && (*it)->eci_mode != QREciMode::QR_ECI_MODE_ISO_8859_1)
    {
        data->eci_mode.clear() ;
        data->eci_mode.push_back ((*it)->eci_mode);
        data->num_eci_mode = 1;
    }
    else if(dictionary->_num_dictionaries>1)
    {
        data->eci_mode.clear() ;
        data->num_eci_mode = dictionary->_num_dictionaries;

        for (std::list<Dictionary *>::iterator it2=dictionary->dictionaries.begin(); it2 != dictionary->dictionaries.end(); ++it2)
                       data->eci_mode.push_back ((*it2)->eci_mode);


    }
    else
    {
        data->eci_mode.clear() ;
        data->num_eci_mode = 0;
    }


    data->qrversion_number = QrVersion::version_to_int(data->qrversion);
    data->num_modules = QrVersion::getnumbermodule(data);
    encodeproces(dictionary);





}


void  QrProcesses::encodeproces(std::shared_ptr<Dictionaries> dictionary)
{
    QrErrorCorrection errorcorrection(data);
    QrIndicator indicador(data);
    std::string aux;
    Dictionary *Dc;
    int value;

    for (unsigned int i = 0 ; i< dictionary->_num_dictionaries ; i ++)
    {
        Dc= Qrlistutils::getelement(dictionary->dictionaries ,i);
        aux = indicador.getEciIndicator(Dc,i);
        result.append(aux);
        aux = indicador.getEciAssignament(Dc,i);
        result.append(aux);

        aux = indicador.getModeIndicator();
        result.append(aux);

        value = QrCharacterCountIndicator::getCharacterCountIndicator(data);

        Conversion::toBinary_n_bits(aux,Dc->size_data,value);
        result.append(aux);


        switch(data->data_coding)
        {

        case QRData::QR_DATA_BYTE:
            aux= QrEncode::encondeISO_8859_1( static_cast<int *>(Dc->data) , Dc->size_data );

            break;
        case QRData::QR_DATA_KANJI :
            aux= QrEncode::encondeKanji( static_cast<int *>(Dc->data) , Dc->size_data );
            break;
        case QRData::QR_DATA_NUMERIC:
            aux= QrEncode::encondeNumeric(reinterpret_cast<std::string *>(Dc->data));
            break;
        case QRData::QR_DATA_ALPHANUMERIC:
            aux= QrEncode::encondeAlphaNumeric(static_cast<std::string *>(Dc->data));
            break;
        default:

            break;
        }

        result.append(aux);

    }

    padding(&errorcorrection);
    errorproces();

}

 void QrProcesses::padding (QrErrorCorrection *error_correction)
 {
    std::string aux;
    int lg,lg2;
    int auxInt;
    int parity;

    lg = error_correction->getDataBits ();
    lg2 = result.size();

    auxInt = QrTerminator::getTerminator(data);
    if(lg>=lg2 + auxInt)
    {
      parity =QrParity::getparity(data);
      while((lg2+auxInt) % parity != 0 )
                  auxInt++;

      for(int i=0;i<auxInt;i++)
                       result.append("0");


      lg2 = lg2 +auxInt;
      if(lg > lg2)
      {
          lg = (lg-lg2) /parity ;
          aux= PadBytes::pad(data,lg);
          result.append(aux);
      }
    }
    else
    {
         auxInt =lg-lg2;
         if(auxInt > 0)
         {
            for(int i=0;i<auxInt;i++)
                                result.append("0");
         }

    }


 }

 void  QrProcesses::errorproces()
{
   Qrerrorcorrectioncoding errorcorrection(result,data);
   result = errorcorrection.getResult();


}



