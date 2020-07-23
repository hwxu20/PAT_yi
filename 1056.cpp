#include <iostream>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	
	int p = 0, sum = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &p);
		sum += 11 * (N - 1)*p;
	}
		
	printf("%d\n", sum);

	return 0;
}