#include <iostream>
using namespace std;

#define GetMax(a, b) a > b ? a : b

struct SingleOp
{
	char Op;
	bool IsAns;
	int Num_Mis;
	SingleOp() { Op = '0'; IsAns = false;  Num_Mis = 0; }
};

struct Options
{
	int Num_Ans;
	int Num_Correct;
	SingleOp p[5];
	Options(int n = 0, int nc = 0) : Num_Ans(n), Num_Correct(nc) {}
	bool check(char c);
};

bool Options::check(char c)
{
	if (p[c - 'a'].IsAns) return true;
	else return false;
}

struct Question
{
	int No;
	int Points;
	Options ops;
	int T_Mistake;
	Question(int no = 0, int p = 0, int n = 0, int nc = 0, int t = 0) : No(no), Points(p), T_Mistake(t) 
	{ ops = Options(n, nc); }
	void update(char* a, int n, double& pt);//更新错误选项的数目，计算学生分数
};

void Question::update(char* a, int n, double& pt)
{
	bool flag = true;
	int num_c = 0;
	for (int i = 0; i < ops.Num_Ans; i++)
		if (ops.p[i].IsAns) ops.p[i].Num_Mis++;

	for (int i = 0; i < n; i++)
	{
		if (!ops.check(a[i])) { flag = false; ops.p[a[i] - 'a'].Num_Mis++; }
		else { num_c++; ops.p[a[i] - 'a'].Num_Mis--; }
	}
	if ((flag == true) && (num_c == ops.Num_Correct)) pt += Points;
	else if (flag == true) pt += 0.5 * Points;

	T_Mistake = 0;
	for (int i = 0; i < ops.Num_Ans; i++)
		T_Mistake += ops.p[i].Num_Mis;
}

void ReadAns(int nc, char* s)
{
	char c = '0';
	int i = 0;
	while (c != ')')
	{
		c = getchar();
		if ((c != ' ') && (c != ')')) s[i++] = c;
	}
}

bool cmp(Question a, Question b)
{
	return a.T_Mistake == b.T_Mistake ? (a.T_Mistake > b.T_Mistake) : (a.No < b.No);
}

bool cmp_op(SingleOp a, SingleOp b)
{
	return a.Num_Mis == b.Num_Mis ? (a.Num_Mis > b.Num_Mis) : (a.Op < b.Op);
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	Question* Q = new Question[M];

	for (int i = 0; i < M; i++)
	{
		int p, num, num_c;
		scanf("%d %d %d", &p, &num, &num_c);
		Q[i].Points = p;
		Q[i].ops.Num_Ans = num;
		Q[i].ops.Num_Correct = num_c;
		Q[i].No = i + 1;
		for (int j = 0; j < num; j++)
		{
			Q[i].ops.p[j].Op = 'a' + j;
			Q[i].ops.p[j].IsAns = false;
			Q[i].ops.p[j].Num_Mis = 0;
		}
			
		for (int j = 0; j < num_c; j++)
		{
			char c; cin >> c;
			Q[i].ops.p[c - 'a'].IsAns = true;
		}
	}

	for (int i = 0; i < N; i++)
	{
		int num_c;
		double pt = 0.0;
		char s[6] = "00000";
		for (int j = 0; j < M; j++)
		{
			char c = '0';
			while (c != '(') c = getchar();
			scanf("%d", &num_c);
			ReadAns(num_c, s);
			Q[j].update(s, num_c, pt);
		}
		printf("%.1lf\n", pt);
	}

	int max_mis = 0;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < Q[i].ops.Num_Ans; j++)
			max_mis = GetMax(max_mis, Q[i].ops.p[j].Num_Mis);
	if (max_mis == 0) printf("Too simple\n");
	else
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < Q[i].ops.Num_Ans; j++)
			{
				if (max_mis == Q[i].ops.p[j].Num_Mis)
					printf("%d %d-%c\n", max_mis, Q[i].No, Q[i].ops.p[j].Op);
			}
		}
	}

	delete[] Q;
	return 0;
}