#include "gtkQRmm.hpp"
#include  <utility>
#include <string>
#include "QrProcesses.hpp"
#include "drawData.hpp"
#include "QrDataAnalysis.hpp"
#include <cairomm/context.h>
#include <cairomm/surface.h>

using namespace GtkQR;

namespace GtkQR
{
  class PrivateClass
  {
   public:

      PrivateClass()
      {
        matrix=nullptr;
        order_draw=false;
        save_text = true;
        dynamic_margin = true;
        extra_margin = 0;
        draw_image = false;
      }
      ~PrivateClass()
      {
        destroy();
      }

        void destroy()
        {
            unsigned short num_modules;

            if(matrix !=nullptr)
            {
                num_modules =data.getnum_modules();

                for(int i =0 ; i <= num_modules ; i++)
                    delete [] matrix[i];

                delete [] matrix;
                matrix =nullptr;
            }
        }

    Draw_Data_PP draw_data;
    QRDataContainer data;

    float margin;
    bool draw_image;
    bool save_text;
    std::string text;
    char **matrix;

    bool order_draw;
    bool dynamic_margin;
    unsigned short extra_margin;
   };
}



QR::QR():Glib::ObjectBase("QR"),Gtk::Widget()
{
   privateclass = new PrivateClass;
   privateclass->data.correction_level= QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM;

}


QR::QR(const char *_text):Glib::ObjectBase("QR"),Gtk::Widget()
{
   privateclass = new PrivateClass;
   privateclass->text = _text;
   privateclass->data.correction_level= QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM;
   set_matrix();

}


QR::QR(const char *_text,QRErrorCorrectionLevel error):Glib::ObjectBase("QR"),Gtk::Widget()
{
   privateclass = new PrivateClass;
   privateclass->text = _text;
   privateclass->data.correction_level= error;
   set_matrix();

}

QR::~QR()
{
    if(privateclass != nullptr)
                delete privateclass;

}

QR::QR(const QR &_other)
{
   privateclass = new PrivateClass;
   copyqr(_other);

}

QR& QR::operator=(const QR &_other)
{
    privateclass->destroy();
    copyqr(_other);
    return *this;
}

QR::QR(QR &&_other)
{
   privateclass=nullptr;
   std::swap(*privateclass,*_other.privateclass);
}

QR& QR::operator=(QR &&_other)
{
   std::swap(*privateclass,*_other.privateclass);
   return *this;
}

void QR::copyqr(const QR &_other)
{
   privateclass->draw_data=_other.privateclass->draw_data;
   privateclass->data=_other.privateclass->data;
   privateclass->margin=_other.privateclass->margin;
   privateclass->draw_image=_other.privateclass->draw_image;
   privateclass->save_text=_other.privateclass->save_text;
   privateclass->order_draw=_other.privateclass->order_draw;
   privateclass->dynamic_margin=_other.privateclass->dynamic_margin;
   privateclass->extra_margin=_other.privateclass->extra_margin;
   privateclass->text=_other.privateclass->text;

   if(_other.privateclass->matrix !=nullptr)
   {
       privateclass->matrix  = new char *[privateclass->data.getnum_modules()+1 ];
       for(unsigned short i= 0; i < privateclass->data.getnum_modules() ; i++ )
       {
            privateclass->matrix[i]  = new char [privateclass->data.getnum_modules()+1 ];
            for(unsigned short a= 0; a < privateclass->data.getnum_modules() ; a++ )
                        privateclass->matrix[i][a] = _other.privateclass->matrix[i][a];

            privateclass->matrix[i][privateclass->data.getnum_modules()] = '\0';
       }
       privateclass->matrix[privateclass->data.getnum_modules()]=  NULL;
   }
}

void QR::clear_variables()
{
   if(privateclass !=nullptr )
   {
      privateclass->destroy();
   }
}

void QR::set_matrix()
{
    QrProcesses  proces(&privateclass->data);

    clear_variables();

    privateclass->matrix = proces.calculateMatrix(privateclass->text);

    if(privateclass->matrix == nullptr )
        privateclass->draw_image =false;
    else
        privateclass->draw_image =true;


    if(!privateclass->save_text )
    {
        privateclass->text.clear();
    }


    if (privateclass->dynamic_margin)
        privateclass->margin = static_cast<float> (privateclass->data.getnum_modules()) / (privateclass->data.getnum_modules() + 8 + privateclass->extra_margin);
    else
        privateclass->margin = 0.72413f;

}

