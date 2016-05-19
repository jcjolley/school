/***********************************************************************
 * This demo program is designed to:
 *      unsigned stuff
 ************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * main()...
 ***********************************************************************/
int main()
{
   int regular = 0;
   unsigned int notSigned = 0;

   cout << "regular: " << regular << endl;
   cout << "notSigned: " << notSigned << endl;

   regular--;
   notSigned--;

   cout <<  endl;
   cout << "regular: " << regular << endl;
   cout << "notSigned: " << notSigned << endl;
   
   
   return 0;
}
