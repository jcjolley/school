/***********************************************************************
 * This program is designed to demonstrate:
 *      Simple inheritance
 ************************************************************************/

#include <iostream>
using namespace std;

/*********************************
 * EXTENSION
 * A phone number extension
 ********************************/
class Extension
{
   public:
      Extension(int ext) : extension(ext) {                       }
      int getExtension()   const { return extension;              }
      void display()       const { cout << 'x' << getExtension(); }
   private:
      int extension;
};

/*******************************
 * PHONE NUMBER
 * A non-area-code phone number
 *******************************/
class PhoneNumber : public Extension
{
   public:
      PhoneNumber(int exchange, int ext) : Extension(ext),
                                           exchange(exchange) {            }
      int getNumber()   const { return exchange * 10000 + getExtension();  }
      int getExchange() const { return exchange;                           }
      void display()    const { cout << exchange << '-' << getExtension(); }
   private:
      int exchange;
};
   
/**********************************************************************
* This will be just a simple driver program 
***********************************************************************/
int main()
{
   //
   // test the extension
   //

   // prompt for input
   int input;
   cout << "What is your extension? ";
   cin  >> input;

   // create an extension object
   Extension extension(input);

   // test getExtension() and display()
   cout << "Extension: "
        << extension.getExtension()
        << endl;
   cout << "Display: "; 
   extension.display();
   cout << endl;

   //
   // test the phone number
   //

   // prompt for input
   cout << "What exchange are you on? ";
   cin  >> input;
   PhoneNumber phoneNum(input, extension.getExtension());

   // test the getters
   cout << "Extension: "
        << phoneNum.getExtension()            // inherited from Extension
        << endl;
   cout << "Exchange: "
        << phoneNum.getExchange()             // defined in PhoneNumber
        << endl;
   cout << "Number: "
        << phoneNum.getNumber()               // defined in Phone number
        << endl;

   // test display
   cout << "phoneNum.display(): ";
   phoneNum.display();                        // redefined from Extension
   cout << endl;
   cout << "phoneNum.Extension::display(): "; 
   phoneNum.Extension::display();             // call Extension's version
   cout << endl;
   
   
   
   return 0;
}
