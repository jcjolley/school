/**********************************************************************
* Program:
*    Assignment 14, STL
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
* Summary:
*    This program reads a file line by line and then displays the lines
*    in reverse order on screen.
*    
*    Estimated:  1.0 hrs   
*    Actual:     0.75 hrs
*      Making styleChecker happy (I'm working on it as much as I can!)
************************************************************************/

#include <iostream>
#include <cassert>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

#ifdef DEBUG
#define debug(x) cout << #x << ": " << x << endl;
#else
#define debug(x)
#endif

void displayBackwards(const vector <string> &lines);
void readFile(vector <string> &lines);

/**********************************************************************
* Main is our driver program.  We should call him Mr. Escolade
***********************************************************************/
int main()
{
   vector <string>  lines;
   list <string> words;
   map <int, string> stuff;
   readFile(lines);
   displayBackwards(lines);
   return 0;
}

/**********************************************************************
 * displayBackwards
 * displays the strings stored in lines in reverse order
 **********************************************************************/
void displayBackwards(const vector <string> &lines) 
{
   int start = 0;
   int end = lines.size();
   while (start < end)
   {
      end--;
      cout << lines[end] << endl;
   }
         
}

/**********************************************************************
 * readFile
 * reads the file line by line into a vector of strings 
 **********************************************************************/
void readFile(vector <string> &lines)
{
   string filename;
   string line;
   cout << "Enter the name of the file: ";
   cin  >> filename;
      
   ifstream fin(filename.c_str());
   if (fin.fail())
   {
      cout << "Error: The file could not be opened.\n";
      return;
   }
   
   while (getline(fin, line))
   {
      
      lines.push_back(line);
   }
   fin.close();    
}
