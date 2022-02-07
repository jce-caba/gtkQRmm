#include "QrMatrixData.hpp"
#include "QrAlignmentPatternLocations.hpp"

 using namespace GtkQR;

QrMatrixData::QrMatrixData(const char *_t,QRDataContainer *_data)
{
   data = _data;
   word = _t;

   matrix=nullptr;
   counter=0;

   if(data!=nullptr)
   {
     number_modules = data->getnum_modules() ;
     CoordX = number_modules-1;
     CoordY = number_modules-1;

   }


}

void QrMatrixData::setParameters(const char *_t,QRDataContainer *_data)
{
   word = _t;
   data = _data;

   if(data!=nullptr)
   {
     number_modules = data->getnum_modules() ;
     CoordX = number_modules-1;
     CoordY = number_modules-1;

   }

}

QrMatrixData::~QrMatrixData()
{
    //dtor
}

char ** QrMatrixData::getMatrixData()
{
    if(data->isMicro )
        return getMatrixData_micro_QR ();
    else
        return getMatrixData_QR ();

}

char ** QrMatrixData::getMatrixData_micro_QR()
{
   matrix=new char*[number_modules +1 ];

   for(int i =0 ; i < number_modules ; i++)
   {
      matrix[i] =  new char[number_modules +1 ];
      for(int a =0 ; a < number_modules ; a++)
                                    matrix[i][a] = 'n';

      matrix[i][number_modules] = '\0';
   }

    matrix[number_modules]=  nullptr;

    switch(data->getqrversion())
    {
        case QRVersion::QR_VERSION_M1:
               if (!bounceUp(1,number_modules-1,1))
                          return matrix;

               CoordY = 9;
               bounceDown(9,number_modules-1,4);

        break;
        case QRVersion::QR_VERSION_M2:
               if (!bounceUp(1,number_modules-1,2))
                          return matrix;
               bounceUp(9,number_modules-1,4);

        break;
        case QRVersion::QR_VERSION_M3:
               if (!bounceUp(1,number_modules-1,3))
                          return matrix;

               CoordY = 9;
               bounceDown(9,number_modules-1,4);


        break;
        case QRVersion::QR_VERSION_M4:
               if (!bounceUp(1,number_modules-1,4))
                          return matrix;

               bounceUp(9,number_modules-1,4);
        break;
    default:

        break;
    }

    return matrix;
}

char ** QrMatrixData::getMatrixData_QR()
{
   int aux;
   unsigned short version= data->getqrversion_number();
   matrix=new char*[number_modules +1 ];

   for(int i =0 ; i < number_modules ; i++)
   {
      matrix[i] =  new char[number_modules +1 ];
      for(int a =0 ; a < number_modules ; a++)
                                    matrix[i][a] = 'n';

      matrix[i][number_modules] = '\0';
   }

    matrix[number_modules]=  nullptr;

    switch(version)
    {
        case 1:
              setmatrix_1(number_modules);
        break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
              aux = 3 + 2 * (version -2);
              setmatrix_2_6(number_modules,aux);
        break;
        default:
              setmatrix_N(number_modules,data->getqrversion_number());
            break;
    }



   return matrix;
}

void QrMatrixData::setmatrix_2_6(int num_modules,int parameter)
{
     int c[1];
     c[0]= num_modules-4;

    if (!bounceUp(9,num_modules-1,2))
           return;

    if (!stepUp(c,1,9))
            return;

    if  (!stepDown(c,1,num_modules))
            return ;

    if  (!stepUp_left_step(c,1,0) )
                    return ;


    if(!totalDown(num_modules,parameter))
            return;


    if (!cornerUp(num_modules))
           return;

    bounceDown(9,num_modules-9,3);


}

void QrMatrixData::setmatrix_N(int num_modules,int version)
{
     int total_elements;
     int *c;


     total_elements = QrAlignmentPatternLocations::getNumberElements(version);

     c =  new int[total_elements ];
     QrAlignmentPatternLocations::getSeparation(version ,c);

     if  (!up_to_information(num_modules,c,total_elements-1) )
                   goto finish;

     must_up=true;


    for(int i= 1; i < total_elements ; i ++)
    {
        if(must_up)
        {
            if(!totalUp_until(num_modules,c[i]))
                goto finish;
        }
        else
        {
            if(!totalDown_until(num_modules,c[i]))
               goto finish;
        }

        if(must_up && i !=total_elements-1)
        {
            if (!stepUp(c,total_elements,0))
                goto finish;

            if (!stepDown(c,total_elements,num_modules))
                goto finish;

            if  (!stepUp_left_step(c,total_elements,0) )
                goto finish;

            must_up=false;
        }
        else if(i !=total_elements-1)
        {
            if (!stepDown(c,total_elements,num_modules))
                goto finish;

            if (!stepUp(c,total_elements,0))
                goto finish;

            if (!stepDown_left_step(c,total_elements,num_modules))
                goto finish;


            must_up=true;
        }
    }


    for(int i=0;i<total_elements-2;i++)
                     c[i]= c[i+1];


    if(must_up)
    {
        CoordY = num_modules-9;
        if (!stepUp(c,total_elements-2,9))
                        goto finish;

        CoordX=CoordX-1;
        if  (!stepDown(c,total_elements-2,num_modules-11))
                    goto finish;

        bounceUp(9,num_modules-11,2);
    }

finish:

    delete [] c;
}







