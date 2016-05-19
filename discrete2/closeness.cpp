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
using namespace std;

class Relation operator*(Relation& r1, Relation& r2);

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
   }

public:
   Relation(int size)
   {
      mSize = size;
      init();
   }

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

   Relation(const Relation& relation)
   {
      mSize = relation.getConnectionMatrixSize();
      init();
      *this = relation;
   }

   ~Relation()
   {
      for (int i = 0; i < mSize; i++)
      {
         delete [] mMatrix[i];
      }
      delete [] mMatrix;
   }

   int getConnectionMatrixSize() const
   {
      return mSize;
   }

   bool* operator[](int row) const
   {
      return mMatrix[row];
   }

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

   /****************************************************************************
    *  TODO:                                                                   *
    *  In the next seven functions replace the "return false;" with your code. *
    *  NOTE: you may have to implement some of these functions outside of this *
    *  class definition (like is done with the describe function).             *
    *                                                                          *
    ***************************************************************************/
   bool isReflexive()
   {
      return false; 
   }

   bool isIrreflexive()
   {
      return false;
   }

   bool isNonreflexive()
   {
      return false;
   }

   bool isSymmetric()
   {
      return false;
   }

   bool isAntisymmetric()
   {
      return false;
   }

   bool isAsymmetric()
   {
      return false;
   }

   bool isTransitive()
   {
      return false;
   }

   void describe();
};

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

void Relation::describe()
{
   cout << "\nThe relation represented by the " << mSize << "x" << mSize << " matrix\n";
   cout << *this << "is\n";
   cout << (isReflexive() ? "" : "NOT ") << "Reflexive;\n";
   cout << (isIrreflexive() ? "" : "NOT ") << "Irreflexive;\n";
   cout << (isNonreflexive() ? "" : "NOT ") << "Nonreflexive;\n";
   cout << (isSymmetric() ? "" : "NOT ") << "Symmetric;\n";
   cout << (isAntisymmetric() ? "" : "NOT ") << "Antisymmetric;\n";
   cout << (isAsymmetric() ? "" : "NOT ") << "Asymmetric; and\n";
   cout << (isTransitive() ? "" : "NOT ") << "Transitive.\n";
}

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

void usage(const char * programName)
{
   cout << programName << " will do such and such.\n";
}

void learned()
{
   cout << "I learned a lot, and had a ton of fun.\n";
}
