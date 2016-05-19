/***********************************************************************
 * Program:
 *    Pong. What?  you never heard of pong?
 * Author:
 *    Br. Helfrich
 * Summary:
 *    OK, I couldn't help myself.  The first video game is "Tennis for Two"
 *    developed in 1958 (you read that correctly) by William Higinbotham
 *    as a demo for the computer systems in the Brookhaven National Laboratory.
 *    The display was a normal oscilloscope.  Ours will use slighly more
 *    advanced graphics: OpenGL
 ***********************************************************************/

#include "point.h"       // the ball has a position
#include "uiInteract.h"  // interface with OpenGL
#include "uiDraw.h"      // all the draw primitives exist here

#define PADDLE 20

// set the bounds of the game
float Point::xMin = -128.0;
float Point::xMax =  128.0;
float Point::yMin = -128.0;
float Point::yMax =  128.0;

/*****************************************
 * PONG
 * The main pong structure containing everything
 * necessary to plan our beloved game
 ****************************************/
class Pong
{
public:
   Pong();                          // set up the game
   void advance();                  // advance the game by one move
   void draw();                     // draw everything
   void move(int up, int down);     // move everything
   void strike();                   // did we hit something?
private:
   Point ball;   // ball position
   float dx;     // horizontal velocity of the ball
   float dy;     // vertical velocity of the ball
   bool dead;    // is the game over?
   int score;    // current score.. how many times did we hit the ball?
   Point paddle; // location of the paddle
};

/***************************************************
 * PONG :: CONSTRUCTOR
 * Give the ball a random vertical velocity and set
 * the positions of everything else.
 ***************************************************/
Pong::Pong() : ball(), dead(false), score(0), paddle()
{
   ball.setX(ball.getXMin() + 1.0);
   dx = 4.0;
   dy = (float)random(-2, 2);
   paddle.setX(paddle.getXMax() - 1.0); 
};

/********************************************
 * PONG :: ADVANCE
 * Move the ball forward by some amount
 *******************************************/
void Pong::advance()
{
   // gravity.. just for fun!
//   dy -= .2;
   
   // woops, we missed the ball!
   if (ball.getX() + dx > ball.getXMax() - 1.0)
      dead = true;

   // bounce off the back wall
   else if (ball.getX() + dx < ball.getXMin() + 1.0)
   {
      ball.setX(ball.getXMin() + 1.0);
      dx *= -1.0;
   }

   // bounce off the ceiling
   else if (ball.getY() + dy > ball.getYMax() - 1.0)
   {
      ball.setY(ball.getYMax() - 1.0);
      dy *= -1.0;
   }

   // and off the floor
   else if (ball.getY() + dy < ball.getYMin() + 1.0)
   {
      ball.setY(ball.getYMin() + 1.0);
      dy *= -1.0;
   }
   else
   {
      ball.setX(ball.getX() + dx);
      ball.setY(ball.getY() + dy);
   }
}

/****************************************
 * STRIKE
 * Strike the paddle.  The further from the center,
 * the more it hits
 ****************************************/
void Pong::strike()
{
   // ball not at the paddle yet
   if (ball.getX() + dx < ball.getXMax() - 2.0)
      return;

   // missed!
   float distance = ball.getY() - paddle.getY();
   if (fabs(distance) > PADDLE)
      return;

   //
   // yeah, we hit the ball
   //
   
   // hit.  Change the dx direction.
   dx *= -1.0;
   ball.setX(ball.getXMax() - 1.0);

   // get some score
   score++;

   // speed up every 5 points
   if (score % 5 == 0)
      dx += -1.0;

   // the dy is changed by the angle.
   dy += distance / 5;
}

/**************************************************
 * PONG : MOVE
 * Move the paddle
 *************************************************/
void Pong::move(int up, int down)
{
   if (up && paddle.getY() < paddle.getYMax())
      paddle.addY( 5);
   if (down && paddle.getY() > paddle.getYMin())
      paddle.addY(-5);
}

/*************************************************
 * PONG : DRAW
 * Draw the stuff
 ************************************************/
void Pong::draw()
{
   // draw the ball and the paddle
   drawRect(paddle, 2, PADDLE * 2, 0);

   // draw the ball
   if (!dead)
      drawCircle(ball, 4, 12, 0);

   // draw the score
   Point point(ball.getXMin() + 5, ball.getYMax() - 5);
   drawNumber(point, score);
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
   Pong *pPong = (Pong *)p;

   // advance the ball
   pPong->advance();

   // check the paddle
   pPong->move(pUI->isUp(), pUI->isDown());

   // did we hit the ball?
   pPong->strike();

   // draw it
   pPong->draw();
}


/*********************************
 * MAIN
 * initialize the drawing window, initialize
 * the game,and run it!
 *********************************/
int main(int argc, char **argv)
{
   // Start the drawing
   Interface ui(argc, argv, "Pong!");

   // play the game.  Our function callback will get called periodically
   Pong pong;  
   ui.run(callBack, (void *)&pong);

   return 0;
}
