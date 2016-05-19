/***********************************************************************
 * This program is designed to demonstrate:
 *      This program will demonstrate how to define a structure, declare a
 *      variable, reference the member variables, and pass a structure as
 *      a parameter
 ************************************************************************/

#include <iostream>
using namespace std;

/***************************************
 * ADDRESS
 * A standard address such as you would
 * find on an envelope
 **************************************/
struct Address                 // structure tag is TitleCased
{
   string street;              // the street can be long, use the string class
   string city;                // same is true with the city
   char state[3];              // states use a two-letter abbreviation, plus \0
   int zip;                    // the zip is five digit integer
};

// fill the Address structure
void prompt(Address & input);

// display the contents of the address on the screen
void display(const Address & output);

/**********************************************************************
* This will be just a simple driver program 
***********************************************************************/
int main()
{
   Address address;           // declare the variable
   prompt(address);           // since it is pass-by-reference, address changes
   display(address);          // since it is a const, address cannot change
   return 0;
}

/**************************************************
 * PROMPT
 * Prompt the user for an address
 **************************************************/
void prompt(Address & input)              // we are changing the input so it is
{                                         //    pass-by-reference
   cout << "What is your street address? ";
   getline(cin, input.street);            // use the dot operator to access the
   cout << "What is your city? ";         //    member variables here
   getline(cin, input.city);
   cout << "What is your state and zip? ";
   cin  >> input.state >> input.zip;
}

/***************************************************
 * DISPLAY
 * Display the contents of the address
 ***************************************************/
void display(const Address & output)     // we are not changing the output
{                                        //    so the parameter is a const
   cout << output.street << endl         // we access the member variables
        << output.city   << ", "         //    with the dot operator.  Because
        << output.state  << " "          //    the variable is a const, we
        << output.zip << endl;           //    cannot change the values
}
