/***********************************************************************
 * This demo program is designed to:
 *      Demonstrate how to throw and catch exceptions
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

void exceptionalFunction() throw (int, float, string, char);

/**********************************************************************
 * main()...
 ***********************************************************************/
int main()
{
   try
   {
      exceptionalFunction();
      cout << "No exception was thrown\n";
   }
   catch (int integer)
   {
      cout << "An integer was thrown!\n";
   }
   catch (float floatingPoint)
   {
      cout << "A floating point number was thrown!\n";
   }
   catch (string text)
   {
      cout << "Text was thrown!\n";
   }
   catch (...)
   {
      cout << "Error! Unexpected exception was thrown!\n";
   }
   
   return 0;
}

/********************************
 * PROMPT
 * Ask the user how exceptional he feels today
 *******************************/
int prompt()
{
   cout << "Which type of exception would you like to throw?\n";
   cout << "\t1. Integer\n";
   cout << "\t2. Float\n";
   cout << "\t3. String\n";
   cout << "\t4. Nothing at all, thank you!\n";

   int input;
   cin >> input;
   return input;
}
   
/********************************
 * EXCEPTIONAL FUNCTION
 * This function will throw whichever
 * exception the user chooses
 *******************************/
void exceptionalFunction() throw (int, float, string, char)
{
   switch (prompt())
   {
      case 1:
         throw 0;
      case 2:
         throw float(0.0);
      case 3:
         throw string("zero");
      case 4:
         break;
      default:
         throw '0';
   }
   cout << "End of the exceptional function\n";
}
