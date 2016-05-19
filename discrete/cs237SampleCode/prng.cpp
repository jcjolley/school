#include <iostream>
#include <cstdlib>
using namespace std;

// Example from Rosen on page 207: prng 7 3 9 4
// Run with no arguments to get the pure multiplicative generator
// mentioned on page 207.

unsigned long prng(unsigned long a, unsigned long s, unsigned long m, unsigned long c)
{
   return ((s * a + c) % m);
}

int main(unsigned long argc, char* argv[])
{
   unsigned long a = (argc > 1) ? atol(argv[1]) : 16807;
   unsigned long s = (argc > 2) ? atol(argv[2]) : 1;
   unsigned long m = (argc > 3) ? atol(argv[3]) : 2147483647;
   unsigned long c = (argc > 4) ? atol(argv[4]) : 0;

   unsigned long i = 1;
   unsigned long x = s;

   cout << x << ", ";

   while (i < m)
   {
      x = prng(a, x, m, c);
      cout << x << ", ";
      if (i % 10 == 0) cout << endl;
      i++;
   }
   cout << endl;

   return 0;
}

