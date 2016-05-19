#include <cstdlib>
#include <iostream>
busing namespace std;

int showAll()
{
   for (int i = 0; i < 1001; i++)
   {
      cout << i << " <-> ("
           << (i % 7) << ", "
           << (i % 11) << ", "
           << (i % 13) << ")" << endl;
   }
}

int crtmagic(int a, int b, int c)
{
   int x = ((a * -286) + (b * 364) + (c * -77)) % 1001;
   return ((x < 0) ? (x + 1001) : x);
}

int main(int argc, char* argv[])
{
   if (argc == 1)
   {
      showAll();
   }
   else
   {
      int a = ((argc > 1) ? atoi(argv[1]) : 0);
      int b = ((argc > 2) ? atoi(argv[2]) : 0);
      int c = ((argc > 3) ? atoi(argv[3]) : 0);

      cout << crtmagic(a, b, c) << endl;
   }

   return 0;
}
