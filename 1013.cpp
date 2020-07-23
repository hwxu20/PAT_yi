#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n);

int main()
{
	int M = 0, N = 0, NumPrime = 0, PrimeCnt = 0, i = 0, k = 0;
	cin >> M >> N;
	int *p = new int[N - M + 1];

	i = 2;

	while(PrimeCnt != N)
	{
		if (isPrime(i))
		{
			if (M - 1 <= PrimeCnt)
				p[PrimeCnt - M + 1] = i;
			PrimeCnt++;
		}
		if (i == 2)
			i = 3;
		else
		{
			i += 2;
		}
	}

	for (int j = 0; j < N - M + 1; j++)
	{
		if (k == 0)
		{
			cout << p[j];
			k++;
		}
		else if (k == 9)
		{
			cout << " " << p[j] << endl;
			k = 0;
		}
		else
		{
			cout << " " << p[j];
			k++;
		}
	}

	return 0;
}

bool isPrime(int n)
{
	if (n == 1) return 0;
	if ((n == 2) || (n == 3)) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 3; i <= floor(sqrt(n)); i+=2)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}
