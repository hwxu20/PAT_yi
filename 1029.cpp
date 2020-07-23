#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;

//	transform(a.begin(), a.end(), a.begin(), toupper);
//	transform(b.begin(), b.end(), b.begin(), toupper);

	set<char> keyset, brkeyset;
	int N1 = a.size(), N2 = b.size();

	for (int i = 0; i < N1; i++)
	{
		if ((a[i] >= 'a') && (a[i] <= 'z'))
			a[i] += 'A' -'a';
	}
	for (int i = 0; i < N2; i++)
	{
		if ((b[i] >= 'a') && (b[i] <= 'z'))
			b[i] += 'A' - 'a';
	}


	for (int i = 0; i < N2; i++)
			keyset.insert(b[i]);

	set<char>::iterator iter1, iter2;
	for (int i = 0; i < N1; i++)
	{
		iter1 = keyset.find(a[i]);
		iter2 = brkeyset.find(a[i]);

		if ((iter1 == keyset.end()) && (iter2 == brkeyset.end()))
		{
			cout << a[i];
			brkeyset.insert(a[i]);
		}
	}
	cout << endl;

	return 0;
}