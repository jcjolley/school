#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
  ifstream fin;
  fin.open(argv[1]);
  ofstream fout;
  string newFile = "reversed";
  newFile.append(argv[1]);
  fout.open(newFile);

  string line;
  while (getline(fin, line))
  {
    reverse(line.begin(), line.end());
    line.erase(line.begin());
    line.append("\n");
    fout << line;
  }
  return 0;
}