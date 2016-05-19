/***********************************************************************
 * Component:
 *    Grading
 * Summary:
 *    This component will deal with computing the grade for a student
 *    and converting number grades to letter grades
 ************************************************************************/

#include <cassert>    // as always
#include "grading.h"  // prototypes, etc.
using namespace std;

/*****************************************************************
 * COMPUTE AVERAGE
 * Compute the average taking -1s into account
 *
 * computeAverage
 *     FOR i = 1 to num by 1s 
 *        IF score[i] != -1
 *           sum += points[i] * scores[i]
 *           totalPoints += points[i] * 100
 *     IF totalPoints != 0
 *        RETURN sum / totalPoints
 *     ELSE
 *        RETURN -1
 *****************************************************************/
int computeAverage(const vector <Entry> & grades)
{
   int pointsEarned   = 0;
   int pointsPossible = 0;

   // loop through all the items in the points and scores array
   for (int i = 0; i < grades.size(); i++)
      // if he has completed this item, then add it to the points values
      if (grades[i].score != -1)
      {
         // paranoia
         assert(grades[i].points >= 0);
         assert(grades[i].score >= 0 && grades[i].score <= 100);

         // add the points to the possible list
         pointsEarned   += grades[i].points * grades[i].score;
         // and the points to the total list
         pointsPossible += grades[i].points;
      }

   // make the final computation
   return (pointsPossible == 0) ? -1 : pointsEarned / pointsPossible;
}

/********************************************************************
 * COMPUTE LETTER
 * Determine the letter grade from the number grade
 *
 * computeLetter
 *    return grades[average / 10]
 *******************************************************************/
char computeLetter(int average)
{
   //                0%  10%  20%  30%  40%  50%  60%  70%  80%  90%  100%
   char grades[] = {'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};

   assert(average >= 0 && average <= 100);
   
   return grades[average / 10];
}

/********************************************************************
 * COMPUTE SIGN
 * Determine the sign associated with a grade
 *
 * computeSign
 *    IF average >= 60 and average <= 93
 *      RETURN sign[average % 10]
 *    ELSE
 *      RETURN *
 *******************************************************************/
char computeSign(int average)
{
   //             ?0%  ?1%  ?2%  ?3%  ?4%  ?5%  ?6%  ?7%  ?8%  ?9%  
   char sign[] = {'-', '-', '-', '*', '*', '*', '*', '+', '+', '+'};
   assert(average >= 0 && average <= 100);

   return (average >= 60 && average <= 93) ? sign[average % 10] : '*';
}
