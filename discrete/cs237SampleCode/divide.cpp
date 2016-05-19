#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void divide(int a, int d, int& q, int& r)
{
   q = a / d; // div
   r = a % d; // mod
}

int main(int argc, char* argv[])
{
   int a = (argc > 1) ? atoi(argv[1]) : 1;
   int d = (argc > 2) ? atoi(argv[2]) : 1;
   int q = 0;
   int r = 0;

   divide(a, d, q, r);

   cout << setw(10) << a << " div " << d << " = " << q << endl;
   cout << setw(10) << a << " mod " << d << " = " << r << endl << endl;

   cout << setw(10) << "a" << " = " << setw(6) << "d" << " *"
        << setw(10) << "q" << " +" << setw(6) << "r" << endl;
   cout << setw(10) <<  a  << " = " << setw(6) <<  d  << " *"
        << setw(10) <<  q  << " +" << setw(6) <<  r  << endl;

   return 0;
}
