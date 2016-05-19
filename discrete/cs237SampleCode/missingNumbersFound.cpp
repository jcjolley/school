/******************************************************************************
 * In Discrete Mathematics, it is often the case that we must find patterns
 * in order to solve a problem. The following problem is one such example:
 *
 *       6 _ _
 *     x _ _ _
 *     =======
 *       _ _ _
 *   _ _ _ _
 * _ 5 _ 5
 * ===========
 * _ _ 5 _ 4 _
 *
 * The problem asks that the suppressed digits be restored by using logical
 * reasoning. We can deduce that the rightmost (ones) digit of the second
 * number must be a 1, since the first partial product only has 3 digits.
 * Likewise, because the third partial product ends with a 5 we know that
 * either the ones digit of the first number or the hundreds digit of the
 * second number is a 5. Etc.
 *
 * This program takes the set of all possible inputs, and using the known
 * variables, filters the set of all outputs, solving the equation.
 *
 *****************************************************************************/
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

int main()
{
   int result;
   int temp;
   int tempResult;
   stringstream ss1;
   stringstream ss2;
   // used to compare specific numbers in the result  
   string tempResultString; 
   string resultString;

   // first number starts with 6 and cannot exceed 699
   for (int first = 600; first < 700; first++)
   {                        
      // second number cannot exceed 991, and must always end with 1
      for (int second = 101; second < 992; second += 10)
      {
         result = first * second;
         ss1 << result;
         resultString = ss1.str(); ss1.str("");

         temp = second / 100;         // 100's place value
         tempResult = temp * first;   // the 100's place value * first number
         ss2 << tempResult;
         tempResultString = ss2.str(); ss2.str("");

         // if the product has six digits, a 5 in the 1000's place,
         // a 4 in the 10's place, and the 3rd partial product
         // has a 5 in the 100's place and
         // a 5 in the 1's place, it is a valid answer
         if (result > 100000 && resultString[4] == '4' &&
             resultString[2] == '5' && 
             tempResultString[1] == '5' &&
             tempResultString[3] == '5')
         {
            // display the answer
            cout << setw(7) << first << endl;
            cout << setw(2) << "*" << setw(5) << second << endl;
            cout << setw(7) << "------" << endl;
            cout << setw(7) << ((second % 10) * first) << endl;
            cout << setw(6) << (((second % 100) / 10) * first) << endl;
            cout << setw(5) << ((second / 100) * first) << endl;
            cout << setw(7) << "------" << endl;
            cout << setw(7) << result << endl;
         }
      }
   }
   return 0;
}
