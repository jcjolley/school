/***********************************************************************
* Source file:
*    HAND: The data structure necessary to hold a hand of cards
* Summary:
*    All the data and methods necessary to hold a collection of
*    playing cards (a hand or a deck).
************************************************************************/

#include <iostream>   // Because a hand is displayed
#include <fstream>    // We will write to a file
#include <cassert>    // Because I am paranoid
#include <stdlib.h>   // For the random function... for shuffling
#include "hand.h"     // The hand data structures
using namespace std;

/**********************************************************************
 * CONSTRUCTOR
 * Build a default hand, ordered
 ***********************************************************************/
Hand::Hand(bool fill)
{
   // fill up the cards with a full deck... in order
   for (int iSuit = FIRST_SUIT; iSuit <= LAST_SUIT; iSuit++)
      for (int iRank = FIRST_RANK; iRank <= LAST_RANK; iRank++)
         listCards.push_back(Card(iSuit, iRank));
}

/********************************************
 * READ
 * Read a hand from the file.  
 ********************************************/
bool Hand::read(const char *szFileName)
{
   // open the file
   ifstream fin(szFileName);
   if (fin.fail())
      return false;

   // read the contents
   Card card;
   while (fin >> card)
      listCards.push_back(card);
   
   // close it...
   fin.close();
   return true;
}

/*********************************************
 * DISPLAY
 * Show the contents of the hand on the screen
 ********************************************/
ostream &operator << (ostream &out, const Hand &hand)
{
   int size = hand.size();

   // display the first n-1 items
   for (int i = 0; i < size - 1; i++)
      out << hand[i] << ' ';

   // the last is special because it has a new line at the end
   if (size)
      out << hand[size - 1] << endl;

   return out;
}

/*********************************************
 * []
 *********************************************/
const Card & Hand::operator[](int iHand) const
{
   assert(iHand < listCards.size());
   assert(iHand >= 0);

   return listCards[iHand];
}

/*********************************************
 * REMOVE CARD
 * Take a card from the deck
 ********************************************/
Card Hand::removeCard(int i)
{
   assert(i >= 0);
   if (i >= listCards.size())
      return Card(NO_CARD);

   Card card = listCards[i];
   listCards.erase(i + listCards.begin());
   return card;
}

/***************************************
 * shuffle
 * Swap the cards in the stack
 ***************************************/
void Hand::shuffle()
{
   int size = listCards.size();
   srand((int)&size);

   for (int iSlot = 0; iSlot < size - 1; iSlot++)
   {
      // find the index of the replacement slot
      int num = size - iSlot - 1;
      int iReplace = iSlot + (rand() % num) + 1;
      assert(iReplace > iSlot && iReplace < size);

      // perform the swap
      Card temp = listCards[iSlot];
      listCards[iSlot] = listCards[iReplace];
      listCards[iReplace] = temp;
   }

   return;
}
       

/***************************************
 * +
 * Place all the cards in the RHS in the LHS
 ***************************************/
Hand & Hand::operator += (const Hand &rhs)
{
   for (int iRight = 0; iRight < rhs.size(); iRight++)
      *this += rhs[iRight];
   return *this;
}

/***************************************
 * +
 * Add a card to the hand
 ***************************************/
Hand & Hand::operator += (const Card &rhs)
{
   listCards.push_back(rhs);
   return *this;
}

/*****************************************
 * Extraction
 * Read the hand
 *****************************************/
istream &operator >> (istream &in, Hand &hand)
{
   Card card;
   if (in >> card)
      hand += card;

   return in;
   
}

/*****************************************
 * Equal?
 *****************************************/
bool operator == (const Hand &lhs, const Card &rhs)
{
   for (int i = 0; i < lhs.size(); i++)
      if (rhs == lhs[i])
         return true;
   return false;
}

/*****************************************
 * Equal?
 *****************************************/
bool operator == (const Hand &lhs, const Hand &rhs)
{

   for (int i = 0; i < lhs.size(); i++)
      if (lhs != rhs[i])
         return false;
   for (int i = 0; i < rhs.size(); i++)
      if (rhs != lhs[i])
         return false;

   return true;
}

