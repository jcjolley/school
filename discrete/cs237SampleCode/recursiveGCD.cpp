#include <cstdlib>
#include <iostream>
using namespace std;

// Demonstrates a recursive version of the GCD algorithm.

int gcd(int a, int b)
{
   int g;   // --- return value, greatest common divisor of a and b
  
/*   if (b > a)
   {
      g = gcd(b, a);
   }
   else*/ if (b == 0)
   {
      g = a;
   }
   else
   {
      g = gcd(b, a % b);
   }
   return g;
}

int main(int argc, char* argv[])
{
   if (argc != 3)
   {
      cout << "Usage: " << argv[0] << " a b\n";
      return 1;
   }
   int num1 = atoi(argv[1]);
   int num2 = atoi(argv[2]);

   cout << "The greatest common divisor of " << num1;
   cout << " and " << num2;
   cout << " is " << gcd(num1, num2) << endl;

   return 0;
}

