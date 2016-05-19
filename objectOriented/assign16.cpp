/***********************************************************************
* Program:
*    Assignment 16, Exception Handling
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
* Summary: 
*    This program is designed to illustrate the types of information that
*    we can send through the exception handling mechanism.
*
*    Estimated:  0.3 hrs   
*    Actual:     0.3 hrs
*      Pretty straightforward.  The hardest part was remembering to make
*    a variable of type "Missing" to throw  
************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef bool Missing;

string readData(const string &fileName) throw (string, Missing, int);

/**********************************************************************
 * MAIN: This function will prompt the user for the file and display the
 *       contents on the screen.
 * IMPORTANT: you are not allowed to change any part of main
 ***********************************************************************/
int main()
{
   try
   {
      // get the filename
      string fileName;
      cout << "What is the filename? ";
      getline(cin, fileName);

      // Read the data.  Note that your function should have the
      // appropriate throw list for the 3 data types thrown.
      string data = readData(fileName);

      // display the results:
      cout << "The important fact: \""
           << data
           << "\"\n";
   }
   catch (string s)
   {
      cout << "ERROR: Invalid filename \""
           << s
           << "\"\n";
      return 1;
   }
   catch (Missing)
   {
      cout << "ERROR: No filename specified\n";
      return 1;
   }
   catch (int code)
   {
      switch (code)
      {
         case 0:
            cout << "ERROR: The file was empty\n";
            return 1;
         case 1:
            cout << "ERROR: The message exceeded 140 characters\n";
            return 1;
         case 2:
            cout << "ERROR: The message was longer than 1 line\n";
            return 1;
         default:
            cout << "ERROR: Unexpected error code " << code << endl;
            return 1;
      }
   }
   
   return 0;
}

/**********************************************************************
 * readData
 * Reads a file, throws errors if it doesn't match the criteria, and
 * returns the data in a string
 **********************************************************************/
string readData(const string &fileName) throw (string, Missing, int)
{
   int error = 0;
   int numLines = 0;
   string temp;
   if (fileName.length() == 0)
   {
      Missing filename = true;
      throw filename;
   }
   ifstream fin(fileName.c_str());
   if (fin.fail())
      throw fileName;
   while (getline(fin, temp))
      numLines++;

   if (temp.length() == 0)
      throw error;
   if (temp.length() > 140)
   {
      error = 1;
      throw error;
   }
   if (numLines > 1)
   {
      error = 2;
      throw error;
   }
   return temp;
}
