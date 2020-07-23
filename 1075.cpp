#include <iostream>
using namespace std;

#define MAXSIZE 100002
#define AddHead 100000
//#define AddTrai 100001

struct ListNode
{
	int data;
	int pred;
	int succ;
	ListNode(int d = 0, int p = 0, int s = 0): data(d), pred(p), succ(s) {}
};

void InsertA(ListNode* List, int add, int r)
{
	if ((add == r) || (add == List[r].succ)) return;
	List[List[add].pred].succ = List[add].succ;
	List[List[add].succ].pred = List[add].pred;
	List[List[r].succ].pred = add; List[add].succ = List[r].succ;
	List[r].succ = add; List[add].pred = r;
}

ListNode List[MAXSIZE];

int main()
{
	int FirstAdd, N, K;
	scanf("%d %d %d", &FirstAdd, &N, &K);
	List[AddHead].data = 0; List[AddHead].pred = -1; List[AddHead].succ = FirstAdd;
//	List[AddTrai].data = 0; List[AddTrai].pred = -1; List[AddTrai].succ = -1;
	List[FirstAdd].pred = AddHead;

	int add, d, add_succ;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &add, &d, &add_succ);
		List[add].data = d;
		List[add].succ = add_succ;
		if (add_succ != -1) List[add_succ].pred = add;
	}

	int Neg_flag = 0, K_flag = 0, flag = 0;
	int FirstNeg = -1, FirstK = -1, First0toK = -1;
	int cur = FirstAdd;
	for (int i = 0; i < N; i++)//找到三个分类的第一个元素
	{
		if (cur == -1) break;
		if ((List[cur].data < 0) && (Neg_flag == 0)) { FirstNeg = cur; Neg_flag = 1; }
		if ((List[cur].data > K) && (K_flag == 0)) { FirstK = cur; K_flag = 1; }
		if ((0 <= List[cur].data) && (List[cur].data <= K) && (flag == 0)) { First0toK = cur; flag = 1; }
		if ((Neg_flag == 1) && (K_flag == 1) && (flag == 1)) break;
		cur = List[cur].succ;
	}

	int InsertAdd = AddHead;
	if (Neg_flag == 1)
	{
		InsertA(List, FirstNeg, InsertAdd);
		InsertAdd = FirstNeg;
	}
	if (flag == 1)
	{
		InsertA(List, First0toK, InsertAdd);
		InsertAdd = First0toK;
	}
	if (K_flag == 1)
	{
		InsertA(List, FirstK, InsertAdd);
		InsertAdd = FirstK;
	}

	cur = List[InsertAdd].succ;
	int LastNeg = FirstNeg, LastK = FirstK, Last0toK = First0toK;
	for (int i = 0; i < N; i++)
	{
		if (cur == -1) break;
		int tmp = List[cur].succ;
		if (List[cur].data < 0)
		{
			InsertA(List, cur, LastNeg);
			LastNeg = cur;
		}
		else if ((0 <= List[cur].data) && (List[cur].data <= K) )
		{
			InsertA(List, cur, Last0toK);
			Last0toK = cur;
		}
		else
		{
			InsertA(List, cur, LastK);
			LastK = cur;
		}
		cur = tmp;
	}

	cur = List[AddHead].succ;
	for (int i = 0; i < N; i++)
	{
		if (List[cur].succ == -1)
		{
			printf("%05d %d -1\n", cur, List[cur].data);
			break;
		}
		printf("%05d %d %05d\n", cur, List[cur].data, List[cur].succ);
		cur = List[cur].succ;
	}

	return 0;
}