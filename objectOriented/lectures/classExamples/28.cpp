/***********************************************************************
 * This demo program is designed to:
 *      Square bracket operator
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Text
{
public:
   Text & operator += (const string & rhs)
   {
      data.push_back(rhs);
      return *this;
   }
   string operator [] (int index);
   int operator [] (const string & rhs)
   {
      for (int i = 0; i < data.size(); i++)
         if (rhs == data[i])
            return i;
      return -1;
   }
   
private:
   vector <string> data;
};

string Text :: operator [] (int index)
{
   if (index >= 0 && index < data.size())
      return data[index];
   else
      return string("");
}


/**********************************************************************
 * main()...
 ***********************************************************************/
int main()
{
   string s;
   Text text;
   
   for (int i = 0; i < 5; i++)
   {
      cout << "> ";
      cin  >> s;
      text += s;
   }

   int index;
   cout << "Give me an index: ";
   cin  >> index;
   cout << text[index];

   cout << "Give me a name: ";
   cin  >> s;
   cout << "it is in index "
        << text[s]
        << endl;
   
   return 0;
}
