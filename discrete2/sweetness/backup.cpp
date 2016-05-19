#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <limits>
#include <set>
#include <cstdlib>
#include <vector>
#include <numeric>
#include <pthread.h>
#include <cstring>
using namespace std;

//MUST BE 4
#define NUM_THREADS 4
const int MAXSIZE = numeric_limits<int>::max();


/**************************************************************
* Struct to hold our answer in
***************************************************************/
struct Answer
{
   int c;
   int minRange;
   float sweetness;
   float percentage;
   float stdDev;
};

/****************************************************
* Initialize the Sieve of Eratosthenes
* Every true left in the array is prime
* Code adapted from pseudocode at 
* http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
****************************************************/
void initSieve(bool sieve[])
{
   cout << "Priming sieve." << endl;
   fill(sieve, sieve + MAXSIZE, true);
   int MAX = sqrt(MAXSIZE);

   for (int i = 2; i < MAX; i++)
      if (sieve[i])
         for (unsigned int j = i * i; j < MAXSIZE; j += i)
            sieve[j] = false;
   cout << "Sieve primed." << endl;
}

/*****************************************************************************
* Returns the percent of the results from x^2 + x + c when the range
* of inputs to x is 10,000 wide.
****************************************************************************/
float percentPrimesInRange(bool sieve[], int minRange, int c)
{
   set<int> found;
   unsigned int temp = 0;
   int maxRange = minRange + 10000;
   
   //run the numbers and check for primes
   for (int x = minRange; x < maxRange; x++)
   {
      temp = abs(x * x + x + c);
      if (temp > MAXSIZE)
         break;
      if (sieve[temp])
         found.insert(temp);
   }

   float percentage = (float)found.size() / 10000;

   //we only want the good sweetness values
   if (percentage > 0.5)
   {
      ofstream fout;
      fout.open("constantsFound.txt", fstream::app);
      fout << c << " ";
      fout.close();
   }
   return percentage;
}

/****************************************************
* What I've learned
****************************************************/
string learned() 
{
   return "replace me";
}

/****************************************************
* Gives usage information
****************************************************/
void usage()
{
   cout << "USAGE: sweetness x [c]\n"
        << "   x: The minimum of the 10,000 wide range of inputs to x\n"
        << "   Without a c provided the program will run \n"
        << "   on a range of c's from -5,000,000 to 5,000,000\n";
}

void *BusyWork(void *t)
{
   int i;
   long tid;
   double result = 0.0;
   tid = (long)t;
   printf("Thread %ld starting...\n", tid);
   for (i = 0; i < 1000000; i++)
   {
      result = result + sin(i) * tan(i);
   }
   printf("Thread %ld done. Result = %e\n", tid, result);
   pthread_exit((void *) t);
}

/************************************************************
* Struct to pass around the arguments to the threads
*************************************************************/
struct threadData
{
   bool *sieve;
   int minRange;
   int cStart;
   int cEnd;
   int thread;
   char outFile[10];
};

/***************************************************************
* Helper function that cycles through the c's from -5 million to 5 million
* Threads call this.
***************************************************************/
void *changeC(void *voidPtrData)
{
   threadData *data = new threadData;
   data = (struct threadData *)voidPtrData;
   cout << "Thread " << data->thread << " searching inputs from " << data->minRange << " to " << data->minRange + 10000 <<  " for c range: " << data->cStart << " to " << data->cEnd << endl;
   for (int c = data->cStart; c < data->cEnd; c++)
      percentPrimesInRange(data->sieve, data->minRange, c);
   pthread_exit(NULL);
}

