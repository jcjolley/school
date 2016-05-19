/***********************************************************************
 * This program is designed to demonstrate:
 *      Overloading functions
 ************************************************************************/

#include <iostream>
using namespace std;

// overload with an integer parameter
void overload(int value);

// overload with two integer parameters
void overload(int value1, int value2);

// overload with a string parameter
void overload(const char * value);

/**********************************************************************
* This will be just a simple driver program 
***********************************************************************/
int main()
{
   // first use the integer version
   cout << "overload(7):         ";
   overload(7);

   // next, use the two integer version
   cout << "overload(7, 7):      ";
   overload(7, 7);

   // finally, use the c-string version
   cout << "overload(\"seven\"):   ";
   overload("seven");
   
   return 0;
}

/***********************************************
 * OVERLOAD : INTEGER
 * This version of the function takes an integer
 * as a parameter
 **********************************************/
void overload(int value)
{
   cout << "The integer version of the overload() function\n";
}

/***********************************************
 * OVERLOAD : INTEGER
 * This version of the function takes an integer
 * as a parameter
 **********************************************/
void overload(int value1, int value2)
{
   cout << "The multi-integer version of the overload() function\n";
}

/***********************************************
 * OVERLOAD : TEXT
 * This version of the function takes text
 * as a parameter
 **********************************************/
void overload(const char * value)
{
   cout << "The text version of the overload() function\n";
}

