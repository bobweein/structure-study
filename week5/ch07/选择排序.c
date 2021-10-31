//选择排序
#include <stdio.h>
void xuanzesort(int* p,int n)
{
	int i;
	int min = 0;
	for (int j = 0; j <= n; j++)
	{
		min = j;
		for (int i = j; i <= n; i++)
		{
			if (p[i] < p[min])  min = i;
		}
		int temp;
		temp = p[min];
		p[min] = p[j];
		p[j] = temp;
		printf("%4d", p[j]);
	}
}
int main()
{
	int arr[20],i;
	int* p = arr;
	printf("请输入一个无序数组：（以0为输入结束的标志）\n");
	for ( i = 0; i < 19; i++)
	{
		scanf_s("%d", &arr[i]);
		if (arr[i] == 0)
		{
			 --i;
			 break;
		}
	}
	xuanzesort(p, i);
	return 0;
}
