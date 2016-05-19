/***********************************************************************
* Program:
*    RIFLE.H, Skeet
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

#ifndef Skeet__gun__
#define Skeet__gun__

#include "point.h"
#define ANGLE_MAX 90
#define ANGLE_MIN 0

/***********************************************************************
 * Rifle Class
 * Creates a rifle and everything needed to make it work
 **********************************************************************/
class Rifle
{
public:
   Rifle();
   void move(int goUp, int goDown);
   void draw();
   Point & getPoint()       { return point; }
   float getAngle()   const { return angle; }
   void setAngle(float tAngle) { angle = tAngle; }
   bool isDead() const {return dead;}
   void resurrect() { dead = false;}
   void kill()      { dead = true;}
private:
   Point point;
   float angle;
   bool dead;
};

#endif /* defined(__Skeet__gun__) */

