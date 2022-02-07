#include "QrReedSolomon.hpp"

using namespace GtkQR;

QrReedSolomon::QrReedSolomon(char **_allblocks,QRDataContainer *_data,QrErrorCorrection *_ec)
{
    data= _data;
    allblocks=_allblocks;
    error_correction = _ec;
}

QrReedSolomon::~QrReedSolomon()
{
    //dtor
}

void QrReedSolomon::setBlocks(char **_allblocks)
{
    allblocks=_allblocks;
}

int *  QrReedSolomon::getErrorCorrectionCodewords()
 {
    int codewordsPerBlock;
    int aux =0;
    int aux2;
    int total;
    int *generatorpolynomial;
    int *messagepolynomial;
    int *multiplier ;
    int *copymultiplier;

    codewordsPerBlock = error_correction->getECCodewords ();


    while (allblocks[aux] !=  NULL)
    {
        aux++;
    }

    total = aux+ codewordsPerBlock;

    //multiply the message polynomial by x to n , codewordsPerBlock is n (10)
    messagepolynomial = Conversion::toDecimalarray(aux,allblocks,codewordsPerBlock);
    generatorpolynomial = QrGeneratorPolynomial::getGeneratorPolynomial(codewordsPerBlock,aux) ;



    //The number of steps in the division must equal the number of terms in the message polynomial
    //  In this case, the division will take 16 steps to complete  aux = 16

    multiplier = copyarray (messagepolynomial,total);
    copymultiplier = copyarray (messagepolynomial,total);

    for(int i =0 ;i < aux ;i ++)
    {
        //Step 1a:  Multiply the Generator Polynomial by the Lead Term of the Message Polynomial
         //Step Na: Multiply the Generator Polynomial by the Lead Term of the XOR result from the previous step
        aux2 = Qrlog::getLog(multiplier[0]);
        multiply(total,aux2,generatorpolynomial,multiplier);

        //Step 1b: XOR the result with the message polynomial
        //Step Nb: XOR the result with the result from step 1b
        Xor(total,copymultiplier,multiplier);
        multiplier = discardfirstterm (multiplier,total);
        total --;
        delete [] copymultiplier;
        copymultiplier = copyarray (multiplier,total);

    }

    countarray = total;

    delete [] generatorpolynomial;
    delete [] messagepolynomial;
    delete [] copymultiplier;

    return multiplier;
 }

  int *  QrReedSolomon::copyarray (int *value,int lg)
  {
      int *res;

      res = new int [lg];


      for (int i = 0 ; i < lg  ; i =i + 1)
      {
        res[i] = value[i];

      }

      return res;
  }

  int    QrReedSolomon::getCountarray()
  {
      return countarray;
  }

  void QrReedSolomon::multiply(int total,int mp,int * generatorpolynomial,int * multiplier)
  {
    for (int i = 0 ; i < total; i =i + 1)
    {
        if(generatorpolynomial[i]==-1)
            multiplier[i] = -1;
        else
        {
            multiplier[i] = mp + generatorpolynomial[i] ;
            multiplier[i] = Qrlog::getIntegerNotation(multiplier[i]);
        }
    }

  }

 void QrReedSolomon::Xor(int total,int * messagepolynomial,int * multiplier)
{

    for (int i = 0 ; i < total; i =i + 1)
    {
        if (messagepolynomial[i]==-1 && multiplier[i] ==-1)
            multiplier[i] = -1;
        else
        {
            if (messagepolynomial[i]==-1 )
                         messagepolynomial[i] = 0;

            if (multiplier[i] ==-1)
                         multiplier[i] = 0;


            multiplier[i] = messagepolynomial[i]  ^ multiplier[i];
        }

    }

}

  int *  QrReedSolomon::discardfirstterm (int *value,int lg)
  {
      int *res;

      res = new int [lg - 1];

      for (int i = 0 ; i < lg -1 ; i =i + 1)
      {
        res[i] = value[i+1];

      }


      delete [] value;
      return res;
  }
