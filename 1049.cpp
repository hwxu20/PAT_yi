#include <iostream>
using namespace std;


int main()
{
	int N;
	scanf("%d", &N);

	long double *p = new long double[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%Lf",&p[i]);
	}

	long double sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += p[i] * (N - i) * (i + 1);
	}
	printf("%.2Lf\n", sum);

	delete[] p;
	return 0;
}