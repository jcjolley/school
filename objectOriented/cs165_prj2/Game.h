/***********************************************************************
* Program:
*    GAME.H, Skeet
*    Brother Helfrich, CS165
* Author:
*    Sam Barney and Joshua Jolley
* Summary:
*    This program emulates the game of Skeet, complete with menus,
*    original sound, levels, and powerups.  
*    Estimated:  15.0 hrs
*    Actual:     30.0 hrs
*    Homing was difficult to implement well, and learning how to uses
*    classess and pass the right information between classes wwas,
*    well, a learning experience.
**********************************************************************/


#ifndef __Skeet__Game__
#define __Skeet__Game__
#include "uiInteract.h"
#include "SoundManager.h"


/***********************************************************************
 * Game Class
 * A generic Game class to be inherited from.  We will use this for
 * for Asteroids, and perhaps for Chess if we add a GUI
 **********************************************************************/
class Game
{
public:
   
   static SoundManager soundManager;
   
   virtual ~Game(){}
   virtual void interact(const Interface ui) {}
   virtual void advance() {}
   virtual void draw() {}
};

void callBack(const Interface *pUI, void *p);

#endif /* defined(__Skeet__Game__) */
