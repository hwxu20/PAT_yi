#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	string Hand[10], Eye[10], Mouth[10];
	
	char ch = '0'; 
	int H_num = 0, E_num = 0, M_num = 0;

	getline(cin, a);
	int i = 0;
	while (i < a.size())
	{
		if (a[i] == '[')
		{
			i++;
			while (a[i] != ']')
			{
				Hand[H_num].push_back(a[i]);
				i++;
			}
			i++;
			H_num++;
		}
		else i++;
	}

	getline(cin, a); i = 0;
	while (i < a.size())
	{
		if (a[i] == '[')
		{
			i++;
			while (a[i] != ']')
			{
				Eye[E_num].push_back(a[i]);
				i++;
			}
			i++;
			E_num++;
		}
		else i++;
	}

	getline(cin, a); i = 0;
	while (i < a.size())
	{
		if (a[i] == '[')
		{
			i++;
			while (a[i] != ']')
			{
				Mouth[M_num].push_back(a[i]);
				i++;
			}
			i++;
			M_num++;
		}
		else i++;
	}

	
	int N;
	scanf("%d", &N);

	int Hl, El, M, Er, Hr;
	for (int j = 0; j < N; j++)
	{
		scanf("%d %d %d %d %d", &Hl, &El, &M, &Er, &Hr);
		if ((Hl < 1) || (Hl > H_num) || (Hr < 1) || (Hr > H_num) || (El < 1) || (El > E_num) || (Er < 1) || (Er > E_num) || (M < 1) || (M > M_num))
		{
			printf("Are you kidding me? @\\/@\n"); continue;
		}
		printf("%s(%s%s%s)%s\n", Hand[Hl - 1].data(), Eye[El - 1].data(), Mouth[M - 1].data(), Eye[Er - 1].data(), Hand[Hr - 1].data());
//		printf("%s\n", Hand[Hl - 1]);
	}


	return 0;
}