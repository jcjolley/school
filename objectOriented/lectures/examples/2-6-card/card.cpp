/***********************************************************************
* Source File:
*    Implementation of the Card class.
* Summary: 
*    This file will implement all the methods described in card.h
************************************************************************/

#include <iostream>
#include <string>
#include <cassert>
#include "card.h"
using namespace std;

/*************************************************************
 *************************************************************
 ************* NON-MEMBER OPERATOR OVERLOADING ***************
 *************************************************************
 *************************************************************/

/*****************************
 * Insertion  cout << x;
 * RETURN:    ostream by reference   (so we can say (cout << x) << y;)
 * PARAMETER: ostream by reference   (we do not want a copy of cout)
 *            constant by reference  (we do not want to make a copy or change)
 *****************************/
ostream & operator << (ostream & out, const Card & rhs)
{
   if (rhs.isInvalid())
      out << NO_CARD;
   else
      out << rhs.getSuit() << rhs.getRank();

   // return the output stream
   return out;
}

/*****************************
 * Extraction    cin >> x;
 * RETURN:    istream by reference  (so we can say (cin >> x) >> y;)
 * PARAMETER: istream by reference  (we do not want a copy of cin)
 *            by reference          (no copies but we do want to change this) 
 *****************************/
istream & operator >> (istream & in, Card & rhs)
{
   // input comes in the form of a string
   string input;
   in >> input;

   // do the actual work
   rhs.parse(input);
   assert(rhs.validate());

   // return the input stream
   return in;
}

/*********************************
 * Equivelence
 * RETURN:    Bool                  (either equal or not)
 * PARAMETER: constant by reference (do not make a copy)
 ********************************/
bool operator == (const Card & lhs, const Card & rhs)
{
   // only same if both suit and rank are the same
   return lhs.getValue() == rhs.getValue();
}

/*********************************
 * Difference
 * RETURN:    Bool                  (either equal or not)
 * PARAMETER: constant by reference (do not make a copy)
 ********************************/
bool operator != (const Card & lhs, const Card & rhs)
{
   // should be inline
   return !(lhs == rhs);
}

/*********************************
 * Greater than or equal to
 * RETURN:    Bool
 * PARAMETER: constant by reference (do not make a copy)
 ********************************/
bool operator >= (const Card & lhs, const Card & rhs)
{
   // we are only comparing the ranks, not the suit for playing cards
   unsigned char iLHS = lhs.getValue() % 13;
   unsigned char iRHS = rhs.getValue() % 13;

   return iLHS >= iRHS;
}

/*********************************
 * Greater than 
 * RETURN:    Bool
 * PARAMETER: constant by reference (do not make a copy)
 ********************************/
bool operator > (const Card & lhs, const Card & rhs)
{
   // again, only comparing the ranks
   unsigned char iLHS = lhs.getValue() % 13;
   unsigned char iRHS = rhs.getValue() % 13;

   return iLHS > iRHS;
}

/*********************************
 * Less than or equal to
 * RETURN:    Bool
 * PARAMETER: constant by reference (do not make a copy)
 *
 * In most cases, we can simply say:
 *     return !(lhs > rhs);
 ********************************/
bool operator <= (const Card & lhs, const Card & rhs)
{
   unsigned char iLHS = lhs.getValue() % 13;
   unsigned char iRHS = rhs.getValue() % 13;

   return iLHS <= iRHS;
}

/*********************************
 * Less than 
 * RETURN:    Bool
 * PARAMETER: constant by reference (do not make a copy)
 *
 * In most cases, we can simply say:
 *     return !(lhs >= rhs);
 ********************************/
bool operator < (const Card & lhs, const Card & rhs)
{
   unsigned char iLHS = lhs.getValue() % 13;
   unsigned char iRHS = rhs.getValue() % 13;

   return iLHS < iRHS;
}

/***************************
 * Plus Equals
 * RETURN:    Self by reference    (so we can say (x += 1) += 3;)
 * PARAMETER: Self by reference
 *            Whatever makes sense (card += 2 make sense, not card1 += card2;)
 **************************/
Card & operator += (Card & lhs, const int input)
{
   int iSuit = lhs.getValue() / 13;
   int iRank = lhs.getValue() % 13 + input;
   if (iRank > LAST_RANK)
      iRank = LAST_RANK;
   if (iRank < FIRST_RANK)
      iRank = FIRST_RANK;

   lhs.setValue((iSuit * 13) + iRank);

   // return the left hand side
   return lhs;
}

