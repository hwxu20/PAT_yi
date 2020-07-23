#include <iostream>
using namespace std;

const int CLK_TCK = 100;

int main()
{
	unsigned int C1, C2, C_diff, T_diff;
	cin >> C1 >> C2;

	C_diff = C2 - C1;

	int Decimal = 0;
	Decimal = C_diff % CLK_TCK;

	if (Decimal >= 50)
		C_diff += (CLK_TCK - Decimal);
	
	T_diff = C_diff / CLK_TCK;

	int hr, minute, sec;
	sec = T_diff % 60;
	T_diff -= sec;
	minute = (T_diff % 3600) / 60;
	T_diff -= minute * 60;
	hr = T_diff / 3600;

	printf("%02d:%02d:%02d\n", hr, minute, sec);

	return 0;
}
