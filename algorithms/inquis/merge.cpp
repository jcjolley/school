#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void merge (int * arr, int size, int middle, long long & count)
{
   int j = 0; 
   int k = 0;
   int * sorted = new int[size];
   for (int i = 0, j = middle, k = 0; k < size; k++)
   {
      count++; //This is the critical operation
      if (j == size)
         sorted[k] = arr[i++];
      else if (i == middle || arr[j] < arr[i])
         sorted[k] = arr[j++];
      else
         sorted[k] = arr[i++];
   }
        
   for (int i = 0; i < size; i++)
      arr[i] = sorted[i];

   delete [] sorted;
}

void merge_sort (int * arr, int size, long long & count)
{
   if (size < 2)
      return;
   int middle = size / 2;
   merge_sort(arr, middle, count);
   merge_sort(arr + middle, size - middle, count);
   merge(arr, size, middle, count);
}


int main(int argc, char** argv)
{
   if (argc != 3)
   {
      cout << "USAGE: merge [n] [numRuns]" << endl;
      exit(1);
   }

   srand(time(NULL));
   long long count = 0;
   int n = atoi(argv[1]);
	const int RUNS = atoi(argv[2]);
   int ** arr = new int*[RUNS];

   //create RUNS random arrays of length n
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
	merge_sort(arr[run], n, count);
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
