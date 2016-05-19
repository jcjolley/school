#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <limits>
#include <set>
#include <cstdlib>
#include <vector>
#include <numeric>
#include <pthread.h>
#include <ctime>
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
   float sweetness;   //calculated as percentage/stdDev
   float percentage;
   float stdDev;
};

/************************************************************
* Struct to pass arguments into the threads
*************************************************************/
struct threadArguments
{
   bool *sieve;
   int minRange;
   int cStart;
   int cEnd;
   int thread;
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
   time_t timer;
   timer = time(0);

   for (int i = 2; i < MAX; i++)
   {
      if (sieve[i])
      {
         for (unsigned int j = i * i; j < MAXSIZE; j += i)
         {
            sieve[j] = false;
         }
      }
   }
   
   timer = time(0) - timer;
   cout << "Sieve primed in " << timer << " seconds." << endl;
}

/*****************************************************************************
* Returns the percent of the results from x^2 + x + c when the range
* of inputs to x is 10,000 wide.
****************************************************************************/
float percentPrimesInRange(bool sieve[], int minRange, int c)
{
   set<int> found;
   unsigned int result = 0;
   int maxRange = minRange + 10000;
   float percentage;

   //run the numbers and check for primes
   for (int x = minRange; x < maxRange; x++)
   {
      result = abs(x * x + x + c);
      if (result > MAXSIZE)
      {
         break;
      }
      if (sieve[result])
      {
         found.insert(result);
      }
   }

   percentage = (float)found.size() / 10000;

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

/***************************************************************
* Helper function that cycles through the c's from -5 million to 5 million
* Threads call this.
***************************************************************/
void *iterateThroughConstants(void *voidPtrData)
{
   threadArguments *data;
   data = (struct threadArguments *)voidPtrData;

   for (int c = data->cStart; c < data->cEnd; c++)
   {
      percentPrimesInRange(data->sieve, data->minRange, c);
   }

   pthread_exit(NULL);
}

/*******************************************************************
* Works the problem using threads!  This was a piece of work, and
* hope it counts as something creative. I learned a lot about pthreads!
* code adapted from https://computing.llnl.gov/tutorials/pthreads/
*******************************************************************/
void multiThreadIterateConstants(bool sieve[], int minRange, set<int> &cSet)
{
   struct threadArguments data[NUM_THREADS];
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
      rc = pthread_create(&thread[t], &attr, iterateThroughConstants, (void *) &data[t]);
      if (rc)
      {
         cerr << "ERROR thread " << t << " can't init" << endl;
         exit(-1);
      }

      cout << "Thread " << t << " searching inputs from "
           << data[t].minRange << " to " << data[t].minRange + 10000
           <<  " for c range: " << data[t].cStart << " to " << data[t].cEnd << endl;
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
   {
      cSet.insert(atoi(output));
   }

   cout << "\nConstants with better than 50% prime generation: ";

   for (set<int>::iterator it = cSet.begin(); it != cSet.end(); it++)
   {
      cout << *it << " ";
   }

   cout << endl;
}

/******************************************************************
* Tests the c's we found for x inputs of [0-10000] to [10000-20000]
*******************************************************************/
Answer calcSweetestConstant(bool sieve[], int minRange, set<int> &cSet)
{
   set<int> found;
   unsigned int result = 0;
   int maxRange = minRange + 10000;
   int c = 0;
   float sweetness = 0;
   Answer answer;
   int gap = 0;
   vector<int> gaps;
   double sum;
   double mean;
   double sqSum;
   double stdDev;
   float percentage;

   //test all c's
   for (std::set<int>::iterator it = cSet.begin(); it != cSet.end();  ++it)
   {
      c = *it;
      found.clear();
      gaps.clear();
      //cout << "Testing c: " << c << endl;
      for (int x = minRange; x < maxRange; x++)
      {
         result = abs(x * x + x + c);
         //don't overflow
         if (result > MAXSIZE)
         {
            break;
         }
         if (sieve[result])
         {
            //the set ensures unique primes
            found.insert(result);

            //don't push back a 'gap' of 0
            if (gap)
            {
               gaps.push_back(gap);
               gap = 0;
            }
         }
         else
         {
            gap++;
         }
      }

      percentage = (float)found.size() / 10000;

      //only calc standard deviation for the good percentages
      if (percentage > .53)
      {
         //calculate standard deviation
         sum = accumulate(gaps.begin(), gaps.end(), 0.0);
         mean = sum / gaps.size();
         sqSum = inner_product(gaps.begin(), gaps.end(), gaps.begin(), 0.0);
         stdDev = sqrt(sqSum / gaps.size() - mean * mean);

         sweetness = percentage / stdDev;
      }

      //find the best sweetness and the best c
      if (sweetness > answer.sweetness)
      {
         answer.sweetness = sweetness;
         answer.c = c;
         answer.stdDev = stdDev;
         answer.percentage = percentage;
         answer.minRange = minRange;
      }
   }
   return answer;
}

/**********************************************************************
*  Display the results from our answer struct
**********************************************************************/
void displayResults(Answer &answer)
{
   cout << "\n\nThe highest sweetness is: " << answer.sweetness << endl;
   cout << "The minimum of the range of inputs for x: " << answer.minRange << endl;
   cout << "The c for this sweetness is: " << answer.c << endl;
   cout << "The percentage of outputs that were prime: " << answer.percentage << endl;
   cout << "The standard deviation of the gaps is: " << answer.stdDev << endl;
}


/**********************************************************************
*  When we get 2 command line args run this
**********************************************************************/
void mainArg2(bool sieve[], int minRange, set<int> cSet)
{
   Answer temp;
   Answer answer;
   answer.sweetness = 0;

   cout << "\nCalculating Sweetness. x: " << minRange
        << " - " << minRange + 10000 << endl;

   multiThreadIterateConstants(sieve, minRange, cSet);

   cout << "\nTesting will now begin on the constants listed above "
        << "for the x ranges starting between [0-10000] - [10000-20000]" << endl;

   for (minRange = 0; minRange < 10000; minRange++)
   {
      temp = calcSweetestConstant(sieve, minRange, cSet);
      if (answer.sweetness < temp.sweetness)
         answer = temp;
   }

   displayResults(answer);
}

/**********************************************************************
* When we get 3 command line args, run this
**********************************************************************/
void mainArg3(bool sieve[], int minRange, int c, set<int> cSet)
{
   Answer answer;

   cSet.insert(c);

   cout << "\nCalculating Sweetness. x: " << minRange
        << " - " << minRange + 10000 << " c: " << c << endl;
   
   answer = calcSweetestConstant(sieve, minRange, cSet);
   
   displayResults(answer);
}

/****************************************************
* What I've learned
****************************************************/
void learned()
{
   cout << "*************************************************************\n"
        << "|                        Best Sweetness                     |\n"
        << "|===========================================================|\n"
        << "|                    The highest sweetness* is: 0.42333     |\n"
        << "|     The minimum of the range of inputs for x: 12          |\n"
        << "|                  The c for this sweetness is: -1354363    |\n"
        << "|    The percentage of results that were prime: 0.5357      |\n"
        << "|        The standard deviation of the gaps is: 1.26544     |\n"
        << "|                                                           |\n"
        << "|       *Sweetness = percentage / standard deviation        |\n"
        << "*************************************************************\n";

   cout << "     This was a fun exploration. I learned a lot. Working with "
        << "Brenton and Adam, we learned about some of the qualities of a "
        << "good prime generating constant. For example, if the constant is "
        << "even you will never get a good prime generation percentage. "
        << "We also learned that the best constants will be co-primes! This "
        << "was verified by our results. We also learned that the best primes "
        << "are found with constants in the -3,000,000 to 1,000,000 range. "
        << "We left our range from -5,000,000 to 5,000,000 to match what was "
        << "said in class.\n"
        << "My top 5 constants are: -2639113 -1776433 -1354363 -752293 247757\n"
        << "Feel free to ask me about what else we've learned.\n\n";
}

/****************************************************
* Gives usage information
****************************************************/
void usage()
{
   cout << "USAGE: sweetness x [c]\n"
        << "   To replicate my best results run `sweetness 0 -1354363`\n"
        << "   To do the full search and get my best results run "
        << "`sweetness 0`\n\n"
        << "   x: The minimum of the 10,000 wide range of inputs to x\n"
        << "   When c is not provided, the program will display the sweetest \n"
        << "   x and c combination using a range of c's from -5,000,000 to "
        << "5,000,000.\n\n"
        << "   With an x and c pair provided the program will compute the \n"
        << "   sweetness value of this pair.\n\n";
}

/******************************************************************************
* Main.
******************************************************************************/
int main (int argc, char *argv[])
{
   if (argc < 2 || argc > 3)
   {
      learned();
      usage();
      exit(1);
   }

   bool *sieve = new bool[MAXSIZE];
   set<int> cSet;

   initSieve(sieve);

   if (argc == 2)
   {
      mainArg2(sieve, atoi(argv[1]), cSet);
   }
   else
   {
      mainArg3(sieve, atoi(argv[1]), atoi(argv[2]), cSet);
   }

   delete [] sieve;
   return 0;
}
