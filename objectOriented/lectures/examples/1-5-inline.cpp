/***********************************************************************
 * This program is designed to demonstrate:
 *      Inline functions
 ************************************************************************/

#include <iostream>
using namespace std;

/************************************************
 * MULTIPLY - INLINE
 * This function is inline, but it behaves exactly
 * the same as the other
 ***********************************************/
inline int multiplyInline(int value1, int value2)
{
   return value1 * value2;
}

/************************************************
 * MULTIPLY - STANDARD
 * Another version of MULTIPLY functionally the same
 * as addInline()
 ***********************************************/
int multiplyStandard(int value1, int value2)
{
   return value1 * value2;
}


/**********************************************************************
* This will be just a simple driver program 
***********************************************************************/
int main()
{
   // the inline version
   cout << "multiplyInline(6, 7)   = "
        <<  multiplyInline(6, 7)
        << endl;

   // the standard version
   cout << "multiplyStandard(6, 7) = "
        <<  multiplyStandard(6, 7)
        << endl;
   
   return 0;
}
