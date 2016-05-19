/***********************************************************************
 * This demo program is designed to:
 *      Demonstrate how to use the map container.  This will be demonstrated
 *      with a program retrieving an individual's phone number using the
 *      name as a key
 ************************************************************************/

#include <iostream>
#include <string>
#include <map>
using namespace std;

/**********************************************************************
 * MAIN
 * Simple program designed to demonstrate the map
 ***********************************************************************/
int main()
{
   // declare a map between phone numbers and names
   map <string, string> phoneNumbers;         // a map with a string index
   string number;                             //    and a string item
   string name;

   // fill the list
   cout << "Please enter five phone numbers and names:\n";
   for (int i = 0; i < 5; i++)
   {
      cout << "> ";
      cin  >> number;
      cin.ignore();
      getline(cin, name);
      phoneNumbers[name] = number;            // add items to the map with []
   }

   // now retrieve the name
   cout << "Enter someone's name: ";
   getline(cin, name);
   number = phoneNumbers[name];               // retrieve items with []
   if (number.size() == 0)                    // if the key does not exist, a
      cout << "No number from that name\n";   //    default object is returned
   else
      cout << "That phone number of "
           << name << " is "
           << number << endl; 

   return 0;
}

