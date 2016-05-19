/***********************************************************************
* Program:
*    SKEET.H, Skeet
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

#ifndef Skeet_skeet_h
#define Skeet_skeet_h
#include "bird.h"
#include "bullet.h"
#include "rifle.h"
#include "shotgun.h"
#include "score.h"
#include "Game.h"
#include <string>
#include "shotgunPowerup.h"
#include "homingPowerup.h"

/***********************************************************************
 * Skeet Class
 * This class is the real work horse of the game.  Draws, Advances, 
 * the members of Skeet. Checks interaction.
 **********************************************************************/
class Skeet : Game
{
public:
   Skeet();
   ~Skeet();
   void interact(const Interface ui);
   void advance();
   void draw();
   void reset();
   void resurrect()           { dead = false; }
   bool isDead()        const { return dead;}
   void kill();
   Score & getScore()         { return score; }
   Score & getLives()         { return lives; }
   int & getLevel()           { return level; }
   void addLevel()            { level++;}
      
private:
   Bird     bird;
   Bullet   *bullets;
   char     availableBullets;
   Rifle    rifle;
   Score    score;
   Score    totalBirds;
   Score    lives;
   Shotgun  shotgun;
   bool dead;
   int level;
   std::string numLives;
   Point ptNumLives;
   ShotgunPowerup shotgunPowerup;
   HomingPowerup homingPowerup;
   bool homing;
   static int homingCount;        //used as a timer
   static int shotgunCount;       //used as a timer
 
   
};

#endif
