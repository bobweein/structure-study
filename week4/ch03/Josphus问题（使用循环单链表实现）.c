#include <stdio.h>
#include<stdlib.h>
#define ListSize 100
#define LEN sizeof(struct Node)
typedef int DateType;


typedef struct Node
{
	int data;
	struct Node* next;
}ListNode,*LinkList;
LinkList CreatCycList(int n);
void Josphus(LinkList head, int n, int m, int k);
void main()
{
	LinkList head;
	int n, m, k;
	printf("输入圈中人的个数n:");
	scanf_s("%d", &n);
	printf("输入开始报数的序号k:");
	scanf_s("%d", &k);
	printf("报数为m的人出列m:");
	scanf_s("%d", &m);
	head = CreatCycList(n);
	Josphus(head, n, m, k);
}
LinkList CreatCycList(int n)
{
	LinkList head = NULL;
	ListNode* s, * r;
	
	int i;
	r = NULL;
	for (i=1;i<=n;i++)
	{
		s = malloc(LEN);
		if (s == NULL)  printf("error");
		s->data = i;
		s->next = NULL;
		if (head == NULL)
		{
			head = s;
			r = head;
		}
		else
		{
			r->next = s;
			r = s;	
		}
	}
	r->next = head;
	return head;
}
void Josphus(LinkList h, int n, int m, int k)

{
	ListNode* p, * q;
	int i;
	p = h;
	q = NULL;
	for (i = 1; i < k; i++)
	{
		q = p;
		p = p->next;
	}
	while (p->next !=p)
	{
		for (i = 1; i < m; i++)
		{
			q = p;
			p = q->next;
		}
		q->next = p->next;
		printf("%4d", p->data);
		free(p);
		p = q->next;
	}
	printf("%4d\n", p->data);
}
