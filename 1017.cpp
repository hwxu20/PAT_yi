#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string A;
	vector<int> Q;
	int B = 0, R = 0, temp = 0, temp_rem = 0, j = 0;

	cin >> A >> B;
	if (A[0] - '0' >= B)
	{
		temp = A[0] - '0';
		Q.push_back(static_cast<int>(temp / B));
		temp_rem = temp % B;
		j++;
	}
	else
		temp_rem = A[0] - '0';

	for (int i = 1; i < A.size(); i++)
	{
		Q.push_back(static_cast<int>((temp_rem * 10 + (A[i]-'0')) / B));
		j++;
		temp_rem = (temp_rem * 10 + (A[i]-'0')) % B;
	}

	R = temp_rem;

	if (j == 0)
		cout << 0;
	else
	{
		for (int i = 0; i < Q.size(); i++)
		{
			cout << Q[i];
		}
	}
	cout << " " << R << endl;

	return 0;
}