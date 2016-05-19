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

   Card card;
   card.initialize();

   char chSuit;
   char chRank;

   cout << "Instructions: keep prompting the user for a suit and rank\n"
        << "              until the suit is specified as 0.\n";

   bool done = false;
   do
   {
      //prompt for suit
      cout << "Suit: ";
      cin  >> chSuit;

      if (chSuit == '0')
         done = true;
      else
      {
         // prompt for rank
         cout << "Rank: ";
         cin  >> chRank;

         // set and display

         card.setCard(card.iSuit(chSuit), card.iRank(chRank));
         cout << endl;
         card.display();
         cout << endl;
      }
   }
   while (!done);

   return 0;
}
