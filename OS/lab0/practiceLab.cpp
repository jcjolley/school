/***********************************************************************
* Program:
*    Lab 00, Practice Lab Submission
*    Brother Jones, CS345
* Author:
*    Joshua Jolley
* Summary:
*    A simple program that counts the number of integers entered from the
*    command line
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * FUNCTION: main
 * Counts the number of integers input, and displays the result to the user
 ***********************************************************************/
int main() 
{
   int input = 1;
   int count = -1; // we don't want to count the final 0
 
   //loop until we get a 0 
   while (input != 0) 
   {
      cout << "Enter an integer: ";
      cin >> input;
      count++;
   }
   
   //display the results
   switch (count)
   {
      case 0:
         cout << "No non-zero integers were entered." << endl;
         break;
      case 1:
         cout << "You entered 1 integer." << endl;
         break;
      default:
         cout << "You entered " << count << " integers." << endl;
   }

   return 0;
}

