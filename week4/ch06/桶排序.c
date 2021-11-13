#include<stdio.h>
#include<string.h>
int main()
{
	void bucketsort(int* arry, int len);//声明桶排序函数
	int arr[10] = {64,8,216,512,27,729,0,1,343,125};//待排序数组
	int i;

	int len = sizeof(arr) / sizeof(arr[0]);//数组长度
	printf("未排序的原始数组为：");
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	bucketsort(arr, len);//调用桶排序函数
	printf("\n排序后的数组为：");
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	return 0;
}
void bucketsort(int* arry, int len)
{
	void bubblesort(int* arry, unsigned int len);
	if (len < 2) return;//长度小于无需排序
	int bucket[3][5];//设置三个桶，每个桶的大小为5
	int bucketsize[3];//记录三个桶中元素的个数
	int c = 0;
	memset(bucket, 0, sizeof(bucket));//初始化，把二维数组初始化为0，
	memset(bucketsize, 0, sizeof(bucketsize));//把每个桶的大小初始化为0
	//开始将元素放入不同的桶中
	for (int i = 0; i < len; i++)
	{
		unsigned int c = (unsigned int)(arry[i] / 10);//按位数来分桶
		if (c == 0 ) c = 0;//只有个位上有数字，就放到bucket[0]这个桶中
		else
			if (c>0&& c<= 9)//只有十位和个位上有数字，就放到bucket[1]这个桶中
				c = 1;
			else //百位，十位，个位上都有数字的话，就放到bucket[2]这个桶中
				if (c>=10) c = 2;
		int a = bucketsize[c];//指向桶中空位
		bucket[c][bucketsize[c]++] = arry[i];//放入bucket[c]中的空位bucket[c][a]上，并将bucketsize[c]++,让它指向桶中的下一个空位。
	}
	//对桶中的元素进行冒泡排序
	for (int i = 0; i < 3; i++)
		bubblesort(bucket[i], bucketsize[i]);
        //把排好序的桶依次输出
	int jj = 0, kk = 0;
	for (int ii = 0; ii < 5; ii++)
	{
		for (jj = 0; jj < bucketsize[ii]; jj++)
			arry[kk++] = bucket[ii][jj];
	}
}//冒泡排序
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
