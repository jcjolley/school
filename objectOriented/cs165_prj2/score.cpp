/***********************************************************************
* Program:
*    SCORE.CPP, Skeet
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
#include "score.h"
#include "uiDraw.h"


/***********************************************************************
 * Score::Score Constructor
 * initializes the members of score
 **********************************************************************/
Score::Score()
{
   point.setX(point.getXMax() - 20); //digit is 7 pixels wide
   point.setY(point.getYMax() - 1);
   setScore('0');
   
}

/***********************************************************************
 * Score::draw
 * draws the members of score
 **********************************************************************/
void Score::draw()
{
   drawNumber(point, score);
}

/***********************************************************************
 * Score::operator++
 * Overloads the ++ operator to work with score
 **********************************************************************/
Score & Score::operator++()
{
   this->addScore();
   return *this;
}

/***********************************************************************
 * Score::operator++ postfix
 * Overloads the ++ operator to work with score (postfix)
 **********************************************************************/
Score Score::operator ++ (int postfix)
{
   Score temp(*this);
   this->addScore();
   return temp;
}