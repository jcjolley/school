/***********************************************************************
 * This demo program is designed to:
 *      Test card.h and card.cpp: Acessors and Mutators
 ************************************************************************/

#include <iostream>
#include <string>
#include "card.h"                 // get access to the Card class through
                                  //    including the card header file
using namespace std;

/**********************************************************************
 * MAIN: a simple driver program for our card class
 *********************************************************************/
int main()
{
   Card card;                     // how many member variables are used here?
                                  //    How is the playing card stored?
                                  //    Frankly, the client here does not care!

   // we need to initialize the card        
   card.initialize();             // call the method with the dot operator

   cout << "Instructions: keep prompting the user for a suit and rank\n"
        << "              until the suit is specified as 0.\n";

   for (;;)                       // forever. We will return when done
   {
      //prompt for suit
      char chSuit;                // this simple driver program will just
      cout << "Suit: ";           //    get user input in the most
      cin  >> chSuit;             //    convenient way so we can exercise
      if (chSuit == '0')          //    the methods of Card
         return 0;

      // prompt for rank
      char chRank;
      cout << "Rank: ";
      cin  >> chRank;

      // set the card
      card.setCard(card.iSuit(chSuit),   
                   card.iRank(chRank));

      // display the results
      cout << endl;               // notice how we are able to call the
      card.display();             //    display function without passing any 
      cout << endl;               //    parameters.  The data is silently
   }                              //    passed through the hidden "this"

   return 0;
}
