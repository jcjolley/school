/***********************************************************************
 * This demo program is designed to:
 *      Test card.h and card.cpp: Constructors
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
   Card card1;

   cout << endl
        << "Default Constructor - Default card: "
        << card1.getSuit() << card1.getRank()
        << endl;

   //non default copy constructor
   string sFourHearts("4H");
   Card card2(sFourHearts);
   cout << endl
        << "Non Default Copy Constructor - A card built from "
        << sFourHearts << ": "
        << card2.getSuit() << card2.getRank()
        << endl;

   // copy constructor
   Card card3(card2);
   cout << endl
        << "Copy Constructor - Card 3 copied from card 2: "
        << card3.getSuit() << card3.getRank()
        << endl << endl;;
   
   return 0;
}
