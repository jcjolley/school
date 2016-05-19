
#include <iostream>
using namespace std;

class ComplexNumber
{
public:
   void set(float real, float imaginary);
   void display();
   private:
   float real;
   float imaginary;
};

void ComplexNumber::set(float real, float imaginary)
{
   cout << "Please input the real number of your complex number: " << endl;
   cin >> real;
   cout << "Please input the imaginary number of your complex number: " << endl;
   cin >> imaginary;
   this->real = real;
   this->imaginary = imaginary;
}

void ComplexNumber::display()
{
   cout << real << " + " << imaginary << "i\n";
}

int main()
{
   float real;
   float imaginary;
   ComplexNumber complex;
   complex.set(real, imaginary);
   complex.display();
}
