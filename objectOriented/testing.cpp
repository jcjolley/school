#include <iostream>
using namespace std;

int main()
{
	for (int row = 7; row >= 0; row--)
		{
			cout << row << " ";
			for (int col = 0; col < 8; col++)
				cout << col;
			cout << endl;
		}
}