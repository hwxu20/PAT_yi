#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main()
{
	int k = 0;
	string a;
	map<char, int> digits;
	cin >> a;

	k = a.size();

	for (int i = 0; i < k; i++)
	{
		digits[a[i]]++;
	}

	for (int i = 0; i < 10; i++)
	{
		if (digits.count(i+'0'))
			cout << i << ":" << digits[i + '0'] << endl;
	}

	return 0;
}