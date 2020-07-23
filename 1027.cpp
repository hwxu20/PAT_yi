#include <iostream>
using namespace std;

int main()
{
	int N;
	char c;
	cin >> N >> c;

	int N_used = 1, N_left = N - 1, Num = 1;
	
	while (N_left > 0)
	{
		int temp = 2 * Num + 1;
		if (N_used + 2 * temp <= N_left)
		{
			N_left -= 2 * temp;
			Num++;
		}
		else
			break;
	}

	for (int j = Num - 1; j >= 0; j--)
	{
		for (int k = 0; k < Num - 1 - j; k++) printf(" ");
		for (int k = 0; k < (2 * j + 1); k++) printf("%c", c);
		//for (int k = 0; k < Num - 1 - j; k++) printf(" ");
		printf("\n");
	}
	for (int j = 1; j < Num; j++)
	{
		for (int k = 0; k < Num - 1 - j; k++) printf(" ");
		for (int k = 0; k < (2 * j + 1); k++) printf("%c", c);
		//for (int k = 0; k < Num - 1 - j; k++) printf(" ");
		printf("\n");
	}

	printf("%d\n", N_left);

	return 0;
}
