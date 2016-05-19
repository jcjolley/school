/***********************************************************************
* Program:
*    SHOTGUNPOWERUP.H, Skeet
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
#ifndef __Skeet__ShotgunPowerups__
#define __Skeet__ShotgunPowerups__
#include "vector.h"


/***********************************************************************
 * ShotgunPowerup Class
 * Draws, advances, regenerates, etc the ShotgunPowerup
 **********************************************************************/
class ShotgunPowerup
{
public:
   ShotgunPowerup();
   void regenerate(int x, int y, int level);
   void draw();
   void advance();
   bool isDead();
   Vector & getVector() { return vector; }
   int getSize()  const { return diamPowerup; }
   void kill()          { dead = true; return; }
   void resurrect() {dead = false; }
   
private:
   Vector vector;
   int diamPowerup;
   bool dead;
};


#endif /* defined(__Skeet__powerups__) */
