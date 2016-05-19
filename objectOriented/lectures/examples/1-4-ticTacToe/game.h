/***********************************************************************
 * Component:
 *    game.h
 *    Brother Helfrich, CS165
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the game logic for Tic-Tac-Toe
 ************************************************************************/

#ifndef _GAME_H
#define _GAME_H

#include "ticTacToe.h"    // need Game

// clear the tic-tac-toe board
void clearBoard(Game & game);

// allow the user to place a piece on the board
void editSquare(Game & game);

#endif // _GAME_H
