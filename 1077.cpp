#include <iostream>
using namespace std;

#define GetMax(a, b) a > b ? a : b
#define GetMin(a, b) a < b ? a : b

double GradeCal(double* g, int N, int M)
{
	double GT = g[0];
	double max = 0, min = 0, sum = 0, n = 0, GS = 0;
	for (int i = 1; i < N; i++)
	{
		if ((0 <= g[i]) && (g[i] <= M))
		{
			if (n == 0) { max = g[i]; min = g[i]; }
			else
			{
				max = GetMax(max, g[i]);
				min = GetMin(min, g[i]);
			}
			sum += g[i];
			n++;
		}
	}
	GS = (sum - max - min) / (n - 2);

	return (GT + GS) * 0.5;
}

int Around(double a)
{
	double decimal;
	int integer;
	integer = int(a);
	decimal = a - integer;
	if (decimal < 0.5) return integer;
	else return integer + 1;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	double* g = new double[N];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			scanf("%lf", &g[j]);
		printf("%d\n", Around(GradeCal(g, N, M)));
	}

	delete[] g;
	return 0;
}