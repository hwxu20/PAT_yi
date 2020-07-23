#include <iostream>
#include <sstream>
using namespace std;

int main() 
{
	int sum = 0, j = 0, a[4];
	string numstr;

	getline(cin,numstr,'\n');
	for (int i = 0; i < numstr.size(); i++)
		sum += (numstr[i] - '0');

	while (sum)
	{
		a[j] = sum % 10;
		sum /= 10;
		j++;
	}
	j--;

	while (j >= 0)
	{
		switch (a[j])
		{
		case 0:
			cout << "ling";
			break;
		case 1:
			cout << "yi";
			break;
		case 2:
			cout << "er";
			break;
		case 3:
			cout << "san";
			break;
		case 4:
			cout << "si";
			break;
		case 5:
			cout << "wu";
			break;
		case 6:
			cout << "liu";
			break;
		case 7:
			cout << "qi";
			break;
		case 8:
			cout << "ba";
			break;
		default:
			cout << "jiu";
		}
		j--;
		if (j >= 0)
			cout << " ";
		else
			cout << endl;
	}
	return 0;
}