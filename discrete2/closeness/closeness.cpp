/***************************************************************************
 * Program:
 *    Relations as Connection Matrices
 * Author:
 *    You
 * Purpose:
 *    Exploring and enhancing an implementation of a
 *    representation of relations to discover their basic properties.
 *
 * Summary:
 *    Represents relations as connection (zero-one) matrices, and provides
 *    functionality for testing properties of relations.
 *
 *    NOTE: deliberately (mostly) uncommented!
 *
 ***************************************************************************/
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>
using namespace std;


/*************************************************************
* Represents a relationship binary matrix 
**************************************************************/
class Relation
{
private:
   bool** mMatrix;
   int mSize;

   void init()
   {
      mMatrix = new bool*[mSize];
      for (int i = 0; i < mSize; i++)
      {
         mMatrix[i] = new bool[mSize];
      }

      for (int i = 0; i < mSize; i++)
         for (int j = 0; j < mSize; j++)
            mMatrix[i][j] = 0;
   }

public:
   /*************************************************************
   * Constructor
   **************************************************************/
   Relation(int size)
   {
      mSize = size;
      init();
   }

   /*************************************************************
   * Overloaded = operator for a Relation
   **************************************************************/
   Relation& operator=(const Relation& rtSide)
   {
      if (this == &rtSide)
      {
         return *this;
      }
      else
      {
         mSize = rtSide.mSize;
         for (int i = 0; i < mSize; i++)
         {
            delete [] mMatrix[i];
         }
         delete [] mMatrix;
         init();
         for (int x = 0; x < mSize; x++)
         {
            for (int y = 0; y < mSize; y++)
            {
               mMatrix[x][y] = rtSide[x][y];
            }
         }
      }
      return *this;
   }

   /*************************************************************
   * Copy constructor
   **************************************************************/
   Relation(const Relation& relation)
   {
      mSize = relation.getConnectionMatrixSize();
      init();
      *this = relation;
   }

   /*************************************************************
   * Destructor
   **************************************************************/
   ~Relation()
   {
      for (int i = 0; i < mSize; i++)
      {
         delete [] mMatrix[i];
      }
      delete [] mMatrix;
   }

   /*************************************************************
   * Returns n in an n x n matrix
   **************************************************************/
   int getConnectionMatrixSize() const
   {
      return mSize;
   }

   /*************************************************************
   * Array bracket overloader for Relation
   **************************************************************/
   bool* operator[](int row) const
   {
      return mMatrix[row];
   }

   /*************************************************************
   * Equivalence operator overload for Relation
   **************************************************************/
   bool operator==(const Relation& relation)
   {
      int size = relation.getConnectionMatrixSize();
      if (mSize != size)
      {
         return false;
      }
      for (int i = 0; i < size; i++)
      {
         for (int j = 0; j < size; j++)
         {
            if (mMatrix[i][j] != relation[i][j])
            {
               return false;
            }
         }
      }
      return true;
   }

   /*************************************************************
   * Multiplication operator overload for Relation class
   **************************************************************/
   Relation operator*(Relation& rhs)
   {
      assert(rhs.getConnectionMatrixSize() == mSize);

      Relation temp(mSize);

      for (int k = 0; k < mSize; k++)
      {   
         for (int i = 0; i < mSize; i++)
         {
            for (int j = 0; j < mSize; j++)
            {
               temp[i][j] = temp[i][j] || (mMatrix[i][k] && rhs[k][j]);
            }
         }
      }
      return temp;
   }

   /*************************************************************
   * Overload <= for Relation class
   **************************************************************/
   bool operator<=(Relation& rhs)
   {
      assert(rhs.getConnectionMatrixSize() == mSize);

      for (int i = 0; i < mSize; i++)
      {
         for (int j = 0; j < mSize; j++)
         {   
            if (mMatrix[i][j] > rhs[i][j])
            {   
               return false;
            }
         }
      }
      return true;
   }

   /*************************************************************
   * Checks if matrix is reflexive 
   **************************************************************/
   bool isReflexive()
   {
      //all related along a diagonal
      for (int i = 0; i < mSize; i++)
      {
         if (!mMatrix[i][i])
         {
            return false;
         }
      }
      return true;
   }

