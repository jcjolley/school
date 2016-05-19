/***********************************************************************
 * Program:
 *    Unit 2, Safe String
 *    Brother Helfrich, CS 470
 * Author:
 *    Joshua Jolley
 * Summary: 
 *    Secure string class.
 ************************************************************************/

#include "myUtils.h"
#include "String.h"
#include <iostream>

#ifdef DEBUG
#define debug(x) std::cerr << #x << ": " << x << std::endl 
#define D(x) x
#else
#define debux(x)
#define D(x)
#endif

using namespace std;

int main(int argc, char* argv[])
{
   char hello[] = "hello";
   String str = String(hello);
   str = str.Strcat(hello);
   str.display();
   return 0;
}
