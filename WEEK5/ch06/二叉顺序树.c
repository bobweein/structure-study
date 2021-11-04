#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode
{
	int data;
	struct BiTNode* lchild, * rchild;
}Bitnode ,*Bitree;
int Search(Bitree T, int key, Bitree  f, Bitree* p)//f为结点的双亲，
//p是查找路径上的最后一个结点并返回0；key 为需要查找的元素
{
	if (!T)
	{
		*p = f;//如果没找到，指向前一个结点的指针
		return 0;
	}
	else if (key == T->data)
	{
		*p = T;//找到的话，返回这个指向这个结点的指针，
		return 1;
	}
	else if (key < T->data)
		return Search(T->lchild, key, T, p);
	else
		return Search(T->rchild, key, T, p);
}
int Insert(Bitree* T, int key)
{
	int Search(Bitree T, int key, Bitree  f, Bitree * p);//声明
	Bitree p, s;
	if (!Search(*T, key, NULL, &p))//避免重复输入同一个结点,函数的实参为&p，虽然形参与实参是值传递
		//但是通知指针可以改变实参指针指向的数据,所以p的值为f;
	{
		s = (Bitree)malloc(sizeof(Bitnode));
		if (s == NULL) printf("Out Of Space");
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)//如果p为NULL，(如果这个表是空表）则将这个新开辟的空间作为根结点。
			*T = s;
		//直接用p->data的原因是上面避免重复输入时，调用了search函数，
			//该函数返回的p,返回的位置就是要插入位置的根节点；等于说本函数中所加的判断起到了
			//两个作用，一是避免输入已经输入的结点，二是是指针p指向查找路径上最后访问的结点
		//要插入元素时只需要比较这个最后访问的结点的数据域的值的大小，如果比这个大就放在右孩子结点
		//如果比这个小就放在左孩子结点，不要再顺着二叉树去查找可以插入的位置。
		else if (key < p->data)
			p->lchild = s;
		else
			p->rchild = s;
		return 1;
	}
	else 
		return 0;
}
int Deleteb(Bitree* T, int key)
//顺着二叉树去查找要删去的元素的；用递归的思想，跟search函数的想法一样
{
	int Delete(Bitree * p);
	if (!*T)
		return 0;
	else
	{
		if (key == (*T)->data)
			return Delete(T);//因为删除操作有三个不同的情况，所以在写一个函数,
		else if (key < (*T)->data)
			return  Deleteb(&(*T)->lchild, key);
		else 
			return Deleteb(&(*T)->rchild, key);
	}
}
int Delete(Bitree* p)
{
	Bitree q, s;
//如果要删除的结点只有左孩子结点，则把指向这个根结点的左孩子结点的指针赋给指向根结点的指针
//，然后释放要删除的元素
	if ((*p)->rchild == NULL)
	{
		q = *p; *p = (*p)->lchild; free(q);
	}
	//若果要删除的结点只有有孩子结点，跟前一种类似；
	else if ((*p)->lchild == NULL)
	{
		q = *p; *p = (*p)->rchild; free(q);
	}
	//如果要删除的结点既有左孩子有又右孩子的话
	else
	{
		q = *p; s = (*p)->lchild;//先左转指向要删除结点的左孩子
		//然后一直右转，找到与要删除结点最接近的一个结点，
		//（要删除结点的右子树上也有一个很接近该结点的一的结点）
		while (s->rchild)
		{
			q = s; s = s->rchild;
		}
		(*p)->data = s->data;
		//把上面找的那个最接近删除结点的结点的值放在这个付给这个要删除结点
		// s就是指向这个被找到的结点
		// q是这个被找到的结点的前驱
		//如果寻找的结点的前驱不是这个要删除的结点
		//就把这寻找到的结点的左子树做这个要寻找的结点的前驱的右子树
		//因为已经把这个找到的节点去做根结点了
		if (q != *p)
			q->rchild = s->lchild;
		//如果寻找的这个结点的前驱时这个删除结点
		//把这个找到的结点的左子树连接到前驱的左子树
		else q->lchild = s->lchild;
		free(s);
	}
	return 1;
}
void PrePrint(Bitree T)//前序输出
{
	if (T)
	{
		printf("%4d", T->data);
		PrePrint(T->lchild);
		PrePrint(T->rchild);
	}
}
int main()
{
	Bitree T=NULL;
	int n,key;
	printf("请输入节点个数；");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		
		scanf_s("%d", &key);
		Insert(&T, key);
	}
	printf("\n二叉树为：\n");
	PrePrint(T);
	printf("\n请输入要删除的数：");
	scanf_s("%d", &key);
	Deleteb(&T, key);
	PrePrint(T);
	return 0;

}
