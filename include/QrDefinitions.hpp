#ifndef Qr_Definitions_HCPP_INCLUDED
#define Qr_Definitions_HCPP_INCLUDED
#include <string>
#include <list>
#include <memory>
#include <functional>


 /** \brief namespace GtkQR
 */
namespace GtkQR
{
   #ifndef QRPROCESSES_HPP
    class QrProcesses;
   #endif


   #ifndef QRMASK_HPP
    class QrMask;
   #endif


 /** \brief No version number
 */
 constexpr unsigned short QR_NO_VERSION = 41;

 /** \brief version number M1
 */
 constexpr short QR_VERSION_NUMBER_M1 = -4;

 /** \brief version number M2
 */
 constexpr short QR_VERSION_NUMBER_M2 = -3;

 /** \brief version number M3
 */
 constexpr short QR_VERSION_NUMBER_M3 = -2;

 /** \brief version number M4
 */
 constexpr short QR_VERSION_NUMBER_M4 = -1;

 /** \brief No mask applied
 */
 constexpr short QR_NO_MASK = -5;


 /** \brief Selectable error correction
 */
enum class QRErrorCorrectionLevel
{
    QR_ERROR_CORRECTION_LEVEL_LOW, /**< allowing recovery 7% codewords  */
    QR_ERROR_CORRECTION_LEVEL_MEDIUM,/**< allowing recovery 15% codewords  */
    QR_ERROR_CORRECTION_LEVEL_QUALITY,/**< allowing recovery 25% codewords  */
    QR_ERROR_CORRECTION_LEVEL_HIGH,/**< allowing recovery 30% codewords ,\n not available in micro QR */
    QR_ERROR_CORRECTION_LEVEL_NOTHING /**< error detection only \n in version M1 micro QR  */
};


 /** \brief QR and micro QR versions
 */
enum class QRVersion {QR_VERSION_M1,QR_VERSION_M2,QR_VERSION_M3,QR_VERSION_M4,
                      QR_VERSION_1,QR_VERSION_2,QR_VERSION_3,QR_VERSION_4,QR_VERSION_5,QR_VERSION_6,QR_VERSION_7
,QR_VERSION_8,QR_VERSION_9,QR_VERSION_10,QR_VERSION_11,QR_VERSION_12,QR_VERSION_13,QR_VERSION_14,QR_VERSION_15,QR_VERSION_16,QR_VERSION_17,QR_VERSION_18,QR_VERSION_19,
QR_VERSION_20,QR_VERSION_21,QR_VERSION_22,QR_VERSION_23,QR_VERSION_24,QR_VERSION_25,QR_VERSION_26,QR_VERSION_27,QR_VERSION_28,QR_VERSION_29,QR_VERSION_30,
QR_VERSION_31,QR_VERSION_32,QR_VERSION_33,QR_VERSION_34,QR_VERSION_35,QR_VERSION_36,QR_VERSION_37,QR_VERSION_38,QR_VERSION_39,QR_VERSION_40,QR_VERSION_NULL
                     } ;


 /** \brief Character set types in text
 */
enum class QRData {QR_DATA_NUMERIC, /*!< The data only contains the digits 0 to 9  */
                   QR_DATA_ALPHANUMERIC, /*!< The data only contains digits 0 - 9; upper case letters A -Z; nine other characters: space, $ % * + - . / :  */
                   QR_DATA_BYTE, /*!< The data only contains ISO/IEC 8859-1 */
                   QR_DATA_KANJI, /*!< Kanji character set in accordance with JIS X 0208 Annex 1 Shift Coded Representation \n .in QR Code can have values 8140HEX -9FFCHEX and E040HEX -EBBFHE*/
                   QR_DATA_NULL /*!< No data */
                  } ;


 /** \brief Standard character encodings
 */
enum class QREciMode {QR_ECI_MODE_ISO_8859_1,QR_ECI_MODE_ISO_8859_2,QR_ECI_MODE_ISO_8859_3,QR_ECI_MODE_ISO_8859_4,
                      QR_ECI_MODE_ISO_8859_5,QR_ECI_MODE_ISO_8859_6,QR_ECI_MODE_ISO_8859_7,QR_ECI_MODE_ISO_8859_8,
                      QR_ECI_MODE_ISO_8859_9,QR_ECI_MODE_ISO_8859_10,QR_ECI_MODE_ISO_8859_11,QR_ECI_MODE_ISO_8859_13,
                      QR_ECI_MODE_ISO_8859_14,QR_ECI_MODE_ISO_8859_15,QR_ECI_MODE_ISO_8859_16,Shift_JIS,UTF_8
                     } ;


 /** \brief Information container of a QR & micro QR
 */
 class QRDataContainer
 {

  public:
     /** \brief Creates a empty QRDataContainer
     */
     QRDataContainer();
     /** \brief destructor
     *
     */
     ~QRDataContainer();

     /** \brief copy constructor
     *
     */
     QRDataContainer(const QRDataContainer &);

     /** \brief assignment operator
     *
     */
     QRDataContainer(QRDataContainer &&);

     /** \brief move constructor
     *
     */
     QRDataContainer& operator=(const QRDataContainer &);

     /** \brief move assignment operator
     *
     */
     QRDataContainer& operator=(QRDataContainer &&);

     bool enable_UTF8; /**< enable o disable UTF8, : set false to deactivate UTF8 and set true to activate  */
     bool isMicro; /**< enable o disable micro QR, : set false to deactivate Micro QR and set true to activate  */
     QRErrorCorrectionLevel correction_level; /**< QR and micro QR error correction level   */

     QRVersion getqrversion(); /**< Get  QRVersion of QR  */
     short getqrversion_number(); /**< Get  version number of QR  */
     unsigned short getnum_modules(); /**< Get the number of modules per row or column  */
     unsigned short getnum_mask(); /**< Get  the applied mask  */
     QREciMode geteci_mode(int position); /**< Get  QREciMode by position  */
     unsigned short getnum_eci_mode(); /**< Get  number of character encoding formats that the image has, if it only contains characters belonging to Numerical/alphanumeric/ISO 8859 1/Kanji its value is 0  */
     QRData getdata_coding(); /**< Get  #QRData of QR  */
     std:: string &  geterror(); /**< Get  error if the image has not been applied  */
     std:: string &  getwarning(); /**< Get  warning if the image has not been applied   */


  private :

     QRVersion qrversion; /**< QR and micro QR version , read parameter  */
     short qrversion_number; /**< QR and micro QR version number, read parameter  */
     unsigned short num_modules; /**< QR and micro QR number of modules, read parameter  */
     unsigned short mask;  /**< QR and micro QR number of mask, read parameter  */

     std::list<QREciMode> eci_mode; /**< QR and micro QR eci mode, read parameter  */
     unsigned short num_eci_mode ; /**< number of character encoding formats that the image has, if it only contains characters belonging to Numerical/alphanumeric/ISO 8859 1/Kanji its value is 0  ,  read parameter  */
     QRData data_coding ; /**< QR and micro QR eci mode, read parameter  */

     std:: string  error; /**< message in case of error if it is not possible create qr , read parameter  */
     std:: string  warning; /**< warning message, for example if you use #QR_ERROR_CORRECTION_LEVEL_HIGH in micro QR ,read parameter*/



     void   copyparameters(QRDataContainer &);
     void   copylist(const QRDataContainer &);


     friend class QrProcesses;
     friend class QrMask;

} ;


}


#endif // Qr_Definitions_H_INCLUDED
