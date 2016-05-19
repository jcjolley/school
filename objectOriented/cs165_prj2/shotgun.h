/***********************************************************************
* Program:
*    SHOTGUN.H, Skeet
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

#ifndef Skeet__shotgun__
#define Skeet__shotgun__

#include "point.h"
#define SHOTGUN_ANGLE_MAX 90
#define SHOTGUN_ANGLE_MIN 0

/***********************************************************************
 * Shotgun Class
 * Creates a shotgun and everything needed to make it work.
 **********************************************************************/
class Shotgun
{
public:
   Shotgun();
   void move(int goUp, int goDown);
   void draw();
   Point & getPoint()       { return point; }
   float getAngle(int numAngle)   const { return angle[numAngle]; }
   void setAngle (float tAngle) { angle[1] = tAngle; }
   bool isDead() const {return dead;}
   void resurrect() { dead = false;}
   void kill()      { dead = true;}
private:
   Point point;
   float angle[3];
   bool dead;
};

#endif /* defined(__Skeet__gun__) */

