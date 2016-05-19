/***********************************************************************
 * This demo program is designed to:
 *      Virtual Functions
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
 * main(), a driver program for our base and derived classes
 ***********************************************************************/
int main()
{
   Derived derived;
   Base base;

   derived.funky();
   base.funky();

   return 0;
}
