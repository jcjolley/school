/***********************************************************************
 * This program is designed to demonstrate:
 *      How constructors and destructors are called
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


/**********************************************************************
 * MAIN: Just demonstrate how constructors and destructors are called
 ***********************************************************************/
int main()
{
   Silly s1;                 // line 1
   Silly s2(s1);             // line 2
   return 0;                 // line 3
}
