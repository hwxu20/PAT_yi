#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool isPrime(int n)
{
	if ((n == 2) || (n == 3)) return 1;
	if ((n % 6) != 1 && (n % 6) != 5) return 0;
	for (int i = 5; i <= ceil(sqrt(n)); i += 6)
		if ((n%i) == 0 || (n % (i + 2) == 0)) return 0;
	return 1;
}

void findGift(int a, int i)
{
	if (i == 1) printf("Mystery Award\n");
	else if (isPrime(i)) printf("Minion\n");
	else printf("Chocolate\n");
}

void CheckID(int *S, int a, bool* Checked)
{
	bool noID = 1, nogift = 1;
	if (S[a] != 0)
	{ 
		noID = 0; 
		if (Checked[S[a]] != 1) nogift = 0;
	}
	printf("%04d: ", a);
	if (noID == 1) printf("Are you kidding?\n");
	else if (nogift == 1) printf("Checked\n");
	else
	{
		findGift(a, S[a]);
		Checked[S[a]] = 1;
	}
}

int main()
{
	int N;
	scanf("%d", &N);

	int S[10000]; int id;
	for (int i = 0; i < 10000; i++) S[i] = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> id;
		S[id] = i + 1;
	}

	bool *Checked = new bool[N];
	for (int i = 0; i < N; i++) Checked[i] = 0;

	int M; 

	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		cin >> id;
		CheckID(S, id, Checked);
	}

	delete[] Checked;
	return 0;
}