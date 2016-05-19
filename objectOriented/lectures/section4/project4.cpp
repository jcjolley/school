/***********************************************************************
* Program:
*    Assignment ##, ???? 
*    Brother Helfrich, CS165
* Author:
*    your name
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int readFile(vector <string> &nameList)
{
   ifstream input;
   string getName;
   int size;
   
   input.open("studentList.txt");

   input >> size;

   for (int i = 0; i < size; i++)
   {
      getline(input, getName);

      if (i == 0)
         nameList.push_back(getName);
      else
      {
         bool inserted = false;
         for (int j = 0; j < nameList.size(); j++)
            if (getName < nameList[j])
            {
               nameList.insert(nameList.begin() + j, getName);
               inserted = true;
               break;
            }
         if(!inserted)
            nameList.push_back(getName);
      }
      
   }
   return 0;
}

void display(vector <string> story)
{

   for (int i = 0; i < story.size(); i++)
      cout << story[i] << endl;
   return;
}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOOSE POINTS.
 ***********************************************************************/
int main()
{
   vector <string> nameList;

   readFile(nameList);

   display(nameList);
   
   return 0;
}
