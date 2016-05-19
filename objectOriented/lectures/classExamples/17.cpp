/***********************************************************************
 * This demo program is designed to:
 *      
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**********************************************************************
 * main()...
 ***********************************************************************/
int main()
{
   int array1[10];
   vector < string > array2;

   cout << "my vector is now " << array2.size() << " elements large\n";

   // fill my array
   string text;
   while (text != "quit")
   {
      cout << array2.size() << ":" << array2.capacity() << "> ";
      cin  >> text;
      array2.push_back(text);
   }

   // the new size
   cout << "my vector is now " << array2.size() << " elements large\n";

   // display the contents
   for (int i = 0; i < array2.size(); i++)
      cout << "\t" << array2[i] << endl;
      

   
   return 0;
   
}
