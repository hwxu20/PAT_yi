#include <iostream>
#include <string>
using namespace std;

#define MINLEN 6

void PW_Check(string a)
{
	if (a.size() < MINLEN)
	{
		printf("Your password is tai duan le.\n");
		return;
	}

	bool digit_flag = false, alpha_flag = false;
	for (int i = 0; i < a.size(); i++)
	{
		if (isdigit(a[i]))
		{
			digit_flag = true;
			continue;
		}
		else if (isalpha(a[i]))
		{
			alpha_flag = true;
			continue;
		}
		else if (a[i] == '.')
			continue;
		else
		{
			printf("Your password is tai luan le.\n");
			return;
		}
	}
	if (digit_flag == false)
		printf("Your password needs shu zi.\n");
	else if (alpha_flag == false)
		printf("Your password needs zi mu.\n");
	else
		printf("Your password is wan mei.\n");
}

int main()
{
	int N;
	scanf("%d", &N); getchar();

	string pw;
	for (int i = 0; i < N; i++)
	{
		getline(cin, pw);
		PW_Check(pw);
	}

	return 0;
}