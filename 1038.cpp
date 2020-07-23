#include <iostream>
#include <string>
#include <map>
using namespace std;


int main()
{
	int N, M;
	cin >> N;
	map<int, int> Student;
	int temp = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		Student[temp]++;
	}

	cin >> M;
	int *p = new int[M];
	for (int i = 0; i < M; i++)
		cin >> p[i];

	printf("%d", Student[p[0]]);
	for (int i = 1; i < M; i++)
		printf(" %d", Student[p[i]]);

	delete[] p;
	return 0;
}