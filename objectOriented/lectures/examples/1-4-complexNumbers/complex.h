/***********************************************************************
* Header:
*    Complex
* Summary:
*    This header file defines the format for a single complex number. 
************************************************************************/

#ifndef COMPLEX_H
#define COMPLEX_H

// Main data structure: a complex number
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

// Is the current number zero?
bool isZero(const Complex & num);

#endif // COMPLEX_H