/*******************************************************************
* Works the problem using threads!  This was a piece of work, and
* hope it counts as something creative. I learned a lot about pthreads!
* code adapted from https://computing.llnl.gov/tutorials/pthreads/
*******************************************************************/
void multiThread(bool sieve[], int minRange, set<int> &cSet)
{
   struct threadData data[NUM_THREADS];
   pthread_t thread[NUM_THREADS];
   pthread_attr_t attr;
   int rc;
   long t;
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
   ifstream fin;
   char output[10];

   //setup the arguments for the threads
   for (int i = 0; i < NUM_THREADS; i++)
   {
      data[i].sieve = sieve;
      data[i].minRange = minRange;
      data[i].thread = i + 1;
      switch (i)
      {
      case 0:
         data[i].cStart = -4999999;
         data[i].cEnd   = -2500001;
         break;
      case 1:
         data[i].cStart = -2499999;
         data[i].cEnd   = -1;
         break;
      case 2:
         data[i].cStart = 1;
         data[i].cEnd   = 2499999;
         break;
      case 3:
         data[i].cStart = 2500001;
         data[i].cEnd   = 5000000;
         break;
      }
   }

   //create the threads
   for (t = 0; t < NUM_THREADS; t++)
   {
      rc = pthread_create(&thread[t], &attr, changeC, (void *) &data[t]);
      if (rc)
      {
         cerr << "ERROR thread " << t << " can't init" << endl;
         exit(-1);
      }
   }

   //free the joinable attribute and wait for the other threads
   pthread_attr_destroy(&attr);
   for (t = 0; t < NUM_THREADS; t++)
   {
      rc = pthread_join(thread[t], NULL);
      if (rc) 
      {
         cerr << "ERROR: thread can't join" << endl;
         exit(-1);
      }
   }

   //collect our c's from the file
   fin.open("constantsFound.txt");

   while (fin >> output)
      cSet.insert(atoi(output));
   
   cout << "C's found: ";
   for (set<int>::iterator it = cSet.begin(); it != cSet.end(); it++)
      cout << *it << " ";
   cout << endl;
}


/******************************************************************
* Tests the c's we found for x inputs of [0-10000] to [10000-20000]
*******************************************************************/
void *testingC(void *voidPtrData)
{
   threadData *data = new threadData;
   data = (struct threadData *)voidPtrData;
   cout << "Thread " << data->thread << " searching inputs from " << data->minRange << " to " << data->minRange + 10000 <<  " for c: "<< data->cStart << endl;
   set<int> found;
   unsigned int temp = 0;
   int maxRange = data->minRange + 10000;
   int c = data->cStart;
   float sweetness = 0;
   Answer *answer = new Answer;
   answer->sweetness = 0;
   int gap = 0;
   vector<int> gaps;
   double sum;
   double mean;
   double sqSum;
   double stdDev;

   //cout << "Testing c: " << c << endl;
   for (int x = data->minRange; x < maxRange; x++)
   {
      temp = abs(x * x + x + c);
      if (temp > MAXSIZE)
         break;
      if (data->sieve[temp])
      {
         found.insert(temp);
         if (gap)
         {
            gaps.push_back(gap);
            gap = 0;
         }
      }
      else
         gap++;
   }

   float percentage = (float)found.size() / 10000;
   
   if (percentage > .53)
   {
      //calculate sweetness.  Our range is always 10,000 wide.
       sum = accumulate(gaps.begin(), gaps.end(), 0.0);
       mean = sum / gaps.size();
       sqSum = inner_product(gaps.begin(), gaps.end(), gaps.begin(), 0.0);
       stdDev = sqrt(sqSum / gaps.size() - mean * mean);

      sweetness = percentage / stdDev;
   }

   //find the best sweetness and the best C
   if (sweetness > answer->sweetness)
   {
      answer->sweetness = sweetness;
      answer->c = c;
      answer->stdDev = stdDev;
      answer->percentage = percentage;
   }

   ofstream fout;
      fout.open(data->outFile);
      fout << answer->sweetness  << " " << answer->minRange << " "
           << answer->c << " " << answer->percentage << " "
           << answer->stdDev << endl;
      fout.close();
   pthread_exit(NULL);
}

