/***********************************************************************
* Program:
*    SCENE.CPP, Skeet
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
#include "scene.h"


/***********************************************************************
 * Scene::Interact
 * This function determines which scene is currently taking input from
 * the user
 **********************************************************************/
void Scene::interact(const Interface ui)
{
   // If we are on the start screen, interact with it.
   if(!startScreen.isDead())
   {
      startScreen.interact(ui);
      helpScreen.resurrect();
   }
   // If we are on the help screen, interact with it
   else if (!helpScreen.isDead() && startScreen.getSelectorY() == -30)
   {
      helpScreen.interact(ui, startScreen);
    
   }
   // If we are on the level screen, interact with it
   else if(!levelScreen.isDead())
   {
      levelScreen.interact(ui);
   }
   // If we are playing the game, interact with it
   else if(!skeet.isDead() && startScreen.getSelectorY() == 0)
   {
      skeet.interact(ui);
   }
   // Otherwise, game over
   else
   {
      gameOver.interact(ui, skeet, startScreen);
   }
      
}


/***********************************************************************
 * Scene::advance
 * This function determines which scene is being advanced
 **********************************************************************/
void Scene::advance()
{
   Game sound;
   
   // Advance the start screen if we are on it.
   if(!startScreen.isDead())
   {
      startScreen.advance();
   }
   // Otherwise
   else
   {
      // Update the level screen
      levelScreen.advance(skeet.getScore().getScore());
      // Advance the sceet game if we are playing and not
      // on the level screen
      if (levelScreen.isDead() && !skeet.isDead() &&
          startScreen.getSelectorY() == 0)
         skeet.advance();
      // If we are on the gameOver screen, set the scores.
      if (!gameOver.isDead())
          gameOver.getScore().setScore(skeet.getScore().getScore());
      // If we lost the game, advance the game over screen.
      if (skeet.isDead())
         gameOver.advance(skeet.getScore().getScore(), skeet, startScreen);
   }
}


/***********************************************************************
 * Scene::draw
 * This function determines which scene is being drawn
 **********************************************************************/
void Scene::draw()
{
   // Draw each screen as they come up.
   if(!startScreen.isDead())
   {
      startScreen.draw();
   }
   else if (!helpScreen.isDead() && startScreen.getSelectorY() == -30)
      helpScreen.draw();
   else if(!levelScreen.isDead())
      levelScreen.draw(skeet.getScore().getScore());
   else if(skeet.getLives().getScore() <= 0)
      gameOver.draw();
   else
   {
      skeet.draw();
   }
}