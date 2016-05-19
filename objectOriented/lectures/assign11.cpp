/***********************************************************************
* Program:
*    Assignment 11, Defensive Programming
*    Brother Helfrich, CS165
* Author:
*    The Key
* Summary: 
*    Write a function to accept two integer values from the user.  This
*    function must be resistant to all user-induced errors.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

/***********************************************************************
 * GET COORDINATES
 * Prompt the user for a row and column
 ***********************************************************************/
void getCoordinates(int & col, int & row)
{
   // your code goes here
}

/***********************************************************************
 * Simple driver program for getCoordinate
 ***********************************************************************/
int main()
{
   int col;
   int row;

   getCoordinates(col, row);

   cout << "The values are: ("
        << col << ", " << row << ")\n";
   
   return 0;
}
