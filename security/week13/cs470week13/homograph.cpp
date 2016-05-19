#include <stdlib.h>   
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
vector<string>& tokenize(vector<string>& tokens, string str)
{
   stringstream ss(str);
   string token;
   while (std::getline(ss, token, '/')) {
      tokens.push_back(token);
   }
   return tokens;
}

string parseHomeBase(vector<string> tokens)
{
   cout << getenv("HOME") << endl;
   return string("homeStub");
}

string parseRootBased(vector<string> tokens)
{
   return string("rootStub");
}

string parseWorkingDirectoryBased(vector<string> tokens)
{
   cout << getenv("PWD") << endl;
   return string("WDstub");
}

string canonicalize(string str)
{
   vector<string> tokens;
   tokens = tokenize(tokens, str);
   string canon;
   switch(tokens[0][0])
   {
      case '/':
         canon = parseRootBased(tokens);
         break;
      case '~':
         canon = parseHomeBase(tokens);
         break;
      default:
         canon = parseWorkingDirectoryBased(tokens);
   }

   return canon;
}

void isHomograph(string a, string b)
{
   if (a == b)
      cout << "The files are homographs" << endl;
   else
      cout << "The files are NOT homographs" << endl;
}

int main()
{
   string filea = "";
   string fileb = "";
   cout << "Specify the first filename: ";
   getline(cin,filea);
   cout << "Specify the second filename: ";
   getline(cin,fileb);
   isHomograph(filea, fileb);
   return 0;
}
