/***********************************************************************
 * This program is designed to demonstrate:
 *      How to use a void pointer with a function
 ************************************************************************/

#include <iostream>
using namespace std;

/********************************************
 * SWAP
 * Swap the left-hand-side with the right-hand-side.
 * Note that we are swapping pointers so we need
 * to pass the pointer by-reference.
 ********************************************/
void swap(void * & pLhs, void * & pRhs)
{
   void * pTemp = pLhs;
   pLhs = pRhs;
   pRhs = pTemp;
}

/**********************************************************************
* This will be just a simple driver program 
***********************************************************************/
int main()
{
   char buffer1[256];       // this is a constant pointer.  We can change the 
   char buffer2[256];       //    data but not the address of buffer1
   char * p1 = buffer1;     // p1 shares the address of buffer1 but we 
   char * p2 = buffer2;     //    have the ability to change the address

   // prompt the user
   cout << "First message:  ";
   cin.getline(buffer1, 256);
   cout << "Second message: ";
   cin.getline(buffer2, 256);

   // before we swap
   cout << "Before: \"" << p1 << "\", \"" << p2 << "\"\n";

   // swap them
   swap(p1, p2);            // note that we do not need to cast the char *
                            //    to a void pointer.
   // display after the swap
   cout << "After:  \"" << p1 << "\", \"" << p2 << "\"\n";
   
   return 0;
}
