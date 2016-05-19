/***********************************************************************
* Program:
*    BULLET.CPP, Skeet
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


#include "bullet.h"
#include "uiDraw.h"
#include <cmath>
#include <iostream>
#define TO_RADIANS .0174532925
#define BULLET_SPEED 10

/***********************************************************************
 * Bullet::Bullet() Constructor
 * Initializes the members of Bullet
 **********************************************************************/
Bullet::Bullet()
{
   dead = true;
   maxRifleB = 5;
   maxShotgunB = 9;
   bullet_speed = 10.0;
}

/***********************************************************************
 * Bullet::fire
 * Fires a bullet from the lower right hand corner
 **********************************************************************/
void Bullet::fire(float angle, int level)
{
   
   //make it alive! (now it will be drawn/advanced)
   dead = false;
   
   //put the bullet in the lower right hand corner
   vector.getPoint().setX(vector.getPoint().getXMax() - 1);
   vector.getPoint().setY(vector.getPoint().getYMin() + 1);
   
   //we need to "flop" the angle to get it to work correctly
   angle = angle + ((90 - 1 ) - (2 * angle)) + 1;
   
   //"fire" the bullet by giving it an dx and dy
   //based on the angle of the gun
   vector.setDx(-cos(angle * TO_RADIANS) * BULLET_SPEED * (level/8.0 + 1.3));
   
   vector.setDy(sin(angle * TO_RADIANS) * BULLET_SPEED * (level/8.0 + 1.3));
   
 
   
   return;
}

/***********************************************************************
 * Bullet::draw
 * Draws the bullet
 **********************************************************************/
void Bullet::draw()
{
   //draw it
   drawDot(vector.getPoint());
   
   return;
}

/***********************************************************************
 * Bullet::advance
 * Advances the bullet by calling vector.advance
 **********************************************************************/
void Bullet::advance()
{
   vector.advance();
   return;
}

/***********************************************************************
 * Bullet:isDead
 * Kills the bullet if it leaves the screen and returns whether it's dead or not
 **********************************************************************/
bool Bullet::isDead()
{
  
   //if we're off the screen, we're dead.
   if (vector.getPoint().getX() > vector.getPoint().getXMax() + 15)
      kill();
   if (vector.getPoint().getX() < vector.getPoint().getXMin())
      kill();
   if (vector.getPoint().getY() > vector.getPoint().getYMax())
      kill();
   if (vector.getPoint().getY() < vector.getPoint().getYMin() - 15)
      kill();
   
   return dead;
}

/***********************************************************************
 * Bullet::kill
 * kills the bullet
 **********************************************************************/
void Bullet::kill()
{
   dead = true;
}


