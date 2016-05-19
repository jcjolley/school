#include <iomanip>
#include <iostream>
#include <cstdlib>
using namespace std;

// Demonstrates an iterative implementation of the fibonacci function.

int fibonacci(int n)
{
   int x;
   int y;
   int z;

   if (n == 0)
   {
      y = 0;
   }
   else
   {
      x = 0;
      y = 1;
      while (n-- > 0)
      {
         z = x + y;
         x = y;
         y = z;
      }
   }
   return y;
}

int main(int argc, const char* argv[])
{
   cout << fibonacci(atoi(argv[1])) << endl;
}
