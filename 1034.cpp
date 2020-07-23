#include <iostream>
#include <string>
using namespace std;

long long int GCD(long long int a, long long int b)
{
	long long int c;
	a = abs(a);
	while (1)
	{
		c = a % b;
		if (c == 0) return b;
		else {a = b; b = c;}
	}
}

string simplify(long long int a, long long int b)
{
	if (b < 0) { a = -a; b = -b; }
	long long int k;
	k = a / b;
	a = a - k*b;
	long long int divider = GCD(a, b);
	a /= divider; b /= divider;

	string result;
	if ((k == 0) && (a == 0)) result = to_string(0);
	else if (k == 0) result = to_string(a) + '/' + to_string(b);
	else if (a == 0) result = to_string(k);
	else result = to_string(k) + " " + to_string(abs(a)) + '/' + to_string(b);

	return result;
}

void display(string a)
{
	int sign = a[0] - '-';
	if (sign == 0) cout << "(" << a << ")";
	else cout << a;
}

int main()
{
	string a, b;
	cin >> a >> b;

	long long int a1, a2, b1, b2;
	size_t len_a = a.find('/');
	size_t len_b = b.find('/');

	a1 = stoi(a.substr(0, len_a)); a2 = stoi(a.substr(len_a + 1));
	b1 = stoi(b.substr(0, len_b)); b2 = stoi(b.substr(len_b + 1));

	//ADD
	long long int m, n;
	m = a1*b2 + b1*a2;
	n = a2*b2;

	display(simplify(a1, a2)); cout << " + "; 
	display(simplify(b1, b2)); cout << " = ";
	display(simplify(m, n)); cout << endl;

	//SUB
	m = a1*b2 - b1*a2;
	n = a2*b2;

	display(simplify(a1, a2)); cout << " - ";
	display(simplify(b1, b2)); cout << " = ";
	display(simplify(m, n)); cout << endl;

	//MUL
	m = a1*b1;
	n = a2*b2;

	display(simplify(a1, a2)); cout << " * ";
	display(simplify(b1, b2)); cout << " = ";
	display(simplify(m, n)); cout << endl;

	//DIV
	m = a1*b2;
	n = a2*b1;

	display(simplify(a1, a2)); cout << " / ";
	display(simplify(b1, b2)); cout << " = ";
	if (n == 0) cout << "Inf" << endl;
	else display(simplify(m, n));

	return 0;
}