/***********************************************************************
* Program:
*    LEVELSCREEN.CPP, Skeet
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
#include "Game.h"
#include "levelScreen.h"
#include "uiDraw.h"
#include <cstdio>

const std::string gameMusic = "Skeet - Gameplay Music";

int LevelScreen::runTimes = 0;

/***********************************************************************
 * LevelScreen::LevelScreen Constructor
 * This function sets up all the points and text for LevelScreen
 **********************************************************************/
LevelScreen::LevelScreen()
{
   // Set the position to draw the level at
   ptLevel.setX(-40);
   ptLevel.setY(70);
   
   // Set the position to draw each of the tips at
   ptTips = new Point[10];
   ptTips[0].setX(-70);
   ptTips[1].setX(-80);
   ptTips[2].setX(-81);
   ptTips[3].setX(-90);
   ptTips[4].setX(-130);
   ptTips[5].setX(-100);
   ptTips[6].setX(-95);
   ptTips[7].setX(-110);
   ptTips[8].setX(-130);
   ptTips[9].setX(-120);
   
   // Set the initial displayed level to 1
   level[6] = '1';
   dead = false;
   level = "Level ";
   tips = new std::string[10];
   
   // Initialize the tips
   tips[0] = "Press spacebar to continue.";
   tips[1] = "The S power-up grants a shotgun.";
   tips[2] = "Power-ups only last a short time.";
   tips[3] = "The H power-up grants homing bullets";
   tips[4] = "Hitting a power-up you already have grants a life.";
   tips[5] = "The rifle has 5 shots. Try spamming them.";
   tips[6] = "The shotgun has 3 shots. Aim Carefully.";
   tips[7] = "Shooting a power-up bubble grants the power-up.";
   tips[8] = "As you advance in level birds and bullets speed up.";
   tips[9] = "In later levels birds get harder flight patterns.";
}

/***********************************************************************
 * LevelScreen::interact
 * If space is pressed kill the level screen
 **********************************************************************/
void LevelScreen::interact(const Interface ui)
{
   if(ui.isSpace())
      kill();
}

/***********************************************************************
 * LevelScreen::advance
 * Advances the level screen.
 **********************************************************************/
void LevelScreen::advance(int score)
{
   if(score / 5 == runTimes)
   {
      runTimes++;
      resurrect();
      // Set the current level
      if (score > 4)
      {
         setLevel(score / 5 + 1);
         // Stop the game music
         Game game;
         game.soundManager.stop(gameMusic);
      }
      
      else
         setLevel(1);
         
      
   }
}

/***********************************************************************
 * LevelScreen::draw
 * Draws the members of LevelScreen
 **********************************************************************/
void LevelScreen::draw(int numLevel)
{
   // Draw the current level and the tip associated with it
   drawText(ptLevel, level.c_str());
   drawText(ptTips[(numLevel / 5) % 10], tips[(numLevel / 5) % 10].c_str(), 1);
}

/***********************************************************************
 * LevelScreen::setLevel
 * Sets the level to be displayed
 **********************************************************************/
void LevelScreen::setLevel(int numLevel)
{
   
   // If the level is less than 10, insert it into the level string
   // followed by a null character
   if (numLevel < 10)
   {
      level[6] = numLevel + '0';
      level[7] = '\0';
   }
   // Otherwise, insert the tens place, then the single digits followed
   // by a null character
   else
   {
      level[6] = numLevel / 10 + '0';
      level[7] = numLevel % 10 + '0';
        level[8] = '\0';
   }
     
}

/***********************************************************************
 * LevelScreen::~LevelScreen Destructor
 * Deletes the dynamically allocated members of LevelScreen
 **********************************************************************/
LevelScreen::~LevelScreen()
{
   delete [] ptTips;
   delete [] tips;
}
