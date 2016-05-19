#include <iostream>
#include <cstdlib>
#include <time.h>

#define RUNS 1000
using namespace std;
int main(int argc, char** argv)
{
   if (argc != 2)
   {
      cout << "USAGE: bubble [n]" << endl;
      exit(1);
   }

   srand(time(NULL));
   long long count = 0;
   int n = atoi(argv[1]);
   int ** arr = new int*[RUNS];

   //create 100 random arrays of length n
   for (int i = 0; i < RUNS; i++)
   {
      arr[i] = new int[n];
      for (int j = 0; j < n; j++)
      {
         arr[i][j] = rand() % 100;
      }
   }

   //start RUNS bubble sorts
	for (int run = 0; run < RUNS; run++)
	{
		  bool swapped = true; 
		  while (swapped)
		  {
		     swapped = false;
		     for(int i = 0; i < n - 1; i++)
			  {
					 count++; //this comparison is the critical op
					 if (arr[run][i] > arr[run][i + 1])
					 {
					     int temp = arr[run][i];
						  arr[run][i] = arr[run][i + 1];
						  arr[run][i + 1] = temp; 
						  swapped = true;
					 }
			  }
		  }
	}

   //clean up the mess we made of the heap
   for (int i = 0; i < RUNS; i++)
   {
      delete [] arr[i];
   }
   delete [] arr;

   //print out the average number of critical operations.
   cout << count / RUNS << endl;
}
