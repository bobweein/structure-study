#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(ListNode)
typedef struct Data
{
	int num;
	struct Data* next;
 }ListNode,*LinkList;
LinkList CreatList(LinkList pT)
{
	LinkList head,p,q;

	head = malloc(LEN);
	if (head == NULL) return NULL;
	head->num = 0;
	head->next = NULL;

	p = malloc(LEN);
	if (p == NULL) return NULL;
	scanf_s("%d", &p->num);
	p->next = NULL;
	q = head;
	while (p->num != 0)
	{
		q->next = p;
	    q = p;
	    p = malloc(LEN);
	    if (p == NULL) return NULL;
	scanf_s("%d", &p->num);
	}
		return head;
}
void print(LinkList L)
{
	LinkList p;
	p = L;
	while (p!=NULL)
	{
		p = p->next;
		printf("%d  ", p->num);
		
	}
}
int main()
{
	LinkList L,head;
	head = NULL;
	printf("输入的节点中num的值，以0结尾\n");
	L = CreatList(head);
	printf("链表节点中的元素为：");
	print(L);
	return 0;
}

