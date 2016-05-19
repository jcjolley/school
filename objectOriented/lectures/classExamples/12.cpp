/***********************************************************************
 * This demo program is designed to:
 *      demonstrate asserts
 ************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

/**********************************************************************
 * main()...
 ***********************************************************************/
int main()
{

   int value;
   cout << "What is the land speed of an unladen swallow? ";
   cin  >> value;

   assert(value > 0);

   cout << "What! I don't know that!\n";
      
   
   return 0;
}
