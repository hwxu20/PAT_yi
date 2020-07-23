#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;

class Mooncake
{
public:
	double Amount;
	double T_value;
	double A_value;
	void update_A();
};

void Mooncake::update_A()
{
	A_value = T_value / Amount;
}

bool cmp(Mooncake a, Mooncake b)
{
	return a.A_value > b.A_value;
}


int main()
{
	int N = 0;
	double D = 0.0, V_sum = 0.0;
	cin >> N >> D;
	Mooncake *p = new Mooncake[N];
	
	for (int i = 0; i < N; i++)
	{
		cin >> p[i].Amount;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> p[i].T_value;
		p[i].update_A();
	}

	sort(p, p + N, cmp);

	for (int i = 0; i < N; i++)
	{
		if (D > p[i].Amount)
		{
			V_sum += p[i].T_value;
			D -= p[i].Amount;
		}
		else
		{
			V_sum += p[i].A_value * D;
			D = 0;
			break;
		}
	}

	printf("%.2lf\n", V_sum);
	//cout << fixed << setprecision(2) << V_sum << endl;

	return 0;
}