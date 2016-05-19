/***********************************************************************
 * This program is designed to demonstrate:
 *      How constructors the copy constructor is called when a
 *      function is involved.
 ************************************************************************/

#include <iostream>
using namespace std;

/***************************************
 * SILLY
 * This class does not do that much and
 * hence is a bit silly
 **************************************/
class Silly
{
public:
   Silly()                       { cout << "Default constructor\n"; }
   Silly(const Silly & s)        { cout << "Copy constructor\n";    }
  ~Silly()                       { cout << "Destructor\n";          }
};

/****************************************
 * FUNCTION
 * This function will return a Silly object
 ***************************************/
Silly function(Silly s)
{
   cout << "Function\n";           // function line 1
   return s;                       // function line 2
}
      


/**********************************************************************
 * MAIN: Just demonstrate how constructors and destructors are called
 ***********************************************************************/
int main()
{
   Silly s;                        // main line 1
   function(s);                    // main line 2
   return 0;                       // main line 3
}

