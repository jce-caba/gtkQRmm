#include "Qrerrorcorrectioncoding.hpp"

using namespace GtkQR;

Qrerrorcorrectioncoding::Qrerrorcorrectioncoding(std::string &_t,QRDataContainer *_d)
{
   data = _d;
   group1=nullptr;
   group2=nullptr;
   allblocks=nullptr;
   text=_t;

   error_correction=new QrErrorCorrection(data);
}

Qrerrorcorrectioncoding::~Qrerrorcorrectioncoding()
{
   delete error_correction;
   freememory ();
   freememorygroup (group1);
   freememorygroup (group2);

}

 std::string & Qrerrorcorrectioncoding::getResult()
 {
     _getgroups();
     getgroup1();
     getgroup2();
     getfinalmessage();


    return result;
 }


 void Qrerrorcorrectioncoding::_getgroups()
 {
     QRVersion version = data->getqrversion();

     if(version == QRVersion::QR_VERSION_M1 && data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_NOTHING )
              _getgroups_especial();
     else if (version == QRVersion::QR_VERSION_M3){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
              _getgroups_especial();

        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
             _getgroups_especial();

     }
     else
       _getgroups_all_versions();
 }

 void Qrerrorcorrectioncoding::_getgroups_especial(){
     int aux,lg = text.size();
     int a=0;


    aux=(lg+4)/8;
    allblocks=new char*[aux +1 ];

        for(int i=0; i<aux; i++)
        {
            allblocks[i]=new char[ 9 ];
            if( i== aux -1 )
            {
                allblocks[i][0]='0';
                allblocks[i][1]='0';
                allblocks[i][2]='0';
                allblocks[i][3]='0';
                allblocks[i][4]=text.at(a);
                allblocks[i][5]=text.at(a + 1);
                allblocks[i][6]=text.at(a + 2);
                allblocks[i][7]=text.at(a + 3);
            }
            else
            {
                allblocks[i][0]=text.at(a);
                allblocks[i][1]=text.at(a + 1);
                allblocks[i][2]=text.at(a + 2);
                allblocks[i][3]=text.at(a + 3);
                allblocks[i][4]=text.at(a + 4);
                allblocks[i][5]=text.at(a + 5);
                allblocks[i][6]=text.at(a + 6);
                allblocks[i][7]=text.at(a + 7);
            }

            allblocks[i][8]='\0';
            a=a+8;
        }

     allblocks[aux] = new char[ 1 ];
     allblocks[aux][0]=  '\0';

 }

