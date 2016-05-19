/***********************************************************************
 * This demo program is designed to:
 *      Demonstrate prefix notation for common functions
 ************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * This is a very simple program
 ***********************************************************************/
int main()
{
   // the same thing as:
   //     cout << "Hello world\n";
   // isn't the infix notation much nicer?
   operator<<(cout, "Hello world\n");
   
   return 0;
}
