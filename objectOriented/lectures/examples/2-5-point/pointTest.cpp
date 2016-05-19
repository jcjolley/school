/***********************************************************************
 * This program is designed to demonstrate:
 *      How to write a driver program for a given class
 ************************************************************************/

#include <iostream>    // for COUT and CIN
#include "point.h"     // to get the POINT class which we will be testing
using namespace std;

// initialize the static member variables
float Point::xMin = -10.0;
float Point::yMin = -10.0;
float Point::xMax =  10.0;
float Point::yMax =  10.0;

/**********************************************************************
* This will be just a simple driver program to exericse Point
***********************************************************************/
int main()
{
   // create a legal point at zero, zero
   Point pt1;                                   // bounds set to (-10, -10) 
   cout << "Initial value: ";                   //     to (10,10) 
   pt1.display();
   cout << endl;

   // move it to an illegal point
   pt1.setX(-20.0);                             // outside the xMin bounds
   cout << "After setting to (-20.0, 0.0), "
        << (pt1.isDead() ? "invalid" : "valid")
        << endl;

   // create another point that is also invalid
   Point pt2(0, 20.0);                          // also sharing the same bounds
   cout << "Second point at (0.0, 20.0) is "    //    as pt1, so this is
        << (pt2.isDead() ? "invalid" : "valid") //    also invalid
        << endl;
   
   return 0;
}
