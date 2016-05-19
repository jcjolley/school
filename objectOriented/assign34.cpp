/***********************************************************************
* Program:
*    Assignment 34, Polymorphism with virtual functions
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
* Summary: 
*    This program is designed to demonstrate simple polymorphism
*    through the use of virtual functions.  Here the display() function
*    will be differently defined in each of the inherited time classes.
*
*    Estimated:  0.7 hrs   
*    Actual:     0.5 hrs
*      doing year month day rather than day month year.  Sneaky.
************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

enum {DAY, MONTH, YEAR};

/**********************************************************************
 * Date Class
 * This class teaches you how to woo a lady like a gentleman
 **********************************************************************/
class Date
{
public:
   Date() : day(1), month(1), year(2000) {};
   Date(int Year, int Month = 1, int Day = 1) : day(Day), month(Month), year(Year) {};
   Date(Date & date)      {day = date.day; month = date.month; year = date.year;}
   void copy(Date & date) {day = date.day; month = date.month; year = date.year;}
   friend std::istream & operator >> (std::istream & in, Date & date);
   bool isLeapYear(int year);
   int daysMonth(int month, int year);
   virtual void display() {};
protected:
   int day;
   int month;
   int year;
};

/**********************************************************************
 * DateShort Class
 * Take this class when your time to woo is limited
 **********************************************************************/
class DateShort : public Date
{
public:
   DateShort() : Date() {};
   void display();
};

/**********************************************************************
 * DateLong Class
 * Take this class when you've got ample time to woo
 **********************************************************************/
class DateLong : public Date
{
public:
   DateLong() : Date() {}; 
   void display();
};
   
 /**********************************************
 * DateShort::Display
 *  Redefined.  Display the current date: 1/3/2010
 *  INPUT date   the current date
 *********************************************/
   void DateShort::display()
{
   cout << month << "/"
        << day   << "/"
        << year;
}


/**********************************************
 * DISPLAY LONG.  Display the current date: 1st of October, 2009
 *  INPUT date   the current date
 *********************************************/
void DateLong::display()
{
   // day
   cout << day;
   switch (day)
   {
      case 1:
      case 21:
      case 31:
         cout << "st";
         break;
      case 2:
      case 22:
         cout << "nd";
         break;
      case 3:
      case 23:
         cout << "rd";
         break;
      default:
         cout << "th";
   }
   
   // month
   const char MONTHS[12][10] =
      { "January", "February", "March",     "April",   "May",      "June",
        "July",    "August",   "September", "October", "November", "December"};
   
   cout << " of " << MONTHS[month - 1] << ", ";

   // year   
   cout << year;
}


/**********************************************************************
 * >> Overload
 * This function overloads the >> operator for Date 
**********************************************************************/
istream & operator >> (std::istream & in, Date & date)
{
   in >> date.year >> date.month >> date.day;
   return in;
}


/**********************************************************************
 * MAIN:  This is a driver program to exercise our Date class.  In this
 *        case, we will have an array of three dates.  Each date will remember
 *        it is actually a generic date, a short date, or a long date.  Any
 *        humorous puns or play-on-words is completely accidental. 
 ***********************************************************************/
int main()
{
   Date      date;
   DateShort dateShort;
   DateLong  dateLong;
   Date *    dates[3];

   // user input
   cout << "Specify year, month, day: ";
   cin  >> date;

   // We want the same date for the short and long version
   dateLong.copy(date);
   dateShort.copy(date);
   dates[0] = &date;
   dates[1] = &dateShort;
   dates[2] = &dateLong;
   
   // Finally, display the output
   cout << "Base class with empty display: \"";
   dates[0]->display();
   cout << "\"\n";

   cout << "Short version:                 \"";
   dates[1]->display();
   cout << "\"\n";

   cout << "Long version:                  \"";
   dates[2]->display();
   cout << "\"\n";

   return 0;
}

/*****************************************************
 * DAYS MONTH.  How many days are there in the current month?
 *   INPUT  month    the month we are inquiring about
 *          year     we only care about this when month == 2
 *   OUTPUT return   return the number
 *****************************************************/
int Date::daysMonth(int month, int year)
{
   if (month > 12 || month < 1)
   {
      assert(false);
      return 0;
   }

   const int DAYS[13] =
   /* JAN FEB MAR APR MAY JUN JUL AUG SEP OCT NOV DEC */
      { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   
   // special case the one leap month
   if (month == 2 && this->isLeapYear(year))
      return 29;
   
   assert(month > 0 && month < 13);
   return DAYS[month];
}

/***********************************************
 * IS LEAP YEAR.  Is the passed year a leap year?
 *   INPUT   year    The current year
 *   OUTPUT  return  True if we are in a leap year
 **********************************************/
bool Date::isLeapYear(int year)
{
   // no leap years before 1753
   assert(year >= 1753);

   // what, are you Buck Rogers?
   assert(year < 2500);

   // Not a leap year if not evenly divisible by 4
   // This will eliminate 75% of all years
   if (year % 4 != 0)
      return false; // 2001, 2002, 2003, 2005, etc.
   assert(year % 4 == 0);

   // Is a leap year if not divisible by 100
   // This will eliminate 96% of the rest
   if (year % 100 != 0)
      return true; // 1996, 2004, 2008, 2012, etc.
   // We better be 1800, 1900, 2000, 2100 at this point
   assert(year % 100 == 0);

   // Is a leap year if on the quad century
   if (year % 400 == 0)
      return true; // 1600, 2000, 2400, etc.
   // It better be something like 1800, 1900, 2100, etc.
   assert(year % 400 != 0);

   // the balance better be 1900, 1800, etc.
   assert(year == 1800 || year == 1900 || year == 2100 || year == 2200);
   return false;
}
