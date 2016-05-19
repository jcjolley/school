/***********************************************************************
* Program:
*    BULLET.H, Skeet
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



#ifndef Skeet_bullet_h
#define Skeet_bullet_h
#include "vector.h"

/***********************************************************************
 * Bullet Class
 * This class advances, fires, draws, etc a bullet
 **********************************************************************/
class Bullet
{
public:
   Bullet();
   void fire(float angle, int level);
   void draw();
   void advance();
   bool isDead();
   Vector & getVector() { return vector; }
   void kill();
   int getMaxRifleB() const {return maxRifleB;}
   int getMaxShotgunB() const {return maxShotgunB;}
   
private:
   Vector vector;
   bool dead;
   int maxRifleB;
   int maxShotgunB;
   float bullet_speed;
};

#endif
