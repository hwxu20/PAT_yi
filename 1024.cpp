#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	string a;
	int sign = 0, exp_sign = 0, move = 0;
	cin >> a;
	if (a[0] == '+') sign = 1;
	else sign = 0;

	int j = 0, len = 0;
	len = a.size();
	for (int i = len - 1; i > len - 7; i--)
	{
		if ((a[i] == '+') || (a[i] == '-'))
		{
			if (a[i] == '+') exp_sign = 1;
			else exp_sign = 0;
			a.erase(i-1, 2);
			break;
		}
		else
		{
			move += (a[i] - '0') * pow(10, j);
			a.erase(i, 1);
			j++;
		}
	}


	if (move != 0)
	{
		a.erase(2, 1);
		if (exp_sign == 0)
		{
			a.insert(1, move, '0');
			a.insert(2, 1, '.');
		}
		else
		{
			if (move < a.size() - 2)
				a.insert(move + 2, 1, '.');
			else if (move > a.size() - 2)
			{
				a.insert(a.size(), move - a.size() + 2, '0');
			}
		}	
	}

	if (sign == 1)
		a.erase(0, 1);
	cout << a << endl;

	return 0;
}

//int main() {
//	string sc, a, b;
//	cin >> sc;
//	if (sc[0] == '-') cout << "-";
//	a = sc.substr(1, sc.find("E") - 1);
//	b = sc.substr(sc.find("E") + 1);
//	int bi = stoi(b);
//	a = a.replace(a.find("."), 1, "");
//	if (bi<0) {
//		cout << "0.";
//		for (int i = 1; i<abs(bi); i++)
//			cout << "0";
//		cout << a;
//	}
//	else if (bi>0) {
//		if (bi<a.length() - 1) {
//			a.insert(bi + 1, ".");
//		}
//		else {
//			for (int i = a.length() - 1; i<bi; i++)
//				a += "0";
//		}
//		cout << a;
//	}
//	else
//		cout << sc.substr(1, sc.find("E") - 1);
//	return 0;
//}