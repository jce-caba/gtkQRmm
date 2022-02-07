#ifndef DRAWDATA_HPP
#define DRAWDATA_HPP
#include <gtkmm.h>
#include "QrDefinitions.hpp"


namespace GtkQR
{
    class Draw_Data_PP
    {

      public :
        Draw_Data_PP();
        Draw_Data_PP(const Draw_Data_PP &);
        Draw_Data_PP& operator=(const Draw_Data_PP &);

        double size_modules;
        guint startX, startY;
        guint width;

        #if (GTKMM_MAJOR_VERSION >= 3 )
        Gdk::RGBA white;
        Gdk::RGBA black;
        #else
        Gdk::Color white;
        Gdk::Color black;
        #endif

        void copyparameters(const Draw_Data_PP &);

    };


   class drawData
   {
    public:
        drawData()=delete;
        ~drawData() = delete;
        static void draw(const Cairo::RefPtr<Cairo::Context>&,const Draw_Data_PP *,const char **);


    protected:

    private:
   };

}



#endif // DRAWDATA_HPP
