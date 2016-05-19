/***********************************************************************
* Program:
*    Project 3, Chess with Objects
*    Brother Helfrich, CS165
* Author:
*    The Key
* Summary: 
*    This fill will keep track of the position on the board
************************************************************************/

#include <iostream>
#include "position.h"
using namespace std;

/*************************************
 * main
 **************************************/
int main()
{
   Position pos1;
   Position pos2;

   try
   {
      cout << "Enter a position: ";
      cin  >> pos1;
      cout << "    You entered: " << pos1 << endl;
   }
   catch (string s)
   {
      cout << "Error reading first position: " << s << endl;
   }

   try
   {
      cout << "Enter another position: ";
      cin  >> pos2;
      cout << "You entered: " << pos2 << endl;
   }
   catch (string s)
   {
      cout << "Error reading second position: " << s << endl;
   }
   
   if (pos1 == pos2)
      cout << "They are the same!\n";
   else
      cout << "They are different!\n";

   pos1 = pos2;
   cout << "After pos1 = pos2, then: " << pos1 << " " << pos2 << endl;

   return 0;

}

