/***********************************************************************
 * This demo program is designed to:
 *      Demonstrate iterators as they work with vectors
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**********************************************************************
 * MAIN
 * A simple program to demonstrate how to create a vector of strings
 * and iterate through them forward and backwards
 ***********************************************************************/
int main()
{
   vector <string> words;

   // fill the vector of words;
   cout << "Please enter some words.  Specify \"Done!\" when done\n";
   string text;
   cin >> text;
   while (text != "Done!")
   {
      words.push_back(text);
      cin >> text;
   }

   // loop through the list
   cout << "The list forwards:\n";
   for (vector <string> :: iterator it = words.begin();
        it < words.end();
        it++)
      cout << "\t" << *it << endl;

   // loop through the list backwards
   cout << "The list backwards:\n";
   for (vector <string> :: reverse_iterator it = words.rbegin();
        it != words.rend();
        it++)
      cout << "\t" << *i << endl;        
   
   return 0;
}
