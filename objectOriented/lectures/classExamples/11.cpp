/***********************************************************************
 * This demo program is designed to:
 *      multiple input with CIN
 ************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

/**********************************************************************
 * main()...
 ***********************************************************************/
int main()
{
   int x;
   int y;

   cout << "Give me numbers or give me death: ";
//   cin  >> x;
//   cin  >> y;
   cin >> x >> y;
   
   cout << "The values are: ("
        << x << ", " << y
        << ")\n";

   assert(x > 3);
   
   return 0;
}
