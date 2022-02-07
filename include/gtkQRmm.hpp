#ifndef GTKQR_HPP
#define GTKQR_HPP
#include <gtkmm.h>
#include "QrDefinitions.hpp"
#include "QrUtils.hpp"





namespace GtkQR
{
  class PrivateClass;


  /** \brief QR widget
  */
  class QR : public Gtk::Widget
  {
      public:
        /** \brief Creates a new empty widget GtkQR without any image
        */
        QR();
        /** \brief copy constructor
        *
        */
        QR(const QR &);
        /** \brief move constructor
        *
        */
        QR(QR &&);
        /** \brief Creates a new widget GtkQR with text
        * \param  text : text you want to encode
        */
        QR(const char *text);

        /** \brief Creates a new widget GtkQR with text and error correction level
        * \param  text : text you want to encode
        * \param error_level_correction : #QRErrorCorrectionLevel for qr image
        */
        QR(const char *text,QRErrorCorrectionLevel error_level_correction);

        /** \brief destructor
        *
        */
        ~QR();

        /** \brief assignment operator
        *
        */
        QR& operator=(const QR &);

        /** \brief move assignment operator
        *
        */
        QR& operator=(QR &&);

        /** \brief set text of the widget and regenerates it
        * \param  text : text you want to encode
        */
        void set_text(Glib::ustring  &text);

        /** \brief set text of the widget and regenerates it
        * \param  text : text you want to encode
        */
        void set_text(const char *text);


        /** \brief set text and error correction level of the widget and regenerates it
        *
        * \param text :text you want to encode
        * \param error_level_correction : #QRErrorCorrectionLevel for qr image
        */
        void set_text_and_correction(Glib::ustring &text,QRErrorCorrectionLevel error_level_correction);
        /** \brief set text and error correction level of the widget and regenerates it
        *
        * \param text :text you want to encode
        * \param error_level_correction : #QRErrorCorrectionLevel for qr image
        */
        void set_text_and_correction(const char *text,QRErrorCorrectionLevel error_level_correction);

        /** \brief the micro QR ,default:false
        * \param set_micro :true to use Micro QR, false to use QR
        *
        */
        void set_micro(bool set_micro);

        /** \brief Allows the encoding of characters in UTF8 ,default:true
        * \param set_UTF8 :true to allow UTF8, false otherwise
        * \details In <a href="https://en.wikipedia.org/wiki/Extended_Channel_Interpretation">Extended Channel Interpretation</a> allows the encoding of characters in <a href="https://en.wikipedia.org/wiki/UTF-8">UTF8</a>  when using characters not included in <a href="https://en.wikipedia.org/wiki/ISO/IEC_8859-1">ISO/IEC 8859-1</a>,
        * if you disable this option then it will use the following encoding :
        * <a href="https://en.wikipedia.org/wiki/ISO/IEC_8859-2">ISO/IEC 8859-2</a>,
        * <a href="https://en.wikipedia.org/wiki/ISO/IEC_8859-3">ISO/IEC 8859-3</a>,
        * <a href="https://en.wikipedia.org/wiki/ISO/IEC_8859-4">ISO/IEC 8859-4</a>,
        * <a href="https://en.wikipedia.org/wiki/ISO/IEC_8859-5">ISO/IEC 8859-5</a>,
        * <a href="https://en.wikipedia.org/wiki/ISO/IEC_8859-6">ISO/IEC 8859-6</a>,
        * <a href="https://en.wikipedia.org/wiki/ISO/IEC_8859-7">ISO/IEC 8859-7</a>,
        * <a href="https://en.wikipedia.org/wiki/ISO/IEC_8859-8">ISO/IEC 8859-8</a>,
        * <a href="https://en.wikipedia.org/wiki/ISO/IEC_8859-9">ISO/IEC 8859-9</a>,
        * <a href="https://en.wikipedia.org/wiki/ISO/IEC_8859-10">ISO/IEC 8859-10</a>,
        * <a href="https://en.wikipedia.org/wiki/ISO/IEC_8859-11">ISO/IEC 8859-11</a>,
        * <a href="https://en.wikipedia.org/wiki/ISO/IEC_8859-13">ISO/IEC 8859-13</a>,
        * <a href="https://en.wikipedia.org/wiki/ISO/IEC_8859-14">ISO/IEC 8859-14</a>,
        * <a href="https://en.wikipedia.org/wiki/ISO/IEC_8859-15">ISO/IEC 8859-15</a>,
        * <a href="https://en.wikipedia.org/wiki/ISO/IEC_8859-16">ISO/IEC 8859-16</a> or
        * <a href="https://en.wikipedia.org/wiki/Shift_JIS"> JIS X 0201</a>
        * \n.With UTF8 you will have all the characters but occupying more space for the encoding, in case of using ISO/IEC 8859-2 to JIS X 0201 the encoding uses less space but not all the characters are possible
        */
        void set_UTF8(bool  set_UTF8);


        /** \brief Save text in GtkQR ,default:true
        *
        * \param set_save_text :true to save text, false otherwise
        * \details Not saving the text in memory we save memory but it has the disadvantage that when using the
        * \ref set_dynamic_margin(bool set_dynamic) "set_dynamic_margin" ,
        * \ref set_extra_margin(unsigned short size_margin) "set_extra_margin" ,
        * \ref set_micro(bool set_micro) "set_micro" or
        * \ref set_UTF8(bool  set_UTF8) "set_UTF8" or
        * change color functions you have to re-enter the text to regenerate the image
        *
        */
        void set_save_text(bool set_save_text);

