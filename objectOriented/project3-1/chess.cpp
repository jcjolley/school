/***********************************************************************
* Program:
*    CHESS.CPP, Chess Project 3
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
//Chess.cpp
#include <iostream>
#include "chess.h"
#include <cassert>

using namespace std;
void Chess::interact()
{
	
	while (command != "quit")
	{
		board.draw();
		if(turn % 2 == 1)
			cout << "(White): ";
		else 
			cout << "(Black): ";
		cin >> command;
                
                if (command[0] >= 'a' && command[0] <= 'h' &&
                    command[1] >= '1' && command[1] <= '8')
                   if(makeMove())
                      turn++;
	}
        cout << "To save a game, please specify the filename.\n" << "    To quit without saving a file, just press <enter>\n"; 
        cin.ignore();
        getline(cin,filename);
        save();
}

bool Chess::makeMove()
{
	//parse command into a move
    move = command;
    if (command[0] >= 'a' && command[0] <= 'h' &&
        command[1] >= '1' && command[1] <= '8')
    	{
    		assert(command[0] >= 'a');
            return board.movePiece(move);
        }
    else
       return false;
}

Chess::Chess()
{

	command = " ";
	int turn = 0; 
	filename = " ";
	
}
