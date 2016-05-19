/***********************************************************************
* Program:
*    POINT.CPP, Skeet
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




#include "point.h"
#include <cassert>

/******************************************
 * POINT : CONSTRUCTOR WITH X,Y
 * Initialize the point to the passed position
 *****************************************/
Point::Point(float x, float y) : x(0.0), y(0.0), check(false), dead(false)
{
   setX(x);
   setY(y);
}

/*******************************************
 * POINT : SET X
 * Set the x position if the value is within range
 *******************************************/
void Point::setX(float x)
{
   assert(xMin < xMax);
   if (!check || (x >= xMin && x <= xMax))
      this->x = x;
   else
      dead = true;
}

/********************************************
 * POINT : Assignmenet
 *******************************************/
const Point & Point :: operator = (const Point & rhs)
{
   x        = rhs.x;
   y        = rhs.y;
   check    = rhs.check;
   dead     = rhs.dead;

   return *this;
}

/*******************************************
 * POINT : SET Y
 * Set the y position if the value is within range
 *******************************************/
void Point::setY(float y)
{
   assert(yMin < yMax);
   if (!check || (y >= yMin && y <= yMax))
      this->y = y;
   else
      dead = true;
}


/******************************************
 * POINT insertion
 *       Display coordinates on the screen
 *****************************************/
std::ostream & operator << (std::ostream & out, const Point & pt)
{
   out << "(" << pt.getX() << ", " << pt.getY() << ")";
   return out;
}

/*******************************************
 * POINT extraction
 *       Prompt for coordinates
 ******************************************/
std::istream & operator >> (std::istream & in, Point & pt)
{
   float x;
   float y;
   in >> x >> y;

   pt.setX(x);
   pt.setY(y);

   return in;
}
   
