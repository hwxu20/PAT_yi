#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student
{
public:
	string ID;
	int Test_No;
	int Exam_No;
};

bool cmp(Student a, Student b)
{
	return a.Test_No < b.Test_No;
}

int main()
{
	int N;
	cin >> N;

	vector<Student> p;
	Student temp;
	
	for (int i = 0; i < N; i++)
	{
		cin >> temp.ID >> temp.Test_No >> temp.Exam_No;
		p.push_back(temp);
	}

	int M;
	cin >> M;
	int *test = new int[M];
	for (int i = 0; i < M; i++)
		cin >> test[i];

	sort(p.begin(), p.end(), cmp);
	for (int i = 0; i < M; i++)
		printf("%s %d\n", p[test[i] - 1].ID.data(), p[test[i] - 1].Exam_No);

	delete[] test;
	return 0;
}