void Qrerrorcorrectioncoding::_getgroups_all_versions(){

     int aux,lg = text.size();
     int a=0;


    aux=lg/8;
    allblocks=new char*[aux +1 ];


        for(int i=0; i<aux; i++)
        {
            allblocks[i]=new char[ 9 ];
            allblocks[i][0]=text.at(a);
            allblocks[i][1]=text.at(a + 1);
            allblocks[i][2]=text.at(a + 2);
            allblocks[i][3]=text.at(a + 3);
            allblocks[i][4]=text.at(a + 4);
            allblocks[i][5]=text.at(a + 5 );
            allblocks[i][6]=text.at(a + 6);
            allblocks[i][7]=text.at(a + 7);
            allblocks[i][8]='\0';
            a=a+8;
        }


     allblocks[aux] = new char[ 1 ];
     allblocks[aux][0]=  '\0';

 }

 void Qrerrorcorrectioncoding::getgroup1() // // * CHECK OK * //
 {
    int numBlocks1;
    int sizeBlocks1;
    int counter=0,counter2=0;

    numBlocks1 = error_correction->getNumberBlocks1 ();
    sizeBlocks1 = error_correction->getNumberDataBlocks1 ();


    group1=new char**[numBlocks1 +1 ];

    for(int i=0 ; i<numBlocks1;i++)
    {
        group1[i] =new char*[sizeBlocks1 +1 ];

        counter=0;
        for (int a = 0 ; a< sizeBlocks1; a++)
        {
            group1[i][a]= allblocks[counter2];
            counter++;
            counter2++;
        }
        group1[i][counter]=NULL;

    }


    group1[numBlocks1]=  NULL;

 }

 void Qrerrorcorrectioncoding::getgroup2()// // * CHECK OK * //
 {
    int numBlocks2;
    int sizeBlocks2;
    int aux;
    int counter=0,counter2=0;

    numBlocks2 = error_correction->getNumberBlocks2 ();
    if(numBlocks2 == 0)
          return ;

    sizeBlocks2 = error_correction->getNumberDataBlocks2 ();

    aux = error_correction->getNumberBlocks1 ();
    counter2 = error_correction->getNumberDataBlocks1 ();
    counter2 = aux * counter2 ;


    group2=new char**[numBlocks2 +1 ];

    for(int i=0 ; i<numBlocks2;i++)
    {
        group2[i] =new char*[sizeBlocks2 +1 ];
        counter=0;
        for (int a = 0 ; a< sizeBlocks2; a++)
        {
            group2[i][a]= allblocks[counter2];
            counter++;
            counter2++;
        }
        group2[i][counter]=NULL;

    }

    group2[numBlocks2]=  NULL;

 }

 void Qrerrorcorrectioncoding::getfinalmessage()
 {
     QRVersion version = data->getqrversion();

     if(version == QRVersion::QR_VERSION_M1 && data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_NOTHING )
               getfinalmessage_special();
     else if (version == QRVersion::QR_VERSION_M3){
        if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW)
               getfinalmessage_special();

        else if(data->correction_level==QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM)
             getfinalmessage_special();

     }
     else
         getfinalmessage_all_versions();
 }

 void Qrerrorcorrectioncoding::getfinalmessage_special()
 {
    int *_ref;
    int total;
    std::string aux;
    QrReedSolomon reedsolomon(allblocks,data,error_correction);

    result = text;
    int ** codeworderrorgroup1;

    // calculate error correction codewords
    codeworderrorgroup1 = new int *[1];


    reedsolomon.setBlocks(group1[0]);
    codeworderrorgroup1[0] = reedsolomon.getErrorCorrectionCodewords();

    // Interleave the Error Correction Codewords
    // all codeword have same total

    total =   reedsolomon.getCountarray();

    _ref = codeworderrorgroup1[0];

    for(int i=0 ; i<total; i++)
    {
      Conversion::toBinary_n_bits(aux,_ref[i],8);
      result.append(aux);
    }


    //std::swap(&text,&result);
    delete [] codeworderrorgroup1;

 }

 void Qrerrorcorrectioncoding::getfinalmessage_all_versions()
 {
    int numBlocks1;
    int sizeBlocks1;

    int numBlocks2;
    int sizeBlocks2;

    int total;
    int *_ref;

    char **txt;
    std::string aux;


    result.clear();
    QrReedSolomon reedsolomon(allblocks,data,error_correction);

    int b = 0;

    int ** codeworderrorgroup1;
    int ** codeworderrorgroup2 = nullptr;


    numBlocks1 = error_correction->getNumberBlocks1 ();
    sizeBlocks1 = error_correction->getNumberDataBlocks1 ();



    numBlocks2 = error_correction->getNumberBlocks2 ();
    sizeBlocks2 = error_correction->getNumberDataBlocks2 ();


    if(sizeBlocks1 >= sizeBlocks2)
               total = sizeBlocks1;
    else
               total = sizeBlocks2 ;



    while( b < total)
    {
        for(int i=0 ; i<numBlocks1; i++)
        {
            txt = group1[i];

            if (b < sizeBlocks1)
                  result.append(txt[b]);
        }
        for(int i=0 ; i<numBlocks2; i++)
        {
            txt = group2[i];
            if (b < sizeBlocks2)
                   result.append(txt[b]);
        }

        b++;
    }

    // calculate error correction codewords
    codeworderrorgroup1 = new int *[numBlocks1];


    for(int i=0 ; i<numBlocks1; i++)
    {
        txt = group1[i];
        reedsolomon.setBlocks(txt);
        codeworderrorgroup1[i] = reedsolomon.getErrorCorrectionCodewords();
    }


    if (numBlocks2 > 0)
           codeworderrorgroup2 = new int *[numBlocks2];

    for(int i=0 ; i<numBlocks2; i++)
    {
        txt = group2[i];
        reedsolomon.setBlocks(txt);
        codeworderrorgroup2[i] = reedsolomon.getErrorCorrectionCodewords();
    }



    // Interleave the Error Correction Codewords
    // all codeword have same total

    total =reedsolomon.getCountarray();
    b = 0;

    std::string result2;

    while( b < total)
    {
        for(int i=0 ; i<numBlocks1; i++)
        {
            _ref = codeworderrorgroup1[i];
            Conversion::toBinary_n_bits(aux,_ref[b],8);
            result.append(aux);result2.append(aux);
        }
        for(int i=0 ; i<numBlocks2; i++)
        {
            _ref = codeworderrorgroup2[i];
            Conversion::toBinary_n_bits(aux,_ref[b],8);
            result.append(aux);
        }

        b++;
    }


    // delete memory
    for(int i=0 ; i<numBlocks1; i++)
    {
       delete [] codeworderrorgroup1[i] ;
    }
     delete [] codeworderrorgroup1 ;

    for(int i=0 ; i<numBlocks2; i++)
    {
        delete [] codeworderrorgroup2[i];
    }

    if (numBlocks2 > 0)
         delete [] codeworderrorgroup2 ;



    total = Qrremainderbits::getremainderbits(data->getqrversion_number());

    if (total > 0)
    {

        for(int i=0; i<total; i++)
                result.append("0");


    }
 }


 void  Qrerrorcorrectioncoding::freememorygroup (char ***value){

    int a=0;
    char ** v;

    if (value == nullptr)
                 return;

    v= value[a];

    while ( v != NULL )
    {
      delete [] v;
      a ++;
      v= value[a];
    }
    delete [] v;
    delete [] value;

 }


 void  Qrerrorcorrectioncoding::freememory (){
    int a=0;
    char * v;
    char c=2;

    if (allblocks == nullptr)
                 return;

    while ( c != '\0' )
    {
      c = allblocks[a][0];
      v = allblocks[a];
      delete [] v;
      v = nullptr;
      a ++;
    }

    delete [] allblocks;

 }
