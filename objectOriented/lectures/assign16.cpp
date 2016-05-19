/***********************************************************************
* Program:
*    Assignment 16, Rounding
*    Brother Helfrich, CS165
* Author:
*    your name
* Summary: 
*    This program is designed to round numbers. We will round
*    up, round down, and round depending on the value.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

// round down always
float roundDown(float value);

// round up or down, depending...
float round(float value);

// round up always
float roundUp(float value);

/**********************************************************************
 * MAIN
 * Just a simple program to test three functions.
 ***********************************************************************/
int main()
{
   // fetch the value;
   float value;
   cout << "Please enter a value: ";
   cin  >> value;

   // configure the output for 2 decimal points of precision
   cout.setf(ios::fixed | ios::showpoint);
   cout.precision(2);

   // display the results
   cout << "Round down: " << roundDown(value) << endl;
   cout << "Round:      " << round(value)     << endl;
   cout << "Round up:   " << roundUp(value)   << endl;
   
   return 0;
}

