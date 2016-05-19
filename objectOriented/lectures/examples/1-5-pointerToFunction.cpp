/***********************************************************************
 * This program is designed to demonstrate:
 *      demonstrate how to create and use a pointer to a function
 ************************************************************************/

#include <iostream>
using namespace std;

/****************************************
 * DISPLAY GPA
 * Display a number in the format:
 *    3.9
 ***************************************/
void displayGPA(float gpa)
{
   cout.setf(ios::fixed | ios::showpoint);
   cout.precision(1);
   cout << gpa;
}

/****************************************
 * DISPLAY MONEY
 * Display a number in the format:
 *    $3.91
 ***************************************/
void displayMoney(float money)
{
   cout.setf(ios::fixed | ios::showpoint);
   cout.precision(2);
   cout << "$" << money;
}

/****************************************
 * DISPLAY
 * Display the user information according to
 * the passed display function
 ****************************************/
void display(void (*pDisplay)(float), float value)
{
   cout << "The answer is: ";
   pDisplay(value);
   cout << endl;
}

/**********************************************************************
 * MAIN
 * This will exercise our display functions with a simple menu structure
 ***********************************************************************/
int main()
{
   // prompt for the value
   float value;
   cout << "What is the amount? ";
   cin  >> value;

   // prompt for the type of value it is
   char input;
   cout << "Is this money (y/n)";
   cin  >> input;

   // choose the appropriate display function
   void (*pDisplay)(float);
   if (input == 'Y' || input == 'y')
      pDisplay = displayMoney;
   else
      pDisplay = displayGPA;

   // call the generic display function
   display(pDisplay, value);
   return 0;
}
