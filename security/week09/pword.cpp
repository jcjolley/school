/***********************************************************************
* Program:
*    Week 09, Password Strength
*    Brother Wilson, CS470
* Author:
*    Joshua Jolley
* Summary: 
*    Displays the number of possible password combinations 
*    and the equivalent bit strength of the provided password.
************************************************************************/

#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>

#define SIZE 1024

using namespace std;

/***************************************************************************
 * GetPassword
 * Get's the password from the user.
 **************************************************************************/
void getPassword(int argc, char* argv[], char password[])
{
   if (argc < 2)
   {
      cout << "Please enter the password: ";
      cin.getline(password, SIZE); //getline avoids buffer overflows
   }
   else
   {
      strncpy(password, argv[1], SIZE); //strncpy avoids buffer overflows
   }
   return;
}
  
/***************************************************************************
 * GetPasswordSpace
 * Determines the number of possible password combinations from a given pword 
 **************************************************************************/
long long int getPasswordSpace(char* password)
{
   bool hasNumerals = false;
   bool hasLowercase = false;
   bool hasUppercase = false;
   bool hasSymbols = false;
   int characterSet = 0;
   int passwordLength = strlen(password);

   //check each character of the string to determine what classes of
   //characters we have
   for (char * p = password; *p; p++)
   {
      if (!hasUppercase && isupper(*p))
      {
         hasUppercase = true;
         continue; //each case is exclusive, no sense checking the others.
      }
      if (!hasLowercase && islower(*p))
      {
         hasLowercase = true;
         continue;
      }
      if (!hasNumerals && isdigit(*p))
      {
         hasNumerals = true;
         continue;
      }
      if (!hasSymbols && ispunct(*p))
      {
         hasSymbols = true;
         continue;
      }
   }
   
   if (hasNumerals)
   {
      characterSet += 10; //only 10 numbers  
   }

   if (hasLowercase)
   {
      characterSet += 26; //26 lowercase letters
   }

   if (hasUppercase)
   {
      characterSet += 26; //26 uppercase letters
   }

   if (hasSymbols)
   {
      characterSet += 32; //and 32 symbols
   }

   return pow(characterSet, passwordLength);
   
}

/***************************************************************************
 * Main
 * Runs the whole show.
 **************************************************************************/
int main(int argc, char* argv[])
{
   char password[SIZE];
   getPassword(argc, argv, password);
   
   long long int combinations = getPasswordSpace(password);
   
   int bitStrength = log2(combinations);
   
   cout << "There are " << combinations << " combinations" << endl;
   cout << "That is equivalent to a key of " << bitStrength << " bits" << endl;

   return 0;
}
