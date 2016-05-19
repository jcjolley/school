#include <iostream>
#include <cstdlib>
using namespace std;

// Demonstrates an iterative version of the factorial function.

int factorial(int n)
{
   int rtnval = 1;
   while (n > 0)
   {
      rtnval *= n--;
   }
   return rtnval;
}

int main(int argc, const char* argv[])
{
   cout << factorial(atoi(argv[1])) << endl;

   return 0;
}
