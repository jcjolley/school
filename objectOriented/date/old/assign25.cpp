/***********************************************************************
* Program:
*    CURRENTDRIVER.CPP, Date Class
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
* Summary:
*    A robust implementation of a Date class (You'll get the girls
*    after you take this class!)
*    Estimated:  4.0 hrs
*    Actual:     4.0 hrs
*    Learning class syntax, especially overloading operators
**********************************************************************/



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
      // test +=
      date += delta;
      // test -=
      dateCheck -= -delta;
      // Test !=
      assert(!(date != dateCheck));
      // Test ++pre, +
      assert(++dateCheck == date + 1);
      // Test post--, +
      assert(date + 1 == dateCheck--);
      // Test >, -
      assert(date >= dateCheck - 100);
      // Test <, +
      assert(date < dateCheck + 360);
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
