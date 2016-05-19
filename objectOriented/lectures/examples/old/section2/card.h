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
   // various constructors
   Card();                     // default constructor
   Card(std::string s);        // non default constructor - parse string
   Card(int iSuit, int iRank); // non default constructor - order            
   Card(const Card & rhs);     // copy constructor

   // getters and setters
   bool setSuit(char chSuit);
   bool setRank(char chRank);
   char getSuit() const;
   char getRank() const;
   bool isInvalid() const { return value == INVALID; };
   
   // insertion and extraction operators
   friend std::ostream & operator << (std::ostream & out, const Card & card);
   friend std::istream & operator >> (std::istream & in,        Card & card);

   // increment and decrement ... only changing rank
   Card & operator ++ () { return operator += ( 1); };  // prefix
   Card & operator -- () { return operator += (-1); };  // prefix
   Card operator ++ (int postfix);   // postfix
   Card operator -- (int postfix);   // postfix

   // change a card by adding or subtracting one
   Card operator + (const int input) const;
   Card operator - (const int input) const { return operator +  (-input); };
   Card & operator += (const int input);
   Card & operator -= (const int input)    { return operator += (-input); };
   friend Card operator + (int lhs, const Card & rhs);
   
   // assignment
   Card & operator = (const Card & rhs)
   {
      // integer assignment where this is the lhs and the parameter is the rhs
      value = rhs.value;
      return *this;
   }

   // Relative comparison... only comparing rank
   // this is done with non-member methods
   bool operator >= (const Card & rhs) const;
   friend bool operator >  (const Card & lhs, const Card & rhs);
   friend bool operator <= (const Card & lhs, const Card & rhs);
   friend bool operator <  (const Card & lhs, const Card & rhs);

   // Absolute comparision... comparing both rank and suit
   // this is done with member methods
   bool operator == (const Card & rhs) const;
   bool operator != (const Card & rhs) const;

  private:
   // holds the value.  Though there are 256 possible, only 52 are used
   unsigned char value;             // internal representation

   // private functions
   Card(char value);                // private for conversion
   bool parse(std::string s);            // parse input string and assing
   bool validate() const;           // are we in a valid state?
   int  iSuit(char chSuit) const;   // convert 'S' to suit code
   int  iRank(char chRank) const;   // convert 'Q" to rank code

};


#endif // CARD_H
