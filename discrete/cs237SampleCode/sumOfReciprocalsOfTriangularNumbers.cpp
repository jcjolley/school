#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

double sumOfReciprocalsOfTriangularNumbers(long numIterations)
{
   double sum = 0.0;
   long tSum = 0;
   for (long i = 1; i <= numIterations; i++)
   {
#ifdef SHOW
      cout << sum << endl;
#endif      
      tSum += i;
      sum += 1.0 / (double) tSum;
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
      cout << sumOfReciprocalsOfTriangularNumbers(atol(argv[1])) << endl;
      return 0;
   }
}
