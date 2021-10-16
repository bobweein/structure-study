#include <stdio.h>
int main()
{
	void paixu (int**pt, int n);
	int* arr[5];
	int a[5];
	printf("请输入一个有5五个整数的数组：\n");
	for (int i = 0; i <= 4; i++)
		scanf_s("%d", &a[i], 4);
	int** p;
	for (int i = 0; i <= 4; i++)
		arr[i] = &a[i];
	p = arr;
	printf("排序前数组中元素的顺序是：\n");
	for (int i = 0; i <= 4; i++)
	{
		p = arr + i;
		printf("%d  ", **p);
	}
	p = arr;//这一步十分重要，因为经过上面那个循环p=arr+4;所以下面调用函数时j=0时*（（*pt）+j)=a[4]的值即7；
	paixu(p, 5);
	printf("\n排序后数组中元素的顺序是：\n");
	for (int i = 0; i <= 4; i++)
	{
		p = arr + i;
		printf("%d  ", **p);
	}
	return 0;
}
void paixu(int**pt, int n)
{
	for (int i=0;i<=n-2;i++)
		for (int j = 0; j <= n - 2- i; j++)
		{
			if (*((*pt) + j) > *((*pt) + j + 1))
			{
				int temp;
				temp =*( *pt + j);
				*(*pt+ j) = *(*pt + j + 1);
				*(*pt + j + 1) = temp;
			}
		}
}
