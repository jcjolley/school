/***********************************************************************
* Program:
*    Assignment 25, Static
*    Brother Helfrich, CS165
* Author:
*    your name
* Summary: 
*    This assignment is designed to illustrate one common use for
*    static in a class: configuration
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>    // for CIN and COUT
#include <string>      // for STRING class
#include <cassert>     // It is not paranoia if they really do want to get you
#include "date.h"      // for the DATE class
using namespace std;

bool Date :: isShort = false;  // initially the long format

/**********************************************************************
 * A simple driver program to exercise our static member variable
 ***********************************************************************/
int main()
{
   Date date1;
   Date date2;

   // infinite loop to faciliate testing
   for (;;)
   {
      // Prompt the user for the Day, Month, and Year
      int year;
      int month;
      int day;
      cout << "What is the date (day month year): ";
      cin  >> day >> month >> year;

      // set the new date
      date1.setDate(year, month, day);
      date2.setDate(year, month, day);

      // display the results
      date1.display();                          // both date1 and date2
      cout << "  -  ";                          //    should display the same
      date2.display();                          //    because they look at
      cout << endl;                             //    the same member variable

      // continue, switch modes, or quit?
      string input;
      cout << "Short, Long, or Quit? ";
      cin  >> input;
      if (input == string("Short"))
         date1.setShort();                      // though we are only changing
      if (input == string("Long"))              //    one, both date1 and date2
         date2.setLong();                       //    should be changed here
      if (input == string("Quit"))
         return 0;
   }
}
