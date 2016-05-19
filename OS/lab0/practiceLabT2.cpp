/****************************************************************************
* Program:
*    Lab 00T2, Practice Lab Submission
*    Brother Jones, CS345
* Author:
*    Joshua Jolley
* Summary: 
*    A simple program to count the number of integers input
*****************************************************************************
*****************************************************************************
*
* Changes made to my code for the re-submission:
*   Broke the lab up into functions
*   Added error handling 
*****************************************************************************/

#include <iostream>
using namespace std;
/**********************************************************************
 * FUNCTION: getInput
 * Gets input and checks for errors.
 ***********************************************************************/
int & getInput(int & input)
{
   cout << "Enter an integer: ";
   cin >> input;
   if (cin.fail())
   {
      cin.clear();  
      cin.ignore();
      input = 0; //This terminates the program on bad input
   } 
   return input;
}
/**********************************************************************
 * FUNCTION:  display
 * Displays the results of our count
 ***********************************************************************/
 void display(const int & count)
 {
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
 }

/**********************************************************************
 * FUNCTION: main
 * Counts the number of integers input, and displays the result to the user
 ***********************************************************************/
int main() 
{
   int input = 1;
   int count = 0; 
 
   //loop until we get a 0 
   while (getInput(input)) 
   {
      count++;
   }
   
   //display the results
   display(count);
   return 0;
}

