//对分查找结合快速排序！
#include <stdio.h>
#define N 10
void InsertionSort(int a[], int n)
{
	int j, p;
	int tmp;
	for (p = 1; p < n; p++)
	{
		tmp = a[p];
		for (j = p; j > 0 && a[j - 1] > tmp; j--)//对for循环函数的充分利用
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}
void Quicksort(int a[], int n)
{
	void Qsort(int a[], int left, int right);
	Qsort(a, 0, n - 1);
}
int Median3(int a[], int left, int right)
{
	void swap(int* a, int* b);
	int center = (left + right) / 2;
	if (a[left] > a[center])
		swap(&a[left], &a[center]);
	if (a[left] > a[right])
		swap(&a[left], &a[right]);
	if (a[center] > a[right])
		swap(&a[center], &a[right]);
	swap(&a[center], &a[right - 1]);
	//因为经过上面的变换，a[right]已经比选取的这个枢纽元（privot)更大了,
	//Hide pivot
	return a[right - 1];//return pivot
}

void Qsort(int a[], int left, int right)
{
	void swap(int* a, int* b);
	int i, j;
	int pivot;
	if (left + 3 <= right)//这一段需要快速排序的数组的长度小于3时，用插入排序
	{
		//长度大于三
		pivot = Median3(a, left, right);
		i = left; j = right - 1;
		for (; ;)
		{
			while (a[++i] < pivot) {}
			while (a[--j] > pivot) {}
			if (i < j)
				swap(&a[i], &a[j]);
			else break;
		}
		swap(&a[i], &a[right - 1]);
		Qsort(a, left, i - 1);
		Qsort(a, i + 1, right);
	}
	else//长度小于三，用插入排序！
		InsertionSort(a + left, right - left + 1);//很nice的地方！
}
void swap(int* a, int* b)
{
	int temp;
	temp = *a; *a = *b; *b = temp;
}
void BinarySearch(int arr[], int n)//自己写的对分查找
{
	int center, left, right;
	left = 0; right = N - 1;
	center = (left + right) / 2;
	while (left!=center||n==arr[center])//循环出口，没找到这个元素
	{
		if (n > arr[center])
		{
			left = center;
			center = (left + right) / 2;
		}
	    if (n == arr[center])
		{
			printf("找到这个元素了！\n");
			return;
		}
		if(n<arr[center])
	    {
			right = center;
			center = (left + right) / 2;
		}
		if (n == arr[right])
			//这个值等于arr[right]（最后一个元素）,但是center陷入死循环，
			//无法跨越到最后一个元素导致程序但会未找到该元素
		{
			printf("找到这个元素了！\n");
			return;
		}
	}
	printf("没有找到这个数!\n");
	return;
}
//一种更简洁的方法，已解决center始终偏向left的问题
//当n>arr[center],将left=center+1;
//当n<arr[center],将right=center-1;
//而且因为left和right 会移动，所以会出现left>right的情况，所以将这个设置为循环结束的标志
void BinarySearch1(int arr[], int n)
{
	int left, center, right;
	left = 0; right = N - 1;
	while (left <= right)
	{
		center = (left + right) / 2;
		if (n > arr[center])
			left = center + 1;
		else
			if (n < arr[center])
				right = center - 1;
			else
			{
				printf("找到这个元素了！\n");
				return;
			}
	}
	printf("没有找到这个元素！\n");
	return;
}
void Print(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%4d", a[i]);
	printf("\n");
}
int main()
{
	void BinarySearch(int arr, int n);
	void BinarySearch1(int* arr, int n);
	printf("请输入一个无序数组\n");
	//int array[10] = { 0,13,26,31,43,57,65,75,81,92 };
	int array[10] = { 13,81,92,43,65,31,57,26,75,0 };
	Print(array, N);
	printf("请将一个乱序的数组进行快速排序\n");
	Quicksort(array,10);
	Print(array, N);
	printf("\n请输入一个需要查找的元素:");
	int n;
	scanf_s("%d", &n);
	BinarySearch(array, n);
	BinarySearch1(array, n);
	return 0;
}
