#include<stdio.h>
#define NumSets 9
typedef int DisjSet[NumSets + 1];
typedef int SetType;
typedef int ElementType;
void Initialize(DisjSet S);
void SetUnion(DisjSet S, SetType Root1, SetType Root2);
SetType Find(ElementType X, DisjSet S);
void Initialize(DisjSet S)
{
	int i;
	for (i = NumSets; i > 0; i--)
		S[i] = 0;
}
//按高度初始化
//按高度求并
void SetUnion(DisjSet S, SetType Root1, SetType Root2)
{
	if (S[Root2] < S[Root1])		
		S[Root1] = Root2;			
	else
	{
		if (S[Root1] == S[Root2])	
			S[Root1]--;
		S[Root2] = Root1;
	}
}

//查找算法
SetType Find(ElementType X,DisjSet S)
{
	if(S[X]<=0)
		return X;
	else
		return Find(S[X],S);
}

void main()
{
	DisjSet S;
	Initialize(S);
	SetUnion(S, 5, 6);
	SetUnion(S, 5, 7);
	SetUnion(S, 4, 5);
	printf("查找8的结果为：%d\n", Find(7, S));
}
