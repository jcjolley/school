/***********************************************************************
 * This program is designed to demonstrate:
 *      Test the write.h class
 ************************************************************************/

#include <iostream>             // for cin and cout
#include <string>               // for the filename
#include "write.h"              // to get the Write class
using namespace std;

/**********************************************************************
* This will be just a simple driver program 
***********************************************************************/
int main()
{
   // get the filename
   string fileName;
   cout << "What is the filename? ";
   cin  >> fileName;

   // open the connection
   Write write(fileName);

   // Write some text
   write.writeToFile(string("Hello world\n"));

   // don't bother closing it!
   return 0;
}
