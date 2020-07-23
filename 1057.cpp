#include <iostream>
using namespace std;

int main()
{
	char c = '0';
	int sum = 0, ones = 0, bits_num = 0;
	while (c != '\n')
	{
		c = getchar();
		if (('a' <= c) && (c <= 'z'))
			sum += c - 'a' + 1;
		else if (('A' <= c) && (c <= 'Z'))
			sum += c - 'A' + 1;
	}

	int temp = sum;
	while (temp > 0)
	{
		ones++;
		temp = temp & (temp - 1);
	}

	temp = sum;
	while (temp > 0)
	{
		bits_num++;
		temp = temp >> 1;
	}
		
	printf("%d %d\n", bits_num - ones, ones);

	return 0;
}