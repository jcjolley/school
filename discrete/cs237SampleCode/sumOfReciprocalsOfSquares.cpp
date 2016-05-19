#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

double sumOfReciprocalsOfSquares(long numIterations)
{
   double sum = 0.0;
   for (long i = 1; i <= numIterations; i++)
   {
#ifdef SHOW
      cout << sum << endl;
#endif      
      sum += 1.0 / (double) (i * i);
   }
   return sum;
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
      cout << sumOfReciprocalsOfSquares(atol(argv[1])) << endl;
      return 0;
   }
}
