#include <iostream>
#include <string>
#include <map>
using namespace std;


int main()
{
	string a, b, temp;
	cin >> a >> b;

	map<int, int> Tanzhu, Xiaohong;

	for (int i = 0; i < a.size(); i++)
		Tanzhu[a[i]]++;
//	for (int i = 0; i < b.size(); i++)
//		Xiaohong[b[i]]++;

	for (int i = 0; i < b.size(); i++)
		Tanzhu[b[i]]--;

	int lack = 0, left = 0;
	bool lack_flag = 0;
	map<int, int>::iterator iter;
	iter = Tanzhu.begin();
	while (iter != Tanzhu.end())
	{
		if (iter->second < 0)
		{
			lack_flag = 1;
			lack -= iter->second;
		}

		left += iter->second;
		iter++;
	}

	if (lack_flag) printf("No %d", lack);
	else printf("Yes %d", left);

	return 0;
}