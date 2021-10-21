#include <stdio.h>
typedef int DataType;
#define ListSize 100
//int CSHList(ListNode *L);
//int IsEmpty(ListNode *L);
//void Findi(ListNode *L, int i);
//ListNode* CreatList(ListNode *L, int n);
//ListNode* Insert(ListNode *L, int i, int e);
//int* find(ListNode *L, int e);
typedef struct
{
	DataType list[ListSize];
	int length;
}ListNode;
int CSHList(ListNode *L)
{
	return L->length = 0;
}
int IsEmpty(ListNode *L)
{
	return L->length == 0;
}
ListNode* CreatList(ListNode *L, int n)
{
	L->length = n;
	for (int i = 0; i < n; i++)
		scanf_s("%d", &L->list[i]);
	return L;
}
void Findi(ListNode *L, int i)
{
	if (L->length == 0) printf("empty list\n");
	else
	if (L->length >= i&&i>0)
	{
		printf("第%d个元素为：",i);
		printf("%d\n", L->list[i - 1]);
	}
	else
		printf("这个位置上可能没有元素！\n");
}
int* find(ListNode *L, int e)
{
	int* p;
	for (int i = 0; i < L->length; i++)
		if (L->list[i] == e)
		{
			p = &L->list[i];
			printf("值为%d的元素的地址为：", e);
			printf("%d\n", p);
			return p;
		}
	return NULL;
}
ListNode* Insert(ListNode *L, int i, int e)
{
	if (i<0 || i>L->length) printf("这个位置不对，快换一个！\n");
	else
		if (L->length > ListSize)
		{
			printf("这个顺序表已经满了！\n");
		}
		else
		{
			for (int j = L->length; j >= i; j--)
				L->list[j] = L->list[j - 1];
			L->list[i - 1] = e;
			L->length=L->length+1;

		}
	return L;
}
void print(ListNode *L)
{
	printf("这个顺序表中的元素为：\n");
	for (int i = 0; i < L->length; i++)
		printf("%d ", L->list[i]);
	printf("\n");
}
int main()
{
	ListNode *L,p;
	int n;
	printf("请输入元素个数：（请不要超过一百！）");
	scanf_s("%d", &n);
	L = CreatList(&p,n);
	print(L);


	int i, e;
	printf("请输入要插入的位置i，和要插入的元素e");
	scanf_s("%d%d", &i, &e);
	Insert(L, i, e);
	printf("请输入插入后的顺序表");
	print(L);

	printf("请输入要查找的元素");
	int m;
	scanf_s("%d", &m);
	int* c;
	c=find(L, m);
	printf("验证%d\n", *c);

	int j = 4;
	printf("顺序表表中第四个元素是什么？是：");
	Findi(L, j);

	return 0;
}
