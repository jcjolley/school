/***********************************************************************
* Program:
*    Assignment 35, Pure Virtual Functions
*    Brother Helfrich, CS165
* Author:
*    your name
* Summary: 
*    This program will demonstrate abstract classes and pure virtual functions.
*    An abstract class (ValidNumber) will have two children: GPA and
*    Price.  Each will have unique display and validate functions.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>
using namespace std;


/***************************************
 * TEST. Test the abstract base class
 *    INPUT:  num:       A valid number to be tested
 *            sMessage:  The prompt message 
 ***************************************/
void test(ValidNumber & num, const char * sMessage)
{
   num.prompt(sMessage);
   num.display();
}
   
/**********************************************************************
 * MAIN.  This function, coupled with TEST, will constitute the driver
 *        program for our ValidNumber family of classes.  
 ***********************************************************************/
int main()
{
   GPA   gpa;
   Price price;

   test(gpa,   "Enter a GPA where 0.0 <= gpa <= 4.0");
   test(price, "Enter a non-negative price");
   
   return 0;
}

