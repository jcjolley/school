/***********************************************************************
* Header
*    File
* Summary: 
*    This component will deal with file interfaces for a grading program
************************************************************************/

#ifndef FILE_H
#define FILE_H

#include <string>    // filenames come in as strings
#include <vector>    // grades are vectors of data
#include "grades.h"  // where grade entries are defined

// How to read grades from a file
int readFile(const std::string & fileName,          // target filename
             std::vector <Entry> & grades);         // list of grades

// How to write grades to a file
int writeFile(const std::string & fileName,         // source filename
              const std::vector <Entry> & grades);  // list of grades

// prompt the user for a filename
void getName(std::string & fileName);

#endif // FILE_H
