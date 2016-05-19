/***********************************************************************
* Program:
*    Project 3, Chess with Objects
*    Brother Helfrich, CS165
* Author:
*    The Key
* Summary: 
*    This fill will keep track of the move on the board
************************************************************************/

#include <iostream>
#include "move.h"
using namespace std;


/*************************************
 * main
 **************************************/
int main()
{
   Move move1;
   Move move2;

   try
   {
      cout << "Enter a move: ";
      cin  >> move1;
      cout << "    You entered: " << move1 << endl;
   }
   catch (string s)
   {
      cout << "Error reading first move: " << s << endl;
   }

   try
   {
      cout << "Enter another move: ";
      cin  >> move2;
      cout << "You entered: " << move2 << endl;
   }
   catch (string s)
   {
      cout << "Error reading second move: " << s << endl;
   }
   
   if (move1 == move2)
      cout << "They are the same!\n";
   else
      cout << "They are different!\n";

   move1 = move2;
   cout << "After move1 = move2, then: " << move1 << " " << move2 << endl;

   return 0;

}

