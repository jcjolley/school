#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// Demonstrates the famous factorial recursive function.
// This code has been "instrumented" to show the recursive
// call structure

int indent = 0;

int factorial(int n)
{
   int rtnval = 0;
   cout << setw(++indent) << ">" << "factorial(" << n << ")\n";
   if (n == 0)
   {
      rtnval = 1;
   }
   else
   {
      rtnval = (n * factorial(n - 1));
   }
   cout << setw(indent--) << rtnval << endl;
   return rtnval;
}

int main(int argc, const char* argv[])
{
   cout << factorial(atoi(argv[1])) << endl;

   return 0;
}
