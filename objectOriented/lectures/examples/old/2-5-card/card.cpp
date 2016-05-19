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
 **************** MEMBER OPERATOR OVERLOADING ****************
 *************************************************************
 *************************************************************/

/*********************************
 * Equivelence
 * RETURN:    Bool                  (either equal or not)
 * PARAMETER: constant by reference (do not make a copy)
 * METHOD:    const                 (no not change this)
 ********************************/
bool Card :: operator == (const Card & rhs) const
{
   // I am paranoid
   assert(this->validate());
   assert(rhs.validate());

   // only same if both suit and rank are the same
   return value == rhs.value;
}

/*********************************
 * Difference
 * RETURN:    Bool                  (either not equal or equal)
 * PARAMETER: constant by reference (do not make a copy)
 * METHOD:    const                 (no not change this)
 ********************************/
bool Card :: operator != (const Card & rhs) const
{
   // should be an inline
   return !(*this == rhs);
}

/*********************************
 * Greater than or equal to
 * RETURN:    Bool                  
 * PARAMETER: constant by reference (do not make a copy)
 * METHOD:    const                 (no not change this)
 ********************************/
bool Card :: operator >= (const Card & rhs) const
{
   // paranoia
   assert(this->validate());
   assert(rhs.validate());

   // we are only comparing the ranks, not the suit for playing cards
   unsigned char iLHS = this->value % 13;
   unsigned char iRHS = rhs.value % 13;

   return iLHS >= iRHS;
}

/*********************************
 * Greater than
 * RETURN:    Bool
 * PARAMETER: constant by reference (do not make a copy)
 * METHOD:    const                 (no not change this)
 ********************************/
bool Card :: operator > (const Card & rhs) const
{
   // paranoia
   assert(this->validate());
   assert(rhs.validate());

   // again, only comparing the ranks
   unsigned char iLHS = this->value % 13;
   unsigned char iRHS = rhs.value % 13;

   return iLHS > iRHS;
}

/*********************************
 * Less than or equal to
 * RETURN:    Bool
 * PARAMETER: constant by reference (do not make a copy)
 * METHOD:    const                 (no not change this)
 *
 * In most cases, we can simply say:
 *     return !(*this > rhs);
 ********************************/
bool Card :: operator <= (const Card & rhs) const
{
   // paranoia
   assert(this->validate());
   assert(rhs.validate());
   
   unsigned char iLHS = this->value % 13;
   unsigned char iRHS = rhs.value % 13;

   return iLHS <= iRHS;
}

/*********************************
 * Less than
 * RETURN:    Bool
 * PARAMETER: constant by reference (do not make a copy)
 * METHOD:    const                 (no not change this)
 *
 * In most cases, we can simply say:
 *     return !(*this >= rhs);
 ********************************/
bool Card :: operator < (const Card & rhs) const
{
   // paranoia
   assert(this->validate());
   assert(rhs.validate());   

   unsigned char iLHS = this->value % 13;
   unsigned char iRHS = rhs.value % 13;

   return iLHS < iRHS;
}

/**************************
 * Assignment
 * RETURN:    Self by reference      (so we can say (x = y) = 10;)
 * PARAMETER: Constant by reference
 * METHOD:    not const              (we are intentionally changing this)
 **************************/
Card & Card :: operator = (const Card & rhs)
{
   // paranoia
   assert(rhs.validate());

   // do the assignment.  Only one member variable here
   value = rhs.value;

   // now we better be in a valid state
   assert(this->validate());

   // return self by reference 
   return *this;
}

/***************************
 * Plus Equals
 * RETURN:    Self by reference    (so we can say (x += 1) += 3;)
 * PARAMETER: Whatever makes sense (card += 2 make sense, not card1 += card2;)
 * METHOD:    not const            (we are intentionally changing this)
 **************************/
Card & Card :: operator += (const int input)
{
   // paranoia
   assert(this->validate());
   
   // here this is somewhat complex. The suit does not change
   int iSuit = value / 13;

   // grab the rank and add _input_, making sure it is in range
   int iRank = value % 13 + input;
   if (iRank > LAST_RANK)
      iRank = LAST_RANK;
   if (iRank < FIRST_RANK)
      iRank = FIRST_RANK;

   // re-create the value
   value = (iSuit * 13) + iRank;

   // return by reference
   return *this;
}

/*****************************
 * Minus Equals
 * RETURN:    Self by reference    (so we can say (x -= 1) -= 3;)
 * PARAMETER: Whatever makes sense (card += 2 make sense, not card1 -= card2;)
 * METHOD:    not const            (we are intentionally changing this)
 *****************************/
Card & Card :: operator -= (const int input)
{
   // This should be inline.  Just call +=
   return *this += -input;
}

/***************************
 * Increment: prefix  (++x)
 * RETURN:    Self by reference    (so we can say ++(++x) )
 * PARAMETER: none                 (++ is a unary operator)
 * METHOD:    not constant         (we are intentionally changing this)
 **************************/
Card & Card :: operator ++ ()
{
   // should be inline.  Just call +=
   return *this += 1;
}

/***************************
 * Increment: postfix   (x++)
 * RETURN:    Self by value       (we are returning the old copy of this)
 * PARAMETER: integer             (this parameter is ignored)
 * METHOD:    not const           (we are intentionally changing this)
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
Card Card :: operator ++ (int postfix)
{
   // paranoia
   assert(this->validate());

   // remember the old value so we can return it
   unsigned char valueOld = value;

   // add one to this calling the += operator
   *this += 1;

   // now we need to return a copy of the old value. 
   return Card (valueOld);
}

/**************************
 * Decrement: prefix  (--x)
 * RETURN:    Self by reference    (so we can say --(--x) )
 * PARAMETER: none                 (-- is a unary operator)
 * METHOD:    not constant         (we are intentionally changing this)
 **************************/
Card & Card :: operator -- ()
{
   // should be inline
   return *this -= 1;
}

/***************************
 * Decrement: postfix     (x--)
 * RETURN:    Self by value       (we are returning the old copy of this)
 * PARAMETER: integer             (this parameter is ignored)
 * METHOD:    not const           (we are intentionally changing this)
 *
 * Again, we need to return a copy of the old value.
 **************************/
Card Card :: operator -- (int postfix)
{
   // paranoia
   assert(this->validate());

   // this way is less efficient that what we did for x++
   // call the copy constructor
   Card cardOld (*this);           

   // decrement this
   *this -= 1;

   // return the old copy. This will call another copy-constructor
   return cardOld;
}

/*************************
 * Addition
 * RETURN:    Self by value         (we are creating a new card to return)
 * PARAMETER: Whatever makes sense  (usually the same parameter as +=
 * METHOD:    constant              (we cannot change this)
 *
 * From the following:
 *     cout << x + y << endl;
 * We do not expect x or y to change.  Therefore, it must be a const method
 *************************/
Card Card :: operator + (const int input) const
{
   // paranoia
   assert(this->validate());

   // suit does not change
   int iSuit = value / 13;

   // add input to the rank.  Change to make sure we are still valid
   int iRank = value % 13 + input;
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

