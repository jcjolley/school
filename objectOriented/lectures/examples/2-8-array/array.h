/***********************************************************************
 * This program is designed to demonstrate:
 *      How to create a simple container class: arrays.  This will
 *      be simliar to the vector class
 ************************************************************************/

#include <iostream>   // for OSTREAM

/******************************************
 * ARRAY
 * A container of doubles similar to a vector
 *****************************************/
class Array
{
   public:
      // initialize to zero
      Array() : sizeArray(0), capacityArray(0) {}
      // initialize and grow to a given capacity
      Array(int capacity) : sizeArray(0), capacityArray(0)
      {
         grow(capacity);
      }
      // initialize and copy the passed array
      Array(const Array & array) : sizeArray(0), capacityArray(0)
      {
         grow(array.size());
         for (int i = 0; i < size(); i++)
            *this += array.get(i);
      }

      // delete the array as appropriate
      ~Array()
      {
         if (capacityArray)
            delete [] data;
      }

      // access a given item for getting and setting
      double & operator [](int index) throw(bool)
      {
         if (index < 0 || index >= sizeArray)
            throw false;
         return data[index];
      }
      // this is a read-only version of access
      double get(int index) const throw(bool)
      {
         if (index < 0 || index >= sizeArray)
            throw false;
         return data[index];
      }
      // push an item onto the back of the list
      Array & operator += (double value) throw(bool)
      {
         grow(sizeArray + 1);
         data[sizeArray++] = value;
         return *this;
      }
      // copy the contents of one Array onto another
      Array & operator = (const Array & rhs) throw(bool)
      {
         grow(rhs.capacity());
         sizeArray = 0;
         for (int i = 0; i < rhs.size(); i++)
            (*this) += rhs.get(i);
         return *this;
      }
      // is value a member of this?
      bool isMember(double value) const
      {
         for (int i = 0; i < size(); i++)
            if (value == data[i])
               return true;
         return false;
      }
      // grow the array to a given size
      void grow(int capacity) throw(bool);
      // set intersection
      Array operator && (const Array & rhs) const;
      // set union
      Array operator || (const Array & rhs) const;
      
      // fetch the size or capacity
      int size()     const { return sizeArray;     }
      int capacity() const { return capacityArray; }
   
   private:
      double * data;            // where the data for the array is stored
      int      sizeArray;       // the number of items currently in the array
      int      capacityArray;   // the capacity of the array
};

// insertion operator
std::ostream & operator << (std::ostream & out, const Array & rhs);
