#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long double R1, P1, R2, P2;
	scanf("%Lf %Lf %Lf %Lf", &R1, &P1, &R2, &P2);

	long double R, P, A, B;
	R = R1*R2;
	P = P1 + P2;

	A = R*cos(P); B = R*sin(P);
	if ((fabs(A) < 0.005) && (A<0)) A = 0.0;
	if ((fabs(B) < 0.005) && (B<0)) B = 0.0;
//	if (fabs(B) < 0.01) B = 0.0;
//	if (B >= 0)
//		printf("%.2Lf+%.2Lfi\n", A, B);
//	else
//	{
//		B = -B;
//		printf("%.2Lf-%.2Lfi\n", A, B);
//	}
	printf("%.2Lf%+.2Lfi\n", A, B);
//	printf("%.2Lf", 0.004);

	return 0;
}