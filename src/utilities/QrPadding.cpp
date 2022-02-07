#include "QrPadding.hpp"

using namespace GtkQR ;

std::string PadBytes::pad(QRDataContainer *data,unsigned int value)
{
  int parity;
  std::string result("");

  if(data->isMicro)
  {
      parity = QrParity::getparity(data);

      if (parity ==4)
            padBytesMicro(value,result);
      else
            padBytesQR(value,result);

  }
  else
        padBytesQR(value,result);

   return result;
}

void PadBytes::padBytesMicro(int value,std::string &result)
{

   for (int i = 0; i < value; i =i+ 1)
            result.append("0000");

}


 void PadBytes::padBytesQR(int value,std::string &result)
 {
   std::string even = "11101100";
   std::string odd  = "00010001";

   for (int i = 0; i < value; i =i+ 1)
   {
      if ((i+2)% 2 == 0 )
      {
        result.append(even);
      }
      else
      {
        result.append(odd);
      }
   }


}
