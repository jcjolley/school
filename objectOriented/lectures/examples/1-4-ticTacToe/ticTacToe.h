/***********************************************************************
 * Component:
 *    ticTacToe.h
 *    Brother Helfrich, CS165
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The board of Tic-Tac-Toe
 ************************************************************************/

#ifndef _TIC_TAC_TOE_H
#define _TIC_TAC_TOE_H

/**************************************
 * GAME
 * A game is a combination of the 3x3
 * board and whose turn it currently is
 **************************************/
struct Game
{
   char board[][3];
   bool xTurn;
};

#endif // _TIC_TAC_TOE_H
