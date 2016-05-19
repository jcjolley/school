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

   //start 100 selection sorts
   for (int run = 0; run < RUNS; run++)
   {
      int min = 0;
      for (int i = 0; i < n; i++) {
         for (int j = i, min = i; j < n; j++) {
            count++; //the comparison in this if is the critical operation
            if (arr[run][j] < arr[run][min]) {
               min = j;
            }
         }
      int temp = arr[run][i];
      arr[run][i] = arr[run][min];
      arr[run][min] = temp;
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