#if (GTKMM_MAJOR_VERSION >= 3 )

 bool QR::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
 {
    privateclass->order_draw= false;
    guint width, height;
    guint width_real, height_real;

    width = get_allocation().get_width() ;
    height = get_allocation().get_height() ;

    Gdk::Cairo::set_source_rgba(cr, privateclass->draw_data.white);
    cr->rectangle ( 0, 0, width, height);
    cr->fill ();

    if (! privateclass->draw_image)
                           return false;

    if(width > height)
    {
        height_real = privateclass->margin * height;
        width_real =  height_real;
    }
    else
    {
        height_real = privateclass->margin * width;
        width_real =  height_real;
    }


    privateclass->draw_data.size_modules = width_real / static_cast<double> (privateclass->data.getnum_modules());
    privateclass->draw_data.startX = (width - width_real) /2 ;
    privateclass->draw_data.startY = (height - height_real) /2 ;
    privateclass->draw_data.width = width_real ;

    drawData::draw(cr, const_cast<const Draw_Data_PP *>(&privateclass->draw_data),const_cast<const char **>(privateclass->matrix));

    return false;
 }

#else

  bool QR::on_expose_event(GdkEventExpose* event)
{
   guint width, height;
   guint width_real, height_real;

  if(m_refGdkWindow)
  {
    privateclass->order_draw= false;
    width = get_allocation().get_width() ;
    height = get_allocation().get_height() ;

    Cairo::RefPtr<Cairo::Context> cr = m_refGdkWindow->create_cairo_context();
    Gdk::Cairo::set_source_color(cr,privateclass->draw_data.white);
    cr->rectangle ( 0, 0, width, height);
    cr->fill ();

    if (! privateclass->draw_image)
                           return false;

    if(width > height)
    {
        height_real = privateclass->margin * height;
        width_real =  height_real;
    }
    else
    {
        height_real = privateclass->margin * width;
        width_real =  height_real;
    }

    privateclass->draw_data.size_modules = width_real / static_cast<double> (privateclass->data.getnum_modules());
    privateclass->draw_data.startX = (width - width_real) /2 ;
    privateclass->draw_data.startY = (height - height_real) /2 ;
    privateclass->draw_data.width = width_real ;

    drawData::draw(cr, const_cast<const Draw_Data_PP *>(&privateclass->draw_data),const_cast<const char **>(privateclass->matrix));


  }
  return true;
}


#endif





void QR::on_realize()
{

  set_realized();

    GdkWindowAttr attributes;
    memset(&attributes, 0, sizeof(attributes));

    Gtk::Allocation allocation = get_allocation();

    //Set initial position and size of the Gdk::Window:
    attributes.x = allocation.get_x();
    attributes.y = allocation.get_y();
    attributes.width = allocation.get_width();
    attributes.height = allocation.get_height();

    attributes.event_mask = get_events () | Gdk::EXPOSURE_MASK;
    attributes.window_type = GDK_WINDOW_CHILD;
    attributes.wclass = GDK_INPUT_OUTPUT;

    m_refGdkWindow = Gdk::Window::create(get_parent_window(), &attributes,
            GDK_WA_X | GDK_WA_Y);
    set_window(m_refGdkWindow);

    //make the widget receive expose events
    m_refGdkWindow->set_user_data(gobj());
}

void QR::set_text(Glib::ustring &_text)
{
  privateclass->text = _text;
  set_matrix();
  draworder();
}

void QR::set_text(const char * _text)
{
  privateclass->text = _text;
  set_matrix();
  draworder();
}

void QR::draworder()
{
    if( ! privateclass->order_draw )
    {
        privateclass->order_draw= true;
        queue_draw();
    }

}

void QR::set_text_and_correction(Glib::ustring &_text,QRErrorCorrectionLevel error)
{
  privateclass->text = _text;
  privateclass->data.correction_level= error;
  set_matrix();
  draworder();
}

