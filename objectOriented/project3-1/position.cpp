/***********************************************************************
* Program:
*    POSITION.CPP, Chess Project 3
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
//  position.cpp
//  Chess
//
//  Created by Samuel Barney on 11/7/12.
//  Copyright (c) 2012 CS165. All rights reserved.
//

#include "position.h"
#include <cctype>
#include <cassert>
using namespace std;
/*********************************************************
* Operator = Overload
* This function will allow us to use the = operator with
* the position class
*********************************************************/
Position & Position::operator = (char * s) throw(string)
{
   //make it lowercase
   s[0] = tolower(s[0]);
   
   
   //validate input
   if (s[0] < 'a' || s[0] > 'h' || s[1] < '1' || s[1] > '8')
      //throw a string if we fail
      throw string("Error: Validation of position failed");
   
   //setRow
   setCol((int)s[0] - 'a');
   assert (col >= 0 && col < 8);
   
   //setcol
   setRow((int)s[1] - '1');
   assert (row >=0 && row < 8);
   
   return *this;
}


/*********************************************************
 *
 *
 *
 *********************************************************/
std::ostream & operator << (std::ostream & out, const Position & pos)
{
   out << "(" << pos.row << "," << pos.col << ")";
   return out;
}

/*********************************************************
 *
 *
 *
 *********************************************************/



/*********************************************************
 *
 *
 *
 *********************************************************/


/*********************************************************
 *
 *
 *
 *********************************************************/



/*********************************************************
 *
 *
 *
 *********************************************************/