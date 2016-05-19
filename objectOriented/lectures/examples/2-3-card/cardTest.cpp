/***********************************************************************
 * This demo program is designed to:
 *      Test card.h and card.cpp: Acessors and Mutators
 ************************************************************************/

#include <iostream>
#include <string>
#include "card.h"
using namespace std;

/**********************************************************************
 * main()...
 ***********************************************************************/
int main()
{
   // default constructor
   Card card;

   char suit;
   char rank;

   // setters
   do
   {
      cout << "Enter a suit: ";
      cin  >> suit;
   }
   // Check to see if the input is valid.
   // If so, assign it. If not, reprompt.
   while (!card.setSuit(suit));

   // do the same thing as above, but for the rank instead.
   do
   {
      cout << "Enter a rank: ";
      cin  >> rank;
   }
   while (!card.setRank(rank));
   
   // getters
   cout << "Get Suit: "
        << card.getSuit()
        << endl;

   cout << "Get Rank: "
        << card.getRank()
        << endl;

   // setters

   
   
   return 0;
}
