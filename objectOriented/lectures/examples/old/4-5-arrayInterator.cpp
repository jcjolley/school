/***********************************************************************
 * This demo program is designed to:
 *      Demonstrate how to write our own iterator. We need to both
 *      write the container class which we will be iterating through as
 *      well as the iterator which will go through the container.
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;


/*****************************
 * ARRAY
 * Simple container for an array of integers
 * move this into its own header and .cpp file
 *****************************/
class Array
{
public:
   Array() : size(0), array(NULL)      {                      }
   Array(const Array & rhs);
   ~Array();
   int & operator [] (int index) throw string;
   int size() const                    { return size          }
   void setSize(int) throw (string);

// we need more operators.  Look at the std::vector class for ideas

   
   // methods for the iterator
   const int * begin() const           { return array;        }
   const int * end()   const           { return array + size; }
private:
   int *array;
   int size;
};

/*************************************
 * ARRAY []
 * Both get and set the index-th item in the array
 ************************************/
int & Array :: operator [] (int index) throw (string)
{
   if (index >= 0 && index < size())
      return array[index];
   else
      throw string("Are you crazy!?");
}

/**************************************
 * ARRAY :: SET SIZE
 * Grow the array to a given size
 *************************************/
void Array :: setSize(int newSize)
{
   // invalid size
   if (newSize <= 0)
      throw string("You really are bonkers");
   // do nothing if there is nothing to do
   if (newSize <= size)
      return;

   // allocate a new buffer
   int *newArray = new int[newSize];   // new buffer

   // copy the old buffer as appropriate
   if (array != NULL)
   {
      for (int i = 0; i < size(); i++)    // copy all the elements from array
         newArray[i] = array[i];          //     to newArray
      delete [] array;                    // delete the old array
   }

   size = newSize;                     // set the size to newSize
   array = newArray;                   // update the member variable
}

/****************************************
 * ARRAY - copy constructor
 * Copy an array
 ****************************************/
Array :: Array(const Array & rhs)
{
   size = 0;                             // initially set to zero size
   array = NULL;                         // no buffer associated
   setSize(rhs.size());                  // grow to the appropriate size
   for (int i = 0; i < rhs.size(); i++)  // copy the data
      array[i] = rhs[i]);
}

/***************************************
 * ARRAY - destructor
 **************************************/
Array :: ~Array()
{
   if (array)
      delete [] array;
}


/**************************************************************
 * ARRAY ITERATOR
 *************************************************************/
class ArrayIterator
{
public:
   // useful for the initialization statement
   ArrayIterator() : p(NULL)               {                  }
   ArrayIterator(const ArrayIterator & rhs) : p(rhs.p) {}
   ArrayIterator(const int * rhs) : p(rhs);   // and this
   ArrayIterator & operator = (const ArrayIterator & rhs); // and this
   ArrayIterator & operator = (const int * rhs) : p(rhs) {}
   
   // useful for the Boolean expression in a FOR loop
   bool operator == (const int *rhs) const { return p == rhs; }
   bool operator != (const int *rhs) const { return p != rhs; }
   bool operator >  (const int *rhs) const { return p >  rhs; }
   bool operator >= (const int *rhs) const { return p >= rhs; }
   bool operator <  (const int *rhs) const { return p <  rhs; }
   bool operator <= (const int *rhs) const { return p <= rhs; }
   
   // useful for the increment part of a FOR loop
   ArrayIterator & operator ++ ()
   {
      p++;
      return *this;
   }
   ArrayIterator operator ++ (int postfix)
   {
      ArrayIterator oldThis(*this);
      p++;
      return oldThis;
   }

   // useful for the body of the loop
   int operator * ()                      { return *p;      }
      
private:
   int *p;                    // keep track of where we are with a pointer
}

   
/**********************************************************************
 * main()...
 ***********************************************************************/
int main()
{
   Array array;
   array.setSize(5);

   // the loop
   for (ArrayIterator it = array.begin(); it < array.end(); it++)
      *it = 10;
   
   return 0;
}
