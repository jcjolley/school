/***********************************************************************
 * Program:
 *    Exploration 3, simple RSA
 *    Brother Neff, CS237
 *
 * Author:
 *    Amanda Clark
 *
 * Collaborators:
 *    James Nelson, Bryce Call, Jordan Jensen
 *
 * Summary:
 *    RSA Encryption/Decryption without huge nubmers
 *    Compile with:
 *      g++ -c rsa.cpp
 ***********************************************************************/

/***********************************************************************
 * RSA Encryption/Decryption
 ***********************************************************************/

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

/***********************************************************************
 * Finds b^n % m. This is basically algorithm 5 in Rosen's book, but
 * instead of constructing a string that is the binary representation
 * of n, we just use division and mod by 2.
 ***********************************************************************/
int modPow(int b, int n, int m)
{
   int x = 1;
   int power = b % m;

   while (n > 0)
   {
      // If lowest digit of n is a binary 1:
      if (n % 2 == 1)
      {
         x = (x * power) % m;
      }
      power = (power * power) % m;
      n /= 2;
   }
   
   return x;
}

/***********************************************************************
 * Computes the gcd(a, b) and returns it. It also computes the modular
 * multiplicative inverses of a and b mod each other and returns them
 * by reference stored in oldOldS and oldOldT respectively.
 ***********************************************************************/
int extendedEuclideanGCD(int a, int b, int &oldOldS, int &oldOldT)
{
   // Initialize all of the variables to be used.
   int q;
   int r;
   int s;
   int t;
   int x = a;
   int y = b;
   oldOldS = 1;
   int oldS = 0;
   oldOldT = 0;
   int oldT = 1;

   // Run through the extended Euclidean algorithm.
   while (y != 0)
   {
      q = x / y;
      r = x % y;
      x = y;
      y = r;
      s = oldOldS - q * oldS;
      t = oldOldT - q * oldT;
      oldOldS = oldS;
      oldOldT = oldT;
      oldS = s;
      oldT = t;
   }
   
   // x = gcd(a,b)
   // (oldolds)a + (oldoldt)b = x
   return x;
}

/******************************************************************************
 * finds s such that a * s is congruent to 1 (mod m)
 *****************************************************************************/
int findInverse(int a, int m)
{
   int s;
   int t;

   // Make sure that the two numbers passed in are actually relatively prime.
   assert(extendedEuclideanGCD(a, m, s, t) == 1);

   // Make s positive.
   while (s < 0)
   {
      s += m;
   }
   
   return s;
}

/*****************************************************************************
 * Run it through its paces.
 *****************************************************************************/
int main(int argc, char* argv[])
{
   if (argc < 5)
   {
      cout << "Usage: " << argv[0] << " p q e message\n";
      return 1;
   }

   int p = atoi(argv[1]);
   int q = atoi(argv[2]);
   int n = p * q;
   int e = atoi(argv[3]);
   int d = 0;

   char* message = argv[4];
   int offset = 'A';    // offset for conversion without spaces
   bool spaces = false; // true => there are spaces in the message

   int length = strlen(message);

   if (isalpha(message[0]))
   {
      int size = (int) (ceil(length / 2.0));
      int numeric[size];
      int number;

      for (int i = 0; i < length; i++)
      {
         // is there a space?
         if (message[i] == ' ')
         {
            spaces = true;
            offset--;
            break;
         }
      }

      cerr << "RSA Encryption:\n\n";

      cerr << "Translate the letters in '" << message << "' into their "
           << "numerical\nequivalents and then group the numbers into "
           << "blocks of four, result is:\n";

      for (int i = 0; i < length; i++)
      {
         message[i] = toupper(message[i]); // Change to all upper case
         if (message[i] == ' ')
         {
            number = 0; // spaces translate as zero
         }
         else
         {
            number = message[i] - offset; // find numeric equivalent
         }
         if (i % 2 == 0)
         {
            numeric[i / 2] = number * 100; // 2 hundreds digits
         }
         else
         {
            numeric[i / 2] += number; // 2 tens digits
         }
      }

      // output the converted letters as a number with leading zeros
      for (int i = 0; i < size; i++)
      {
         cout << setfill('0') << setw(4) << numeric[i] << " ";
      }
      cout << endl;
      cout.flush();

      cerr << "\nEncrypt each block using the mapping C = M^e mod n, ";
      cerr << "result is:\n";

      for (int i = 0; i < size; i++)
      {
         cout << setfill('0') << setw(4) << modPow(numeric[i], e, n)
              << " ";
      }
      cout << endl;
   }
   else
   {
      cerr << "RSA Decryption:\n\n";

      length = argc - 4;
      int numeric[length];

      for (int i = 0; i < length; i++)
      {
         numeric[i] = atoi(argv[i + 4]);
      }

      cerr << "Find the inverse of " << e << " modulo " << p - 1 << " * "
           << q - 1 << " = " << ((p - 1) * (q - 1)) << ", result is: ";
      d = findInverse(e, ((p - 1) * (q - 1)));
      cerr << d << endl << endl;

      cerr << "Decrypt the message ";
      for (int i = 0; i < length; i++)
      {
         cerr << setfill('0') << setw(4) << numeric[i] << " ";
      }

      cerr << "\nusing fast modular exponentiation to compute P = C^"
           << d << " mod " << n << ", result is:\n";

      for (int i = 0; i < length; i++)
      {
         numeric[i] = modPow(numeric[i], d, n);
         cerr << setfill('0') << setw(4) << numeric[i] << " ";
      }
      cerr << endl;
      cerr.flush();

      cerr << "\nTranslate back to English letters, result is:\n";
      cerr.flush();

      if (d > 1000) offset--;

      for (int i = 0; i < length * 2; i++)
      {
         char c = ((i % 2 == 0) ?
                   (numeric[i / 2] / 100) + offset
                   :
                   (numeric[i / 2] % 100) + offset);
         cout << ((c < 'A') ? ' ' : c);
      }
      cout << endl;
   }

   return 0;
}
