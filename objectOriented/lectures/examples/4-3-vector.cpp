/***********************************************************************
 * This program is designed to demonstrate:
 *      How to use a class template to store a non-trivial data structure:
 *      the vector<T> class from the standard template library
 ************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

/*****************************************
 * VECTOR <T>
 * Just like the std::vector<T> class
 ****************************************/
template <class T>
class Vector
{
   public:
      // default constructor: no space allocated
      Vector() : data(NULL), size(0), capacity(0) {}
      // non-default constructor: set the capacity initially
      Vector(int capacity) : data(NULL), size(0), capacity(0)
      {
         if (capacity > 0)
            resize(capacity);
      }
      // copy-constructor: copy over the data from the right-and-side
      Vector(const Vector<T> & rhs) : data(NULL), size(0), capacity(0)
      {
         if (rhs.getSize())
            *this = rhs; // call the assignment operator
      }
      // delete the data as necessary
      ~Vector()
      {
         if (NULL != data)
         {
            assert(capacity);
            delete [] data;
         }
      }
      // add to the end of the list, reallocating as necesary
      Vector<T> & pushBack(const T & t) throw (bad_alloc);
      // the += operator works exactly the same as pushBack()
      Vector<T> & operator += (const T & t) throw (bad_alloc) 
      {
         return pushBack(t);
      }
      // read-write access with bounds checking
      T & operator [] (int index) throw (bool)
      {
         // sanity check
         if (index < 0 || index >= size)
            throw true;
         return data[index];    // return-by-reference
      }
      // read-only access with bounds checking
      T operator () (int index) throw (bool)
      {
         return (*this)[index];  // return-by-value
      }
      // copy one Vector<T> into another
      Vector<T> & operator = (const Vector<T> & rhs) throw (bad_alloc);
      // fetch the size
      int getSize() const { return size; }
      // fetch the capacity
      int getCapacity() const { return capacity; }

   private:
      T *  data;                 // user data, a dynamically-allocated array
      int  capacity;             // the capacity of the array
      int  size;                 // the number of items currently used
      void resize(int newCapacity) throw (bad_alloc);  
};

/***************************************
 * VECTOR <T> :: RESIZE
 **************************************/
template <class T>
void Vector<T> :: resize(int newCapacity) throw (bad_alloc)
{
   assert(newCapacity > 0 && newCapacity > capacity);

   // allocate the new array
   T * pNew;
   pNew = new T[newCapacity];       // could throw bad_alloc

   // copy over the data from the old array
   for (int i = 0; i < size; i++)
      pNew[i] = data[i];

   // delete the old and assign the new
   delete [] data;
   data = pNew;
   capacity = newCapacity;
}

/***************************************
 * VECTOR <T> :: pushBack
 **************************************/
template <class T>
Vector<T> & Vector<T> :: pushBack (const T & t) throw (bad_alloc)
{
   assert(size <= capacity);
   
   // grow if necessary
   if (capacity == 0)
      resize(1);
   else if (size == capacity)
      resize(capacity * 2);   // could throw bad_alloc
   assert(size < capacity);

   // actually add on to the end of the list
   data[size++] = t;
   return *this;
}

/***************************************
 * VECTOR <T> :: assigment operator
 **************************************/
template <class T>
Vector<T> & Vector<T> :: operator = (const Vector<T> & rhs) throw (bad_alloc)
{
   // blow away anything that was in this->data previously
   size = 0;

   // make sure we are big enough to handle the new data
   if (rhs.size > capacity)
      resize(rhs.size);
   assert(capacity >= rhs.size);

   // copy over the data from the right-hand-side
   size = rhs.size;
   for (int i = 0; i < rhs.size; i++)
      data[i] = rhs.data[i];

   // return self
   return *this;
}

/**********************************************************************
* This will be just a simple driver program 
***********************************************************************/
int main()
{
   Vector<int> numbers;

   // fill it up
   for (int i = 0; i < 5; i++)
   {
      int input;
      cout << "> ";
      cin  >> input;
      numbers += input;
   }

   // display the results
   for (int i = 0; i < 5; i++)
      cout << numbers[i] << endl;
   
   return 0;
}
