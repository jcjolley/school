/***********************************************************************
* Program:
*    Lecture 1.5, Grades Program
*    Brother Helfrich, CS165
* Author:
*    Br. Helfrich
* Summary: 
*    This program will keep track of a student's grades in a given class.
*    The data will be stored in a file so potentially the grades for many
*    classes can be tracked at the same time.  
************************************************************************/

#include <iostream>    // simple I/O
#include <cassert>     // as always
#include "grades.h"    // description of each grade entry
#include "file.h"      // to read/write to the file
#include "interface.h" // to allow the program to interact with the user
using namespace std;

// Create a blank grade list
int newList(vector <Entry> & grades);


/**********************************************************************
 * MAIN
 * create/open the file, let the user interact with the data, then write
 * the results when finished.
 *
 * main()
 *    getName()
 *    num = readFile()
 *    IF num = 0
 *      num = newFile()
 *    interact()
 *    writeFile()
 ***********************************************************************/
int main()
{
   // get the filename
   string fileName;
   getName(fileName);
      
   // read the file
   vector <Entry> grades;
   int  num = readFile(fileName, grades);
   if (0 == num)
      num = newList(grades);
   
   // allow the user to interact with the grades data
   interact(grades);

   // write the new data to the disk
   if (!writeFile(fileName, grades))
      cout << "Error writing to file " << fileName << endl;
   
   return 0;
}

/***************************************************************
 * NEW LIST
 * create a new score list from scratch
 *
 * newFile
 *     PROMPT for number of scores
 *     GET num
 *     FOR 1 to num
 *       GET description[i]
 *       SET points[i] = 100
 *       SET scores[i] = -1
 ***************************************************************/
int newList(vector <Entry> & grades)
{
   // prompt for number of scores
   int num;
   do
   {
      cout << "How many records are in the file? ";
      cin  >> num;
   }
   while (num <= 0);
   assert(num > 0);
   
   // loop through all the records
   for (int i = 0; i < num; i++)
   {
      Entry entry;
      cout << "Description for #" << i + 1 << ": ";
      cin  >> entry.description;
      entry.points = 100;
      entry.score = -1;
      grades.push_back(entry);
   }
   
   // return the number saved
   return num;
}

