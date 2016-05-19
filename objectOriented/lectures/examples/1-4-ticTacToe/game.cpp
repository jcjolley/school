/***********************************************************************
 * Component:
 *    game.cpp
 *    Brother Helfrich, CS165
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the game logic for Tic-Tac-Toe
 ************************************************************************/

#include "ticTacToe.h" // for Board

#include <iostream>    // editSquare() needs to prmopt the user
#include <cassert>     // I am still paranoid
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

// get coordinates
void getCoordinates(Coordinate & coordinate);

/***********************************************
 * CLEAR BOARD
 * Empty the board and set the turn to X
 **********************************************/
void clearBoard(Game & game)
{
   // remove all the markings off the board
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         game.board[row][col] = '*';

   // set the turn to X's
   game.xTurn = true;
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

