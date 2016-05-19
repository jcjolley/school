/***********************************************************************
 * This demo program is designed to:
 *      Create a structure to store data and pass it to functions.
 ************************************************************************/

#include <iostream>
using namespace std;

struct Name
{
   string first;
   string last;
};

void passByReference(Name &  name);
void passByPointer(  Name * pName);
void passByValue(    Name    name);

/**********************************************************************
 * main()...
 ***********************************************************************/
int main()
{
   Name name =
   {
      string("Brigham"),
      string("Young")
   };

   // data and address
   cout << "main()           " 
        << " - address:"  << &name
        << " - value:"    << name.first << " " << name.last
        << endl;
   
   // call some functions
   passByReference(name);
   passByPointer(&name);
   passByValue(name);
   
   return 0;
}

/********************************************
 * PASS BY REFERENCE
 * Note that this does not make a copy of the structure.
 * Instead, this version and the version in main() are the
 * same.
 *******************************************/
void passByReference(Name & name)
{
   cout << "passByReference()"
        << " - address:"  << &name
        << " - value:"    << name.first << " " << name.last
        << endl;
}

/*********************************************
 * PASS BY POINTER
 * Here we are passing the address by value. Note
 * we need to dereference using the * or the ->
 * operator.  Both will be demonstrated.
 *********************************************/
void passByPointer(Name * pName)
{
   cout << "passByPointer()  "
        << " - address:"  << pName
        << " - value:"    << pName->first << " " << (*pName).last
        << endl;
}

/********************************************
 * PASS BY VALUE
 * Generally we avoid doing this because a copy
 * of the structure is made.  In this case, the
 * structure has quite a bit of data in it.  it
 * is usually a better idea to pass-by-reference
 * as a constant:
 *    void passConstByValue(const Name & name)
 ********************************************/
void passByValue(Name name)
{
   cout << "passByValue()    "
        << " - address:"  << &name
        << " - value:"    << name.first << " " << name.last
        << endl;
}
