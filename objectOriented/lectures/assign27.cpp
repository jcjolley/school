/***********************************************************************
* Program:
*    Assignment 27, Operator overloading with Friends
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

   //
   //    ____  _  _  ____     ___   __   _  _  __ _  ____  __    ____  ____
   //   (_  _)/ )( \(  __)   / __) / _\ / )( \(  ( \(_  _)(  )  (  __)(_  _)
   //     )(  ) __ ( ) _)   ( (_ \/    \) \/ (/    /  )(  / (_/\ ) _)   )(
   //    (__) \_)(_/(____)   \___/\_/\_/\____/\_)__) (__) \____/(____) (__) 
   //
     
   // Prompt the user for a date and a number
   Date date;
   cout << "Date: ";
   cin  >> date;
   Date newYears;  // 1/1/2000 from default constructor
   int  num;
   cout << "number: ";
   cin  >> num;

   // difference
   cout << "\n--- difference ---\n";
   cout << "There are " << (date - newYears)
        << " days between new years and " << date << endl;
   date.setShort();
   
   // comparison
   cout << "\n--- comparison ---\n";
   cout << date << " == " << newYears << " : " << (date == newYears) << endl;
   cout << date << " != " << newYears << " : " << (date != newYears) << endl;
   cout << date << " >= " << newYears << " : " << (date >= newYears) << endl;
   cout << date << " >  " << newYears << " : " << (date >  newYears) << endl;
   cout << date << " <= " << newYears << " : " << (date <= newYears) << endl;
   cout << date << " <  " << newYears << " : " << (date <  newYears) << endl;
   
   // arithmetic
   cout << "\n--- arithmetic ---\n";
   cout << date << " + " << num  << " : " << (date + num) << endl; 
   cout << num  << " + " << date << " : " << (num + date) << endl; 
   cout << date << " - " << num  << " : " << (date - num) << endl;

   // add onto
   cout << "\n--- add onto ---\n";
   cout << date << " += " << num << " : " << (date += num) << endl;
   cout << "date : " << date << endl;
   cout << date << " -= " << num << " : " << (date -= num) << endl;
   cout << "date : " << date << endl;

   // increment and decrement
   cout << "\n--- increment and decrement ---\n";
   cout << "date++ : " <<   date++ << endl;
   cout << "date   : " <<   date   << endl;
   cout << "++date : " << ++date   << endl;
   cout << "date   : " <<   date   << endl;
   cout << "date-- : " <<   date-- << endl;
   cout << "date   : " <<   date   << endl;
   cout << "--date : " << --date   << endl;
   cout << "date   : " <<   date   << endl;

   // phew!
   return 0;
}
