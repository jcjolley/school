/***********************************************************************
 * Source File:
 *    Vector : The representation of a vector for an object on the screen
 * Author:
 *    Br. Grimmett
 * Summary:
 *    Everything we need to know about a vector of an ojbect on the screen
 *    including the location and the movement magnitude and direction.
 ************************************************************************/

#include "vector.h"
#include <cassert>

/******************************************
 * Vector : Default CONSTRUCTOR
 * Initialize the vector dx = 0, dy = 0
 *****************************************/
Vector::Vector()
{
   setDx(0);
   setDy(0);
}


/*******************************************
 * Vector : setPoint
 * Set the point position 
 *******************************************/
void Vector::setPoint(Point currentPoint)
{
   // check the point
   this->point = currentPoint;
}

/*******************************************
 * Vector : SET X
 * Set the X value
 *******************************************/
void Vector::setX(float valDx)
{
   this->point.setX(valDx);
}

/*******************************************
 * Vector : SET Y
 * Set the Y value
 *******************************************/
void Vector::setY(float valDy)
{
   this->point.setY(valDy);
}

/*******************************************
 * Vector : SET DX
 * Set the Dx value
 *******************************************/
void Vector::setDx(float valDx)
{
   this->dx = valDx;
}

/*******************************************
 * Vector : SET DY
 * Set the Dy value
 *******************************************/
void Vector::setDy(float valDy)
{
   this->dy = valDy;
}



