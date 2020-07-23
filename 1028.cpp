#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Person
{
public:
	string Name;
	int Birth_yr;
	int Birth_mon;
	int Birth_day;
	Person(string s = "Person", int yr = 0, int mon = 0, int day = 0) : Name(s), Birth_yr(yr), Birth_mon(mon), Birth_day(day) {};

	bool operator==(const Person& p)
	{
		if ((p.Birth_yr == Birth_yr) && (p.Birth_yr == Birth_day) && (p.Birth_day == Birth_day))
			return 1;
		else
			return 0;
	}
};

bool cmp(Person a, Person b)
{
	return (a.Birth_yr != b.Birth_yr) ? (a.Birth_yr > b.Birth_yr) :
		((a.Birth_mon != b.Birth_mon) ? (a.Birth_mon > b.Birth_mon) :
		((a.Birth_day != b.Birth_day) ? (a.Birth_day > b.Birth_day) : 0));
}

int main()
{
	int N;
	cin >> N;

	const Person P200("P200",1814, 9, 6);
	const Person P0("P0", 2014, 9, 6);
	int Valid_Num = 0;

	Person p_temp, oldest, yongest;
	string temp;
	oldest = P0; yongest = P200;

	for (int i = 0; i < N; i++)
	{
		cin >> p_temp.Name;
		cin >> temp;
		p_temp.Birth_yr = stoi(temp.substr(0, 4));
		p_temp.Birth_mon = stoi(temp.substr(5, 2));
		p_temp.Birth_day = stoi(temp.substr(8, 2));

		if ((p_temp.Birth_yr < P200.Birth_yr) ||
			((p_temp.Birth_yr == P200.Birth_yr) && (p_temp.Birth_mon < P200.Birth_mon)) ||
			((p_temp.Birth_yr == P200.Birth_yr) && (p_temp.Birth_mon == P200.Birth_mon) && (p_temp.Birth_day < P200.Birth_day)))
			continue;

		if ((p_temp.Birth_yr > P0.Birth_yr) ||
			((p_temp.Birth_yr == P0.Birth_yr) && (p_temp.Birth_mon > P0.Birth_mon)) ||
			((p_temp.Birth_yr == P0.Birth_yr) && (p_temp.Birth_mon == P0.Birth_mon) && (p_temp.Birth_day > P0.Birth_day)))
			continue;

		Valid_Num++;
		if (cmp(p_temp, yongest) || (p_temp == yongest))
			yongest = p_temp;

		if (cmp(oldest, p_temp) || (p_temp == oldest))
			oldest = p_temp;
	}
	
	if (Valid_Num > 0)
		printf("%d %s %s\n", Valid_Num, oldest.Name.data(), yongest.Name.data());
	else
		printf("%d\n", Valid_Num);

	return 0;
}
