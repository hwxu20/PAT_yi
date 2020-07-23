#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct University
{
	string ID;
	int NumStu;
	int YiG; int JiaG; int DingG; int WTG;
	University(string id = "", int n = 0, int y = 0, int j = 0, int d = 0, int w = 0): \
		ID(id), NumStu(n), YiG(y), JiaG(j), DingG(d), WTG(w) {}
	void update(string s, int gs);
	void updateWTG();
};

//struct University
//{
//	string ID;
//	int NumStu;
//	double WTG;
//	University(string id = "", int n = 0, int w = 0) : \
//		ID(id), NumStu(n), WTG(w) {}
//	void update(string s, int gs);
////	void updateWTG();
//};

//void University::update(string s, int gs)
//{
//	char ch = s[0];
//	switch (ch)
//	{
//		case 'B':
//			WTG += gs / 1.5; break;
//		case 'A':
//			WTG += gs; break;
//		case 'T':
//			WTG += gs*1.5; break;
//		default:
//			break;
//	}
//}

void University::update(string s, int gs)
{
	char ch = s[0];
	switch (ch)
	{
		case 'B':
			YiG += gs; break;
		case 'A':
			JiaG += gs; break;
		case 'T':
			DingG += gs; break;
		default:
			break;
	}
}

void University::updateWTG()
{
	double w;
	w = YiG / 1.5 + JiaG + DingG*1.5;
	WTG = int(w);
}

bool cmp_u(University a, University b)
{
	return a.WTG != b.WTG ? a.WTG > b.WTG : \
		(a.NumStu != b.NumStu ? a.NumStu < b.NumStu : (a.ID < b.ID));
}

void stolower(string& a)
{
	for (int i = 0; i < a.size(); i++)
		a[i] = tolower(a[i]);
}

int main()
{
	int N;
	scanf("%d", &N);

	map<string, University> U;
	string s_id, u_id; int g;
	for (int i = 0; i < N; i++)
	{
		cin >> s_id >> g >> u_id;
		stolower(u_id);
		if (U.find(u_id) == U.end())
			U.insert(pair<string, University>(u_id, University(u_id)));
		U[u_id].NumStu++;
		U[u_id].update(s_id, g);
	}

	vector<University> U_vec;
	map<string, University>::iterator iter;
	for (iter = U.begin(); iter != U.end(); iter++)
	{
		iter->second.updateWTG();
		U_vec.push_back(iter->second);
	}

	printf("%d\n", U_vec.size());
	sort(U_vec.begin(), U_vec.end(), cmp_u);
	int rank = 0, wpre = -1;
	for (int i = 0; i < U_vec.size(); i++)
	{
		if (U_vec[i].WTG != wpre) rank = i + 1;
		printf("%d %s %d %d\n", rank, U_vec[i].ID.data(), U_vec[i].WTG, U_vec[i].NumStu);
		wpre =U_vec[i].WTG;
	}

	return 0;
}