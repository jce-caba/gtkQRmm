#include "drawData.hpp"

using namespace GtkQR;


Draw_Data_PP::Draw_Data_PP()
{
    white.set("white");
    black.set("black");
}

Draw_Data_PP::Draw_Data_PP(const Draw_Data_PP &other)
{
   copyparameters(other);
}

Draw_Data_PP& ::Draw_Data_PP::operator=(const Draw_Data_PP &other)
{
   copyparameters(other);
   return *this;
}

void Draw_Data_PP::copyparameters(const Draw_Data_PP &other)
{
   size_modules = other.size_modules;
   startX = other.startX;
   startY = other.startY;
   width = other.width;

   white = other.white;
   black = other.black;
}


void drawData::draw(const Cairo::RefPtr<Cairo::Context>& cr,const Draw_Data_PP *container,const char **matrix)
{
    int a =0;
    int i= 0;

    if(matrix==nullptr)
        return;



     #if (GTKMM_MAJOR_VERSION >= 3 )
       Gdk::Cairo::set_source_rgba(cr, container->black);
     #else
       Gdk::Cairo::set_source_color(cr,container->black);
     #endif


    do
    {
        do
        {
             if(matrix[a][i] == '1')
             {
                 cr->rectangle ( container->startX + container->size_modules*a, container->startY + container->size_modules* i, container->size_modules, container->size_modules);
             }

         i++;
        }while(matrix[a][i] != '\0');

       i=0;
       a++;

    }while(matrix[a] !=nullptr);


    cr->fill ();



}
