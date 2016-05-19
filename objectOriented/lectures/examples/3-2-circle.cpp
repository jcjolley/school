/***********************************************************************
 * This program is design to:
 *    Demonstrate inheritance.
 ************************************************************************/

#include <iostream>
using namespace std;


/***********************************************************
 * Point: Position of an item on the screen.
 ***********************************************************/
class Point
{
public:
   Point() : x(0), y(0)   {                         }
   Point(int x, int y)    { setX(   x); setY(   y); }
   Point(const Point &pt) { setX(pt.x); setY(pt.y); }
   int  getX() const      { return x;               }
   int  getY() const      { return y;               }
   void setX(int x)       { this->x = x;            }
   void setY(int y)       { this->y = y;            }
   friend ostream & operator << (ostream & out, const Point & pt);
   friend istream & operator >> (istream & in ,       Point & pt);
private:
   int x;
   int y;
};

/**********************************************
 * Circle: A circle is a point with a radius
 **********************************************/
class Circle : public Point
{
public:
   Circle()                    : Point(), radius(0) {                    }
   Circle(int r, int x, int y) : Point(x, y)        { setRadius(r);      }
   Circle(const Circle & circle);
   int  getRadius()                                 { return radius;     }
   void setRadius(int r)                            { this->radius = r;  }
   friend ostream & operator << (ostream & out, const Circle & c);
   friend istream & operator >> (istream & in ,       Circle & c);
private:
   int radius;
};


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
   in >> pt.x >> pt.y;              // direct access to x and y is possible
   return in;                       //    because this function is a friend
}                                   //    to Point

/********************************************
 * CIRCLE COPY CONSTRUCTOR
 * Copy a circle.
 *******************************************/
Circle :: Circle(const Circle & circle)
{
   setX(circle.getX());             // we must use the public Point::getX() and
   setY(circle.getY());             //    Point::setX() to change x and y
   radius = circle.radius;          // direct access to radius is possible
}                                   //    because radius is part of Circle

/*********************************************
 * CIRCLE INSERTION
 * Write a circle to the screen
 ********************************************/
ostream & operator << (ostream & out, const Circle & circle)
{
   out << '('    << circle.getX()   // need to use getters here.  The member
       << ", "   << circle.getY()   //   variables are not accessible.
       << ", r=" << circle.radius   // we do have access to the radius private
       << ')';
   return out;
}

/********************************************
 * CIRCLE EXTRACTION
 * Read a circle in from the user
 *******************************************/
istream & operator >> (istream & in, Circle & circle)
{
   int x;                            // we don't have access to Point::x so
   int y;                            //    we need to read into variables

   // read data from in   
   in >> x >> y >> circle.radius;    // since radius is part of Circle and >>
                                     //    is a friend, we use circle.radius
   // now set the values
   circle.setX(x);                   // only the public Point::setX() and
   circle.setY(y);                   //    Point::setY() is visible to Circle
   return in;
}
