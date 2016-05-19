/***********************************************************************
* Program:
*    GAME.CPP, Skeet
*    Brother Helfrich, CS165
* Author:
*    Sam Barney and Joshua Jolley
* Summary:
*    This program emulates the game of Skeet, complete with menus,
*    original sound, levels, and powerups.  
*    Estimated:  15.0 hrs
*    Actual:     30.0 hrs
*    Homing was difficult to implement well, and learning how to uses
*    classess and pass the right information between classes was,
*    well, a learning experience.
**********************************************************************/


#include "Game.h"

SoundManager Game::soundManager = SoundManager();


/***********************************************************************
 * CallBack
 * This function is called by the UI. Controls interaction, advancing,
 * drawing, sound, etc.
 **********************************************************************/
void callBack(const Interface *pUI, void *p)
{
   // Convert p to our generic game pointer
   Game * game = static_cast<Game *>(p);
   
   // Call our generic handler functions
   game->interact(*pUI);
   game->draw();
   game->advance();
   game->soundManager.update();
 
}