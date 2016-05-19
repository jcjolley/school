/***********************************************************************
* Header File: chess.h
*    Project 1, (Chess)
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
************************************************************************/

#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <cctype>
#include <cstdlib>

using namespace std;

bool displayTest(const char board[][8][8]);
void displayBoard(const char board[][8][8]);
inline void displayOptions();

/**********************************************************************
 * displayOptions
 * It's all in the name.
 **********************************************************************/
inline void displayOptions()
{
   cout << "Options:\n"
        << "?\tDisplay these options\n"
        << "b2b4\tSpecify a move using the Smith Notation\n"
        << "test\tSimple display for test purposes\n"
        << "quit\tLeave the game. You will be prompted to save\n";
}

#endif
