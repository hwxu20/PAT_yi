#include <iostream>
#include <string>
using namespace std;

void Compress(string& A, string& B)
{
	char c, c_pre;
	int n_rep = 0;
	c_pre = A[0];
	for (int i = 1; i < A.size(); i++)
	{
		c = A[i];
		if (c != c_pre)
		{
			if (n_rep)
			{
				B = B + to_string(n_rep + 1);
				B.push_back(c_pre);
				n_rep = 0;
			}
			else B.push_back(c_pre);
		}
		else n_rep++;
		c_pre = c;
	}
}

void Decompress(string& A, string& B)
{
	int digit_cnt = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (!isdigit(A[i]))
		{
			if (!digit_cnt) B.push_back(A[i]);
			else 
			{
				for (int j = 0; j < digit_cnt; j++)
					B.push_back(A[i]);
				digit_cnt = 0;
			}
		}
		else
		{
			digit_cnt = digit_cnt*10;
			digit_cnt += A[i] - '0';
		}
	}
}

int main()
{
	char ch;
	scanf("%c", &ch); getchar();

	string str, result;
	getline(cin, str);
	str.push_back('\n');

	if (ch == 'C') Compress(str, result);
	else Decompress(str, result);

	cout << result;

	return 0;
}