#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n = 0;
	string istr[80];

	do
	{
		cin >> istr[n];
		n++;
	} while (cin.get() != '\n');
	
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
			cout << istr[n - i - 1];
		else
			cout << istr[n - i - 1] << " ";
	}
	cout << endl;

	return 0;
}