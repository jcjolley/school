/***********************************************************************
 * Header
 *    Grading
 * Summary:
 *    This component will deal with computing the grade for a student
 *    and converting number grades to letter grades
 ************************************************************************/

#ifndef GRADING_H
#define GRADING_H

#include <vector>        // because grades are vectors ...
#include "grades.h"      // .. of Entries

// Compute the average grade taking missing assignments and
// weighting into account
int computeAverage(const std::vector <Entry> & grades);

// Compute the letter grade
char computeLetter(int average);

// Compute the grade sign
char computeSign(int average);

#endif // GRADING_H
