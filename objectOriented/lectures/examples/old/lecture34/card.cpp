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

/*******************************************************************
 *******************************************************************
 ************************** ACES LOW *******************************
 *******************************************************************
 *******************************************************************/

/********************************
 * I RANK
 * Find the index from the RANKS array
 * of a given letter
 ********************************/
int AcesLow::iRank(char chRank) const
{
   // either 0 or 1 is 10
   if (chRank == '1')
      chRank = '0';

   // look up the number
   chRank = tolower(chRank);
   for (int i = 0; i < 13; i++)
      if (chRank == ACES_LOW_RANKS[i])
         return i;

   return -1;
}

/**********************************************************************
* Constructor
***********************************************************************/
AcesLow::AcesLow()
{
   value = 0;
   assert(validate());
}


/*****************************************
 * Copy constructor
 *****************************************/
AcesLow::AcesLow(const AcesLow & rhs)
{
   value = rhs.value;
   assert(validate());
}

/*****************************************
 * Pseudo-copy constructor
 *****************************************/
AcesLow::AcesLow(const Card & rhs)
{
   value = rhs.value;
   assert(validate());
}

/********************************
 * SET RANK
 *******************************/
bool AcesLow::setRank(char chRank)
{
   assert(!isInvalid());
   // look up the rank
   int i = iRank(chRank);

   // bail if invalid
   if (i == -1)
      return false;

   // set the value
   value = i + (value / 13 * 13);
   assert(validate());
   return true;
}

/*******************************
 * GET RANK
 *******************************/
char AcesLow::getRank() const
{
   assert(!isInvalid());
   assert(validate());
   return ACES_LOW_RANKS[value % 13];
}

/**********************************
 * PARSE
 * Parse the input string to set the rank and suit
 *********************************/
bool AcesLow::parse(string s)
{
   if (s == NO_CARD)
   {
      value = INVALID;
      return true;
   }

   cout << "From " << s;
   
   // for each letter in the input buffer
   for (int i = 0; i < s.length(); i++)

      // one of them better resolve...
      if (!setSuit(s[i]) && !setRank(s[i]))
      {
         // ... or else!
         cout << "Faied to read " << s[i] << endl;
         return false;
      }

   cout << " to " << (int)value << endl;

   return true;
}


/*****************************
 * Insertion
 *****************************/
ostream &operator << (ostream &out, const AcesLow &card)
{
   cout << "AcesLow: ";
   if (card.isInvalid())
      out << NO_CARD;
   else
      out << card.getSuit() << card.getRank();
   return out;
}

/*****************************
 * Extraction
 *****************************/
istream &operator >> (istream &in, AcesLow &card)
{
   // input comes in the form of a string
   string input;
   in >> input;

   // do the actual work
   card.parse(input);
   
   // return the input stream
   return in;
}


/*******************************************************************
 *******************************************************************
 *****************************  CARD  ******************************
 *******************************************************************
 *******************************************************************/


/**********************************************************************
* Constructor
***********************************************************************/
Card::Card()
{
   value = 0;
   assert(validate());
}

/*********************************************
 * Constructor for string conversion
 *********************************************/
Card::Card(string s)
{
   value = 0;  // first set everything to zero, then check
   parse(s);
   assert(validate());
}

/********************************************
 * Constructor for the order of the card in the series
 *******************************************/
Card::Card(int iSuit, int iRank)
{
   // make sure we are in the valid range
   if (iSuit >= (sizeof(SUITS)/sizeof(SUITS[0])) || iSuit < 0)
      iSuit = 0;
   if (iRank >= (sizeof(RANKS)/sizeof(RANKS[0])) || iRank < 0)
      iRank = 0;

   // assign
   value = iSuit * 13 + iRank;

   // paranoia
   assert(validate());
}

/*****************************************
 * Copy constructor
 *****************************************/
Card::Card(const Card & rhs)
{
   value = rhs.value;
   assert(validate());
}

/*****************************************
 * Copy constructor
 *****************************************/
Card::Card(const AcesLow & rhs)
{
   value = rhs.value;
   assert(validate());
}


/**************************************************************
 * Private constructor
 **************************************************************/
Card::Card(char value)
{
   this->value = value;
   validate();
}

/*******************************
 * I SUIT
 * find the index from the suits[] array
 * of a given letter
 *********************************/
int Card::iSuit(char chSuit) const
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
 * of a given letter
 ********************************/
int Card::iRank(char chRank) const
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
 ***********************************/
bool Card::setSuit(char chSuit)
{
   assert(!isInvalid());
   // look up the suit index;
   int i = iSuit(chSuit);

   // bail if invalid
   if (i == -1)
      return false;

   // set the value
   value = (value % 13) + (i * 13);
   assert(validate());
   return true;
}

/********************************
 * SET RANK
 *******************************/
