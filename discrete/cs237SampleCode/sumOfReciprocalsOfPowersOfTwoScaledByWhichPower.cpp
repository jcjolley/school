#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

long double sumOfReciprocalsOfPowersOfTwoScaledByWhichPower(long numIterations)
{
   long double sum = 0.0;
   for (long n = 1; n <= numIterations; n++)
   {
#ifdef SHOW
      cout << sum << endl;
#endif      
      sum += n / pow(2.0, n);
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
      cout.setf(ios::fixed);
      cout.setf(ios::showpoint);
      cout.precision(19);
      cout << sumOfReciprocalsOfPowersOfTwoScaledByWhichPower(atol(argv[1]))
           << endl;
      return 0;
   }
}
