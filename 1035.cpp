#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void display(int *a, int N)
{
	printf("%d", a[0]);
	for (int i = 1; i < N; i++)
		printf(" %d", a[i]);
	printf("\n");
}

//one-step insertion sort [lo,hi)+[hi]
void Insertion_Sort(int *a, int lo, int hi)
{
	int j = 0, temp = 0;
	temp = a[hi];
	for (j = hi - 1; j >= 0 && a[j] > temp; j--)
		a[j + 1] = a[j];
	a[j + 1] = temp;
	return;
}

//merge [lo,mi) [mi,hi)
void merge(int *a, int lo, int mi, int hi)
{
	int *A = a + lo;
	int lb = mi - lo, lc = hi - mi;
	int *B = new int[lb];
	for (int i = 0; i < lb; i++) { B[i] = A[i]; }
	int *C = a + mi;

	int i = 0, j = 0, k = 0;
	while ((j < lb) || (k < lc))
	{
 		if (!(j < lb)) break;
		if ((j < lb) && (!(k < lc) || (B[j] < C[k])))
		{
			A[i++] = B[j++]; continue;
		}
		if (C[k] < B[j]) A[i++] = C[k++];
	}

	delete[] B;
}

//one-step merge sort [lo lo+k+1) [lo+k+1, lo+2k+2)
void Merge_Sort(int *a, int lo, int hi, int k)// kth merge
{
	int i = 0, g_size = static_cast<int>(pow(2, k - 1));
	int lo_i = lo + i;
	int mi_i = lo_i + g_size;
	int hi_i = mi_i + g_size;

	//Self-made MergeSort
	//while (hi_i <= hi)
	//{
	//	merge(a, lo_i, mi_i, hi_i);
	//	i += 2*g_size;
	//	lo_i = lo + i;
	//	mi_i = lo_i + g_size;
	//	hi_i = mi_i + g_size;
	//}
	//if ((hi_i > hi) && (mi_i < hi)) merge(a, lo_i, mi_i, hi);

	//Using std::sort function
	while (lo_i < hi)
	{
		sort(a + lo_i, a + min(hi_i, hi));
		i += 2 * g_size;
		lo_i = lo + i;
		hi_i = lo_i + 2*g_size;
	}

//	display(a, hi - lo);

	return;
}

bool isEqual(int *a, int *b, int N)
{
	for (int i = 0; i < N; i++)
	{
		if (a[i] != b[i]) break;
		if ((i == N - 1) && (a[i] == b[i])) return 1;
	}
	return 0;
}

int main()
{
	int N;
	cin >> N;

	int *ori_seq = new int[N];
	int *mid_seq = new int[N];
	for (int i = 0; i < N; i++) cin >> ori_seq[i];
	for (int i = 0; i < N; i++) cin >> mid_seq[i];

	int *temp_seq = new int[N];
	for (int i = 0; i < N; i++) temp_seq[i] = ori_seq[i];

	if (N > 1) 
	{
		int eq_flag = 0;
		for (int i = 1; i < N; i++)
		{
			sort(temp_seq, temp_seq + i + 1);//[lo, hi)
			//Insertion_Sort(temp_seq, 0, i); //[lo,hi]
			eq_flag = isEqual(temp_seq, mid_seq, N);
			if (eq_flag)
			{
				printf("Insertion Sort\n");
				Insertion_Sort(temp_seq, 0, i + 1);
				display(temp_seq, N);
				break;
			}
		}

		if (eq_flag == 0)
		{
			for (int i = 0; i < N; i++) temp_seq[i] = ori_seq[i];
			int temp = N, m_step = 1;
			while (temp > 0)
			{
				Merge_Sort(temp_seq, 0, N, m_step);
				m_step++;
				temp = temp >> 1;
				if (isEqual(temp_seq, mid_seq, N))
				{
					printf("Merge Sort\n");
					Merge_Sort(temp_seq, 0, N, m_step);
					display(temp_seq, N);
					break;
				}
			}
		}
	}

	delete[] temp_seq;
	delete[] ori_seq;
	delete[] mid_seq;
	return 0;
}

//
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int n;
//void insort(int a[], int b[]) {
//	int key = 0;          //当匹配到中间序列时，key置1，下次排序后输出，结束程序就行
//	for (int i = 2; i <= n; i++) {		//插入排序起始为2，结束为n，否则测试点2不通过
//		sort(a, a + i);
//		if (key) {
//			cout << "Insertion Sort" << endl;
//			cout << a[0];
//			for (int j = 1; j < n; j++)
//				cout << " " << a[j];
//			return;
//		}
//		if (equal(a, a + n, b))  //equal是一个比较数组的函数,测试是否在两个范围的元素都是平等的
//			key = 1;
//	}//3个参数first1,last1和first2.如果对于区间[first1,last1)内所有的first1+i,first1+i和first2所在位置处的元素都相等，则equal算法返回真，否则返回假。
//}
//void mesort(int a[], int b[]) {
//	int key = 0;
//	for (int i = 2;; i *= 2) {   //这里不给结束条件，是因为当i>n时还要进行一次排序
//		for (int j = 0; j < n; j += i) {
//			sort(a + j, a + (j + i < n ? j + i : n));  //注意确定边界
//		}
//		if (key) {
//			cout << "Merge Sort" << endl;
//			cout << a[0];
//			for (int j = 1; j < n; j++)
//				cout << " " << a[j];
//			return;
//		}
//		if (equal(a, a + n, b))
//			key = 1;
//		if (i > n)
//			break;
//	}
//}
//int main() {
//	cin >> n;
//	int a1[100], a2[100], b[100];
//	for (int i = 0; i < n; i++) {
//		cin >> a1[i];//输入原始序列 
//		a2[i] = a1[i];
//	}
//	for (int i = 0; i < n; i++)
//		cin >> b[i];//输入中间数列 
//	insort(a2, b);//表示插入排序
//	mesort(a1, b);//表示归并排序
//	return 0;
//}