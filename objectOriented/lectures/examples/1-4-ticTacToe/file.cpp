/***********************************************************************
* Component:
*    File.cpp
*    Brother Helfrich, CS165
* Author:
*    Br. Helfrich
* Summary: 
*    All the File I/O for Tic-Tac-Toe
************************************************************************/

#include "file.h"

#include <iostream>    // for error messages
#include <fstream>     // for ifstream and ofstream
#include <cassert>     // because I am paranoid
using namespace std;

/**********************************************
 * READ BOARD
 * Prompt the user for a filename and read the
 * the board from a file
 *********************************************/
void readBoard(const string & fileName, Game & game)
{
   assert(fileName.length() != 0);

   // open the file
   ifstream fin(fileName.c_str());

   try
   {
      if (fin.fail())                        
         throw "Unable to open file";        

      // read the contents of the file
      int numXoverO = 0;
      for (int row = 0; row < 3; row++)
         for (int col = 0; col < 3; col++)
         {
            // read the item from the board
            fin >> game.board[row][col];

            // check for failure.
            if (fin.fail())                 
               throw "Error reading file "; 

            // keep track of whose turn it is
            if (game.board[row][col] == 'X')
               numXoverO++;
            else if (game.board[row][col] == 'O')
               numXoverO--;
            else if (game.board[row][col] != '.')
               throw "Unexpected symbol";    
         }

      // determine whose turn it is by the xOverO count   
      game.xTurn = (numXoverO == 0 ? true : false);
      if (numXoverO != 0 && numXoverO != 1) 
         throw "Invalid board";           
   }
   catch (const char * message)           
   {                                      
      cout << "Error: "   << message      
           << " in file " << fileName     
           << ".\n";
   }

   // close the file
   fin.close();
}              

/*******************************************************
 * WRITE BOARD
 * Write the contents of the board to a file
 ******************************************************/
void writeBoard(const string & fileName, const Game & game)
{
   // open the file
   ofstream fout(fileName.c_str());
   if (fout.fail())
   {
      cout << "Unable to write to file "
           << fileName
           << ".\n";
      return;
   }

   // write the contents
   for (int row = 0; row < 3; row++)
   {
      for (int col = 0; col < 3; col++)
         fout << game.board[row][col];
      fout << endl;
   }

   // close the file
   fout.close();               
}

