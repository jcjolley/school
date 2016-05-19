/***********************************************************************
 * This program is designed to demonstrate:
 *      Test complex.h
 ************************************************************************/

#include <iostream>
#include "complex.h"   // since everything is inline, no object file is needed
using namespace std;

/**********************************************************************
* This will be just a simple driver program for Complex
***********************************************************************/
int main()
{
   Complex c1;

   for (;;)
   {
      cout << "Old value: " << c1 << endl;

      // prompt for new value
      Complex c2;
      cout << "\n\nEnter a complex number: ";
      cin  >> c2;
      cout << "New value: " << c2 << endl << endl;

      // plus
      cout << '(' << c1 << ")+(" << c2 << ") == " << c1 + c2 << endl;
      cout << '(' << c2 << ")+(" << c1 << ") == " << c2 + c1 << endl;
      cout << '(' << c1 << ")+" << c2.getReal() << " == "
           << c1 + c2.getReal() << endl;
      cout << c2.getReal() << "+(" << c1 << ") == "
           << c2.getReal() + c1 << endl << endl;

      // minus
      cout << '(' << c1 << ")-(" << c2 << ") == " << c1 - c2 << endl;
      cout << '(' << c2 << ")-(" << c1 << ") == " << c2 - c1 << endl;
      cout << '(' << c1 << ")-" << c2.getReal() << " == "
           << c1 - c2.getReal() << endl;
      cout << c2.getReal() << "-(" << c1 << ") == "
           << c2.getReal() - c1 << endl << endl;

      // times
      cout << '(' << c1 << ")*(" << c2 << ") == " << c1 * c2 << endl;
      cout << '(' << c2 << ")*(" << c1 << ") == " << c2 * c1 << endl;
      cout << '(' << c1 << ")*" << c2.getReal() << " == "
           << c1 * c2.getReal() << endl;
      cout << c2.getReal() << "*(" << c1 << ") == "
           << c2.getReal() * c1 << endl << endl;

      // c1 = c2 and loop again...
      c1 = c2;
   }

   
   return 0;
}
