/***********************************************************************
* Program:
*    Test the Card class
************************************************************************/

#include <iostream>
#include <cassert>
#include "card.h"
using namespace std;


/**********************************************************************
* Just a simple driver program
***********************************************************************/
int main()
{
   // card 1
   AcesLow card1;
   cout << "Enter card 1: ";
   cin  >> card1;

   // card 21
   AcesLow card2;
   cout << "Enter card 2: ";
   cin  >> card2;

   // relative comparisions
   if (card1 > card2)
      cout << card1 << " > " << card2 << endl;
   if (card1 < card2)
      cout << card1 << " < " << card2 << endl;
   if (card1 >= card2)
      cout << card1 << " >= " << card2 << endl;
   if (card1 <= card2)
      cout << card1 << " <= " << card2 << endl;

   // absolute comparisions
   if (card1 == card2)
      cout << card1 << " == " << card2 << endl;
   if (card1 != card2)
      cout << card1 << " != " << card2 << endl;

   // assignment
   AcesLow card3 = card1;
   assert(card3 == card1);
   assert(!(card3 != card1));

   // relative
   cout << "The card after " << card1 << " is "
        << (AcesLow)(card1 + 1) << endl;
   cout << "The card before " << card2 << " is "
        << (AcesLow)(card2 - 1) << endl;
   card3 = card1;
   assert(++card3 == card1 + 1);
   assert(card3 + 1 == 1 + card3);
   card3 = card1;
   assert(--card3 == card1 - 1);
   
   return 0;
}

