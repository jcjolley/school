/***********************************************************************
 * This demo program is designed to:
 *      The string, vector, and map class.
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

void vectorOfFloatsDemo();
void stringDemo();
void mapOfCharsAndStringsDemo();

/**********************************************************************
 * main()...
 ***********************************************************************/
int main()
{
   vectorOfFloatsDemo();
   stringDemo();
   mapOfCharsAndStringsDemo();
   
   return 0;
}

/****************************************
 * VECTOR OF FLOATS DEMO
 * Demostrate how to create, populate,
 * and display a vector of floating point
 * numbers.  Recall that vectors are
 * much like arrays...
 ****************************************/
void vectorOfFloatsDemo()
{
   // intro
   cout << "######################\n";
   cout << "Demo: Vector of floats\n";
   vector<float> list;

   // fill the vector
   cout << "\tPlease enter 5 values:\n";
   for (int i = 0; i < 5; i++)
   {
      float value;
      cout << "\t# " << i + 1 << ": ";
      cin  >> value;
      list.push_back(value);
   }

   // display the list
   cout << "\tThe values are: ";
   for (int i = 0; i < 5; i++)
      cout << list[i] << (i == 4 ? "\n" : ", ");
}

/************************************
 * STRING DEMO
 * Demostrate how to create a string, copy
 * it, and display it various ways. Recall
 * that strings are similar to character arrays
 ***********************************/
void stringDemo()
{
   // intro
   cout << "######################\n";
   cout << "Demo: Strings\n";
   string text;

   // fill the string
   cout << "\tPlease enter some text: ";
   cin  >> text;

   // copy the string with quotes around it
   string textOutput;
   textOutput = "\"";
   textOutput += text + "\"";

   // display the results
   cout << "\tThe string is: " << textOutput << endl;
}

/**************************************
 * MAP OF CHARS AND STRINGS DEMO
 * Demonstrate how to create a mapping of
 * single characters to strings.  A map
 * is much like a simple database
 **************************************/
void mapOfCharsAndStringsDemo()
{
   // intro
   cout << "######################\n";
   cout << "Demo: Map\n";
   map <char, string> data;

   // fill the map
   cout << "\tPlease enter 5 strings, each with a different first letter\n";
   for (int i = 0; i < 5; i++)
   {
      string text;
      cout << "\t# " << i + 1 << ": ";
      cin  >> text;

      char key = text[0];  // the key is the first letter in this case
      data[key] = text;    // add an item with a simple assignment
   }

   // display the results
   cout << "\tWhich item do you wish to retrieve? Specify the first letter: ";
   char key;
   cin >> key;
   cout << "\tThe string beginning with '"
        << key << "' is \""
        << data[key] << "\"\n";
}
