/***********************************************************************
* Program:
*    STARTSCREEN.H, Skeet
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
#ifndef __Skeet__startScreen__
#define __Skeet__startScreen__

#include <iostream>
#include "uiInteract.h"
#include "selector.h"
#include "point.h"


/***********************************************************************
 * StartScreen Class
 * Controls interacting, advancing, drawing etc for the Start screen
 **********************************************************************/
class StartScreen
{
public:
   
   StartScreen();
   void interact(const Interface ui);
   void advance();
   void draw();
   bool isDead() const {return dead;}
   void kill();
   void resurrect() { dead = false; }
   int getSelectorY();
   
private:
   bool dead;
   Selector selector;
   std::string title;
   std::string start;
   std::string help;
   std::string exit;
   Point ptTitle;
   Point ptStart;
   Point ptHelp;
   Point ptExit;
};
#endif /* defined(__Skeet__startScreen__) */
