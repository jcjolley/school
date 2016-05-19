/***********************************************************************
 * This demo program is designed to:
 *      A generic algorithm implemented with a float stand-in
 ************************************************************************/

#include <iostream>    // for CIN and COUT
#include <string.h>    // for STRCMP
using namespace std;

/*******************************************************
 * BINARY SEARCH: perform a binary search
 * Input:
 *    array:    a list to search through
 *    size:     the size of the array
 *    pCompare: a compare callback: negative is smaller, zero is equal, etc. 
 *    search:   the value being searched for
 * Output:
 *    bool:     true if found, false if not found
 ******************************************************/
bool binarySearch(const void * array[],            // an array of void pointers
                  int size,                        // number of items in array
                  int (*pCompare)(const void *, const void *), 
                  const void * search)             // the search value
{
   int iFirst = 0; 
   int iLast  = size - 1;

   // loop through the list
   while (iLast >= iFirst) 
   {                                 
      int iMiddle = (iLast + iFirst) / 2;

      int compare = pCompare(array[iMiddle], search);
      if (compare == 0)                            // 0 means they are the same
         return true;
      if (compare > 0)                             // positive means bigger
         iLast = iMiddle - 1;   
      else                                         // negative means smaller
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
   const char * values[10] =
   {
      "Adam",  "Benjamin", "Esther", "Isaiah",  "Joseph",
      "Mary",  "Moroni",   "Mosiah",  "Nephi",  "Peter"
   };

   // the value to search for
   char search[256];
   cout << "Which item to you want to find? ";
   cin  >> search;

   // binary search
   if (binarySearch((const void **)values,                
                    10,
                    (int  (*)(const void *, const void *))strcmp,
                    (const void *)search))
      cout << "\tThe name is in the list\n";
   else
      cout << "\tThe name is not in the list\n";

   return 0;
}

