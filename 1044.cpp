#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

const string M_unit[13] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
const string M_ten[13] = { "tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };


//»ğĞÇÎÄtoµØÇòÎÄ
void MtoE(string a)
{
	int b = 0;
	if (a.size() <= 4)
	{
		for (int i = 0; i < 13; i++)
			if (a == M_unit[i])
			{   
				b = i; break;
			}
		for (int i = 0; i < 13; i++)
			if (a == M_ten[i])
			{
				b = i * 13; break;
			}
	}
	else
	{
		string a1(a.substr(0, 3));
		string a2(a.substr(4, a.size() - 4));
		int b1, b2;
		for (int i = 0; i < 13; i++)
			if (a1 == M_ten[i])
			{
				b1 = i; break;
			}
		for (int i = 0; i < 13; i++)
			if (a2 == M_unit[i])
			{
				b2 = i;
				break;
			}
				
		b = b1 * 13 + b2;
	}
	printf("%d\n", b);
}

void EtoM(int a)
{
	int a1, a2;
	string b;
	a1 = a / 13;
	a2 = a % 13;

	if (a1 == 0) b = M_unit[a2];
	else if (a2 == 0) b = M_ten[a1];
	else b = M_ten[a1] + " " + M_unit[a2];

	printf("%s\n", b.data());

}

int main()
{
	int N;
	cin >> N; getchar();

	string *num_series = new string[N];
	for (int i = 0; i < N; i++)
		getline(cin, num_series[i]);

	for (int i = 0; i < N; i++)
	{
		if (('0' <= num_series[i][0]) && (num_series[i][0] <= '9'))
			EtoM(stoi(num_series[i]));
		else MtoE(num_series[i]);
	}

	delete[] num_series;
	return 0;
}