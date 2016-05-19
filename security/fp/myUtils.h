/***********************************************************************
 * Program:
 *    Unit 2, Safe String
 *    Brother Helfrich, CS 470
 * Author:
 *    Joshua Jolley
 * Summary: 
 *    Secure string class.
 ************************************************************************/

#include <cassert>
#include <iostream>

#ifdef DEBUG
#define debug(x) std::cerr << #x << ": " << x << std::endl 
#define D(x) x
#else
#define debug(x)
#define D(x)
#endif
int MAX_LENGTH = 2048;
/***********************************************************************
*  Function Strlen
*  
*  Returns the length of a string
****************************************************************************/
unsigned int Strlen(const char * s)
{
   //we check the size incase the buffer isn't null terminating
   int i = 0;

   for (; s[i]; i++)
   {
      if (i > MAX_LENGTH)
         return MAX_LENGTH;
   }
   return i;
}
 
/***********************************************************************
*  Function Streql
*  
*  Checks if two strings are equal
****************************************************************************/
bool Streql(const char* a, const char* b)
{
   if (a == b)
   {
      return true;
   }

   int lengthA = Strlen(a);
   int lengthB = Strlen(b);

   if (lengthA != lengthB)
   {
      return false;
   }

   for (int i = 0; i < lengthA; i++, a++, b++)
   {
      if (*a != *b)
      {
         return false;
      }
   }

   return true;
}

/***********************************************************************
*  Function Strcmp
*  
*  Compares 2 strings
****************************************************************************/
int Strcmp(const char* a, const char* b, int length)
{
   int lengthA = Strlen(a);
   int lengthB = Strlen(b);

   int minLength = (lengthA <= lengthB) ? lengthA : lengthB;
   minLength = (minLength <= length) ? minLength : length; 

   for (int i = 0; i < minLength; i++, a++, b++)
   {
      if (*a != *b)
      {
         return *a - *b;
      }
   }
   
   if (length <= minLength)
   {
      return 0;
   }

   return lengthA - lengthB;
}