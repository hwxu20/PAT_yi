#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int print_PAT(map<char,int> &a, char c)
{
	int num = a[c];
	if (num)
	{
		printf("%c", c);
		a[c]--;
		return 1;
	}
	else return 0;
}

int main()
{
	string a;
	cin >> a;
	map<char, int> Engchar;

	for (int i = 0; i < a.size(); i++)
		Engchar[a[i]]++;

	string out = "PATest";
	int over = 1;
	while (over > 0)
	{
		over = 0;
		for (int i = 0; i < out.size(); i++)
			over += print_PAT(Engchar, out[i]);
	}

	return 0;
}