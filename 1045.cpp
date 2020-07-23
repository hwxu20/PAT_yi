#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<long long int> a;
	long long int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		a.push_back(temp);
	}

	long long int *max_l = new long long int[N];
	long long int *min_r = new long long int[N];
	long long int temp_max = a[0], temp_min = a[N-1];
	for (int i = 0; i < N; i++)
	{
		if (a[i] > temp_max)
			temp_max = a[i];
		max_l[i] = temp_max;
		if (a[N - i - 1] < temp_min)
			temp_min = a[N - i - 1];
		min_r[N - i - 1] = temp_min;
	}

	vector<long long int> MainElem;
	if (a[0] <= min_r[1])
		MainElem.push_back(a[0]);
	for (int i = 1; i < N - 1; i++)
	{
		if ((max_l[i - 1] <= a[i]) && (a[i] <= min_r[i + 1]))
			MainElem.push_back(a[i]);
	}
	if (max_l[N-2] <= a[N-1])
		MainElem.push_back(a[N-1]);

	printf("%d\n", MainElem.size());
	if (MainElem.size() > 0) printf("%lld", MainElem[0]);
	for (int i = 1; i < MainElem.size(); i++)
		printf(" %lld", MainElem[i]);
	printf("\n");

	delete[] max_l;
	delete[] min_r;
	return 0;
}