/***********************************************************************
* Program:
*    HOMINGPOWERUP.CPP, Skeet
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
#include "homingPowerup.h"
#include "uiDraw.h"
#include "point.h"

/**************************************************
* HomingPowerup Constructor
* Constructs a new instance of the class
 **************************************************/
HomingPowerup::HomingPowerup()
{
   diamPowerup = 20;
   dead = true;
}

/**************************************************
* Regenerate
* creates a powerup on screen, gives it a point and dx and dy
 **************************************************/
void HomingPowerup::regenerate(int x, int y, int level)
{
   //"Its.... ALIIIVE!"
   dead = false;
   
   //move the power up out of the path of the bullets aimed for the bird
   vector.getPoint().setX(x - 21);
   vector.getPoint().setY(y + 21);
   
   //send the powerup straight down
   vector.setDx(0);
   vector.setDy(-3);
   return;
}

/**************************************************
* Draw
* draws the powerup
 **************************************************/
void HomingPowerup::draw()
{
   //draw the circle
   drawCircle(vector.getPoint(), diamPowerup/2, 20, 0);
   
   //move the H so it fits well in the circle
   Point point = vector.getPoint();
   point.setY(point.getY() - 5);
   point.setX(point.getX() - 3);
   
   //draw the H
   drawText(point, "H", 1);
   
}

/**************************************************
 * Advance
 * Advances the powerup
 **************************************************/
void HomingPowerup::advance()
{
   vector.advance();
}

/**************************************************
 * isDead()
 * draws the powerup
 **************************************************/
bool HomingPowerup::isDead()
{
   //if we're off the screen
   if (vector.getPoint().getX() > vector.getPoint().getXMax())
   {
      //we're dead
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

