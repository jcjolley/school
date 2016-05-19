/***********************************************************************
* Program:
*    Example 1.4: Tic-Tac-Toe
*    Brother Helfrich, CS165
* Author:
*    Br. Helfrich
* Summary: 
*    This program corresponds to the design document presented in chapter
*    1.0: the game of Tic-Tac-Toe
************************************************************************/

#include "ticTacToe.h"   // the Board
#include "interface.h"   // for interface.h
#include "game.h"        // for the game logic

#include <iostream>
using namespace std;

/**********************************************************************
 * Main: Interact with the game and prompt the user to save at the end.
 ***********************************************************************/
int main()
{
   // set up the board
   Game game;
   cout << "Here!\n";
   game.board[1][1] = '?';
   clearBoard(game);
   cout << "Here!\n";
   for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
         cout << "-" << game.board[i][j];
   cout << endl;
   cout << "Here!\n";

   // let the users play the game
   interact(game);

   return 0;
}
