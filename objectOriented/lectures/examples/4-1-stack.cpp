/***********************************************************************
 * This program is designed to demonstrate:
 *      A generic data-structure implemented with void pointers
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
      void push(void * value) throw(bool)
      {
         if (size < MAX)
            data[size++] = value;   // must support the assignment operator
         else
            throw false;
      }
      // pop an item off the stack if there is one.  Otherwise throw
      void * pop() throw(bool)
      {
         if (size)
            return data[--size];    // must support the assignment operator
         else
            throw false;
      }         
   private:
      void * data[MAX];             // a stack of void pointers
      int    size;                  // number of items currently in the stack
};

/********************************************************************** 
 * This will be just a simple driver program to test Stack 
 ***********************************************************************/
int main()
{
   Stack stack;

   // add two items: "four" "one"
   stack.push((void *)"four");
   stack.push((void *)"one");

   // pop off one item: "one"
   cout << (char *)stack.pop() << endl;

   // add two more: "three" "two"
   stack.push((void *)"three");
   stack.push((void *)"two");

   // pop them all off: "two" "three" "four"
   cout << (char *)stack.pop() << endl;
   cout << (char *)stack.pop() << endl;
   cout << (char *)stack.pop() << endl;   
   
   return 0;
}
