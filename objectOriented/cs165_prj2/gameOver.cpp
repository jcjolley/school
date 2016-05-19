/***********************************************************************
* Program:
*    GAMEOVER.CPP, Skeet
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
#include "gameOver.h"
#include "uiDraw.h"
#include <fstream>
#include <algorithm>
using namespace std;

int GameOver::loadRunTimes = 0;
int GameOver::saveRunTimes = 0;
int GameOver::gameOverTimer = 500;
const std::string gameOverMusic = "Skeet - GameOver Music";


/***********************************************************************
 * GameOver::GameOver Constructor
 * This function is a constructor for GameOver.
 **********************************************************************/
GameOver::GameOver()
{
   ptGameOver.setY(200);
   ptGameOver.setX(-50);
   ptYourScore.setY(80);
   ptYourScore.setX(-80);
   score.getPoint().setX(30);
   score.getPoint().setY(89);
   ptHighScores.setY(65);
   ptHighScores.setX(-80);
   ptNum1.setY(50);
   ptNum1.setX(0);
   ptNum2.setY(20);
   ptNum2.setX(0);
   ptNum3.setY(-10);
   ptNum3.setX(0);
   
   // Initilize our high scores
   highScore = new Score[3];
   
   highScore[0].getPoint().setY(59);
   highScore[0].getPoint().setX(30);
   
   highScore[1].getPoint().setY(29);
   highScore[1].getPoint().setX(30);
   
   highScore[2].getPoint().setY(-1);
   highScore[2].getPoint().setX(30);
   
   // Set the position of the restart menu item
   ptResetText.setY(-70);
   ptResetText.setX(-10);
   
   // Set the initial selector point
   selector.getPoint().setY(-67);
   selector.getPoint().setX(-25);
   
   // Default the highscores to 0
   highScore[0].setScore(0);
   highScore[1].setScore(0);
   highScore[2].setScore(0);
   
   // Setup everything else
   dead = true;
   gameOver = "Game Over";
   yourScore = "Your score is:";
   highScores = "Highscores:";
   num1 = "#1";
   num2 = "#2";
   num3 = "#3";
   resetText = "Restart";
   
   // Load the music for the game over screen
   Game game;
   game.soundManager.load(gameOverMusic, FMOD_LOOP_NORMAL | FMOD_2D);
}

/***********************************************************************
 * GameOver::interact
 * This function checks to see if the user hits space.  If so it 
 * resets the game and takes you back to the start screen.
 **********************************************************************/
void GameOver::interact(const Interface ui, Skeet & skeet,
                        StartScreen & startScreen)
{
   // If the user chose to restart the game
   if (ui.isSpace())
   {
      // Disable the game over screen
      kill();
      // Reset the skeet scene and start screen
      skeet.reset();
      startScreen.resurrect();
      skeet.resurrect();
      gameOverTimer=500;
      
      // Reset our counters for loading and saving of highscores
      loadRunTimes = 0;
      saveRunTimes = 0;
   }
}

/***********************************************************************
 * GameOver::advance
 * This function loads the saves your score, loads the high scores, and
 * if you've been on this scene long enough, restarts the game.
 **********************************************************************/
void GameOver::advance(int yScore, Skeet & skeet, StartScreen & startScreen)
{
   // If the music isn't playing, play it.
   Game game;
   if (!game.soundManager.isPlaying(gameOverMusic))
   {
      game.soundManager.play(gameOverMusic);
   }
   
   // Set the score
   score.setScore(yScore);
   
   // If this is the first time that this has been run, save and load
   // the high scores
   if (saveRunTimes == 0)
      saveScore(score);
   if (loadRunTimes == 0)
      loadScore(highScore);
   if (!isDead())
   {
      // If we are on the game over screen and the user hasn't selected
      // anything, decrement the timer.
      // Otherwise, return to the main screen.
      if (gameOverTimer > 0)
         gameOverTimer--;
      else
      {
         kill();
         skeet.reset();
         startScreen.resurrect();
         skeet.resurrect();
         gameOverTimer = 500;
         loadRunTimes = 0;
         saveRunTimes = 0;
      }
   }
}

/***********************************************************************
 * GameOver::draw()
 * This function draws everything in GameOver: Text, scores, selector, etc.
 **********************************************************************/
void GameOver::draw()
{
   // Draw the text on the screen;
   drawText(ptGameOver, gameOver.c_str());
   drawText(ptYourScore, yourScore.c_str(), 1);
   drawText(ptHighScores, highScores.c_str(), 1);
   drawText(ptNum1, num1.c_str(), 1);
   drawText(ptNum2, num2.c_str(), 1);
   drawText(ptNum3, num3.c_str(), 1);
   drawText(ptResetText, resetText.c_str(), 1);
   
   static int counter = 0;
   
   // Flash the selector
   if (counter < 40)
   {
      selector.draw();
      counter++;
   }
   counter++;
   if (counter == 50)
      counter = 0;
   
   // Draw the score the user got
   score.draw();
   
   // Draw all of the high scores
   for (int i = 0; i < 3; i++)
      highScore[i].draw();
   
   
}

/***********************************************************************
 * GameOver::saveScore
 * This function saves your score to the list of scores
 **********************************************************************/
void GameOver::saveScore(Score & score)
{
   
   ofstream fout("highScoresList", fstream::app);
   
   if (fout.fail())
   {
      cerr << "the file could not be opened for writing\n";
   }
   else
   {
      fout << score.getScore() << " ";
      fout.close();
      saveRunTimes = 7;
   }
   return;
}

/***********************************************************************
 * GameOver::loadScore
 * Loads every score into a vector, sorts the vector, and sets the top
 * 3 scores to highScore
 **********************************************************************/
void GameOver::loadScore(Score *highScore)
{
   ifstream fin("highScoresList");
   
   // Return early if we can't open the highscore file.
   if (fin.fail())
   {
      std::cerr<< "the file could not be opened for reading\n";
      return;
   }
   int temp = 0;
   // Load every single highscore into the highscore vector
   while(!fin.fail())
   {
      fin >> temp;
      
      if (temp != 0)
      {
         scores.push_back(temp);
         temp = 0;
      }
   }
   
   
   // Sort the highscores from lowest to highest
   sort (scores.begin(), scores.end());
   
   // Make sure that we arn't grabbing the last highscore which always
   // is 0
   int sizeIndex = scores.size() - 1;
   
   // Insert the top three highscores
   for (int highScoreIndex = 0; highScoreIndex < 3; highScoreIndex++)
   {
      if (sizeIndex >= 0)
      highScore[highScoreIndex].setScore(scores[sizeIndex--]);
      scores.pop_back();
   }
   
   // Set our flag so that we do not run this again
   loadRunTimes = 1;
}


/***********************************************************************
 * GameOver::~GameOver Destructor
 * This function deletes the dynamically allocated members of GameOver
 **********************************************************************/
GameOver::~GameOver()
{
   delete [] highScore;
}

void GameOver::kill()
{
   dead = true;
   Game game;
   // Stop the game over music
   game.soundManager.stop(gameOverMusic);
}