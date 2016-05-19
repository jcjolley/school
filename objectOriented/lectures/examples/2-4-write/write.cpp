/***********************************************************************
 * This file implements the WRITE interface, a class
 *      designed to write data to a file
 ************************************************************************/

#include "write.h"               // need the class definitions
using namespace std;             // much more convenient that using std::

/**********************************************
 * WRITE :: WRITE
 * Connect to the output stream
 **********************************************/
Write::Write(const string & fileName) : isOpen(false)
{
   fout.open(fileName.c_str());
   isOpen = !(fout.fail());
}

/***********************************************
 * WRITE :: WRITE TO FILE
 * Sent the passed text to the file
 **********************************************/
void Write::writeToFile(const string & text)
{
   if (isOpen)
      fout << text << endl;
}

/**********************************************
 * WRITE :: ~WRITE
 * Close the output stream if it is open
 **********************************************/
Write::~Write()
{
   if (isOpen)
      fout.close();
}
