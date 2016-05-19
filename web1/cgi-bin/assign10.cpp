/***********************************************************************
* Program:
*    Assignment 10, CGI Mortgage Calculator
*    Brother Ercanbrack, CS 213
* Author:
*    Joshua Jolley 
* Summary:
*    Demonstrates the use of a CGI to calculate a mortgage payment
************************************************************************/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

/************************************************************************
* FUNCTION: calculateMortgage
* returns the mortgage payment
*************************************************************************/
float calculateMortgage(float amount, float term, float apr)
{
   //calculate the number of payments 
   float numPayments = term * 12;

   //get the interest rate in the form of 0.05
   float interest = apr / 100.0;

   //figure out our compund interest
   float compInterest = pow(1 + interest, numPayments);

   //calculate and return the payment
   return (amount * (interest * compInterest) / (compInterest - 1));
}

/************************************************************************
* FUNCTION: parseQuery 
* parses the Query string and returns a map with the values
*************************************************************************/
void parseQuery(map<string, float> & qMap)
{
   //declare vars
   size_t found = 1;
   string key;
   string temp;
   float value;  
   string query = getenv("QUERY_STRING");

   //loop until we've parsed the whole query string
   while (found != string::npos)
   {
      //get the name of the key for our map
      found = query.find('=');
      key = query.substr(0,found);   
      query.erase(0,found + 1);
      
      //get the value of the above key for our map
      found = query.find('&');
      if (found != string::npos)
      {  
         value = atof(query.substr(0,query.length()).c_str());   
         query.erase(0,found + 1);
      }
      else //if there wasn't an & we're on the last value
      {
         value = atof(query.substr(0,query.length()).c_str());   
         query.erase(0,query.length());  
      }
      //add the key - value pair to the qMap
      qMap[key] = value;
   }
}

/************************************************************************
* Main
* our driver program
*************************************************************************/
int main()
{
   //declare vars 
   map<string,float> qMap;
   
   //fill our query map
   parseQuery(qMap);

   //calculate our payment 
   float payment = calculateMortgage(qMap["amount"], qMap["term"], qMap["apr"]);
   
   //return our payemnt
   cout << "Content-type: text/html\n\n";
   cout << "$" << fixed << setprecision(2) << payment << endl;
   return 0;
}
