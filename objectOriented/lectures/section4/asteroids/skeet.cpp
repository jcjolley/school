/***********************************************************************
 * Program:
 *    Skeet. Play the wonderful Skeet game using OpenGL
 * Author:
 *    Br. Grimmett
 * Summary:

 ***********************************************************************/

#include "point.h"         // Objects have a position
#include "vector.h"        // Objects have a vector 
#include "gameEntities.h"  // The Ball, Bird, Bullet, and Rifle Classes
#include "uiInteract.h"    // interface with OpenGL
#include "uiDraw.h"        // all the draw primitives exist here
#include <iostream>        // Used only for debugging
using namespace std;


// set the bounds of the game
float Point::xMin = -128.0;
float Point::xMax =  128.0;
float Point::yMin = -128.0;
float Point::yMax =  128.0;

// Set the Number of bullets available
#define NUM_BULLETS 5
// Set the size of the Bird
#define BIRD_SIZE 20

/*****************************************
 * Skeet - Here the class descriptor
 ****************************************/
class Skeet
{
public:
   Skeet();                             // set up the game
   void draw();                         // draw everything
   void interact(const Interface *pUi); // Handle the key presses
   void advance();                      // Advance the game
private:
   Bird bird;                           // The Bird class 
   Bullet bullets[NUM_BULLETS];         // The Bullet class
   Rifle rifle;                         // The Rifle class
   int hit;                             // Holds the score of hits
   int missed;                          // Holds the score of misses
};

/***************************************************
 * Skeet:: CONSTRUCTOR
 * Set the hit and misses to 0
 * Randomly set the x position of the bird
 * Randomly set the y speed of the bird
 ***************************************************/
Skeet::Skeet()
{
   hit = 0;
   missed = 0;

   bird.setX(bird.getXMin() + 1.0);
   bird.setDx(4.0);
   bird.setDy((float)random(-2, 2));

};

/********************************************
 * Skeet :: ADVANCE
 * Move all the objects forward
 *******************************************/
void Skeet::advance()
{
   // advance the bullets if they are alive
   for (int i = 0; i < NUM_BULLETS; i++)
      if (!bullets[i].isDead())
         bullets[i].advance();

    // if the bird is dead, resurrect the bird at some random time
   if (bird.isDead())
   {
      if (0 == (random(0, 30)))
         bird.regenerate();
   }
   else
   {
      // advance the bird
      if (bird.advance())
      {
         //  Add one to score, because the bird just went off the screen
         missed++;
      }
   }
   // check to see if the bullet struck the bird, as long as the bird is alive
   if (!bird.isDead())
      for (int i = 0; i < NUM_BULLETS; i++)
      {
         // Make sure the bullet is alive, then make sure the position
         // of the bullet and bird are within the bird's size
         if (!bullets[i].isDead())
            if ((BIRD_SIZE > abs((bullets[i].getX() - bird.getX()))) &&
                (BIRD_SIZE > abs((bullets[i].getY() - bird.getY()))))
            {
               // Kill the bird, and the bullet.
               bird.kill();
               bullets[i].kill();
               i = NUM_BULLETS;
               // Add one to the score
               hit++;
            }
      }
}


/**************************************************
 * Skeet : Interact
 * Send the key presses to the right objects
 *************************************************/
void Skeet::interact(const Interface *pUI)
{
   // move the rifle
   rifle.move(pUI->isUp()   + pUI->isRight(),
              pUI->isDown() + pUI->isLeft());

   // shoot a bullet
   if (pUI->isSpace())
   {
      // Space bar pressed, so start up a bullet, if one is available(dead)
      
      for (int i = 0; i < NUM_BULLETS; i++)
         if (bullets[i].isDead())
         {
            // Fire the bullet, sending the current angle of the rifle
            bullets[i].fire(rifle.getAngle());
            i = NUM_BULLETS;
         }
   }
   
}

/*************************************************
 * Skeet : DRAW
 * Draw all the objects that need to be drawn
 ************************************************/
void Skeet::draw()
{
   // draw the rifle
   rifle.draw();

   // draw the bird
   bird.draw();

   // draw the bullets if they are alive
   for (int i = 0; i < NUM_BULLETS; i++)
      if (!bullets[i].isDead())
         bullets[i].draw();

   // put the score on the screen
   static const Point point;
   Point pointHit(point.getXMin() + 2, point.getYMax() - 2);
   Point pointMiss(point.getXMax() - 30, point.getYMax() - 2);
   drawNumber(pointHit, hit);
   drawNumber(pointMiss, missed);
  
}

/*********************************************
 * CALLBACK
 * The main interaction loop of the engine.
 * This gets called from OpenGL.  It give us our
 * interface pointer (where we get our events from)
 * as well as a void pointer which we know is our
 * game class.
 *********************************************/
void callBack(const Interface *pUI, void *p)
{
   // we know the void pointer is our game class so
   // cast it into the game class.
   Skeet *pSkeet = (Skeet *)p;

   // Send the key presses to the interact function
   pSkeet->interact(pUI);
   // Advance all the objects that might move or change state
   pSkeet->advance();
   // draw all the objects that need to be drawn
   pSkeet->draw();
}


/*********************************
 * MAIN
 * initialize the drawing window, initialize
 * the game,and run it!
 *********************************/
int main(int argc, char **argv)
{
   // Start the drawing
   Interface ui(argc, argv, "Skeet");

   // play the game.  Our function callback will get called periodically
   Skeet skeet;  
   ui.run(callBack, (void *)&skeet);

   return 0;
}
