#include <iostream>
#include <cmath>
#include <map>
#include <set>
using namespace std;

int main()
{
	//map<int, int> d;
	set<int> d;
	int N;
	scanf("%d", &N);

	for (int i = 1; i < N + 1; i++)
	{
		//int tmp = floor(i / 2.0) + floor(i / 3.0) + floor(i / 5.0);
		//d[tmp]++;
		int tmp = i / 2 + i / 3 + i / 5;
		d.insert(tmp);
	}

	printf("%d\n", d.size());

	return 0;
}