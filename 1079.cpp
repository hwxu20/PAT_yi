#include <iostream>
#include <string>
using namespace std;

#define MAXITER 10


string BigAdd(string& A, string& B)
{
	int N = A.size();
	int up = 0, rem = 0;
	string C;
	for (int i = 0; i < N; i++)
	{
		rem = A[i] + B[i] + up - 2*'0';
		if (rem > 9) { up = 1; rem -= 10; }
		else { up = 0; }
		char c = rem + '0';
		C = c + C;
	}
	if (up == 1) C = '1' + C;
	return C;
}

bool IsPalin(string& A)
{
	bool flag = true;
	int n = A.size() / 2;
	int k = A.size() - 1;
	for (int i = 0; i < n; i++)
	{
		if (A[i] != A[k - i])
		{ flag = false; break; }
	}
	return flag;
}

bool PalinIter(string& A)
{
	string B = string(A.rbegin(), A.rend());
	string result = BigAdd(A, B);
	cout << A << " + " << B << " = " << result << endl;
	A = result;
	return (IsPalin(result));
}

int main()
{
	string str;
	cin >> str;
	if (IsPalin(str))
	{
		printf("%s is a palindromic number.\n", str.data());
		return 0;
	}

	int cnt = 0;
	for (int i = 0; i < MAXITER; i++)
	{
		if (PalinIter(str)) { cnt++; break; }
		else cnt++;
	}
	
	if (cnt < MAXITER) printf("%s is a palindromic number.\n", str.data());
	else printf("Not found in 10 iterations.\n");

	return 0;
}