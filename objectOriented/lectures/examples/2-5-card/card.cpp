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
   assert(sizeof(RANKS_HIGH) == sizeof(RANKS_LOW));
   
   // make sure we are in the valid range
   if (iSuit >= (sizeof(SUITS) / sizeof(SUITS[0])) || iSuit < 0)
      iSuit = 0;
   if (iRank >= (sizeof(RANKS_HIGH) / sizeof(RANKS_HIGH[0])) || iRank < 0)
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
   static const char * pRank = (acesHigh ? RANKS_HIGH : RANKS_LOW);
   
   // either 0 or 1 is 10
   if (chRank == '1')
      chRank = '0';

   // look up the number
   chRank = tolower(chRank);
   for (int i = 0; i < 13; i++)
      if (chRank == pRank[i])
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
   // this is static because we should only need to initialize it once
   static const char * pRank = (acesHigh ? RANKS_HIGH : RANKS_LOW);

   // paranoia
   assert(this->validate());
   
   return pRank[value % 13];                 // point to the appropriate string
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

