#include <iostream>
#include <cstring>
using namespace std;

const char Odd_code[13] = { '0','1','2','3','4','5','6','7','8','9','J','Q','K' };

int main()
{
	char A[100], B[100], C[100];
	cin >> A >> B;

	int A_size = strlen(A), B_size = strlen(B);
	
	int j = 0, Max_size;
	if (A_size < B_size) Max_size = B_size;
	else Max_size = A_size;

	while (j < Max_size)
	{
		int a, b;
		if (j > A_size - 1) a = 0;
		else a = A[A_size - j - 1] - '0';
		if (j > B_size - 1) b = 0;
		else b = B[B_size - j - 1] - '0';

		if ((j + 1) % 2 == 1) C[Max_size - j - 1] = Odd_code[(a + b) % 13];
		else
		{
			if (b < a) C[Max_size - j - 1] = b + 10 - a + '0';
			else  C[Max_size - j - 1] = b - a + '0';
		}
		j++;
	}
	
	for (int i = 0; i < Max_size; i++) printf("%c", C[i]);

	return 0;
}