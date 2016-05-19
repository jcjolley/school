/***********************************************************************
 * Header File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen, including
 *    the location and the bounds.
 ************************************************************************/


#ifndef POINT_H
#define POINT_H

#include <string>             // for the STRING passed to prompt()

/*********************************************
 * POINT
 * A single position.  
 *********************************************/
class Point
{
public:
   // constructors
   Point()            : x(0.0), y(0.0), dead(false) {                }
   Point(float x, float y);
   Point(const Point & point)                       { *this = point; }

   // getters
   float getX()       const { return x;              }
   float getY()       const { return y;              }
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

   // input and output
   void display();
   void prompt(const std::string & sPrompt);

private:
   float x;           // horizontal position
   float y;           // vertical position
   bool  dead;        // have we exceed our bounds?
   static float xMin; // minimum extent of the x position
   static float xMax; // maximum extent of the x position
   static float yMin; // minimum extent of the y position
   static float yMax; // maximum extent of the y position
};

#endif // POINT_H
