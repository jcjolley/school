/***********************************************************************
 * This program is designed to demonstrate:
 *      Demonstrate how to build a class from a structure using
 *      function pointers
 ************************************************************************/

#include <iostream>
using namespace std;

// Forward reference because VTableCard needs to refer to Card,
// and Card needs to refer to VTableCard! 
struct Card;

// the three prototypes.  Note that these are exactly the same
// as what we used for 2-1-FunctionPtr.cpp
void set(Card * pThis, int iSuit, int iRank);
int getRank(const Card * pThis);
int getSuit(const Card * pThis);

/**********************************************
 * V TABLE CARD
 * The v-table for the Card class, consisting
 * of all the function pointers Card needs
 **********************************************/
struct VTableCard
{
   void (*set    )(      Card * pThis, int iSuit, int iRank); 
   int  (*getRank)(const Card * pThis);                       
   int  (*getSuit)(const Card * pThis);                       
};

// Create a single global instance of VTableCard which all Cards will use
const VTableCard V_TABLE_CARD =
{
   &set,
   &getRank,
   &getSuit
};

/***********************************************
 * CARD
 * A card class build from a structure
 ***********************************************/
struct Card
{
   // our one member variable, the value between 0 and 51
   int card;

   // all the member functions are under this pointer
   const VTableCard *__vtptr;
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
   cardAce.__vtptr = &V_TABLE_CARD;

   // now we can use the class.
   cardAce.__vtptr->set(&cardAce /*pThis*/, 3 /*iSuit*/, 0 /*iRank*/);

   // display the results
   cout << "The suit is "
        << cardAce.__vtptr->getSuit(&cardAce)
        << " where 0 = Diamonds, 1 = Clubs, 2 = Hearts, 3 = Spades\n";
   cout << "The rank is "
        << cardAce.__vtptr->getRank(&cardAce)
        << " where 0 = Ace\n";      
   
   return 0;
}
