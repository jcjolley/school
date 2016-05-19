/***********************************************************************
 * This demo program is designed to:
 *      Demonstrate the use of constructors and destructors
 ************************************************************************/

#include <iostream>
using namespace std;

/**********************************
 * This class is, well, silly
 *********************************/
class Silly
{
public:
   Silly()
   {
      cout << "\tDefault constructor\n";
   };
   Silly(const Silly &s)
   {
      cout << "\tCopy Constructor\n";
   };
   ~Silly()
   {
      cout << "\tDestructor\n";
   };
};

/**********************************
 * Just a silly function passing a Silly
 * as pass-by-value
 *********************************/
const Silly functionValue(const Silly s)
{
   cout << "\tInside the function Value\n";
   return s;
}

/**********************************
 * Just a silly function passing a Silly
 * as pass-by-reference
 *********************************/
const Silly & functionReference(const Silly & s)
{
   cout << "\tInside the function Reference\n";
   return s;
}

/******************
 * main()...
 ******************/
int main()
{
   cout << "main() start\n";
   Silly s1;
   cout << "main() after s1 is created\n";
   Silly s2(s1);
   cout << "main() after s2 is created\n";
   functionValue(s1);
   cout << "main() after functionValue is called\n";
   functionReference(s1);
   cout << "main() after functionReference is called\n";

   return 0;
}
