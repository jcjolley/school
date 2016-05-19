/***********************************************************************
 * Header File:
 *    Vector : The representation of a point and speed/direction
 * Author:
 *    Br. Grimmett
 * Summary:
 *    Everything we need to know about an object that is moving, including
 *    the location, speed and direction.
 ************************************************************************/


#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include "point.h"

/*********************************************
 * Vector
 * Both Magnitude and Direction  
 *********************************************/
class Vector
{
public:
   Vector();
   // getters
   Point getPoint()    const { return point;           };
   float getDx()       const { return dx;              };
   float getDy()       const { return dy;              };
   float getX() const { return point.getX();};
   float getY() const { return point.getY();};
   float getXMin() const {return point.getXMin();};
   float getXMax() const {return point.getXMax();};
   float getYMin() const {return point.getYMin();};
   float getYMax() const {return point.getYMax();};
   
   // setters
   void setPoint(Point curretPoint);
   void setX(float newX);
   void setY(float newY);
   void setDx(float valDx);
   void setDy(float valDy);
   void addDx(float incrDx)      { setDx(getDx() + incrDx); };
   void addDy(float incrDy)      { setDy(getDy() + incrDy); };

private:
   Point point;        // position of our vector
   float dx;           // horizontal position
   float dy;           // vertical position
};


#endif // POINT_H
