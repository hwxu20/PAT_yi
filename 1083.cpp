#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define AbsSub(a, b) a > b ? (a - b) : (b - a)

struct CmpCard
{
	bool operator()(const int& a, const int& b) const { return a > b; }
};

int main()
{
	int N;
	scanf("%d", &N);

	map<int, int, CmpCard> Card;
	for (int i = 1; i < N + 1; i++)
	{
		int tmp, sub;
		scanf("%d", &tmp);
		sub = AbsSub(i, tmp);
		Card[sub]++;
	}

	map<int, int>::iterator iter;
	for (iter = Card.begin(); iter != Card.end(); iter++)
	{
		if (iter->second > 1)
			printf("%d %d\n", iter->first, iter->second);
	}
	return 0;
}