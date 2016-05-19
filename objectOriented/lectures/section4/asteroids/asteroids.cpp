/***********************************************************************
 * Program:
 *    Asteroids. Play the wonderful Asteroids game using OpenGL
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

#define NUM_BIG_ROCKS 2
#define NUM_MEDIUM_ROCKS 4
#define NUM_SMALL_ROCKS 8
#define NUM_ROCKS 14

/*****************************************
 * Skeet - Here the class descriptor
 ****************************************/
class Asteroids
{
public:
   Asteroids();                             // set up the game
   void draw();                         // draw everything
   void interact(const Interface *pUi); // Handle the key presses
   void advance();                      // Advance the game
private:
   Ship ship;                           // The Bird class 
   Bullet bullets[NUM_BULLETS];         // The Bullet class
   Target *rocks[NUM_ROCKS];// The Rocks
   BigRock bigRock[NUM_BIG_ROCKS];
   MediumRock mediumRock[NUM_MEDIUM_ROCKS];
   SmallRock smallRock[NUM_SMALL_ROCKS];
   int hit;                             // Holds the score of hits
   int miss;
};

/***************************************************
 * Asteroids:: CONSTRUCTOR
 * Set the hit and misses to 0
 * Set the x position of the ship to 0
 * Set the y position of the ship to 0
 ***************************************************/
Asteroids::Asteroids()
{
   hit = 0;
   miss = 0;

   Target *ptrRock = bigRock;
   for (int i = 0; i < NUM_BIG_ROCKS; i++)
      rocks[i] = ptrRock++;
      
   ptrRock = mediumRock;
   for (int i = NUM_BIG_ROCKS; i < NUM_BIG_ROCKS + NUM_MEDIUM_ROCKS; i++)
   {
      ptrRock->kill();
      rocks[i] = ptrRock++;
   }

   
   ptrRock = smallRock;
   for (int i = NUM_BIG_ROCKS + NUM_MEDIUM_ROCKS; i < NUM_ROCKS; i++)
   {
      ptrRock->kill();
      rocks[i] = ptrRock++;
   }
   
};

/********************************************
 * Asteroids :: ADVANCE
 * Move all the objects forward
 *******************************************/
