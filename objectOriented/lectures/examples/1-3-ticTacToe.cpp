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

/**************************************
 * GAME
 * A game is a combination of the 3x3
 * board and whose turn it currently is
 **************************************/
struct Game
{
   char board[][3];       // the same 3x3 array as before
   bool xTurn;            // also whose turn it is
};

/************************************
 * COORDINATE
 * The position on the Tic-Tac-Toe board
 ************************************/
struct Coordinate
{
   int row;
   int col;
};

// clear the tic-tac-toe board
void clearBoard(Game & game);

// the main interaction loop
void interact(Game & game);

// read the board from a file
void readBoard(const string & fileName, Game & game);

// write the board to a file
void writeBoard(const string & fileName, const Game & game);

// prompt the user for a filename
string getText(const char * prompt);

// display the interface options to the user
void displayOptions();

// allow the user to place a piece on the board
void editSquare(Game & game);

// display the contents of the board on the screen
void displayBoard(const Game & game);

// get coordinates
void getCoordinates(Coordinate & coordinate);

// convert symbol to display letter
char convertSymbol(char letter);

/**********************************************************************
 * Main: Interact with the game and prompt the user to save at the end.
 ***********************************************************************/
int main()
{
   // set up the board
   Game game;                  // declariation is easy with a struct
   clearBoard(game);           // it is also much eaiser to pas parameters

   // let the users play the game
   interact(game);

   return 0;
}

/*************************************************
 * INTERACT
 * Allow the user to interact with the game of Tic-Tac-Toe
 *************************************************/
void interact(Game & game)
{
   string fileName;
   char input = '\0';
   displayBoard(game);
   displayOptions();

   // main interaction loop
   do
   {
      cout << "<" << (game.xTurn ? 'X' : 'O') << "> ";
      cin  >> input;

      switch (input)
      {
         case '?':
            displayOptions();
            break;
         case 'e':
            editSquare(game);
            displayBoard(game);
            break;
         case 'r':
            fileName =
               getText("What file would you like to read the board from? ");
            if (fileName.length() != 0)
            {
               readBoard(fileName, game);
               displayBoard(game);
            }
            break;
         case 's':
            fileName =
               getText("What file would you like to write your board to? ");
            if (fileName.length() != 0)
               writeBoard(fileName, game);
            break;
      }
   }
   while (input != 'q');
}

/***********************************************
 * CLEAR BOARD
 * Empty the board and set the turn to X
 **********************************************/
void clearBoard(Game & game)
{
   // remove all the markings off the board
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         game.board[row][col] = '.';

   // set the turn to X's
   game.xTurn = true;
}

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
void editSquare(Game & game)
{
   Coordinate coordinate;

   // get the coordinates
   getCoordinates(coordinate);
   assert(coordinate.row >= 0 && coordinate.row <= 2);
   assert(coordinate.col >= 0 && coordinate.col <= 2);
   if (game.board[coordinate.row][coordinate.col] != '.')
      return;

   // prompt the user for a square
   game.board[coordinate.row][coordinate.col] = (game.xTurn ? 'X' : 'O');
   game.xTurn = !game.xTurn;

   assert(game.board[coordinate.row][coordinate.col] == 'X' ||
          game.board[coordinate.row][coordinate.col] == 'O');
}

/**************************************************
 * DISPLAY BOARD
 * Display the contents of the board on the screen
 **************************************************/
void displayBoard(const Game & game)
{
   // header
   cout << "   A   B   C\n";
   
   // first two rows with a horizontal line after
   for (int row = 0; row <= 1; row++)
   {
      // first two columns with a vertical line after
      cout << row + 1 << " ";
      for (int col = 0; col <= 1; col++)
         cout << " " << convertSymbol(game.board[row][col]) << " |";

      // last column
      cout << " " << convertSymbol(game.board[row][2]) << endl;

      // horizontal line
      cout << "  ---+---+---\n";
   }

   // last row
   int row = 2;
   cout << row + 1 << " ";
   for (int col = 0; col <= 1; col++)
      cout << " " << convertSymbol(game.board[row][col]) << " |";
   cout << " " << convertSymbol(game.board[row][2]) << endl;
}

/******************************************
 * GET COORDINATES
 * Prompt the user for a row and a column
 * The input is in the form of "A2"
 *****************************************/
void getCoordinates(Coordinate & coordinate)
{
   char colLetter;

   do
   {
      // prompt with instructions
      cout << "Please specify the coordinates: ";
      cin >> colLetter >> coordinate.row;

      if (cin.fail())                      // detect we are in an error state
      {
         cin.clear();                      // clear the error state
         cin.ignore(256, '\n');            // ignore the rest of the characters
      }
   }
   while (colLetter < 'A' || colLetter > 'C' ||
          coordinate.row < 1 || coordinate.row > 3);

   // convert to a letter to a number
   coordinate.col = colLetter - 'A';

   // convert from 1's based to 0's based
   coordinate.row--;

   assert(coordinate.col >= 0 && coordinate.col <= 2);
   assert(coordinate.row >= 0 && coordinate.row <= 2);
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
