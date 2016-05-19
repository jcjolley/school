/***********************************************************************
 * This demo program is designed to:
 *      Demonstrate callback functions through an apply function. In
 *      this case, applyAll will add the previous two items on the list:
 *          {x1, x2, x3} -> {x1, x1 + x2, x1 + x2 + x3} 
 ************************************************************************/

#include <iostream>
using namespace std;

template <class T>
void applyAll(T list[], int numElements);

#define MAX 5

/**********************************************************************
 * MAIN: Driver program to demonstrate the applyAll function
 ***********************************************************************/
int main()
{
   float listNumbers[MAX];
   string listText[MAX];

   // fill the data
   cout << "Please enter " << MAX << " numbers ";
   for (int i = 0; i < MAX; i++)
      cin >> listNumbers[i];

   cout << "Please enter " << MAX << " words ";
   for (int i = 0; i < MAX; i++)
      cin >> listText[i];

   // apply the transform to all
   applyAll(listNumbers, MAX);
   applyAll(listText,    MAX);

   // display the results
   cout << "Numbers: ";
   for (int i = 0; i < MAX; i++)
      cout << listNumbers[i] << (i == MAX - 1? '\n' : ' ');
   cout << "Words: ";
   for (int i = 0; i < MAX; i++)
      cout << listText[i] << (i == MAX - 1? '\n' : ' ');

   return 0;
}


/*************************************************
 * APPLY ALL
 * Apply the transform specified by apply to all the
 * elements in the list
 **************************************************/
template <class T>
void applyAll(T list[], int numElements)
{
   for (int i = 1; i < numElements; i++)
      list[i] = list[i - 1] + list[i];
}
