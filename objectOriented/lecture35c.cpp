/***********************************************************************
 * This demo program is designed to:
 *      Slicing Problem
 ************************************************************************/

#include <iostream>
using namespace std;

/*****************************
 * Base class
 *****************************/
class Base
{
public:
   virtual void funky() { cout << "Base!\n"; };
};

/***************************
 * Derived class
 **************************/
class Derived: public Base
{
public:
   virtual void funky() { cout << "Derived!\n"; };
};

/**********************************************************************
 * main()...
 ***********************************************************************/
int main()
{
   Derived derived;
   derived.funky();

   Base base = derived;
   base.funky();
   
   return 0;
}
