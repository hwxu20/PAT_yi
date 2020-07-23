#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	string b;
	getline(cin, a);
	getline(cin, b);
	int Na = a.size(), Nb = b.size();

	for (int i = 0; i < Na; i++)
	{
		if (('A' <= a[i]) && (a[i] <= 'Z'))
			a.insert(a.end(), a[i] + 'a' - 'A');
	}

	
	for (int i = 0; i < Nb; i++)
	{
		int brk_flag = 0;
		if (a.find(b[i]) != a.npos)
			brk_flag = 1;
		else if ((a.find('+') != a.npos) && ('A' <= b[i] && b[i] <= 'Z'))
			brk_flag = 1;
		
		if (brk_flag == 0)
			cout << b[i];
	}

	cout << endl;

	return 0;
}