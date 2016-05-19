/***********************************************************************
* Program:
*    BOARD.CPP, Chess Project 3
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
//  board.cpp
//  Chess
//
//  Created by Joshua Jolley on 11/8/12.
//  Copyright (c) 2012 Joshua Jolley & Sam Barney. All rights reserved.
//

#include "board.h"
#include "pieces.h"
using namespace std;
/*****************************************************************
 * Board Constructor
 * Sets up the member variables of Board
 ******************************************************************/
Board::Board()
{
 
   board[7][0] = new Rook(Position(7,0));
   board[7][1] = new Knight(Position(7,1));
   board[7][2] = new Bishop(Position(7,2));
   board[7][3] = new Queen(Position(7,3));
   board[7][4] = new King(Position(7,4));
   board[7][5] = new Bishop(Position(7,5));
   board[7][6] = new Knight(Position(7,6));
   board[7][7] = new Rook(Position(7,7));
 
   
   board[6][0] = new Pawn(Position(6,0));
   board[6][1] = new Pawn(Position(6,1));
   board[6][2] = new Pawn(Position(6,2));
   board[6][3] = new Pawn(Position(6,3));
   board[6][4] = new Pawn(Position(6,4));
   board[6][5] = new Pawn(Position(6,5));
   board[6][6] = new Pawn(Position(6,6));
   board[6][7] = new Pawn(Position(6,7));
   
   board[5][0] = new BlankPiece(Position(5,0));
   board[5][1] = new BlankPiece(Position(5,1));
   board[5][2] = new BlankPiece(Position(5,2));
   board[5][3] = new BlankPiece(Position(5,3));
   board[5][4] = new BlankPiece(Position(5,4));
   board[5][5] = new BlankPiece(Position(5,5));
   board[5][6] = new BlankPiece(Position(5,6));
   board[5][7] = new BlankPiece(Position(5,7));

   board[4][0] = new BlankPiece(Position(4,0));
   board[4][1] = new BlankPiece(Position(4,1));
   board[4][2] = new BlankPiece(Position(4,2));
   board[4][3] = new BlankPiece(Position(4,3));
   board[4][4] = new BlankPiece(Position(4,4));
   board[4][5] = new BlankPiece(Position(4,5));
   board[4][6] = new BlankPiece(Position(4,6));
   board[4][7] = new BlankPiece(Position(4,7));

   board[3][0] = new BlankPiece(Position(3,0));
   board[3][1] = new BlankPiece(Position(3,1));
   board[3][2] = new BlankPiece(Position(3,2));
   board[3][3] = new BlankPiece(Position(3,3));
   board[3][4] = new BlankPiece(Position(3,4));
   board[3][5] = new BlankPiece(Position(3,5));
   board[3][6] = new BlankPiece(Position(3,6));
   board[3][7] = new BlankPiece(Position(3,7));

   board[2][0] = new BlankPiece(Position(2,0));
   board[2][1] = new BlankPiece(Position(2,1));
   board[2][2] = new BlankPiece(Position(2,2));
   board[2][3] = new BlankPiece(Position(2,3));
   board[2][4] = new BlankPiece(Position(2,4));
   board[2][5] = new BlankPiece(Position(2,5));
   board[2][6] = new BlankPiece(Position(2,6));
   board[2][7] = new BlankPiece(Position(2,7));

   board[1][0] = new Pawn(Position(1,0), true);
   board[1][1] = new Pawn(Position(1,1), true);
   board[1][2] = new Pawn(Position(1,2), true);
   board[1][3] = new Pawn(Position(1,3), true);
   board[1][4] = new Pawn(Position(1,4), true);
   board[1][5] = new Pawn(Position(1,5), true);
   board[1][6] = new Pawn(Position(1,6), true);
   board[1][7] = new Pawn(Position(1,7), true);

   board[0][0] = new Rook(Position(0,0), true);
   board[0][1] = new Knight(Position(0,1), true);
   board[0][2] = new Bishop(Position(0,2), true);
   board[0][3] = new Queen(Position(0,3), true);
   board[0][4] = new King(Position(0,4), true);
   board[0][5] = new Bishop(Position(0,5), true);
   board[0][6] = new Knight(Position(0,6), true);
   board[0][7] = new Rook(Position(0,7), true);
   
   board[5][0] = new BlankPiece(Position(5,0));
   board[5][0] = new BlankPiece(Position(5,0));
   board[5][0] = new BlankPiece(Position(5,0));
   board[5][0] = new BlankPiece(Position(5,0));
   board[5][0] = new BlankPiece(Position(5,0));
   board[5][0] = new BlankPiece(Position(5,0));
   board[5][0] = new BlankPiece(Position(5,0));
   board[5][0] = new BlankPiece(Position(5,0));
   
}
/*****************************************************************
 * movePiece
 * This function moves the piece 
 ******************************************************************/
bool Board::movePiece (Move & move)
{
   
   cerr << "The starting position: (" << move.getSrc().getRow() << ", " << move.getSrc().getCol() << ")\n";
   cerr << "The destination position: (" << move.getDes().getRow() << ", " << move.getDes().getCol() << ")\n";
   cerr << "The piece's position before moving: " << board[move.getSrc().getRow()][move.getSrc().getCol()]->getPos().getRow() << ", "
        << board[move.getSrc().getRow()][move.getSrc().getCol()]->getPos().getCol() << ")\n";
   
   //delete the piece we're moving to
   delete board[move.getDes().getRow()][move.getDes().getCol()];

   //move the piece from the source position to the destination position 
   board[move.getDes().getRow()][move.getDes().getCol()] = board[move.getSrc().getRow()][move.getSrc().getCol()];


   board[move.getSrc().getRow()][move.getSrc().getCol()] = new BlankPiece(Position(move.getSrc().getRow(), move.getSrc().getCol()));
   
      board[move.getDes().getRow()][move.getDes().getCol()]->setPos(move.getDes().getRow(),move.getDes().getCol());
   cerr << "The piece's position after moving: (" << board[move.getDes().getRow()][move.getDes().getCol()]->getPos().getRow() << ", "
        << board[move.getDes().getRow()][move.getDes().getCol()]->getPos().getCol() << ")\n";
   return true;
}
/*****************************************************************
 * Draw
 * This function draws 
 ******************************************************************/
void Board::draw()
{
   cout << "  abcdefgh" << endl;
   for (int row = 7; row >= 0; row--)
      {
         cout << row + 1 << " ";
         for (int col = 0; col < 8; col++)
           board[row][col]->draw();
         cout << endl;
      }
}
/*****************************************************************
 *~Board Destructor
 *
 ******************************************************************/
Board::~Board()
{
   for (int row = 0; row < 8; row++)
      for (int col = 0; col < 8; col++)
         delete board[row][col];
}

/*****************************************************************
 *
 *
 ******************************************************************/

/*****************************************************************
 *
 *
 ******************************************************************/