void QrMatrixData::setmatrix_1(int num_modules)
{

     if (!bounceUp(9,num_modules-1,4))
           return;

     if (!totalUp(num_modules,2))
           return;

     if (!cornerUp(num_modules))
           return;


     bounceDown(9,num_modules-9,3);
}



bool QrMatrixData::upwardPlacement()
{
   while(CoordY >= limitY)
   {
      if (word[counter] == '\0')
                       return false;

      matrix[CoordX][CoordY] = word[counter];
      counter ++;

      if (word[counter] == '\0')
                       return false;

      matrix[CoordX -1 ][CoordY] =word[counter];
      counter ++;
      CoordY--;
   }

   CoordY++;
   return true;
}


bool QrMatrixData::downwardPlacement()
{
   while(CoordY <= limitY)
   {
      if (word[counter] == '\0')
                       return false;

      matrix[CoordX][CoordY] =word[counter];
      counter ++;

      if (word[counter] == '\0')
                       return false;

      matrix[CoordX -1 ][CoordY] =word[counter];
      counter ++;
      CoordY++;
   }
   CoordY--;
   return true;
}

bool QrMatrixData::upwardPlacementonecolumn()
{
   while(CoordY >= limitY)
   {
      if (word[counter] == '\0')
                       return false;

      matrix[CoordX][CoordY] = word[counter];
      counter ++;
      CoordY--;
   }
   CoordY++;
   return true;
}

bool QrMatrixData::downPlacementonecolumn()
{
   while(CoordY <= limitY)
   {
      if (word[counter] == '\0')
                       return false;

      matrix[CoordX][CoordY] = word[counter];
      counter ++;
      CoordY++;
   }
   CoordY--;
   return true;
}

bool QrMatrixData::bounceUp(int Y_Upper,int Ylower,int bounce_number)
{
    int a = 0;

    while (a < bounce_number)
    {
       limitY = Y_Upper;
       if (upwardPlacement()==0)
            return false;

       a++;

       CoordX=CoordX-2;
       if(a < bounce_number)
       {
         limitY = Ylower;
         if (downwardPlacement()==0)
                     return false;

         CoordX=CoordX-2;
         a++;
       }
    }
  return true;
}

bool QrMatrixData::bounceDown(int Y_Upper,int Ylower,int bounce_number)
{
    int a = 0;

    while (a < bounce_number)
    {
       limitY = Ylower;
       if (downwardPlacement()==0)
            return false;

       a++;

       CoordX=CoordX-2;
       if(a < bounce_number)
       {
         limitY = Y_Upper;
         if (upwardPlacement()==0)
                     return false;

         CoordX=CoordX-2;
         a++;
       }
    }

  return true;
}

bool QrMatrixData::totalUp(int _num_modules,int bounce_number)
{
    int a = 0;

    while (a < bounce_number)
    {
       limitY = 7;

       if (upwardPlacement()==0)
                     return false;

       limitY = 0;
       CoordY = 5;

       if (upwardPlacement()==0)
                     return false;
       a++;
       CoordX=CoordX-2;
       if(a < bounce_number)
       {
         limitY = 5;
         if (downwardPlacement()==0)
                     return false;

         CoordY = 7;
         limitY = _num_modules-1;
         if (downwardPlacement()==0)
                     return false;

         CoordX=CoordX-2;
         a++;
       }
    }
  return true;

}

bool QrMatrixData::totalDown(int _num_modules,int bounce_number)
{

    if (bounce_number > 0)
    {
       limitY = 5;

       if (downwardPlacement()==0)
                     return false;

       limitY = _num_modules -1;
       CoordY = 7;

       if (downwardPlacement()==0)
                     return false;

       CoordX=CoordX-2;
       if (bounce_number > 1)
       {
           return totalUp(_num_modules,bounce_number-1);
       }
    }
  return true;

}

bool QrMatrixData::cornerUp(int _num_modules)
{
  // Esquina antes timing
   CoordY = _num_modules-9;
   limitY = 9;

   if (upwardPlacement()==0)
                     return false;


   CoordX=CoordX-3;
   return true;
}


bool QrMatrixData::stepUp(int* steps,int num_steps,int Y_Upper)
{
    limitY = steps[0];

    for(int i=0;i < num_steps;i++)
    {
       if (upwardPlacement()==0)
                    return false;

       CoordY = CoordY - 6;
       if (i  + 1 < num_steps)
       {
          limitY = steps[i+1];
       }
    }

    if(Y_Upper <=5 && CoordY >=7)
    {
        limitY = 7;
        if (upwardPlacement()==0)
                     return false;

        CoordY = 5;
        limitY =Y_Upper;

        if (upwardPlacement()==0)
                     return false;
    }
    else
    {
        limitY =Y_Upper;

        if (upwardPlacement()==0)
                     return false;

    }

    CoordX=CoordX-2;
    return true;
}

