#include <iostream>
#include <vector>
using namespace std;

vector<int>* Forbid[100000];

bool Check(int a, int b)
{
	if (Forbid[a] == NULL) return false;
	int n = Forbid[a]->size();
	for (int i = 0; i < n; i++)
	{
		if ((*Forbid[a])[i] == b)
			return true;
	}
	return false;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (Forbid[a] == NULL) Forbid[a] = new vector<int>;
		if (Forbid[b] == NULL) Forbid[b] = new vector<int>;
		Forbid[a]->push_back(b);
		Forbid[b]->push_back(a);
	}

	int A[1000];
	for (int i = 0; i < M; i++)
	{
		int K;
		scanf("%d", &K);
		for (int j = 0; j < K; j++)
			scanf("%d", &A[j]);
		bool flag = false;
		for (int j = 0; j < K; j++)
			for (int k = j; k < K; k++)
			{
				if (Check(A[j], A[k]))
				{
					flag = true;
					j = K;
					break;
				}
			}
		if (flag == false) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}