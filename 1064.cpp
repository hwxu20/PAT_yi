#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 46

int main()
{
	int Friend[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
		Friend[i] = 0;

	int N;
	scanf("%d", &N);

	string a; 
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int sum = 0;
		cin >> a;
		for (int j = 0; j < a.size(); j++)
			sum += a[j] - '0';
		if (Friend[sum] == 0) cnt++;
		Friend[sum]++;
	}
	
	printf("%d\n", cnt);
	int k = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (Friend[i] > 0)
		{
			if (k == 0) printf("%d", i);
			else printf(" %d", i);
			k++;
		}
	}
	printf("\n");

	return 0;
}
