#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

const long NUM = 3000;

int main(int argc, char* argv[])
{
   long num = ((argc < 2) ? NUM : atol(argv[1]));

   double SUM = 0.0;

   for (int n = 0; n < num; n++)
   {
      SUM += ((1.0 / (2 * n + 1)) * pow(-1, n) * 4);
#ifdef SHOW      
      cout << SUM << endl;
#endif
   }
   cout << "After " << num << " iterations, sum = " << SUM << endl;

   return 0;
}
