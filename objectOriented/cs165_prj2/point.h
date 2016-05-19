/***********************************************************************
* Program:
*    POINT.H, Skeet
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



#ifndef POINT_H
#define POINT_H

#include <iostream>

/*********************************************
 * POINT
 * A single position.  
 *********************************************/
class Point
{
public:
   // constructors
   Point()            : x(0.0), y(0.0), check(false), dead(false) {}
   Point(bool check)  : x(0.0), y(0.0), check(check), dead(false) {}
   Point(float x, float y);
   Point(const Point & point) { *this = point; }

   // getters
   float getX()       const { return x;              }
   float getY()       const { return y;              }
   bool  getCheck()   const { return check;          }
   bool  isDead()     const { return dead;           }
   float getXMin()    const { return xMin;           }
   float getXMax()    const { return xMax;           }
   float getYMin()    const { return yMin;           }
   float getYMax()    const { return yMax;           }

   // setters
   void setX(float x);
   void setY(float y);
   void addX(float dx)      { setX(getX() + dx);     }
   void addY(float dy)      { setY(getY() + dy);     }
   void setCheck(bool f)    { check = f;             }
   const Point & operator = (const Point & rhs);

private:
   float x;           // horizontal position
   float y;           // vertical position
   bool  check;       // do bounds checking
   bool  dead;        // have we exceed our bounds?
   static float xMin; // minimum extent of the x position
   static float xMax; // maximum extent of the x position
   static float yMin; // minimum extent of the y position
   static float yMax; // maximum extent of the y position
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Point & pt);
std::istream & operator >> (std::istream & in,        Point & pt);

#endif // POINT_H
