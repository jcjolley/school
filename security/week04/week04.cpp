/***********************************************************************
* Program:
*    Week 04 
*    Brother Wilson, CS 470
* Author:
*    Joshua Jolley
* Summary:
*    Implement a whitelist to sanitize HTML
***********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>

using namespace std;

/***********************************************************
 * FUNCTION: SanitizeTag
 * Replace the '<' and '>' at the given indexes
 * OUTPUT: The new index after compensating for the characters 
 *         we added to the string
 *********************************************************/
int sanitizeTag (string& str, int openingAngleBracket, int closingAngleBracket)
{
   const string LT = "&lt;";
   const string GT = "&gt;";
   str.replace(closingAngleBracket,1,GT);
   str.replace(openingAngleBracket,1,LT);
   return closingAngleBracket + 6;
}

/***********************************************
 * FUNCTION: Sanitize
 * Sanitize an html string in place using a provided whitelist
 **********************************************/
string sanitize(set<string> whitelist, string html)
{
   unsigned int openingAngleBracket = 0;
   char current;
   string tag = "";
   stack<string> tags;
   bool isTag = false;
   bool isClosingTag = false;

   //parse the html string, looking at each character once
   //and sanitizing as we go.
   for (unsigned int i = 0; i < html.length(); i++)
   {
      current = html[i];
      switch (current)
      {
         case '<':
            openingAngleBracket = i; 
            isTag = true;
            break;
         case '/':
            isClosingTag = true;
            break;
         case ' ':
            while (isTag && html[i + 1] != '>')
            {
               ++i; //we found an attribute, let's skip it
            }
            break;
         case '>':
            if (whitelist.find(tag) == whitelist.end())
            {
               i = sanitizeTag(html,openingAngleBracket,i); //not in whitelist.
            } 
            else
            {
               if (isClosingTag)
               {    
                  if (tags.top() != tag)
                  {
                     i = sanitizeTag(html,openingAngleBracket,i); //misplaced
                  }
                  else
                  {
                     tags.pop(); //it was a valid closing tag. 
                  }    
               }
               else
               {
                  tags.push(tag); // Valid opening tag, put it on the stack!
               }
            }

            isTag = false;
            isClosingTag = false;
            tag = "";
            break;
         default:
            if (isTag)
            {
               tag += current;
            }
      }
   }
   
   //add any unmatched tags in correct order
   while (tags.size() > 0)
   {
      html += "</" + tags.top() + ">";
      tags.pop();
   }

   return html;
}

/********************************************************************
 * MAIN: Our driver program
 ********************************************************************/
int main ()
{
   set<string> whitelistSet;
   string whitelist[13] = {"a", "abbr", "acronym", "b", "blockquote",
                           "cite", "code", "del", "em", "i", "q", 
                           "strike", "strong"};

   for (unsigned int i = 0; i < 13; ++i)
   {
      whitelistSet.insert(whitelist[i]);
   }

   string input;

   while (input != "quit")
   {
      cout << "> ";
      getline(cin, input);
      cout << "\t" << sanitize(whitelistSet, input) << endl;
   }

   return 0;
}
