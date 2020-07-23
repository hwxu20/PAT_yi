#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int Num = 0;
	cin >> Num;

	int *p = new int[Num];
	
	for (int i = 0; i < Num; i++)
		cin >> p[i];
	
	map<int, int> mapCallatz;

	for (int i = 0; i < Num; i++)
	{
		mapCallatz[p[i]]++;
		int temp = p[i];

		while (temp!=1)
		{
			if (temp % 2 == 0)
			{
				temp /= 2;
				mapCallatz[temp]++;
			}
			else
			{
				temp = (3 * temp + 1) / 2;
				mapCallatz[temp]++;
			}
		}
	}

	int *q = new int[Num];
	int j = 0;
	for (int i = 0; i < Num; i++)
	{
		if (mapCallatz[p[i]] == 1)
		{
			q[j] = p[i];
			j++;
		}
	}

	if (j > 0)
		sort(q, q + j);
	
	while (j)
	{
		cout << q[j-1];
		if (j != 1)
			cout << " ";
		j--;
	}
	cout << endl;

	return 0;
}

