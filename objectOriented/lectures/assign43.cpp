/***********************************************************************
* Program:
*    Assignment 43, Class Templates
*    Brother Helfrich, CS165
* Author:
*    your name
* Summary: 
*    A class template is similar to a function template, except the
*    abstract type can be applied to all member functions and all
*    member variables of the class. Your job with this assignment is
*    to convert the following class to be type-agnostic.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


// this allows to me conveniently add debug code.  See push() for an example
#ifdef NDEBUG
#define DEBUG(x)    // disappears in ship (or non-debug) mode
#else
#define DEBUG(x) x  // appears in debug mode 
#endif // NDEBUG

/****************************************************
 * STACK: a first-in, last-out data structure
 ****************************************************/
class Stack
{
   public:
      bool pop( float & value);
      void push(float   value);
      bool isEmpty()          { return data.size() == 0; }
   private:
      vector <float> data;
};


/**********************************************************************
 * MAIN: Simple driver program to exercise our Stack data type
 ***********************************************************************/
int main()
{
   //
   // Integer Stack
   //

   cout << "#### Integers ####\n";
   Stack <int> stack; 
   int value;

   // add three to the stack
   for (int i = 0; i < 3; i++)
   {
      cout << "push: ";
      cin >> value;
      stack.push(value);
   }
   
   // remove one just for kicks
   stack.pop(value);
   cout << "\tpop: " << value << endl;

   // add three more
   for (int i = 0; i < 3; i++)
   {
      cout << "push: ";
      cin >> value;
      stack.push(value);
   }

   // remove them all 
   while (stack.pop(value))
      cout << "\tpop: " << value << endl;
   assert(stack.isEmpty());

   //
   // String Stack
   //

   cout << "#### Strings ####\n";
   Stack <string> stringStack;
   string stringValue;

   // add three to the stack
   for (int i = 0; i < 3; i++)
   {
      cout << "push: ";
      cin >> stringValue;
      stringStack.push(stringValue);
   }

   // remove one just for kicks
   stringStack.pop(stringValue);
   cout << "\tpop: " << stringValue << endl;

   // add three more
   for (int i = 0; i < 3; i++)
   {
      cout << "push: ";
      cin >> stringValue;
      stringStack.push(stringValue);
   }

   // remove them all
   while (stringStack.pop(stringValue))
      cout << "\tpop: " << stringValue << endl;
   assert(stringStack.isEmpty());
   
   return 0;
}




/************************************************
 * POP: remove the item off the end of the list
 *   OUTPUT: value:    The value to be removed from the stack
 *           <return>  Whether the pop was successful
 ************************************************/
bool Stack :: pop(float & value)
{
   // empty stack case.
   if (isEmpty())
      return false;

   // remove the last item off the stack
   assert(data.size() > 0);             // verify not off the end of th elist
   value = data[data.size() - 1];
   data.resize(data.size() - 1);
   assert(data.size() >= 0);            // verify not off the end of the list
   return true;
}


/**********************************************
 * PUSH: add an item to the end of the list
 *   INPUT: value:     The item to be added to the stack
 *********************************************/
void Stack :: push(int float)
{
   DEBUG(int size = data.size(););      // save the size for later
   assert(size >= 0);                   // verify the list is not empty
   data.resize(data.size() + 1, value);
   assert(size + 1 == data.size());     // verify the size is bigger now
   assert(!isEmpty());                  // verify the list is not empty
}
