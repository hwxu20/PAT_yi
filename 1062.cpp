#include <iostream>
using namespace std;


int GCD(int a, int b)
{
	int temp;
	while (b > 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

class Frac_Display
{
public:
	int n;
	void display(int a, int b)
	{
		if (n == 0) printf("%d/%d", a, b);
		else printf(" %d/%d", a, b);
		n++;
	}
	void operator()(int a, int b) { display(a, b); }
	Frac_Display() { n = 0; }
};


int main()
{
	int N1, M1, N2, M2, K;
	scanf("%d/%d %d/%d %d", &N1, &M1, &N2, &M2, &K);
	double MIN = double(N1) / double(M1);
	double MAX = double(N2) / double(M2);
	double tmp;
	if (MIN > MAX) 
	{
		tmp = MAX; MAX = MIN; MIN = tmp;
	}

	Frac_Display dis;
	for (int i = 1; i < K; i++)
	{
		if (GCD(K, i) == 1)
		{
			double tmp = double(i) / double(K);
			if ((MIN < tmp) && (tmp < MAX))
				dis.display(i, K);
			else if (MAX <= tmp)
				break;
		}
	}
	printf("\n");

	return 0;
}
