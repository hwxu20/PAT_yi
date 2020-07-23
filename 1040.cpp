#include <iostream>
#include <string>
#include <vector>
using namespace std;
const long long int DIVISOR = 1000000007;

int main()
{
	long long int Num_PAT = 0;
	string a;
	cin >> a;
	unsigned int N = a.size();

	//暴力算法
	//for (int i = 0; i < a.size(); i++)
	//{
	//	for (int j = i + 1; j < a.size(); j++)
	//	{
	//		if (a[i] != 'P') break;
	//		for (int k = j + 1; k < a.size(); k++)
	//		{
	//			if (a[j] != 'A') break;
	//			else if (a[k] == 'T')
	//			{
	//				Num_PAT++;
	//				if (Num_PAT >= DIVISOR)
	//					Num_PAT -= DIVISOR;
	//			}
	//		}
	//	}
	//}

	//简化算法——寻找A，PAT的数目=A之前P的数目*A之后T的数目
	vector<int> P(N, 0), T(N, 0);
	int cnt_p = 0, cnt_t = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] == 'P') P[i] = ++cnt_p;
		else P[i] = cnt_p;

		if (a[N - i - 1] == 'T') T[N - i - 1] = ++cnt_t;
		else T[N - i - 1] = cnt_t;
	}

	for (int i = 1; i < N; i++)
		if (a[i] == 'A') Num_PAT = (Num_PAT + P[i] * T[i]) % DIVISOR;

	printf("%lld", Num_PAT);

	return 0;
}