Answer multiThreadCs(bool sieve[], int minRange, set<int> cSet)
{
   int numThreads = cSet.size();
   struct threadData data[numThreads];
   int count = 0;
   pthread_t thread[numThreads];
   pthread_attr_t attr;
   int rc;
   long t;
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
   Answer answers[numThreads];
   Answer answer;

   for (std::set<int>::iterator it = cSet.begin(); it != cSet.end();  ++it)
   {
      data[count].sieve = sieve;
      data[count].minRange = minRange;
      data[count].thread = count + 1;
      data[count].outFile[0] = 'o';
      data[count].outFile[1] = 'u';
      data[count].outFile[2] = 't';
      data[count].outFile[3] = (char)count;   
      data[count++].cStart = *it;
   }
   
   //create the threads
   for (t = 0; t < numThreads; t++)
   {
      rc = pthread_create(&thread[t], &attr, testingC, (void *) &data[t]);
      if (rc)
      {
         cerr << "ERROR thread " << t << " can't init" << endl;
         exit(-1);
      }
   }

   //free the joinable attribute and wait for the other threads
   pthread_attr_destroy(&attr);
   for (t = 0; t < numThreads; t++)
   {
      rc = pthread_join(thread[t], NULL);
      if (rc) 
      {
         cerr << "ERROR: thread can't join" << endl;
         exit(-1);
      }
   }

   for (int i = 0; i < numThreads; i++)
      if (answer.sweetness < answers[i].sweetness)
         answer = answers[i];
   return answer;
}

/******************************************************************************
* Main.
******************************************************************************/
int main (int argc, char *argv[])
{

   if (argc < 2 || argc > 3)
   {
      usage();
      exit(1);
   }
   bool *sieve = new bool[MAXSIZE];
   set<int> cSet;

   initSieve(sieve);

   Answer temp;
   Answer answer;
   answer.sweetness = 0;

   if (argc == 2)
   {
      cout << "\nCalculating Sweetness. x: " << atoi(argv[1])
           << " - " << atoi(argv[1]) + 10000 << endl;

      multiThread(sieve, atoi(argv[1]), cSet);

      cout << "\nTesting will now begin on the c's "
           << "for the x ranges starting between [0-10000] - [10000-20000]" << endl;
      for (int minRange = 0; minRange < 10000; minRange++)
      {
         multiThreadCs(sieve, minRange, cSet);
      }

      char inFile[5] = "out";
      for (int i = 0; i < cSet.size(); i++)
      {  
         inFile[3] = (char)i;
         ifstream fin;
         fin.open(inFile);
         while (!fin.eof())
         {
           fin >> temp.sweetness >> temp.minRange 
               >> temp.c >> temp.percentage 
               >> temp.stdDev;
         }
         if (answer.sweetness < temp.sweetness)
            answer = temp;
      }

      cout << "\n\nThe highest sweetness is: " << answer.sweetness << endl;
      cout << "The minimum of the range of inputs for x: " << answer.minRange << endl;
      cout << "The c for this sweetness is: " << answer.c << endl;
      cout << "The percentage of outputs that were prime: " << answer.percentage << endl;
      cout << "The standard deviation of the gaps is: " << answer.stdDev;
   }
   else
   {
      cSet.insert(atoi(argv[2]));
      cout << "\nCalculating Sweetness. x: " << argv[1]
           << " - " << atoi(argv[1]) + 10000 << " c: " << argv[2] << endl;
      multiThreadCs(sieve, atoi(argv[1]), cSet);
      
      char inFile[5] = "out0";
      ifstream fin;
      fin.open(inFile);
      while (!fin.eof())
      {
        fin >> answer.sweetness >> answer.minRange 
            >> answer.c >> answer.percentage 
            >> answer.stdDev;
      }

      cout << "\n\nThe highest sweetness is: " << answer.sweetness << endl;
      cout << "The minimum of the range of inputs for x: " << answer.minRange << endl;
      cout << "The c for this sweetness is: " << answer.c << endl;
      cout << "The percentage of outputs that were prime: " << answer.percentage << endl;
      cout << "The standard deviation of the gaps is: " << answer.stdDev << endl;
   }
   delete [] sieve;
   return 0;
}
