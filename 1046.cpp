#include <iostream>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	int a_hu, a_ha, b_hu, b_ha;
	int a_win = 0, b_win = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d %d", &a_ha, &a_hu, &b_ha, &b_hu);
		if ((a_hu == (a_ha + b_ha)) && (b_hu == (a_ha + b_ha))) continue;
		else if (a_hu == (a_ha + b_ha)) a_win++;
		else if (b_hu == (a_ha + b_ha)) b_win++;
	}

	printf("%d %d\n", b_win, a_win);

	return 0;
}