void QR::set_text_and_correction(const char * _text,QRErrorCorrectionLevel error)
{
  privateclass->text = _text;
  privateclass->data.correction_level= error;
  set_matrix();
  draworder();
}

QRVersion QR::get_version()
{
  return privateclass->data.getqrversion();
}

short QR::get_version_number()
{
  return privateclass->data.getqrversion_number();
}

unsigned short QR::get_mask()
{
  return privateclass->data.getnum_mask();
}

QRData  QR::get_data_coding()
{
    return privateclass->data.getdata_coding();
}

void  QR::set_micro(bool _set)
{
  if(privateclass->data.isMicro != _set)
  {
     privateclass->data.isMicro= _set;
     set_matrix();
  }
}

void  QR::set_UTF8(bool _set)
{
  if(privateclass->data.enable_UTF8 != _set)
  {
      privateclass->data.enable_UTF8= _set;
      set_matrix();
  }
}

void QR::set_save_text(bool _set)
{
  privateclass->save_text = _set;
}

void QR::set_dynamic_margin(bool _set)
{
    privateclass->dynamic_margin = _set;
}

void QR::regenerate()
{
    draworder();
}



#if (GTKMM_MAJOR_VERSION >= 3 )
void QR::set_foreground_color(Gdk::RGBA color)
{
    privateclass->draw_data.black = color;
}

void QR::set_background_color(Gdk::RGBA color)
{
    privateclass->draw_data.white = color;
}

#else

void QR::set_foreground_color(Gdk::Color color)
{
    privateclass->draw_data.black = color;
}

void QR::set_background_color(Gdk::Color color)
{
    privateclass->draw_data.white = color;
}

#endif





void QR::set_extra_margin(unsigned short size_margin)
{
    privateclass->extra_margin = 2*size_margin;
}


std::string &  QR::get_text()
{
   return privateclass->text;
}

void QR::save_png_image(const Glib::ustring  &filename,int _size)
{
   Draw_Data_PP draw_data;
   guint width;
   auto surface = Cairo::ImageSurface::create(Cairo::Format::FORMAT_RGB24, _size, _size);

   auto cr = Cairo::Context::create(surface);

   draw_data.white= privateclass->draw_data.white;
   draw_data.black= privateclass->draw_data.black;


   #if (GTKMM_MAJOR_VERSION >= 3 )
       Gdk::Cairo::set_source_rgba(cr, draw_data.white);
   #else
       Gdk::Cairo::set_source_color(cr,draw_data.white);
   #endif

   cr->rectangle ( 0, 0, _size, _size);
   cr->fill ();

    if (privateclass->draw_image)
    {
        width = privateclass->margin * _size;
        draw_data.size_modules = width / (double) privateclass->data.getnum_modules();
        draw_data.startX = (_size - width) /2 ;
        draw_data.startY =  draw_data.startX ;
        draw_data.width = width ;
        drawData::draw(cr, const_cast<const Draw_Data_PP *>(&draw_data),const_cast<const char **>(privateclass->matrix));
    }



  #ifdef CAIRO_HAS_PNG_FUNCTIONS

    surface->write_to_png(filename);
  ;
  #else

  #endif

}

int QR::get_number_character_encoding()
{
  return privateclass->data.getnum_eci_mode();
}

QREciMode QR::get_character_encoding(int position)
{
  return privateclass->data.geteci_mode(position);
}

QrMatrix  QR::get_qrmatrix()
{
   QrMatrix qrmatrix;

   if(privateclass->matrix !=nullptr)
   {
       qrmatrix.num_modules = privateclass->data.getnum_modules();
       qrmatrix.matrix  = new char *[qrmatrix.num_modules+1 ];
       for(unsigned short i= 0; i < qrmatrix.num_modules ; i++ )
       {
            qrmatrix.matrix[i]  = new char [qrmatrix.num_modules+1 ];
            for(unsigned short a= 0; a < qrmatrix.num_modules ; a++ )
                        qrmatrix.matrix[i][a] = privateclass->matrix[i][a];

            qrmatrix.matrix[i][qrmatrix.num_modules] = '\0';
       }
       qrmatrix.matrix[qrmatrix.num_modules]=  nullptr;
   }


   return qrmatrix;
}
