#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main()
{
	unsigned int A, B, D, Sum, temp;
	int a[33];
	int cnt = 0;
	cin >> A >> B >> D;

	Sum = A + B;
	if (D == 10)
		cout << Sum << endl;
	else if (Sum == 0)
	{
		cout << 0 << endl;
	}
	else 
	{
		temp = Sum;
		while (temp != 0)
		{
			a[cnt] = temp % D;
			temp /= D;
			cnt++;
		}

		for (int i = 0; i < cnt; i++)
		{
			cout << a[cnt - i - 1];
		}
		cout << endl;
	}
	return 0;
}