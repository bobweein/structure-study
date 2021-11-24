#include <stdio.h>
void insertionsort(int arr[], int n)
{
	void Printarr(int arr[], int n);
	if (n != 1)//递归出口的标志
		insertionsort(arr, n - 1);//先往前走，做到递归出口，然后在回来的途中解决问题！（先解决n=2的问题，然后在返回上一层解决n=3的问题，一直往后回到递归开始的地方）
	int temp,i;
	temp = arr[n];//当前递归中数组的最后一个（不是最大的那个数组的最后一个）
	i = n - 1;
	while(i>=0)
	{
		if (arr[i] > temp)//如果arr[i]大于temp;将arr[i]赋给arr[i+1]，相当于将他向后移一个位置！
		{
			arr[i + 1] = arr[i];
			if (i ==0) //当arr[0]被往后移一个一个位置时，将temp放在数组的最前端！
			{
				arr[i] = temp; break;
			}
		}
		if (arr[i] <=temp)//如果arr[i]<=temp时，将temp放在arr[i]的后一个位置，即arr[i+1]!
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
