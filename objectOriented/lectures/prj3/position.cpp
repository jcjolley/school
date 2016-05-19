/***********************************************************************
* Program:
*    Project 3, Chess with Objects
*    Brother Helfrich, CS165
* Author:
*    Br. Helfrich
* Summary: 
*    This fill will keep track of the position on the board
************************************************************************/

#include "position.h"
#include <iostream>
#include <cassert>

/***************************************************
 * POSITION : COPY CONSTRUCTOR
 ***************************************************/
Position::Position(const Position & rhs) : invalid(false)
{
   setRow(rhs.getRow());
   setCol(rhs.getCol());
}

/***********************************************
 * POSITION : INEQUALITY
 **********************************************/
bool Position::operator != (const Position & rhs) const
{
   return rhs.getRow() != getRow() || rhs.getCol() != getCol();
}

/***********************************************
 * POSITION : EQUALITY
 **********************************************/
bool Position::operator == (const Position & rhs) const
{
   return rhs.getRow() == r && rhs.getCol() == c;
}

/**********************************************
 * POSITION : ASSIGNMENT
 **********************************************/
const Position & Position::operator = (const Position & rhs)
{
   invalid = rhs.isInvalid();
   setRow(rhs.getRow());
   setCol(rhs.getCol());
   assert(invalid == rhs.isInvalid());

   return *this;
}

/**********************************************
 * POSITION : ASSIGNMENT
 **********************************************/
const Position & Position::operator = (const char * rhs) throw ( string )
{
   if (rhs == NULL)
      throw string("NULL string");

   if (rhs[0] < 'a' || rhs[0] > 'h' ||
       rhs[1] < '1' || rhs[1] > '8')
      throw string("Invalid specification of coordinates");

   setCol(rhs[0] - 'a');
   setRow(rhs[1] - '1');

   return *this;
}

/******************************************
 * POSITION INSERTION OPERATOR
 ******************************************/
ostream & operator << (ostream & out, const Position & rhs)
{
   out << (char)(rhs.getCol() + 'a')
       << (char)(rhs.getRow() + '1');

   return out;
}

/*************************************
 * POSITION EXTRACTION OPERATOR
 **************************************/
istream & operator >> (istream & in,  Position & rhs) throw ( string )
{
   char text[3] = {};
   in >> text[0] >> text[1];
   if (in.fail())
   {
      in.clear();
      in.ignore();
      throw string("Error reading coordinates");
   }
   else
   {
      rhs = text;
   }

   return in;   
}



