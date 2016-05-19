#include <cassert>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <values.h>
using namespace std;

/********************************************************************
 * Computes C(n, k) by a clever algorithm using a 1-dimensional table
 * Input: A pair of nonnegative integers n >= k >= 0
 * Output: The value of C(n, k)
 ********************************************************************/
int binomial2(int T[], int size, int n, int k)
{
   assert(n < size);
   int u;
   for (int i = 0; i <= n; i++)
   {
      if (i <= k)   // in the triangular part
      {
         T[i] = 1;  // the diagonal element
         u = i - 1; // the rightmost element to be computed
      }
      else
      {
         u = k;     // in the rectangular part
      }
      // overwrite the preceding row moving right to left.
      for (int j = u; j >= 1; j--)
         T[j] += T[j - 1];
   }
   return T[k];
}

int main(int argc, char* argv[])
{
   if (argc < 2)
   {
      cout << "Usage: " << argv[0] << " n\n";
      return 1;
   }
   else
   {
      int n = atoi(argv[1]);
      assert(n <= 32);
      int T[100];

      for (int r = 0; r < n; r++)
      {
         binomial2(T, 100, r, r);

         // determine primeness
         bool prime = true;
         for (int i = 1; i < r; i++)
            if (T[i] % r != 0)
            {
               prime = false;
               break;
            }
         if (prime && r > 1) cout << "\E[22;32m";

         for (int k = 0; k <= r; k++)
            cout << T[k] << " ";
         cout << endl;

         if (prime && r > 1) cout << "\E[0m";
      }
      return 0;
   }
}
