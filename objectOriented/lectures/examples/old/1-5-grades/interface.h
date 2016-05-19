/***********************************************************************
* Header
*    Interface
* Summary: 
*     All user-facing functionality.
************************************************************************/

#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>    // grades are vectors of data
#include "grades.h"  // where grade entries are defined

// Main interaction function 
void interact(std::vector <Entry> & grades);

#endif // FILE_H
