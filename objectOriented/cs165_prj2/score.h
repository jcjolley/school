/***********************************************************************
* Program:
*    SCORE.H, Skeet
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
#ifndef __Skeet__score__
#define __Skeet__score__

#include "point.h"

/***********************************************************************
 * Class Score
 * This class creates a score displaying object
 **********************************************************************/
class Score
{
public:
   Score();
   Point & getPoint()   { return point; }
   int getScore()            const { return score; }
   void addScore()                  { score++; }
   void setScore(int score)         { this->score = score; }
   void draw();
   Score & operator ++ ();
   Score operator ++ (int postfix);
   
private:
   int score;
   Point point;
   
};
#endif /* defined(__Skeet__score__) */