        /** \brief  sets whether the margin is always the same ,default:true
        * \param set_dynamic: false is is always the same , true otherwise
        * \details The QR standard establishes that at least 4 image margin modules are necessary
        * ,but the number of modules varies from 21x21 in version 1 to 170x170 in version 40 .if the parameter is set to false the margin is calculated in the worst case 21x 21 ,
        * if it is set to true the margin will depend on the number of modules or qr version
        *
        */
        void set_dynamic_margin(bool set_dynamic);

        #if (GTKMM_MAJOR_VERSION >= 3 )
        /** \brief change the background color
        *
        * \param color :
        *
        */
        void set_background_color(Gdk::RGBA color);

        /** \brief change the foreground color
        *
        * \param color :
        *
        */
        void set_foreground_color(Gdk::RGBA color);

        #else
        /** \brief change the background color
        *
        * \param color :
        *
        */
        void set_background_color(Gdk::Color color);

        /** \brief change the foreground color
        *
        * \param color :
        *
        */
        void set_foreground_color(Gdk::Color color);
        #endif



        /** \brief regenerate qr image
        * \details Some functions like
        * \ref set_dynamic_margin(bool set_dynamic) "set_dynamic_margin" ,
        * \ref set_extra_margin(unsigned short size_margin) "set_extra_margin" ,
        * \ref set_micro(bool set_micro) "set_micro" or
        * \ref set_UTF8(bool  set_UTF8) "set_UTF8",
        * don't regenerate the image they only change options , if you use the above functions before
        * \ref set_text(Glib::ustring  &text) "set_text" ,
        * \ref set_text(const char *text) "set_text",
        * \ref set_text_and_correction(Glib::ustring &text,QRErrorCorrectionLevel error_level_correction) "set_text_and_correction" or
        * \ref set_text_and_correction(const char *text,QRErrorCorrectionLevel error_level_correction) "set_text_and_correction"
        * no need to regenerate the image
        */
        void regenerate();

        /** \brief Save the qr image to png
        *
        * \param filename : file name to save image
        * \param _size : size of image
        */
        void save_png_image(const Glib::ustring  &filename,int _size);

        /** \brief Get version enum for qr image
        *
        * \return #QRVersion
        *
        */
        QRVersion            get_version();

        /** \brief Get version number of the widget GtkQR according to the encrypted text
        *
        * \return version number
        * \details Version number are 1 to 40 for QR and #QR_VERSION_NUMBER_M1 , #QR_VERSION_NUMBER_M2 ,
        *  #QR_VERSION_NUMBER_M3 and #QR_VERSION_NUMBER_M4 for micro QR
        * .If QR can't render the image return #QR_NO_VERSION
        */
        short                get_version_number();

        /** \brief Get mask pattern for qr image
        *
        * \return number 0 to 7
        *
        */
        unsigned short       get_mask();

        /** \brief Get type of data for qr image
        *
        * \return #QRData
        *
        */
        QRData               get_data_coding();

        /** \brief Get text of the widget
        *
        * \return text of widget GtkQR ,
        * if you disable save text with function
        * \ref set_save_text(bool set_save_text) "set_save_text"
        * text of widget is empty
        */
        std::string &        get_text();


       /** \brief   extra space added to the margins ,default:0
       * \param size_margin: extra margin to add
       *
       */
        void  set_extra_margin(unsigned short size_margin);

       /** \brief Get number character encoding
       * \return number of character encoding
       * \details Obtains the character encoding number, if the encodings
       * that are default (NUMERIC,ALPHANUMERIC,ISO/IEC 8859-1 or KANJI) returns 0.
       * Returning a number >=1 indicates that the <a href="https://en.wikipedia.org/wiki/Extended_Channel_Interpretation">Extended Channel Interpretation</a> is used
       */
       int   get_number_character_encoding();


        /** \brief Get character encoding used in the QR
        *
        * \param position :position of character enconding ,starts with 0
        * \return character encoding
        * \details Get character encoding used in the QR starting position 0 to
        * \ref get_number_character_encoding() "get_number_character_encoding" -1
        * , if number of character_encoding is 0 always return QR_ECI_MODE_ISO_8859_1
        *
        */
        QREciMode  get_character_encoding(int position);

        /** \brief Get the character matrix representing the QR
        *  \return character matrix
        * \details A QR image is made up of a series of rectangles called modules,
        * each value of the matrix is a coordinate (X,Y) that represents the different modules, being value '1'
        * for foreground color and '0' for background color.
        * \see \ref QrMatrix::GetQrMatrix(std::string &text,QRDataContainer *data) "GetQrMatrix"
        * \note the (0,0) coordinate is at the top left .
       */
        QrMatrix  get_qrmatrix();


      protected:
        #if (GTKMM_MAJOR_VERSION >= 3 )
         /// @private
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
        #else
         /// @private
        bool on_expose_event(GdkEventExpose* event) override;
        #endif


        /// @private
        void on_realize() override;

      private:
        PrivateClass *privateclass;
        void copyqr(const QR &);


        void clear_variables();
        void set_matrix();

        void draworder();


        Glib::RefPtr<Gdk::Window> m_refGdkWindow;

   };
}



#endif // GTKQR++_HPP
