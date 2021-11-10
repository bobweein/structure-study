//指向指针数据类型的指针大有用途。替代以前链表的生成程序。
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
typedef bool Status;
#define TRUE 1
#define FALSE 0
#define LH +1//左高
#define EH 0//等高
#define RH -1//右高
typedef struct BiTNode 
{
	int data;
	int bf;
	struct BiTNode* lchild, * rchild;
}BiTNode ,*BiTree;
//右旋
void R_Rotate(BiTree* p)
{
	BiTree L;
	L = (*p)->lchild;//L为p的左孩子
	(*p)->lchild = L->rchild;//L的左孩子成为p的左孩子
	L->rchild = (*p);//p成为L的右孩子
	(*p) = L;//根结点的左孩子成为新的根结点
}
//左旋（和右旋相似）
void L_Rotate(BiTree* p)
{
	BiTree R;
	R = (*p)->rchild;
	(*p)->rchild = R->lchild;
	R->lchild = (*p);
	(*p) = R;
}
//左平衡(左边需要平衡分为四种情况，把每种情况理清楚)
void LeftBalance(BiTree* T)
{
	BiTree L;
	BiTree Lr;
	L = (*T)->lchild;
	switch (L->bf)
	{
	case LH://情况1
		(*T)->bf = L->bf = EH;
		R_Rotate(T);
		break;
	case RH:
		Lr = L->rchild;
		switch (Lr->bf)
		{
		case LH ://情况二
			(*T)->bf = RH;
			L->bf = EH;
	     	break;
		case EH://情况三
			(*T)->bf = L->bf = EH;
			break;
		case RH://情况四
			L->bf = LH;
			(*T)->bf = EH;
			break;
		}
		Lr->bf = EH;
		//双旋操作
		L_Rotate(&(*T)->lchild);
		R_Rotate(T);
	}
}
//右平衡（跟左平衡一样）
void RightBalance(BiTree* T)
{
	BiTree R;
	BiTree Rl;
	R = (*T)->rchild;
	switch (R->bf)
	{
	case RH:
		(*T)->bf = R->bf = EH;
		L_Rotate(T);
		break;
	case LH:
		Rl = R->lchild;
		switch (Rl->bf)
		{
		case LH:
			(*T)->bf = EH;
			R->bf = RH;
			break;
		case EH:
			(*T)->bf = R->bf = EH;
			break;
		case RH:
			R->bf = EH;
			(*T)->bf = LH;
			break;
		}
		Rl->bf = EH;
		R_Rotate(&(*T)->rchild);
		L_Rotate(T);
	}
}
//插入函数
 Status InsertAVL(BiTree* T, int e, Status* taller)
{
	 if (!*T)//当（*T）为NULL；或者树中没有相等的结点时 ，创建一个新的空间，并赋值
	 {
		 *T = (BiTree)malloc(sizeof(BiTNode));
		 if (*T == NULL)
		 {
			 printf("Out of Space!\n");
			 return FALSE;
		 }
		 (*T)->data = e;
		 (*T)->lchild = (*T)->rchild = NULL;
		 (*T)->bf = EH;
		 *taller = TRUE;
	 }
	 else 
	 {
		 if (e == (*T)->data)//查找到这个结点存在于树中
		 {
			 *taller = FALSE;
			 return FALSE;
		 }
		 if (e < (*T)->data)//这个元素可以插入到左子树
		 {
			 if (!InsertAVL(&(*T)->lchild, e, taller))//未插入的话，返回FALSE
				 return FALSE;
			 if (*taller)//如果是长高了
			 {
				 switch ((*T)->bf)
				 {
				 case LH://原来左子树比右子树高，需要作左平衡处理
					 LeftBalance(T);
					 *taller = FALSE;
					 break;
				 case EH://原本左右子树等高，现在左子树增高而树增高
					 (*T)->bf = LH;
					 *taller = TRUE;
					 break;
				 case RH://原来右子树比左子树高，现在左右子树等高
					 (*T)->bf = EH;
					 *taller = FALSE;
					 break;
				 }
			 }
			 
		 }
		 else
		 {
			 if (!InsertAVL(&(*T)->rchild, e, taller))
				 return FALSE;
			 if (*taller)
			 {
				 switch ((*T)->bf)
				 {
				 case LH://原本左子树比右子树高，现在左右子树等高
					 (*T)->bf = EH;
					 *taller = FALSE;
					 break;
				 case EH://原本左右子树等高，现在右子树增高而树增高
					 (*T)->bf = RH;
					 *taller = TRUE;
					 break;
				 case RH://原来右子树比左子树高，需要作左平衡处理
					 RightBalance(T);
					 *taller = FALSE;
					 break;
				 }
			 }
		 }
	 }
	 return TRUE;
}
 Print(BiTree T)//前序遍历
 {
	 if (T)
	 {
		 printf("%4d", T->data);
		 Print(T->lchild);
		 Print(T->rchild);
		
	 }
 }
 void main()
 {
	 int i;
	 int a[10] = { 3,2,1,4,5,6,7,10,9,8 };
	 BiTree T =NULL;
	 Status taller;
	 for (i = 0; i < 10; i++)
		 InsertAVL(&T, a[i], &taller);
	 printf("平衡后的树为：\n");
	 Print(T);

 }
