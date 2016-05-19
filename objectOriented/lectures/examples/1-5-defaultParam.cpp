/***********************************************************************
 * This program is designed to demonstrate:
 *      Default parameters
 ************************************************************************/

#include <iostream>
using namespace std;

// the prototype where we specify the default parameter information
void defaultParam(int one = 0, int two = 0, int three = 0);

/**********************************************************************
* This will be just a simple driver program for defaultParam()
***********************************************************************/
int main()
{
   // zero parameters
   cout << "defaultParam()        : ";
   defaultParam();

   // one parameter.  one == 1
   cout << "defaultParam(1)       : ";
   defaultParam(1);

   // two parameters.  one == 1, two == 2
   cout << "defaultParam(1, 2)    : ";
   defaultParam(1, 2);

   // three parameters.  one == 1, two == 2, three == 3
   cout << "defaultParam(1, 2, 3) : ";
   defaultParam(1, 2, 3);
   
   return 0;
}

/**********************************************
 * DEFAULT PARAM
 * Observe how the function declaration makes
 * no reference to the default params.  That
 * occurs in the function prototype.  If there were
 * no prototype, we would specify the default
 * parameter information here
 **********************************************/
void defaultParam(int one, int two, int three)
{
   cout << "defaultParam(" << one << ", " << two << ", " << three << ")\n";
}

