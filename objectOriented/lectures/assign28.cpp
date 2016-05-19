/***********************************************************************
* Program:
*    Assignment 28, Member Operator overloading
*    Brother Helfrich, CS165
* Author:
*    your name
* Summary: 
*    This assignment is to demonstrate all types of
*    non-member function operator overloading
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>
#include <cassert>
#include "date.h"
using namespace std;

bool Date::isShort = false;

/**********************************************************************
 * What kind of craziness is this?
 ***********************************************************************/
int main()
{

   //    _____ _               ___                  _   _      _
   //   /__   \ |__   ___     / _ \__ _ _   _ _ __ | |_| | ___| |_
   //     / /\/ '_ \ / _ \   / /_\/ _` | | | | '_ \| __| |/ _ \ __|
   //    / /  | | | |  __/  / /_\\ (_| | |_| | | | | |_| |  __/ |_   _ _ _
   //    \/   |_| |_|\___|  \____/\__,_|\__,_|_| |_|\__|_|\___|\__| (_|_|_)
   //                                                                       

   // the original date
   Date dateOriginal;      // new years 2000
   
   // Prompt the user for a date and a number
   Date date;
   cout << "Date: ";
   cin  >> date;
   int  n;
   cout << "Number: ";
   cin  >> n;
   
   // make a copy of the date and display it
   dateOriginal = date;
   cout << "\nThe date is: " << dateOriginal << endl;
   date.setShort();

   // change the date somewhat
   cout << "\n---infix notation---\n";
   cout << "date += " << n << " : " << (date += n) << endl;
   cout << "++date     : "          << ++date      << endl;
   cout << "date -= " << n << " : " << (date -= n) << endl;
   cout << "date--     : "          << date--      << endl;
   cout << "date : "  << date << " ";
   cout << (dateOriginal != date ? "ERROR!\n" : "It worked!\n");

   // we will call the functions in infix notation to make sure
   // everything was implemented as member functions except <<.
   cout << "\n---prefix notation---\n";
   cout << "date.operator+=(" << n << ") = " << date.operator+=(n) << endl;
   cout << "date.operator++( )  = "          << date.operator++( ) << endl;
   cout << "date.operator-=(" << n << ") = " << date.operator-=(n) << endl;
   cout << "date.operator--(1)  = "          << date.operator--(1) << endl;
   operator << (operator << ( operator << (cout, "date: "), date), " ");
   cout << (dateOriginal.operator==(date) ? "It worked!\n" : "ERROR!\n");

   // phew!
   return 0;
}
