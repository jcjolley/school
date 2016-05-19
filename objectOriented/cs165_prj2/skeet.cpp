/***********************************************************************
* Program:
*    SKEET.CPP, Skeet
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




#include "skeet.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include <cassert>
const std::string shotgunSound = "shotgun";
const std::string rifleSound = "rifle";
const std::string gameplayMusic = "Skeet - Gameplay Music";
const std::string powerupHit = "Powerup";
const std::string deathSound = "Lost Life";
int Skeet::homingCount = 500;
int Skeet::shotgunCount = 750;


/***********************************************************************
 * Skeet::Skeet Constructor
 * Initializes the members of skeet
 **********************************************************************/
Skeet::Skeet() : Game()
{
   //intialize score,life,totalbirds
   totalBirds.setScore(0);
   score.setScore(0);
   lives.setScore(10);
   
   //put the total points in the left hand corner
   totalBirds.getPoint().setX(totalBirds.getPoint().getXMin() + 1);
   totalBirds.getPoint().setY(totalBirds.getPoint().getYMax() - 1);
   
   //set the points
   lives.getPoint().setY(lives.getPoint().getYMax()-1);
   lives.getPoint().setX(10);
   ptNumLives.setY(ptNumLives.getYMax() - 10);
   ptNumLives.setX(-30);
   
   //load music/sound effects
   soundManager.load(shotgunSound);
   soundManager.load(rifleSound);
   soundManager.load(gameplayMusic);
   soundManager.load(powerupHit);
   soundManager.load(deathSound);
   
   //initialize the rest of the members
   bullets = new Bullet[9];
   availableBullets = 9;
   level = 1;
   numLives = "Lives:";
   homing = false;
   
}

/***********************************************************************
 * Skeet::reset
 * Resets the members back to their starting values
 **********************************************************************/
void Skeet::reset()
{
   totalBirds.setScore(0);
   score.setScore(0);
   lives.setScore(10);
   availableBullets = 9;
   level = 1;
   homing = false;
   shotgun.kill();
   rifle.resurrect();
   
}

/***********************************************************************
 * Skeet::interact
 * Checks for input, fires the rifle, moves the rifle, etc. based on input
 **********************************************************************/
void Skeet::interact(const Interface ui)
{
   int fired = 0;
   //if the rifle is alive
   if (!rifle.isDead())
   {
      //move the rifle
      rifle.move(ui.isUp(), ui.isDown());
      
      //if space is pressed and we have a bullet to fire
      if (ui.isSpace() && availableBullets > 0)
         //loop through the bullets
         for (int i = 0; i < bullets[1].getMaxRifleB(); i++)
         {
            //find the available bullet
            if (bullets[i].isDead())
            {
               fired++;
               //FIRE AWAY!
               bullets[i].fire(rifle.getAngle(), level);
               break; //stop here because we found a bullet
            }
         }
      if (fired)
      {
         soundManager.play(rifleSound);
      }
   }
   
   //do the same thing as rifle but with shotgun if the shotgun is alive
   if (!shotgun.isDead())
   {
      //move the shotgun
      shotgun.move(ui.isUp(), ui.isDown());
      //if space is pressed and we have enough bullets for a full shot
      if (ui.isSpace() && availableBullets > 2)
      {
         //loop through the bullets
         for (int i = 0; i < bullets[1].getMaxShotgunB(); i++)
         {
            //find an available bullet
            if (bullets[i].isDead())
          {
             //Fire!!
             bullets[i].fire(shotgun.getAngle(fired), level);
             fired++;
             if (fired == 3)
             {
                //after we've got 3 bullets, we stop.
                break;
             }
          }
         }
      }
      if (fired)
      {
         //if we fired the gun we need the sound effect!
         soundManager.play(shotgunSound);
      }
   }
}

/***********************************************************************
 * Skeet::advance
 * Advances the bullets, birds, powerups etc. Checks for collision
 **********************************************************************/
