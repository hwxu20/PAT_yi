#include <iostream>
using namespace std;

int Callatz(int num);

int main()
{
	int num_in = 0, count = 0;
	cout << "Please enter a number (1 ~ 1000)" << endl;
	cin >> num_in;

	if (num_in <= 0)
		cout << "The number must be positive!" << endl;
	else
		count = Callatz(num_in);

	cout << count << endl;

	return 0;
}

int Callatz(int num)
{
	int cnt = 0;

	while (num != 1)
	{
		if (num % 2 == 0)
			num /= 2;
		else
			num = (3 * num + 1) / 2;
		cnt++;
	}
		
	return cnt;
}