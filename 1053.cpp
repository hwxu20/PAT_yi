#include <iostream>
using namespace std;

int main()
{
	int N, D;
	double e;
	scanf("%d %lf %d", &N, &e, &D);

	int *K = new int[N];
	int *Low = new int[N];
	for (int i = 0; i < N; i++) Low[i] = 0;

	int Empty_p = 0, Empty = 0;
	for (int i = 0; i < N; i++)
	{
		double elec_used;
		scanf("%d", &K[i]);
		for (int j = 0; j < K[i]; j++)
		{
			scanf("%lf", &elec_used);
			if (elec_used < e) Low[i]++;
		}
		if ((Low[i] > K[i] / 2) && (K[i] > D)) Empty++;
		else if (Low[i] > K[i] / 2) Empty_p++;
	}

	double ep_ratio, e_ratio;
	ep_ratio = 100.0* Empty_p / N;
	e_ratio = 100.0* Empty / N;

	printf("%.1lf\%% %.1lf\%%", ep_ratio, e_ratio);

	return 0;
}