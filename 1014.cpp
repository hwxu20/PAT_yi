#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> weekday = {"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main()
{
	string a1, a2, b1, b2;
	int len_a = 0, len_b = 0, cnt = 0, minute = 0;
	char day = '0', hr = '0';
	cin >> a1 >> a2 >> b1 >> b2;
	//getline(cin, a1);
	//getline(cin, a2);
	//getline(cin, b1);
	//getline(cin, b2);

	len_a = min(a1.size(), a2.size());
	len_b = min(b1.size(), b2.size());

	for (int i = 0; i < len_a; i++)
	{
		if ((a1[i] == a2[i]) && ('A'<= a1[i]) && (a1[i] <= 'G') && (cnt == 0))
		{
			day = a1[i] - 'A';
			cnt++;
			continue;
		}
		else if ((a1[i] == a2[i]) && (cnt == 1))
		{
			if (isdigit(a1[i]) || (('A' <= a1[i]) && (a1[i] <= 'N')))
			{
				hr = a1[i];
				break;
			}
		}
	}


	for (int i = 0; i < len_b; i++)
	{
		if ((b1[i] == b2[i]) && isalpha(b1[i]))
		{
			minute = i;
			break;
		}
	}

	cout << weekday[day] << " ";

	if (isdigit(hr))
		cout << 0 << hr - '0' << ":";
	else
		cout << hr - 'A' + 10 << ":";

	if (minute < 10)
		cout << 0 << minute << endl;
	else
		cout << minute << endl;


	return 0;
}