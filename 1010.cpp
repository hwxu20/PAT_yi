#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, int> polynominal;
	map<int, int> dpolynominal;

	int a = 0, n = 0;
	
	do {
		cin >> a >> n;
		polynominal[n] = a;
		if (n!=0)
			dpolynominal[n-1] = n * a;
	} while (cin.get() != '\n');
	
	map<int, int>::reverse_iterator dpoly_riter;
	map<int, int>::iterator poly_iter;
	poly_iter = polynominal.begin();
	dpoly_riter = dpolynominal.rbegin();

	if ((polynominal.size() == 1) && (poly_iter->first == 0))
		cout << 0 << " " << 0 << endl;
	else
	{
		for (dpoly_riter = dpolynominal.rbegin(); dpoly_riter != dpolynominal.rend(); dpoly_riter++)
		{
			if (dpoly_riter == dpolynominal.rbegin())
				cout << dpoly_riter->second << " " << dpoly_riter->first;
			else
				cout << " " << dpoly_riter->second << " " << dpoly_riter->first;
		}
		cout << endl;
	}

	return 0;
}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int a, b;
//	int x = 1;
//	while (cin >> a >> b)//ÊäÈë 
//	{
//		if (b == 0)
//			break;//ÉáÆú 
//		if (!x)
//			cout << " ";
//		else
//			x = 0;
//		cout << a*b << " " << b - 1;
//	}
//	if (x)
//		cout << "0 0";
//	return 0;
//}