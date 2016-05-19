/***********************************************************************
 * This program is designed to:
*    Accept an index from the user and work regardless of
*    the type of input the user may type.
************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

int getIndex(int min, int max);

/**********************************************************************
 * MAIN: Simple driver program for getIndex();
 ***********************************************************************/
int main()
{
   int index = getIndex(1 /*min*/, 10 /*max*/);

   cout << "The user's index is: " << index << endl;
   
   return 0;
}


/**************************************************************
 * GET INDEX: Prompt the user for an index between a certain range
 *   INPUT  min: minimum value in the acceptable range
 *          max: maximum value in the acceptable range
 *   OUTPUT index: returned value guarenteed to be in the range
 *************************************************************/
int getIndex(int min, int max)
{
   // before we do anything, validate the input.
   assert(min <= max);

   bool done = false;
   int index = min - 1;  // some invalid state.

   // instructions
   cout << "Please enter the index.  The acceptable range is "
        << min << " <= index <= " << max << ".\n";

   do
   {
      // we should be all clear at this point
      assert(cin.good());
      cout << "> ";
      cin  >> index;

      // check for a value that is not an integer
      if (cin.fail())
      {
         cout << "ERROR: non-digit entered\n";
         cin.clear();           // clear the error state
         assert(cin.good());    // we better have successfully cleared the bit
         cin.ignore(256, '\n'); // ignore all the characters in the buffer
      }

      // check we are within range
      else if (index < min || index > max)
      {
         assert(cin.good());
         cout << "ERROR: value is outside the accepted range\n";
      }
      // otherwise, we are good!
      else
         done = true;
   }
   while (!done);

   // ensure we are good before we even think of leaving
   assert(cin.good());
   assert(index >= min && index <= max);
   return index;
}
