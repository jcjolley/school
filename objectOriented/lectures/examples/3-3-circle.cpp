/***********************************************************************
 * This program is deisgned to:
 *    Demonstrate simple inheritance
 ************************************************************************/

#include <iostream>
using namespace std;


/***********************************************************
 * Point: Position of an item on the screen.
 ***********************************************************/
class Point
{
   public:
      Point() : x(0), y(0)    {                         }
      Point(int x, int y)     { setX(   x); setY(   y); }
      Point(const Point & pt) { setX(pt.x); setY(pt.y); }
      int  getX() const       { return x;               }
      int  getY() const       { return y;               }
      void setX(int x)        { this->x = x;            }
      void setY(int y)        { this->y = y;            }
      friend ostream & operator << (ostream & out, const Point & pt);
      friend istream & operator >> (istream & in ,       Point & pt); 
   protected:
      int x;
      int y;
};

/**********************************************
 * Circle: A circle is a point with a radius
 **********************************************/
class Circle : public Point
{
   public:
      Circle(const Circle & circle) : Point(circle.x, circle.y), r(r) {}
      Circle()                      : Point(), r(0)    {               }
      Circle(int r, int x, int y)   : Point(x, y)      { setRadius(r); }
      int  getRadius()                                 { return r;     }
      void setRadius(int r)                            { this->r = r;  }
      friend ostream & operator << (ostream & out, const Circle & c);
      friend istream & operator >> (istream & in ,       Circle & c);
   private:
      int r;
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
   in >> pt.x >> pt.y;
   return in;
}

/*********************************************
 * CIRCLE INSERTION
 * Write a circle to the screen
 ********************************************/
ostream & operator << (ostream & out, const Circle & circle)
{
   out << '('    << circle.x                 // access to Point's privates
       << ", "   << circle.y
       << ", r=" << circle.r                 // the same as Circle's privates
       << ')';
   return out;
}

/********************************************
 * CIRCLE EXTRACTION
 * Read a circle in from the user
 *******************************************/
istream & operator >> (istream & in, Circle & circle)
{
   in >> circle.x >> circle.y >> circle.r;   // access to Point's privates
   return in;
}
