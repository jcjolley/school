/***********************************************************************
* Header File: chess.h
*    Project 1, (Chess)
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
************************************************************************/

#ifndef CHESS_H
#define CHESS_H

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>
using namespace std;

#ifdef DEBUG
#define debug(x) cout << #x << ": " << x << endl;
#else
#define debug(x)
#endif


inline void resetBoard(char board[][8][8]);

/**********************************************************************
 * resetBoard
 * resets the Board to starting positions
 **********************************************************************/
inline void resetBoard (char board[][8][8])
{
   for (int row = 0; row < 8; row++)
   {
      for (int col = 0; col < 2; col++)
         board[1][col][row] = 'b';
      for (int col = 1; col < 2; col++)
         board[0][col][row] = 'p';
      for (int col = 2; col < 6; col++)
      {
         board[1][col][row] = ' ';
         board[0][col][row] = ' ';
      }
      for (int col = 6; col < 8; col++)
         board[1][col][row] = 'w';
      for (int col = 6; col < 7; col++)
         board[0][col][row] = 'p';
   }
   board[0][0][0] = 'R';
   board[0][7][0] = 'R';
   board[0][0][1] = 'N';
   board[0][7][1] = 'N';
   board[0][0][2] = 'B';
   board[0][7][2] = 'B';
   board[0][0][3] = 'Q';
   board[0][7][3] = 'Q';
   board[0][0][4] = 'K';
   board[0][7][4] = 'K';
   board[0][0][5] = 'B';
   board[0][7][5] = 'B';
   board[0][0][6] = 'N';
   board[0][7][6] = 'N';
   board[0][0][7] = 'R';
   board[0][7][7] = 'R';
}

#endif
