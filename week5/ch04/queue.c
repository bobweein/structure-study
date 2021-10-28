#include <stdio.h>
#include <stdlib.h>
typedef struct Dui
{
	int num;
	struct Dui* next;
	struct Dui* front;
	struct Dui* rear;
}DuiNode, * DuiList;
DuiList Init(DuiList head, DuiList S)
{
	S->rear = head;
	return head;
}
DuiList EnterDui(DuiList S, DuiList head)
{

	int x;
	printf("\n请输入要入队的元素:");
	scanf_s("%d", &x);
	DuiList p;
	p = malloc(sizeof(struct Dui));
	if (p == NULL) printf("Out of Space!");
	p->num = x;
	S->rear->next = p;
	S->rear = p;
	S->rear->next = NULL;
	return head;
}
DuiList OutDui(DuiList head)
{
	if (head == NULL) return head;
	else
	{
		DuiList q, p = NULL;
		p = head->next;
		head->next = p->next;
		q = p;
		free(q);
		return head;
	}
}
void PrintDui(DuiList head)
{
	DuiList p = head->next;
	if (head == NULL) printf("这是一个空对列!\n");
	while (p)
	{
		printf("%4d", p->num);
		p = p->next;
	}
}
void main()
{
	DuiNode DUI = { 0,NULL,NULL };
	DuiList S = &DUI;
	DuiList head = S;
	head = Init(head, S);

	//head =Creat( S);

	printf("执行入队操作\n");
	for (int i = 0; i <= 3; i++)
		head = EnterDui(S, head);
	printf("执行若干次入队操作后的队列:\n");
	PrintDui(head);

	printf("\n执行出队操作\n");
	head = OutDui(head);
	printf("\n执行若干次出队操作后的队列:\n");
	PrintDui(head);
}
