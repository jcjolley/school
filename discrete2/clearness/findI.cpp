#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  double high = 1;
  double low = 0;
  double mid = (high - low /  2); 
  double lastI;
  double mPrincipal = 300000;
  double mTermInMonths = 360;
  double mMonthlyPayment = 1656.61;
  double m = 1;
  while (true)
  {
    lastI = mid;
    mid = low + (high - low) / 2;
    if (abs(lastI - mid) < .0000001)
      break;
    m = mPrincipal * (mid / (1 - pow((1 + mid), -1 * mTermInMonths)));
    if (mMonthlyPayment - m > 0)
    {
      low = mid;
    }  
    else if ( mMonthlyPayment - m < 0)
    {
      high = mid;
    }
  }
  cout << "Mid: " << mid << " R: " << mid * 12 << endl;
}