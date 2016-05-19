/***********************************************************************
 * This program is designed to:
 *      Late binding with function pointers - no VTables
 ************************************************************************/

#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

#define MAX 256

/***********************************************************
 * TEXT
 * Main text structure
 ***********************************************************/
struct Text
{
   char data[MAX];
   int length;
   void (*copy)(Text & textDest, const Text & textSrc);
   bool (*isEqual)(const Text & textDest, const Text & textSrc);
};


/****************************************************
 * TEXT IS EQUAL
 * Determine if two text structures are equal
 ****************************************************/
bool textIsEqual(const Text & text1, const Text & text2)
{
   // if the buffers are inequal, don't bother!
   if (text1.length != text2.length)
      return false;
   
   // point to the buffers
   const char *p1 = text1.data;
   const char *p2 = text2.data;

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
void textCopy(Text & textDest, const Text & textSrc)
{
   for (textDest.length = 0;
        textDest.length <= textSrc.length;
        textDest.length++)
      textDest.data[textDest.length] = textSrc.data[textDest.length];
   textDest.length--;
}

/**********************************************************************
 * main()...
 ***********************************************************************/
int main()
{
   // two text objects
   Text text1;
   text1.copy = &textCopy;
   text1.isEqual = &textIsEqual;

   Text text2;
   text2.copy = &textCopy;
   text2.isEqual = &textIsEqual;

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
   if (text1.isEqual(text1, text2))
      cout << "They are the same!\n";
   else
      cout << "They are different!\n";

   // copy text
   text1.copy(text1, text2);
   assert(text1.isEqual(text1, text2));
   
   return 0;
}
