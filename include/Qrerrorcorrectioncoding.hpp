#ifndef QRERRORCORRECTIONCODING_HPP
#define QRERRORCORRECTIONCODING_HPP
#include "QrDefinitions.hpp"
#include <string>
#include "QrErrorCorrection.hpp"
#include <utility>
#include "QrConversions.hpp"
#include "Qrremainderbits.hpp"
#include "QrReedSolomon.hpp"

namespace GtkQR
{

  class Qrerrorcorrectioncoding
  {
     public:
        Qrerrorcorrectioncoding(std::string &,QRDataContainer *);
        ~Qrerrorcorrectioncoding();

        std::string & getResult();

     protected:

     private:

         std::string text;
         std::string result;

         QRDataContainer *data;
         QrErrorCorrection *error_correction;

         char ***group1;
         char ***group2;
         char ** allblocks;

         void _getgroups();
         void _getgroups_especial();
         void _getgroups_all_versions();

         void getgroup1();
         void getgroup2();

         void getfinalmessage();
         void getfinalmessage_special();
         void  getfinalmessage_all_versions();

         void  freememory ();
         void  freememorygroup (char ***);
  };

}


#endif // QRERRORCORRECTIONCODING_HPP
