/***********************************************************************
* Program:
*    Assignment 42, Function templates
*    Brother Helfrich, CS165
* Author:
*    your name
* Summary: 
*    This program is designed to demonstrate how function templates work
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>
using namespace std;


/**********************************************************************
 * MAIN.  Driver program to test our callback functions
 *        You are not allowed to modify MAIN in any way.
 ***********************************************************************/
int main()
{
   int numbers[5];
   string words[7];

   //
   //  First fill the arrays of words and numbers
   //
   
   // fill the numbers
   cout << "Specify 5 numbers: ";
   for (int i = 0; i < 5; i++)
      cin >> numbers[i];

   // fill the text
   cout << "Specify 7 words of text: ";
   for (int i = 0; i < 7; i++)
      cin >> words[i];

   //
   // Next, sort them.  Note how we use exactly the same sorting routine.
   // sort() has no idea what data type it is using.
   //
   
   // sort numbers
   sort(numbers, 5);

   // sort the words
   sort(words, 7);

   //
   // Finally, display the results.
   //
   
   // display the numbers
   cout << "Sorted numbers: ";
   for (int i = 0; i < 4; i++)
      cout << numbers[i] << ", ";
   cout << numbers[4] << endl;

   // display the text
   cout << "Sorted words: ";
   for (int i = 0; i < 6; i++)
      cout << words[i] << ", ";
   cout << words[6] << endl;
   
   return 0;
}

