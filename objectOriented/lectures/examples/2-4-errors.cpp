/***********************************************************************
 * This program is designed to demonstrate:
 *      What would happen if there is no default constructor?
 ************************************************************************/

#include <iostream>
using namespace std;

/***********************************************************
 * SIMPLE
 * A simple class designed to show what would happen when
 * there is no default constructor
 ***********************************************************/
class Simple
{
   public:
      Simple(int value) : value(value) {      }  // non-default constructor 
   private:
      int value;
};

/**********************************************************************
 * This will be just a simple driver program 
 ***********************************************************************/
int main()
{
   Simple s;               // ERROR: no default constructor
   return 0;
}

