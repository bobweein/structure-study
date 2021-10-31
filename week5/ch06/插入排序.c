	#include <stdio.h>
void bubblesort(int *p,int n)
{
	int flag = 0;
	int y = 1;
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j <= n - i-1; j++)
		{
			if (*(p+j) > *(p +j+1))
			{
				int temp;
				temp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = temp;
				flag = 1;
			}
		}
		if (flag == 0) break;
	
		y++;
	}
}
void insertsort(int *p,int x,int n)
{
	*(p + n + 1) = x;
	for (int i = n; i >= 0; i--)
	{
		if (*(p + i) > *(p+i+1))
		{
			int temp;
			temp = *(p + i);
			*(p + i ) = *(p+i+1);
			*(p + i + 1) = temp;
		}
	}
}
void print(int* p, int n)
{
	for (int i = 0; i <= n; i++)
	{
		printf("%4d", *p);
		p = p + 1;
	}
}
int main()
{
	printf("请输入一个数组(0为输入结束的标志）\n");
	int arr[20],i;
	for (i = 0; i <= 19; i++)
	{
		scanf_s("%d", &arr[i]);
		if (arr[i] == 0)
		{
			--i;
			break;
		}
	}
	int* p, n = i;
	p = arr;
	bubblesort(p,n);
	printf("排好序的数组为\n");
	print(p,n);

	printf("\n请输入需要插入的值");
	int x;
    scanf_s("%d", &x);
	insertsort(p, x,n);
	printf("插入排序后的数组为：\n");
	print(p, ++n);

	return 0;
}
