#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student
{
public:
	int ID;
	int DF;
	int CF;
	int ZF;
};

int cmp(Student a, Student b)
{
	return (a.ZF != b.ZF) ? (a.ZF > b.ZF) : 
		  ((a.DF != b.DF) ? (a.DF > b.DF) : (a.ID < b.ID) );
}

int main()
{
	int N = 0, L = 0, H = 0, M = 0;
	cin >> N >> L >> H;

	Student temp = {0,0,0,0};
	vector<Student> St_vec[4];
	for (int i = 0; i < N; i++)
	{
		cin >> temp.ID >> temp.DF >> temp.CF;
		temp.ZF = temp.DF + temp.CF;

		if ((L <= temp.DF) && (L <= temp.CF))
		{
			if ((H <= temp.DF) && (H <= temp.CF))
				St_vec[0].push_back(temp);
			else if (H <= temp.DF)
				St_vec[1].push_back(temp);
			else if (temp.CF <= temp.DF)
				St_vec[2].push_back(temp);
			else
				St_vec[3].push_back(temp);
			M++;
		}
	}

	printf("%d\n", M);
	//cout << M << '\n';
	for (int i = 0; i < 4; i++)
	{
		sort(St_vec[i].begin(), St_vec[i].end(), cmp);
		for (int j = 0; j < St_vec[i].size(); j++)
		{
			printf("%d %d %d\n", St_vec[i][j].ID, St_vec[i][j].DF, St_vec[i][j].CF);
			//cout << St_vec[i][j].ID << " "
			//	<< St_vec[i][j].DF << " "
			//	<< St_vec[i][j].CF << '\n';
		}
	}
	return 0;
}