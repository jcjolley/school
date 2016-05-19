/***********************************************************************
* Header File: saveGame.cpp
*    Project 1, (Chess)
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
************************************************************************/

#include "saveGame.h"

/**********************************************************************
 * quitGame
 * saves the file and quits the game
 **********************************************************************/
void quitGame(const string moves[], const int turn)
{
   string filename = " ";
   getSavename(filename);   //get the filename
   if (!filename.size() == 0) //if there is a file name
      writeFile(moves, filename, turn); //write the moves to the file
}

/**********************************************************************
 * writeFile
 * writes the list of moves to the filename
 **********************************************************************/
void writeFile(const string moves[], const string filename, const int turn)
{
   ofstream fout(filename.c_str());
   if (fout.fail())
      cout << "Unable to open file " << filename << "for output.\n";
   for (int i = 0; i <= turn; i++) //for every turn
   {
      fout << moves[i] << " "; //write the turns
      if (i > 0 && i % 2 != 0)
         fout << "\n"; //print them in pairs
   }
   fout.close();
}


