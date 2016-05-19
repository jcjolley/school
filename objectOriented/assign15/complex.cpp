/***********************************************************************
* Program:
*    Assignment 15, Separate Compilation
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
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
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
*      Just wrapping my head around the whole concept... as soon
*      as I figured out what I was doing it all came together.
************************************************************************/
#include "complex.h"

using namespace std;

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

