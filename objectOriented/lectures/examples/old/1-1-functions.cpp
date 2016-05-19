/***********************************************************************
 * This demo program is designed to:
 *  Demonstrate parameter passing and function calling.
 ************************************************************************/

#include <iostream>
using namespace std;

// pass-by-value.  A copy of the parameter is made
void passByValue(int value);

// pass-by-reference.  The parameter is shared between the caller and callee
void passByReference(int & reference);

// return value.  Data is sent back to the caller through the return mechanism
int  returnValue();

// void function.  No data is sent into our out of the function
void voidFunction();

// overloading.  Two functions with different parameters
void overloading(int value);
void overloading(const char * value);

// default parameters.  One function with many different parameters
void defaultParam(int one, int two = 2, int three = 3);

// inline functions. Works the same but does not involve a function call
inline int inlineFunction()
{
   return 42;
}

/**********************************************************************
 * main()...
 ***********************************************************************/
int main()
{
   // Get a dummy value to work with
   int userValue;
   cout << "Please enter an integer value: ";
   cin  >> userValue;
   cout << endl;

   // Pass-by-value will not change the user's value
   passByValue(userValue);
   cout << "Pass-by-value:\n"
        << "\tpassByValue(userValue);\n"
        << "\tuserValue == " << userValue << endl
        << "\tbecause only a copy was changed\n";

   // Pass-by-reference will change it.
   passByReference(userValue);
   cout << "Pass-by-reference:\n"
        << "\tpassByReference(userValue);\n"
        << "\tuserValue == " << userValue << endl
        << "\tbecause both the caller and callee share the variable\n\n";

   // This function will do nothing because we are not saving the return value
   returnValue();
   cout << "Return value:\n"
        << "\treturnValue()\n"
        << "\tuserValue == " << userValue << endl
        << "\tbecause the return value was never checked\n";

   // Now we will change the value due to the assignment
   userValue = returnValue();
   cout << "Return value:\n"
        << "\tuserValue = returnValue();\n"
        << "\tuserValue == " << userValue << endl
        << "\tbecause of the assignment in main()\n\n";

   // Call the integer version of the overloading function:
   cout << "Overloading:\n"
        << "\toverloading(7);\n";
   overloading(7);
   // call the floating point version of the overloading function
   cout << "Overloading:\n"
        << "\toverloading(\"seven\");\n";
   overloading("seven");
   cout << endl;

   // call the defaultParam function with different numbers of parameters
   cout << "Default Param:\n"
        << "\tdefaultParam(userValue);\n";
   defaultParam(userValue);
   cout << "Default Param:\n"
        << "\tdefaultParam(userValue, 0);\n";
   defaultParam(userValue, 0);
   cout << "Default Param:\n"
        << "\tdefaultParam(userValue, 0, 0);\n";
   defaultParam(userValue, 0, 0);
   cout << endl;

   // call the inline function
   userValue = inlineFunction();
   cout << "Inline:\n"
        << "\tuserValue = inlineFunction();\n"
        << "\tuserValue == " << userValue << endl
        << "\tbecause it works like any other function\n\n";

   // Finally, our lonely void function
   voidFunction();

   return 0;
}

/************************************************
 * PASS BY VALUE
 * Pass-by-value cannot influence the caller because
 * a copy of the parameter is made.  Any change made to
 * value here will not influence the caller
 ************************************************/
void passByValue(int value)
{
   value = 0;
}

/************************************************
 * PASS BY REFERENCE
 * In this case, main:userValue and passByReference:reference
 * are the same variable, just with different names.  Thus
 * all changes made to reference will also influence value
 ************************************************/
void passByReference(int & reference)
{
   reference = 0;
}

/*************************************************
 * RETURN VALUE
 * Here, the only purpose of this function is to send
 * a value to the caller.  It is up to the caller to
 * actually do something with it.
 *************************************************/
int returnValue()
{
   return -1;
}

/**************************************************
 * VOID FUNCTION
 * No data is entering this function from main() because
 * the parameter list is empty.  No data is leaving this
 * function to main() because there are no pass-by-reference
 * parameters and no return value
 **************************************************/
void voidFunction()
{
   cout << "Program is finished\n";
}

/***********************************************
 * OVERLOADING : INTEGER
 * This version of the function takes an integer
 * as a parameter
 **********************************************/
void overloading(int value)
{
   cout << "\tThe integer version of the overloading() function\n";
}

/***********************************************
 * OVERLOADING : TEXT
 * This version of the function takes text
 * as a parameter
 **********************************************/
void overloading(const char * value)
{
   cout << "\tThe text version of the overloading() function\n";
}

/************************************************
 * DEFAULT PARAM
 * This function can be called with one, two, or three
 * parameters.
 ***********************************************/
void defaultParam(int one, int two, int three)
{
   cout << "\tdefaultParam(" << one << ", " << two << ", " << three << ")\n";
}
