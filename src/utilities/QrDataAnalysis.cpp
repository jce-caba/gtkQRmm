#include "QrDataAnalysis.hpp"
#include "8859_1_character_set.hpp"
#include "Kanji_character_set.hpp"
#include "8859_2_character_set.hpp"
#include "8859_3_character_set.hpp"
#include "8859_4_character_set.hpp"
#include "8859_5_character_set.hpp"
#include "8859_6_character_set.hpp"
#include "8859_7_character_set.hpp"
#include "8859_8_character_set.hpp"
#include "8859_9_character_set.hpp"
#include "8859_10_character_set.hpp"
#include "8859_11_character_set.hpp"
#include "8859_13_character_set.hpp"
#include "8859_14_character_set.hpp"
#include "8859_15_character_set.hpp"
#include "8859_16_character_set.hpp"
#include "JIS8_character_set.hpp"
#include "Kanji_character_set.hpp"

 using namespace GtkQR;

QrDataAnalysis::QrDataAnalysis(QRDataContainer *_data)
{
    data=_data;
}

QrDataAnalysis::~QrDataAnalysis()
{
    //dtor
}

bool QrDataAnalysis::isNumeric(std::string &txt)
{
    int lg;
    int a =0;
    bool result =true;

    if(txt.empty())
          return false;

    lg= txt.size();

    while(a<lg &&result)
    {
      if( static_cast<int> ( txt.at(a)) < 48 || static_cast<int> ( txt.at(a)) > 57 )
             result=false;
      else
             a++;
    }

    return result;
}

bool QrDataAnalysis::isAlphaNumeric(std::string &txt)
{
    int lg;
    int a =0;
    int result =1;

    if(txt.empty())
          return false;

    lg= txt.size();

    while(a<lg &&result)
    {
      if( static_cast<int> (txt.at(a)) >= 48 && static_cast<int> (txt.at(a)) <= 57 )
             a++;
      else if( static_cast<int> ( txt.at(a)) >= 65 && static_cast<int> ( txt.at(a)) <= 90 )
             a++;
      else if( static_cast<int> ( txt.at(a)) == 32 || static_cast<int> ( txt.at(a)) == 36 || static_cast<int> ( txt.at(a)) == 37 || static_cast<int> ( txt.at(a)) == 42 ||
               static_cast<int> ( txt.at(a)) == 43 || static_cast<int> ( txt.at(a)) == 45 || static_cast<int> ( txt.at(a)) == 46 || static_cast<int> ( txt.at(a)) == 47  || static_cast<int> ( txt.at(a)) == 58 )
             a++;
      else
             result=false;
    }

    return result;
}

bool QrDataAnalysis::is_8859_1(int total_lenght,int **values)
{
    int result =true;
    int a =0;
    int value1;

    while (a< total_lenght && result )
    {
         value1 = values[0][a];

         if( value1 > 0 && value1 <= 127)
                           a++;
         else if( value1 > 161 && value1 <= 255)
                           a++;
         else
            result = false;

    }


    return result;
}

int QrDataAnalysis::is_type(int total_lenght,int **valuesIN,int **valuesOUT,FUNCTION_POT _f)
{
    int a =0;
    int value1;
    int result =true;

    while (a< total_lenght && result ==1 )
    {
        value1 = _f(valuesIN[0][a]);
        if(value1>0)
        {
            valuesOUT[0][a]=value1;
            a++;
        }
        else
           result =false;

    }


   return result;
}

int QrDataAnalysis::check_chunk (int start,int stop,int **valuesIN,FUNCTION_POT _f)
{
    int a =start;
    int value1;
    bool result =true;

    while (a< stop && result  )
    {
        value1 = _f(valuesIN[0][a]);
        if(value1>0)
        {
            a++;
        }
        else
           result =false;

    }

   return a;
}

int * QrDataAnalysis::make_copy (int start,int stop,int **valuesIN,FUNCTION_POT _f)
{
   int *values_out=nullptr;
   int a = 0;

   values_out = new int[stop - start];

   for(int i = start; i < stop ; i++)
   {
       values_out[a]=_f(valuesIN[0][i]);
       a++;
   }

   return values_out;
}

