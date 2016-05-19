/***********************************************************************
* Program:
*    POSITION.H, Chess Project 3
*    Brother Helfrich, CS165
* Author:
*    Sam Barney and Joshua Jolley
* Summary:
*    This program is on it's way to becoming a full fledged Chess
*    program!
*    Estimated:  3.0 hrs
*    Actual:     7.0 hrs
*    Tired programming and silly mistakes
**********************************************************************/
//
//  position.h
//  Chess
//
//  Created by Samuel Barney on 11/7/12.
//  Copyright (c) 2012 CS165. All rights reserved.
//

#ifndef __Chess__position__
#define __Chess__position__
#include <iostream>
#include <string>

class Position
{
public:
   Position() {}
   Position(const Position & copy) { row = copy.row; col = copy.col; }
   Position(char * s) { *this = s; }
   Position(const char * s) { *this = (char*)s; }
   Position(int aRow, int aCol) { row = aRow; col = aCol; }
   Position & operator = (char * s) throw(std::string);
   Position & operator = (const Position & rhs) {row = rhs.row; col = rhs.col; return *this;}
   int getRow() const {return row;}
   int getCol() const {return col;}
   void setRow(int x) { row = x; }
   void setCol(int y) { col = y; }
   bool operator== (const Position & rhs) const
   {
      return getRow() == rhs.getRow() && getCol() == rhs.getCol();
   }
   
   friend std::ostream & operator << (std::ostream & out, const Position & pos);
   //friend std::istream & operator >> (std::istream & in, Position & pos);
   
private:
   
   int row;
   int col;
 
};

#endif /* defined(__Chess__position__) */
