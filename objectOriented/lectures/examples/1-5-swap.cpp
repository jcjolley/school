/***********************************************************************
 * This program is designed to demonstrate:
 *      Overloading functions with swap()
 ************************************************************************/

#include <iostream>
using namespace std;

/************************************
 * SWAP: integers
 * Swap two integers
 ***********************************/
void swap(int & value1, int & value2)
{
   int tmp = value1;
   value1  = value2;
   value2  = tmp;
}

/**********************************
 * SWAP: STRINGS
 * Swap two strings
 **********************************/
void swap(string & s1, string & s2)
{
   string tmp = s1;
   s1 = s2;
   s2 = tmp;
}

/*********************************
 * SWAP: DOUBLES
 * Swap two doubls
 ********************************/
void swap(double & value1, double & value2)
{
   double tmp = value1;
   value1  = value2;
   value2  = tmp;
}


/**********************************************************************
* This will be just a simple driver program 
***********************************************************************/
int main()
{
   string last  = "Thomas";                 // oh no! I got the first name and
   string first = "Ricks";                  //   the last name mixed up

   swap(last, first);                       // calls the "string &" version

   cout << first << ' ' << last << endl;    // all is better now!
   return 0;
   
}
