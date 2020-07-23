#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N = 0, M = 0;
	cin >> N >> M;

	int *p = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> p[i];
	}

	M = M % N;
	reverse(p, p + N - M);
	reverse(p + N - M, p + N);
	reverse(p, p + N);

	for (int i = 0; i < N; i++)
	{
		if (i == N - 1)
			cout << p[i];
		else
			cout << p[i] << " ";
	}
	cout << endl;

	return 0;
}