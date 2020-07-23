#include <iostream>
using namespace std;

void GameJudge(int n1, int b, int t, int n2, int x, bool& result)
{
	if (t <= x)
	{
		bool big;
		big = n1 < n2 ? true : false;
		if (bool(b) == big) result = true;
		else result = false;
	}
	else printf("Not enough tokens.  Total = %d.\n", x);
}

void PtCal(bool result, int t, int& x)
{
	if (t <= x)
	{
		if (result)
		{
			x += t;
			printf("Win %d!  Total = %d.\n", t, x);
		}
		else
		{
			x -= t;
			printf("Lose %d.  Total = %d.\n", t, x);
		}
	}
}

int main()
{
	int T, K;
	scanf("%d %d", &T, &K);

	int n1, n2, t, b, x;
	bool result;
	x = T;
	for (int i = 0; i < K; i++)
	{
		scanf("%d %d %d %d", &n1, &b, &t, &n2);
		GameJudge(n1, b, t, n2, x, result);
		PtCal(result, t, x);
		if (x == 0)
		{ printf("Game Over.\n"); break; }
	}

	return 0;
}