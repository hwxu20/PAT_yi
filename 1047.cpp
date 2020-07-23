#include <iostream>
#include <map>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	map<int, int> Group;
	int group, member, grade;
	int max_group, max_grade = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d-%d %d", &group, &member, &grade);
		Group[group] += grade;
		if (Group[group] > max_grade)
		{
			max_grade = Group[group];
			max_group = group;
		}
	}
	
	printf("%d %d", max_group, max_grade);

	return 0;
}