#include "QrEncode.hpp"

using namespace GtkQR;

QrEncode::QrEncode()
{
    //ctor
}

QrEncode::~QrEncode()
{
    //dtor
}

std::string QrEncode::encondeNumeric(std::string *value)
{
  int aux,lg = value->size();
  char c;
  std::string result("");
  std::string text;

  for (int i = 0; i < lg; i =i+ 3)
  {
       c=value->at(i);
       text.clear();
       if (i + 1 >= lg )
       {
            text.push_back(c);
            aux = Conversion::number_to_int(text);
            Conversion::toBinary_n_bits(text,aux,4);
            result.append(text);

       }
       else if (i + 2 >= lg )
       {
           text.push_back(c);
           c = value->at(i+1);
           text.push_back(c);
           aux = Conversion::number_to_int(text);

           Conversion::toBinary_n_bits(text,aux,7);
           result.append(text);

       }
       else
       {
           text.push_back(c);
           c = value->at(i+1);
           text.push_back(c);
           c = value->at(i+2);
           text.push_back(c);

           aux = Conversion::number_to_int(text);
           Conversion::toBinary_n_bits(text,aux,10);
           result.append(text);

       }
  }


   return result;
}

std::string QrEncode::encondeAlphaNumeric(std::string *value)
{
  int aux,aux2,lg = value->size();
  char c;
  std::string result("");
  std::string text;


  for (int i = 0; i < lg; i =i+ 2)
  {
     c=value->at(i);
     aux = getAlphaNumericValue(c);

     if (i + 1 >= lg )
     {
        Conversion::toBinary_n_bits(text,aux,6);
        result.append(text);
     }
     else
     {
        c = value->at(i+1);
        aux2 = getAlphaNumericValue(c);
        aux =(aux*45) + aux2;

        Conversion::toBinary_n_bits(text,aux,11);
        result.append(text);
     }

  }


  return result;
}


int  QrEncode::getAlphaNumericValue(char txt)
{
  int value=1;

  if( (int) txt >= 48 && (int) txt <= 57 )
  {
     value=(int) txt;
     value=value-48;
  }
  else if( (int) txt >= 65 && (int) txt <= 90 )
  {
     value=(int) txt;
     value=value - 55; // - 65 +10
  }
  else if( (int) txt == 32  ) //space
        value = 36;
  else if( (int) txt == 36  ) //dolar
        value = 37;
  else if( (int) txt == 37  )
        value = 38;
  else if( (int) txt == 42  )
        value = 39;
  else if( (int) txt == 43  )
        value = 40;
  else if( (int) txt == 45  )
        value = 41;
  else if( (int) txt == 46  )
        value = 42;
  else if( (int) txt == 47  )
        value = 43;
  else if( (int) txt == 58  )
        value = 44;

  return value;
}

std::string QrEncode::encondeISO_8859_1(int *value,int num_bytes)
{
   std::string result("");
   std::string text;

    for (int i =0 ; i < num_bytes;i ++)
    {
        Conversion::toBinary_n_bits(text,value[i],8);
        result.append(text);
    }



    return result;
}

std::string QrEncode::encondeKanji(int *value,int num_bytes)
{
  int aux,aux2;
  int i = 0;
  std::string result("");
  std::string bits;
  std::string bits_16;

  while (i < num_bytes)
  {
     aux=value[i];
     i++;

     if (aux >=33088 && aux <= 40956) //range 0x8140 to 0x9FFC
     {
       aux=aux -33088 ;
       Conversion::toBinary_n_bits(bits_16,aux,16);
       Conversion::least_significant_byte(bits_16,bits);
       aux = Conversion::toDecimal(bits);

       Conversion::most_significant_byte(bits_16,bits);
       aux2 = Conversion::toDecimal(bits);

       aux2 = 192 * aux2;
       aux = aux + aux2;

       Conversion::toBinary_n_bits(bits,aux,13);
       result.append(bits);


     }
     else if (aux >=57408 && aux <= 60351) //0xE040 to 0xEBBF
     {
        aux=aux -49472 ;
        Conversion::toBinary_n_bits(bits_16,aux,16);
        Conversion::least_significant_byte(bits_16,bits);
        aux2 = Conversion::toDecimal(bits);

        Conversion::most_significant_byte(bits_16,bits);
        aux = Conversion::toDecimal(bits);

        aux = 192 * aux;
        aux = aux + aux2;

        Conversion::toBinary_n_bits(bits,aux,13);
        result.append(bits);

     }

  }


  return result;
}
