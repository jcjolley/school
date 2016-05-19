/***********************************************************************
 * This program is designed to demonstrate:
 *      How to use an iterator to loop through a linked list
 ************************************************************************/

#include <iostream>          // for CIN and COUT
#include <list>              // for the linked list container called LIST
using namespace std;

/**********************************************************************
 * This will be just a simple driver program 
 ***********************************************************************/
int main()
{
   // declare a list object
   list <int> data;

   // prompt the user for 3 numbers
   cout << "Please enter five numbers\n";
   for (int i = 0; i < 5; i++)
   {
      int value;
      cout << "> ";
      cin  >> value;
      data.push_back(value);
   }

   // delete the even numbers
   for (list <int> :: iterator it = data.begin(); it != data.end(); it++)
      if (*it % 2 == 0)                // determine if the number is even
         it = data.erase(it);          // update it when we erase the number
         
   // display the numbers
   cout << "The list with even numbers removed\n";
   for (list <int> :: iterator it = data.begin(); it != data.end(); it++)
      cout << *it << ' ';
   cout << endl;

   return 0;
}
