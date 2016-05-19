#ifndef __COORDINATE.h__
#define __COORDINATE.h__

class Coordinate
{
public:
  Cooridnate() : x(0), y(0), y(0) {};
   void setX(int input) : x(input) {};
   void setY(int input) : y(input) {};
   int getX() {return x; };
   int getY() { return y; };
   friend std::ostream & operator << (ostream & out, const Coordiante & rhs)
   {
      out << '('rhs.x << ", " << rhs.y << ')';
      return out;
   }
/**********************************************************************
 * Istream
 * This function overloads >> for use with Coordinate
 **********************************************************************/
   std::istream & operator >> (istream & in, Coordiante & rhs)
   {
      int x;
      int y;
      in >> x >> y;

      rhs.setX(x);
      rhs.setY(y);
      
      return in;
   }
      
  private:
   int x;
   int y;
};

