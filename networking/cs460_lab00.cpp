/***********************************************************************
* Program:
*    Lab 00, Practice Lab Submission
*    Brother Jones, CS460
* Author:
*    Joshua Jolley
* Summary: 
*    Counts the number of strings starting with upper case letters 
************************************************************************/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/**********************************************************************
 * Counts the number of strings with upper case letters. 
 ***********************************************************************/
int main(int argc, char** argv)
{

   string str = "";
   int count = 0;

   cout << "Enter a string: ";


   while (getline(cin, str))
   {
      if (str.empty())
      {
         break;
      }

      if (isupper(str[0]))
      {
         count++;
      }
      cout << "Enter a string: ";
   }
   
   if (count == 0)
   {
      cout << "No strings starting with an upper"
           << " case letter were seen." << endl;
      return 0;
   }

   if (count == 1)
   {
      cout << "One string starting with an upper"
           << " case letter was seen." << endl;
   } 
   else 
   {
      cout << "You entered " << count << " strings"
           << " that started with an upper case letter." << endl;
   }

   return 0;
}

