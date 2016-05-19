/***********************************************************************
* Program:
*    Week 05, Memory Injection
*    Brother Wilson, CS470
* Author:
*    Joshua Jolley
* Summary: 
*    This program is designed to illustrate weaknesses in the stack.
*
************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;


void partOne();    // Find the qaddress of the stack, heap, and code segments
void partTwo();    // Manipulate the stack to find a weakness
void partThree();  // Demonstrate a variety of vulnerabilities
void stackExploit();
void heapExploit();
void arrayExploit();
void arcExploit();
/******************************************************
 * MAIN
 * This function will only take you to one of the three parts
 * of Assignment 10
 *****************************************************/
int main()
{
   // prompt
   cout << "Please select an option:\n";
   cout << "  1.  Find the address\n";
   cout << "  2.  Manipulate the stack\n";
   cout << "  3.  Demonstrate vulnerabilities\n";
   cout << "> ";
   int selection;
   cin >> selection;

   // highly complex menu system
   switch (selection)
   {
      case 1:
         partOne();
         break;
      case 2:
         partTwo();
         break;
      case 3:
         partThree();
         break;
      default:
         cout << "Unknown option\n";
         return 1;
   }

   return 0;
}

/**************************************************************
 **************************************************************
 **************************** PART 1 **************************
 **************************************************************
 **************************************************************/

/**********************************************
 * Part 1
 *
 * Find the address of the stack, heap, and code.
 * Note that it will be in a different location with
 * every execution
 **********************************************/
void partOne()
{
   cout << "Code pointer: " << (void *)(&partOne) << endl;
   char * h = new char('a');
   cout << "Heap pointer: " << (void *)(h) << endl;
   char x = 'a';
   cout << "Stack pointer: "<< (void *)(&x + 1) << endl;
   return;
}


/**************************************************************
 **************************************************************
 **************************** PART 2 **************************
 **************************************************************
 **************************************************************/

void fail(char grade);
void pass(char grade);


/**********************************************************************
 * All your code needs to exist in this function below the comment
 *********************************************************************/
void readStack()
{
   int   number;
   char  text[16];
   
   ////////////////////////////////////////////////
   // put your magic code between here...
   // 80 bytes through the stack are the values we want.
   //
   for(number = 0; number < 16; number++)
   {
      text[number] = text[number + 80];
   }

   number = *(&number + 20); // an int is 4 bytes, 4 * 20 = 80 
   char letterGrade;
   void (*pointerFunction)(char);

   *(&letterGrade + 80) = 'A';
   *(&pointerFunction + 10) = pass;
   // ... and here
   ////////////////////////////////////////////////

   // output the goods
   cout << "\tnumber: "
        << number
        << endl;
   cout << "\ttext:   "
        << text
        << endl;

   return;
}

/*******************************************************************
 * Part 2
 *
 * This function contains the data that you are trying to manipulate.
 * Please don't modify partTwo() in any way
 ********************************************************************/
void partTwo()
{
   int   number;   // first local variable that you need to read
   char  text[16]; // second

   char  letterGrade;
   void (*pointerFunction)(char);

   // compilers are annoying.
   // If we don't get the address of these two variables, our
   // compiler will optimize them away and they will not appear
   // on the stack.  To get around this, I use the address-of
   // operator which forces the compiler to put them in the stack.
   &letterGrade;
   &pointerFunction;
   // get the values
   cout << "number: ";
   cin  >> number;
   cout << "text:   ";
   cin  >> text;


   // Call the function and display the results.
   pointerFunction = fail;
   letterGrade = 'B';
   readStack();            // vulnerability is here 
   (*pointerFunction)(letterGrade);

   return;
}


/**********************************************************************
 * The failure case. Don't touch this function
 *********************************************************************/
void fail(char grade)
{
   cout << "\tI am sorry, but you got a 'C'\n";
}

/**********************************************************************
 * I think you would really rather call this function.  This
 * is read-only also
 *********************************************************************/
void pass(char grade)
{
   cout << "\tGood job, you got a(n) '" << grade << "'\n";
}


/**************************************************************
 **************************************************************
 **************************** PART 3 **************************
 **************************************************************
 **************************************************************/


/*************************************
 * Part 3
 *
 * partThree() will call four functions to
 * demonstrate Stack, Heap, ArrayIndex, and Arc
 * vulnerabilities.  You should
 *   * Write the functions with code defects
 *     that represent the various vulnerabilities
 *   * Create input that will cause the vulnerabilities
 *     to be exploited
 *   * Create a simple menu system similar to main()
 *     so the user can witness the vulnerability
 *     of his choice
 *************************************/
void partThree()
{ 
   cout << "  1. Stack smashing\n"
        << "  2. Heap spraying\n"
        << "  3. Array index\n"
        << "  4. Arc vulnerability\n"
        << "> ";

   int select;
   cin >> select;

   switch (select)
   {
      case 1:
         stackExploit();
         break;
      case 2:
         heapExploit();
         break;
      case 3:
         stackExploit(); //array index vulnerability is used in all functions
         break;
      case 4:
         arcExploit();
         break;
      default:
         cout << "Unknown option " << select << endl;
   }
   return;
}

/***************************************************************************
 * stackVulnerability
 * 1. There must be a buffer on the stack.
 * 2. The first buffer must be reachable through external input
 * 3. The buffer size must not be checked.   
 * ************************************************************************/
void stackVulnerability(char input[])
{
   char text[5];
   strcpy(text, input); 
   return;
}

/***************************************************************************
 * stackExploit
 *
 * stackExploit demonstrates stack smashing.
 **************************************************************************/
void stackExploit()
{
   char input[80] = "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii";
   stackVulnerability(input);
   cout << "This code isn't safe.  We won't get here" << endl;
   return;
}

/***************************************************************************
 * heapVulnerability
 * 1. Two adjacent buffers
 * 2. First buffer reachable via external input
 * 3. No bounds checking
 * 4. Second buffer deleted first 
 **************************************************************************/
void heapVulnerability(char input[]){
   char * one = new char[5];
   char * two = new char[5];
   strcpy(one, input);
   cout << "This code is " << two << endl;
   delete [] two;
   delete [] one;
   return;
}


/***************************************************************************
 * heapExploit
 *
 * heapExploit demonstrates heap spraying.
 **************************************************************************/
void heapExploit()
{
   char text[45] = "Terribly, terribly unsafe.      Unsafe!!"; 
   heapVulnerability(text);
}


/******************************************************
 * arcVulnerability
 * 1.There must be a function pointer used in the code.
 * 2.Through some vulnerability, there must be a way for user 
 *    input to overwrite the function pointer. 
 * 3. After the memory is overwritten, the pointer must be dereferenced.
 *************************************************************************/
void arcVulnerability(char input[])
{
   char text[2];
   void (*function)(char);
   function = fail;
   strcpy(text, input);
   (*function)('F');
}

/***************************************************************************
 * arcExploit
 *
 * This function demonstrates an arcExploit
 **************************************************************************/
void arcExploit()
{
   char text[80] = "This is so unsafe it's not even funny.  We're in real trouble!";
   arcVulnerability(text);
}
