/***********************************************************************
* Program:
*    Assignment ##, ???? 
*    Brother Helfrich, CS165
* Author:
*    your name
* Summary: 
*    This header file describes all the interfaces associated with
*    manipulating dates.
************************************************************************/

#ifndef DATE_H
#define DATE_H

#include <string>
using std::string;

//
// Date structure
//

struct Date
{
   int *data;  // dynamically allocated
};

//
// Initialize and uninitialize
//

// Initialize the date
void initialize(Date & date);

// Uninitialize the date
void uninitialize(Date & date);

//
// Read and write to a file
//

// read the date from a file
bool read(Date & date, const string & fileName);

// write the date to a file
bool write(const Date & date, const string & fileName);

//
// Compare dates (no pun intended)
//

bool isEquals(const Date & lhs, const Date & rhs);
inline bool isNotEquals(const Date & lhs, const Date & rhs)
{
   return !(isEquals(lhs, rhs));
}

bool isGreater(const Date & lhs, const Date & rhs);

int difference(Date lhs, Date rhs);

//
// Set and adjust
//

// Set the current year 
bool setYear(Date & date, int year);

// Set the current month
bool setMonth(Date & date, int month);

// Set the current day
bool setDay(Date & date, int day);

// set the current date
bool setDate(Date & date, int year, int month, int day);

// adjust the date by a fixed number of days
void adjustDay(Date & date, int adjustment);

// adjust the date by a fixed number of months
void adjustMonth(Date & date, int adjustment);

// adjust the date by a fixed number of years
void adjustYear(Date & date, int adjustment);

//
// Utility functions
//

// How many days are in the current month?
int daysMonth(int month, int year);

// Is the current year a leap year?
bool isLeapYear(int year);



// Display the current date
void display(const Date & date, bool isShort);

// Short version of the display
void displayShort(const Date & date);

// Long version of the same
void displayLong(const Date & date);

// This is some debug code designed to catch common errors with
// dates, such as going to an action movie or asking her to pay.  If
// you want to use the assertDate() code, then these #defines will
// be needed in your .h file.  Also, don't forget to copy over the
// assertDateProc() which is currently in date.cpp

// Gather input from the user
void input(Date & date);

#ifdef NDEBUG
// NDEBUG is defined so we want assertDate() to compile to nothing.  This
// effectively removes all references to assertDate() from the code.
#define assertDate(date)

#else
// NDEBUG is not defined (that is a double negative! this means that we
// are in debug mode, the default state).  This means we _do_ want
// assertDate() to check our date class and make sure that everything
// works the way it should.
void assertDateProc(const Date & date, const char * file, int line);

// This part is weird.  We are adding two new parameters: the file
// name and the line number.  The compiler will turn these two
// special macros into the file name and the line number of the code
// where this function is called from. This is how assert() knows
// the file name and line number of the code when an assert fires!
#define assertDate(date) assertDateProc(date, __FILE__ , __LINE__)
#endif

#endif // DATE_H
