#include <iostream>
using namespace std;

int main()
{
	int a = 0, temp = 0;
	int decbit[3];
	cin >> a;

	temp = a;
	int bit_cnt = 0;
	while (temp)
	{
		decbit[bit_cnt] = temp % 10;
		temp /= 10;
		bit_cnt++;
	}

	for (int i = bit_cnt-1; i >= 0; i--)
	{
		for (int j = 0; j < decbit[i]; j++)
		{
			if (i == 2)
				cout << "B";
			else if (i == 1)
				cout << "S";
			else
				cout << j + 1;
		}
	}
	cout << endl;

	return 0;
}