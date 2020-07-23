#include <iostream>
using namespace std;

bool isOk(int w1, int w2, int* p, int* q, int N)//w1,w2狼, p是发言结果，q是w1,w2两狼情况下的排列
{
	int cnt_w = 0, cnt_p = 0; //狼和人撒谎的次数
	int id, isw;

	//判断两狼有且仅有一只撒谎
	id = abs(p[w1]) - 1; isw = ((p[w1] > 0) ? 1 : -1);
	if (q[id] != isw) cnt_w++;
	id = abs(p[w2]) - 1; isw = ((p[w2] > 0) ? 1 : -1);
	if (q[id] != isw) cnt_w++;
	if (cnt_w != 1) return false;

	for (int i = 0; i < N; i++)
	{
		if ((i == w1) || (i == w2)) continue;
		id = abs(p[i]) - 1; isw = ((p[i] > 0) ? 1 : -1);
		if (q[id] == isw) continue;
		else cnt_p++;
	}
	if (cnt_p != 1) return false;
	else return true;
}

int main()
{
	int N;
	scanf("%d", &N);
	
	int* p = new int[N];
	int* q = new int[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &p[i]);
		q[i] = 1;
	}

	int w1, w2;
	bool flag = false;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
		{
			q[i] = -1; q[j] = -1;
			flag = isOk(i, j, p, q, N);
			if (flag)
			{
				w1 = i + 1; w2 = j + 1;
				i = N; break;
			}
			else 
			{
				q[i] = 1; q[j] = 1;
				continue;
			}
		}
	if (flag) { printf("%d %d\n", w1, w2); }
	else printf("No Solution\n");

	delete[] p;
	delete[] q;
	return 0;
}