/***********************************************************************
* CPP File: display.cpp
*    Project 1, (Chess)
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
************************************************************************/

#include "display.h"


/**********************************************************************
 * displayTest
 * shows the display without all the fancy colors and spacing
 **********************************************************************/
bool displayTest(const char board[][8][8])
{

   cout << "  abcdefgh\n";
   for (int row = 0; row < 8; row++)
      for (int col = 0; col < 8; col++)
      {
         if (col == 0)
            //the rows are backwards, this math sets it right
            cout << row + (7 - (2 * row)) + 1 << " ";
         if (board[1][row][col] == 'w') //if it is white
            cout << (char)tolower(board[0][row][col]); //make it lowercase
         else if (board[1][row][col] == 'b') //if it's black
            cout << (char)toupper(board[0][row][col]); //uppercase!
         else
            cout << board[0][row][col];  //if it's empty, who cares? ;)
         if (col == 7)
            cout << endl;
      }
                            
   return true;
}

/**********************************************************************
 * displayBoard
 * displays the chessboard and pieces in fancy colors
 **********************************************************************/
void displayBoard(const char board[][8][8])
{
   system("clear");
   cout << "   a  b  c  d  e  f  g  h \n"; //header

   //I put off making this elegant until I ran out of time.  My bad :(
   for (int row = 0; row < 8; row++)
      for (int col = 0; col < 8; col++)
      {
         if (col == 0)
            cout << row + (7 - (2 * row)) + 1 << " ";  //correct rows
         if (row % 2 == 0 && col % 2 == 0 && board[1][row][col] == 'w')
            cout << "\E[31;47m" << " " << board[0][row][col] << " "
                 << "\E[0m";
         if (row % 2 == 0 && col % 2 != 0 && board[1][row][col] == 'w')
            cout << "\E[37;41m " << board[0][row][col] << " \E[0m";
         if (row % 2 == 0 && col % 2 == 0 && board[1][row][col] == 'b')
            cout << "\E[30;47m" << " " << board[0][row][col] << " "
                 << "\E[0m";
         if (row % 2 == 0 && col % 2 != 0 && board[1][row][col] == 'b')
            cout << "\E[30;41m " << board[0][row][col] << " \E[0m";
         if (row % 2 == 0 && col % 2 == 0 && board[1][row][col] == ' ')
            cout << "\E[47m   \E[0m";
         if (row % 2 == 0 && col % 2 != 0 && board[1][row][col] == ' ')
            cout << "\E[41m   \E[0m";
         
         if (row % 2 != 0 && col % 2 != 0 && board[1][row][col] == 'w')
            cout << "\E[31;47m" << " " << board[0][row][col] << " "
                 << "\E[0m";
         if (row % 2 != 0 && col % 2 == 0 && board[1][row][col] == 'w')
            cout << "\E[37;41m " << board[0][row][col] << " \E[0m";
         if (row % 2 != 0 && col % 2 != 0 && board[1][row][col] == 'b')
            cout << "\E[30;47m" << " " << board[0][row][col] << " "
                 << "\E[0m";
         if (row % 2 != 0 && col % 2 == 0 && board[1][row][col] == 'b')
            cout << "\E[30;41m " << board[0][row][col] << " \E[0m";
         if (row % 2 != 0 && col % 2 != 0 && board[1][row][col] == ' ')
            cout << "\E[47m   \E[0m";
         if (row % 2 != 0 && col % 2 == 0 && board[1][row][col] == ' ')
            cout << "\E[41m   \E[0m";
         if (col == 7) //new line at the end of each row
            cout << endl;
      }
}

