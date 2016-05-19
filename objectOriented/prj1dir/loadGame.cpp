/***********************************************************************
* CPP File: loadGame.cpp
*    Project 1, (Chess)
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
************************************************************************/
#include "loadGame.h"
#include "movePiece.h"
#include "chess.h"

/**********************************************************************
 * loadGame
 * this function handles everything related to loading a game from a file
 **********************************************************************/
bool loadGame(int &turn, string moves[], char board[][8][8])
{
   
   string filename = " ";
   string move = " ";
   int numMoves = 0;

   getFilename(filename);  //get the file name   
   if (readFile(moves, numMoves, filename)) //read the file       
   {
      //if we're succesful set everything up
      turn = 0;
      resetBoard(board);

      //and make the moves
      for (int i = 0; i < numMoves; i++)
      {
         move = moves[i];
         if (! movePiece(turn,move,board,filename)) //use overloaded movePiece
            return false;
         turn++;
      }
   }
   return true;
}

/**********************************************************************
 * readFile
 * reads the file
 **********************************************************************/
bool readFile(string moves[], int &numMoves, const string filename)
{
   ifstream fin(filename.c_str()); //open the file
   
   if (fin.fail())
   {
      cout << "Unable to open file " << filename << " for input\n";
      fin.close();
      return false;
   }
   while (fin >> moves[numMoves]) //read the moves one at a time
      numMoves++;
   
   fin.close();
   return true;
}

