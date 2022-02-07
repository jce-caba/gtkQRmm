#ifndef QRDEFINITIONS_INTERNAL_HPP
#define QRDEFINITIONS_INTERNAL_HPP
#include "QrDefinitions.hpp"
#include <list>

namespace GtkQR
{
    enum class TypeImage  {
      TipeJPG,
      TipePNG,
      TypeBMP ,
      TypeIco ,
      TypeImageInvalid
    } ;

    enum class TypeData  {

        TipeChar,TipeInt,Type_invalid
    };

     class Dictionary  {

       public:
            Dictionary();
            ~Dictionary();
            QREciMode eci_mode;
            QRData coding;
            void *data;
            TypeData typedata;
            unsigned int size_data;
            bool free_memory;

     } ;

    class Dictionaries  {

      public:
            Dictionaries();
            ~Dictionaries();
            std::list<Dictionary *> dictionaries;
            unsigned int _num_dictionaries;
            bool error;
            unsigned int total_data;

    } ;

}


#endif // QRDEFINITIONS_INTERNAL_HPP
