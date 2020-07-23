#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
	string Name;
	int Height;
};

bool Namecmp(string a, string b)
{
	int len_a = strlen(a.data()), len_b = strlen(b.data());
	int len = min(len_a, len_b);
	for (int i = 0; i < len; i++)
	{
		if (a[i] < b[i]) return 1;
		else if (a[i] > b[i]) return 0;
	}
	if (len_a > len_b) return 0;
	else return 1;
}

bool cmp(Student a, Student b)
{
	return a.Height != b.Height ? a.Height > b.Height : Namecmp(a.Name, b.Name);
}

int main()
{
	int N, K, N_row, N_Last;
	scanf("%d %d", &N, &K);
	N_row = N / K;
	N_Last = N_row + N % K;

	Student *p = new Student[N];
	for (int i = 0; i < N; i++)
		cin >> p[i].Name >> p[i].Height;
	sort(p, p + N, cmp);

	string *q = new string[N_Last];

	//最后一排
	int mid = N_Last / 2, i = 0, j = 1;
	q[mid] = p[i++].Name;
	while (i < N_Last)
	{
		if (mid - j >= 0) q[mid - j] = p[i++].Name;
		if (mid + j < N_Last) q[mid + j] = p[i++].Name;
		j++;
	}
	printf("%s", q[0].data());
	for (int i = 1; i < N_Last; i++)
		printf(" %s", q[i].data());
	printf("\n");

	//其他排
	for (int k = 0; k < K - 1; k++)
	{
		int ik = N_Last + k * N_row;
		i = 0; j = 1;
		mid = N_row / 2;
		Student *P = p + ik;
		q[mid] = P[i++].Name;
		while (i < N_row)
		{
			if (mid - j >= 0) q[mid - j] = P[i++].Name;
			if (mid + j < N_row) q[mid + j] = P[i++].Name;
			j++;
		}
		printf("%s", q[0].data());
		for (int i = 1; i < N_row; i++)
			printf(" %s", q[i].data());
		printf("\n");
	}

	delete[] q;
	delete[] p;
	return 0;
}