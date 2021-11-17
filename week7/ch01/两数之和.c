//想法先用一个插入排序对乱序数组进行排序(平均时间复杂度为O(nlogn)
//然后从排好序的数组的中间位置向两边进行操作，时间复杂度为O(n）
//当n>2时，该算法的时间复杂度小于O(n^2)
#include <stdio.h>
#define Cutoff (3)
typedef int ElementType;
//函数声明
void  Quicksort(ElementType A[], int N);
ElementType Median3(ElementType A[], int left, int right);
void Qsort(ElementType A[], int left, int right);
void InsertionSort(ElementType A[], int N);
void swap(int* a, int* b);
void FindP(ElementType A[], int N, int sum);
//快速排序的驱动程序
void  Quicksort(ElementType A[], int N)
{
	Qsort(A, 0, N - 1);
}
//实现三数中指分割方法的程序
ElementType Median3(ElementType A[], int left, int right)
{
	int center = (left + right) / 2;
	if (A[left] > A[center])
		swap(&A[left], &A[center]);
	if (A[left] > A[right])
		swap(&A[left], &A[right]);
	if (A[center] > A[right])
		swap(&A[center], &A[right]);
	swap(&A[center], &A[right - 1]);
	return A[right - 1];
}
//快速排序
void Qsort(ElementType A[], int left, int right)
{
	int i, j;
	ElementType Pivot;
	if (left + Cutoff <= right)
	{
		Pivot = Median3(A, left, right);
		i = left; j = right - 1;
		for (;;)
		{
			while (A[++i] < Pivot) {}
			while (A[--j] > Pivot) {}
			if (i < j)
				swap(&A[i], &A[j]);
			else
				break;
		}
		swap(&A[i], &A[right - 1]);
		Qsort(A, left, i - 1);
		Qsort(A, i + 1, right);
	}
	else
		InsertionSort(A + left, right-left + 1);
}
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
//插入排序
void InsertionSort(ElementType A[], int N)
{
	int j, P;
	ElementType tmp;
	for (P = 1; P < N; P++)
	{
		tmp = A[P];
		for (j = P; j > 0 && A[j - 1] > tmp; j--)
			A[j] = A[j - 1];
		A[j] = tmp;
	}
}
void FindP(ElementType A[],int N,int sum)
{
	int center;
	int i=N/2;
	while (A[i] >= sum)
		i--;
	center = A[i];
	int left, right;
	left = i-1; right = i;
	while (A[left] + A[right] != sum&&left>=0&&right<=N-1)
	{
		if (A[left] + A[right] > sum)
			left--;
		if (A[left] + A[right] < sum)
			right++;
	}
	if (A[left] + A[right] == sum)
		printf("数组中和为 %4d 的两个元素 %4d %4d 的下标分别为: %4d %4d\n", sum, A[left], A[right], left, right);
	else
		printf("数组中没有何为 %4d 的两个元素!\n",sum);
}
int main()
{
	int A[] = { 6,10,0,14,3,1,27,12,31,44,59,66,81,92 };
	int sum, N = sizeof(A) / sizeof(A[0]);
	printf("先对乱序数组进行快速排序！\n");
	Quicksort(A, N);
	printf("排序好的数组为：\n");
	for (int i = 0; i < N; i++)
		printf("%4d", A[i]);
	printf("\n请输入两个数的和数并是计算机执行查找操作\n");
	scanf_s("%d", &sum);
	FindP(A, N, sum);
	return 0;
}
