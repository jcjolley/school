/***********************************************************************
* Program:
*    Assignment 27, Recursion
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
* Summary: 
*    This program will recursivly add.    
*    Estimated:  1.0 hrs   
*    Actual:     0.5 hrs
*      Making sure I fit the program's specifications.  I'm not sure I
*      do still.  It's recursion, but perhaps not how you wished it.
************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

#ifdef DEBUG
#define debug(x) cout << #x << ": " << x << endl;
#else
#define debug(x)
#endif

int add(int m, int n);

/**********************************************************************
 * Main is our driver program. We shall call him Sir William the third...
 * his royal hiney has fallen on hard times and now he chauffeurs
***********************************************************************/
int main()
{
   Add add;
   int m;
   int n;
   int sum;
   cout << "This program performs addition: sum = m + n\n";
   cout << "m: ";
   cin >> m;
   cout << "n: ";
   cin >> n;
   
   cout << "sum: " << add(m,n) << endl;
   
   return 0;
   
}

/**********************************************************************
 * add
 * This function adds using recursion
 **********************************************************************/
int Add::add(int m, int n)
{
   if (m == 0)
      return n 
   else
   {
     return 1 + add(m - 1,n);
   }
}
