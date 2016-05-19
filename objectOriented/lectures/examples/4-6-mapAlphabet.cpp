/***********************************************************************
 * This program is designed to demonstrate:
 *      How to store and retrieve items using a map.  In this case, we will
 *      translate letters into the NATO phonetic alphabet.
 ************************************************************************/

#include <iostream>      // for CIN and COUT
#include <map>           // for the MAP container
#include <string>        // the alphabet will be stored as a STRING
#include <fstream>       // we will read the alphabet from a file
using namespace std;

/*********************************************************************
 * READ ALPHABET
 * Read the phonetic alphabet maping from a file
 ********************************************************************/
void readAlphabet(const char * fileName, map <char, string> & alphabet)
{
   // open the file
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "ERROR: Unable to open the alphabet file " << fileName << endl;
      return;
   }

   // read the file. The first item is the letter
   char letter;
   string word;
   while (fin >> letter >> word)
      alphabet[letter] = word;                // add data to the map with
                                              //    the [] operator 
   // close the file and bail
   fin.close();
   return;
}

/**********************************************************************
 * MAIN
 * Read the alphabet and prompt the user for the letter
 ***********************************************************************/
int main()
{
   // make a maping
   map <char, string> alphabet;               // a map with a char key and
                                              //    a string data item
   // read the alphabet
   readAlphabet("/home/cs165/examples/4-6-mapAlphabet.txt", alphabet);

   // prompt the user for a letter
   char letter;
   cout << "What letter? ";
   cin  >> letter;

   // display the results
   cout << "The letter '" << letter
        << "' corresponds to "
        << alphabet[letter] << endl;          // retrieve the data with the
                                              //    [] operator.  Note that 
   return 0;                                  //    this is case-sensetive
}
