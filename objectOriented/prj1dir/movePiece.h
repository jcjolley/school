/***********************************************************************
* Header File: movePiece.h
*    Project 1, (Chess)
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
************************************************************************/
#ifndef MOVEPIECE_H
#define MOVEPIECE_H

#include <string>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool movePiece(int turn, string move, char board[][8][8], string filename);
bool movePiece(const int turn, const string move, char board[][8][8]);
int isInvalidMove(const string move, const char board[][8][8]);
void convertMove(const string move, int &startRow, int &startCol,
                 int &endRow, int &endCol, bool &isCastle);
void makeMove(const int startRow, const int startCol, const int endRow,
              const int endCol, const int turn, const bool isCastle,
              char board[][8][8]);
#endif
