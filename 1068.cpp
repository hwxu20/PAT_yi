#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

struct Pixel
{
	int data;
	int x; int y;
	Pixel(int d = 0, int xx = 0, int yy = 0): data(d), x(xx), y(yy) {}
};

int main()
{
	int M, N, TOL;
	scanf("%d %d %d", &M, &N, &TOL);

	int** Data = new int*[N];
	for (int i = 0; i < N; i++)
		Data[i] = new int[M];

	map<int, int> Special;
	vector<Pixel*> Unique;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &Data[i][j]);
			Special[Data[i][j]]++;
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (Special[Data[i][j]] == 1)
			{
				int flag = 1;
				int dxmin = -1, dxmax = 2, dymin = -1, dymax = 2;
				while (dxmin + i < 0) dxmin++;
				while (dxmax + i > N) dxmax--;
				while (dymin + j < 0) dymin++;
				while (dymax + j > M) dymax--;
				for (int a = dxmin; a < dxmax; a++)
				{
					if (flag == 0) break;
					for (int b = dymin; b < dymax; b++)
					{
						if (a == 0 && b == 0) continue;
						if (fabs(Data[i + a][j + b] - Data[i][j]) <= TOL)
						{
							flag = 0; break;
						}
					}
				}
				if (flag == 1)
				{
					Pixel* p = new Pixel(Data[i][j], i + 1, j + 1);
					Unique.push_back(p);
				}
			}
		}

	if (Unique.size() == 1) printf("(%d, %d): %d\n", Unique[0]->y, Unique[0]->x, Unique[0]->data);
	else if (Unique.size() > 1) printf("Not Unique\n");
	else printf("Not Exist\n");

	return 0;
}
