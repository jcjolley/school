/***********************************************************************
* Program:
*    BIRD.H, Skeet
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



#ifndef Skeet_bird_h
#define Skeet_bird_h
#include "vector.h"
typedef void (*AdjustMovement)(Vector & vector);


/***********************************************************************
 * Bird Class
 * This class advances and draws the bird, complete with craSy
 * movement styles. (Crazy is more fun to say with a spanish accent)
 **********************************************************************/
class Bird
{
public:
   Bird();
   void regenerate(int level);
   void draw();
   void advance();
   bool isDead();
   Vector & getVector() { return vector; }
   int getSize()  const { return diamBird; }
   void kill();
private:
   Vector vector;
   bool dead;
   int diamBird;   //diameter of the bird;
   AdjustMovement adjMove;
};


#endif
