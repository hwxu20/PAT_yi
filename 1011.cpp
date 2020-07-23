#include <iostream>
using namespace std;

int main()
{
	int Test_Num;
	cin >> Test_Num;

	long long int *a_ptr = new long long int[Test_Num];
	long long int *b_ptr = new long long int[Test_Num];
	long long int *c_ptr = new long long int[Test_Num];

	for (int i = 0; i < Test_Num; i++)
	{
		cin >> a_ptr[i] >> b_ptr[i] >> c_ptr[i];
	}

	for (int i = 0; i < Test_Num; i++)
	{
		if (a_ptr[i] + b_ptr[i] > c_ptr[i])
			cout << "Case #" << i + 1 << ": true" << endl;
		else
			cout << "Case #" << i + 1 << ": false" << endl;
	}

	//cout << sizeof(int) << endl;
	//cout << sizeof(long int) << endl;
	//cout << sizeof(long long int) << endl;

	return 0;
}