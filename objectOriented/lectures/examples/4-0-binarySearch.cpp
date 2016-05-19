/***********************************************************************
 * This demo program is designed to:
 *      A generic algorithm implemented with a float stand-in
 ************************************************************************/

#include <iostream>
using namespace std;

/*******************************************************
 * BINARY SEARCH: perform a binary search
 * Input:
 *    numbers: a list of numbers to search through
 *    size:    the size of the numbers list
 *    search:  the number that you are searching for
 * Output:
 *    bool:    true if found, false if not found
 ******************************************************/
bool binarySearch(const float numbers[], int size, float search)
{
   int iFirst = 0; 
   int iLast  = size - 1;

   // loop through the list
   while (iLast >= iFirst) 
   {                                 
      int iMiddle = (iLast + iFirst) / 2;

      if (numbers[iMiddle] == search)     // must support == operator
         return true;
      if (numbers[iMiddle] > search)      // must support > operator
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
   float values[] =
   {
      1.2, 3.1, 5.8, 7.2, 7.2, 8.9, 9.0, 11.4, 13.6
   };

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

