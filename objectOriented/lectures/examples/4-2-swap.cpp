/***********************************************************************
 * This program is designed to demonstrate:
 *      How to use a function template
 ************************************************************************/

#include <iostream>   // for COUT
#include <string>     // for the STRING class
using std::cout;      // notice that we are not "using namespace std;" because
using std::endl;      //   there is a standard function called std::swap
using std::string;    //   that will be confused with ours

/********************************************
 * SWAP
 * Swap the left-hand-side with the right-hand-side.
 * All data-types need to support the assignment operator
 ********************************************/
template <class T>
void swap(T & lhs, T & rhs)
{
   T tmp = lhs;
   lhs = rhs;
   rhs = tmp;
}

/**********************************************************************
* This will be just a simple driver program 
***********************************************************************/
int main()
{
   // swap text
   string text1("First");
   string text2("Second");
   swap(text1, text2);
   cout << "The values swapped: " << text1 << ' ' << text2 << endl;

   // swap numbers
   double value1(3.14159);
   double value2(2.71828);
   swap(value1, value2);
   cout << "The values swapped: " << value1 << ' ' << value2 << endl;

   return 0;
}
