#if 0
   Exercise 2.3.77 on page 149:

   Show that the function f : Z+  x  Z+ --> Z+

   with f(m, n) = [(m + n - 2)(m + n - 1)/2] + m

   is one-to-one and onto.

   A little experimentation with this function shows the pattern.

   f(1,1) =  1   f(2,1) =  3   f(3,1) =  6   f(4,1) = 10   f(5,1) = 15

   f(1,2) =  2   f(2,2) =  5   f(3,2) =  9   f(4,2) = 14   f(5,2) = 20

   f(1,3) =  4   f(2,3) =  8   f(3,3) = 13   f(4,3) = 19   f(5,3) = 26

   f(1,4) =  7   f(2,4) = 12   f(3,4) = 18   f(4,4) = 25

   f(1,5) = 11   f(2,5) = 17   f(3,5) = 24

   f(1,6) = 16   f(2,6) = 23

   f(1,7) = 22

   It should be clear that the range of values this function takes on
   for a fixed value of m + n, say m + n = x, is

   (x - 2)(x - 1)                (x - 2)(x - 1)
   --------------  + 1  through  -------------- + (x - 1)
          2                             2

   since m can assume the values 1, 2, 3,...,(x - 1) under these
   conditions, and the first term in the formula is a fixed positive
   integer when m + n is fixed.

   To show that this function is one-to-one and onto, we merely need
   to show that the range of values for x + 1 picks up precisely
   where the range of values for x left off, i.e., that

   f(x - 1, 1) + 1 = f(1, x)

                     (x - 2)(x - 1) 
   f(x - 1, 1) + 1 = -------------- + (x - 1) + 1
                            2

                     x^2 - x + 2    (x - 1)x
                   = -----------  = --------  + 1  = f(1, x)
                         2             2

================================================================
#endif

#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

int f(int m, int n)
{
   int x = m + n;
   return (((x - 2) * (x - 1) / 2) + m);
}

void invert(int y, int& m, int& n)
{
   int x = 42; // what calculation REALLY goes here?
   m = y - ((x - 2) * (x - 1) / 2);
   n = x - m;
}

int main(int argc, char* argv[])
{
   int y = (argc > 1) ? atoi(argv[1]) : 0;

   if (y > 0)
   {
      int m = 0;
      int n = 0;
      invert(y, m, n);
      // check answer
      if (y == f(m, n))
      {
         cout << "m = " << m << ", n = " << n << endl;
      }
   }
   else
   {
      cout << "Usage: " << argv[0] << " y (> 0)\n";
   }

   return 0;
}
