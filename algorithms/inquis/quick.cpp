#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

/* Adapted from http://rosettacode.org/wiki/Sorting_algorithms/Quicksort#C */
void quick_sort (int *arr, int size, long long & count)
{
   int left = 0;
   int right = size - 1;
   int pivot;

   if (size < 2)
     return;

   pivot = arr[ size / 2 ];
	while (true)	
	{
		while (arr[left] < pivot)
		{
			count++;
			left++; 
		} 
		while (arr[right] > pivot)
		{
		   count++;
			right --;
		}
		if (left >= right)
			break;
      
      count++;
		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;

		left++;
		right--;
   }

   quick_sort(arr, left, count);
   quick_sort(arr + left, size - left, count);
}

int main(int argc, char** argv)
{
   if (argc != 3)
   {
      cout << "USAGE: quick [n] [numRuns]" << endl;
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
	quick_sort(arr[run], n, count);
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
