#include <iostream>
#include <cmath>
using namespace std;

int Round_45(double a)
{
	int b;
	double dec;
	b = static_cast<int>(floor(a));
	dec = a - b;
	if (dec >= 0.5) return (b + 1);
	else return b;
}

int main()
{
	int N_col, N_row;
	char c;
	cin >> N_col >> c;

	N_row = Round_45(double(N_col * 0.5));
	for (int i = 0; i < N_col; i++)
		printf("%c", c);
	printf("\n");

	for (int i = 0; i < N_row - 2; i++)
	{
		printf("%c", c);
		for (int j = 0; j < N_col - 2; j++)
			printf(" ");
		printf("%c\n", c);
	}

	for (int i = 0; i < N_col; i++)
		printf("%c", c);
	printf("\n");

	return 0;
}