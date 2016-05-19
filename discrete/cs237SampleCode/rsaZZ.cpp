/***********************************************************************
 * Program:
 *    Exploration 3, RSA with ZZ
 *    Brother Neff, CS237
 *
 * Author:
 *    Amanda Clark
 *
 * Collaborators:
 *    James Nelson, Bryce Call, Jordan Jensen
 *
 * Summary:
 *    RSA Encryption/Decryption Function Definitions using ZZ 
 *    Compile with:
 *      g++ -c rsaZZmain.cpp
 ***********************************************************************/

#include <cassert>
#include <cstdlib>
#include <NTL/ZZ.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>

NTL_CLIENT

/*****************************************************************************
 * Find b^n % m.
 *****************************************************************************/
ZZ modExp(ZZ b, ZZ n, ZZ m)
{
   return PowerMod(b % m, n, m);
}

/*****************************************************************************
 * Find s such that a * s is congruent to 1 (mod m).
 *****************************************************************************/
ZZ findInverse(ZZ a, ZZ m)
{
   return InvMod(a, m);
}

/****************************************************************************
 * Convert from a text message representing a base 27 number to a ZZ number.
 ****************************************************************************/
ZZ fromBase27(string message)
{
   // Start the power out for the end of the string.
   ZZ power = to_ZZ(1);
   ZZ total = to_ZZ(0);

   // Loop through the string from end to start and increase the power of 27.
   for (int i = message.length() - 1; i >= 0; power *= 27)
   {
      // Add the current letter multiplied by the current power of 27 to total.
      total += (message[i--] - '@') * power;
   }

   return total;
}

/****************************************************************************
 * Convert from a ZZ number to a base 27 number represented by a text message.
 ****************************************************************************/
string toBase27(ZZ n)
{
   // String value represented by n
   string retVal;

   // Loop through n by powers of 27 from the end to the beginning.
   for (ZZ i = n; i > 0; i /= 27)
   {
      retVal.insert(0, 1, (char)(i % 27 + '@'));
   }
   
   return retVal;
}

/****************************************************************************
 * Find a suitable e for a ZZ number that is the "totient" of two primes.
 ****************************************************************************/
ZZ findE(ZZ t)
{
   // e must be the lowest number > 1 that is relatively prime to t.
   ZZ e;

   // t will be even, so start at 3 and check increasing odd numbers
   // until you find a number e that is relatively prime to t.
   for (e = to_ZZ(3); GCD(t, e) != 1; e += 2)
   {
      // Empty. Just go until we find a relatively prime odd nubmer.
   }
   
   return e;
}

/*****************************************************************************
 * Find suitable primes p and q for encrypting a ZZ number that is the message.
 *****************************************************************************/
void findPandQ(ZZ m, ZZ& p, ZZ& q)
{
   // Start at sqrt(m) and find the next two primes.
   p = NextPrime(SqrRoot(m));
   q = NextPrime(p + 1);
}
