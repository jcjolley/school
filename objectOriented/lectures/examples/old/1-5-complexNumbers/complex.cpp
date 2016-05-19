/***********************************************************************
* Program:
*    Example 15, Complex numbers
*    Brother Helfrich, CS165
* Author:
*    Br. Helfrich
* Summary:
*    This is the implementation file where the functions in the prototypes
*    are implemented.  
************************************************************************/

#include <iostream>
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

