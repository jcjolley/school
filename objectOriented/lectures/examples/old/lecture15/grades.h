/***********************************************************************
 * Header
 *    Grades
 * Summary:
 *    This header file defines the format for a single grade entry
 ************************************************************************/

#ifndef GRADES_H
#define GRADES_H

#include <string>

// A single grade entry
struct Entry
{
   std::string description;   // textual description of the grade entry
   int points;                // how many points is the entry worth?
   int score;                 // earned score in percent
};

#endif // GRADES_H
