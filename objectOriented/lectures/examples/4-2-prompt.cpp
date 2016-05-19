/***********************************************************************
 * This program is designed to:
*    Demonstrate how to write a generic prompt function 
*    using function templates
************************************************************************/

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

/**************************************************************
 * PROMPT: A generic prompt function
 * INPUT:
 *   sPrompt   = the prompt string to show the user
 *   sReprompt = the error message to display the user if validation failed
 *************************************************************/
template <class T>
void prompt(T & t, const char * sPrompt, const char * sReprompt = NULL)
{
   bool done = false;
   assert(sPrompt != NULL);                // the prompt is not optional

   do
   {
      // instructions
      cout << sPrompt << ": ";
      cin  >> t;                           // T needs to support the insertion

      if (cin.fail())                             
      {
         if (sReprompt != NULL)            // the reprompt is optional
            cout << sReprompt << endl;
         cin.clear();                             
         cin.ignore(256, '\n');                   
      }
      else                                        
         done = true;
   }
   while (!done);
}


/**********************************************************************
 * MAIN: Simple driver program for prompt()
 ***********************************************************************/
int main()
{
   // first with strings
   string text;
   prompt(text, "Please enter text");
   cout << "The text you entered is: " << text << endl;

   // second with double
   double number;
   prompt(number, "Please enter a number", "Invalid character");
   cout << "The number you entered is: " << number << endl;
   
   return 0;
}
