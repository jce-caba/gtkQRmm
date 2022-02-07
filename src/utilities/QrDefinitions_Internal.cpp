#include "QrDefinitions_Internal.hpp"

using namespace GtkQR;

Dictionary::Dictionary()
{
    data =nullptr;
}

Dictionary::~Dictionary()
{
    if (data !=nullptr && free_memory)
    {
        switch(typedata)
        {
            case TypeData::TipeChar:
                 delete [] static_cast<std::string *>(data);
            break;
            case TypeData::TipeInt:
                  delete [] static_cast<int *>(data);
            break;
            case TypeData::Type_invalid:

            break;
        }
    }
}

//----------------------------------------------------

Dictionaries::Dictionaries()
{

}

Dictionaries::~Dictionaries()
{

    for (std::list<Dictionary *>::iterator it=dictionaries.begin(); it != dictionaries.end(); ++it)
    {

       delete *it;
    }


    //if (dictionaries !=nullptr)
      //  delete [] dictionaries;
}
