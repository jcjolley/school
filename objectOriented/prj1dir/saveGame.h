/***********************************************************************
* Header File: saveGame.h
*    Project 1, (Chess)
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
************************************************************************/
#ifndef SAVEGAME_H
#define SAVEGAME_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void quitGame(const string moves[], const int turn);
inline void getSavename(string &filename);
void writeFile(const string moves[], const string filename, const int turn);

/**********************************************************************
 * getSavename
 * prompts for and gets the filename to save to
 **********************************************************************/
inline void getSavename(string &filename)
{
   cout << "To save a game, please specify the filename.\n"
        << "    To quit without saving a file, just press <enter>\n";
   cin.ignore();
   getline(cin, filename);
}

#endif
