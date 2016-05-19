/***********************************************************************
 * This demo program is designed to:
 *      demostrate the Slicing Problem
 ************************************************************************/

#include <iostream>
using namespace std;

/*****************************
 * Base class
 *****************************/
class Base
{
public:
   /******************************************
    * BASE :: METHOD
    * Virtual function in Base class. Note that
    * this is not inline because it is a virtual
    * function.  Even if you use the "inline"
    * keyword, the compiler will still make it
    * a normal function.
    ******************************************/
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
   /*****************************************
    * DERIVED :: METHOD
    * Another implementation of method
    *****************************************/
   virtual void method()
   {
      cout << "Derived!\n";
   }
};

/**********************************************************************
 * Demonstrate the slicing problem
 ***********************************************************************/
int main()
{
   // we will create a Derived
   Derived derived;
   // this will display "Derived!"
   derived.method();

   // here we will assign Derived to Base but, due to the slicing problem,
   // we forget that we ever were a Derived.  We become, in essence, a Base
   // here.  This is the slicing problem.
   Base base = derived;
   // even though we assigned derived to base, we are of type base.  We
   // have Base's VTable, not Derived.
   // this will display "Base!"
   base.method();


   // now we will avoid the slicing problem.  We will not turn derived
   // into base, we will just copy the pointer. This means that we keep
   // what was unique about it.
   Base *pBase = &derived;
   // this will display "Derived!"
   pBase->method();
   
   return 0;
}
