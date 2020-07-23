#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a = 0, N = 0, rem = 0;
	int sum1 = 0, sum2 = 0, N2 = 0, N3 = 0, sum4 = 0, N4 = 0, max5 = 0;
	double avg4 = 0.0;
	int sign3 = 1;

	cin >> N;
	do {
		cin >> a;
		rem = a % 5;
		switch (rem)
		{
		case 0:
			if (a % 2 == 0)
				sum1 += a;
			break;
		case 1:
			if (sign3 == 1)
			{
				sum2 += a;
				sign3 = 0;
				N2++;
			}
			else
			{
				sum2 -= a;
				sign3 = 1;
				N2++;
			}
			break;
		case 2:
			N3++;
			break;
		case 3:
			sum4 += a;
			N4++;
			break;
		case 4:
			if (a > max5)
				max5 = a;
			break;
		default:
			cout << "Error occurred!" << endl;
		}
	} while (cin.get() != '\n');

	if (sum1 == 0)
		cout << "N" << " ";
	else
		cout << sum1 << " ";

	if (N2 == 0)
		cout << "N" << " ";
	else
		cout << sum2 << " ";

	if (N3 == 0)
		cout << "N" << " ";
	else
		cout << N3 << " ";

	if (N4 == 0)
		cout << "N" << " ";
	else
	{
		cout << fixed << setprecision(1) << static_cast<double>(sum4) / N4 << " ";
	}

	cout.unsetf(ios::fixed);
	if (max5 == 0)
		cout << "N" << endl;
	else
		cout << max5 << endl;

	return 0;
}
