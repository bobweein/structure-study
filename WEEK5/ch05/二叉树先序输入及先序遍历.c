#include <stdio.h>
#include <stdlib.h>
typedef struct Tree
{
	int data;
	struct Tree* lchild, * rchild;
}BiTNode,*Bitree;
void CreatBitree(Bitree* T)//前序输入二叉树！
{
	int ch;
	scanf_s("%d", &ch);
	if (ch == 0)
		*T = NULL;
	else
	{
		*T = (Bitree)malloc(sizeof(BiTNode));
		if (!*T)
			printf("Out Of Space");
		(*T)->data = ch;
		CreatBitree(&(*T)->lchild);
		CreatBitree(&(*T)->rchild);
	}
}

void PreOrderTraverse(Bitree T)//前序遍历二叉树
{
	if (T == NULL)
		return;
	printf("%4d", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}
void main()
{
	Bitree T=NULL;
	printf("前序输入建立二叉树：\n");
	CreatBitree(&T);
	printf("前序遍历二叉树:\n");
	PreOrderTraverse(T);

}
