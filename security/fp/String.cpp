/***********************************************************************
 * Program:
 *    Unit 2, Safe String
 *    Brother Helfrich, CS 470
 * Author:
 *    Joshua Jolley
 * Summary:
 *    Secure string class.
 ************************************************************************/
#include <cmath>
#include "String.h"
#include "myUtils.h"

#ifdef DEBUG
#define debug(x) std::cerr << #x << ": " << x << std::endl
#define D(x) x
#else
#define debux(x)
#define D(x)
#endif

String::String(const char * a) {
   length = Strlen(a);
   if (size == 0)
      size = 1;
   else
      size = log2((float) length + 1);

   for (; size < length; size *= 2);
   str = new char[size];

   char * p = str;
   const char * p2 = a;
   for (; *p2; p++,p2++)
   {
      *p = *p2;
   } 
}

String::String(String & a) {
   *this = String(a.str);
}

String String::Strcat(const char * a) {
   //check to see if we need a bigger buffer
   int newSize = length + Strlen(a) + 1;
   for (; size < newSize; size *= 2);
   
   //initialize a new cstring to replace str
   char * newStr = new char[size];
   char * p2 = newStr;

   //move the contents of str to new str
   for (char * p = str ; *p; p++, p2++) {
      *p2 = *p;
   }

   //free our memory and replace str with newStr
   if (str != NULL)
      delete [] str;
   str = newStr;
   char * p = str;

   //get to the null character
   for (; *p; p++);

   //concatenate a into str
   for (const char * p2 = a; *p2; p++, p2++) {
      *p = *p2;
   }

   //we like null terminated strings
   *p = '\0';

   length = Strlen(str);
   return *this;
}