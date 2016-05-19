/***********************************************************************
 * This demo program is designed to:
 *      Demonstrate callback functions through an apply function.  In
 *      this case, applyAll will add the previous two items on the list:
 *          {x1, x2, x3} -> {x1, x1 + x2, x1 + x2 + x3} 
 ************************************************************************/

#include <iostream>
using namespace std;

void applyAll(void **list, int numElements,
              void(*apply)(void *, void *));

void applyNumbers(void *, void *);
void applyText   (void *, void *);

#define MAX 5

/**********************************************************************
 * MAIN: Driver program to demonstrate the applyAll function
 ***********************************************************************/
int main()
{
   float listNumbers[MAX];
   float *pListNumbers[MAX];
   string listText[MAX];
   string *pListText[MAX];

   // fill the data
   cout << "Please enter " << MAX << " numbers ";
   for (int i = 0; i < MAX; i++)
   {
      cin >> listNumbers[i];
      pListNumbers[i] = listNumbers + i;
   }
   cout << "Please enter " << MAX << " words ";
   for (int i = 0; i < MAX; i++)
   {
      cin >> listText[i];
      pListText[i] = listText + i;
   }

   // apply our transform
   applyAll((void **)pListNumbers, MAX, applyNumbers);
   applyAll((void **)pListText,    MAX, applyText);

   // display the results
   cout << "Numbers: ";
   for (int i = 0; i < MAX; i++)
      cout << listNumbers[i] << (i == MAX - 1? '\n' : ' ');
   cout << "Words: ";
   for (int i = 0; i < MAX; i++)
      cout << listText[i] << (i == MAX - 1? '\n' : ' ');

   return 0;
}


/***********************************************
 * APPLY NUMBERS
 * Apply a transform to a number.  In this case: double it!
 **********************************************/
void applyNumbers(void *pv1, void *pv2)
{
   float *pNumber1 = (float *)pv1;
   float *pNumber2 = (float *)pv2;
   *pNumber1 += *pNumber2;
}

/************************************************
 * APPLY TEXT
 * Apply a transform to text. In this case, reverse it!
 ************************************************/
void applyText(void *pv1, void *pv2)
{
   string *pString1 = (string *)pv1;
   string *pString2 = (string *)pv2;

   *pString1 = *pString2 + *pString1;
}

/*************************************************
 * APPLY ALL
 * Apply the transform specified by apply to all the
 * elements in the list
 **************************************************/
void applyAll(void **list, int numElements, void(*apply)(void *, void *))
{
   for (int i = 1; i < numElements; i++)
      (*apply)(list[i], list[i - 1]);
}
