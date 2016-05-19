/***********************************************************************
 * This program is designed to demonstrate:
 *      Demonstrate how to build a class from a structure using
 *      function pointers
 ************************************************************************/

#include <iostream>
using namespace std;


/***********************************************
 * CARD
 * A card class build from a structure
 ***********************************************/
struct Card
{
   // our one member variable, the value between 0 and 51
   int card;

   // set the card data from the iSuit and iRank properties
   void (*set    )(      Card * pThis, int iSuit, int iRank);

   // get the rank (iRank specifically) from the card member variable
   int  (*getRank)(const Card * pThis);

   // get the suit (iSuit) from the card member variable;
   int  (*getSuit)(const Card * pThis);                      
};

/****************************************
 * SET
 * Set the member variable in pThis from
 * iSuit and iRank
 ****************************************/
void set(Card * pThis, int iSuit, int iRank)
{                                           
   pThis->card = iRank + iSuit * 13;
}

/****************************************
 * GET RANK
 * Get the rank component of pThis->card
 ****************************************/
int getRank(const Card * pThis)          
{                                        
   return pThis->card % 13;
}

/*****************************************
 * GET SUIT
 * Get the suit component of pThis->card
 ****************************************/
int getSuit(const Card * pThis)           
{                                         
   return pThis->card / 13;
}


/**********************************************************************
* This will be just a simple driver program 
***********************************************************************/
int main()
{
   // instantiate a card object, but it is not initialized
   Card cardAce;

   // we need to hook up the method function pointers immediately!
   cardAce.set     = set; 
   cardAce.getRank = getRank;
   cardAce.getSuit = getSuit;

   // now we can use the class.
   cardAce.set(&cardAce /*pThis*/, 3 /*iSuit*/, 0 /*iRank*/);

   // display the results
   cout << "The suit is "
        << cardAce.getSuit(&cardAce)
        << " where 0 = Diamonds, 1 = Clubs, 2 = Hearts, 3 = Spades\n";
   cout << "The rank is "
        << cardAce.getRank(&cardAce)
        << " where 0 = Ace\n";      
   
   return 0;
}
