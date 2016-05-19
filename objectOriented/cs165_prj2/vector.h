/***********************************************************************
* Program:
*    VECTOR.H, Skeet
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



#ifndef Skeet_vector_h
#define Skeet_vector_h
#include "point.h"

/***********************************************************************
 * Vector class
 * This class holds a point and a dx and dy and can calculate the difference
 * between its point and another vector's point
 **********************************************************************/
class Vector
{
public:
   Point & getPoint()           { return point; }
   float  getDx()         const { return dx; };
   float  getDy()         const { return dy; };
   void setDx(float rhs);
   void setDy(float rhs);
   void advance();
   float difference(Vector & b);
   Vector & operator++()            { advance(); return *this; }
   
   float operator-(Vector & other)  { return difference(other); }
private:
   Point point;
   float dx;
   float dy;
};


#endif
