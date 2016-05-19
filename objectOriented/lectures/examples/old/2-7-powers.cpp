/***********************************************************************
 * This demo program is designed to:
 *      Demonstrate Recursion
 ************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

double powers(double value, int exponent);

/**********************************************************************
 * Just a driver program
 ***********************************************************************/
int main()
{
   // directions
   cout << "This program will compute: n^e.\n";

   // get the value
   cout << "Please specify n: ";
   double value;
   cin  >> value;

   // get the exponent
   cout << "Please specify e: ";
   int exponent;
   cin >> exponent;

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);
   cout << "the value "
        << value << "^"
        << exponent << " is: "
        << powers(value, exponent) << endl;
   
   return 0;
}


/***********************************
 * POWERS
 * Find the exponent.  The equation is:
 *    powers(value, 0)        = 1;
 *    powers(value, exponent) = value * powers(value, exponent - 1)
 **********************************/
double powers(double value, int exponent)
{
   assert(exponent >= 0);
   if (exponent == 0)
      return 1.0;
   else
      return value * powers(value, exponent - 1);
}
