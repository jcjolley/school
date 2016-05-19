/***********************************************************************
* Component:
*    File
* Summary: 
*    This component will deal with file interfaces for a grading program
************************************************************************/

#include <fstream>   // for accessing the file system
#include <cassert>   // as always
#include <iomanip>   // to format the data in the file
#include <iostream>  // to promtp the user for the filename
#include "file.h"    // prototypes, etc.

using namespace std;

/*****************************************************************
 * READ FILE
 * Read data from the file in the following format:
 *    <numItems>
 *    <name1> <points1> <score1>
 *    <name2> <points2> <score2>
 *
 * writeFile
 *    openFile
 *    SAVE num
 *    FOR 1 to num
 *       WRITE description[i] points[i] scores[i]
 *    closeFile
 **********************************************************/
int readFile(const string & fileName, vector <Entry> & grades)
{
   int num = 0;
   assert(fileName != string(""));

   // open the file
   ifstream fin(fileName.c_str());
   if (fin.fail())
      return 0;
   
   // read the number of records
   fin >> num;
   assert(num > 0);
   if (fin.fail())
      return 0;
   
   // read each record
   int i;
   for (i = 0; i < num && !fin.eof(); i++)
   {
      Entry entry;
      fin >> entry.description
          >> entry.points
          >> entry.score;
      grades.push_back(entry);
   }

   // bail if there are not the expected number of items in the file.
   if (i != num)
      return 0;
   
   // close the file
   fin.close();
   return num;
}

/***********************************************************
 * WRITE FILE
 * Write the data to the file in the same format as readFile:
 *    <numItems>
 *    <name1> <points1> <score1>
 *    <name2> <points2> <score2>
 *
 * writeFile
 *    openFile
 *    SAVE num
 *    FOR 1 to num
 *       SAVE description[i] points[i] scores[i]
 *    closeFile
 **********************************************************/
int writeFile(const string & fileName, const vector <Entry> & grades)
{
   assert(fileName != string(""));

   // open the file for writing
   ofstream fout(fileName.c_str());
   if (fout.fail())
      return false;
   
   // write the number of records
   fout << grades.size() << endl;
   
   // write each record out in the file
   for (int i = 0; i < grades.size(); i++)
      fout << setw(10)
           << grades[i].description << " \t"
           << grades[i].points      << " \t"
           << grades[i].score       << endl;
   
   // close the file
   fout.close();

   cout << "File saves successfully\n";   
   return true;
}


/******************************************************************
 * GET NAME
 * Prompt the user for the filename
 *
 * getName
 *   PROMPT for fileName
 *   GET fileName
 *****************************************************************/
void getName(string & fileName)
{
   cout << "What is the filename of the grades file? ";
   cin  >> fileName;

   return;
}
