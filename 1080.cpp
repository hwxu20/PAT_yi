#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

#define GPMIN 200
#define GMIN 60

struct Student
{
	string ID;
	int Gp; int Gmid; int Gfin; int G;
	bool pass;
	Student(string id = "", int gp = -1, int gmid = -1, int gfin = -1, int g = -1): 
		ID(id), Gp(gp), Gmid(gmid), Gfin(gfin), G(g) { pass = false; }
	void update();
};

void Student::update()
{
	if ((Gp < GPMIN) || (Gfin == -1)) { G = -1; pass = false; return; }
	if (Gfin < Gmid)
		G = round(0.4 * Gmid + 0.6 * Gfin);
	else G = Gfin;
	pass = (60 <= G ? true : false);
}

bool cmp(Student a, Student b)
{
	return a.G != b.G ? a.G > b.G : a.ID < b.ID;
}

int main()
{
	int P, M, N;
	scanf("%d %d %d", &P, &M, &N);
	map<string, Student> s;
	string id; int tmp;
	for (int i = 0; i < P; i++)
	{
		cin >> id >> tmp;
		if (GPMIN <= tmp)
		{
			Student p(id, tmp);
			s.insert(pair<string, Student>(id, p));
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> id >> tmp;
		if (s.find(id) != s.end())
			s[id].Gmid = tmp;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> id >> tmp;
		if (s.find(id) != s.end())
			s[id].Gfin = tmp;
	}
	
	map<string, Student>::iterator iter;
	int pass_cnt = 0;
	vector<Student> s_pass;
	for (iter = s.begin(); iter != s.end(); iter++)
	{
		iter->second.update();
		if (iter->second.pass) s_pass.push_back(iter->second);
	}

	sort(s_pass.begin(), s_pass.end(), cmp);
	for (int i = 0; i < s_pass.size(); i++)
	{
		printf("%s %d %d %d %d\n", s_pass[i].ID.data(), s_pass[i].Gp, \
			s_pass[i].Gmid, s_pass[i].Gfin, s_pass[i].G);
	}

	return 0;
}
