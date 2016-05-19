/***********************************************************************
 * This demo program is designed to:
 *      Demonstrate pointers to functions
 ************************************************************************/

#include <iostream>
using namespace std;

/*****************************************************
 * DISPLAY MONEY
 * Display a decimal value as currency
 *****************************************************/
void displayMoney(double value)
{
   // format for money
   cout.setf(ios::fixed | ios::showpoint);
   int precisionOld = cout.precision(2);

   // display the currency
   cout << "$" << value;

   // reset to how it used to be
   cout.unsetf(ios::fixed | ios::showpoint);
   cout.precision(precisionOld);
}

/*****************************************************
 * DISPLAY DEFAULT
 * Display a decimal value in the default way
 *****************************************************/
void displayDefault(double value)
{
   cout << value;
}

/**************************************************
 * DISPLAY INTEGRAL
 * Display a decimal value as an integer
 *************************************************/
void displayIntegral(double value)
{
   // non-scientific
   cout.setf(ios::fixed);
   int precisionOld = cout.precision(0);

   // display the value
   cout << value;

   // reset to how it used to be
   cout.unsetf(ios::fixed);
   cout.precision(precisionOld);
}

/*******************************************
 * DISPLAY
 * A generic display function taking a pointer to a
 * function as a parameter
 ******************************************/
void display(void (*p)(double), double value)
{
   cout << "The value is ";
   p(value);
   cout << endl;
}

/**********************************************************************
 * main()...
 ***********************************************************************/
int main()
{
   // first, we will display the addresses of the various functions
   cout << "The address of... \n";
   cout << "\tdisplayMoney():    " << (void *)(displayMoney)    << endl;
   cout << "\tdisplayDefault():  " << (void *)(&displayDefault) << endl;
   cout << "\tdisplayIntegral(): " << (void *)(displayIntegral) << endl;

   // next, we will create a pointer to a function. Recall that a pointer
   // to a function must include the complete function signature
   void (*p)(double);

   double value;
   cout << "Please enter a value: ";
   cin  >> value;
   
   // for this example, I will let the user select which function we will
   // make p point to
   int selection;
   cout << "Please select how you would like to display your value:\n"
        << "\t1. As money\n"
        << "\t2. Using the default mechanism\n"
        << "\t3. As an integer\n";
   cout << "> ";
   cin  >> selection;
   switch (selection)
   {
      default:
         cout << "Unexpected input.  Treating it as an integer\n";
         // fall through
      case 3:
         p = displayIntegral;
         break;
      case 2:
         p = displayDefault;
         break;
      case 1:
         p = displayMoney;
   };

   // call the appropriate function directly ...
   p(value);
   cout << endl;

   // ... or call our fancy display function
   display(p, value);
   return 0;
}
