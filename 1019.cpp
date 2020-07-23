#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(char a, char b)
{
	return a > b;
}

int main()
{
	string a;
	cin >> a;
	a.insert(0, 4 - a.size(), '0');

	string temp1, temp2;
	int result;

	do {
		temp1 = a; 
		temp2 = a;
		sort(temp1.begin(), temp1.end());//decrease
		sort(temp2.begin(), temp2.end(),cmp);//increase
		result = stoi(temp2) - stoi(temp1);
		a = to_string(result);
		a.insert(0, 4 - a.size(), '0');

		printf("%04d - %04d = ", stoi(temp2), stoi(temp1));
		printf("%04d\n", result);
	} while ((result != 6174) && (result != 0));

	return 0;
}