#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPrime(long long a)
{
	if (a == 1) return false;
	if ((a == 2) || (a == 3)) return true;
	if (a % 2 == 0) return false;
	for (int i = 3; i <= sqrt(a); i+=2)
	{
		if (a % i == 0) return false;
	}
	return true;
}

int main()
{
	int L, K;
	scanf("%d %d", &L, &K);
	string a;
	cin >> a;

	bool flag = false;
	for (int i = 0; i <= L - K; i++)
	{
		string b(a.begin() + i, a.begin() + i + K);
		long long c = 0;
		for (int j = 0; j < K; j++)
		{
			c = c * 10;
			c += b[j] - '0';
		}
		flag = isPrime(c);
		if (flag == true)
		{
			cout << b << endl;
			break;
		}
		else continue;
	}

	if (flag == false) printf("404\n");

	return 0;
}