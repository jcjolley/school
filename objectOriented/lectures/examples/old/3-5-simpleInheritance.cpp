/***********************************************************************
 * This demo program is designed to:
 *      Demonstrate virtual Functions.  However, in this case,
 *      they are working like simple inheritance because there
 *      are no pointers.
 ************************************************************************/

#include <iostream>
using namespace std;

/*****************************
 * Base class
 *****************************/
class Base
{
public:
   /************************************************
    * BASE :: METHOD
    * Virtual function in the base class
    ************************************************/
   virtual void method()
   {
      cout << "Base!\n";
   }
};

/***************************
 * Derived class
 **************************/
class Derived: public Base
{
public:
   /************************************************
    * DERIVED :: METHOD
    * Virutal function in the derived class
    ************************************************/
   virtual void method()
   {
      cout << "Derived!\n";
   }
};

/**********************************************************************
 * main(), a driver program for our base and derived classes
 ***********************************************************************/
int main()
{
   // create one instance of the base class
   Base base;

   // create one instance of the derived class
   Derived derived;

   // this will display "Base!" 
   base.method();

   // this will display "Derived!"
   derived.method();

   return 0;
}
