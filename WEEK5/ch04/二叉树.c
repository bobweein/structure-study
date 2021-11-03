#include <stdio.h>
#include <stdlib.h>
#define  N 20
typedef struct Node
{
	int data;
	struct Node* lchild;
	struct Node* rchild;
}*Bitree ,BiNode;
Bitree  stack[N];
Bitree Init()
{
	Bitree T;
	return T = NULL;
}
//这个插入函数搬用了方芷柔同学写的插入函数。
Bitree Insert(int x, Bitree T)//插入元素
{
    if (T == NULL)
    {
        T = malloc(sizeof(struct Node));//申请内存
        if (T == NULL)
            printf ("Out of space");
        else
        {
            T->data = x;
            T->lchild = T->rchild = NULL;
        }
    }
    else if (x < T->data)
        T->lchild = Insert(x, T->lchild);//向左沿树查找可插入的位置
    else if (x > T->data)
        T->rchild = Insert(x, T->rchild);//向右沿树查找可插入的位置
    return T;
}
void PrePrint(Bitree T)
{
    if (T)
    {
       
        PrePrint(T->lchild);
        printf("%4d", T->data);
        PrePrint(T->rchild);
    }
}
void main()
{
    Bitree T = NULL;
    printf("请输入结点个数：");
    int n;
    scanf_s("%d", &n);
    printf("开始创建树：");
   
    int i,x;
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", &x);
       T= Insert(x, T);
    }
    PrePrint(T);
    return;

}
