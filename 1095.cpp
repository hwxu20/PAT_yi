#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct Student
{
	string ID;
	int Grade;
	Student(string id, int g) : ID(id), Grade(g) {}
};

struct TestLocation
{
	int ID;
	int Num;
	TestLocation(int id, int n) : ID(id), Num(n) {}
};

bool cmp1(Student a, Student b)
{
	return (a.Grade != b.Grade) ? (a.Grade > b.Grade) : (a.ID < b.ID);
}

void func1(map<string, int> &S, char le)
{
	map<string, int>::iterator iter = S.begin();
	vector<Student> V;
	while (iter != S.end())
	{
		if (iter->first[0] == le)
			V.push_back(Student(iter->first, iter->second));
		iter++;
	}
	if (V.size() == 0)
	{
		printf("NA\n");
		return;
	}
	sort(V.begin(), V.end(), cmp1);
	for (int i = 0; i < V.size(); i++)
		//cout << V[i].ID << " " << V[i].Grade << endl;
		printf("%s %d\n", V[i].ID.data(), V[i].Grade);
}

void func2(map<string, int> &S, int loc)
{
	map<string, int>::iterator iter = S.begin();
	int num = 0, sum = 0;
	while (iter != S.end())
	{
		int tmp = stoi(iter->first.substr(1, 3));
		if (tmp == loc)
		{
			num++;
			sum += iter->second;
		}
		iter++;
	}
	if (num == 0)
	{
		printf("NA\n");
		return;
	}
	printf("%d %d\n", num, sum);
}

bool cmp3(TestLocation a, TestLocation b)
{
	return (a.Num != b.Num) ? (a.Num > b.Num) : (a.ID < b.ID);
}

void func3(map<string, int> &S, string d)
{
	map<string, int>::iterator iter = S.begin();
	map<int, int> L;
	vector<TestLocation> T;
	while (iter != S.end())
	{
		if (d == iter->first.substr(4, 6))
		{
			int loc = stoi(iter->first.substr(1, 3));
			L[loc]++;
		}
		iter++;
	}
	if (L.size() == 0)
	{
		printf("NA\n");
		return;
	}
	map<int, int>::iterator iter1 = L.begin();
	while (iter1 != L.end())
	{
		T.push_back(TestLocation(iter1->first, iter1->second));
		iter1++;
	}
	sort(T.begin(), T.end(), cmp3);
	for (int i = 0; i < T.size(); i++)
		printf("%d %d\n", T[i].ID, T[i].Num);
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	map<string, int> Students;
	for (int i = 0; i < N; i++)
	{
		string s; int g;
		cin >> s >> g;
		Students.insert(pair<string, int>(s, g));
	}

	for (int i = 0; i < M; i++)
	{
		int cmd; string date;
		scanf("%d", &cmd);
		printf("Case %d: ", i + 1);
		switch (cmd)
		{
		case 1 :
			char Level;
			cin >> Level;
			printf("1 %c\n", Level);
			func1(Students, Level);
			break;
		case 2:
			int location;
			cin >> location;
			printf("2 %d\n", location);
			func2(Students, location);
			break;
		case 3:
			cin >> date;
			printf("3 %s\n", date.data());
			func3(Students, date);
			break;
		default:
			break;
		}
	}

	return 0;
}