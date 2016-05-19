/***********************************************************************
 * Program:
 *    Exploration 2, Freshness
 *    Brother Neff, CS 238
 * Author:
 *    You
 * Summary:
 *    Amortization Calculating Program
 *    Exploring a practical recurrence relation.
 ***********************************************************************/
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <streambuf>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

/***********************************************************************
 * A java-like System.getProperty() utility.
 *
 * Deliberately uncommented.
 ***********************************************************************/
class System
{
private:
   map<string, string> mProperties;

public:

   string getProperty(string pKey, string pDefault)
   {
      if (mProperties.find(pKey) == mProperties.end())
      {
         return pDefault;
      }
      else
      {
         return mProperties[pKey];
      }
   }

   bool getIntegerProperty(string pKey, int& pResult)
   {
      string prop = getProperty(pKey, "");
      if (prop == "")
      {
         pResult = 0;
         return false;
      }
      else
      {
         pResult = atoi(prop.c_str());
         return true;
      }
   }

   bool getDoubleProperty(string pKey, double& pResult)
   {
      string prop = getProperty(pKey, "");
      if (prop == "")
      {
         pResult = 0.0;
         return false;
      }
      else
      {
         pResult = atof(prop.c_str());
         return true;
      }
   }

   void setProperty(string pKeyValue)
   {
      size_t i = pKeyValue.find_first_of('=');
      if (i != string::npos)
      {
         string key = pKeyValue.substr(0, i);
         string value = pKeyValue.substr(i + 1);
         setProperty(key, value);
      }
   }

   void setProperty(string pKey, string pValue)
   {
      mProperties.insert(pair<string, string>(pKey, pValue));
   }
} System;

class Boolean
{
public:
   bool getBoolean(string pKey)
   {
      bool result = false;
      result = toBoolean(System.getProperty(pKey, "0"));
      return result;
   }
private:
   bool toBoolean(string name)
   { 
      return (name != "0");
   }
} Boolean;

/*******************************************************************
 * runWithData is a global function declared here
 * and implemented in the clearness.cpp file.
 *
 * It serves as the interface between the CLI and the Amortize class.
 *** ****************************************************************/
void runWithData(int termInMonths, double rate, double principal,
                 double monthlyPayment, double extraMonthlyPayment,
                 bool showAmortizationSchedule, int start, int end,
                 bool havePrincipal, bool haveRate,
                 bool haveTermInMonths, bool haveMonthlyPayment);

/*******************************************************************
 * getDataAndRunWithIt is a global function that is called by main
 * and then calls runWithData with the data it gets from the System
 * properties (set by main).
 *******************************************************************/
void getDataAndRunWithIt()
{
   int termInMonths;
   double rate;
   double principal;
   double monthlyPayment;
   double extraMonthlyPayment;
   bool showAmortizationSchedule;
   int start;
   int end;
   bool haveTermInMonths = System.getIntegerProperty("n", termInMonths);
   bool havePrincipal = System.getDoubleProperty("p", principal);
   bool haveRate = System.getDoubleProperty("r", rate);
   bool haveMonthlyPayment = System.getDoubleProperty("m", monthlyPayment);
   System.getDoubleProperty("x", extraMonthlyPayment);
   System.getIntegerProperty("s", start);
   System.getIntegerProperty("e", end);
   showAmortizationSchedule = Boolean.getBoolean("v");

   runWithData(termInMonths, rate, principal,
               monthlyPayment, extraMonthlyPayment,
               showAmortizationSchedule, start, end,
               havePrincipal, haveRate,
               haveTermInMonths, haveMonthlyPayment);
}

/*************************************************************************
 * Prototypes for functions called by main.
 * TODO: implement these in clearness.cpp
 *************************************************************************/
void learned();
void usage(char * programName);

/****************************************************************
 * Main reads command-line argument(s) as follows:
 *
 *  Name of a file containing parameter settings, or
 *  (3 of the following 4 parameters are required)
 *
 *      p= principal (amount loaned)
 *      n= term in months (number of payments)
 *      r= annual interest rate (in percent, e.g. 3.75)
 *      m= monthly payment amount
 *
 *      v= (optional) 1 = view amortization schedule
 *      x= (optional) extra monthly payment
 *      s= (optional) month extra payment starts
 *      e= (optional) month extra payment ends (default = n)
 ****************************************************************/
int main(int argc, char* argv[])
{
   if (argc <= 1)
   {
      learned();
      usage(argv[0]);
      return 0;
   }
   else if (argc == 2)
   {
      const char* filename = argv[1];
      string data;
      ifstream ifs(filename, ios_base::in);

      if (ifs)
      {
         while (true)
         {
            ifs >> data;

            if (ifs.eof() || ifs.fail())
            {
               break;
            }
            System.setProperty(data);
         }
         ifs.close();
      }
   }
   else
   {
      for (int i = 1; i < argc; i++)
      {
         string data = argv[i];
         System.setProperty(data);
      }
   }

   getDataAndRunWithIt();
   return 0;
}
