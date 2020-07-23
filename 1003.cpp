#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int main()
{
	int N;
	string istr;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> istr;
		//getline(cin,istr,'\n');
		int p_pos = 0, t_pos = 0;
		map<char, int> mapPAT;

		for (int j = 0; j < istr.size(); j++)
		{
			mapPAT[istr[j]]++;
			if (istr[j] == 'P') p_pos = j;
			if (istr[j] == 'T') t_pos = j;
		}

		if (mapPAT['P'] == 1 && mapPAT['T'] == 1 && mapPAT.size() == 3 &&
			(t_pos - p_pos) != 1 && p_pos*(t_pos - p_pos - 1) == (istr.size() - t_pos - 1))
			//cout << "YES" << endl;
			printf("YES\n");
		else
			//cout << "NO" << endl;
			printf("NO\n");
	}

	return 0;
}
