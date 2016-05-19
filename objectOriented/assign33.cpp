/***********************************************************************
* Program:
*    Assignment 33, Inheritance Qualifiers
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
* Summary: 
*    This program is designed to demonstrate protected inheritance
*
*    Estimated:  0.1 hrs   
*    Actual:     0.1 hrs
*      It wasn't diffiuclt
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
protected:
   int x;
   int y;
};

/**********************************************************************
 * Circle: A circle that contains a point
 **********************************************************************/
class Circle : protected Point
{
public:
   Circle() : Point(0, 0), r(0) {};
   Circle(int x, int y, int r) : Point(x,y), r(r) {};
   Circle(const Circle &circle)      {setX(circle.x); setY(circle.y); setRadius(circle.r);}
   int getRadius ()             {return r;}
   int setRadius (int r)        {this->r = r;}
   friend ostream & operator << (ostream & out, const Circle & circle);
   friend istream & operator >> (istream & in,        Circle & circle);
private:
   int r;
};

/**********************************************************************
 * << Overload
 * Overloads the << operator for circle class
 **********************************************************************/
ostream & operator << (ostream & out, const Circle & circle)
{
   out << "(" << circle.x << ", " << circle.y << ", r=" << circle.r << ")";
   return out;
}

/**********************************************************************
 * >> Overload
 * Overloads the << operator for the circle class
 **********************************************************************/
istream & operator >> (istream & in, Circle & circle)
{
   in >> circle.x >> circle.y >> circle.r;
   return in;
}

/**********************************************************************
 * MAIN: A simple driver program to exercise the Point and Circle
 *       classes. 
 ***********************************************************************/
int main()
{
   // point test
   Point pt;
   cout << "Please enter a position (x y): ";
   cin  >> pt;
   cout << pt << endl;

   // circle test
   Circle circle;
   cout << "Please enter a circle (x y radius): ";
   cin  >> circle;
   cout << circle << endl;
   
   return 0;
}


/*********************************************
 * POINT INSERTION
 * Write a point to the screen
 ********************************************/
ostream & operator << (ostream & out, const Point & pt)
{
   out << '(' << pt.x << ", " << pt.y << ')';
   return out;
}

/********************************************
 * POINT EXTRACTION
 * Read a point in from the user
 *******************************************/
istream & operator >> (istream & in, Point & pt)
{
   in >> pt.x >> pt.y;
   return in;
}

