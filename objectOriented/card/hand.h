/***********************************************************************
* Header file:
*    HAND: The data structure necessary to hold a hand of cards
* Summary: 
*    All the data and methods necessary to hold a collection of
*    playing cards (a hand or a deck).
************************************************************************/

#ifndef HAND_H
#define HAND_H

#include "card.h"    // a hand consists of cards
#include <iostream>  // for the insertion and extraction operator overloading
#include <vector>    // a hand is a vector of cards

/**********************************************************************
 * HAND
 * A hand is just a collection of cards
 ***********************************************************************/
class Hand
{
  public:
   // constructors
   Hand() {};
   Hand(bool fill);
   Hand(const std::string sFileName) { read(sFileName.c_str()); };
   Hand(const char *szFileName)      { read(szFileName);        };

   // read a hand from a file
   bool read(const char *szFileName);

   // scramble the cards in a hand.  Useful if the hand is the deck
   void shuffle();

   // display or read the contents of a hand
   friend std::ostream & operator << (std::ostream & out, const Hand &hand);
   friend std::istream & operator >> (std::istream & in,        Hand &hand);

   // look at a given card out of the hand
   const Card & operator[](int iHand) const;

   // size of the hand
   int size() const  { return listCards.size(); };

   // empty a hand
   void clear()   { listCards.clear();  };
   
   // combine two hands
   Hand & operator += (const Hand &rhs);

   // add a card to a hand
   Hand & operator += (const Card &rhs);

   // remove a card from the hand
   Card removeCard(int iHand);
   Card removeTop() { return removeCard(0); };
   
   // compare two hands to see if they are the same
   friend bool operator == (const Hand &lhs, const Hand &rhs); 
   friend bool operator != (const Hand &lhs, const Hand &rhs)
   {
      return !(lhs == rhs);
   }
   // see if a given card is in the hand
   friend bool operator == (const Hand &lhs, const Card &rhs); 
   friend bool operator != (const Hand &lhs, const Card &rhs)
   {
      return !(lhs == rhs);
   }


   
  private:
   std::vector <Card> listCards;
   
};

#endif // HAND_H
