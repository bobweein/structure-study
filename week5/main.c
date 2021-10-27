//用链表实现栈
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct Node
{
	ElementType data;
	
	struct Node * next;
	struct Node * topof;
}ListNode;
typedef ListNode* ListNext;

ListNext CreatStack (ListNext S)
{
	ListNext p1, head;
	head = NULL;
	 p1= malloc(sizeof(ListNode));
	 S->topof = p1;
	 if (p1 == NULL) printf("Out of Space!");
	 scanf_s("%d", &p1->data);
	 p1->next = NULL;
	 head = p1;
	 while (p1->data != 0)
	 {
		 S->topof->next = p1;
		 S->topof = p1;
		 p1 = malloc(sizeof(ListNode));
		 if (p1 == NULL) printf("Out of Space!");
		 scanf_s("%d", &p1->data);
		 p1->next = NULL;
	 }
	 S->topof->next=NULL;
	 return head;
}
ListNext FindPrevious(ListNext head, ElementType X)
{
	ListNext p = NULL;
	p = head;
	if (head->data == X)
	{
		ListNext q;
		q = head;
		free(q);
		q = NULL;
		//head->data = 0;
		return head;
	}
	else 
		while (p && p->next->data != X)
	    {
		p = p->next;
	    }
	return p;
}
ListNext Push(ListNext S, ListNext head)
{
		ListNext p;
		p = malloc(sizeof(ListNode));
		if (p == NULL)printf("Out of Space!");
		scanf_s("%d", &p->data);
		if (p->data != 0)
		{
			if (head->data ==0)
			{
				head = p;
				p->next = NULL;
				S->topof = p;
		    }
			else
			{
				S->topof->next = p;
				p->next = NULL;
				S->topof = p;
			}
		}
		return head;
		
}
ListNext Pop(ListNext S,ListNext head)
{
	if (S->topof == NULL)
	{
		printf("Out of Space!");
	}
	else
	{
		int x = S->topof->data;
		ListNext q = NULL;
		ListNext p = FindPrevious(head, x);
		S->topof = p;
		if(S->topof!=NULL)
		S->topof->next = NULL;
	}
	return head;
	
}
void PrintStack(ListNext head)
{
	printf("现在栈中的元素为（从栈底到栈顶）：");
	ListNext p;
	p = head;
		while (p)
		{
			printf("%4d", p->data);
			p = p->next;
		}
	printf("\n");
}
int main()
{
	ListNode Node = { 0,NULL,NULL };
	ListNext S = &Node;
	ListNext head = NULL;
	printf("请输入栈顶元素（每次只能输入一个数字(添加数字0作为输入结束的标志！如 ”8 0“）)\n");
	head = CreatStack(S);
	printf("\n输入元素后的栈：");
	PrintStack(head);

	for (int i = 1; i <= 5; i++)
	{
		printf("请执行删除栈顶操作！\n");
		head = Pop(S, head);
		printf("    执行删除操作后的栈：\n");
		PrintStack(head);
	}

	printf("请执行进栈操作！\n");
	head = Push(S, head);
	printf("执行进栈操作后的栈\n");
	PrintStack(head);
	return 0;

}
