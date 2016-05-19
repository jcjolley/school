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

/************************************************************
 * DISPLAY
 * Display the card in english.
 ****************************************************/
void Card :: display()
{

   int iRank = value % 13;
   int iSuit = value / 13;
   
   // rank
   switch (iRank)
   {
      case 8:
         cout << "10";
         break;
      case 9:
         cout << "Jack";
         break;
      case 10:
         cout << "Queen";
         break;
      case 11:
         cout << "King";
         break;
      case 12:
         cout << "Ace";
         break;
      default:
         cout << iRank + 2;
   }

   cout << " of ";

   // suit
   switch (iSuit)
   {
      case 0:
         cout << "Spades";
         cout << endl;
         break;
      case 1:
         cout << "Hearts";
         cout << endl;
         break;
      case 2:
         cout << "Clubs";
         cout << endl;
         break;
      default:
         cout << "Diamonds";
         cout << endl;
   }
}

/******************************************************
 * INITIALIZE
 * Set card to two of spades at the bginning.
 * 
 ***************************************************/
void Card :: initialize()
{
   setCard('s', 2);
}

/**************************************************
 * SET CARD
 * RETURN:    Bool            (Were we successful in setting the value?)
 * PARAMETER: Character       (one for the suit, and one for the rank)
 * METHOD:    Not const       (we are intentially changing values)
 *************************************************/
void Card :: setCard(int iSuit, int iRank)
{
   if (iSuit >= (sizeof(SUITS) / sizeof(SUITS[0])) || iSuit < 0)
      iSuit = 0;
   if (iRank >= (sizeof(RANKS) / sizeof(RANKS[0])) || iRank < 0)
      iRank = 0;

   value = iSuit * 13 + iRank;

   assert(validate());
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
/*************************************************************
 *************************************************************
 ********************** HELPER METHODS ***********************
 *************************************************************
 *************************************************************/

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

