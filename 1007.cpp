#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n);
bool isPrime_3(int n);

int main()
{
	int N = 0, Prime_last = 2, Prime_cur = 2, PrimePair_Cnt = 0;
	cin >> N;

	for (int i = 2; i < N + 1; i++)
	{
		if (isPrime_3(i))
		{
			Prime_last = Prime_cur;
			Prime_cur = i;
			if ((Prime_cur - Prime_last) == 2)
				PrimePair_Cnt++;
		}
	}

//	cout << PrimePair_Cnt << endl;
	printf("%d\n", PrimePair_Cnt);
	return 0;
}


bool isPrime(int n)
{
	if ((n == 2) || (n == 3)) return 1;
	if (n%2 == 0) return 0;
	for (int i = 3; i <= floor(sqrt(n)); i += 2)
	{
		if (n%i == 0) return 0;
	}
	return 1;
}

//Fastest prime number judgement algorithm

bool isPrime_3(int n) {
	if (n == 2 || n == 3)	return 1;
	if (n % 6 != 1 && n % 6 != 5)	return 0;
	for (int i = 5; i <= floor(sqrt(n)); i += 6)
		if (n%i == 0 || n % (i + 2) == 0)	return 0;
	return 1;
}

