/*************************************************************************
 * Stubby CLI
 *************************************************************************/
#include <cstdlib>
#include <string>
using namespace std;

/*************************************************************************
 * Function prototypes
 *************************************************************************/
void learned();
void usage(const char *);
void runOne(string);

/**************************************************************
 * main looks at its command-line parameters.
 * If none, it calls two functions in order, namely
 *   learned
 *   usage
 * Otherwise it calls runOne with each command-line parameter,
 * each naming a file to test.
 ***************************************************************/
int main(int argc, const char* argv[])
{
   if (argc == 1)
   {
      learned();
      usage(argv[0]);
   }
   else
   {
      for (int i = 1; i < argc; i++)
      {
         runOne(string(argv[i]));
      }
   }
   return 0;
}   
