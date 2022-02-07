 #include <gtkmm.h>
 #include "gtkQRmm.hpp"

 void set_isMicro();
 void set_UTF8();
 void change_background();
 void change_foreground();
 void set_text();
 void save_image();


  void setInformation ();
  const char *to_version(int);
  const char *to_mask(int);
  const char *to_code(GtkQR::QRData);
  const char *to_mode(GtkQR::QREciMode);


 class WidgetsContainer
 {
  public:

    GtkQR::QR  *_qr;
    Gtk::TextView *text;
    Gtk::ComboBoxText *comboerror;
    Gtk::Label *label_version;
    Gtk::Label *lbl_mask;
    Gtk::Label *lbl_encode;

    Gtk::CheckButton *isMicro;
    Gtk::CheckButton *utf8;

    Gtk::ColorButton *foreground;
    Gtk::ColorButton *background;

    Gtk::Window *window;

    Gtk::ComboBoxText *cmbecis;
 };

 WidgetsContainer widgetscontainer;


 int main(int argc, char **argv)
 {
  auto app = Gtk::Application::create(argc, argv,"org.gtkmm.examples.base");
  Gtk::Window window;
  GtkQR::QR _qr;
  Gtk::Paned paned(Gtk::Orientation::ORIENTATION_HORIZONTAL);
  Gtk::Box gtkbox1(Gtk::ORIENTATION_VERTICAL,0);
  Gtk::Label GtkLabel572("Text",false);
  Gtk::ScrolledWindow scrolltext;
  Glib::RefPtr<Gtk::Adjustment> h_adjustment537;
  Glib::RefPtr<Gtk::Adjustment> v_adjustment553;
  Gtk::Viewport viewporttext(h_adjustment537,v_adjustment553);
  Gtk::TextView text;
  Gtk::Box GtkBox060(Gtk::ORIENTATION_HORIZONTAL,0);
  Gtk::Label GtkLabel153("Error",false);
  Gtk::ComboBoxText comboerror;
  Gtk::Box GtkBox281(Gtk::ORIENTATION_HORIZONTAL,0);
  Gtk::Label lbl2("Version:",false);
  Gtk::Label label_version;
  Gtk::Label GtkLabel290("encode :",false);
  Gtk::Label lbl_encode;
  Gtk::Label GtkLabel448("Mask :",false);
  Gtk::Label lbl_mask;
  Gtk::Box GtkBox511(Gtk::ORIENTATION_HORIZONTAL,0);
  Gtk::Label lbl1("Eci Mode:",false);
  Gtk::Label lblNothing("Nothing",false);
  Gtk::ComboBoxText cmbecis;
  Gtk::CheckButton isMicro("Is Micro",false);
  Gtk::CheckButton GtkCheckButton031("Enable UTF 8",false);
  Gtk::Box GtkBox613(Gtk::ORIENTATION_HORIZONTAL,0);
  Gtk::Box GtkBox312(Gtk::ORIENTATION_HORIZONTAL,0);
  Gtk::Label GtkLabel431("Background color :",false);
  Gdk::RGBA rgbacolor407("rgb(255,255,255)");
  Gtk::ColorButton GtkColorButton799(rgbacolor407);
  Gtk::Box GtkBox068(Gtk::ORIENTATION_HORIZONTAL,0);
  Gtk::Label GtkLabel670("Foreground color :",false);
  Gdk::RGBA rgbacolor266("rgb(0,0,0)");
  Gtk::ColorButton GtkColorButton868(rgbacolor266);
  Gtk::Box GtkBox923(Gtk::ORIENTATION_HORIZONTAL,0);
  Gtk::Button GtkButton141("Set Text",false);
  Gtk::Button GtkButton846("Save Image",false);

  h_adjustment537 = Gtk::Adjustment::create (0,0,100,1,10,0);
  v_adjustment553 = Gtk::Adjustment::create (0,0,100,1,10,0);

  widgetscontainer._qr= &_qr;
  widgetscontainer.text = &text;
  widgetscontainer.comboerror = &comboerror;
  widgetscontainer.label_version = &label_version;
  widgetscontainer.lbl_mask = &lbl_mask;
  widgetscontainer.lbl_encode = &lbl_encode;
  widgetscontainer.isMicro = &isMicro;
  widgetscontainer.utf8 = &GtkCheckButton031;

  widgetscontainer.foreground = &GtkColorButton868;
  widgetscontainer.background = &GtkColorButton799;
  widgetscontainer.window = &window;

  widgetscontainer.cmbecis=&cmbecis;



  window.set_default_size (800,600);
  window.set_can_focus (false);
  window.set_title ("Example 2");
  window.set_resizable (false);
  window.set_position (Gtk::WIN_POS_CENTER);
  paned.set_visible (true);
  paned.set_can_focus (true);
  paned.property_position().set_value (300);
  paned.set_wide_handle (true);
  gtkbox1.set_visible (true);
  gtkbox1.set_can_focus (false);
  gtkbox1.set_hexpand (true);
  GtkLabel572.set_visible (true);
  GtkLabel572.set_can_focus (false);
  GtkLabel572.set_halign (Gtk::Align::ALIGN_START);
  GtkLabel572.set_margin_start (5);
  GtkLabel572.set_margin_top (5);
  GtkLabel572.set_margin_bottom (5);
  scrolltext.set_size_request (-1,200);
  scrolltext.set_visible (true);
  scrolltext.set_can_focus (true);
  scrolltext.set_margin_start (5);
  scrolltext.set_margin_end (5);
  scrolltext.set_margin_top (5);
  scrolltext.set_margin_bottom (5);
  scrolltext.set_shadow_type (Gtk::ShadowType::SHADOW_IN);
  viewporttext.set_visible (true);
  viewporttext.set_can_focus (false);
  text.set_visible (true);
  text.set_can_focus (true);
  text.set_margin_top (5);
  text.set_margin_bottom (5);
  GtkBox060.set_visible (true);
  GtkBox060.set_can_focus (false);
  GtkLabel153.set_visible (true);
  GtkLabel153.set_can_focus (false);
  GtkLabel153.set_halign (Gtk::Align::ALIGN_START);
  GtkLabel153.set_margin_start (5);
  GtkLabel153.set_margin_end (5);
  GtkLabel153.set_margin_top (5);
  GtkLabel153.set_margin_bottom (5);

  comboerror.append("0","Nothing");
  comboerror.append("1","L");
  comboerror.append("2","M");
  comboerror.append("3","Q");
  comboerror.append("4","H");


  comboerror.set_size_request (100);
  comboerror.set_visible (true);
  comboerror.set_can_focus (false);
  comboerror.set_halign (Gtk::Align::ALIGN_START);
  comboerror.set_margin_top (5);
  comboerror.set_margin_bottom (5);
  comboerror.set_active (1);
  GtkBox281.set_visible (true);
  GtkBox281.set_can_focus (false);
  lbl2.set_visible (true);
  lbl2.set_can_focus (false);
  lbl2.set_margin_start (5);
  lbl2.set_margin_end (5);
  lbl2.set_margin_top (5);
  lbl2.set_margin_bottom (5);
  label_version.set_can_focus (false);

  GtkLabel290.set_visible (true);
  GtkLabel290.set_can_focus (false);
  GtkLabel290.set_margin_start (5);
  GtkLabel290.set_margin_end (5);
  GtkLabel290.set_margin_top (5);
  GtkLabel290.set_margin_bottom (5);
  lbl_encode.set_can_focus (false);
  lbl_encode.set_margin_start (5);
  lbl_encode.set_margin_end (5);
  lbl_encode.set_margin_top (5);
  lbl_encode.set_margin_bottom (5);
  GtkLabel448.set_visible (true);
  GtkLabel448.set_can_focus (false);
  GtkLabel448.set_margin_start (5);
  GtkLabel448.set_margin_end (5);
  GtkLabel448.set_margin_top (5);
  GtkLabel448.set_margin_bottom (5);
  lbl_mask.set_can_focus (false);
  lbl_mask.set_margin_start (5);
  lbl_mask.set_margin_end (5);
  lbl_mask.set_margin_top (5);
  lbl_mask.set_margin_bottom (5);
  GtkBox511.set_visible (true);
  GtkBox511.set_can_focus (false);
  lbl1.set_visible (true);
  lbl1.set_can_focus (false);
  lbl1.set_halign (Gtk::Align::ALIGN_START);
  lbl1.set_margin_start (5);
  lbl1.set_margin_end (10);
  lbl1.set_margin_top (5);
  lbl1.set_margin_bottom (5);
  lblNothing.set_can_focus (false);
  lblNothing.set_halign (Gtk::Align::ALIGN_START);
  lblNothing.set_margin_top (5);
  lblNothing.set_margin_bottom (5);
  cmbecis.set_can_focus (false);
  cmbecis.set_margin_top (5);
  cmbecis.set_margin_bottom (5);
  isMicro.set_visible (true);
  isMicro.set_can_focus (true);
  isMicro.set_receives_default (false);
  isMicro.set_margin_start (5);
  isMicro.set_margin_top (5);
  isMicro.set_margin_bottom (5);
  isMicro.property_draw_indicator().set_value (true);
  GtkCheckButton031.set_visible (true);
  GtkCheckButton031.set_can_focus (true);
  GtkCheckButton031.set_receives_default (false);
  GtkCheckButton031.set_margin_start (5);
  GtkCheckButton031.set_margin_top (5);
  GtkCheckButton031.set_margin_bottom (5);
  GtkCheckButton031.set_active (true);
  GtkCheckButton031.property_draw_indicator().set_value (true);
  GtkBox613.set_visible (true);
  GtkBox613.set_can_focus (false);
  GtkBox312.set_visible (true);
  GtkBox312.set_can_focus (false);
  GtkLabel431.set_visible (true);
  GtkLabel431.set_can_focus (false);
  GtkLabel431.set_margin_start (5);
  GtkLabel431.set_margin_end (5);
  GtkLabel431.set_margin_top (5);
  GtkLabel431.set_margin_bottom (5);
  GtkColorButton799.set_visible (true);
  GtkColorButton799.set_can_focus (true);
  GtkColorButton799.set_receives_default (true);
  GtkColorButton799.set_margin_top (5);
  GtkColorButton799.set_margin_bottom (5);
  GtkColorButton799.property_show_editor().set_value (true);
  GtkBox068.set_visible (true);
  GtkBox068.set_can_focus (false);
  GtkLabel670.set_visible (true);
  GtkLabel670.set_can_focus (false);
  GtkLabel670.set_margin_start (5);
  GtkLabel670.set_margin_end (5);
  GtkLabel670.set_margin_top (5);
  GtkLabel670.set_margin_bottom (5);
  GtkColorButton868.set_visible (true);
  GtkColorButton868.set_can_focus (true);
  GtkColorButton868.set_receives_default (true);
  GtkColorButton868.set_margin_top (5);
  GtkColorButton868.set_margin_bottom (5);
  GtkColorButton868.property_show_editor().set_value (true);
  GtkBox923.set_visible (true);
  GtkBox923.set_can_focus (false);
  GtkBox923.set_halign (Gtk::Align::ALIGN_END);
  GtkBox923.set_margin_end (10);
  GtkBox923.set_margin_top (10);
  GtkBox923.set_margin_bottom (10);
  GtkButton141.set_visible (true);
  GtkButton141.set_can_focus (true);
  GtkButton141.set_receives_default (true);
  GtkButton141.set_margin_end (10);
  GtkButton846.set_visible (true);
  GtkButton846.set_can_focus (true);
  GtkButton846.set_receives_default (true);
  _qr.set_visible (true);

  isMicro.signal_toggled().connect(sigc::ptr_fun(&set_isMicro));
  GtkCheckButton031.signal_toggled().connect(sigc::ptr_fun(&set_UTF8));
  GtkColorButton799.signal_color_set().connect(sigc::ptr_fun(&change_background));
  GtkColorButton868.signal_color_set().connect(sigc::ptr_fun(&change_foreground));
  GtkButton141.signal_clicked().connect(sigc::ptr_fun(&set_text));
  GtkButton846.signal_clicked().connect(sigc::ptr_fun(&save_image));

  window.add (paned);
  paned.pack1(_qr,false,true);
  paned.pack2(gtkbox1,true,true);
  gtkbox1.pack_start (GtkLabel572,false,true,0);
  gtkbox1.pack_start (scrolltext,false,true,0);
  gtkbox1.child_property_position(scrolltext).set_value(1);
  gtkbox1.pack_start (GtkBox060,false,true,0);
  gtkbox1.child_property_position(GtkBox060).set_value(2);
  gtkbox1.pack_start (GtkBox281,false,true,0);
  gtkbox1.child_property_position(GtkBox281).set_value(3);
  gtkbox1.pack_start (GtkBox511,false,true,0);
  gtkbox1.child_property_position(GtkBox511).set_value(4);
  gtkbox1.pack_start (isMicro,false,true,0);
  gtkbox1.child_property_position(isMicro).set_value(5);
  gtkbox1.pack_start (GtkCheckButton031,false,true,0);
  gtkbox1.child_property_position(GtkCheckButton031).set_value(7);
  gtkbox1.pack_start (GtkBox613,false,true,0);
  gtkbox1.child_property_position(GtkBox613).set_value(8);
  gtkbox1.pack_start (GtkBox068,false,true,0);
  gtkbox1.child_property_position(GtkBox068).set_value(9);
  gtkbox1.pack_start (GtkBox923,false,true,0);
  gtkbox1.child_property_position(GtkBox923).set_value(10);
  scrolltext.add (viewporttext);
  viewporttext.add (text);
  GtkBox060.pack_start (GtkLabel153,false,true,0);
  GtkBox060.pack_start (comboerror,false,true,0);
  GtkBox060.child_property_position(comboerror).set_value(1);
  GtkBox281.pack_start (lbl2,false,true,0);
  GtkBox281.pack_start (label_version,false,true,0);
  GtkBox281.child_property_position(label_version).set_value(1);
  GtkBox281.pack_start (GtkLabel290,false,true,0);
  GtkBox281.child_property_position(GtkLabel290).set_value(2);
  GtkBox281.pack_start (lbl_encode,false,true,0);
  GtkBox281.child_property_position(lbl_encode).set_value(3);
  GtkBox281.pack_start (GtkLabel448,false,true,0);
  GtkBox281.child_property_position(GtkLabel448).set_value(4);
  GtkBox281.pack_start (lbl_mask,false,true,0);
  GtkBox281.child_property_position(lbl_mask).set_value(5);
  GtkBox511.pack_start (lbl1,false,true,0);
  GtkBox511.pack_start (lblNothing,false,true,0);
  GtkBox511.child_property_position(lblNothing).set_value(1);
  GtkBox511.pack_start (cmbecis,false,true,0);
  GtkBox511.child_property_position(cmbecis).set_value(2);
  GtkBox613.pack_start (GtkBox312,false,true,0);
  GtkBox312.pack_start (GtkLabel431,false,true,0);
  GtkBox312.pack_start (GtkColorButton799,false,true,0);
  GtkBox312.child_property_position(GtkColorButton799).set_value(1);
  GtkBox068.pack_start (GtkLabel670,false,true,0);
  GtkBox068.pack_start (GtkColorButton868,false,true,0);
  GtkBox068.child_property_position(GtkColorButton868).set_value(1);
  GtkBox923.pack_start (GtkButton141,false,true,0);
  GtkBox923.pack_start (GtkButton846,false,true,0);
  GtkBox923.child_property_position(GtkButton846).set_value(1);

  return app->run(window);
 }

 void set_isMicro()
 {
    widgetscontainer._qr->set_micro(widgetscontainer.isMicro->get_active());
    widgetscontainer._qr->regenerate();
    setInformation ();

 }

 void set_UTF8()
 {
       widgetscontainer._qr->set_UTF8(widgetscontainer.utf8->get_active());
       widgetscontainer._qr->regenerate();
       setInformation ();

 }

 void change_background()
 {
   Gdk::RGBA color =  widgetscontainer.background->get_rgba();
   widgetscontainer._qr->set_background_color(color);
   widgetscontainer._qr->regenerate();

 }

 void change_foreground()
 {
   Gdk::RGBA color =  widgetscontainer.foreground->get_rgba();
   widgetscontainer._qr->set_foreground_color(color);
   widgetscontainer._qr->regenerate();


 }

 void set_text()
 {
    int value;
    Gtk::TextBuffer::iterator  start;
    Gtk::TextBuffer::iterator _end;
    const Glib::RefPtr<Gtk::TextBuffer> buffer = widgetscontainer.text->get_buffer();

    buffer->get_bounds(start,_end);

    Glib::ustring text = buffer->get_text( start,_end,true);


    value = widgetscontainer.comboerror->get_active_row_number();
    switch(value)
    {
        case 0:
           widgetscontainer._qr->set_text_and_correction(text,GtkQR::QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_NOTHING);
        break;
        case 1:
           widgetscontainer._qr->set_text_and_correction(text,GtkQR::QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_LOW);
        break;
        case 2:
           widgetscontainer._qr->set_text_and_correction(text,GtkQR::QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_MEDIUM);
        break;
        case 3:
           widgetscontainer._qr->set_text_and_correction(text,GtkQR::QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_QUALITY);
        break;
        case 4:
          widgetscontainer._qr->set_text_and_correction(text,GtkQR::QRErrorCorrectionLevel::QR_ERROR_CORRECTION_LEVEL_HIGH);
        break;

    }

    setInformation ();

 }

 void save_image()
 {
   Gtk::FileChooserDialog filechooser( *widgetscontainer.window,"Save File" ,Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
   filechooser.add_button 	( "Cancel",0);
   filechooser.add_button 	( "Select",1);


   if(filechooser.run()==1)
   {



     const Glib::ustring str =filechooser.get_current_name();
     widgetscontainer._qr->save_png_image(str,200);
   }


 }


 void setInformation ()
 {
    int value;
    GtkQR::QRData qrdata;
    GtkQR::QREciMode ecimode;
    Glib::ustring text;

    value = widgetscontainer._qr->get_version_number();
    const Glib::ustring str = to_version(value);
    widgetscontainer.label_version->set_visible (true);
    widgetscontainer.label_version->set_text(str);
    value = widgetscontainer._qr->get_mask();
    const Glib::ustring str2 = to_mask(value);
    widgetscontainer.lbl_mask->set_visible (true);
    widgetscontainer.lbl_mask->set_text(str2);

    qrdata=widgetscontainer._qr->get_data_coding();
    widgetscontainer.lbl_encode->set_visible (true);
    widgetscontainer.lbl_encode->set_text (to_code(qrdata));

    value=widgetscontainer._qr->get_number_character_encoding();



    if (value > 0)
    {
        widgetscontainer.cmbecis->set_visible (true);
        widgetscontainer.cmbecis->remove_all();
    }
    else
          widgetscontainer.cmbecis->set_visible (false);


    for(int i=0;i<value;i++)
    {
      ecimode = widgetscontainer._qr->get_character_encoding(i);
      text = to_mode(ecimode);
      widgetscontainer.cmbecis->append( text );
    }

    if (value > 0)
          widgetscontainer.cmbecis->set_active( 0 );

 }

 const char *to_version(int version)
 {

     if(version==1)
             return "QR_1";
     else if(version==2)
             return "QR_2";
     else if(version==3)
             return "QR_3";
     else if(version==4)
             return "QR_4";
     else if(version==5)
             return "QR_5";
     else if(version==6)
             return "QR_6";
     else if(version==7)
             return "QR_7";
     else if(version==8)
             return "QR_8";
     else if(version==9)
             return "QR_9";
     else if(version==10)
             return "QR_10";
     else if(version==11)
             return "QR_11";
     else if(version==12)
             return "QR_12";
     else if(version==13)
             return "QR_13";
     else if(version==14)
             return "QR_14";
     else if(version==15)
             return "QR_15";
     else if(version==16)
             return "QR_16";
     else if(version==17)
             return "QR_17";
     else if(version==18)
             return "QR_18";
     else if(version==19)
             return "QR_19";
     else if(version==20)
             return "QR_20";
     else if(version==21)
             return "QR_21";
     else if(version==22)
             return "QR_22";
     else if(version==23)
             return "QR_23";
     else if(version==24)
             return "QR_24";
     else if(version==25)
             return "QR_25";
     else if(version==26)
             return "QR_26";
     else if(version==27)
             return "QR_27";
     else if(version==28)
             return "QR_28";
     else if(version==29)
             return "QR_29";
     else if(version==30)
             return "QR_30";
     else if(version==31)
             return "QR_31";
     else if(version==32)
             return "QR_32";
     else if(version==33)
             return "QR_33";
     else if(version==34)
             return "QR_34";
     else if(version==35)
             return "QR_35";
     else if(version==36)
             return "QR_36";
     else if(version==37)
             return "QR_37";
     else if(version==38)
             return "QR_38";
     else if(version==39)
             return "QR_39";
     else if(version==40)
             return "QR_40";
     else if(version==0)
             return "NULL";
     else if(version==GtkQR::QR_VERSION_NUMBER_M1)
             return "M1";
     else if(version==GtkQR::QR_VERSION_NUMBER_M2)
             return "M2";
     else if(version==GtkQR::QR_VERSION_NUMBER_M3)
             return "M3";
     else if(version==GtkQR::QR_VERSION_NUMBER_M4)
             return "M4";


     return "";

 }

const char *to_mask(int mask)
{
    switch(mask)
    {
    case 0:
        return "0";
        break;
    case 1:
        return "1";
        break;
    case 2:
        return "2";
        break;
    case 3:
        return "3";
        break;
    case 4:
        return "4";
        break;
    case 5:
        return "5";
        break;
    case 6:
        return "6";
        break;
    case 7:
        return "7";
        break;

    }


    return "";
}

const char *to_code(GtkQR::QRData code)
{
    switch(code)
    {
        case GtkQR::QRData::QR_DATA_NUMERIC:
              return "numeric";
        break;
        case GtkQR::QRData::QR_DATA_ALPHANUMERIC:
              return "alpha";
        break;
        case GtkQR::QRData::QR_DATA_BYTE:
              return "byte";
        break;
        case GtkQR::QRData::QR_DATA_KANJI:
              return "kanji";
        break;
        default:

        break;
    }

    return "";
}

const char *to_mode(GtkQR::QREciMode mode)
{
    switch(mode)
    {
        case GtkQR::QREciMode::QR_ECI_MODE_ISO_8859_1:
              return "ISO 8859 1";
        break;
        case GtkQR::QREciMode::QR_ECI_MODE_ISO_8859_2:
              return "ISO 8859 2";
        break;
        case GtkQR::QREciMode::QR_ECI_MODE_ISO_8859_3:
              return "ISO 8859 3";
        break;
        case GtkQR::QREciMode::QR_ECI_MODE_ISO_8859_4:
              return "ISO 8859 4";
        break;
        case GtkQR::QREciMode::QR_ECI_MODE_ISO_8859_5:
              return "ISO 8859 5";
        break;
        case GtkQR::QREciMode::QR_ECI_MODE_ISO_8859_6:
              return "ISO 8859 6";
        break;
        case GtkQR::QREciMode::QR_ECI_MODE_ISO_8859_7:
              return "ISO 8859 7";
        break;
        case GtkQR::QREciMode::QR_ECI_MODE_ISO_8859_8:
              return "ISO 8859 8";
        break;
        case GtkQR::QREciMode::QR_ECI_MODE_ISO_8859_9:
              return "ISO 8859 9";
        break;
        case GtkQR::QREciMode::QR_ECI_MODE_ISO_8859_10:
              return "ISO 8859 10";
        break;
        case GtkQR::QREciMode::QR_ECI_MODE_ISO_8859_11:
              return "ISO 8859 11";
        break;
        case GtkQR::QREciMode::QR_ECI_MODE_ISO_8859_13:
              return "ISO 8859 13";
        break;
        case GtkQR::QREciMode::QR_ECI_MODE_ISO_8859_14:
              return "ISO 8859 14";
        break;
        case GtkQR::QREciMode::QR_ECI_MODE_ISO_8859_15:
              return "ISO 8859 15";
        break;
        case GtkQR::QREciMode::QR_ECI_MODE_ISO_8859_16:
              return "ISO 8859 16";
        break;
        case GtkQR::QREciMode::Shift_JIS:
              return "Shift JIS";
        break;
        case GtkQR::QREciMode::UTF_8:
              return "UTF 8";
        break;

        default:

        break;
    }

    return "";
}


