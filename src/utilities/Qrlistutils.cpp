#include "Qrlistutils.hpp"

using namespace GtkQR ;

Qrlistutils::Qrlistutils()
{
    //ctor
}

Qrlistutils::~Qrlistutils()
{
    //dtor
}


Dictionary* Qrlistutils::getelement(std::list <Dictionary*> & _list ,int position)
{
    int a=0;
    Dictionary* value=nullptr;
    std::list<Dictionary*>::iterator it=_list.begin();


    while (a<=position && it != _list.end())
    {
       if(a==position)
       {
          value=*it;
       }
       a++;
       it++;
    }

    return value;
}


