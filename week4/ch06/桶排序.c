#include<stdio.h>
#include<string.h>
int main()
{
	void bucketsort(int* arry, int len);
	int arr[10] = {64,8,216,512,27,729,0,1,343,125};
	int i;

	int len = sizeof(arr) / sizeof(arr[0]);
	printf("未排序的原始数组为：");
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	bucketsort(arr, len);
	printf("\n排序后的数组为：");
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	return 0;
}
void bucketsort(int* arry, int len)
{
	void bubblesort(int* arry, unsigned int len);
	if (len < 2) return;
	int bucket[3][5];
	int bucketsize[3];
	int c = 0;
	memset(bucket, 0, sizeof(bucket));
	memset(bucketsize, 0, sizeof(bucketsize));
	for (int i = 0; i < len; i++)
	{
		unsigned int c = (unsigned int)(arry[i] / 10);
		if (c == 0 ) c = 0;
		else
			if (c>0&& c<= 9)
				c = 1;
			else 
				if (c>=10) c = 2;
		int a = bucketsize[c];
		bucket[c][bucketsize[c]++] = arry[i];
	}
	
	for (int i = 0; i < 3; i++)
		bubblesort(bucket[i], bucketsize[i]);

	int jj = 0, kk = 0;
	for (int ii = 0; ii < 5; ii++)
	{
		for (jj = 0; jj < bucketsize[ii]; jj++)
			arry[kk++] = bucket[ii][jj];
	}
}
void bubblesort(int* arry, unsigned int len)
{
	if (len < 2) return;
	int i, temp, ifswap=0;
	for(i=0;i<len-1;i++)
		if (arry[i] > arry[i+1])
		{
			temp = arry[i+1];
			arry[i+1] = arry[i];
			arry[i] = temp;
			ifswap = 1;
		}
	if (ifswap == 0) return;
	bubblesort(arry, --len);
}
