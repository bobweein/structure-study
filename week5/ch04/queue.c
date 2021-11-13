//链表实现队列
#include <stdio.h>
#include <stdlib.h>
typedef struct Dui
{
	int num;
	struct Dui* next;
	
}DuiNode, * DuiList;
struct Dui* front;//对头指针,直接使用头指针作为队尾
//初始化
DuiList Init(void)
{
	DuiList p;
	p = malloc(sizeof(DuiNode));
	if (p == NULL) printf("Out of Space!");
	p->next = NULL;
	return p;
}
//入队，始终将队尾作为链表的第一个结点！
DuiList EnterDui(DuiList S,int x)
{
	DuiList p;
	p = malloc(sizeof(DuiNode));
	if (p == NULL)
	{
		printf("Out of Space!");
		return NULL;
	}
	p->num = x;
	p->next = NULL;
	if (S->next == NULL)//将front指针放入
		front = p;
		DuiList q;
		q = S->next;
		p->next = q;
		S->next = p;
	return S;
}
DuiList OutDui(DuiList S)
{
	if (S->next==NULL) return NULL;
	else
	{
		DuiList p;
		p = S->next;
		if (p == NULL) return S;//队列为空
		if (p == front)//当链表中只剩下第一个结点时（队列中只有一个元素了），它的前驱是S
		{
			free(p); S->next = NULL; return;
		}
		while (p && p->next != front)//当队列中元素右两个及以上时，能找到前驱
			p = p->next;
		if (p != NULL)
		{
			p->next = NULL;
			free(front);
			front = p;
		}
	}
	return S;
}
void PrintDui(DuiList S)
{
	DuiList qt = S->next;
	if (qt == NULL)
	{
		printf("这是一个空对列!\n");
		return;
	}
	while (qt)
	{
		printf("%4d", qt->num);
		qt = qt->next;
	}
	printf("\n");
}
void main()
{
	
	DuiList S ;
	S = Init();
	int x;

	printf("执行入队操作\n");
	printf("请输入要入队的元素:\n");
	for (int i = 0; i <= 20; i++)
	{
		scanf_s("%d", &x);
		if (x == 0) break;
		S = EnterDui(S,x);
	}
	printf("执行若干次入队操作后的队列:\n");
	PrintDui(S);

	printf("\n执行出队操作		");
	printf("队列中元素，（从对尾到对头）\n");
	while (S->next)
	{
		S = OutDui(S);
		PrintDui(S);
	}
}
