#include <iostream>
#include <cmath>
using namespace std;

float calculateMortgage(float amount, int term, float apr)
{
   int numPayments = term * 12;
   float interest = apr / 100.0;
   float compInterest = pow(1 + interest, numPayments);

   return amount * (interest * compInterest) / (compInterest - 1)
}

int main()
{

   cout << "Content-type: text/html\n\n";
   cout << "<html><head><title>Ruby Test</title></head><body>\n";
   cout << " Hello world!\n";
   cout << "</body></html>\n";
   
   return 0;
}

//GET -- for reference.
// parseQueryString(string queryString, string key[], string value[], int &noPairs)
// {
//    int pos = 0;
//    int loc = 0;
//    noPairs = 0;

//    while(loc != string::npos)
//    {
//       loc = queryString.find('=',pos);
//       key[noPairs] = queryString.substr(pos,loc - pos);
//       pos = ++loc;
//       loc = queryString.find('&',pos);
//       value[noPairs] = 
//    }
// }

//POST
//char* queryStringLen = getenv("CONTENT_LENGTH");
//int length = atoi(queryStringLen);
//char * queryString = new char[length];
//cin.get(queryString, length + 1);