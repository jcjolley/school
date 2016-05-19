/***********************************************************************
* Program:
*    Assignment 35, Pure virtual functions
*    Brother Helfrich, CS165
* Author:
*    your name
* Summary: 
*    We are to take Assignment 3.4 one step further and make the
*    base class an abstract class. This means that we are to make
*    a new derrived class called Space and Piece will be abstract.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

/*********************************************
 * OUT << PIECE
 * Insertion operator for the piece
 ********************************************/
ostream & operator << (ostream & out, const Piece & rhs)
{
   out << rhs.getLetter();
   return out;
}

/**********************************************************************
 * MAIN: This is a driver program for our various piece classes.
 *       You are not allowed to change MAIN in any way
 ***********************************************************************/
int main()
{
   // make an array of pieces
   Piece * board[8][8];

   // the white army
   board[0][0] = new Rook  (true /*white*/);
   board[0][1] = new Knight(true /*white*/);
   board[0][2] = new Bishop(true /*white*/);
   board[0][3] = new Queen (true /*white*/);
   board[0][4] = new King  (true /*white*/);
   board[0][5] = new Bishop(true /*white*/);
   board[0][6] = new Knight(true /*white*/);
   board[0][7] = new Rook  (true /*white*/);

   // the pawns
   for (int col = 0; col < 8; col++)
   {
      board[1][col] = new Pawn  (true  /*white*/);
      board[6][col] = new Pawn  (false /*black*/);      
   }

   // the spaces
   for (int row = 2; row < 6; row++)
      for (int col = 0; col < 8; col++)
         board[row][col] = new Space;        // default constructor!
   
   // the black army
   board[7][0] = new Rook  (false /*black*/);
   board[7][1] = new Knight(false /*black*/);
   board[7][2] = new Bishop(false /*black*/);
   board[7][3] = new Queen (false /*black*/);
   board[7][4] = new King  (false /*black*/);
   board[7][5] = new Bishop(false /*black*/);
   board[7][6] = new Knight(false /*black*/);
   board[7][7] = new Rook  (false /*black*/);

   // display the board
   for (int row = 7; row >= 0; row--)
   {
      for (int col = 0; col < 8; col++)
         cout << *board[row][col];
      cout << endl;
   }

   // destroy everything
   for (int row = 0; row < 8; row++)
      for (int col = 0; col < 8; col++)
         delete board[row][col];

   return 0;
}
