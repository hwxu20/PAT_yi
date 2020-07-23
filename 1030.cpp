#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	long long p;
	cin >> N >> p;

	long long *ptr = new long long[N];
	for (int i = 0; i < N; i++)
		cin >> ptr[i];

	sort(ptr, ptr + N);
	int max = 0, temp = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + max; j < N; j++)
		{
			if (ptr[j] <= ptr[i] * p)
			{
				temp = j - i + 1;
				if (temp > max)
					max = temp;
			}
			else
				break;
		}
	}

	printf("%d\n", max);

	delete[] ptr;
	return 0;
}