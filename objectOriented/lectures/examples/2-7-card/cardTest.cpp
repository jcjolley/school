/***********************************************************************
 * This demo program is designed to:
 *      Test card.h and card.cpp: member operator overloading
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

   cout << "Default card: "
        << card1.getSuit() << card1.getRank()
        << endl;

   string sFourHearts("4H");
   Card card2(sFourHearts);
   cout << endl
        << "A card built from " << sFourHearts << ": "
        << card2.getSuit() << card2.getRank()
        << endl;

   // test the comparison operators
   cout << "card1 "
        << (card1 > card2 ? "is" : "is not")
        << " greater than card2\n";
   cout << "card1 "
        << (card1 >= card2 ? "is" : "is not")
        << " greater than or equal to card2\n";
   cout << "card1 "
        << (card1 < card2 ? "is" : "is not")
        << " less than card2\n";
   cout << "card1 "
        << (card1 <= card2 ? "is" : "is not")
        << " less than or equal to card2\n";
   cout << "card1 "
        << (card1 == card2 ? "is" : "is not")
        << " equal-to card2\n";
   cout << "card1 "
        << (card1 != card2 ? "is" : "is not")
        << " not-equal-to card2\n";


   // copy constructor
   Card card3(card2);
   cout << endl
        << "Card 3 copied from card 2: "
        << card3.getSuit() << card3.getRank()
        << endl;

   // test the comparison operators
   cout << "card2 "
        << (card2 > card3 ? "is" : "is not")
        << " greater than card3\n";
   cout << "card2 "
        << (card2 >= card3 ? "is" : "is not")
        << " greater than or equal to card3\n";
   cout << "card2 "
        << (card2 < card3 ? "is" : "is not")
        << " less than card3\n";
   cout << "card2 "
        << (card2 <= card3 ? "is" : "is not")
        << " less than or equal to card2\n";
   cout << "card2 "
        << (card2 == card3 ? "is" : "is not")
        << " equal-to card3\n";
   cout << "card2 "
        << (card2 != card3 ? "is" : "is not")
        << " not-equal-to card2\n";
   
   return 0;
}