/*****************************
 * Minus Equals
 * RETURN:    Self by reference    (so we can say (x -= 1) -= 3;)
 * PARAMETER: Self by reference
 *            Whatever makes sense (card += 2 make sense, not card1 -= card2;)
 *****************************/
Card & operator -= (Card & lhs, const int input)
{
   // This should be inline.  Just call +=
   return lhs += -input;
}

/***************************
 * Increment: prefix (++x)
 * RETURN:    Self by reference  (so we can say ++(++x) )
 * PARAMETER: By reference       (we will change the lhs)
 **************************/
Card & operator ++ (Card & rhs)
{
   // call the += opeator, this should be inline
   return rhs += 1;
}

/***************************
 * Increment: postfix (x++)
 * RETURN:    Self by value      (we are returning the old copy of this)
 * PARAMETER: By reference       (we will change the lhs)
 *            integer            (this parameter is ignored)
 *
 * The difference between ++x and a++ is that the prefix notation (++x)
 * is changing a before the expression is evaluated and the postfix
 * notation (x++) is changed after.  This means:
 *     int x = 5;
 *     cout << ++x << endl;      // display 6
 * Wherease
 *     int x = 5;
 *     cout << x++ << endl;      // display 5
 * Therefore, postfix increment (x++) must return the value of this before
 * the change was made. This means we need to make a copy
 **************************/
Card operator ++ (Card & lhs, int postfix)
{
   // remember the old value of the left hand side so we can return it
   unsigned char valueOld = lhs.getValue();

   // actually increment using the += operator
   lhs += 1;

   // create a copy of the old version
   return Card (valueOld);
}

/**************************
 * Decrement: prefix (--x)
 * RETURN:    Self by reference    (so we can say --(--x) )
 * PARAMETER  By reference         (we will change the lhs)
 **************************/
Card & operator -- (Card & rhs)
{
   // should be inline
   return rhs -= 1;
}

/***************************
 * Decrement: postfix  (x--)
 * RETURN:    Self by value       (we are returning the old copy of this)
 * PARAMETER: By reference        (we will change the lhs)
 *            integer             (this parameter is ignored)
 *
 * Again we need to return a copy of the old value.
 **************************/
Card operator -- (Card & lhs, int postfix)
{
   // remember the old value of the left hand side so we can return it
   unsigned char valueOld = lhs.getValue();

   // actually increment using the += operator
   lhs -= 1;

   // create a copy of the old version
   return Card (valueOld);
}

/*************************
 * Addition
 * RETURN:    Self by value         (we are creating a new card to return)
 * PARAMETER: Const by reference    (we do not want to change the lhs)
 *            Whatever makes sense  (usually the same parameter as +=
 *
 * From the following:
 *     cout << x + y << endl;
 * We do not expect x or y to change.  Therefore, both are const
 *************************/
Card operator + (const Card & lhs, const int input)
{
   // suit does not change
   int iSuit = lhs.getValue() / 13;

   // add input to the rank.  Change to make sure we are still valid   
   int iRank = lhs.getValue() % 13 + input;
   if (iRank > LAST_RANK)
      iRank = LAST_RANK;
   if (iRank < FIRST_RANK)
      iRank = FIRST_RANK;

   // create a new card to return with the new value
   return Card((int)(iSuit * 13 + iRank));

   // we could also have said:
   // Card cardReturn(this);  // copy constructor
   // cardReturn += input;    // call += operator
   // return cardReturn;      // another copy constructor
}

/*************************
 * Addition
 * This is the same as above except the parameters are in a different order
 *************************/
Card operator + (const int input, const Card & rhs)
{
   return rhs + input;
}


/*************************************************************
 *************************************************************
 ************************ CONSTRUCTORS ***********************
 *************************************************************
 *************************************************************/

/**********************************************************************
 * Default Constructor
 ***********************************************************************/
Card :: Card() : value(0)
{
   assert(validate());
}

/*********************************************
 * Constructor for string conversion
 * Notice how the parameter is constant by reference
 *********************************************/
Card :: Card(const string & s) : value(0)
{
   parse(s);
   assert(validate());
}

/********************************************
 * Constructor for the order of the card in the series. 
 *******************************************/
