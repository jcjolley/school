/*************************************************************************
* Predicate class declaration (IMPLEMENT in your own pq.cpp file.)
* (Add to this file, if desired, but do NOT change what is already in it.)
*************************************************************************/
#ifndef _PREDICATE_H
#define _PREDICATE_H 1
/**************************************************************
* The Predicate class is an abstract base class with pure virtual
* abstract functions (per the =0 suffix).
***************************************************************/
class Predicate
{
public:
   /**************************************************************
   * Is this Predicate true for the given x and y?
   ***************************************************************/
   virtual bool isTrue(int x, int y)=0;

   /**************************************************************
   * Is this Predicate false for the given x and y?
   ***************************************************************/
   virtual bool isFalse(int x, int y)=0;

   /**************************************************************
   * Is this Predicate true for all x for all y
   * in the supplied sets?
   ***************************************************************/
   bool forAllForAll(int setX[], int sizeX, int setY[], int sizeY);

   /**************************************************************
   * Is this Predicate true for all x for some y
   * in the supplied sets?
   ***************************************************************/
   bool forAllForSome(int setX[], int sizeX, int setY[], int sizeY);

   /**************************************************************
   * Is this Predicate true for some x for all y
   * in the supplied sets?
   ***************************************************************/
   bool forSomeForAll(int setX[], int sizeX, int setY[], int sizeY);

   /**************************************************************
   * Is this Predicate true for some x for some y
   * in the supplied sets?
   ***************************************************************/
   bool forSomeForSome(int setX[], int sizeX, int setY[], int sizeY);
};

#endif /* predicate.h */
