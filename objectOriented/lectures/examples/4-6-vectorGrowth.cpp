/***********************************************************************
 * This program is designed to:
 *    demonstrate how a vector grows by factors of two as
 *    more items are added to it.  
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

/***************************************************
 * MAIN
 * This demo consists of a single function to demonstrate
 * the growth properties of vectors
 **************************************************/
int main()
{
   vector <int> list;                            // initially zero size

   // The initial size of a vector
   cout << "When first created, there are "
        << list.capacity()
        << " items in the vector\n";

   // Now we will add items to the list, one at a time.
   cout << "Size\tCapacity\n";
   for (int i = 0; i < 40; i++)                
   {
      list.push_back(i);
      cout << " "   << list.size()
           << "\t " << list.capacity() << endl;
   }
   
   return 0;
}
