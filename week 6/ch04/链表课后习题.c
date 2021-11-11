//如果P=1,3,4,6
//那么，L中的第1，第3，第4，第6个元素被打印出来！
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
}LinkNode ,*LinkList;
LinkList CreatList()
{

		LinkList q, p, head;
		int n=0;
		q = p = malloc(sizeof(LinkNode));
		if (q == NULL)printf("Out of Space!\n");
		head = NULL;
		scanf_s("%d", &q->data);
		while (q->data)
		{
			n++;
			if (n == 1)
				head = q;
			else
				p->next = q;
			p = q;
			q = malloc(sizeof(LinkNode));
			if (q == NULL) printf("Out of Space!\n");
			scanf_s("%d", &q->data);
		}
		p->next = NULL;
		return head;
}
void PrintLots(LinkList L, LinkList P)
{
	LinkList p, q;
	q= L; p= P;
	while (p)
	{
		q = L;
		int temp=p->data;
		for (int i = 1; i < temp; i++)
			q = q->next;
		printf("%4d", q->data);
		p = p->next;
	}
}
int main()
{
	LinkList L, P;
	printf("请输入链表P(升序输入，数据不超过10)；\n");
	P = CreatList();
	printf("请输入大于十个数据：\n");
	L = CreatList();
	PrintLots(L, P);
	return 0;
}
