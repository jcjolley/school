/***********************************************************************
* Program:
*    CHESS.H, Chess Project 3
*    Brother Helfrich, CS165
* Author:
*    Sam Barney and Joshua Jolley
* Summary:
*    This program is on it's way to becoming a full fledged Chess
*    program!
*    Estimated:  3.0 hrs
*    Actual:     7.0 hrs
*    Tired programming and silly mistakes
**********************************************************************/
//chess.h

#ifndef ___Chess_H____
#define ___Chess_H____
#include "board.h"
#include <string>
#include "move.h"

class Chess
{
public:
	Chess();
	void interact();
	
	


private:
	Board board;
	std::string command;
	int turn; 
	Move move;
	std::string filename;
	bool makeMove();
	void save() {};
};

#endif