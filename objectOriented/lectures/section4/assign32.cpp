/***********************************************************************
* Program:
*    Assignment 32, ???? 
*    Brother Helfrich, CS165
* Author:
*    your name
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>
using namespace std;

/***********************************************************
 * Point: Position of an item on the screen.
 ***********************************************************/
class Point
{
public:
   Point() : x(0), y(0)   {                         };
   Point(int x, int y)    { setX(   x); setY(   y); };
   Point(const Point &pt) { setX(pt.x); setY(pt.y); };
   int  getX() const      { return x;               };
   int  getY() const      { return y;               };
   void setX(int x)       { this->x = x;            };
   void setY(int y)       { this->y = y;            };
   friend ostream & operator << (ostream & out, const Point & pt);
   friend istream & operator >> (istream & in ,       Point & pt);
private:
   int x;
   int y;
};

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



/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOOSE POINTS.
 ***********************************************************************/
int main()
{
   // point test
   Point pt;
   cout << "Please enter a position (x y): ";
   cin  >> pt;
   cout << pt << endl;

   // circle test
   //  Circle circle;
   //cout << "Please enter a circle (x y radius): ";
   //cin  >> circle;
   //cout << circle << endl;

   
   return 0;
}
