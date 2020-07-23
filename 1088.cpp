#include <iostream>
#include <string>
using namespace std;

#define GetMax(a, b) (a > b) ? a : b
#define AbsSub(a, b) ((a > b) ? (a - b) : (b - a))

void Judge(double a, int my)
{
	if (my < a) printf(" Cong");
	else if (my == a) printf(" Ping");
	else printf(" Gai");
}

void Display(double a, double b, double c, int my)
{
	printf("%d", int(a));
	Judge(a, my); Judge(b, my); Judge(c, my);
	printf("\n");
}

int main()
{
	int M, X, Y;
	scanf("%d %d %d", &M, &X, &Y);

	int max_a, max_b;
	double max_c;
	bool flag = false;
	for (int i = 9; i > 0; i--)
		for (int j = 9; j >= 0; j--)
		{
			int a = i * 10 + j;
			int b = j * 10 + i;

			//if ( (abs(a - b) * Y) == (X * b))
			if ((AbsSub(a,b) * Y) == (X * b))
			{
				flag = true;
				max_a = a;
				max_b = b;
				max_c = 1.0 * max_b / Y;
				i = 0;
				break;
			}
		//	printf("%d %d\n", AbsSub(a, b), abs(a - b));
		}

	//for (int i = 99; i >= 10; i--)
	//{
	//	string c = to_string(i);
	//	string d(c.rbegin(), c.rend());
	//	max_a = i;
	//	max_b = stoi(d);
	//	max_c = abs(max_a - max_b) * 1.0 / X;
	//	if (max_b == max_c * Y)
	//	{
	//		flag = true;
	//		break;
	//	}
	//}

	if (flag == false) printf("No Solution\n");
	else
		Display(max_a, max_b, max_c, M);

	return 0;
}