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
#ifndef FILE_H
#define FILE_H

#include<iostream>

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

#endif
