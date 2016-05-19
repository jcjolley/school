/***********************************************************************
* Program:
*    Assignment 25, Operator overloading
*    Brother Grimmett, CS165
* Author:
*    your name
* Summary: 
*    This assignment is to demonstrate all types of
*    member function operator overloading
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>
#include <cassert>
#include "date.h"
using namespace std;

/**********************************************************************
 * A simple driver program to exercise our constructors
 ***********************************************************************/
int main()
{
   // Prompt the user for the Day, Month, and Year
   int year;
   int month;
   int day;
   cout << "Year:  ";
   cin  >> year;
   cout << "Month: ";
   cin  >> month; 
   cout << "Day:   ";
   cin  >> day;
   Date date(year, month, day);

   // test assignment
   Date dateCheck = date;
   assert(date == dateCheck);
   
   int delta = 0;
   
   do
   {
      // test +, --
      date = date + delta;
      dateCheck = dateCheck - delta;
      dateCheck++;
      assert(date  < dateCheck);
      // Test non-default constructor
      assert(Date(date.getYear() - 1) < date);

      date.displayLong();
      cout << endl;

      cout << "> ";
      cin  >> delta;
   }
   while (delta != 0);

   return 0;
}
