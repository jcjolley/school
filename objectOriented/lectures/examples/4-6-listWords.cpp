/***********************************************************************
 * This program is designed to demonstrate:
 *      How to work with the list container.  This will hold a list
 *      of strings.
 ************************************************************************/

#include <iostream>    // for CIN and COUT
#include <list>        // for the LIST container
#include <string>      // a list of STRINGS
using namespace std;

/********************************************************************** 
 * MAIN
 * This will demonstrate how to create a list of strings
 ***********************************************************************/
int main()
{
   // declare a list of strings
   list <string> data;

   // add items on to the end of the list with push_back
   data.push_back(string("five"));     
   data.push_back(string("six"));

   // add items to the head of the list
   data.push_front(string("two"));
   data.push_front(string("one"));

   // add items to the middle
   list <string> :: iterator it = data.begin();
   it++;   // skip the first
   it++;   // skip the second
   it = data.insert(it, string("four"));
   it = data.insert(it, string("three"));

   // display the list forwards
   cout << "The list displayed forwards\n";
   for (it = data.begin(); it != data.end(); it++)
      cout << '\t' << *it << ' ';
   cout << endl;

   // display the list backwards
   cout << "The list displayed backwards\n";
   list <string> :: reverse_iterator rit;
   for (rit = data.rbegin(); rit != data.rend(); rit++)
      cout << '\t' << *rit << ' ';
   cout << endl;
   
   return 0;
}