   /*************************************************************
   * Checks if matrix is Irreflexive 
   **************************************************************/
   bool isIrreflexive()
   {
      //all unrelated along a diagonal
      for (int i = 0; i < mSize; i++)
      {
         if (mMatrix[i][i])
         {
            return false;
         }
      }
      return true;
   }

   /*************************************************************
   * Checks if matrix is Nonreflexive
   **************************************************************/
   bool isNonreflexive()
   {
      // !isReflexive && !isIrreflexive
      return !isReflexive() && !isIrreflexive();
   }

   /*************************************************************
   * Checks if matrix is Symmetric
   **************************************************************/
   bool isSymmetric()
   {
      //the transformed matrix == the original matrix
      for (int i = 0; i < mSize; i++)
      {   
         for (int j = 0; j < mSize; j++)
         {
            if (mMatrix[i][j] != mMatrix[j][i])
            {
               return false;
            }
         }
      }

      return true;
   }

   /*************************************************************
   * Checks if matrix is Antisymmetric
   **************************************************************/
   bool isAntisymmetric()
   {
      // no relation for both Mij and Mji when i != j
      for (int i = 0; i < mSize; i++)
      {   
         for (int j = 0; j < mSize; j++)
         {
            if (i != j)
            {
               if (mMatrix[i][j] && mMatrix[j][i])
               {
                  return false;
               }
            }
         }
      }

      return true;
   }

   /*************************************************************
   * Checks if matrix is Asymmetric
   **************************************************************/
   bool isAsymmetric()
   {
      return isAntisymmetric() && isIrreflexive();
   }

   /*************************************************************
   * Checks if matrix is Transitive
   **************************************************************/
   bool isTransitive()
   {
      return (*this) * (*this) <= (*this);
   }

   void describe();
};

/*************************************************************
* Overloads << for Relation 
**************************************************************/
ostream& operator<<(ostream& os, const Relation& relation)
{
   int n = relation.getConnectionMatrixSize();
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         os << relation[i][j] << " ";
      }
      os << endl;
   }
   return os;
}

/*************************************************************
* Overloads >> for Relation 
**************************************************************/
istream& operator>>(istream& is, Relation& relation)
{
   int n = relation.getConnectionMatrixSize();
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         is >> relation[i][j];
      }
   }
   return is;
}

/*************************************************************
* Describes the properties of the relation
**************************************************************/
void Relation::describe()
{
   cout << "\nThe relation represented by the " << mSize << "x" << mSize << " matrix\n";
   cout << *this << "is\n";
   cout << (isReflexive()     ? "" : "NOT ") << "Reflexive;\n";
   cout << (isIrreflexive()   ? "" : "NOT ") << "Irreflexive;\n";
   cout << (isNonreflexive()  ? "" : "NOT ") << "Nonreflexive;\n";
   cout << (isSymmetric()     ? "" : "NOT ") << "Symmetric;\n";
   cout << (isAntisymmetric() ? "" : "NOT ") << "Antisymmetric;\n";
   cout << (isAsymmetric()    ? "" : "NOT ") << "Asymmetric; and\n";
   cout << (isTransitive()    ? "" : "NOT ") << "Transitive.\n";
}

/*************************************************************
* Loads a relation from a file and describes it
**************************************************************/
void runOne(string file)
{
   ifstream inFile(file.c_str());

   if (inFile.is_open())
   {
      int size;
      inFile >> size;
      Relation relation(size);
      inFile >> relation;
      inFile.close();
      relation.describe();
   }
   else
   {
      cout << "Unable to open " << file << ".\n";
   }
}

/*************************************************************
* How to use the program
**************************************************************/
void usage(const char * programName)
{
   cout << "USAGE: " << programName << "[file]..."
        << "   With no parameters this calls usage() and learned()"
        << "   Each supplied paramter must be a file containing a relation\n";
}

/*************************************************************
* What I learned
**************************************************************/
void learned()
{
   cout << "I re-learned how to multiply matrices. I learned how to check "
        << "binary matrices for several different properties, and better yet "
        << "how to code them.  I re-learned the importance of initializing my "
        << "variables when I couldn't get the transitive check to work despite "
        << "being reasonably certain that my code was correct.  (I added "
        << "the variable initialization to the init() method in the Relation "
        << "class to prevent that from troubling me in this program ever "
        << "again.)  I think I am better prepared for test 3 because I "
        << "completed this exploration." << endl;
}
