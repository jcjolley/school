/***********************************************************************
* Header File
*    This is the header file for a playing card.
* Summary: 
*    The playing card stores the type of card (queen of hearts, for example)
*    and knows the relationship between the cards.
************************************************************************/

#ifndef CARD_H
#define CARD_H

#include <string>   // because many of the functions take or return strings
#include <iostream> // because of the insertion and extraction operator


/*****************************************
 * RANK: The ordering of the cards
 ****************************************/
#define FIRST_RANK 0
#define LAST_RANK  12
const char RANKS[] = "234567890jqka";

/***************************************
 * SUIT: The ordering of the ranks
 ***************************************/
#define FIRST_SUIT 0
#define LAST_SUIT  3
const char SUITS[] = "shcd";

// the current card is invalid
#define INVALID 255
#define NO_CARD "--"

/*****************************************
 * CARD
 * Card class
 *****************************************/
class Card
{
  public:
   // initialize
   void initialize()   { value = 0; };
   
   // getters and setters
   bool setSuit(char chSuit);
   bool setRank(char chRank);
   char getSuit() const;
   char getRank() const;
   bool isInvalid() const { return value == INVALID; };

   void display();             // just like << from lesson26
   
  private:
   // holds the value.  Though there are 256 possible, only 52 are used
   unsigned char value;                //internal representation

   // private functions
   bool validate() const;              // are we in a valid state?
   int  iSuit(char chSuit) const;      // convert 'S' to suit code
   int  iRank(char chRank) const;      // convert 'Q" to rank code
};

#endif // CARD_H