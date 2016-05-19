/***********************************************************************
* Program:
*    Lecture 3.b, Addressing schemes
*    Brother Helfrich, CS470
* Author:
*    Br. Helfrich
* Summary: 
*    This program is designed to determine how many different ways we
*    can access template.cpp.  
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/**************************************************************
 * GET FILE
 * This function takes a filename (and path?) as input and displays
 * the first line of the file on the screen.
 *************************************************************/
void getFile(char *input)
{
   string tmp;

   ifstream fin(input);
   if (!fin.fail())
   {
      fin  >> tmp;
      cout << tmp << endl;
      fin.close();
   }
   else
      cout << "Unable to open file " << input << endl;

   return;
}


/***************************************************************
 * MAIN
 * Keep ask ing the user for the file until he presses q
 ***************************************************************/
int main()
{
   char file[256];

   // instructions
   cout << "This program is designed to test how many ways you can\n"
        << "access template.cpp.  It will keep prompting you for a\n"
        << "filename until you type 'q'\n\n";

   // prompt
   cout << "> ";
   cin  >> file;

   // loop until the user types 'q'
   while (!(file[0] == 'q' && file[1] == '\0'))
   {
      getFile(file);
      cout << "> ";
      cin  >> file;
   }

   // make like a tree
   return 0;
}
