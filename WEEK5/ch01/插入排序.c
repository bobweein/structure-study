#include <stdio.h>
void insertionsort(int* p, int n,int len)
{
	void Print(int*p, int n);
	if (n != 0)
	{
		int j = n;
		insertionsort(p, n - 1,len);
		for (int i = j; i >=1; i--)
		{
			if (*(p + i) < *(p + i -1))
			{
				int temp;
				temp = *(p + i);
				*(p+ i) = *(p + i-1);
				*(p + i - 1) = temp;
			}
		}
		printf("本趟的插入排序为:\n");
		Print(p, len);
	}
}
void Print(int *p, int n)
{
	for (int i = 0; i <= n; i++)
	{
		printf("%4d", *(p+i));
	}
	printf("\n");
}
int main()
{
	void insertionsort(int* p, int n,int len);
	void Print(int* p, int n);
	int arr[20],i,n,x;
	int* p = arr;
	printf("请输入一个数组：（以0为输入结束的标志！）\n");
	for (i = 0; i <= 19; i++)
	{
		scanf_s("%d", &arr[i]);
		if (arr[i] == 0)
		{
			--i;
			break;
		}
	}
	Print(arr, i);
	n = i;
	insertionsort(arr, n,i);
	return 0;
}
