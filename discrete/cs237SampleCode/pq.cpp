/*************************************************************************
* Quantifiers Example (unary Predicate only)
*************************************************************************/
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

/**************************************************************
* The Predicate class is an abstract base class with pure virtual
* abstract functions (per the =0 suffix).
***************************************************************/
class Predicate
{
public:
   /**************************************************************
   * Is this Predicate true for the given x?
   ***************************************************************/
   virtual bool isTrue(int x)=0;

   /**************************************************************
   * Is this Predicate true for the given x?
   ***************************************************************/
   virtual bool isFalse(int x)=0;

   /**************************************************************
   * Is this Predicate true for all values in the given set?
   ***************************************************************/
   bool forAll(int set[], int size);

   /**************************************************************
   * Is this Predicate true for some value in the given set?
   ***************************************************************/
   bool forSome(int set[], int size);
};

/**************************************************************
* forAll is A#xP(x) (The Universal Quantification of P(x), the
* proposition that is true if and only if P(x) is true for all
* x in the universe of discourse.)
*
* loops through all values in a set (of a finite size) to see
* if the Predicate is always true.  If it encounters a value
* for which the Predicate is false, then A#xP(x) is false.
* Otherwise A#xP(x) is true.
***************************************************************/
bool Predicate::forAll(int set[], int size)
{
   for (int i = 0; i < size; i++)
   {
      if (isFalse(set[i]))
      {
         return false;
      }
   }
   return true;
}

/**************************************************************
* forSome = E#xP(x) (The Existential Quantification of P(x),
* the proposition that is true if and only if there exists an
* x in the universe of discourse such that P(x) is true.)
*
* loops through all values in a set (of a finite size) to see
* if the Predicate is ever true.  If it encounters any value
* for which the Predicate is true, then E#xP(x) is true.
* Otherwise E#xP(x) is false.
***************************************************************/
bool Predicate::forSome(int set[], int size)
{
   for (int i = 0; i < size; i++)
   {
      if (isTrue(set[i]))
      {
         return true;
      }
   }
   return false;
}

class Even : public Predicate
{
public:
   bool isTrue(int x)
   {
      return ((x % 2) == 0);
   }

   bool isFalse(int x)
   {
      return !isTrue(x);
   }
};

class Odd : public Predicate
{
public:
   bool isTrue(int x)
   {
      return ((x % 2) == 1);
   }

   bool isFalse(int x)
   {
      return !isTrue(x);
   }
};

/**************************************************************
* main tests for both true and false return values for the
* two functions forAll and forSome for the simple Predicates
* Even and Odd.
***************************************************************/
int main()
{
   Even even;
   Odd odd;

   int Evens[] = {0, 2, 4, 6, 8};
   int Odds[] = {1, 3, 5, 7, 9};

   cout << boolalpha << endl;
   cout << "even.forAll(Evens, 5)\n"
        << "     expected to return true;\n"
        << " actual return value is "
        <<  even.forAll(Evens, 5) << ".\n\n";
   cout << "odd.forAll(Evens, 5)\n"
        << "     expected to return false;\n"
        << " actual return value is "
        <<  odd.forAll(Evens, 5) << ".\n\n";
   cout << "even.forAll(Odds, 5)\n"
        << "     expected to return false;\n"
        << " actual return value is "
        <<  even.forAll(Odds, 5) << ".\n\n";
   cout << "odd.forAll(Odds, 5)\n"
        << "     expected to return true;\n"
        << " actual return value is "
        <<  odd.forAll(Odds, 5) << ".\n\n";

   cout << "--------------------------------\n\n";

   cout << "even.forSome(Evens, 5)\n"
        << "     expected to return true;\n"
        << " actual return value is "
        <<  even.forSome(Evens, 5) << ".\n\n";
   cout << "odd.forSome(Evens, 5)\n"
        << "     expected to return false;\n"
        << " actual return value is "
        <<  odd.forSome(Evens, 5)  << ".\n\n";
   cout << "even.forSome(Odds, 5)\n"
        << "     expected to return false;\n"
        << " actual return value is "
        <<  even.forSome(Odds, 5) << ".\n\n";
   cout << "odd.forSome(Odds, 5)\n"
        << "     expected to return true;\n"
        << " actual return value is "
        <<  odd.forSome(Odds, 5)  << ".\n\n";

   return 0;
}
