#include <iostream>
using namespace std;

int main()
{
	int M, N, A, B, R;
	scanf("%d %d %d %d %d", &M, &N, &A, &B, &R);

	int **S = new int*[M];
	for (int i = 0; i < M; i++) S[i] = new int[N];

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &S[i][j]);
			if ((A <= S[i][j]) && (S[i][j] <= B))
				S[i][j] = R;
		}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j == 0) printf("%03d", S[i][j]);
			else printf(" %03d", S[i][j]);
		}
		printf("\n");
	}

	return 0;
}
