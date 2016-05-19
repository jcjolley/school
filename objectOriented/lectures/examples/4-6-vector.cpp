/***********************************************************************
 * This demo program is designed to:
 *      Demonstrate the vector
 ************************************************************************/

#include <iostream>        // for CIN and COUT
#include <vector>          // for the VECTOR class
using namespace std;

/**********************************************************************
 * MAIN
 * Just a simple program to demonstrate vectors
 ***********************************************************************/
int main()
{
   vector <float> data;                     // declaration

   // fill the vector
   cout << "Please enter 5 values:\n";
   for (int i = 0; i < 5; i++)
   {
      float value;
      cout << "\t# " << i + 1 << ": ";
      cin  >> value;
      data.push_back(value);                // add with push-back
   }

   // display the list
   cout << "The values are: ";
   for (int i = 0; i < data.size(); i++)    // get size with size()
      cout << data[i]                       // random access with []
           << (i == 4 ? "\n" : ", ");

   // the destructor usually erases the list
   data.clear();                            // erase everything
   cout << "size:     "
        << data.size() << endl;             // size better be zero
   cout << "capacity: "
        << data.capacity() << endl;         // capacity does not go to zero

   return 0;
}
