#ifndef QRUTILS_HPP
#define QRUTILS_HPP
#include "QrDefinitions.hpp"
#include <functional>

namespace GtkQR
{

   #ifndef GTKQR_HPP
   class QR;
   #endif



    /** \brief class that represents the matrix of points that is formed by a QR image
    */
    class QrMatrix
    {
      public:

        /** \brief Creates a empty QrMatrix
        */
        QrMatrix();

        /** \brief destructor
        *
        */
        ~QrMatrix();

        /** \brief copy constructor
        *
        */
        QrMatrix(const QrMatrix &);

        /** \brief assignment operator
        *
        */
        QrMatrix& operator=(const QrMatrix &);

        /** \brief move constructor
        *
        */
        QrMatrix(QrMatrix &&);

        /** \brief move assignment operator
        *
        */
        QrMatrix& operator=(QrMatrix &&);


 /** \brief Get the character matrix representing the QR without widget
  *
  * \param text :text you want to encode
  * \param data :Container with input and output information
  * \return character matrix
  * \details A QR image is made up of a series of rectangles called modules,
  * each value of the matrix is a coordinate (X,Y) that represents the different modules, being value true
  * for foreground color and false for background color.
  * Usage example  :  \include example1.cpp
  * \note the (0,0) coordinate is at the top left .
  */
        static QrMatrix GetQrMatrix(std::string &text,QRDataContainer *data);

        /** \brief Get value for point in QR
        * \param x : x coordinate
        * \param y : y coordinate
        * \return true for foreground and false for background .
        */
        bool   getValue(unsigned short x ,unsigned short y);


        /** \brief iterate over QR
        * \param _function : lambda function
        */
        void   iterate(std::function<void(unsigned short,unsigned short,bool)> const& _function);

      protected:

      private:

          char ** matrix;
          unsigned short num_modules;

          void   destroy();
          void   copy(const QrMatrix &);

          friend class QR;
    };

}




#endif // QRUTILS_HPP
