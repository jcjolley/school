/***********************************************************************
* Program:
*    DATE.H, Date Class
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




#ifndef DATE_H
#define DATE_H

#include <string>
using std::string;

enum {DAY, MONTH, YEAR};

//
// Date structure
//

class Date
{
  public:
   Date(int year, int month = 1, int day = 1);
   Date();
   Date(Date & temp);
   Date(const Date &temp);
   
   bool setDate(int year, int month, int day);
   bool setYear(int year);
   bool setMonth(int month);
   bool setDay(int day);
   int  getDay()   const { return data[DAY];   }
   int  getMonth() const { return data[MONTH]; }
   int  getYear()  const { return data[YEAR];  }
   void displayLong();


   friend std::ostream & operator << (std::ostream & out, const Date & date);
   friend std::istream & operator >> (std::istream & in, Date & date);
   Date & operator += (const int adjustment);
   Date & operator -= (const int adjustment);
   friend bool operator == (const Date &lhs, const Date &rhs);
   friend bool operator != (const Date &lhs, const Date &rhs);
   Date & operator ++ () {return operator += (1);}
   Date & operator -- () {return operator -= (1);}
   Date operator ++ (int postfix);
   Date operator -- (int postfix);
   Date operator + (const int adjustment) const;
   Date operator - (const int adjustment) const;
      
   friend Date operator + (int lhs, const Date & rhs);
   friend bool operator >= (const Date &lhs, const Date &rhs);
   friend bool operator >  (const Date &lhs, const Date &rhs);
   friend bool operator <= (const Date &lhs, const Date &rhs);
   friend bool operator <  (const Date &lhs, const Date &rhs);
   
   ~Date();

  private:
   void allocate();
   void adjustDay  (int adjustment);
   void adjustMonth(int adjustment);
   void adjustYear (int adjustment);
   int daysMonth(int month, int year);
   bool isLeapYear(int year);
   int *data;  // dynamically allocated
   void assertDate();

};


#endif
