#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

double limitingRadius(long numSides)
{
   double radius = 1.0;
   for (long i = 3; i < numSides; i++)
   {
#ifdef SHOW
      cout << radius << endl;
#endif      
      radius /= cos(M_PI / (double) i);
   }
   return radius;
}

int main(int argc, const char* argv[])
{
   if (argc < 2)
   {
      cerr << "Usage: " << argv[0] << " n\n";
      return 1;
   }
   else
   {
      cout << limitingRadius(atol(argv[1])) << endl;
      return 0;
   }
}
