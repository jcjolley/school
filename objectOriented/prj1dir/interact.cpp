/***********************************************************************
* CPP File: interact.cpp
*    Project 1, (Chess)
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
************************************************************************/

#include "interact.h"
#include "display.h"
#include "movePiece.h"
#include "loadGame.h"
#include "saveGame.h"

/**********************************************************************
 * interact
 * This function controls all user interaction. It uses a while loop
 * to continue until the user inputs 'quit'
 **********************************************************************/
void interact(char board[][8][8])
{
   bool test = false;          //test display or not
   int turn = 0;
   string moves[256] = {" "};  //next time I'll use a vector
   string move = "filler";
   
   while (move != "quit")
   {
      //turn is a count of sucessful moves and is used to detmine
      //whose turn it is.
      if (turn % 2 == 0)
         cout << "(White): ";
      else
         cout << "(Black): ";
      cin  >> move;

      //I could have used move == '?' but I figured compare doesn't
      //get enough love.  Is compare what is called when you use == ?
      if (move.compare("?") == 0)
         displayOptions();    //displays options
      else if (move.compare("read") == 0)
      {
         if(loadGame(turn,moves,board))  //loads the game
         {
            if(!test)
               displayBoard(board);  //displays the board
            else
               displayTest(board);  //displays the test board
         }
      }
      else if (move.compare("test") == 0)
         test = displayTest(board);  //returns true when called
      else if (move.compare("quit") == 0)
         quitGame(moves, turn);       //quits the game
      else
      {
         if (movePiece(turn,move,board))  //not a command? must be a move
         {
            //this only happens if a piece was actually moved
            listMoves(turn,move,moves);  //keeps a running list of moves
            turn++;
            if(!test)
               displayBoard(board);  //displays the board
            else
               displayTest(board);  //displays the test board
         }
      }
      
   }
}



