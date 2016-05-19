/***********************************************************************
* Program:
*    Project 3, Chess with Objects
*    Brother Helfrich, CS165
* Author:
*    Br. Helfrich
* Summary: 
*    This file will keep track of the position on the board
************************************************************************/

#ifndef _POSITION_
#define _POSITION_

#include <string>
using std::string;
using std::ostream;
using std::istream;

/***********************************************
 * DELTA
 * Movement in a direction (dRow and dCol)
 **********************************************/
struct Delta
{
   int dRow;
   int dCol;
};

const Delta ADD_R = { 1,  0};
const Delta ADD_C = { 0,  1};
const Delta SUB_R = {-1,  0};
const Delta SUB_C = { 0, -1};

/***************************************************
 * POSITION
 * The location of a piece on the board
 ***************************************************/
class Position
{
  public:
      Position(const Position & rhs);
      Position() :             r(0), c(0), invalid(false) {}
      Position(int r, int c) : r(0), c(0), invalid(false)
      {
         setRow(r);
         setCol(c);
      }
      Position(const Position & rhs, const Delta & delta) : invalid(false)
      {
         set(rhs.r + delta.dRow, rhs.c + delta.dCol);
      }

      char getRow() const { return r;};
      char getCol() const { return c;};
      void setRow(int r)
      {
         if (r >= 0 && r <= 7)
            this->r = r;
         else
            invalid = true;
      }
      void setCol(int c)
      {
         if (c >= 0 && c <= 7)
            this->c = c;
         else
            invalid = true;
      }
      void set(int r, int c)    { setRow(r); setCol(c); }
      void adjustRow(int delta) { setRow(r + delta);    }
      void adjustCol(int delta) { setCol(c + delta);    }
      void setValid()           { invalid = false;      }
      void setInvalid()         { invalid = true;       }
      bool isInvalid() const    { return invalid;       }
      bool isValid() const      { return !invalid;      }
      bool operator == (const Position & rhs) const;
      bool operator != (const Position & rhs) const;
      const Position & operator =  (const Position & rhs);
      const Position & operator =  (const char     * rhs) throw ( string );
      const Position & operator =  (const string   & rhs) throw ( string )
      {
         *this = rhs.c_str();
         return *this;
      }
      const Position & operator += (const Delta & rhs)
      {
         setValid();
         adjustRow(rhs.dRow);
         adjustCol(rhs.dCol);

         return *this;
      }
      
         

  private:
      char r;
      char c;
      bool invalid;
};


ostream & operator << (ostream & out, const Position & pos);
istream & operator >> (istream & in,  Position & pos) throw ( string );
      
#endif // _POSITION_
