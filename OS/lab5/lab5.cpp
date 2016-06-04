/***********************************************************************
* Program:
*    Lab ProducerConsumer  
*    Brother Jones, CS 345
* Author:
*    Joshua Jolley
*
* Summary:
*    Producer/Consumer with semaphores and a mutex
************************************************************************/
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <cstdlib>

#define BUFFER_SIZE 5

using namespace std;

typedef int bufferItem;
int in = 0;
int out = 0;
bufferItem buffer[BUFFER_SIZE];
pthread_mutex_t bufferMutex;
sem_t empty;
sem_t full;

/************************************************************************
* FUNCTION: producer 
* This is the function our producer threads call
************************************************************************/
void *producer (void *param)
{
   bufferItem itemProduced;
   while (true)
   {
      /* sleep for a random period of time */
      usleep(rand() % 150000);
      
      /* generate a random number */
      itemProduced= (rand()%100 );
      sem_wait(&empty);
      pthread_mutex_lock(&bufferMutex);
      
      /* insert item into shared global bufferand print what was done */
      buffer[in] = itemProduced;                                     //C
      in = (in + 1) % BUFFER_SIZE;                                   //C
      cout << "\t" << itemProduced << "\tP" << (long) param << endl; //C

      pthread_mutex_unlock(&bufferMutex);
      sem_post(&full);
   }
}

/************************************************************************
* FUNCTION: consumer 
* This is the function our consumer threads call.
************************************************************************/
void *consumer(void *param)
{
   bufferItem consumedItem;
   while (true)
   {
      /* sleep for a random period of time */
      usleep(rand() % 150000);
      sem_wait(&full);
      pthread_mutex_lock(&bufferMutex);

      /* consume item from shared global buffer and print what was done */
      consumedItem = buffer[out];                                      //C
      out = (out + 1) % BUFFER_SIZE;                                   //C
      cout << "\t\t\t" << consumedItem << "\tC" << (long)param << endl;//C

      pthread_mutex_unlock(&bufferMutex);
      sem_post(&empty);
   }
}

/************************************************************************
* FUNCTION: Main
* Our driver function.  Maybe George is a better name than Alfred.
************************************************************************/
int main (int argc, char *argv[])
{
   /*1. Check and get command line arguments argv[1], argv[2], argv[3]*/
   if (argc != 4)
   {
      cout << "USAGE: sleepTime producerThreads consumerThreads" << endl;
      exit(1);
   }

   int sleepTime = atoi(argv[1]);
   int numProducerThreads = atoi(argv[2]);
   int numConsumerThreads = atoi(argv[3]);
   int totalThreads = numProducerThreads + numConsumerThreads;
   int threadNum = 0;

   /*2. Initialize buffer [good for error checking but not really needed]*/
   for (int i = 0; i < BUFFER_SIZE; i++) 
   {
      buffer[i] = 0;
   }

   /*3. Initialize the mutexlockand semaphores */
   pthread_mutex_init(&bufferMutex, NULL);
   sem_init(&empty, 0, BUFFER_SIZE); 
   sem_init(&full, 0, BUFFER_SIZE); 

   cout << "     Produced  by P#  Consumed  by C#\n"
        << "     ========  =====  ========  =====" << endl;
   /*4. Create producer threads(s) */
   pthread_t *threads = new pthread_t[totalThreads];

   for(int i = 0; i < numProducerThreads; i++)
   {
      int err = pthread_create( &threads[threadNum++], NULL, producer, (void*) (i + 1));
      if (err)
      {
         cerr << "ERROR: Thread create failed with status " << err << endl;
         exit(1);
      }
   }

   /*5. Create consumer threads(s) */
   for(int i = 0; i < numConsumerThreads; i++)
   {
      int err = pthread_create( &threads[threadNum++], NULL, consumer, (void*) (i + 1));
      if (err)
      {
         cerr << "ERROR: Thread create failed with status " << err << endl;
         exit(1);
      }
   }

   /*6. Sleep [ to readmanual page, do:  man 3sleep ]*/
   sleep(sleepTime);

   /*7. Cancel threads[ pthread_cancel() ]*/
   for (int i = 0; i < totalThreads; i++)
   {
      pthread_cancel(threads[i]);
   }

   return 0;
}
