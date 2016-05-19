// For your consideration: THE ULTIMATE IN ELEGANCE!!
//
// Using two helper functions (forAll and forSome ---
// whose declarations you would need to add to the Predicate
// class) simplifies each of the nested quantifier functions.
// Each function (including the helpers) is four lines of code
// (not counting curly braces all alone on a line) with no local
// variables needed for flags or counts, and with a single,
// uncluttered "for" loop.

bool Predicate::forAll(int x, int setY[], int sizeY)
{
   for (int i = 0; i < sizeY; i++)
   {
      if (isFalse(x, setY[i]))
      {
         return false;
      }
   }
   return true;
}

bool Predicate::forSome(int x, int setY[], int sizeY)
{
   for (int i = 0; i < sizeY; i++)
   {
      if (isTrue(x, setY[i]))
      {
         return true;
      }
   }
   return false;
}

bool Predicate::forAllForAll(int setX[], int sizeX, int setY[], int sizeY)
{
   for (int i = 0; i < sizeX; i++)
   {
      if (! forAll(setX[i], setY, sizeY))
      {
         return false;
      }
   }
   return true;
}

bool Predicate::forAllForSome(int setX[], int sizeX, int setY[], int sizeY)
{
   for (int i = 0; i < sizeX; i++)
   {
      if (! forSome(setX[i], setY, sizeY))
      {
         return false;
      }
   }
   return true;
}

bool Predicate::forSomeForAll(int setX[], int sizeX, int setY[], int sizeY)
{
   for (int i = 0; i < sizeX; i++)
   {
      if (forAll(setX[i], setY, sizeY))
      {
         return true;
      }
   }
   return false;
}

bool Predicate::forSomeForSome(int setX[], int sizeX, int setY[], int sizeY)
{
   for (int i = 0; i < sizeX; i++)
   {
      if (forSome(setX[i], setY, sizeY))
      {
         return true;
      }
   }
   return false;
}
