/*************************************************************************
*    This program is designed to:
*       Display the contents of a file backwards on the screen.
*       In reality it is just an exercise in vectors and strings.
************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool readFile(const string &fileName, vector <string> &contents);
string getFilename();
void display(const vector <string> & contents);

/**********************************************************************
 * Read the contents and display it. 
 ***********************************************************************/
int main()
{
   vector <string> contents;

   // open the filename
   if (!readFile(getFilename(), contents))
   {
      cout << "Unable to open the file\n";
      return 1;
   }

   // display it
   display(contents);
   
   return 0;
}

/*********************************************
 * READ FILE: Read the contents of fileName into contents
 *   INPUT:  fileName: the name of the file
 *   OUTPUT: contents: where it is all stored
 *********************************************/
bool readFile(const string &fileName, vector <string> &contents)
{
   ifstream fin(fileName.c_str());
   if (fin.fail())
      return false;

   // read it all
   string s;
   while (getline(fin, s))
      contents.push_back(s);

   // call it done!
   fin.close();
   return true;
}

/******************************************
 * GET FILENAME: Prompt the user for the filename
 *   INPUT:  <none>
 *   OUTPUT: string containing the filename
 ******************************************/
string getFilename()
{
   string s;
   cout << "Enter the name of the file: ";
   cin  >> s;
   return s;
}

/********************************************
 * DISPLAY: show the contents of the file backwards
 *  INPUT:  contents
 *  OUTPUT: <none>
 ********************************************/
void display(const vector <string> & contents)
{
   for (int i = contents.size() - 1; i >= 0; i--)
      cout << contents[i] << endl;
}