void Skeet::advance()
{
   //lets get the music going!
   if (!soundManager.isPlaying(gameplayMusic))
   {
      soundManager.play(gameplayMusic);
   }
   // Default available bullets to 0
   availableBullets = 0;
   //Unleash the kracken! ...er... move the bullets.
   for (int i = 0; i < 9; i++)
   {
      //setup vectors so we can tell when they hit things
      Vector biV = bird.getVector();
      Vector buV = bullets[i].getVector();
      
      //if a bullet is alive
      if (!bullets[i].isDead())
      {
         //advance the bullet if they're not homing
         if (!homing)
            bullets[i].advance();
         
         /* Homing was a doozy.  The idea: Check to see where the bird is in 
          in relation to the bullet. Then, adjust dx and dy by a percentage of
          distance between the bird and the bullet */
         if (homing)
         {
            //get the difference
            int difference = bird.getVector() - bullets[i].getVector();
            
            //divide by 100 to get numbers that help us change Dx/Dy
            float dChange = (float)(difference / 100.0);
            
            // This is to help the bullet catch the bird when it gets close
            // without this it just follows the bullet around and never
            // catches it
            if (dChange < 2)
               dChange = 2;
            
            //Check the bird's position in relation to the bullet and adjust
            //dy/dx accordingly
            if (!bird.isDead() && bird.getVector().getPoint().getX() >
                bullets[i].getVector().getPoint().getX())
               bullets[i].getVector().setDx(bullets[i].getVector().getDx() / 1.1
               /*the bird is to the right, add to dx */       + 1 * dChange);
            if (!bird.isDead() && bird.getVector().getPoint().getX() <
                bullets[i].getVector().getPoint().getX() )
               bullets[i].getVector().setDx(bullets[i].getVector().getDx() / 1.1
               /*the bird is to the left, take away from dx*/ + 1 * -dChange);
            if (!bird.isDead() && bird.getVector().getPoint().getY() >
                bullets[i].getVector().getPoint().getY() )
               bullets[i].getVector().setDy(bullets[i].getVector().getDy() / 1.1
               /*the bird is above, add to dy*/               + 1 * dChange);
            if (!bird.isDead() && bird.getVector().getPoint().getY() <
                bullets[i].getVector().getPoint().getY() )
               bullets[i].getVector().setDy(bullets[i].getVector().getDy() / 1.1
               /*the bird is below, take away from dy*/      + 1 * -dChange);
            //after we've adjust dx/dy, advance the bullet
            bullets[i].advance();
            
         }
         
         if (!bird.isDead())
            //if, we hit something in the new spot
            if (bird.getSize() > (bird.getVector() - bullets[i].getVector())
                && bird.getVector() - bullets[i].getVector() > 0)
            {
               bird.kill();     //BA-DA-DUM DUM DUM, another one bites the dust!
               
               bullets[i].kill();
               // Increment the available bullets counter
               availableBullets++;
               score++;            //yes please.
               
               //Random chance to spawn a shotgun powerup
               if (random(0,5) == 2)
                  shotgunPowerup.regenerate(bird.getVector().getPoint().getX(),
                                            bird.getVector().getPoint().getY(),
                                            level);
               //Random chance to spawn a homing powerup
               if (random(0,5) == 1)
                  homingPowerup.regenerate(bird.getVector().getPoint().getX(),
                                           bird.getVector().getPoint().getY(),
                                           level);
            }
         
         //if there is a powerup
         if (!shotgunPowerup.isDead())
            //and we hit it
            if (shotgunPowerup.getSize() > (shotgunPowerup.getVector() -
                bullets[i].getVector()) && shotgunPowerup.getVector() -
                bullets[i].getVector() > 0)
            {
               //get rid of the bullet
               bullets[i].kill();
               //make another bulelt available
               availableBullets++;
               //get rid of the powerup
               shotgunPowerup.kill();
               //turn off the rifle
               rifle.kill();
               if (!shotgun.isDead()) //already got the shotgun? +1 life/score!
                  score++;
               //get the angle of the rifle and pass it to shotgun
               shotgun.setAngle(rifle.getAngle());
               //bring the shotgun to life
               shotgun.resurrect();
               //set the timer for shotgun
               shotgunCount = 750;
               //play a congradulatory sound effect!
               soundManager.play(powerupHit);
               
               
            }
         
         //if there is a homing powerup
         if (!homingPowerup.isDead())
         {
            //and we hit it
            if (homingPowerup.getSize() > (homingPowerup.getVector() -
                bullets[i].getVector()) && homingPowerup.getVector() -
                bullets[i].getVector() > 0)
            {
               //get rid of the bullet
               bullets[i].kill();
               //make a bullet available
               availableBullets++;
               //get rid of the powerup
               homingPowerup.kill(); //already homing? +1 life/score!
               if (homing)
                  score++;
               //set homing to true
               homing = true;
               //start the homing timer
               homingCount = 500;
               //play a congradulatory sound effect!
               soundManager.play(powerupHit);
            }
         }
      }
      else
      {
         // Increment the available bullets counter if the bullet is dead
         availableBullets++;
      }
   }

   //if our bird bit the dust
   if (bird.isDead())
   {
      if (random(0, 30) == 0) //wait for approx 1 second
      {
         bird.regenerate(level);   //toss out another bird
         totalBirds++;
         lives.setScore(11 - (totalBirds.getScore() - score.getScore()));
      }
   }
   else
      bird.advance();
   
   //if there is a shotgunPowerup, advance it
   if (!shotgunPowerup.isDead())
      shotgunPowerup.advance();
   //if there is a homingPowerup, advance it
   if (!homingPowerup.isDead())
      homingPowerup.advance();
   
   //set the level
   level = score.getScore() / 5;
   
   //if you're out of lives end the game
   if (lives.getScore() <= 0)
      kill();
   
   //if we're homing we need to decrement the timer for homing
   if (homing)
      {
         if (homingCount > 0)
            homingCount--;
         else
            //if time is up, end homing
            homing = false;
      }
   
   //if you've got the shotgun we need to decrement the timer for shotgun
   if (!shotgun.isDead())
   {
      
      if (shotgunCount > 0)
         shotgunCount--;
      else
      {
         //if time is up swap back to the rifle
         shotgun.kill();
         //transfer the angle for a smooth transition
         rifle.setAngle(shotgun.getAngle(1));
         rifle.resurrect();
      }
   }
}

/***********************************************************************
 * Skeet::kill
 * Kills the skeet scene
 **********************************************************************/
void Skeet::kill()
{
   dead = true;
   soundManager.stop(gameplayMusic);
}


/***********************************************************************
 * Skeet::draw
 * Draws the members of skeet
 **********************************************************************/
void Skeet::draw()
{
   //only draw thinigs if they're alive
   if (!rifle.isDead())
      rifle.draw();
   if (!shotgun.isDead())
      shotgun.draw();
   if (!bird.isDead())
      bird.draw();
   if (!shotgunPowerup.isDead())
      shotgunPowerup.draw();
   if (!homingPowerup.isDead())
      homingPowerup.draw();
   
   //draw the bullets!
   for (int i = 0; i < 9; i++)
   {
      if (!bullets[i].isDead())
         bullets[i].draw();
   }
   score.draw();
   totalBirds.draw();
   lives.draw();
   //this is the text next to the lives count
   drawText(ptNumLives, numLives.c_str(), 1);
   
}

/***********************************************************************
 * Skeet::~Skeet() Destructor
 * deletes the dynamically allocated members of Skeet
 **********************************************************************/
Skeet::~Skeet()
{
   delete [] bullets;
}
