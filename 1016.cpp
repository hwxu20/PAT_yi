#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	string A, B, PA_str, PB_str;
	int DA = 0, DB = 0, PA =0, PB = 0;
	char DA_char = '0', DB_char = '0';
	cin >> A >> DA >> B >> DB;
	DA_char += DA;
	DB_char += DB;

	for (unsigned int i = 0; i < A.size(); i++)
	{
		if (A[i] == DA_char)
			PA_str.push_back(DA_char);
	}

	for (unsigned int i = 0; i < B.size(); i++)
	{
		if (B[i] == DB_char)
			PB_str.push_back(DB_char);
	}

	for (unsigned int i = 0; i < PA_str.size(); i++)
	{
		PA += static_cast<int>(DA * pow(10, i));
	}

	for (unsigned int i = 0; i < PB_str.size(); i++)
	{
		PB += static_cast<int>(DB * pow(10, i));
	}

	cout << PA + PB << endl;

	return 0;
}
