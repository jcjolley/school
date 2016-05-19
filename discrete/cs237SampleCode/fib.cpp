#include <iomanip>
#include <iostream>
#include <cstdlib>
using namespace std;

// Demonstrates the famous fibonacci recursive function.
// This code has been "instrumented" to show the recursive
// call structure

int indent = 0;

int fibonacci(int n)
{
   cout << setw(++indent) << ">" << "fibonacci(" << n << ")\n";
   int rtnval;
   if (n == 0 || n == 1)
   {
      rtnval = n;
   }
   else
   {
      rtnval = (fibonacci(n - 1) + fibonacci(n - 2));
   }
   cout << setw(indent--) << rtnval << endl;
   return rtnval;
}

int main(int argc, const char* argv[])
{
   cout << fibonacci(atoi(argv[1])) << endl;
}
