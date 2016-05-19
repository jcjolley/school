/***********************************************************************
 * Program:
 *    Unit 2, Safe String
 *    Brother Helfrich, CS 470
 * Author:
 *    Joshua Jolley
 * Summary: 
 *    Secure string class.
 ************************************************************************/
#ifndef ___STRINGH___
#define ___STRINGH___

#include <iostream>

class String
{
public:
  String(){size = 32; str = new char[size]; length = 0;}
  String(const char* a);
  String(String &a);
  ~String(){if (str != NULL) delete [] str;}
  String Strcat(const char * left);
  void display(){std::cout << str << std::endl;}

private:
  char * str; 
  int length;
  int size;
};

#endif