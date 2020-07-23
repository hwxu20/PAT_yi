#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int N;
	scanf("%d", &N);

	int *d = new int[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &d[i]);
	
	sort(d, d + N, cmp);
	int E = 0, i = 0;
	for (i = 0; i < N; i++)
		if (d[i] <= i + 1) break;
	E = i;

	printf("%d\n", E);
	delete[] d;
	return 0;
}


//#include <iostream>
//#include <algorithm>
//using namespace std;
//int a[1000000];
//bool cmp1(int a, int b) {
//	return a > b;
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
//	sort(a + 1, a + n + 1, cmp1);
//	int ans = 0, p = 1;
//	while (ans <= n && a[p] > p) {
//		ans++;
//		p++;
//	}
//	printf("%d", ans);
//	return 0;
//}