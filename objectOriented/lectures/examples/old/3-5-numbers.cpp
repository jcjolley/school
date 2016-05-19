/***********************************************************************
 * This demo program is designed to:
 *      Demonstrate pure Virtual Functions.  Note that we cannot
 *      create an object out of an abstract class so we will
 *      get a compile error
 ************************************************************************/

#include <iostream>
using namespace std;

/****************************************************
 * VALID NUMBER
 * Abstract class designed to contain the notion of a number
 * guarenteed to be within a certain range
 ****************************************************/
class ValidNumber
{
public:
   ValidNumber() : value(0.0)         {               }
   float get()                        { return value; }
   void prompt(const char * sMessage);
   virtual void display() = 0;
private:
   virtual bool validate(float ) = 0;
   float value;
};

/***********************************************
 * GPA
 * Derrived class specific for GPA
 **********************************************/
class GPA : public ValidNumber
{
public:
   virtual void display();
private:
   virtual bool validate(float value);
};

/***********************************************
 * Price
 * Derrived class specific for Prices
 **********************************************/
class Price : public ValidNumber
{
public:
   virtual void display();
private:
   virtual bool validate(float value);
};



/***************************************
 * TEST. Test the abstract base class
 *    INPUT:  num:       A valid number to be tested
 *            sMessage:  The prompt message
 ***************************************/
void test(ValidNumber & num, const char * sMessage)
{
   num.prompt(sMessage);
   num.display();
}

/**********************************************************************
 * MAIN.  This function, coupled with TEST, will constitute the driver
 *        program for our ValidNumber family of classes.
 ***********************************************************************/
int main()
{
   GPA   gpa;
   Price price;

   test(gpa,   "Enter a GPA where 0.0 <= gpa <= 4.0");
   test(price, "Enter a non-negative price");

   return 0;
}


/*****************************************************
 * VALID NUMBER : PROMPT:  Keep prompting the user for
 *           a number until a valid one is reached
 ****************************************************/
void ValidNumber::prompt(const char * sMessage)
{
   // display prompt
   cout << sMessage << ": ";

   // fetch the value on faith
   float userInput;
   cin >> userInput;

   // keep prompting until we get valid input
   while (!validate(userInput))
   {
      cout << "Value out of range, try again: ";
      cin  >> userInput;
   }

   // only then assign
   value = userInput;
}


/*************************************************
 * GPA : DISPLAY:  Display a GPA on the screen
 *************************************************/
void GPA::display()
{
   cout.setf(ios::fixed);
   cout.precision(1);
   cout << get() << endl;
}

/**************************************************
 * GPA : VALIDATE:  Ensure the GPA is in the range
 *   INPUT : value:    The value to validate
 *   OUTPUT: <return>  True for within range, false for not
 *************************************************/
bool GPA::validate(float checkValue)
{
   return checkValue >= 0 && checkValue <= 4.0;
}


/*************************************************
 * Price : DISPLAY:  Display a GPA on the screen
 *************************************************/
void Price::display()
{
   cout.setf(ios::fixed);
   cout.precision(2);
   cout << "$" << get() << endl;
}

/**************************************************
 * Price : VALIDATE:  Ensure the Price is in the range
 *   INPUT : value:    The value to validate
 *   OUTPUT: <return>  True for within range, false for not
 *************************************************/
bool Price::validate(float checkValue)
{
   return checkValue >= 0;
}

