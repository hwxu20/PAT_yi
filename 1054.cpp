#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

double stonum(string a)
{
	int size = a.size();
	int dot_num = 0, dot_pos = 0;
	double integer = 0.0, decimal = 0.0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] == '.')
		{
			dot_num++;
			dot_pos = i;
		}
	}
	
	if (dot_num == 1)
	{
		string temp;
		temp = "0" + a.substr(dot_pos, size - dot_pos);
		integer = atof(a.substr(0, dot_pos).data());
		decimal = atof(temp.data());
		if (a[0] == '-') decimal = - decimal;
		return integer + decimal;
	}
	else
	{
		integer = atof(a.data());
		return integer;
	}
		
	return 0;
}

bool Check(string a)
{
	int size = a.size();
	int dot_num = 0, dot_pos = 0;
	for (int i = 0; i < size; i++)
	{
		if (((a[i] < '0') || ('9' < a[i])) && (a[i] != '.') && (a[i] != '-'))
			return false;
		else if (a[i] == '.')
		{
			dot_num++;
			dot_pos = i;
		}
	}

	double value;
	if (dot_num > 1) return false;
	else if (dot_num == 1)
	{
//		if ((size - dot_pos > 3) || (size - dot_pos < 2)) return false;
		if (size - dot_pos > 3) return false; //0.也是合法输入？？
		else
		{
			value = stonum(a);
			if ((fabs(value) - 1000) > 0.001) return false;
		}
	}
	else
	{
		value = stonum(a);
		if ((fabs(value) - 1000) > 0.001) return false;
	}

	return true;
}

int main()
{
	int N;
	scanf("%d", &N);

	string *a = new string[N];
	double sum = 0.0; int valid_num = 0;
	//for (int i = 0; i < N; i++)
	//{
	//	cin >> a[i];
	//	if (Check(a[i]))
	//	{
	//		sum += stonum(a[i]);
	//		valid_num++;
	//	}
	//	else printf("ERROR: %s is not a legal number\n", a[i].data());
	//}

	double temp = 0.0; char b[50];
	int err;
	for (int i = 0; i < N; i++)
	{
		err = 0;
		cin >> a[i];
		sscanf(a[i].data(), "%lf", &temp);
		sprintf(b, "%.2lf", temp);//temp必须初始化，否则格式输入错误时temp没有有效值，会报错
		int len = strlen(a[i].data());
		for (int j = 0; j < len; j++)
		{
			if (a[i][j] != b[j]) err = 1;
		}
		if ((fabs(temp) - 1000 < 0.001) && (err == 0))
		{
			sum += temp; valid_num++;
		}
		else printf("ERROR: %s is not a legal number\n", a[i].data());
	}

	if (valid_num == 1) printf("The average of 1 number is %.2lf\n", valid_num, sum / valid_num);
	else if (valid_num > 1) printf("The average of %d numbers is %.2lf\n", valid_num, sum / valid_num);
	else printf("The average of 0 numbers is Undefined\n");

	delete[] a;
	return 0;
}