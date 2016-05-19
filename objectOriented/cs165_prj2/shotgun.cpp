/***********************************************************************
* Program:
*    SHOTGUN.CPP, Skeet
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


#include "shotgun.h"
#include "uiDraw.h"


/***********************************************************************
 * Shotgun::Shotgun Constructor
 * Initializes the members of shotgun
 **********************************************************************/
Shotgun::Shotgun()
{
   
   //center the rifle in the lower right hand corner
   getPoint().setX(getPoint().getXMax() -1);
   getPoint().setY(getPoint().getYMin() +1);
   
   //default the gun to point in the middle.
   angle[1] = 45.0;
   angle[0] = angle[1] - 1;
   angle[2] = angle[1] + 1;
   dead = true;
}

/***********************************************************************
 * Shotgun::move
 * Increases or Decreases the angle based on up or down
 **********************************************************************/
void Shotgun::move(int up, int down)
{
   //up/down return 0 if false or the length of time
   //up/down has been pressed if true.
   if (up   && angle[1] <= SHOTGUN_ANGLE_MAX)
   {
      angle[1] -= (up +   9) / (int)5;
   }
   
   if (down && angle[1] >= SHOTGUN_ANGLE_MIN)
   {
      angle[1] += (down + 9) / (int)5;
   }
   if (angle[1] > SHOTGUN_ANGLE_MAX)
   {
      angle[1] = SHOTGUN_ANGLE_MAX;
   }
   if (angle[1] < SHOTGUN_ANGLE_MIN)
   {
      angle[1] = SHOTGUN_ANGLE_MIN;
   }
   angle[0] = angle[1] - 5;
   angle[2] = angle[1] + 5;
   
}

/***********************************************************************
 * Shotgun::draw
 * Draws the members of Shotgun
 **********************************************************************/
void Shotgun::draw()
{
   drawRect(getPoint() /*center*/,15 /*width*/,50 /*length*/,getAngle(1) /*rotation*/);
}