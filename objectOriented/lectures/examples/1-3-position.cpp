/***********************************************************************
 * This program is designed to demonstrate:
 *      How to define, declare, and pass a structure
 ************************************************************************/

#include <iostream>
using namespace std;

/***********************************
 * POSITION
 * The position on the globe
 **********************************/
struct Position         // corresponds to the structure tag
{
   float latitude;      // corresponds to the member variable latitude
   float longitude;
   int altitude;        // note member variables can be of different data-types
};                      // do not forget the semi-colon!

// display a position
void display(const Position & pos);

// prompt for a position
void prompt(Position & pos);

// prompt with pass-by-pointer
void promptPointer(Position * pPos)

/**********************************************************************
 * This will be just a simple driver program 
 ***********************************************************************/
int main()
{
   // First we will declare a simple Position variable
   Position pos1;

   // Next we will fill it with the prompt function
   prompt(pos1);

   // Now to display the results
   cout << "Origional value of pos1: ";
   display(pos1);

   // We will initialize a position as we declare it this time
   Position pos2 = 
   {                             // use curly braces to surround the values
      43.82937,                  // latitude member variable
      -111.7828,                 // longitude
      4865                       // elevation
   };

   // we can perform a structure-copy with the assignment operator
   pos1 = pos2;

   // display the results to verify
   cout << "New value of pos1: ";
   display(pos1);

   // one final prompt
   promptPointer(&pos1);
   
   return 0;
}

/***********************************************
 * DISPLAY
 * Display a position on the screen.  Note that
 * this is passing a constant struct by reference
 * so we avoid making a copy of the position and
 * we avoid changing the position by accident
 ***********************************************/
void display(const Position & pos)   
{
   cout.setf(ios::fixed | ios::showpoint);
   cout.precision(4);
   cout << "("  << pos.latitude     // reference each member variable with the
        << ", " << pos.longitude    //     dot operator.  Since the variable is
        << ", " << pos.altitude     //     a const, there is no chance of
        << ")";                     //     accidentally changing the value 
}

/**********************************************
 * PROMPT
 * Ask the user for a position.  This is
 * pass-by-reference but is not a const because
 * we intend on changing the member variables
 **********************************************/
void prompt(Position & pos)              
{
   cout << "Please enter the position as latitude longitude altitude: ";
   cin  >> pos.latitude
        >> pos.longitude
        >> pos.altitude;
}

/*******************************************
 * PROMPT POINTER
 * Same as prompt() except we will work with
 * pointers on this one.  Note the use of the
 * arrow operator -> instead of the dot operator .
 *******************************************/
void promptPointer(Position * pPos)
{
   cout << "Please enter the position as latitude longitude altitude: ";
   cin  >> pPos->latitude
        >> pPos->longitude
        >> pPos->altitude;
   
}
