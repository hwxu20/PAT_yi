#include <iostream>
#include <map>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int *a = new int[N];
	for (int i = 0; i < N; i++)
		a[i] = 0;

	int SchoolNO = 0, Grade = 0, max_NO = 0, max_Grade = 0;
	map<int, int> map_Wajueji;

	for (int i = 0; i < N; i++)
	{
		cin >> SchoolNO >> Grade;
		a[SchoolNO] += Grade;
		if (a[SchoolNO] >= max_Grade)
		{
			max_NO = SchoolNO;
			max_Grade = a[SchoolNO];
		}
//		map_Wajueji[SchoolNO] += Grade;
//		if (map_Wajueji[SchoolNO] >= max_Grade)
//		{
//			max_NO = SchoolNO;
//			max_Grade = map_Wajueji[SchoolNO];
//		}
	}

	cout << max_NO << " " << max_Grade << endl;

	delete[] a;
	return 0;
}

