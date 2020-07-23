#include <iostream>
#include <string>
using namespace std;

int main()
{
	string CPW; int N;
	cin >> CPW >> N;
	getchar();

	string input; int cnt = 0;
	while (true)
	{
		getline(cin, input);
		if (input == CPW) { printf("Welcome in\n"); break; }
		else if (input == "#") break;
		else
		{
			cnt++;
			if (cnt < N) printf("Wrong password: %s\n", input.data());
			else 
			{
				printf("Wrong password: %s\n", input.data());
				printf("Account locked\n"); break;
			}
		}
	}

	return 0;
}
