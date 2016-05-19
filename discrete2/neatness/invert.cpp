#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
  ifstream fin;
  fin.open(argv[1]);
  ofstream fout;
  string newFile = "inverted";
  newFile.append(argv[1]);
  fout.open(newFile);

  char a;
  while (fin >> noskipws >> a)
  {
    cout << a;
    switch (a)
    {
      case '*':
        fout << ' ';
        break;
      case ' ':
        fout << '*';
        break;
      case '\n':
        fout << '\n';
        break;
    }
  }
  return 0;
}