#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

const int ID_NUM = 18;
const int ID_WEIGTH[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
const char ZtoM[11] = {'1','0','X','9','8','7','6','5','4','3','2'};

bool ID_Check(const string str)
{
	char *c = new char[ID_NUM + 1];
	int sum = 0, Z = 0;
	strcpy(c, str.c_str());
	for (int i = 0; i < ID_NUM - 1; i++)
		sum += (c[i] - '0') * ID_WEIGTH[i];
	Z = sum % 11;

	char M = '0';
	M = ZtoM[Z];

	if (M == c[17]) return 1;
	else return 0;
}

int main()
{
	int N = 0, wr_Num = 0;
	cin >> N;

	string *str = new string[N];
	int *wr_list = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
		if (ID_Check(str[i]) != 1)
		{
			wr_list[wr_Num] = i;
			wr_Num++;
		}
	}

	if (wr_Num == 0) cout << "All passed" << endl;
	else
	{
		for (int i = 0; i < wr_Num; i++)
			cout << str[wr_list[i]] << endl;
	}

	return 0;
}

//#include <iostream>
//#include <string>
//#define MAXSIZE 100 
//using namespace std;
//int main(int argc, char** argv) {
//	char jiaoyan[11] = { '1','0','X','9','8','7','6','5','4','3','2' };
//	int quanzhong[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
//	string idCard[MAXSIZE];
//	int N, allPass = 1;
//	cin >> N;
//	for (int i = 0; i<N; i++)
//	{
//		cin >> idCard[i];
//		int sum = 0;
//		string str = idCard[i];
//		int j;
//		for (j = 0; j<17; j++)
//		{
//			if (str[j]<'0' || str[j]>'9')
//				break;
//			sum += (str[j] - '0')*quanzhong[j];
//		}
//		int z = sum % 11;
//		if (j != 17 || str[17] != (jiaoyan[z]))
//		{
//			allPass = 0;
//			cout << idCard[i] << endl;
//		}
//
//	}
//	if (allPass)
//		cout << "All passed" << endl;
//
//
//	return 0;
//}