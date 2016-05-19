/***********************************************************************
* Program:
*    HELPSCREEN.CPP, Skeet
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

#include "helpScreen.h"
#include "uiDraw.h"

/***********************************************************************
 * HelpScreen::HelpScreen Constructor
 * Sets up the text and points for everything in HelpScreen
 **********************************************************************/
HelpScreen::HelpScreen()
{
   dead = false;
   helps = new std::string[8];
   ptHelps = new Point[8];
   
   // Set the menu item names
   title = "Help";
   back = "Back";

   // Set the help screen text
   helps[0] = "You'll need all the help you can get.";
   
   helps[1] = "This game is designed to emulate the marksman's game of Skeet. ";
   helps[1] +="Aim with up arrow and down ";
   helps[2] = "arrow, fire with spacebar. You have 10 lives, and lose a life ";
   helps[2] +="every time a bird escapes. ";
   
   helps[3] +="You can have up to 5 shots on screen at one time. Shooting ";
   helps[3] +="power-up bubbles grants";
   helps[4] = "special powers. ";
   
   helps[5] = "Shotgun Power-up:  Changes your rifle into a shotgun that ";
   helps[5] +="fires 3 bullets at a time and can have";
   helps[6] ="3 shots on screen at one time. ";
   
   helps[7] = "Homing Power-up:  Makes your bullets home in on birds.  Does ";
   helps[7] +="not home in on power-ups";
   
   // Set the position of the help screen title
   ptTitle.setX(-20);
   ptTitle.setY(230);
   
   // Set the position for all of the help screen texts.
   ptHelps[0].setX(-90);
   ptHelps[0].setY(200);
   ptHelps[1].setX(-260);
   ptHelps[1].setY(170);
   ptHelps[2].setX(-260);
   ptHelps[2].setY(155);
   ptHelps[3].setX(-260);
   ptHelps[3].setY(140);
   ptHelps[4].setX(-260);
   ptHelps[4].setY(125);
   ptHelps[5].setX(-260);
   ptHelps[5].setY(100);
   ptHelps[6].setX(-260);
   ptHelps[6].setY(85);
   ptHelps[7].setX(-260);
   ptHelps[7].setY(60);
   
   // Set the position of the back menu item
   ptBack.setX(0);
   ptBack.setY(-5);
   
   // Set the mosition of the menu selector
   selector.getPoint().setX(-10);
   
   // Place the powerup images
   shotgunPowerup.getVector().setDy(0);
   shotgunPowerup.getVector().getPoint().setX(-280);
   shotgunPowerup.getVector().getPoint().setY(100);
   
   homingPowerup.getVector().setDy(0);
   homingPowerup.getVector().getPoint().setX(-280);
   homingPowerup.getVector().getPoint().setY(65);
}

/***********************************************************************
 * HelpScreen::interact
 * If space is pressed he screen and its objects are killed and you are
 * sent back to the start screen
 **********************************************************************/
void HelpScreen::interact(const Interface ui, StartScreen & startScreen)
{
   // If spacebar was hit, return to the main screen
   if(ui.isSpace())
   {
      startScreen.resurrect();
      kill();
      shotgunPowerup.kill();
      homingPowerup.kill();
   }
}

/***********************************************************************
 * HelpScreen::draw
 * Draws all of the objects in the HelpScreen
 **********************************************************************/
void HelpScreen::draw()
{
   // Draw all of the text for the help screen
   for (int i = 0; i < 8; i++)
      drawText(ptHelps[i], helps[i].c_str(), 1);
   
   // Draw the title
   drawText(ptTitle, title.c_str());
   
   // Draw the menu items
   drawText(ptBack, back.c_str(), 1);
   
   // Draw the powerup images
   shotgunPowerup.draw();
   homingPowerup.draw();
   
   static int counter = 0;
   
   // Make the selector flash
   if (counter < 40)
   {
      selector.draw();
      counter++;
   }
   counter++;
   if (counter == 50)
      counter = 0;
   
   return;
}

/***********************************************************************
 * HelpScreen::~HelpScreen Destructor
 * Deletes the dynamically allocated members of HelpScreen
 **********************************************************************/
HelpScreen::~HelpScreen()
{
   delete [] ptHelps;
   delete [] helps;
}