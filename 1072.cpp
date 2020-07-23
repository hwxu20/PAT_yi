#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	map<int, int> Item;

	for (int i = 0; i < M; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		Item[tmp]++;
	}
	
	int stu_cnt = 0, item_cnt = 0;
	for (int i = 0; i < N; i++)
	{
		string name;
		int n = 0, flag = 0, print_cnt = 0;
		cin >> name;
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
		{
			int tmp = 0;
			map<int, int>::iterator iter = Item.begin();
			scanf("%d", &tmp);
			iter = Item.find(tmp);
			if (iter != Item.end())
			{
				flag = 1;
				item_cnt++;
				if (print_cnt == 0) printf("%s: %04d", name.data(), tmp);
				else printf(" %04d", tmp);
				print_cnt++;
			}
		}
		if (flag == 1) { stu_cnt++; printf("\n"); }
	}
	printf("%d %d\n", stu_cnt, item_cnt);

	return 0;
}