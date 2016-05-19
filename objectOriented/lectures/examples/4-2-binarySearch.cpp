/***********************************************************************
 * This demo program is designed to:
 *      A generic algorithm implemented with templates
 ************************************************************************/

#include <iostream>    // for CIN and COUT
#include <string.h>    // for STRCMP
using namespace std;

/*******************************************************
 * BINARY SEARCH: perform a binary search
 * Input:
 *    array:    a list to search through
 *    size:     the size of the array
 *    search:   the value being searched for
 * Output:
 *    bool:     true if found, false if not found
 ******************************************************/
template <class T>
bool binarySearch(const T array[],                 // an array of values
                  int size,                        // number of items in array
                  const T & search)                // the search value
{
   int iFirst = 0; 
   int iLast  = size - 1;

   // loop through the list
   while (iLast >= iFirst) 
   {                                 
      int iMiddle = (iLast + iFirst) / 2;

      if (numbers[iMiddle] == search)              // must support == operator
         return true;
      if (numbers[iMiddle] > search)               // must support > operator
         iLast = iMiddle - 1;
      else
         iFirst = iMiddle + 1;
   }

   return false;
}

/**********************************************************************
 * MAIN: Simple driver program for the binarySearch algorithm
 ***********************************************************************/
int main()
{
   // list to search in
   float values[] = { 1.2, 3.1, 5.8, 7.2, 7.2, 8.9, 9.0, 11.4, 13.6 };

   // the value to search for
   float search;
   cout << "Which item to you want to find? ";
   cin  >> search;

   // binary search
   if (binarySearch(values, sizeof(values) / sizeof(values[0]), search))
      cout << "\tThe number is in the list\n";
   else
      cout << "\tThe number is not in the list\n";
   
   return 0;
}

