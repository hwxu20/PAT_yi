#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX_SIZE 100000

struct Guest
{
	int ID;
	int flag;
	Guest() { ID = -1; flag = 0; }
};

bool cmp(Guest a, Guest b)
{
	return a.ID < b.ID ? true : false;
}

int main()
{
	int N;
	scanf("%d", &N);

	int Couple[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
		Couple[i] = -1;
	
	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		Couple[a] = b; Couple[b] = a;
	}
	
	int M;
	scanf("%d", &M);
	Guest* g = new Guest[M];

	int Couple_flag[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
		Couple_flag[i] = 0;

	int cnt = 0;
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &g[i].ID);
		if (Couple[g[i].ID] == -1) g[i].flag = 1;
		else
		{
			Couple_flag[g[i].ID]++;
			Couple_flag[Couple[g[i].ID]]++;
		}
	}
	for (int i = 0; i < M; i++)
	{
		if ((Couple[g[i].ID] != -1) && (Couple_flag[g[i].ID] == 1))
			g[i].flag = 1;
		if (g[i].flag == 1) cnt++;
	}
	printf("%d\n", cnt);

	if (cnt > 0)
	{
		sort(g, g + M, cmp);
		int k = 0;
		for (int i = 0; i < M; i++)
		{
			if (g[i].flag == 1)
			{
				if (k == 0) printf("%05d", g[i].ID);
				else printf(" %05d", g[i].ID);
				k++;
			}
		}
		printf("\n");
	}

	delete[] g;
	return 0;
}
