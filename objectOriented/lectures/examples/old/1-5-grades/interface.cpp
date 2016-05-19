/***********************************************************************
 * Component:
 *    Interface
 * Summary:
 *    All user-facing functionality.
 ************************************************************************/

#include <iostream>       // output done here
#include <iomanip>        // formatted output
#include <cassert>        // as always
#include "interface.h"    // implement these interfaces
#include "grading.h"      // for compute grade stuff

using namespace std;

// prototypes for this file only.  They are not externally facing
char getOption();
int getIndex(int num);
bool changeDescription(vector <Entry> & grades);
bool changePoints(vector <Entry> & grades);
bool changeScore(vector <Entry> & grades);
bool clearScore(vector <Entry> & grades);
void display(const vector <Entry> & grades);



/*******************************************************************
 * INTERACT
 * User Interface.  Display the options and prompt the user for his
 * choice.  Based on his choice, select one of many operations.  Keep
 * going until the use selects 'quit'
 *
 * interact()
 *     display()
 *     while not done
 *        SWITCH getOption()
 *           n : changeDescription()
 *           p : changePoints()
 *           s : changeScore()
 *           c : clearScore()
 *           d : display()
 *           q : done = true
 ******************************************************************/
void interact(vector <Entry> & grades)
{
   // display the scores the first time
   display(grades);

   // continue looping until the user indicates he is finished
   bool done = false;
   while (!done)
   {
      bool success = true;   // default success.  We are optimistic
      switch (getOption())
      {
         case 'n':
            success = changeDescription(grades);
            break;
         case 'p':
            success = changePoints(grades);
            break;
         case 's':
            success = changeScore(grades);
            break;
         case 'c':
            success = clearScore(grades);
            break;
         case 'd':
            display(grades);
            break;
         case 'q':
            done = true;    // time to quit
            break;
         default:
            success = false;   // unknown command
      }

      // if an error occured, inform the user
      if (!success)
         cout << "Error processing that command\n";
   }
   
   return;
}


/*********************************************************************
 * GET OPTION
 * Give the user a menu of options and prompt him for his selection.
 * Make sure the results is lowercase
 *
 * getOption()
 *     PROMPT with options
 *     GET option
 *     return lowercase option
 ********************************************************************/
char getOption()
{
   // display all the options
   cout << "Options:\n";
   cout << "\t(n) : Change the name of an item\n";
   cout << "\t(p) : Change the number of points an item is worth\n";
   cout << "\t(s) : Change the earned score on an item\n";
   cout << "\t(c) : Clear the score on an item\n";
   cout << "\t(d) : Display the grade list again\n";
   cout << "\t(q) : Quit\n";

   // prompt for option
   char option;
   cout << "> ";
   cin  >> option;

   return tolower(option);
}


/***********************************************************
 * CHANGE DESCRIPTION
 * Change the description on a grade item
 *
 * changeDescription()
 *    index = getIndex()
 *    PROMPT for description
 *    GET description
 **********************************************************/
bool changeDescription(vector <Entry> & grades)
{
   // get the index
   int i = getIndex(grades.size());
   if (i == -1)
      return false;
   
   //   get the data
   assert(i >= 0 && i < grades.size());
   cout << "What is the new name: ";
   cin  >> grades[i].description;

   return true;
}

/***********************************************************
 * CHANGE POINTS
 * Change the points on a grade item
 *
 * changePoints()
 *    PROMPT for index
 *    GET index
 *    PROMPT for points
 *    GET points
 **********************************************************/
bool changePoints(vector <Entry> & grades)
{
   // get the index
   int i = getIndex(grades.size());
   if (i == -1)
      return false;
   
   // get the data
   int tmp;
   cout << "What is the new points: ";
   cin  >> tmp;

   // validate the score
   if (tmp >= 0)
   {
      assert(i >= 0 && i < grades.size());
      grades[i].points = tmp;
      return true;
   }
   return false;
}

/***********************************************************
 * CHANGE SCORE
 * Change the score on a grade item
 *
 * changePoints()
 *    i = getIndex
 *    IF  index = -1
 *        RETURN error
 *    PROMPT for score
 *    GET tmp
 *    IF tmp >= 0 and tmp <= 100
 *        score[i] <-- tmp
 *        RETURN true
 *    RETURN false
 *********************************************************/
bool changeScore(vector <Entry> & grades)
{
      // get the index
   int i = getIndex(grades.size());
   if (i == -1)
      return false;
   
   // get the data
   int tmp;
   cout << "What is the new score: ";
   cin  >> tmp;

   // validate the score
   if (tmp >= 0 && tmp <= 100)
   {
      assert(i >= 0 && i < grades.size());
      grades[i].score = tmp;
      return true;
   }
   return false;
}

/********************************************************
 * CLEAR SCORE
 * Remove the score earned for a given record.  Set it to -1
 *
 * clearScore
 *   GET index
 *   scores[index] = -1
 *******************************************************/
bool clearScore(vector <Entry> & grades)
{
   // paranoia
   assert(grades.size() >= 0);

   // fetch the index
   int i = getIndex(grades.size());
   if (i == -1)
      return false;
   assert(i >= 0 && i < grades.size());

   grades[i].score = -1;
   assert(grades[i].score == -1);
   return true;
}

/****************************************************************
 * GET INDEX
 * Prompt the user for an index and validate it
 *
 * getIndex()
 *    PROMPT for index
 *    GET index
 *    IF index > num or index < 0
 *      ERROR
 ****************************************************************/
int getIndex(int num)
{
   // get the index
   int index;
   cout << "Which item do you want to edit? ";
   cin  >> index;

   // convert to 0 base because humans talk in 1 base.
   index--;

   // validate to make sure that the index is in bounds
   return (index < 0 || index >= num) ? -1 : index;
}
   

/*********************************************************************
 * DISPLAY
 * Display the list of records to the user
 *
 * display()
 *     DISPLAY header
 *     FOR 1 to num
 *        DISPLAY i, descriptions[i], points[i]
 *        IF score[i] = -1
 *           DISPLAY empty
 *        ELSE
 *           DISPLAY score[i]
 *     average = getAverage()
 *     letter  = getLetter()
 *     sign    = getSign()
 *     DISPLAY average, letter, sign
 *******************************************************************/
void display(const vector <Entry> & grades)
{
   // instructions
   cout << "Your grades are:\n";

   // header
   cout << "\tNumber            Name Points Score\n";
   cout << "\t====== =============== ====== =====\n";

   // loop through all the recoreds
   for (int i = 0; i < grades.size(); i++)
   {
      cout << "\t"
           << setw(6)  << i + 1
           << setw(16) << grades[i].description
           << setw(7)  << grades[i].points;
      if (grades[i].score != -1)
         cout << setw(5) << grades[i].score
              << "%\n";
      else
         cout << "    --\n";
   }

   // trailing row
   int average = computeAverage(grades);
   cout << "\t====== =============== ====== =====\n";
   cout << "\t       Total                   ";

   // grade
   if (average != -1)
   {
      char letter = computeLetter(average);
      char sign   = computeSign(  average);

      cout << setw(3) << average << "% "
           << letter;
      if (sign != '*')
         cout << sign;
      cout << endl;
   }
   else
      cout << "  --\n";
}
