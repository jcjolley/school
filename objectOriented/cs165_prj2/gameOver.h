/***********************************************************************
* Program:
*    GAMEOVER.H, Skeet
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
#ifndef __Skeet__gameOver__
#define __Skeet__gameOver__

#include "uiInteract.h"
#include "point.h"
#include "score.h"
#include <string>
#include <vector>
#include "skeet.h"
#include "startScreen.h"
#include "uiDraw.h"
#include "selector.h"


/***********************************************************************
 * GameOver Class
 * This is the GameOver scene.  Displays current score, 3 high scores, 
 * and gives the option to restart the game.
 **********************************************************************/
class GameOver
{
public:
   GameOver();
   ~GameOver();
   void interact(const Interface ui, Skeet & skeet, StartScreen & startScreen);
   void advance(int yScore, Skeet & skeet, StartScreen & startScreen);
   void draw();
   bool isDead() const {return dead;}
   void kill();
   Score & getScore() { return score;}
   void saveScore (Score & score);
   void loadScore (Score *highScore);
private:
   bool dead;
   std::string gameOver;
   std::string yourScore;
   std::string highScores;
   std::string num1;
   std::string num2;
   std::string num3;
   std::vector <int> scores;
   std::string resetText;
   
   Point ptGameOver;
   Point ptYourScore;
   Point ptHighScores;
   Point ptNum1;
   Point ptNum2;
   Point ptNum3;
   Point ptResetText;
   Score score;
   Score  *highScore;
   Selector selector;
   
   static int loadRunTimes;
   static int saveRunTimes;
   static int gameOverTimer;
};

#endif /* defined(__Skeet__gameOver__) */
