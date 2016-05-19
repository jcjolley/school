/***********************************************************************
 * This program is designed to demonstrate:
 *      The simplest class template possible
 ************************************************************************/

#include <iostream>
using namespace std;

/*****************************************
 * STORE
 * A class template storing a value
 *****************************************/
template <class T>
class Store
{
   public:
      Store(const T & t) : t(t) {}
      Store(const Store<T> & t) { *this = t; }
      T get() const { return t; }
      void set(const T & t);
      Store<T> & operator = (const Store<T> & t)
      {
         this->t = t.get();
         return *this;
      }
      friend ostream & operator << (ostream & out, const Store<T> & t)
      {
         out << t.get();
         return out;
      }
   private:
      T t;
};   

/***************************************
 * STORE<T> :: SET
 ***************************************/
template <class T>
void Store<T> :: set(const T & t)
{
   this->t = t;
}


/**********************************************************************
* This will be just a simple driver program 
***********************************************************************/
int main()
{
   Store<double> s(3.14159);         // use the "double" version of Store<T>
   cout << s << endl;
   return 0;
}
