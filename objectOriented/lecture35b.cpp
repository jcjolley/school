/***********************************************************************
 * This demo program is designed to:
 *      Pure Virtual Functions
 ************************************************************************/

#include <iostream>
using namespace std;

/*****************************
 * Base class
 *****************************/
class Base
{
public:
   virtual void funky() = 0;
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
   Base base; // compile error.  Because Base is an Abstract Class due to the
              //                 pure virtual function funky(), we cannot
              //                 instantiate an object of this type.

   base.funky();

   return 0;
}
