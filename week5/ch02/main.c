//用数组实现栈！
#include <stdio.h>
#define StackSize 50
typedef  int ElementType;
typedef struct
{
	ElementType stack[StackSize];
	int topofstack;
}Sstack;
Sstack Init(Sstack S)
{
	S.topofstack = -1;
	return S;
}
Sstack Push(Sstack S, ElementType X)
{
	if (S.topofstack == StackSize - 1)
		printf("Out of Space!");
	else
	{
		S.stack[S.topofstack++] = X;
	}
	return S;
}
Sstack Pop(Sstack S,ElementType X)
{
	if (S.topofstack == -1)
		printf("Out of Sapce!");
	else
	{
		X = S.stack[S.topofstack];
		printf("栈顶元素%d已拿出！\n", X);
		S.topofstack--;
	}
	return S;
}
ElementType Gettop(Sstack S)
{
	if (S.topofstack != -1 && S.topofstack != StackSize)
		return S.stack[S.topofstack-1];
	
}
ElementType StackLen(Sstack S)
{
	return S.topofstack;
}
Sstack CleanStack(Sstack S,ElementType X)
{
	printf("take the element out of  the stack! ");
	for (int i = StackLen(S); i>0  ; i--)
	{
		X = S.stack[S.topofstack--];
		printf("第%d个元素%d出栈", i, X);
		if (S.topofstack == -1) break;
	}
	printf("栈已清空！");
	return S;
}
void  ElementInStack(Sstack S)
{
	printf("现在栈中的元素为(从栈顶到栈底)：");
	for (int i = StackLen(S) - 1; i >= 0; i--)
		printf("%4d", S.stack[i]);
	printf("\n");

}
int main()
{
	Sstack S = { {0,0},0 };
	S = Init(S);
	S.topofstack = 0;
	int x=1;
	printf("请输入需要进栈的元素（将0作为输入结束的标志！）\n");
	for (int i = 0; i < StackSize; i++)
	{
		scanf_s("%d", &x);
		if (x == 0) break;
		S = Push(S, x);
	}
	ElementInStack(S);
	x = StackLen(S);
	printf("现在栈的长度为%d", x);

	printf("现在栈顶元素为%d\n", Gettop(S));
	printf("\n现在拿出栈顶元素：\n");
	S = Pop(S, x);
	ElementInStack(S);
	x = StackLen(S);
	printf("\n现在栈的长度为%d", x);
	return 0;
}
