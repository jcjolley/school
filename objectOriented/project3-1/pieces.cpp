/***********************************************************************
* Program:
*    PIECES.CPP, Chess Project 3
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
//  Pieces.cpp
//  Chess
//
//  Created by Samuel Barney on 11/5/12.
//  Copyright (c) 2012 CS165. All rights reserved.
//

#include "pieces.h"
#include <iostream>
#define WHITE_WHITE "\E[31;47m"
#define RED_WHITE "\E[37;41m"  
#define WHITE_BLACK "\E[30;47m"
#define RED_BLACK "\E[30;41m"
#define CLEAR     "\E[0m"

using namespace std;

// Initialization section for statics
bool Piece::fSimple = false;
int Piece::currentMove = 0;


float spaceValues[8][8] = {
   {0.0, 0.0, 0.1, 0.2, 0.2, 0.1, 0.0, 0.0},
   {0.0, 0.1, 0.2, 0.3, 0.3, 0.2, 0.1, 0.0},
   {0.1, 0.2, 0.3, 0.4, 0.4, 0.3, 0.2, 0.1},
   {0.2, 0.3, 0.4, 0.4, 0.4, 0.4, 0.3, 0.2},
   {0.2, 0.3, 0.4, 0.4, 0.4, 0.4, 0.3, 0.2},
   {0.1, 0.2, 0.3, 0.4, 0.4, 0.3, 0.2, 0.1},
   {0.0, 0.1, 0.2, 0.3, 0.3, 0.2, 0.1, 0.0},
   {0.0, 0.0, 0.1, 0.2, 0.2, 0.1, 0.0, 0.0}
};

void Piece::draw()
{
   /*if (curPos.getRow() + curPos.getCol() % 2 == 0)
   {
      if (isWhite())
      {
         cout << WHITE_WHITE;
      }
      else
      {
         cout << WHITE_BLACK;
      }
   }
   else
   {
      if (isWhite())
      {
         cout << RED_WHITE;
      }
      else
      {
         cout << RED_BLACK;
      }
   }
   if (!isSimple())
   {

      cout << ' ' << getRank() << ' ';
   }
   else */
   //{
      char rank = (isWhite())? tolower(getRank()) : getRank();
      cout << rank;
   //}
   //cout << CLEAR;

}
/********************************************************************************
 * Piece::getSpace
 *    INPUTS:
 *    RETURNS: float
 *    DESCRIPTION:
 *       Returns the value for the space the piece is on.
 ********************************************************************************/
float Piece::getSpace()
{
   if (getRank() != ' ')
   {
      return spaceValues[curPos.getCol()][curPos.getRow()];
   }
   return 0.0;
}
