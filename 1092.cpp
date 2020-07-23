#include <iostream>
#include <vector>
using namespace std;

#define GETMAX(a, b) ((a>b)?a:b)

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	long long* MoonSales = new long long[N];
	for (int i = 0; i < N; i++)
		MoonSales[i] = 0;

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			int a;
			scanf("%d", &a);
			MoonSales[j] += a;
		}

	long long max = -1;
	vector<int> A;
	for (int i = 0; i < N; i++)
		max = GETMAX(max, MoonSales[i]);

	for (int i = 0; i < N; i++)
	{
		if (MoonSales[i] == max)
			A.push_back(i);
	}

	printf("%lld\n", max);
	for (int i = 0; i < A.size(); i++)
	{
		if (i == 0) printf("%d", A[i] + 1);
		else printf(" %d", A[i] + 1);
	}
	printf("\n");

	return 0;
}
