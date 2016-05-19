/***********************************************************************
* Header File: loadGame.h
*    Project 1, (Chess)
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
************************************************************************/
#ifndef LOADGAME_H
#define LOADGAME_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool loadGame(int &turn, string moves[], char board[][8][8]);
inline void getFilename(string &filename);
bool readFile(string moves[], int &numMoves, const string filename);

/**********************************************************************
 * getFilename
 * gets the filename
 **********************************************************************/
inline void getFilename(string &filename)
{
   cout << "Filename: ";
   cin  >> filename;
}
#endif

