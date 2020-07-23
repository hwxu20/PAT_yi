#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string a;
	getline(cin, a);
	int eng_chac[26];

	for (int i = 0; i < 26; i++)
		eng_chac[i] = 0;

	for (int i = 0; i < a.size(); i++)
	{
		if (('a' <= a[i]) && (a[i]) <= 'z')
			eng_chac[a[i] - 'a']++;
		else if (('A' <= a[i]) && (a[i]) <= 'Z')
			eng_chac[a[i] - 'A']++;
	}

	char max_chac = 'a';
	int max_num = eng_chac[0];
	for (int i = 1; i < 26; i++)
	{
		if (eng_chac[i] > max_num)
		{
			max_chac = i + 'a';
			max_num = eng_chac[i];
		}
	}
	
	printf("%c %d", max_chac, max_num);

	return 0;
}