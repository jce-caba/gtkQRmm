#include "QrConversions.hpp"

using namespace GtkQR;


std::string Conversion::toBinary(int value)
{
    std::string result;
    int i=0;

    while (value!=0)
    {
       if (value % 2 ==0)
           result.insert(0,"0");
       else
           result.insert(0,"1");

       value = value/2 ;
       i++;
    }

    if (result.empty())
         return "0";
    else
         return result;
}

 std::string Conversion::fillzeros(unsigned int lg,std::string  &value){

     std::string  ret;


     if(   value.size()  <  lg)
     {
       for(unsigned int a =0;a<lg;a++)
            ret.insert(0,"0");

     }

     return ret;
 }

  std::string Conversion::fillzerosafter(unsigned int lg,std::string  &value){

     std::string  ret;

     if(   value.size()  <  lg)
     {
       for(unsigned int a =0;a<lg;a++)
            ret.push_back('0');

     }

     return ret;
 }



 void Conversion::least_significant_byte(std::string  & value,std::string  & result) // // * CHECK OK * //
 {
   result.clear();

   for (int i = 8 ; i < 16; i =i + 1)
   {
     result.push_back(value.at(i));
   }

 }

 void Conversion::most_significant_byte(std::string  &value,std::string  & result) // // * CHECK OK * //
 {

   for (int i = 0; i < 8; i =i+ 1)
   {
      result[i]=value[i];
   }

 }

 int Conversion::toDecimal(std::string  &value) // // * CHECK OK * //
 {
   int exp=0,lg = value.size(),res=0,aux;

   for (int i = lg -1 ; i >= 0; i =i - 1)
   {
     aux=value[i];

     if(aux == 49)
     {
        aux = (int) pow (2,exp);
        res =res + aux;
     }

     exp++;
   }

   return res;
 }

 int* Conversion::toDecimalarray(int lg,char **value,int extra_space) // // * CHECK OK * //
 {
   int aux;
   int *res;
   std::string txt;

   res = new  int[lg + extra_space];


   for (int i = 0 ; i < lg; i =i + 1)
   {
     txt   = value[i];
     aux = toDecimal(txt);
     res[i] = aux;
   }

   for (int i = lg ; i < lg + extra_space; i =i + 1)
                 res[i] = -1;


   return res;
 }



 void Conversion::toBinary_n_bits(std::string  &text,int value,int num_bits){
  int i=0;
  int a = num_bits-1;

  text.clear();
  for(int i=0;i<num_bits;i++)
                       text.append("0");


  while (value!=0)
  {
    if (value % 2 !=0)
             text[a]='1';

    value = value/2 ;
    i++;
    a--;
  }

 }

 std::string   Conversion::number_to_char(int value)
 {
     int count=0;
     int digit=value;
     char c;
     std::string  ret;

     while(digit>0)
     {
       digit=digit/10;
       count++;
     }

     for(int i = 0 ; i < count ; i++)
     {
         digit=value % 10;
         value=value/10;

         switch(digit)
         {
             case 0:
                 c ='0';
             break;
             case 1:
                 c ='1';
             break;
             case 2:
                 c ='2';
             break;
             case 3:
                 c ='3';
             break;
             case 4:
                 c ='4';
             break;
             case 5:
                 c ='5';
             break;
             case 6:
                 c ='6';
             break;
             case 7:
                 c ='7';
             break;
             case 8:
                 c ='8';
             break;
             case 9:
                 c ='9';
             break;
             default:
                 c ='0';
             break;
         }
         ret[count-1-i] = c;

     }

     return ret;
 }

 int  Conversion::number_to_int(std::string &value)
 {
     int res=0;
     int aux;
     int factor=1;
     char c;

     for(unsigned int i = 0 ; i < value.size() ; i++)
     {
         c= value.at( value.size()-1-i );

         switch(c)
         {
             case '0':
                 aux  =0;
             break;
             case '1':
                 aux  =1;
             break;
             case '2':
                 aux  =2;
             break;
             case '3':
                 aux  =3;
             break;
             case '4':
                 aux  = 4;
             break;
             case '5':
                 aux  = 5;
             break;
             case '6':
                 aux  = 6;
             break;
             case '7':
                 aux  = 7;
             break;
             case '8':
                 aux  = 8;
             break;
             case '9':
                 aux  = 9;
             break;
             default:
                 aux  = 0;
             break;
         }
         res = res + aux*factor;
         factor = 10*factor;

     }



     return res;
 }

