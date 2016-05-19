#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
#ifdef BOTTOMUP
   for (int x = 1; x < 3000; x++)
#else
   for (int x = 3000; x > 0; x--)
#endif
   {
      if (((x % 2) == 1) &&
          ((x % 3) == 1) &&
          ((x % 4) == 1) &&
          ((x % 5) == 1) &&
          ((x % 6) == 1) &&
          ((x % 7) == 0))
      {
         cout << "x = " << x << endl;
      }
   }
   return 0;
}
