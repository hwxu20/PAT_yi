#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	int c = a * b;
	string str = to_string(c);
	string str_r(str.rbegin(), str.rend());
	int d = stoi(str_r);
	cout << d << endl;

	return 0;
}