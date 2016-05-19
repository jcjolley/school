/***********************************************************************
* Program:
*    BOARD.H, Chess Project 3
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
//  board.h
//  Chess
//
//  Created by Joshua Jolley on 11/8/12.
//  Copyright (c) 2012 Joshua Jolley & Sam Barney. All rights reserved.
//

#ifndef __Chess__board__
#define __Chess__board__
#include "pieces.h"
#include "move.h"

/****************************************************************
 * Class Board
 * Board is in charge of holding and moving the pieces.
 ****************************************************************/

class Board
{
public:
   Board();
   bool movePiece(Move & move);
   void draw();
   ~Board();
   //Piece * operator [](Position pos)
   //{
   //return board[pos.getRow()][pos.getCol()];
   //}
private:
   Piece * board[8][8];
   void swap(int row, int col);
};

#endif /* defined(__Chess__board__) */
