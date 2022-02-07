#ifndef QRLISTUTILS_HPP
#define QRLISTUTILS_HPP
#include <list>
#include "QrDefinitions_Internal.hpp"

namespace GtkQR
{

   class Qrlistutils
   {
    public:
        Qrlistutils();
        ~Qrlistutils();


        static Dictionary* getelement(std::list <Dictionary*> & ,int);

        template<class T>
        static T* getelement(std::list <T*> &  ,int );

    protected:

    private:
   };


}



#endif // QRLISTUTILS_HPP
