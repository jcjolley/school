/***********************************************************************
 * This program is designed to:
 *      Late binding with function pointers - with a VTABLE
 ************************************************************************/

#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

#define MAX 256

// called a "forward declaration," much like a prototype
struct VTableText;

/***********************************************************
 * TEXT
 * Main text structure
 ***********************************************************/
struct Text
{
   char data[MAX];
   int  length;
   const VTableText * __vtptr;
};

/***********************************************************
 * TEXT VTable
 * List of all the member functions that will be in Text
 ***********************************************************/
struct VTableText
{
   void (*copy   )(      Text * pDest,  const Text * pSrc  );
   bool (*isEqual)(const Text * pText1, const Text * pText2);
};

// prototypes of our two member functions
void textCopy   (      Text * pDest,  const Text * pSrc  );
bool textIsEqual(const Text * pText1, const Text * pText2);

// Since every VTable will be the same, we will make a static const here.
const VTableText V_TABLE_TEXT =
{
   &textCopy,
   &textIsEqual
};

/****************************************************
 * TEXT IS EQUAL
 * Determine if two text structures are equal
 ****************************************************/
bool textIsEqual(const Text * pText1, const Text * pText2)
{
   // if the buffers are inequal, don't bother!
   if (pText1->length != pText2->length)
      return false;

   // point to the buffers
   const char *p1 = pText1->data;
   const char *p2 = pText2->data;

   // loop through the text
   while (*p1 == *p2 && *p1)
   {
      p1++;
      p2++;
   }

   // done!
   return *p1 == *p2;
}

/*************************************************
 * TEXT COPY
 * Copy from one buffer to another
 ************************************************/
void textCopy(Text * pDest, const Text * pSrc)
{
   for (pDest->length = 0;
        pDest->length <= pSrc->length;
        pDest->length++)
      pDest->data[pDest->length] = pSrc->data[pDest->length];
   pDest->length--;
}

/**********************************************************************
 * main()...
 ***********************************************************************/
int main()
{
   // two text objects
   Text text1;
   text1.__vtptr = &V_TABLE_TEXT;

   Text text2;
   text2.__vtptr = &V_TABLE_TEXT;

   // initialize them
   cout << "Text 1: ";
   cin.getline(text1.data, MAX);
   text1.length = strlen(text1.data);
   assert(text1.length < MAX);

   cout << "Text 2: ";
   cin.getline(text2.data, MAX);
   text2.length = strlen(text2.data);
   assert(text2.length < MAX);

   // compare them
   if (text1.__vtptr->isEqual(&text1, &text2))
      cout << "They are the same!\n";
   else
      cout << "They are different!\n";

   // copy text
   text1.__vtptr->copy(&text1, &text2);
   assert(text1.__vtptr->isEqual(&text1, &text2));
   
   return 0;
}
