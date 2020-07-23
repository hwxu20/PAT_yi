#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp(double a, double b)
{
	return a < b ? true : false;
}

int main()
{
	int N;
	scanf("%d", &N);

	double* p = new double[N];
	for (int i = 0; i < N; i++)
		scanf("%lf", &p[i]);

	sort(p, p + N, cmp);

	double sum = 0.0;
	sum += (p[0] + p[1]) * pow(0.5, N - 1);
	for (int i = 2; i < N; i++)
		sum += p[i] * pow(0.5, N - i);

	int result = int(sum);
	printf("%d\n", result);
	return 0;
}