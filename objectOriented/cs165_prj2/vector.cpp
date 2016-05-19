/***********************************************************************
* Program:
*    VECTOR.CPP, Skeet
*    Brother Helfrich, CS165
* Author:
*    Sam Barney and Joshua Jolley
* Summary:
*    This program emulates the game of Skeet, complete with menus,
*    original sound, levels, and powerups.  
*    Estimated:  15.0 hrs
*    Actual:     30.0 hrs
*    Homing was difficult to implement well, and learning how to uses
*    classess and pass the right information between classes wwas,
*    well, a learning experience.
**********************************************************************/




#include "vector.h"
#include <cmath>

/**********************************************************************
 * Vector::setDx
 * Sets dx
 *********************************************************************/
void Vector::setDx(float rhs)
{
   dx = rhs;
}

/**********************************************************************
 * Vector::setDy
 * Sets dy
 *********************************************************************/
void Vector::setDy(float rhs)
{
   dy = rhs;
}

/**********************************************************************
 * Vector::advance
 * Advances the point by dx and dy
 *********************************************************************/
void Vector::advance()
{
   //advance x and y by dx and dy respectively
   point.setX(point.getX() + dx);
   point.setY(point.getY() + dy);
   return;
}

/**********************************************************************
 * Skeet::difference
 * Returns the distance between the two vector bases
 *********************************************************************/
float Vector::difference(Vector &rhs)
{
   float x = this->getPoint().getX() - rhs.getPoint().getX();
   float y = this->getPoint().getY() - rhs.getPoint().getY();
   // Get distance between the two objects
   double dSq = sqrt(( x * x ) + ( y * y ));
   return dSq;
}




