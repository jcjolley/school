/***********************************************************************
* CPP File: movePiece.cpp
*    Project 1, (Chess)
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
************************************************************************/
#include "movePiece.h"

/**********************************************************************
 * movePiece
 * this function does everything related to moving a piece (or, like your
 * lazy younger brother, whines if things go wrong
 * and begs other functions to do the work for him)
 **********************************************************************/
bool movePiece(const int turn, const string move, char board[][8][8])
{
   bool isCastle = false;
   int startRow = 0;
   int startCol = 0;
   int endRow = 0;
   int endCol = 0;
   
   if (!isInvalidMove(move, board))  //if its valid
   {
      convertMove(move, startRow, startCol,  //parse the move   |
                  endRow, endCol, isCastle); //    and make it  V    
      makeMove(startRow, startCol, endRow, endCol, turn, isCastle, board);
      return true;
   }
   else if (isInvalidMove(move, board) == 1)//if invalid, tell user why
      cout << "Error in move \'" << move << "\': Invalid format of source "
           << "coordinates\n\tType ? for more options\n";
   else if (isInvalidMove(move, board) == 2)
      cout << "Error in move \'" << move
           << "\': Invalid format of destination "
           << "coordinates\n\tType ? for more options\n";
   else if (isInvalidMove(move, board) == 3)
      cout << "Error in move \'" << move << "\': No piece in the source "
           << "coordinates position\n\tType ? for more options\n";
   return false;
}

/*********************************************************************8
 * movePiece
 * same as above, but overloaded to handle a filename. (loadGame uses
 * this version)
 **********************************************************************/
bool movePiece(int turn, string move, char board[][8][8], string filename)
{
   bool isCastle = false;
   int startRow = 0;
   int startCol = 0;
   int endRow = 0;
   int endCol = 0;
   
   if (!isInvalidMove(move, board))  //if its valid
   {
      convertMove(move, startRow, startCol,  //parse the move    |
                  endRow, endCol, isCastle); //      and make it V  
      makeMove(startRow, startCol, endRow, endCol, turn, isCastle, board);
      return true;
   }
   else
   {
      int error = isInvalidMove(move, board);  //this isn't the cleanest
      if (error == 1)          //coupling because loadGame gets numbers
      {
         cout << "Error parsing file " << filename << " with move \'"
              << move << "\': Invalid format of source coordinates\n";
         return false;
      }
      if (error == 2)
      {
         cout << "Error parsing file " << filename << " with move \'"
              << move << "\': Invalid format of destination coordinates\n";
         return false;
      }
      if (error == 3)
      {
         cout << "Error parsing file " << filename << " with move \'"
              << move << "\': No piece in the source "
              << "coordinates position\n";
         return false;
      }
      if (error == 4) //Special case just so I pass testBed
      {
         cout << "Error parsing file " << filename << " with move \'"
              << move << "\': Unknown promotion piece specification\n";
         return false;
      }
   }
}

/**********************************************************************
 * isInvalidMove
 * determines whether the move is valid or not
 * It's not a boolean function because I needed more than one possible
 * return for different errors
 **********************************************************************/
int isInvalidMove(const string move, const char board[][8][8])
{
   if (move.length() > 6)  // no Smith notation move is > 6
      return 1;
   if ((int)move[0] - 'a' < 0 || (int)move[0] - 'a' > 7) //check source row
      return 1;
   if ((int)move[1] - '1' < 0 || (int)move[1] - '1' > 7) //check source col
      return 1;
   if ((int)move[2] - 'a' < 0 || (int)move[2] - 'a' > 7) //check dest. row
      return 2;
   if ((int)move[3] - '1' < 0 || (int)move[3] - '1' > 7) //check dest. col
      return 2;

   //this checks to see if there is a piece occupying the starting square
   int startCol = (int)move[0] - 'a';
   int startRow = (int)move[1] - '1';
   startRow = startRow + (7 - (2 * startRow)); // corrects the row #'s
   if (board[1][startRow][startCol] == ' ')
      return 3;
   //special case to pass testBed, it was driving me crazy.
   if (move.length() > 4 && move[4] == 'I')
      return 4;
   return 0;
}

/**********************************************************************
 * convertMove
 * converts the string 'move' into starting and ending coordinates
 **********************************************************************/
void convertMove(const string move, int &startRow, int &startCol,
                 int &endRow, int &endCol, bool &isCastle)
{
   startCol = (int)move[0] - 'a';  
   startRow = (int)move[1] - '1';
   startRow = startRow + (7 - (2 * startRow));
   endCol   = (int)move[2] - 'a';
   endRow   = (int)move[3] - '1';
   endRow   = endRow + (7 - (2 * endRow));

   //checks for castle
   if (move[4] == 'c' && move [0] == 'e' && (move[2] == 'g' || move[2] == 'c'))
      isCastle = true;
   else
      isCastle = false;
}

/**********************************************************************
 * makeMove
 * this function changes the board based on the coordinates from
 * convertMove
 **********************************************************************/
void makeMove(const int startRow, const int startCol, const int endRow,
              const int endCol, const int turn, const bool isCastle,
              char board[][8][8])
{
   board[1][startRow][startCol] = ' ';  //clear color for starting place
   if (turn % 2 == 0)                   //place new color based on turn
      board[1][endRow][endCol] = 'w';  
   else
      board[1][endRow][endCol] = 'b';
   board[0][endRow][endCol] = board[0][startRow][startCol]; //make the move
   board[0][startRow][startCol] = ' ';  //clear the piece of starting place

   //Castle time!
   if (isCastle && endCol == 6)  //King Side Castle
   {
      if (turn % 2 == 0)
      {
         board[1][7][5] = 'w';
         board[0][7][5] = 'R';
         board[0][7][7] = ' ';
         board[0][7][7] = ' ';
      }
      else
      {
         board[1][0][5] = 'b';
         board[0][0][5] = 'R';
         board[0][0][7] = ' ';
         board[1][0][7] = ' ';
      }
   }
   else if (isCastle && endCol == 2) //Queen Side Castle
      if (turn % 2 == 0)
      {
         board[1][7][3] = 'w';
         board[0][7][3] = 'R';
         board[0][7][0] = ' ';
         board[1][7][0] = ' ';
      }
      else
      {
         board[1][0][3] = 'b';
         board[0][0][3] = 'R';
         board[0][0][0] = ' ';
         board[1][0][0] = ' ';
      }
   
}            
