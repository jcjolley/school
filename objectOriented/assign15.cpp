/***********************************************************************
* Program:
*    Assignment 15, Complex numbers
*    Brother Helfrich, CS165
* Author:
*    your name
* Summary: 
*    This program is designed to perform very simple manipulations of
*    Complex numbers.  A complex number, as you may recall, is a two
*    part number with a real and imagionary part.
*
*    Your assigment here is to break this file into four parts:
*       complex.h        Header file with data types and prototypes
*       complex.cpp      All the functions manipulating complex numbers
*       complexTest.cpp  Driver program exercising the complex type.
*       makefile         File describing how to build this project
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>
using namespace std;

struct Complex
{
   double real;
   double imaginary;
};

// Prompt the user for a complex number in a user-friendly way
void prompt(Complex & complex);

// Display the complex number on the screen
void display(const Complex & complex);

// Add a number to the current complex number.  Input
// will be in the following form:  lhs += rhs;
void addTo(Complex & lhs, const Complex & rhs);

/*************************************************************
 * IS ZERO: Is the current number zero?
 *   INPUT:  complex number to check
 *   OUTPUT: return whether it is zero
 ************************************************************/
inline bool isZero(const Complex & num)
{
   return (num.real == 0.0 && num.imaginary == 0.0);
}

/**********************************************************************
 * PROMPT:  Prompt the user for a complex number in a user-friendly way
 *   INPUT:   none
 *   OUTPUT:  complex - by pass-by-reference
 **********************************************************************/
void prompt(Complex & complex)
{
   cout << "Please specify the real and imaginary components: ";
   cin  >> complex.real >> complex.imaginary;
}

/******************************************************************
 * DISPLAY: Display the complex number on the screen
 *   INPUT:   complex - to be displayed
 *   OUPUT:   none
 ******************************************************************/
void display(const Complex & complex)
{
   cout.setf(ios::fixed);
   cout.precision(1);
   cout << complex.real << " + " << complex.imaginary << "i";
}

/*****************************************************************
 * ADD TO:  Add a number to the current complex number.  Input
 * will be in the following form:  lhs += rhs;
 *   INPUT:  lhs - Left hand side of the equation - to be added to
 *           rhs - Right hand side of the equation
 *   OUTPUT  lhs - accepting the new value
 *****************************************************************/
void addTo(Complex & lhs, const Complex & rhs)
{
   lhs.real      += rhs.real;
   lhs.imaginary += rhs.imaginary;
}


/**********************************************************************
 * Just a simple driver program to help the user test this new data type
 ***********************************************************************/
int main()
{
   // This is the number we will work with
   Complex number;
   prompt(number);
   cout << "\tCurrent value: ";
   display(number);
   cout << endl;

   // keep going until zero is entered
   while (!isZero(number))
   {
      // grab a new number
      Complex num2;
      prompt(num2);

      // add to current one
      addTo(number, num2);

      // display
      cout << "\tNew value: ";
      display(number);
      cout << endl;
   }

   return 0;
}