bool Card::setRank(char chRank)
{
   assert(!isInvalid());
   // look up the rank
   int i = iRank(chRank);

   // bail if invalid
   if (i == -1)
      return false;

   // set the value
   value = i + (value / 13 * 13);
   assert(validate());
   return true;
}

/*********************************
 * GET SUIT
 *********************************/
char Card::getSuit() const
{
   assert(!isInvalid());
   assert(validate());

   return SUITS[value / 13];
}

/*******************************
 * GET RANK
 *******************************/
char Card::getRank() const
{
   assert(!isInvalid());
   assert(validate());
   return RANKS[value % 13];
}

/*********************************
 * Equivelence
 ********************************/
bool operator == (const Card &lhs, const Card &rhs) 
{
   assert(!lhs.isInvalid());
   assert(!rhs.isInvalid());
   
   assert(lhs.validate());
   assert(rhs.validate());
   return lhs.value == rhs.value;
}

/*********************************
 * Difference
 ********************************/
bool operator != (const Card &lhs, const Card &rhs) 
{
   assert(!lhs.isInvalid());
   assert(!rhs.isInvalid());   
   assert(lhs.validate());
   assert(rhs.validate());
   return lhs.value != rhs.value;
}

/*********************************
 * Greater than or equal to
 ********************************/
bool operator >= (const Card &lhs, const Card &rhs)
{
   assert(!lhs.isInvalid());
   assert(!rhs.isInvalid());
   
   char iLHS = lhs.value % 13;
   char iRHS = rhs.value % 13;

   return iLHS >= iRHS;
}

/*********************************
 * Greater than 
 ********************************/
bool operator > (const Card &lhs, const Card &rhs)
{
   assert(!lhs.isInvalid());
   assert(!rhs.isInvalid());
   
   char iLHS = lhs.value % 13;
   char iRHS = rhs.value % 13;

   return iLHS > iRHS;
}

/*********************************
 * Less than or equal to
 ********************************/
bool operator <= (const Card &lhs, const Card &rhs)
{
   assert(!lhs.isInvalid());
   assert(!rhs.isInvalid());

   char iLHS = lhs.value % 13;
   char iRHS = rhs.value % 13;

   return iLHS <= iRHS;
}

/*********************************
 * Less than 
 ********************************/
bool operator < (const Card &lhs, const Card &rhs)
{
   assert(!lhs.isInvalid());
   assert(!rhs.isInvalid());

   char iLHS = lhs.value % 13;
   char iRHS = rhs.value % 13;

   return iLHS < iRHS;
}


/***************************
 * +=
 **************************/
Card & Card::operator += (const int input)
{
   assert(!isInvalid());

   int iSuit = value / 13;
   int iRank = value % 13 + input;
   if (iRank > LAST_RANK)
      iRank = LAST_RANK;
   if (iRank < FIRST_RANK)
      iRank = FIRST_RANK;

   value = (iSuit * 13) + iRank;
   return *this;
}

/***************************
 * Increment: postfix
 **************************/
Card Card::operator ++ (int postfix)
{
   assert(!isInvalid());
   
   char valueOld = value;
   *this += 1;
   return Card (valueOld);
}

/***************************
 * Decrement: postfix
 **************************/
Card Card::operator -- (int postfix)
{
   assert(!isInvalid());
   
   char valueOld = value;
   *this -= 1;
   return Card (valueOld);
}

/*************************
 * +
 *************************/
Card Card::operator + (const int input) const
{
   assert(!isInvalid());
   
   int iSuit = value / 13;
   int iRank = value % 13 + input;
   if (iRank > LAST_RANK)
      iRank = LAST_RANK;
   if (iRank < FIRST_RANK)
      iRank = FIRST_RANK;
   
   return Card((int)(iSuit * 13 + iRank));
}

/*************************
 * + non-member
 ************************/
Card operator + (int lhs, const Card & rhs)
{
   assert(!rhs.isInvalid());
   
   int iSuit = rhs.value / 13;
   int iRank = rhs.value % 13 + lhs;

   if (iRank > LAST_RANK)
      iRank = LAST_RANK;
   if (iRank < FIRST_RANK)
      iRank = FIRST_RANK;

   return Card(iSuit * 13 + iRank);
}

/*****************************
 * Insertion
 *****************************/
ostream &operator << (ostream &out, const Card &card)
{
   cout << "Card: ";
   if (card.isInvalid())
      out << NO_CARD;
   else
      out << card.getSuit() << card.getRank();
   return out;
}

/*****************************
 * Extraction
 *****************************/
istream &operator >> (istream &in, Card &card)
{
   // input comes in the form of a string
   string input;
   in >> input;

   // do the actual work
   card.parse(input);

   // return the input stream
   return in;
}


/**********************************
 * PARSE
 * Parse the input string to set the rank and suit
 *********************************/
bool Card::parse(string s)
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
bool Card::validate() const
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
