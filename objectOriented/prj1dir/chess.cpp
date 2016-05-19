/***********************************************************************
* Program:
*    Project 1, (Chess)
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
* Summary: 
*    Plays Chess, loading a file, saving a file, displaying the board
*    in color.  Does not enforce rules.
*    Estimated:  8.0 hrs   
*    Actual:     10.0 hrs
*      Getting the design together was the hardest part... that and
*    attempting to revise it with the newer concepts taught in class.
************************************************************************/

#include "chess.h"
#include "display.h"
#include "interact.h"

/**********************************************************************
* Main
* This is the driver function.  It initializes the board and passes it
* off to interact.
***********************************************************************/
int main()
{
   char board[2][8][8] = {};  
   resetBoard(board);       //resets the board to a fresh game
   displayBoard(board);     //displays the board
   interact(board);         //starts the game
   
   return 0;
}

