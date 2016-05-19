/***********************************************************************
* Program:
*    HELPSCREEN.H, Skeet
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
//
//  helpScreen.h
//  Skeet
//
//  Created by Joshua Jolley on 10/24/12.
//  Copyright (c) 2012 ImagineIt! Studios. All rights reserved.
//

#ifndef __Skeet__helpScreen__
#define __Skeet__helpScreen__

#include "uiInteract.h"
#include "point.h"
#include "score.h"
#include <string>
#include "selector.h"
#include "shotgunPowerup.h"
#include "homingPowerup.h"
#include "startScreen.h"

/***********************************************************************
 * HelpScreen class
 * This scene controls interaction, drawing, live/dead state, etc 
 * for the Help Screen
 **********************************************************************/
class HelpScreen
{
public:
   HelpScreen();
   ~HelpScreen();
   void interact(const Interface ui, StartScreen & startScreen);
   void draw();
   bool isDead() const {return dead;}
   void kill() {dead = true;}
   void resurrect() { dead = false;}
   void setLevel (int level);
   
   
private:
   bool dead;
   std::string title;
   std::string * helps;
   std::string back;
   Point * ptHelps;
   Point ptTitle;
   Point ptBack;
   Selector selector;
   ShotgunPowerup shotgunPowerup;
   HomingPowerup homingPowerup;
};

#endif /* defined(__Skeet__helpScreen__) */
