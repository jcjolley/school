/***********************************************************************
* Program
*    PLAY GAME: Play the game of war
* Summary: 
*    Allows the user to play the game of War.  Let's be honest, we are
*    actually just watching the game; War is not very interactive.
************************************************************************/

#include <iostream>
#include <cassert>
#include "war.h"
using namespace std;

/**********************************************************************
* Just a simple driver program
***********************************************************************/
int main()
{
   // create a deck and shuffle it
   Hand deck(true);
   deck.shuffle();

   // size of each hand
   int size;
   cout << "How big is each hand? ";
   cin  >> size;
   cin.ignore();

   // Start the game
   War war;
   war.fillHands(size, deck);
   
   // play war!
   int round = 0;
   while (!war.isFinished())
   {
      // output
      cout << "Round " << ++round << endl;
      war.display();

      // advance the game
      war.advance();
      
      // press any key to continue
      {
         char value;
         cin.get(value);
      }
   }

   // display the results
   if (war.playerLost(1))
      cout << "Player 1 won!\n";
   else
      cout << "Player 2 was victorious!\n";
  
   return 0;
}

