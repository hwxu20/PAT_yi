#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	int M, N, S;
	scanf("%d %d %d", &M, &N, &S);

	if (M >= S)
	{
		map<string, int> Winner;
		for (int i = 0; i < S; i++)
		{
			string tmp; cin >> tmp;
			if (i == S - 1) { Winner[tmp]++; printf("%s\n", tmp.data()); }
		}
		int rep = 0;
		for (int i = S; i < M; i++)
		{
			string tmp; cin >> tmp;
			if ((i - S + 1 - rep) % N == 0)
			{
				if (Winner[tmp] > 0) rep++;
				else { Winner[tmp]++; printf("%s\n", tmp.data()); }
			}
		}
	}
	else
	{
		for (int i = 0; i < M; i++)
		{
			string tmp; cin >> tmp;
		}
		printf("Keep going...\n");
	}

	return 0;
}