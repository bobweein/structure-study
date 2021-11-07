#include<stdio.h>
#define MAXSIZE 16
typedef struct node
{
	int arr[MAXSIZE];//定义一个数组用来存放二叉堆
	int length;

}Sqnode,*Sqnext;
void Heapsort(Sqnext L)
{
	void HeapAdjust(Sqnext L, int n, int m);
	void swap(Sqnext L, int i, int n);
	void Print(Sqnext L);
	void Print1(Sqnext L);
	if (L->length == 0) return;
	//将无序树调整为小顶堆
	int i;
	for (i = L->length / 2; i >= 1; i--)
		HeapAdjust(L, i, L->length);
	Print1(L);
	for (i = L->length; i>1; i--)
	{
		swap(L, 1, i);
		HeapAdjust(L, 1, i-1);
	}
	printf("经过堆排序后的数组为：\n");
	Print(L);
}
//arr[n]  ,arr[n+1],.......,arr[m]除arr[n]外全都是满足小顶堆的性质
void HeapAdjust(Sqnext L,int s,int m)
{
	int j;
	int temp;
	temp = L->arr[s];
	for (j =2*s; j <= m; j*=2)
	{
		if (j<m && L->arr[j]>L->arr[j + 1])
			++j;
		if (temp < L->arr[j])
			break;
		L->arr[s] = L->arr[j];
		s=j;
	}
	L->arr[s] = temp;
		
}
void swap(Sqnext L, int i, int n)
{
	int temp;
	temp = L->arr[i];
	L->arr[i] = L->arr[n];
	L->arr[n] = temp;
}
void Print(Sqnext L)
{
	int i;
	for (i = MAXSIZE-1; i > 0; i--)
		printf("%4d", (*L).arr[i]);
}
void Print1(Sqnext L)
{
	int i;
	printf("建立好的小顶堆为：\n");
	for (i = 1; i < MAXSIZE; i++)
		printf("%4d", (*L).arr[i]);
	printf("\n");
}
int main()
{
	int i;
	Sqnext L;
	Sqnode N = { {0},0 };
	L = &N;
	printf("请输入需要排序的数组：\n");
	for (i = 1; i < 16; i++)
	{
		scanf_s("%d", &(L->arr[i]));
		++L->length;
	}
	Heapsort(L);
	return 0;
}
