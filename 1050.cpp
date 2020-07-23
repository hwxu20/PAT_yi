#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int N;
	scanf("%d", &N);

	int m, n;
	for (n = sqrt(N); n > 0; n--)
		if (N % n == 0) break;
	m = N / n;
		
	int *p = new int[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &p[i]);
	sort(p, p + N, cmp);

	//动态分配二维数组内存
	int **q = new int*[m];
	for (int i = 0; i < m; i++)
		q[i] = new int[n];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			q[i][j] = 0;

	int mm = 0, nn = 0, i = 0;
	int m_min = -1, m_max = m, n_min = -1, n_max = n;
	while (i < N)
	{
		while ((nn < n_max) && (i < N)) { q[mm][nn++] = p[i++]; } 
//		while (nn < n_max) { q[mm][nn++] = p[i++]; }
		mm++; nn--;
		while ((mm < m_max) && (i < N)) { q[mm++][nn] = p[i++]; }
//		while (mm < m_max) { q[mm++][nn] = p[i++]; }
		mm--; nn--;
		while ((nn > n_min) && (i < N)) { q[mm][nn--] = p[i++]; }
//		while (nn > n_min) { q[mm][nn--] = p[i++]; }
		mm--; nn++;
		while ((mm > m_min + 1) && (i < N)) { q[mm--][nn] = p[i++]; }
//		while (mm > m_min + 1) { q[mm--][nn] = p[i++]; }//可能出现下标i越界，因为只检测了m越界与否，需要同时检测i是否越界，或者及时更新max, min
		mm++; nn++;
		m_min++; m_max--;
		n_min++; n_max--;

	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == 0) printf("%d", q[i][j]);
			else printf(" %d", q[i][j]);
			if (j == n - 1) printf("\n");
		}
	}

	for (int i = 0; i < n; i++) delete[] q[i];
	delete[] q;
	delete[] p;

	return 0;
}