bool  QrMatrixData::stepDown(int* steps,int num_steps,int num_modules)
{
    int aux;

    aux = steps[num_steps -1 ] - 6 ;

    if (CoordY <= 5  && aux >= 7 )
    {
        limitY =5;

        if (downwardPlacement()==0)
                     return false;

        CoordY = 7;
    }

    limitY = aux ;

    for(int i=num_steps -1 ;i >= 0;i--)
    {
        if (downwardPlacement()==0)
                     return false;

         CoordY = CoordY + 6;
         if (i  - 1 >= 0)
         {
           limitY = steps[ i -1 ] - 6 ;
         }

    }

    limitY =num_modules -1;

    if (downwardPlacement()==0)
                     return false;

    CoordX=CoordX-2;
    return true;
}

bool QrMatrixData::stepUp_left_step (int* steps,int num_steps,int Y_Upper)
{
    // una columna arriba bordeando escalon por la izquierda
    int aux;
    limitY = steps[0];


    for(int i=0;i < num_steps;i++)
    {
       if (upwardPlacement()==0)
                    return false;

       CoordX=CoordX-1;
       CoordY --;


       if(limitY-5 <=5 && CoordY >=7 )
       {
           aux = limitY-5;
           limitY = 7;
           if (upwardPlacementonecolumn()==0)
                     return false;

           CoordY = 5;
           limitY = aux;

           if (upwardPlacementonecolumn()==0)
                     return false;


           CoordX++;
           CoordY --;

       }
       else
       {
           limitY = limitY-5;
           if (upwardPlacementonecolumn()==0)
                     return false;

           CoordX++;
           CoordY --;
       }



       if (i  + 1 < num_steps)
       {
           limitY = steps[i+1];
       }
    }

     if(Y_Upper <=5 && CoordY >=7)
     {
        limitY = 7;
        if (upwardPlacement()==0)
                     return false;

        CoordY = 5;
        limitY =Y_Upper;

        if (upwardPlacement()==0)
                     return false;

     }
     else
     {
        limitY =Y_Upper;

        if (upwardPlacement()==0)
                     return false;
     }


    CoordX=CoordX-2;
    return true;
}

bool QrMatrixData::stepDown_left_step (int* steps,int num_steps,int _num_modules)
{
    // una columna abajo bordeando escalon por la izquierda
    int aux;

    limitY = steps[num_steps -1 ] - 6 ;


    for(int i=num_steps -1 ;i >= 0;i--)
    {
        if (!downwardPlacement())
                     return false;


        if(limitY + 6 >=7 && CoordY <=5 )
        {
             CoordX--;
             CoordY ++;

             aux = limitY + 5;
             limitY = 5;
             if (!downPlacementonecolumn())
                     return false;

             CoordY = 7;
             limitY = aux;

             if (!downPlacementonecolumn())
                     return false;

              CoordX++;
              CoordY ++;
        }
        else
        {
           CoordX--;
           CoordY ++;
           limitY = limitY + 5;

           if (!downPlacementonecolumn())
                     return false;

           CoordX++;
           CoordY ++;
        }

         if (i  - 1 >= 0)
         {
           limitY = steps[ i -1 ] - 6 ;
         }

    }

    limitY =_num_modules -1;

    if (!downwardPlacement())
                     return false;

    CoordX=CoordX-2;

    return true;
}

bool QrMatrixData::upper_right_version(int _num_modules)
{
    CoordX=CoordX-1;
    CoordY =0;
    limitY = 5;

    if (!downPlacementonecolumn())
                     return false;

    CoordX=CoordX+1;
    CoordY =7;
    limitY = _num_modules-1;
    if (! downwardPlacement())
                     return false;

   CoordX=CoordX-2;
   return true;
}

 bool QrMatrixData::up_to_information(int _num_modules,int *obstacle ,int num_obstacle)
 {
    if (!bounceUp(9,_num_modules-1,2))
           return false;

    if (!stepUp(obstacle,num_obstacle,9))
            return false;

    if (!stepDown(obstacle,num_obstacle,_num_modules))
            return false;

    if  (!stepUp_left_step(obstacle,num_obstacle,7)  )
                        return false;


    if  (!upper_right_version(_num_modules) )
            return false;

    return true;
 }

 bool QrMatrixData::totalUp_until (int _num_modules,int X_limit)
{
  int number = CoordX - X_limit + 2;
  number =number / 2;

  if(!totalUp(_num_modules,number))
            return false;

  if(number % 2==0)
       must_up =true;
  else
       must_up =false;

  return true;

}

 bool QrMatrixData::totalDown_until (int _num_modules,int X_limit)
{
  int number = CoordX - X_limit + 2;
  number =number / 2;

  if(!totalDown(_num_modules,number))
            return false;

  if(number % 2==0)
       must_up =false;
  else
       must_up =true;

  return true;

}

