/***********************************************************************
* Source File
*    WAR: The methods supporting the War card game
* Summary: 
*    Implements all the methods of the WAR game defined in WAR.h
************************************************************************/

#include <iostream>   // output is done here
#include <cassert>    // paranoia
#include "war.h"      // all the definitions of the game 
using namespace std;


/*********************************************
 * FILL HANDS
 * Fill both player1 and player2's hand with a
 * certain number of cards.
 *    INPUT:   sizeHand.  How big each hand will be
 *    OUTPUT:
 ********************************************/
void War::fillHands(int sizeHand, Hand & deck)
{
   for (int i = 0; i < sizeHand; i++)
   {
      player0 += deck.removeTop();
      player1 += deck.removeTop();
   }
}


/*******************************************
 * ADVANCE
 * Advance the game by one turn
 *******************************************/
void War::advance()
{
   assert(player0.size());
   assert(player1.size());

   // compare the top-most card
   Hand stack;
   stack += player0.removeTop();
   stack += player1.removeTop();

   // if player0's card is larger, he gets both
   if (stack[0] > stack[1])
   {
      player0 += stack;
      return;
   }
   
   // if player1's card is larger, he gets both   
   if (stack[1] > stack[0])
   {
      player1 += stack;
      return;
   }

   int iPlayer0 = 0;
   int iPlayer1 = 1;
   while (stack[iPlayer0] >= stack[iPlayer1] &&
          stack[iPlayer0] <= stack[iPlayer1])
   {
      // If player 0 is out of cards, player 1 won!
      if (player0.size() < 3)
      {
         player1 += stack;
         player1 += player0;
         player0.clear();
         return;
      }
      // If player 1 is out of cards, player 0 won!
      if (player1.size() < 3)
      {
         player0 += stack;
         player0 += player1;
         player1.clear();
         return;
      }

      // take two from each and put them in the stack
      for (int i = 0; i < 3; i++)
      {
         stack += player0.removeTop();
         stack += player1.removeTop();
      }
      iPlayer0 = stack.size() - 2;
      iPlayer1 = stack.size() - 1;
   }

   // after the WAR, give the winners cards to the winner
   if (stack[iPlayer0] > stack[iPlayer1])
      player0 += stack;
   else
      player1 += stack;
   return;
}

/***************************************
 * DISPLAY
 * Display the contents of both hands
 ***************************************/
void War::display()
{
   cout << "\tPlayer 1: " << player0;
   cout << "\tPlayer 2: " << player1;   
}

