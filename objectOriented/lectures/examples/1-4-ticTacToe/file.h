/***********************************************************************
* Component:
*    File.h
*    Brother Helfrich, CS165
* Author:
*    Br. Helfrich
* Summary: 
*    All the File I/O for Tic-Tac-Toe
************************************************************************/

#ifndef _FILE_H
#define _FILE_H

#include "ticTacToe.h"    // need Game
#include <string>         // need the string class

// read the board from a file
void readBoard(const std::string & fileName, Game & game);

// write the board to a file
void writeBoard(const std::string & fileName, const Game & game);

#endif // _FILE_H