Card :: Card(int iSuit, int iRank)
{
   // make sure we are in the valid range
   if (iSuit >= (sizeof(SUITS) / sizeof(SUITS[0])) || iSuit < 0)
      iSuit = 0;
   if (iRank >= (sizeof(RANKS) / sizeof(RANKS[0])) || iRank < 0)
      iRank = 0;

   // assign
   value = iSuit * 13 + iRank;

   // paranoia
   assert(validate());
}

/*****************************************
 * Copy constructor
 * Constant by reference
 *****************************************/
Card :: Card(const Card & rhs)
{
   assert(rhs.validate());
   value = rhs.value;
   assert(validate());
}

/**************************************************************
 * Private constructor
 * This is private because only member functions should
 * know about how we store the suit and rank
 **************************************************************/
Card :: Card(unsigned char value)
{
   this->value = value;
   validate();
}

/*************************************************************
 *************************************************************
 ******************** GETTERS AND SETTERS ********************
 *************************************************************
 *************************************************************/

/*******************************
 * I SUIT
 * Find the index from the suits[] array
 * of a given letter. Does not reference
 * any member variable in this
 *********************************/
int Card :: iSuit(char chSuit) const
{
   // look up the suit index;
   chSuit = tolower(chSuit);
   for (int i = 0; i < 4; i++)
      if (chSuit == SUITS[i])
         return i;
   return -1;
}

/********************************
 * I RANK
 * Find the index from the RANKS array
 * of a given letter.  Does not reference
 * any member variable in this
 ********************************/
int Card :: iRank(char chRank) const
{
   // either 0 or 1 is 10
   if (chRank == '1')
      chRank = '0';

   // look up the number
   chRank = tolower(chRank);
   for (int i = 0; i < 13; i++)
      if (chRank == RANKS[i])
         return i;

   return -1;
}


/***********************************
 * SET SUIT
 * RETURN:    Bool         (were we successful in setting the value?)
 * PARAMETER: character    (whatever makes sense for this)
 * METHOD:    not const    (we are intentionally changing this)
 ***********************************/
bool Card :: setSuit(char chSuit)
{
   // paranoia
   assert(this->validate());

   // look up the suit index;
   int i = iSuit(chSuit);

   // bail if invalid
   if (i == -1)
      return false;

   // set the value
   value = (value % 13) + (i * 13);
   assert(this->validate());
   return true;
}

/********************************
 * SET RANK
 * RETURN:    Bool         (were we successful in setting the value?)
 * PARAMETER: character    (whatever makes sense for this)
 * METHOD:    not const    (we are intentionally changing this)
 *******************************/
bool Card :: setRank(char chRank)
{
   // paranoia
   assert(this->validate());

   // look up the rank
   int i = iRank(chRank);

   // bail if invalid
   if (i == -1)
      return false;

   // set the value
   value = i + (value / 13 * 13);
   assert(this->validate());
   return true;
}

/*********************************
 * GET SUIT
 * RETURN:    char         (whatever makes sense for this)
 * PARAMETER: none         (why would I change anything in a getter?)
 * METHOD:    const        (why would I change this in a getter?)
 *********************************/
char Card :: getSuit() const
{
   // paranoia
   assert(this->validate());

   return SUITS[value / 13];
}

/*******************************
 * GET RANK
 * RETURN:    char         (whatever makes sense for this)
 * PARAMETER: none         (why would I change anything in a getter?)
 * METHOD:    const        (why would I change this in a getter?)
 *******************************/
char Card :: getRank() const
{
   // paranoia
   assert(this->validate());
   
   return RANKS[value % 13];
}

/*************************************************************
 *************************************************************
 ********************** HELPER METHODS ***********************
 *************************************************************
 *************************************************************/


/**********************************
 * PARSE
 * Parse the input string to set the rank and suit
 *********************************/
bool Card :: parse(const string & s)
{
   if (s == NO_CARD)
   {
      value = INVALID;
      return true;
   }

   // for each letter in the input buffer
   for (int i = 0; i < s.length(); i++)

      // one of them better resolve...
      if (!setSuit(s[i]) && !setRank(s[i]))

         // ... or else!
         return false;

   return true;
}

/*****************************
 * VALIDATE
 *****************************/
bool Card :: validate() const
{
   if (value == INVALID)
      return true;
   
   int iRank = value % 13;
   int iSuit = value / 13;

   return (iRank >= 0  &&
           iRank <  13 &&
           iSuit >= 0  &&
           iSuit <  4);
}

