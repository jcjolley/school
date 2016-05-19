/***********************************************************************
* Program:
*    Assignment 17, Robust input
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
* Summary: 
*    This is a driver program for a function design to accept an
*    index from the user and work regardless of the type of input
*    the user may type.
*
*    Estimated:  0.2 hrs   
*    Actual:     0.6 hrs
*      I was ignoring before clearing and it caused problems
************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

int getIndex(int min, int max);

/**********************************************************************
 * MAIN: Simple driver program for getIndex()
 ***********************************************************************/
int main()
{
   int index = getIndex(1 /*min*/, 10 /*max*/);

   cout << "The user's index is: " << index << endl;
   
   return 0;
}

/**********************************************************************
 * getIndex
 * robustly gets the index and returns it.
 **********************************************************************/
int getIndex(int min, int max)
{
   assert(max > min);
   cout << "Please enter the index.  "
        << "The acceptable range is 1 <= index <= 10.\n> ";
   int index = min -1;
   for (;;)
   {
      cin >> index;
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(1000, '\n');
         assert(!cin.fail());   
         cout << "ERROR: non-digit entered\n> ";
      }
      else if (index < min || index > max)
         cout << "ERROR: value is outside the accepted range\n> ";
      else
      {
         assert(index >= min && index <= max);
         return index;
      }
   }
}
