#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main()
{
	string a;
	string num1_9 = "123456789";

	for (int i = 0; i < 10; i++)
	{
		int j;
		cin >> j;
		while (j > 0)
		{
			a.push_back(i + '0');
			j--;
		}
	}

	sort(a.begin(), a.end());
	if (a[0] == '0')
	{
		string::size_type pos = a.find_first_of(num1_9);
		char temp;
		temp = a[0];
		a[0] = a[pos];
		a[pos] = temp;
	}
	cout << a << endl;

	return 0;
}