/***********************************************************************
* Program:
*    LEVELSCREEN.H, Skeet
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
#ifndef __Skeet__levelScreen__
#define __Skeet__levelScreen__
#include "uiInteract.h"
#include "point.h"
#include "score.h"
#include <string>


/***********************************************************************
 * LevelScreen Class
 * Controls interaction, advancement, drawing, etc for the Level scene
 **********************************************************************/
class LevelScreen
{
public:
   LevelScreen();
   ~LevelScreen();
   void interact(const Interface ui);
   void advance(int score);
   void draw(int numLevel);
   bool isDead() const {return dead;}
   void kill() {dead = true;}
   void resurrect() { dead = false;}
   void setLevel (int level);
   int getRunTimes() { return runTimes; }
   
private:
   bool dead;
   std::string level;
   Point ptLevel;
   static int runTimes;
   Point  * ptTips;
   std::string * tips;
   
};

#endif /* defined(__Skeet__levelScreen__) */
