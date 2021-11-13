#include <stdio.h>
void insertionsort(int arr[], int n)
{
	void Printarr(int arr[], int n);
	if (n != 1)
		insertionsort(arr, n - 1);
	int temp,i;
	temp = arr[n];
	i = n - 1;
	while(i>=0)
	{
		if (arr[i] > temp)
		{
			arr[i + 1] = arr[i];//3,2,4,10,1,2,5,6,12,13,30,8 
			if (i ==0) 
			{
				arr[i] = temp; break;
			}
		}
		if (arr[i] <=temp)
		{
			arr[i + 1] = temp;
			break;
		}
		i--;
	}
	printf("递归过程									 (%d)\n", n);
	Printarr(arr, n);
}
void Printarr(int arr[],int n)
{
	for (int i = 0; i <= n; i++)
		printf("%4d", arr[i]);
	printf("\n");
}
int main()
{
	int arr[] = { 3,2,4,10,1,2,5,6,12,13,30,8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	insertionsort(arr, len-1);
	
	return 0;
}
