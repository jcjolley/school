/***********************************************************************
* Program:
*    Example 1.0: Tic-Tac-Toe
*    Brother Helfrich, CS165
* Author:
*    Br. Helfrich
* Summary: 
*    This program corresponds to the design document presented in chapter
*    1.0: the game of Tic-Tac-Toe
************************************************************************/

#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

// clear the tic-tac-toe board
void clearBoard(char board[][3], bool & xTurn);

// the main interaction loop
void interact(char board[][3], bool & xTurn);

// read the board from a file
void readBoard(const string & fileName, char board[][3], bool & xTurn);

// write the board to a file
void writeBoard(const string & fileName, const char board[][3]);

// prompt the user for a filename
string getText(const char * prompt);

// display the interface options to the user
void displayOptions();

// allow the user to place a piece on the board
void editSquare(char board[][3], bool & xTurn);

// display the contents of the board on the screen
void displayBoard(const char board[][3]);

// get coordinates
void getCoordinates(int & row, int & col);

// convert symbol to display letter
char convertSymbol(char letter);

/**********************************************************************
 * Main: Interact with the game and prompt the user to save at the end.
 ***********************************************************************/
int main()
{
   // set up the board
   char board[3][3];
   bool xTurn = true;
   clearBoard(board, xTurn);

   // let the users play the game
   interact(board, xTurn);

   return 0;
}

/*************************************************
 * INTERACT
 * Allow the user to interact with the game of Tic-Tac-Toe
 *************************************************/
void interact(char board[][3], bool & xTurn)
{
   string fileName;
   char input = '\0';
   displayBoard(board);
   displayOptions();

   // main interaction loop
   do
   {
      cout << "<" << (xTurn ? 'X' : 'O') << "> ";
      cin  >> input;

      switch (input)
      {
         case '?':
            displayOptions();
            break;
         case 'e':
            editSquare(board, xTurn);
            displayBoard(board);
            break;
         case 'r':
            fileName =
               getText("What file would you like to read the board from? ");
            if (fileName.length() != 0)
            {
               readBoard(fileName, board, xTurn);
               displayBoard(board);
            }
            break;
         case 's':
            fileName =
               getText("What file would you like to write your board to? ");
            if (fileName.length() != 0)
               writeBoard(fileName, board);
            break;
         default:
            cout << "Unexpected option.  The available options are:\n";
            displayOptions();
            break;
      }

   }
   while (input != 'q');
}

/***********************************************
 * CLEAR BOARD
 * Empty the board and set the turn to X
 **********************************************/
void clearBoard(char board[][3], bool & xTurn)
{
   // remove all the markings off the board
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         board[row][col] = '.';

   // set the turn to X's
   xTurn = true;
}

/**********************************************
 * READ BOARD
 * Prompt the user for a filename and read the
 * the board from a file
 *********************************************/
void readBoard(const string & fileName, char board[][3], bool & xTurn)
{
   assert(fileName.length() != 0);

   // open the file
   ifstream fin(fileName.c_str());

   try
   {
      if (fin.fail())                        // throw if we fail to open
         throw "Unable to open file";        //    the file for any reason

      // read the contents of the file
      int numXoverO = 0;
      for (int row = 0; row < 3; row++)
         for (int col = 0; col < 3; col++)
         {
            // read the item from the board
            fin >> board[row][col];

            // check for failure.
            if (fin.fail())                  // throw if we fail to read data
               throw "Error reading file ";  //    from the file

            if (board[row][col] == 'X')
               numXoverO++;
            else if (board[row][col] == 'O')
               numXoverO--;
            else if (board[row][col] != '.') // throw if the symbol we read
               throw "Unexpected symbol";    //    is not a X O or .
         }

      // determine whose turn it is by the xOverO count   
      xTurn = (numXoverO == 0 ? true : false);
      if (numXoverO != 0 && numXoverO != 1)  // throw if the board does not
         throw "Invalid board";              //    make sense
   }
   catch (const char * message)              // all errors are sent here
   {                                         //    so we only need to
      cout << "Error: "   << message         //    construct the error
           << " in file " << fileName        //    message once
           << ".\n";
   }

   // close the file
   fin.close();                              // this is called regardless of
}                                            //    whether there was an error

/*******************************************************
 * WRITE BOARD
 * Write the contents of the board to a file
 ******************************************************/
void writeBoard(const string & fileName, const char board[][3])
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
         fout << board[row][col];
      fout << endl;
   }

   // close the file
   fout.close();               
}

/*************************************************
 * GET TEXT
 * Generic prompt function
 ************************************************/
string getText(const char * prompt)
{
   cout << prompt;
   string input;
   cin >> input;
   return input;
}

/***************************************************
 * DISPLAY OPTIONS
 * Display the menu of options to the user
 ***************************************************/
void displayOptions()
{
   cout << "Options:\n";
   cout << "   ?...Display these options\n";
   cout << "   e...Edit a square\n";
   cout << "   r...Read a board from a file\n";
   cout << "   s...Save a board to a file\n";
   cout << "   q...Quit\n";
}

/*************************************************
 * EDIT SQUARE
 * Edit one square on the tic-tac-toe board
 *************************************************/
void editSquare(char board[][3], bool & xTurn)
{
   int row;
   int col;

   // get the coordinates
   getCoordinates(row, col);
   assert(row >= 0 && row <= 2);
   assert(col >= 0 && col <= 2);
   if (board[row][col] != '.')
      return;

   // prompt the user for a square
   board[row][col] = (xTurn ? 'X' : 'O');
   xTurn = !xTurn;

   assert(board[row][col] == 'X' || board[row][col] == 'O');
}

/**************************************************
 * DISPLAY BOARD
 * Display the contents of the board on the screen
 **************************************************/
void displayBoard(const char board[][3])
{
   // header
   cout << "   A   B   C\n";
   
   // first two rows with a horizontal line after
   for (int row = 0; row <= 1; row++)
   {
      // first two columns with a vertical line after
      cout << row + 1 << " ";
      for (int col = 0; col <= 1; col++)
         cout << " " << convertSymbol(board[row][col]) << " |";

      // last column
      cout << " " << convertSymbol(board[row][2]) << endl;

      // horizontal line
      cout << "  ---+---+---\n";
   }

   // last row
   int row = 2;
   cout << row + 1 << " ";
   for (int col = 0; col <= 1; col++)
      cout << " " << convertSymbol(board[row][col]) << " |";
   cout << " " << convertSymbol(board[row][2]) << endl;
}

/******************************************
 * GET COORDINATES
 * Prompt the user for a row and a column
 * The input is in the form of "A2"
 *****************************************/
void getCoordinates(int & row, int & col)
{
   char colLetter;

   do
   {
      // prompt with instructions
      cout << "Please specify the coordinates: ";
      cin >> colLetter >> row;

      // handle errors
      if (cin.fail())
      {
         cin.clear(); 
         cin.ignore(256, '\n');
      }
   }
   while (colLetter < 'A' || colLetter > 'C' ||
          row < 1 || row > 3);

   // convert to a letter to a number
   col = colLetter - 'A';

   // convert from 1's based to 0's based
   row--;

   assert(col >= 0 && col <= 2);
   assert(row >= 0 && row <= 2);
}

/*********************************************
 * CONVERT SYMBOL
 * Convert symbol for the space '.' into
 * the display representation ' '
 *********************************************/
char convertSymbol(char letter)
{
   assert(letter == '.' || letter == 'O' || letter == 'X');
   return (letter == '.') ? ' ' : letter;
}