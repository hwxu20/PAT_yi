#include <iostream>
#include <string>
using namespace std;

string Waiguan(string& a)
{
	string b, rep;
	char c_cur, c_pre = '#';
	int cnt_rep = 0;
	for (int i = 0; i < a.size(); i++)
	{
		c_cur = a[i];
		if ((c_cur != c_pre) && (c_pre != '#'))
		{
			b.push_back(c_pre);
			rep = to_string(cnt_rep + 1);
			for (int j = 0; j < rep.size(); j++)
				b.push_back(rep[j]);
			//b = b + to_string(cnt_rep + 1);
			cnt_rep = 0;
		}
		else if (c_pre != '#') cnt_rep++;
		c_pre = c_cur;
	}
	return b;
}

int main()
{
	string d; int N;
	cin >> d >> N;

	for (int i = 0; i < N - 1; i++)
	{
		d.push_back('#');
		d = Waiguan(d);
	}

	cout << d << endl;

	return 0;
}