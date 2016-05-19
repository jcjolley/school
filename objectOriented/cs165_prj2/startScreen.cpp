/***********************************************************************
* Program:
*    STARTSCREEN.CPP, Skeet
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
#include "startScreen.h"
#include "uiInteract.h"
#include "uiDraw.h"

const std::string startMusic = "Skeet - Intro Music";


/***********************************************************************
 * StartScreen::StartScreen
 * Initializes the members of StartScreen
 **********************************************************************/
StartScreen::StartScreen()
{
   dead = false;
   
   //setup the starting positions of title and menu options
   ptStart.setX(-5);
   ptStart.setY(-5);
   
   ptHelp.setX(-5);
   ptHelp.setY(-35);
   
   ptTitle.setX(-30);
   ptTitle.setY(50);
   
   //get an instance of Game so we can start the music
   Game game;
   game.soundManager.load(startMusic, FMOD_LOOP_NORMAL);
   title = "Skeet";
   start = "Play";
   help = "Help";
   exit = "Quit";
   
}

/***********************************************************************
 * StartScreen::interact
 * If spacebar is pressed kill the StartScreen
 **********************************************************************/
void StartScreen::interact(const Interface ui)
{
   selector.move(ui.isUp(), ui.isDown());
   if(ui.isSpace())
   {
      kill();
   }
}

/***********************************************************************
 * StartScreen::kill
 * Kills the screen and ends the sound
 **********************************************************************/
void StartScreen::kill()
{
   dead = true;
   Game sound;
   sound.soundManager.stop(startMusic);
}

/***********************************************************************
 * StartScreen::advance
 * Keeps the sound playing
 **********************************************************************/
void StartScreen::advance()
{

   if (!dead) {
      Game sound;
      if (!sound.soundManager.isPlaying(startMusic))
         sound.soundManager.play(startMusic);
   }
}

/***********************************************************************
 * StartScreen::draw
 * Draws the members of StartScreen
 **********************************************************************/
void StartScreen::draw()
{
   //This bit of text here is to make the selector blink
   
   //make a timer and set it to 0
   static int counter = 0;
   
   //while we're a bit over halfway to 50
   if (counter < 30)
   {
      //draw the selector
      selector.draw();
      counter++;
   }
   
   //while we're eq to or over 30
   counter++;
   
   //don't draw and once we hit 50
   if (counter == 50)
      //start over
      counter = 0;
   
   //always draw the rest of the stuff
   drawText(ptStart, start.c_str(), 12);
   drawText(ptHelp, help.c_str(), 12);
   drawText(ptTitle, title.c_str());
   
   
}

/***********************************************************************
 * StartScreen::getSelectorY
 * returns the Y position of Selector.
 **********************************************************************/
int StartScreen::getSelectorY()
{
   //we use this function to determine what menu item we're on
   //which determines which scene to open when this dies
   return selector.getPoint().getY();
}