#include <iostream>
#include <string>
//#include <map>
#include <set>
using namespace std;

int main()
{
	string a, b;
	getline(cin, a); getline(cin, b);

	int Na = a.size(), Nb = b.size();
//	map<char, int> Alpha;
	set<char> Beta;
	for (int i = 0; i < Na; i++)
	{
		if (Beta.find(a[i]) == Beta.end())
		{
			Beta.insert(a[i]);
			printf("%c", a[i]);
		}
//		Alpha[a[i]]++;
//		if (Alpha[a[i]] == 1)
//			printf("%c", a[i]);
	}
	for (int i = 0; i < Nb; i++)
	{
		if (Beta.find(b[i]) == Beta.end())
		{
			Beta.insert(b[i]);
			printf("%c", b[i]);
		}
//		Alpha[b[i]]++;
//		if (Alpha[b[i]] == 1)
//			printf("%c", b[i]);
	}
	printf("\n");

	return 0;
}