#ifndef QRMATRIXDATA_HPP
#define QRMATRIXDATA_HPP
#include "QrDefinitions.hpp"

namespace GtkQR
{
  class QrMatrixData
  {
    public:
        QrMatrixData(const char *,QRDataContainer *);
        ~QrMatrixData();

        char ** getMatrixData();
        void setParameters(const char *,QRDataContainer *);

    protected:

    private:

        char **matrix;
        const char *word;
        int counter;
        int CoordX;
        int CoordY;
        int limitY;
        int number_modules;

        bool must_up;

        QRDataContainer *data;


         void setmatrix_1(int);
         void setmatrix_2_6(int,int);
         void setmatrix_N(int,int);

        char ** getMatrixData_micro_QR();
        char ** getMatrixData_QR();

        bool upwardPlacement();
        bool downwardPlacement();
        bool upwardPlacementonecolumn();
        bool downPlacementonecolumn();
        bool bounceUp(int,int,int);
        bool bounceDown(int,int,int);
        bool totalUp(int,int);
        bool totalDown(int,int);
        bool cornerUp(int);
        bool stepUp(int*,int,int);
        bool stepDown(int*,int,int);
        bool upper_right_version(int);
        bool stepUp_left_step (int*,int,int);
        bool stepDown_left_step (int*,int,int);
        bool up_to_information(int,int *,int);
        bool totalUp_until (int,int);
        bool totalDown_until (int,int);


  };


}



#endif // QRMATRIXDATA_HPP
