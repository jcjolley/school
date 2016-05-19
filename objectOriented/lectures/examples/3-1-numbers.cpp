/***********************************************************************
 * This demo program is designed to:
 *      Demonstrate home-grown polymorphism with function pointers
 ************************************************************************/

#include <iostream>
using namespace std;

// forward declaration so we can define both Nunber and VTableNumber
struct Number;

/**********************************
 * The three methods in our Number class
 *********************************/
struct VTableNumber
{
   void (*add)(           Number * pThis, const Number & rhs);
   void (*subtract)(      Number * pThis, const Number & rhs);
   void (*display)( const Number * pThis);
};

/**********************************
 * NUMBER
 * Our number class with a single value
 **********************************/
struct Number
{
   double value;
   const VTableNumber *__vtptr;
};

void numberAdd(                  Number * pThis, const Number & rhs);
void numberSubtract(             Number * pThis, const Number & rhs);
void numberDisplayDefault( const Number * pThis);
void numberDisplayCurrency(const Number * pThis);

// First VTable. This one for normal numbers containing numberDisplayDefault()
const VTableNumber V_TABLE_NUMBER =
{
   &numberAdd,
   &numberSubtract,
   &numberDisplayDefault
};

// Second VTable for currency.  Note numberDisplayCurrency()
const VTableNumber V_TABLE_NUMBER_CURRENCY =
{
   &numberAdd,
   &numberSubtract,
   &numberDisplayCurrency
};


/**********************************************************************
 * Driver program
 ***********************************************************************/
int main()
{
   // Observe how both are the same data type: Number
   Number num1;
   Number num2;

   // We need to attach or bind the VTables.  This is done for us by
   // the compiler when we use classes
   num1.__vtptr = &V_TABLE_NUMBER;               // default member functions
   num2.__vtptr = &V_TABLE_NUMBER_CURRENCY;      // currency member functions

   // initialize them with some values.
   cout << "What is the value? ";
   double value;
   cin  >> value;
   num1.value = num2.value = value;

   // display them.  Note how the display code is identical:
   cout << "Number 1: ";
   num1.__vtptr->display(&num1);
   cout << endl;
   
   cout << "Number 2: ";
   num2.__vtptr->display(&num2);
   cout << endl;

   return 0;
}


/****************************************
 * DISPLAY DEFAULT
 * Default display to 1 decimal of accuracy
 ***************************************/
void numberDisplayDefault( const Number * pThis)
{
   _Ios_Fmtflags saveF = cout.setf(ios::fixed);
   int saveP = cout.precision(0);

   cout << pThis->value;

   cout.setf(saveF);
   cout.precision(saveP);
}

/****************************************
 * DISPLAY CURRENCY
 * Default display to 2 decimals of accuracy with $
 ***************************************/
void numberDisplayCurrency( const Number * pThis)
{
   _Ios_Fmtflags saveF = cout.setf(ios::fixed | ios::showpoint);
   int saveP = cout.precision(2);

   cout << "$" << pThis->value;

   cout.setf(saveF);
   cout.precision(saveP);
}


/**************************************
 * ADD
 * Add two numbers
 **************************************/
void numberAdd(Number * pThis, const Number & rhs)
{
   pThis->value += rhs.value;
}

/**************************************
 * SUBTRACT
 *************************************/
void numberSubtract(Number * pThis, const Number & rhs)
{
   pThis->value -= rhs.value;
}


