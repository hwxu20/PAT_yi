#include <iostream>
using namespace std;

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	int* Q_Pts = new int[M];
	int* Q_Ans = new int[M];
	int* S_Pts = new int[N];
	for (int i = 0; i < N; i++)
		S_Pts[i] = 0;

	for (int i = 0; i < M; i++)
		scanf("%d", &Q_Pts[i]);
	for (int i = 0; i < M; i++)
		scanf("%d", &Q_Ans[i]);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int Result = 0;
			scanf("%d", &Result);
			if (Result == Q_Ans[j])
				S_Pts[i] += Q_Pts[j];
		}
	}

	for (int i = 0; i < N; i++)
		printf("%d\n", S_Pts[i]);

	return 0;
}