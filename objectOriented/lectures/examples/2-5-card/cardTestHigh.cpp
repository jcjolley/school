/***********************************************************************
 * This demo program is designed to:
 *      Test card.h and card.cpp: Constructors
 ************************************************************************/

#include <iostream>
#include <string>
#include "card.h"
using namespace std;

bool Card :: acesHigh = true;

/**********************************************************************
 * main()...
 ***********************************************************************/
int main()
{
   // what is 0-0?
   Card card00;
   cout << "card00.value == 0  is "
        << card00.getSuit() << card00.getRank()
        << endl;

   // where is the Ace of Diamonds?
   string sAceDiamonds("ad");
   Card cardAceDiamonds(sAceDiamonds);
   cout << "The Ace of Diamonds is at rank: "
        << cardAceDiamonds.iRank('a')
        << endl;
   
   return 0;
}
