#include <stdio.h>
#include "Stack.h"
#include <stdlib.h>
struct Node
{
	ElementType data;
	ProToNode next;
};
int IsEmpty(Stack S)
{
	if (S->next == NULL)return 1;
	else return 0;
}
Stack CreatStack(void)
{
	Stack top;
	top=(Stack)malloc(sizeof(struct Node));
	if (top == NULL) printf("Out of Space !\n");
	else
	{
		top->next = NULL;
		return top;
	}
}
void Push(ElementType x, Stack S)
{
	Stack p;
	p = CreatStack();
	p->data = x;
	p->next = S->next;
	S->next = p;
	return S;
}
void Pop(Stack S)
{
	if (!IsEmpty(S))
	{
		Stack q, p;
		q = S->next;
		p = q;
		S->next = q->next;
		free(p);
		return S;
	}
	else printf("栈已经是空的了！\n");
	return NULL;
}
ElementType Top(Stack S)
{
	if (!IsEmpty(S)) 
	{
		printf("栈顶元素为%4d\n", S->next->data);
		return S->next->data;
	}
		printf("栈已空！\n");
		return 0;
}
void Print(Stack S)
{
	printf("栈中的元素为（从栈顶到栈底）\n");
	Stack p;
	p = S->next;
	while (p)
	{
		printf("%4d", p->data);
		p =p->next;
	}
	printf("\n");
}
int main()
{
	Stack S ;
	S=CreatStack();
	printf("请输入入栈元素：\n");
	int i, x;
	for (i = 0;; i++)
	{
		scanf_s("%d", &x);
		if (x == 0) break;
		Push(x, S);
	}
	Print(S);
	while (S->next)
	{
		Pop(S);
		Print(S);
	}
	return 0;

}
