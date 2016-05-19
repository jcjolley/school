/***********************************************************************
* Program:
*    Project 3, Chess with Objects
*    Brother Helfrich, CS165
* Author:
*    The Key
* Summary: 
*    This fill will keep track of the move on the board
************************************************************************/

#include <iostream>
#include "piece.h"
#include "move.h"
#include "position.h"
using namespace std;


// Two statics in the Piece class: the simple flag indicating that we
//    have the Test board displayed instead of the colorful board, and
//    the currentMove so each piece can tell if it's move was the last move
bool Piece::fSimple = false;   // not starting off in Test mode
int  Piece::currentMove = 0;   // starting at move 0

/*************************************
 * main
 **************************************/
int main()
{
   // rook
   Rook rook(0 /*row*/, 0 /*col*/, true /*white*/);
   cout << "rook:   " << rook << endl;

   // bishop
   Bishop bishop(0, 1, false /*white*/);
   cout << "bishop: " << bishop << endl;

   // knight
   Knight knight(0, 2, true /*white*/);
   cout << "knight: " << knight << endl;

   // queen
   Queen queen(0, 3, false /*white*/);
   cout << "queen:  " << queen << endl;

   // king
   King king(0, 4, true /*white*/);
   cout << "king:   " << king << endl;

   // pawn
   Pawn pawn(0, 5, false /*white*/);
   cout << "pawn:   " << pawn << endl;

   // space
   Space space(0, 6);
   cout << "space:  " << space << endl;
   
   // make a list of pieces
   Piece * list[7] =
   {
      &rook,
      &bishop,
      &knight,
      &queen,
      &king,
      &pawn,
      &space
   };
   for (int i = 0; i < 7; i++)
      cout << *list[i];
   cout << endl;
      
   
   return 0;

}

