#include <iostream>
#include <vector>
using namespace std;

int Check(int a)
{
	int n = 0; int tmp = a; int N = -1;
	vector<int> vec_a;
	while (tmp > 0)
	{
		int rem = tmp % 10;
		vec_a.push_back(rem);
		tmp = tmp / 10; n++;
	}
	for (int i = 1; i < 10; i++)
	{
		bool flag = true;
		int r = i * a * a; int tmp_r = r;
		for (int j = 0; j < n; j++)
		{
			int rem = tmp_r % 10;
			if (rem != vec_a[j])
			{
				flag = false;
				break;
			}
			tmp_r = tmp_r / 10;
		}
		if (flag == true)
		{
			N = i;
			break;
		}
	}
	return N;
}

int main()
{
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int a, N;
		scanf("%d", &a);
		N = Check(a);
		if (N > 0) printf("%d %d\n", N, N*a*a);
		else printf("No\n");
	}

	return 0;
}