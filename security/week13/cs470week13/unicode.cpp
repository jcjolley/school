/***********************************************************************
 * Component:
 *    UNICODE
 * Author:
 *    Br. Helfrich (add your name if you make any changes)
 * Summary:
 *    Everything necessary to work with unicode
 *    text. This includes a character data type,
 *    a string data type, and all the necessary
 *    methods.
 ************************************************************************/

#include <string>     // because we need to interface with strings occasionally
#include <sstream>    // to make building strings easier
#include <cassert>    // because I am paranoid
#include <stdlib.h>   // for rand()
#include "unicode.h"

using namespace std;


/******************************************************************
 * RANDOM
 * This function generates a random number.
 *    INPUT:   min, max : The number of values (min <= num <= max)
 *    OUTPUT   <return> : Return the integer
 ****************************************************************/
int random(int min, int max)
{
   assert(min <= max);
   int num = (rand() % (max - min)) + min;
   assert(min <= num && num <= max);

   return num;
}

/**********************************************
 * STRING FROM CHARACTER
 * For a given character (which may be unicode),
 * return a string with the proper HTML encoding.
 * If simple==false, randomly choose between
 * the following: simple, hex, decimal encoding
 **********************************************/
string stringFromCharacter(Character src, bool simple)
{
   //
   // trivial encoding
   //

   if (src == ' ' || src == '\t' || src == '\n' ||
       (src < 0x0080 && (simple == true || random(0, 3) == 0)))
   {
      string s;
      s += (char)src;
      return s;
   }

   //
   // hex encoding
   //

   stringstream sout;

   if (simple == true || random(0, 2) == 0)
   {
      sout.setf(ios::hex, ios::basefield);
      sout << hex << "&#x" << src << ";";
   }

   //
   // dec encoding
   //  
   else
   {
      sout.setf(ios::dec, ios::basefield);
      sout << dec << "&#" << src << ";";
   }

   // all done!
   return sout.str();   
}

/********************************************
 * IS HEX
 * Is a given letter part of the valid HEX range:
 *       0..9, a..f, A..F
 ********************************************/
inline bool ishex(char letter)
{
   return (
      isdigit(letter) ||
      (letter >= 'a' && letter <= 'f') ||
      (letter >= 'A' && letter <= 'F')
           );
}

#define isdec(letter) isdigit(letter)

/*******************************************
 * CHARACTER FROM STRING
 * Derrive the character from a string.  We will
 * advance the pointer by value
 *******************************************/
