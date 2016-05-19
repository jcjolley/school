/***********************************************************************
* Program:
*    SHOTGUNPOWERUP.CPP, Skeet
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
#include "shotgunPowerup.h"
#include "uiDraw.h"
#include "point.h"

/**************************************************
* shotgunPowerup Constructor
* Constructs a new instance of the class
 **************************************************/
ShotgunPowerup::ShotgunPowerup()
{
   diamPowerup = 20;
   dead = true;
}

/**************************************************
* Regenerate
* creates a powerup on screen, gives it a point and dx and dy
 **************************************************/
void ShotgunPowerup::regenerate(int x, int y, int level)
{
   //frankenstein time
   dead = false;
   
   //move up and to the left a bit so the same bullet/shot can't kill this
   //while killing the bird
   vector.getPoint().setX(x - 21);
   vector.getPoint().setY(y + 21);
   
   //go straight down
   vector.setDx(0);
   vector.setDy(-3);
   return;
}

/**************************************************
* Draw
* draws the powerup
 **************************************************/
void ShotgunPowerup::draw()
{
   //draw the powerup circle
   drawCircle(vector.getPoint(), diamPowerup/2, 20, 0);
   
   //move the S so it fits right
   Point point = vector.getPoint();
   point.setY(point.getY() - 5);
   point.setX(point.getX() - 3);
   
   //draw the S
   drawText(point, "S", 1);
   
}

/**************************************************
 * Advance
 * Advances the powerup
 **************************************************/
void ShotgunPowerup::advance()
{
   vector.advance();
}

/**************************************************
 * isDead()
 * draws the powerup
 **************************************************/
bool ShotgunPowerup::isDead()
{
   // if we're off the screen, we're dead
   if (vector.getPoint().getX() > vector.getPoint().getXMax())
   {
      kill();
   }
   if (vector.getPoint().getY() > vector.getPoint().getYMax())
   {
      kill();
   }
   if (vector.getPoint().getY() < vector.getPoint().getYMin())
   {
      kill();
   }
   return dead;
}