bool QrDataAnalysis::get_unicode(std::string &value,int *total_lenght,int **values,int max_lenght)
{
    int result = true;
    int lg = value.size();
    int aux1 ,aux2,aux3,aux4;
    int a=0;

    *total_lenght=0;

    //*values = (int *) malloc((lg)*sizeof(int));
    *values = new int [lg];



    while (a< lg && result ==1 )
    {
        aux1 = static_cast<int>( value[a]);

        if( aux1 > 0 && aux1 <= 127) {
           // 1 bute

           values[0][*total_lenght]=aux1;
           a++;
           *total_lenght=*total_lenght + 1;
        }
        else
        {
           if (  max_lenght < 2 || a +1 >= lg )
           {
             result=0;
             goto finish;
           }

           aux1 = static_cast<int>(value.at(a)) & -32 ;
           aux2 = static_cast<int>(value.at(a+1)) & -64;

           if(aux1 == -64 && aux2 == -128 ) {

                aux1 = static_cast<int>(value.at(a+1)) & 63 ;
                aux2 = static_cast<int>(value.at(a)) & 31 ;
                values[0][*total_lenght]=  64*aux2  + aux1 ;
                *total_lenght=*total_lenght + 1;
                a=a+2;

           }
           else
           {
               // 3 bytes
               if ( max_lenght < 3 || a +2 >= lg )
               {
                 result=0;
                 goto finish;
               }


               aux1 = static_cast<int>( value[a]) & -16;
               aux2 = static_cast<int>(value[a+1]) & -128;
               aux3 = static_cast<int>(value[a+2]) & -128;

               if(aux1 == -32&& aux2 == -128 && aux3 == -128){

                  aux1 = static_cast<int>( value[a+2] ) & 63;
                  aux2 = static_cast<int>( value[a+1] )& 63;
                  aux3 = static_cast<int>( value[a] ) & 15;

                  values[0][*total_lenght] = 4096*aux3 +64*aux2 + aux1 ;
                  *total_lenght=*total_lenght + 1;
                  a=a+3;
               }
               else
               {
                   // 4 bytes
                   if ( max_lenght < 4 || a +3 >= lg )
                   {
                      result=0;
                      goto finish;
                   }

                   aux1 = static_cast<int>( value[a] )  & -8; // -16 -112 -114 -96
                   aux2 = static_cast<int>(value[a+1] ) & -64 ;
                   aux3 = static_cast<int>(value[a+2] ) & -64;
                   aux4 = static_cast<int>(value[a+3] ) & -64;

                   if(aux1 == -16 && aux2 == -128 && aux3 == -128 && aux4 == -128){

                      aux1 = static_cast<int>( value[a+3] ) & 63;
                      aux2 = static_cast<int>( value[a+2] )& 63;
                      aux3 = static_cast<int>( value[a+1] )& 63;
                      aux4 = static_cast<int>( value[a] ) & 7;
                      values[0][*total_lenght] = 262144*aux4 + 4096*aux3+64*aux2 + aux1 ;
                      *total_lenght=*total_lenght + 1;
                      a=a+4;
                   }
                   else
                     result=0;

               }

           }
        }
    }

finish:

    if( ! result)
    {
        delete [] *values ;
        *total_lenght=-1;
        *values=nullptr;
    }
    else
    {
       for (int z=*total_lenght ;z<lg ;z++)
            values[0][z] = -1;
    }

    return result;
}

 bool QrDataAnalysis::get_UTF8(std::string & value,int **values)
 {
    bool result = true;
    int lg = value.size();
    int aux1 ;
    int a=0;

     //*values = (int *) malloc((lg)*sizeof(int));

     *values = new int [lg];


    while (a< lg && result ==1 )
    {
        aux1 = static_cast<int>( value[a]);

        if( aux1 > 0 && aux1 <= 127)
        {
            // 1 bute
            values[0][a]=aux1;
        }
        else
        {
             aux1 = static_cast<int>(value[a]) & -32 ; // format 110yyyyy
             if(aux1 == -64 )
             {
                values[0][a]=(static_cast<int>(value.at(a) & 31)) + 192 ;
             }
             else
             {
                 aux1 = static_cast<int>(value.at(a))  & -64 ; // format 10xxxxxx
                 if(aux1 == -128 )
                 {
                    values[0][a]=(static_cast<int>(value.at(a)) & 63) + 128 ;
                 }
                 else
                 {
                     aux1 = static_cast<int>(value.at(a)) & -16 ; // format 1110zzzz
                     if(aux1 == -32 )
                     {

                        values[0][a]=(static_cast<int>(value.at(a)) & 15) + 224 ;
                     }
                     else
                     {
                        aux1 = static_cast<int>(value.at(a)) & -8 ; // format 11110uuu
                        if(aux1 == -16 )
                        {
                           values[0][a]=(static_cast<int>(value.at(a)) & 7) + 240 ;
                        }
                        else
                           result = 0;
                     }
                 }
             }
        }

        a++;
    }
    if( ! result)
    {
        delete [] values;
        values=nullptr;
    }

    return result;

}

 Dictionaries* QrDataAnalysis::analyze_data(std::string &text)
 {
    int result ;
    int counter = 0;
    Dictionaries *dictionaries;
    Dictionary   *dictionary;
    int *values=NULL;
    int *values_out=NULL;
    int length_unicode;
    int length_utf8;


    FUNCTION_POT*   _functions[15];
    QREciMode   ecis[15] ;

    dictionaries =  new Dictionaries;
    dictionaries->error=true;
    dictionaries->_num_dictionaries=0;

    if (isNumeric(text) )
    {
        length_unicode = text.size();
        dictionaries->error=false;
        dictionaries->total_data = length_unicode;
        dictionary = new Dictionary;
        dictionary->coding =QRData::QR_DATA_NUMERIC;
        dictionary->eci_mode =QREciMode::QR_ECI_MODE_ISO_8859_1;
        dictionary->data = static_cast<void *>(&text);
        dictionary->typedata = TypeData::TipeChar;
        dictionary->size_data =length_unicode;
        dictionary->free_memory =false;
        dictionaries->dictionaries.push_back (dictionary);
        dictionaries->_num_dictionaries=1;
    }
    else if (isAlphaNumeric(text) )
    {
        length_unicode = text.size();
        dictionaries->error=false;
        dictionaries->total_data = length_unicode;
        dictionary = new Dictionary;
        dictionary->coding =QRData::QR_DATA_ALPHANUMERIC;
        dictionary->eci_mode =QREciMode::QR_ECI_MODE_ISO_8859_1;

        dictionary->data =static_cast<void *>(&text);
        dictionary->typedata =TypeData::TipeChar;
        dictionary->size_data =length_unicode;
        dictionary->free_memory =false;
        dictionaries->dictionaries.push_back (dictionary);
        dictionaries->_num_dictionaries=1;
    }
    else
    {
        result = get_unicode(text,&length_unicode,&values,4); //aqui
        if(result == 0)
            goto finish;

        // ** CHECK ISO 8850_1
        if (is_8859_1(length_unicode,&values))
        {
            dictionaries->error=false;
            dictionaries->total_data = length_unicode;
            dictionary = new Dictionary;
            dictionary->coding =QRData::QR_DATA_BYTE;
            dictionary->eci_mode =QREciMode::QR_ECI_MODE_ISO_8859_1;
            dictionary->data =static_cast<void *>(values);
            dictionary->typedata =TypeData::TipeInt;
            dictionary->size_data =length_unicode;
            dictionary->free_memory =true;
            dictionaries->dictionaries.push_back (dictionary);
            dictionaries->_num_dictionaries=1;
        }
        else if( !data->isMicro && data->enable_UTF8)
        {
            // ** CHECK UTF 8
            delete [] values;
            result =get_UTF8(text,&values);
            if(result == 0)
                goto finish;

            length_utf8 = text.size();
            dictionaries->error=false;
            dictionaries->total_data = length_utf8 +12;
            dictionary = new Dictionary;
            dictionary->coding =QRData::QR_DATA_BYTE;
            dictionary->eci_mode =QREciMode::UTF_8;
            dictionary->data =static_cast<void *>(values);
            dictionary->typedata =TypeData::TipeInt;
            dictionary->size_data =length_utf8;
            dictionary->free_memory =true;
            dictionaries->dictionaries.push_back (dictionary);
            dictionaries->_num_dictionaries=1;

        }
        else if( !data->isMicro)
        {
           //check isos code
           //values_out = (int *) malloc((length_unicode)*sizeof(int));
           values_out =new int[ length_unicode ];

           ecis[0] = QREciMode::QR_ECI_MODE_ISO_8859_2 ; ecis[1] = QREciMode::QR_ECI_MODE_ISO_8859_3 ; ecis[2] = QREciMode::QR_ECI_MODE_ISO_8859_4 ;
           ecis[3] = QREciMode::QR_ECI_MODE_ISO_8859_5 ; ecis[4] = QREciMode::QR_ECI_MODE_ISO_8859_6 ; ecis[5] = QREciMode::QR_ECI_MODE_ISO_8859_7 ;
           ecis[6] = QREciMode::QR_ECI_MODE_ISO_8859_8 ; ecis[7] = QREciMode::QR_ECI_MODE_ISO_8859_9 ; ecis[8] = QREciMode::QR_ECI_MODE_ISO_8859_10 ;
           ecis[9] = QREciMode::QR_ECI_MODE_ISO_8859_11 ; ecis[10] = QREciMode::QR_ECI_MODE_ISO_8859_13 ; ecis[11] = QREciMode::QR_ECI_MODE_ISO_8859_14 ;
           ecis[12] = QREciMode::QR_ECI_MODE_ISO_8859_15 ; ecis[13] = QREciMode::QR_ECI_MODE_ISO_8859_16 ; ecis[14] = QREciMode::Shift_JIS ;

           _functions[0] = &_8859_2_character_set::get_character;
           _functions[1] = &_8859_3_character_set::get_character;
           _functions[2] = &_8859_4_character_set::get_character;
           _functions[3] = &_8859_5_character_set::get_character;
           _functions[4] = &_8859_6_character_set::get_character;
           _functions[5] = &_8859_7_character_set::get_character;
           _functions[6] = &_8859_8_character_set::get_character;
           _functions[7] = &_8859_9_character_set::get_character;
           _functions[8] = &_8859_10_character_set::get_character;
           _functions[9] = &_8859_11_character_set::get_character;
           _functions[10] = &_8859_13_character_set::get_character;
           _functions[11] = &_8859_14_character_set::get_character;
           _functions[12] = &_8859_15_character_set::get_character;
           _functions[13] = &_8859_16_character_set::get_character;
           _functions[14] = &JIS8_character_set::get_character;

            result=0; counter = 0;

            while (counter < 15 && !result)
            {
                if(is_type(length_unicode,&values,&values_out,_functions[counter]))
                    result = 1;
                else
                    counter ++;
            }

            if(result)
            {
                dictionaries->error=false;
                dictionaries->total_data = length_unicode +12;
                dictionary = new Dictionary;
                dictionary->coding =QRData::QR_DATA_BYTE;
                dictionary->eci_mode =ecis[counter];
                dictionary->data =static_cast<void *>(values_out);
                dictionary->typedata =TypeData::TipeInt;
                dictionary->size_data =length_unicode;
                dictionary->free_memory =true;
                dictionaries->dictionaries.push_back (dictionary);
                dictionaries->_num_dictionaries=1;
                delete [] values;
            }
            else if(is_type(length_unicode,&values,&values_out,&Kanji_character_set::get_character)) //check kanji
            {
                dictionaries->error=false;
                dictionaries->total_data = length_unicode;
                dictionary = new Dictionary;
                dictionary->coding =QRData::QR_DATA_KANJI;
                dictionary->eci_mode =QREciMode::QR_ECI_MODE_ISO_8859_1;
                dictionary->data =static_cast<void *>(values_out);
                dictionary->typedata =TypeData::TipeInt;
                dictionary->size_data =length_unicode;
                dictionary->free_memory =true;
                dictionaries->dictionaries.push_back (dictionary);
                dictionaries->_num_dictionaries=1;
                delete [] values;
            }
            else
                delete [] values_out;
        }
        else
        {
           //check kanji
            //values_out = (int *) malloc((length_unicode)*sizeof(int));
            values_out =new int[ length_unicode ];
            if(is_type(length_unicode,&values,&values_out,Kanji_character_set::get_character))
            {
                dictionaries->error=false;
                dictionaries->total_data = length_unicode;
                dictionary = new Dictionary;
                dictionary->coding =QRData::QR_DATA_KANJI;
                dictionary->eci_mode =QREciMode::QR_ECI_MODE_ISO_8859_1;
                dictionary->data =static_cast<void *>(values_out);
                dictionary->typedata =TypeData::TipeInt;
                dictionary->size_data =length_unicode;
                dictionary->free_memory =true;
                dictionaries->dictionaries.push_back (dictionary);
                dictionaries->_num_dictionaries=1;
                delete [] values;
            }
            else
                delete [] values_out;
        }


    }


    if(values!=nullptr && dictionaries->error && !data->isMicro)
                        complex_data(text,dictionaries,values,length_unicode);


    if(values!=nullptr && dictionaries->error)
                          delete [] values;



finish:

    return dictionaries;
 }

 void QrDataAnalysis::free_Dictionaries(Dictionaries *dictionary)
 {

 }

 void  QrDataAnalysis::complex_data(std::string &text,Dictionaries *dictionaries,int *values,int total)
 {
    int watch_dog=0;
    int extra_data=0;
    int result = 1;
    int counter = 0;
    int start =0;
    int chunk ;
    int *values_out=NULL;

    Dictionary   *dictionary;
    std::list<Dictionary *>::iterator it;


    FUNCTION_POT * _functions[16];
    QREciMode   ecis[16] ;

    ecis[0] = QREciMode::QR_ECI_MODE_ISO_8859_1 ;
    ecis[1] = QREciMode::QR_ECI_MODE_ISO_8859_2 ; ecis[2] = QREciMode::QR_ECI_MODE_ISO_8859_3 ; ecis[3] = QREciMode::QR_ECI_MODE_ISO_8859_4 ;
    ecis[4] = QREciMode::QR_ECI_MODE_ISO_8859_5 ; ecis[5] = QREciMode::QR_ECI_MODE_ISO_8859_6 ; ecis[6] = QREciMode::QR_ECI_MODE_ISO_8859_7 ;
    ecis[7] = QREciMode::QR_ECI_MODE_ISO_8859_8 ; ecis[8] = QREciMode::QR_ECI_MODE_ISO_8859_9 ; ecis[9] = QREciMode::QR_ECI_MODE_ISO_8859_10 ;
    ecis[10] =QREciMode::QR_ECI_MODE_ISO_8859_11 ; ecis[11] = QREciMode::QR_ECI_MODE_ISO_8859_13 ; ecis[12] = QREciMode::QR_ECI_MODE_ISO_8859_14 ;
    ecis[13] =QREciMode::QR_ECI_MODE_ISO_8859_15 ; ecis[14] = QREciMode::QR_ECI_MODE_ISO_8859_16 ; ecis[15] = QREciMode::Shift_JIS ;

    _functions[0] = &_8859_1_character_set::get_character;
    _functions[1] = &_8859_2_character_set::get_character;
    _functions[2] = &_8859_3_character_set::get_character;
    _functions[3] = &_8859_4_character_set::get_character;
    _functions[4] = &_8859_5_character_set::get_character;
    _functions[5] = &_8859_6_character_set::get_character;
    _functions[6] = &_8859_7_character_set::get_character;
    _functions[7] = &_8859_8_character_set::get_character;
    _functions[8] = &_8859_9_character_set::get_character;
    _functions[9] = &_8859_10_character_set::get_character;
    _functions[10] = &_8859_11_character_set::get_character;
    _functions[11] = &_8859_13_character_set::get_character;
    _functions[12] = &_8859_14_character_set::get_character;
    _functions[13] = &_8859_15_character_set::get_character;
    _functions[14] = &_8859_16_character_set::get_character;
    _functions[15] = &JIS8_character_set::get_character;


     while (result && start < total)
     {
        chunk = check_chunk (start,total,&values,_functions[counter]);

        if(chunk == start)
        {
            counter++;
            watch_dog++;

            if(watch_dog >=16)
                result= 0;
        }
        else
        {
            watch_dog=0;
            dictionary = new Dictionary;

            dictionary->coding =QRData::QR_DATA_BYTE;
            dictionary->eci_mode =ecis[counter];
            values_out =  make_copy (start,chunk,&values,_functions[counter]);
            dictionary->data =static_cast<void *>(values_out);
            dictionary->typedata =TypeData::TipeInt;
            dictionary->size_data =chunk - start;
            dictionary->free_memory =true;
            extra_data = extra_data + chunk - start + 16;
            dictionaries->dictionaries.push_back (dictionary);
            dictionaries->_num_dictionaries=dictionaries->_num_dictionaries + 1;

            start=chunk ;
            counter++;
        }

        if(counter >=16)
            counter =0;

     }



     if(result)
     {
         dictionaries->error=false;
         it = dictionaries->dictionaries.begin();

         dictionary = *it;


         if(dictionary->eci_mode == QREciMode::QR_ECI_MODE_ISO_8859_1)
                   dictionaries->total_data = extra_data -16;
         else
                   dictionaries->total_data = extra_data;

     }

 }
