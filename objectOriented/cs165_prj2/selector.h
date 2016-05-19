/***********************************************************************
* Program:
*    SELECTOR.H, Skeet
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
//
//  Selector.h
//  Skeet
//
//  Created by Joshua Jolley on 10/17/12.
//  Copyright (c) 2012 ImagineIt! Studios. All rights reserved.
//

#ifndef __Skeet__Selector__
#define __Skeet__Selector__

#include "point.h"

/***********************************************************************
 * Selector Class
 * Draws, advances, and moves a selector
 **********************************************************************/
class Selector
{
public:
   Selector();
   Point & getPoint() {return point;}
   void draw();
   void advance();
   void move(int up, int down);
   
private:
   Point point;
};

#endif /* defined(__Skeet__Selector__) */
