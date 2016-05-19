/***********************************************************************
 * This program is designed to:
*    Demonstrate how to write a generic prompt function taking
*    both the prompt string(s) and the validation callback as parameters
************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

float prompt(const char * sPrompt = "Enter a value", // prompt string
             bool (*pValidate)(float) = NULL,        // validation callback
             const char * sReprompt = NULL);         // reprompt string

/***********************************************
 * VALIDATE GPA: simple validate function
 ***********************************************/
bool validateGPA(float value)
{
   return (value >= 0.0 && value <= 4.0);
}

/**********************************************************************
 * MAIN: Simple driver program for prompt();
 ***********************************************************************/
int main()
{
   float value;
   
   // first pass all three parameters
   cout << "\nPrompt with three parameters\n";
   value = prompt("Enter a GPA", &validateGPA, "Invalid GPA, try again");
   cout << "The value is: " << value << endl;

   // next pass two parameters
   cout << "\nPrompt with two parameters\n";
   value = prompt("Enter a GPA", &validateGPA);
   cout << "The value is: " << value << endl;

   // next pass one parameter
   cout << "\nPrompt with one parameter\n";
   value = prompt("Enter a GPA");
   cout << "The value is: " << value << endl;

   // next pass zero paramters
   cout << "\nPrompt with zero parameters\n";
   value = prompt();
   cout << "The value is: " << value << endl;
   
   return 0;
}


/**************************************************************
 * PROMPT: A generic prompt function
 * INPUT:
 *   sPrompt   = the prompt string to show the user
 *   pValidate = the validation function
 *   sReprompt = the error message to display the user if validation failed
 *************************************************************/
float prompt(const char * sPrompt,
             bool (*pValidate)(float),
             const char * sReprompt)
{
   bool done = false;
   float value;
   assert(NULL != sPrompt);
   
   do
   {
      // we should be all clear at this point
      assert(cin.good());

      // instructions
      cout << sPrompt << ": ";
      cin >> value;
      
      // check for a value that is not an integer
      if (cin.fail())
      {
         if (sReprompt != NULL)
            cout << sReprompt << endl;
         cin.clear();           // clear the error state
         assert(cin.good());    // we better have successfully cleared the bit
         cin.ignore(256, '\n'); // ignore all the characters in the buffer
      }

      // check we are within range
      else if (NULL != pValidate && !pValidate(value))
      {
         assert(cin.good());
         if (sReprompt != NULL)
            cout << sReprompt << endl;
      }
      // otherwise, we are good!
      else
         done = true;
   }
   while (!done);

   // ensure we are good before we even think of leaving
   assert(cin.good());
   assert(NULL == pValidate || pValidate(value));
   return value;
}
