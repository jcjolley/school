/***********************************************************************
* Program:
*    SCENE.H, Skeet
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

#ifndef __Skeet__scene__
#define __Skeet__scene__
#include "skeet.h"
#include "startScreen.h"
#include "levelScreen.h"
#include "gameOver.h"
#include "helpScreen.h"


/***********************************************************************
 * Scene Class
 * This class controls the current scene, like a menu or the game.
 **********************************************************************/
class Scene : Game
{
public:
   void interact(const Interface ui);
   void advance();
   void draw();
   
private:
   std::string musicName;
   Skeet skeet;
   StartScreen startScreen;
   LevelScreen levelScreen;
   GameOver gameOver;
   HelpScreen helpScreen;
   
   
};

#endif /* defined(__Skeet__scene__) */
