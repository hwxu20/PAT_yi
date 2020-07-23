#include <iostream>
#include <string>
using namespace std;

#define GetMax(a, b) a > b ? a : b

int main()
{
	string PAT, num1, num2;
	cin >> PAT;
	string RPAT(PAT.rbegin(), PAT.rend());
	int N = PAT.size();

	cin >> num1;
	cin >> num2;

	int n1 = num1.size();
	int n2 = num2.size();
	int nmax = GetMax(n1, n2);
	string result;
	string rnum1(num1.rbegin(), num1.rend());
	string rnum2(num2.rbegin(), num2.rend());

	int a = 0, b = 0, c = 0, m = 0;//m进制
	int up = 0, rem = 0; 
	for (int i = 0; i < nmax; i++)
	{//c = a + b 进位up，留下rem
		m = RPAT[i] - '0'; if (m == 0) m = 10;
		if (i > n1 - 1) a = 0;
		else a = rnum1[i] - '0';
		if (i > n2 - 1) b = 0;
		else b = rnum2[i] - '0';

		c = a + b + up;
		rem = c % m; up = c / m;
		result.push_back(rem + '0');
	}
	int i = nmax;
	while (up > 0)
	{
		if (i > N - 1) m = 10;
		else m = RPAT[i] - '0'; if (m == 0) m = 10;
		c = up; rem = c % m; up = c / m;
		result.push_back(rem + '0');
	}
	string out(result.rbegin(), result.rend());
//	cout << stoi(out.data()) << endl; //用stoi函数测试点3、4会runtime error，这是因为超过了int的限制
	int flag = 0;
	for (int i = 0; i < out.size(); i++)
	{
		if (out[i] != '0') flag = 1;
		if (flag == 1) printf("%c", out[i]);
	}

	if (flag == 0) printf("%d\n", 0);

	return 0;
}