#include <iostream>
#include <istream>
#include <string>
using namespace std;

class Student
{
public:
	Student() {};
	Student(string n, string i, int g) : Name(n), ID(i), Grade(g) {};
	~Student() {};
	string Name;
	string ID;
	int Grade;
};

int main()
{
	int NumStudent = 0;
	cin >> NumStudent;

	string n_temp, id_temp;
	int g_temp;
	Student *studentptr = new Student[NumStudent];
	for (int i = 0; i < NumStudent; i++)
	{
		cin >> n_temp >> id_temp >> g_temp;
		//scanf("%s %s %d",&n_temp,&id_temp,&g_temp);

		studentptr[i].Name = n_temp;
		studentptr[i].ID = id_temp;
		studentptr[i].Grade = g_temp;
	}

	int max_pos = 0, min_pos = 0, temp_max = 0, temp_min = 0;
	temp_max = studentptr[0].Grade;
	temp_min = studentptr[0].Grade;

	for (int i = 1; i < NumStudent; i++)
	{
		if (temp_max < studentptr[i].Grade)
		{
			temp_max = studentptr[i].Grade;
			max_pos = i;
		}
		if (studentptr[i].Grade < temp_min)
		{
			temp_min = studentptr[i].Grade;
			min_pos = i;
		}
	}
	cout << studentptr[max_pos].Name << " " << studentptr[max_pos].ID << endl;
	cout << studentptr[min_pos].Name << " " << studentptr[min_pos].ID << endl;

	return 0;
}