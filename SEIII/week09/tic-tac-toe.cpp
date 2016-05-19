/**********************************************************************
 * Program:
 *    Lesson 08, Tic-Tac-Toe
 * Summary: 
 *    This program reads, displays, and writes a Tic-Tac-Toe board
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <cassert>

#define X_MARK 'X'
#define O_MARK 'O'
#define NO_MARK '.'
#define SIZE 3
#define debug(x) cout << #x << ": " << x << endl
using namespace std;

bool read(         char board[][SIZE], const char* fileName);
bool write(  const char board[][SIZE], const char* fileName);
void display(const char board[][SIZE]);
bool didWin( const char board[][SIZE], char turn);
bool checkRows(const char board[][SIZE],char turn);
bool checkCols(const char board[][SIZE],char turn);
bool checkBackwardDiagonals(const char board[][SIZE],char turn);
bool checkForwardDiagonals(const char board[][SIZE],char turn);

/**********************************************************************
 * Keeps the data and calles the read/display/write functions
 ***********************************************************************/
int main()
{
   char board[SIZE][3];

   // read the board
   char fileName[256];
   cout << "Enter source filename: ";
   cin  >> fileName;
   if (!read(board, fileName))
   {
      cout << "ERROR: Unable to open file \"" << fileName << "\"\n";
      return 1;
   }

   // display the board
   display(board);

   // write the board to a file
   cout << "Enter destination filename: ";
   cin  >> fileName;
   if (!write(board, fileName))
   {
      cout << "ERROR: Unable to open file \"" << fileName << "\"\n";
      return 1;
   }

   return 0;
}

/**************************************************************
 * READ
 * Read the board from the specified filename
 *************************************************************/
bool read(char board[][SIZE], const char* fileName)
{
   assert(*fileName);

   // open the file
   ifstream fin(fileName);
   if (fin.fail())
      return false;

   // read 9 symbols, hopefully they are . X O
   for (int r = 0; r < SIZE; r++)
      for (int c = 0; c < SIZE; c++)
      {
         fin >> board[r][c];
         assert(!fin.fail());
         assert(board[r][c] == X_MARK ||
               board[r][c] == O_MARK ||
               board[r][c] == NO_MARK);
      }

   // close the file
   fin.close();
   return true;
}

/**********************************************************
 * WRITE
 * Write to fileName the board data
 *********************************************************/
bool write(const char board[][SIZE], const char* fileName)
{
   assert(fileName[0] != '\0');

   // open the file
   ofstream fout(fileName);
   if (fout.fail())
      return false;

   // write my 9 symbols
   for (int r = 0; r < SIZE; r++)
      for (int c = 0; c < SIZE; c++)
         fout << board[r][c] << (c == 2 ? '\n' : ' ');

   // close it!
   fout.close();
   cout << "File written\n";
   return true;
}

/*******************************************************
 * DISPLAY
 * Display the contents the the screen
 *****************************************************/
void display(const char board[][SIZE])
{
   // loop through each row
   for (int r = 0; r < SIZE; r++)
   {
      // only the first row is not preceeded with the --+-- magic
      if (r != 0)
         cout << "---+---+---\n";

      // now, on each row, do the column stuff
      for (int c = 0; c < SIZE; c++)
      {
         // display a space for the dot
         if (board[r][c] == NO_MARK)
            cout << "   ";
         else
            cout << " " << board[r][c] << " ";

         // end with a | or a newline
         cout << (c == 2 ? '\n' : '|');
      }
   }

   // display who won
   if (didWin(board, X_MARK))
      cout << X_MARK << " won!\n";
   if (didWin(board, O_MARK))
      cout << O_MARK << " won!\n";

   return;
}

/********************************************
 * DID WIN
 * Did a given player (determined by the "turn"
 * variable) win the game?
 *******************************************/
bool didWin(const char board[][SIZE], char turn)
{
   return checkRows(board, turn)
      ||  checkCols(board, turn)
      ||  checkBackwardDiagonals(board, turn)
      ||  checkForwardDiagonals(board,turn);
}


/********************************************
 * CHECK ROWS
 * Check if a given player won
 * *****************************************/
bool checkRows(const char board[][SIZE], char turn)
{
   int count = 0;
   for (int row = 0; row < SIZE; row++)
   {
      count = 0;
      for (int col = 0; col < SIZE; col++)
      {
         board[row][col] != turn ? count = 0 : count++;  
      }

      if (count >= 3)
      {
         return true;
      }
   }
   return false;
}


/********************************************
 * CHECK COLS 
 * Check if a given player won
 * *****************************************/
bool checkCols(const char board[][SIZE], char turn)
{
   int count = 0;
   for (int col = 0; col < SIZE; col++)
   {
      count = 0;
      for (int row = 0; row < SIZE; row++)
      {
         if (board[row][col] != turn)  
         {
            board[row][col] != turn ? count = 0 : count++;  
         }
      }
      if (count >= 3)
      {
         return true;
      }
   }
   return false;
}

/********************************************
 * CHECK FORWARD DIAGONALS 
 * Check if a given player won
 * *****************************************/
bool checkForwardDiagonals(const char board[][SIZE], char turn)
{
   int startRow = SIZE - 3;
   int startCol = 0;
   int count = 0;
   int col = startCol;
   int row = startRow;

   while(startCol <= SIZE - 3)
   {
      for (row = startRow, col = startCol; row < SIZE; row++, col++)
      {
         board[row][col] != turn ? count = 0 : count++;  
         if (count >= 3)
         {
            return true;
         }
      }
      if (startCol == 0 && startRow > 0)
      {
         startRow--;
      } else {
         startCol++;
      }
   }
   return false;  
}

/********************************************
 * CHECK BACKWARD DIAGONALS 
 * Check if a given player won
 * *****************************************/
bool checkBackwardDiagonals(const char board[][SIZE], char turn)
{
   int startRow = 2;
   int startCol = 0;
   int count = 0;
   int col = startCol;
   int row = startRow;

   while(startCol <= SIZE - 3)
   {
      for (row = startRow, col = startCol; row >= 0; row--, col++)
      {
         board[row][col] != turn ? count = 0 : count++;  
         if (count >= 3)
         {
            return true;
         }
      }
      if (startRow < SIZE -1)
      {
         startRow++;
      } else {
         startCol++;
      }
   }
   return false;  
}
