#include <iostream>
#include <cmath>
using namespace std;

bool closeAndFar(int a, int b, int c)
{
  int distanceAB = abs(a - b);
  int distanceAC = abs(a - c);
  int distanceBC = abs(b - c);
  if (distanceAB <= 1)
    if (distanceAC >=2 && distanceBC >= 2)
      return true;
  if (distanceAC <= 1)
    if (distanceAB >= 2 && distanceBC >= 2)
      return true;
  return false;
} 


int main()
{
  cout << closeAndFar(1,2,5) << endl;
  cout << closeAndFar(2,7,3) << endl;
  cout << closeAndFar(1,2,3) << endl;
}