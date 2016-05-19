/***********************************************************************
* Program:
*    Example 15, Complex numbers
*    Brother Helfrich, CS165
* Author:
*    Br. Helfrich
* Summary: 
*    This program is designed to perform very simple manipulations of
*    Complex numbers.  A complex number, as you may recall, is a two
*    part number with a real and imagionary part.
************************************************************************/

#include <iostream>
#include "complex.h"
using namespace std;

/**********************************************************************
 * Just a simple driver program to help the user test this new data type
 ***********************************************************************/
int main()
{
   // This is the number we will work with
   Complex number;
   prompt(number);
   cout << "\tCurrent value: ";
   display(number);
   cout << endl;

   // keep going until zero is entered
   while (!isZero(number))
   {
      // grab a new number
      Complex num2;
      prompt(num2);

      // add to current one
      addTo(number, num2);

      // display
      cout << "\tNew value: ";
      display(number);
      cout << endl;
   }
   
   return 0;
}
