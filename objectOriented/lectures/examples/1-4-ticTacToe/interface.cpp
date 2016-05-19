/***********************************************************************
 * Component:
 *    Interface.cpp
 *    Brother Helfrich, CS165
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the stuff that involves talking to the user
 **********************************************************************/

#include "interface.h"   // for the prototypes
#include "file.h"        // for readBoard() and writeBoard()
#include "game.h"        // for editSquare()
#include <iostream>
#include <cassert>
using namespace std;

/************************************
 * COORDINATE
 * The position on the Tic-Tac-Toe board
 ************************************/
struct Coordinate
{
   int row;
   int col;
};

// prompt the user for a filename
string getText(const char * prompt);

// display the interface options to the user
void displayOptions();

// display the contents of the board on the screen
void displayBoard(const Game & game);

// convert symbol to display letter
char convertSymbol(char letter);

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
