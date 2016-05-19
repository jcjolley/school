/***********************************************************************
* Program:
*    PIECES.H, Chess Project 3
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
//  public Pieces.h
//  Chess
//
//  Created by Samuel Barney on 11/5/12.
//  Copyright (c) 2012 CS165. All rights reserved.
//

#ifndef __Chess__Pieces__
#define __Chess__Pieces__

#include "position.h"

/********************************************************************************
 * struct Delta
 ********************************************************************************/
struct Delta
{
   char x;
   char y;
};

/********************************************************************************
 * class Piece
 ********************************************************************************/
class Piece
{
private:
   bool teamWhite;
   static bool fSimple;
   static int currentMove;
protected:
   Position curPos;
   int nMoves;
public:
   Piece(Position pos, bool isWhite): teamWhite(isWhite), curPos(pos) {}
   float getSpace();
   virtual char getRank() = 0;
   virtual int getForce() = 0;
   virtual int getTime() = 0;
   void setPos(Position pos) { curPos = pos; }
   void setPos(int row, int col) {curPos.setRow(row); curPos.setCol(col);}
   Position & getPos() {return curPos;}
   bool isWhite()                   { return teamWhite;                    }
   bool isSimple()                  { return fSimple;                      }
   int getCurrentMove()             { return currentMove;                  }
   bool operator==(char pieceType)  { return getRank() == pieceType;       }
   void draw();
   virtual ~Piece(){}
};


/********************************************************************************
 * class BlankPiece
 ********************************************************************************/
class BlankPiece : public Piece
{
public:
   BlankPiece(Position pos) : Piece(pos, false) {}
   char getRank() { return ' '; }
   int getForce() { return 0; }
   int getTime() { return 0; }
};

/********************************************************************************
 * class Pawn
 ********************************************************************************/
class Pawn : public Piece
{
   int firstMoved;
public:
   Pawn(Position pos, bool isWhite = false) : Piece(pos, isWhite), firstMoved(0) {}
   char getRank() { return 'P'; }
   int getForce() { return 0; }
   int getTime() { return 0; }
};

/********************************************************************************
 * class Rook
 ********************************************************************************/
class Rook : public Piece
{
   
public:
   Rook(Position pos, bool isWhite = false) : Piece(pos, isWhite) {}
   char getRank() { return 'R'; }
   int getForce() { return 0; }
   int getTime() { return 0; }
};

/********************************************************************************
 * class Knight
 ********************************************************************************/
class Knight : public Piece
{
    
public:
   Knight(Position pos, bool isWhite = false) : Piece(pos, isWhite) {}
   char getRank() { return 'N'; }
   int getForce() { return 0; }
   int getTime() { return 0; }
};

/********************************************************************************
 * class Bishop
 ********************************************************************************/
class Bishop : public Piece
{
    
public:
   Bishop(Position pos, bool isWhite = false) : Piece(pos, isWhite) {}
   char getRank() { return 'B'; }
   int getForce() { return 0; }
   int getTime() { return 0; }
};

/********************************************************************************
 * class Queen
 ********************************************************************************/
class Queen : public Piece
{
    
public:
   Queen(Position pos, bool isWhite = false) : Piece(pos, isWhite) {}
   char getRank() { return 'Q'; }
   int getForce() { return 0; }
   int getTime() { return 0; }
};

/********************************************************************************
 * class King
 ********************************************************************************/
class King : public Piece
{
   int firstMoved;
public:
   King(Position pos, bool isWhite = false) : Piece(pos, isWhite), firstMoved(0) {}
   char getRank() { return 'K'; }
   int getForce() { return 0; }
   int getTime() { return 0; }
};

#endif /* defined(__Chess__Pieces__) */
