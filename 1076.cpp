#include <iostream>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	string PW;
	for (int i = 0; i < N; i++)
	{
		getchar();
		char c1, c2, c3, c4, r1, r2, r3, r4;
		scanf("%c-%c %c-%c %c-%c %c-%c", &c1, &r1, &c2, &r2, &c3, &r3, &c4, &r4);
		if (r1 == 'T') PW.push_back(c1 - 'A' + '1');
		if (r2 == 'T') PW.push_back(c2 - 'A' + '1');
		if (r3 == 'T') PW.push_back(c3 - 'A' + '1');
		if (r4 == 'T') PW.push_back(c4 - 'A' + '1');
	}

	for (int i = 0; i < PW.size(); i++)
		printf("%c", PW[i]);
	printf("\n");

	return 0;
}