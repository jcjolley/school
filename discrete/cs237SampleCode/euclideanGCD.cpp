#include <iostream>
#include <cstdlib>
using namespace std;

int euclideanGCD(int a, int d)
{
   int x = a;
   int y = d;

   while (y != 0)
   {
      int q = x / y;
      int r = x % y;
#ifdef SHOW
      cout << x << " = " << y << " * " << q << " + " << r << endl;
#endif
      x = y;
      y = r;
   }
   return x;
}

int main(int argc, char* argv[])
{
   if (argc != 3)
   {
      cerr << "Usage: " << argv[0] << " a d\n";
      return 1;
   }
   int a = atoi(argv[1]);
   int d = atoi(argv[2]);

   cout << "gcd(" << a << ", " << d << ") = "
        << euclideanGCD(a, d) << endl;
   return 0;
}