void Asteroids::advance()
{
   
   // advance the bullets if they are alive
   for (int i = 0; i < NUM_BULLETS; i++)
      if (!bullets[i].isDead())
         bullets[i].advance();

    // if the ship is dead, resurrect the ship
   if (ship.isDead())
   {
      for (int i = 0; i < NUM_ROCKS; i++)
      {
         if (!((rocks[i]->getSize() > abs((rocks[i]->getX() - ship.getX())) &&
                (rocks[i]->getSize() > abs((rocks[i]->getY() - ship.getY()))))))
            ship.regenerate(NO_POINT, NO_POINT);
         
      }
   }
   else
      ship.advance();

   for (int i = 0; i < NUM_ROCKS; i++)
      if (!rocks[i]->isDead())
         rocks[i]->advance();
      else
      {
         if (rocks[i]->getSize() == SIZE_BIG_ROCK)
            if (0 == (random(0, 30)))
            {
               rocks[i]->regenerate(NO_POINT, NO_POINT);
               if ((rocks[i]->getSize() > abs((rocks[i]->getX() - ship.getX()))) &&
                   (rocks[i]->getSize() > abs((rocks[i]->getY() - ship.getY()))))
                  rocks[i]->kill();
            }
      }
   
   // check to see if the target struck the ship, as long as the ship is alive
   if (!ship.isDead())
      for (int i = 0; i < NUM_ROCKS; i++)
      {
         // Make sure the bullet is alive, then make sure the position
         // of the target and ship are within the bird's size
         if (!rocks[i]->isDead())
            if ((rocks[i]->getSize() > abs((rocks[i]->getX() - ship.getX()))) &&
                (rocks[i]->getSize() > abs((rocks[i]->getY() - ship.getY()))))
            {
               ship.kill();
               rocks[i]->kill();
               i = NUM_ROCKS;
               //    Add one to the score
               miss++;
            }
      }

   
   for (int j = 0; j < NUM_BULLETS; j++)
   {
      if (!bullets[j].isDead())
         for (int i = 0; i < NUM_ROCKS; i++)
         {
            // Make sure the bullet is alive, then make sure the position
            // of the target and ship are within the target's size
            if (!rocks[i]->isDead())
               if ((rocks[i]->getSize() > abs((bullets[j].getX() - rocks[i]->getX())))
                   && (rocks[i]->getSize() > abs((bullets[j].getY() - rocks[i]->getY()))))
               {
                  if (rocks[i]->getSize() == SIZE_BIG_ROCK)
                  {
                     //                      Kill the rock and the bullet. \n";
                     bullets[j].kill();
                     rocks[i]->kill();
                     hit++;
                     rocks[i * 2 + 2]->regenerate(rocks[i]->getX(), rocks[i]->getY());
                     rocks[i * 2 + 3]->regenerate(rocks[i]->getX(), rocks[i]->getY());
                  }
                  else if (rocks[i]->getSize() == SIZE_MEDIUM_ROCK)
                  {
                     //                      Kill the rock and the bullet. \n";
                     bullets[j].kill();
                     rocks[i]->kill();
                     hit++;
                     rocks[i * 2 + 2]->regenerate(rocks[i]->getX(), rocks[i]->getY());
                     rocks[i * 2 + 3]->regenerate(rocks[i]->getX(), rocks[i]->getY());
                                 
                  }
                  else
                  {
//                      Kill the rock and the bullet. \n";
                     bullets[j].kill();
                     rocks[i]->kill();
//                  i = NUM_ROCKS;
                  // Add one to the score
                     hit++;
                  }
               }
         }
   }
   
}


/**************************************************
 * Asteroids : Interact
 * Send the key presses to the right objects
 *************************************************/
void Asteroids::interact(const Interface *pUI)
{
   // move the rifle
   ship.move(pUI->isRight(), pUI->isLeft(), pUI->isUp());

   // shoot a bullet
   if (pUI->isSpace())
   {
      // Space bar pressed, so start up a bullet, if one is available(dead)
      
      for (int i = 0; i < NUM_BULLETS; i++)
         if (bullets[i].isDead())
         {
            // Fire the bullet, sending the current angle of the ship
            bullets[i].fire(ship.getAngle(), ship.getX(), ship.getY());
            i = NUM_BULLETS;
         }
   }
   
}

/*************************************************
 * Asteroids : DRAW
 * Draw all the objects that need to be drawn
 ************************************************/
void Asteroids::draw()
{
   // draw the rifle
   ship.draw();

   // draw the bullets if they are alive
   for (int i = 0; i < NUM_BULLETS; i++)
      if (!bullets[i].isDead())
         bullets[i].draw();

   for (int i = 0; i < NUM_ROCKS; i++)
      if (!rocks[i]->isDead())
         rocks[i]->draw();
   
   // put the score on the screen
   static const Point point;
   Point pointHit(point.getXMin() + 2, point.getYMax() - 2);
   Point pointMiss(point.getXMax() - 30, point.getYMax() - 2);
   
   drawNumber(pointHit, hit);
   drawNumber(pointMiss, miss);
   
  
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
   Asteroids *pAsteroids = (Asteroids *)p;

   // Send the key presses to the interact function
   pAsteroids->interact(pUI);
   // Advance all the objects that might move or change state
   pAsteroids->advance();
   // draw all the objects that need to be drawn
   pAsteroids->draw();
}


/*********************************
 * MAIN
 * initialize the drawing window, initialize
 * the game,and run it!
 *********************************/
int main(int argc, char **argv)
{
   // Start the drawing
   Interface ui(argc, argv, "Asteroids");

   // play the game.  Our function callback will get called periodically
   Asteroids asteroids;  
   ui.run(callBack, (void *)&asteroids);

   return 0;
}
