/***********************************************************************
 * Header File
 *    WAR: This is the header file for the War card game
 * Summary:
 *    Holds all the data and functions necessary to play the child's game
 *    of WAR.
 ************************************************************************/

#ifndef WAR_H
#define WAR_H

#include "hand.h"
#include <cassert>

/**********************************************
 * WAR
 * The class to contain all the elements of the game
 **********************************************/
class War
{
  public:
   // fill the hands
   void fillHands(int sizeHand, Hand & deck);
   
   // advance the game by one turn
   void advance();

   // display the current status of the game
   void display();

   // are we finished yet?
   bool isFinished()
   {
      return player0.size() == 0 || player1.size() == 0;
   }

   // did one of the players loose?
   bool playerLost(int iPlayer)
   {
      if (iPlayer == 0)
         return player0.size() == 0;
      if (iPlayer == 1)
         return player1.size() == 0;
      assert(false);
      return true;
   }
   
  private:
   Hand player0;
   Hand player1;    
};

#endif // WAR_H
