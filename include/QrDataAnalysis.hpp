#ifndef QRDATAANALYSIS_HPP
#define QRDATAANALYSIS_HPP
#include <string>
#include "QrDefinitions.hpp"
#include "QrDefinitions_Internal.hpp"


namespace GtkQR
{
   using FUNCTION_POT = int (int);

   class QrDataAnalysis
   {
      public:
        QrDataAnalysis(QRDataContainer *);
        ~QrDataAnalysis();

        bool isNumeric(std::string &);
        bool isAlphaNumeric(std::string &);
        bool is_8859_1(int,int **);

        bool get_UTF8(std::string &,int **values);
        bool get_unicode(std::string &,int *,int **,int);

        Dictionaries*    analyze_data(std::string &);


      protected:

      private:

        QRDataContainer *data;

        int check_chunk (int start,int stop,int **valuesIN,FUNCTION_POT _f);
        int * make_copy (int,int,int **,FUNCTION_POT );
        int is_type(int total_lenght,int **valuesIN,int **valuesOUT,FUNCTION_POT);
        void  complex_data(std::string &,Dictionaries *,int *,int);
        void free_Dictionaries(Dictionaries *);


     };

}



#endif // QRDATAANALYSIS_HPP
