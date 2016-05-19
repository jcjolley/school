/***********************************************************************
* Program:
*    SELECTOR.CPP, Skeet
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
#include "selector.h"
#include "uiDraw.h"

/***********************************************************************
 * Selector::Selector Constructor
 * Initializes the member variables of Selector
 **********************************************************************/
Selector::Selector()
{
   point.setX(-20);
   point.setY(0);
}

/***********************************************************************
 * Selector::draw
 * Draws the selector
 **********************************************************************/
void Selector::draw()
{
   drawShip(point, 180);
}

/***********************************************************************
 * Selector::move
 * Moves the selector
 **********************************************************************/
void Selector::move(int up, int down)
{
   if(up && point.getY() < 0)
      point.setY(0);
   if (down && point.getY() > -30)
      point.setY(-30);
}
