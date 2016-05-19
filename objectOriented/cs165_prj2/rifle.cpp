/***********************************************************************
* Program:
*    RIFLE.CPP, Skeet
*    Brother Helfrich, CS165
* Author:
*    Sam Barney and Joshua Jolley
* Summary:
*    This program emulates the game of Skeet, complete with menus,
*    original sound, levels, and powerups.  
*    Estimated:  15.0 hrs
*    Actual:     30.0 hrs
*    Homing was difficult to implement well, and learning how to uses
*    classes and pass the right information between classes wwas,
*    well, a learning experience.
**********************************************************************/


#include "rifle.h"
#include "uiDraw.h"

/***********************************************************************
 * Rifle::Rifle Constructor
 * Initializes the members of rifle
 **********************************************************************/
Rifle::Rifle()
{
   
   //center the rifle in the lower right hand corner
   getPoint().setX(getPoint().getXMax() -1);
   getPoint().setY(getPoint().getYMin() +1);
   
   //default the gun to point in the middle.
   angle = 45.0;
   dead = false;
}

/***********************************************************************
 * Rifle::move
 * increases and decreases the angle of Rifle based on up or down
 **********************************************************************/
void Rifle::move(int up, int down)
{
   //up/down return 0 if false or the length of time
   //up/down has been pressed if true.
   if (down   && angle < ANGLE_MAX)
      angle += (down +   9) / (int)5;
   if (up && angle > ANGLE_MIN)
      angle -= (up + 9) / (int)5;
   if (angle > ANGLE_MAX)
      angle = ANGLE_MAX;
   if (angle < ANGLE_MIN)
      angle = ANGLE_MIN;
   
}

/***********************************************************************
 * Rifle::draw
 * Draws the members of rifle
 **********************************************************************/
void Rifle::draw()
{
   drawRect(getPoint() /*center*/,10/*width*/,40 /*length*/,getAngle() /*rotation*/);
}