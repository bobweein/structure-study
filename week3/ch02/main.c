#include <stdio.h>
int main()
{
	void select(int arr[], int n);
	int  a[5],b[4];
	int i;
	printf("请输入第一个包含五个数的数组\n");
	select(a, 5);
	printf("\n请输入第二个包含四个数的数组\n");
	select(b, 4);
	return 0;
}
void select(int arr[], int n)
{
	int i=0;
	for (i = 0; i <= n - 1; i++)
		scanf_s("%d", &arr[i]);
	int j,t=0;
	for (j = 0; j <= n - 1; j++)
	{
		
		for (i = 0; i <= n - 2- j; i++)
		{
			
			if (arr[i] > arr[i + 1])
			{
				t = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = t;
			}
		}
	
	}
	for (j = 0; j <= n - 1; j++)
		printf("%d  ", arr[j]);
}
