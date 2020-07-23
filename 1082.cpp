#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	int id, x, y;
	double Maxdis, Mindis;
	int ChapID, CaiID;
	scanf("%d %d %d", &id, &x, &y);
	ChapID = id;
	CaiID = id;
	Maxdis = sqrt(x*x + y*y);
	Mindis = sqrt(x*x + y*y);

	for (int i = 1; i < N; i++)
	{
		double tmp;
		scanf("%d %d %d", &id, &x, &y);
		tmp = sqrt(x*x + y*y);
		if (tmp < Mindis)
		{
			ChapID = id;
			Mindis = tmp;
		}
		if (Maxdis < tmp)
		{
			CaiID = id;
			Maxdis = tmp;
		}
	}

	printf("%04d %04d\n", ChapID, CaiID);

	return 0;
}