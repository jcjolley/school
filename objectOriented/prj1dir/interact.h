/***********************************************************************
* Header File: interact.h
*    Project 1, (Chess)
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
************************************************************************/
#ifndef INTERACT_H
#define INTERACT_H

#include <string>
#include <iostream>
using namespace std;

void interact(char board[][8][8]);
inline void listMoves(const int turn, const string move, string moves[]);

/**********************************************************************
 * listMoves
 * trivial function that creates a list of moves.
 **********************************************************************/
inline void listMoves(const int turn, const string move, string moves[])
{
   moves[turn] = move;
}

#endif
