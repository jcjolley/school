/***********************************************************************
* Program:
*    BIRD.CPP, Skeet
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


#include "Game.h"
#include "bird.h"
#include "uiDraw.h"

/***********************************************************************
 * Bird::Bird Constructor
 * This initializes the members of Bird
 **********************************************************************/
Bird::Bird()
{
   diamBird = 20;
   kill();
}

/*********************************************************************
 * CrasyBird
 * This function gives the bird an random sine wave like path
 *********************************************************************/
void CrasyBird(Vector & vector)
{
   Point point = vector.getPoint();
   vector.setDy(vector.getDy() + sin(random(0,6)));
}

/*********************************************************************
 * SquareBird
 * this function gives the bird a random square wave like path
 *********************************************************************/
void SquareBird(Vector & vector)
{
   // If neither of the vectors directions are 0, default dy to 0
   if ((vector.getDy() != 0 && vector.getDx() !=0))
   {
      vector.setDy(0);
   }
   Point point = vector.getPoint();
   // If we are moving vertically, change our direction to horizontal
   if (vector.getDy() != 0 && random(0,100) > 95)
   {
      float temp = vector.getDx();
      vector.setDx(vector.getDy());
      vector.setDy(temp);
   }
   // If we are moving horizontally, change to vertical movement
   else if (vector.getDx() != 0 && random(0,100) > 85)
   {
      float temp = vector.getDy();
      vector.setDy(vector.getDx());
      vector.setDx(temp);
   }
   
   // If the skeet is trying to advance off of the screen on the x
   // axis, reverse it's direction
   if (vector.getDx() + point.getX() < point.getXMin())
   {
      vector.setDx(-vector.getDx());
   }
   
}

/*********************************************************************
 * Jumper
 * This function gives the bird a teleporting jump
 *********************************************************************/
void Jumper (Vector & vector)
{
   // Randomly move the skeet forward random(1, 100) number of pixels
   if (random(0,100) > 95)
   {
      vector.getPoint().setX(vector.getPoint().getX() + random(1, 100));
   }
}

/***********************************************************************
 * Bird::Regenerate
 * Creates a new bird with a random y, dy and dx, and movement style
 **********************************************************************/
void Bird::regenerate(int level)
{
   dead = false;
   //move the bird all the way to the left
   vector.getPoint().setX(vector.getPoint().getXMin() + 1);
   
   //pick a random Y value between the top and bottom of the screen
   vector.getPoint().setY(random(vector.getPoint().getYMin() + 1,
                                 vector.getPoint().getYMax() + 1) );
   
   // Choose how to adjust the birds movement based on the level.
   // The higher the level, the more variety you get
   switch (random(0,level + 3) % 10)
   {
      case 0:
      case 1:
      case 2:
      case 3:
         adjMove = (AdjustMovement)0;
         break;
      case 4:
      case 5:
         adjMove = CrasyBird;
         break;
      case 6:
      case 7:
         adjMove = Jumper;
         break;
      case 8:
      case 9:
         adjMove = SquareBird;
         break;
   }
   
   //determine dx and dy based on the random y value
   if (vector.getPoint().getY() > 0)
      vector.setDy(random(-4, 0));
   else
      vector.setDy(random(0, 4));
   
   vector.setDx((float)random(3, 6) + ((level/2.0 + 3.0)));
   
   return;
}


/***********************************************************************
 * Bird::draw
 * Draws the bird
 **********************************************************************/
void Bird::draw()
{
   //draw the bird at the point

   drawCircle(vector.getPoint(), diamBird/2/*radius*/,
              20/*drawn points*/, 0 /*rotation*/);
   return;
}


/***********************************************************************
 * Bird::advance
 * Advances the bird. Bounces off the bottom
 **********************************************************************/
void Bird::advance()
{
   Point point = vector.getPoint();
   // Alter the birds position if it had a movement modifier
   if (adjMove)
   {
      adjMove(vector);
   }
   // Cause the bird to bounce when it hits the top or bottom of the
   // screen
   if (vector.getDy() + point.getY() > point.getYMax() ||
       vector.getDy() + point.getY() < point.getYMin())
   {
      vector.setDy(-vector.getDy());
   }
   
   // Move the bird
   vector.advance();
   
   return;
}


/***********************************************************************
 * Bird::isDead
 * Kills the bird if the bird goes off the screen, returns if it's dead or not.
 **********************************************************************/
bool Bird::isDead()
{
   //if we're off the screen, we're dead
   if (vector.getPoint().getX() > vector.getPoint().getXMax())
   {
      kill();
   }
   if (vector.getPoint().getY() > vector.getPoint().getYMax())
   {
      kill();
   }
   return dead;
   
}

/***********************************************************************
 * Bird::kill()
 * Kills the bird.
 **********************************************************************/
void Bird::kill()
{
   dead = true;
   return;
}

