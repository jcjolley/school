#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   int mod = (3 * 5 * 7);
   int a = 16;
#ifdef BOTTOMUP
   for (int x = 1; x < 10302; x++)
#else
   for (int x = 10302; x > 0; x--)
#endif
   {
      if (((x * x) % mod) == a)
      {
         cout << "x = " << (x % mod) << endl;
      }
   }
   return 0;
}
