/***********************************************************************
 * This program is designed to demonstrate:
 *      A generic data-structure implemented with a float stand-in
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX 20

/*********************************************
 * STACK
 * A stack data-structure: first in, last out
 ********************************************/
class Stack 
{
   public:
      // create the stack with a zero size
      Stack() : size(0) {}
      // add an item to the stack if there is room.  Otherwise throw
      void push(float value) throw(bool)
      {
         if (size < MAX)
            data[size++] = value;   // must support the assignment operator
         else
            throw false;
      }
      // pop an item off the stack if there is one.  Otherwise throw
      float pop() throw(bool)
      {
         if (size)
            return data[--size];    // must support the assignment operator
         else
            throw false;
      }         
   private:
      float data[MAX];              // a stack of FLOATS for now
      int   size;                   // number of items currently in the stack
};

/********************************************************************** 
 * This will be just a simple driver program to test Stack 
 ***********************************************************************/
int main()
{
   Stack stack;

   // add two items: 4.5, 1.2
   stack.push(7.8);
   stack.push(1.2);

   // pop off one item: 1.2
   cout << stack.pop() << endl;

   // add two more
   stack.push(5.6);
   stack.push(3.4);

   // pop them all off: 3.4 5.6 7.8
   cout << stack.pop() << endl;
   cout << stack.pop() << endl;
   cout << stack.pop() << endl;   
   
   return 0;
}