Character characterFromString(const string & src, int & i)
{
   // initially we consume nothing!
   assert(i >= 0);

   //
   // Check for hex encoding:
   //   &#x0; &#x00; &#x000; &#x0000; 
   //
   if (src[i + 0] == '&' &&
       src[i + 1] == '#' &&
       src[i + 2] == 'x' &&
       ishex(src[i + 3]) &&
       ((                                          src[i + 4] == ';') ||
        (ishex(src[i + 4]) &&                      src[i + 5] == ';') ||
        (ishex(src[i + 4]) && ishex(src[i + 5]) && src[i + 6] == ';') ||
        (ishex(src[i + 4]) && ishex(src[i + 5]) &&
                              ishex(src[i + 6]) && src[i + 7] == ';')))
   {
      // consume the "&#x"
      assert(src[i + 0] == '&' && src[i + 1] == '#' && src[i + 2] == 'x');
      int iInitial = i;
      i += 3;  // for {'&' '#' 'x'}
      Character character = 0;

      // loop through the hex digits and consume them
      for (const char * p = src.c_str() + i; *p != ';'; p++)
      {
         character *= 16;
         if (isdigit(*p))
            character += (*p - '0');
         else if (*p >= 'A' && *p <= 'F')
            character += (*p - 'A' + 10);
         else if (*p >= 'a' && *p <= 'f')
            character += (*p - 'a' + 10);
         else
            assert(false);
         i++;
      }
      assert((i - iInitial) >= 4 && (i - iInitial) <= 7);

      // consume the semicolon
      assert(src[i] == ';');
      i++;
      assert((i - iInitial) >= 5 && (i - iInitial) <= 8);

      // all done!
      return character;
   }

   //   
   // Check for dec encoding:
   //   &#0; &#00; &#000; &#0000; 
   //
   if (src[i + 0] == '&' &&
       src[i + 1] == '#' &&
       isdec(src[i + 2]) &&
       ((                                          src[i + 3] == ';') ||
        (isdec(src[i + 3]) &&                      src[i + 4] == ';') ||
        (isdec(src[i + 3]) && isdec(src[i + 4]) && src[i + 5] == ';') ||
        (isdec(src[i + 3]) && isdec(src[i + 4]) &&
                              isdec(src[i + 5]) && src[i + 6] == ';')))
   {
      // consume the "&#"
      assert(src[i + 0] == '&' && src[i + 1] == '#');
      int iInitial = i;
      i += 2;  // for {'&' '#'}
      Character character = 0;

      // loop through the hex digits and consume them
      for (const char * p = src.c_str() + i; *p != ';'; p++)
      {
         character *= 10;
         assert(isdec(*p));
         character += (*p - '0');
         i++;
      }
      assert((i - iInitial) >= 3 && (i - iInitial) <= 6);

      // consume the semicolon
      assert(src[i] == ';');
      i++;
      assert((i - iInitial) >= 4 && (i - iInitial) <= 7);

      // all done!
      return character;
   }

   // otherwise, we are in the trivial case
   return (Character)src[i++];
}

/*******************************************
 * CHARACTER FROM NUMBERS
 * Convert a c-str such as 0045 into a Character
 *******************************************/
Character characterFromNumbers(const char *src)
{
   string sHex("&#x0000;");

   sHex[3] = src[0];
   sHex[4] = (ishex(src[1]) ? src[1] : ';');
   sHex[5] = (ishex(src[2]) ? src[2] : ';');
   sHex[6] = (ishex(src[3]) ? src[3] : ';');

   int i = 0;
   return characterFromString(sHex, i);
}

/*****************************************************
 * getString
 * Return a string class (HTML encoded) from a String
 ****************************************************/
string String :: getString() const
{
   string s;

   // walk through the string one character at a time
   for (int i = 0; i < text.size(); i++)
      s += stringFromCharacter(text.at(i), simple);

   return s;
}


/*****************************************************
 * STRING <<
 *****************************************************/
ostream & operator << (ostream & out, const String & rhs)
{
   out << rhs.getString();
   return out;
}

/*****************************************************
 * STRING >>
 *****************************************************/
istream & operator >> (istream & in, String & rhs)
{
   // read the string in
   string s;
   in >> s;

   // all the work happens in the assignment operator
   rhs = s;

   return in;
}

/*****************************************************
 * STRING GETLINE
 *****************************************************/
istream & getline (istream & in, String & rhs)
{
   // read the string in
   string s;
   bool fReturn = getline(in, s);

   // all the work happens in the assignment operator
   if (fReturn)
      rhs = s;
   else
      rhs = string("");

   return in;
}

/**************************************************
 * STRING += STRING
 * Add a string onto the end of this string
 *************************************************/
String & String :: operator += (const String & s)
{
   for (int i = 0; i < s.size(); i++)
      *this += s(i);
   return *this;
}

/***********************************************
 * STRING == STRING
 **********************************************/
bool String :: operator == (const String & rhs) const
{
   // easy stuff first
   if (rhs.size() != text.size())
      return false;

   // loop through the String
   int i;
   for (i = 0; i < rhs.size() && rhs(i) == text.at(i); i++)
      ;

   return i == rhs.size();
}

/*****************************************
 * STRING (string)
 *****************************************/
String & String :: operator = (const string & s)
{
   int index = 0;
   text.clear();
   while (index < s.size())
   {
      int iOld = index;
      *this += characterFromString(s, index);
      assert(iOld < index);
   }

   return *this;
}
