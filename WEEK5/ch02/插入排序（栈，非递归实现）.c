//用栈（非递归的方法）实现插入排序
#include<stdio.h>
#define MaxSize 20
void insertionsort( int *p,int n)
{
	void Print(int* p, int n);
	int stack[MaxSize];
	int top=0;
	for (int i=n;i>=1;i--)
	stack[top++] = i;
	while (top)
	{
		int j = stack[--top];
		for (int i = j; i >= 1; i--)
		{
			if (*(p + i) < *(p + i - 1))
			{
				int temp;
				temp = *(p + i);
				*(p + i) = *(p + i - 1);
				*(p + i - 1) = temp;
			}
		}
		printf("本趟的插入排序为:\n");
		Print(p, n);
	}

}
void Print(int* p, int n)
{
	for (int i = 0; i <= n; i++)
	{
		printf("%4d", *(p + i));
	}
	printf("\n");
}
int main()
{
	void insertionsort(int* p, int n);
	int arr[20], i;
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
	insertionsort(p, i);
	return 0;
}
