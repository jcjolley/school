/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen, including
 *    the location and the bounds.
 ************************************************************************/

#include "point.h"        // for the POINT class definition
#include <cassert>        // because I am paranoid
#include <iostream>       // for CIN and COUT
using namespace std;

/******************************************
 * POINT : CONSTRUCTOR WITH X,Y
 * Initialize the point to the passed position
 *****************************************/
Point :: Point(float x, float y) : x(0.0), y(0.0), dead(false)
{
   setX(x);
   setY(y);
}

/*******************************************
 * POINT : SET X
 * Set the x position if the value is within range
 *******************************************/
void Point :: setX(float x)
{
   assert(xMin < xMax);
   if (xMin <= x && x <= xMax)
      this->x = x;
   else
      dead = true;
}

/*******************************************
 * POINT : SET Y
 * Set the y position if the value is within range
 *******************************************/
void Point :: setY(float y)
{
   assert(yMin < yMax);
   if (yMin <= y && y <= yMax)      
      this->y = y;
   else
      dead = true;
}


/******************************************
 * POINT :: DISPLAY
 *       Display coordinates on the screen
 *****************************************/
void Point :: display()
{
   cout << "(" << getX() << ", " << getY() << ")";
}

/*******************************************
 * POINT :: PROMPT
 *       Prompt for coordinates
 ******************************************/
void Point :: prompt (const string & sPrompt)
{
   // display the prompt
   cout << sPrompt;

   // fetch the data
   float x;
   float y;
   cin >> x >> y;

   // set the data
   setX(x);
   setY(y);
}
   
