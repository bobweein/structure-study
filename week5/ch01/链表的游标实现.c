//该链表为循环单链表！
#include <stdio.h>
typedef int ProToNode;
typedef ProToNode List;
typedef ProToNode Position;
#define SpaceSize 20
typedef  int  ElementType;
ElementType n = 0;
typedef struct
{
	ElementType data;
	Position Next;
}CursorNode;
typedef struct
{
	CursorNode list[SpaceSize];//定义结构体数组
	Position Kongwei;//记录链表中的空位，即可以插入的位置
	int deldata;//存储删去的元素
}CursorList;
CursorList  Initlist(CursorList L)
{
	int i;
	for (i = 0; i < SpaceSize; i++)
		L.list[i].Next = i + 1;
	L.list[SpaceSize - 1].Next = 0;
	L.Kongwei = 1;
	return L;
}
List CursorAlloc(CursorList L)
{
	Position  p;
	p = L.Kongwei;//L.kongewei代表可以插入的位置
	L.Kongwei = L.list[p].Next;//存储下一个可以插入的位置
	return p;
}
void CursorFree(CursorList L, Position p)
{
	//要删去一个元素就是把他所在的位置变成空位
	//把要删去的位置的next指向删去前的空位
	L.list[p].Next = L.Kongwei;
	L.Kongwei = p;
}

CursorList Insert(CursorList L, Position pt, int x)
{
	n++;//主要是为了保证能在刚建立链表时插入的第一个元素的指针域置为0，，
	int k, j;
	k = L.Kongwei;
	L.Kongwei = L.list[k].Next;//47 到48行对空位进行调整
	L.list[k].data = x;//赋值
	//要插入第几个位置就先找到那个位置的前驱的next
	j = L.list[0].Next;//先指向第一个位置
	//使用for循环，使j指向第pt-1个位置（当插入元素位置小于等于2，不必去找位置pt-1）
	for (int i = 1; i < pt - 1; i++)
		j = L.list[j].Next;
	if (pt == 1&&n==1)  L.list[k].Next = 0;
	else {
		//将原本在位置pt上的元素作为第pt+1个位置
		L.list[k].Next = L.list[j].Next;

		//将pt-1位置上的next域指向k,(将这个插入的元素放在位置pt上)
		L.list[j].Next = k;
	}
	if (pt == 1 && n != 1)
	{
		int temp; temp = L.list[k].data; L.list[k].data = L.list[1].data; L.list[1].data = temp;
	}

	return L;
}
Position Islast(Position pt, CursorList L)
{
	if (pt == 0)
	{
		printf("这里是表头！");
		return 0;
	}
	return L.list[pt].Next == 0;
}
Position FindPrevious(int x, CursorList L)
{
	Position p;
	p = L.list[0].Next;
	while (p && L.list[L.list[p].Next].data != x)
	{
		p = L.list[p].Next;
	}
	return p;
}
CursorList Delete(Position pt, CursorList L)
{
	if (pt == 0)
	{
		printf("表头删去无意义！");
		return;
	}
	int p, j;
	j = L.list[0].Next;
	for (int i = 1; i < pt-1; i++)
		j = L.list[j].Next;
	p = L.list[j].Next;
	L.list[j].Next = L.list[p].Next;
	L.deldata = L.list[p].data;
	CursorFree(L, p);
	return L;
}
void PrintList(CursorList L)
{
	int p;
	p = L.list[0].Next;
	while(p)
	{
		printf("%4d", L.list[p].data);
		p = L.list[p].Next;
	}
	printf("\n");
}
Position Find(CursorList L, ElementType x)
{
	int n = 1;
	Position p = L.list[0].Next;
	while (p && L.list[p].data != x)
	{
		p = L.list[p].Next;
		n++;
	}
	return n;
}
Position PFindX(Position pt, CursorList L)
{
	Position p;
	p = L.list[0].Next;
	for (int i = 1; i < pt; i++)
		p = L.list[p].Next;
	return L.list[p].data;
}
int main()
{
	CursorList L = { {0},0,0 };
	int i, len, pt, x;
	int arry[] = { 1,2,3,4,5,6,7,8,9,11 };
	len = sizeof(arry) / sizeof(arry[0]);
	//链表初始化
	L = Initlist(L);
	//输入链表
	for (i = 0; i < len; i++)
		L = Insert(L, i + 1, arry[i]);
	printf("这个静态链表为： ");
	PrintList(L);
	//删去某个位置上的元素
	printf("要删去的位置为：");
	scanf_s("%d", &pt);
	L = Delete(pt, L);//这里如果改成DeleteList(pt,L)并且该函数无返回值的话，就会出现错误，
	printf("\n要删去的元素为%4d\n", L.deldata);//会导致L是上面循环之后链表的值不会显示有元素删去L.deldata是初始化时的值
	printf("删去元素后的链表：");
	PrintList(L);
	//插入一个元素到某个位置
	printf("请输入要插入的位置：");
	scanf_s("%d", &pt);
	printf("请输入要插入的元素：");
	scanf_s("%d", &x);
	printf("插入元素后链表为：");
	L = Insert(L, pt, x);
	PrintList(L);
	//找到数值为x的元素，并返回他的位置！
	printf("请输入一个你要查找的数：");
	scanf_s("%d", &x);
	pt = Find(L, x);
	printf("这个数的在第%d位置上！(如果结果为0，代表链表为空)", pt);
	//通过位置找元素，并返回这个元素的值！
	printf("\n请输入要查找的位置(请不要大于链表的长度！)：");
	scanf_s("%d", &pt);
	int y = 0;
	y = PFindX(pt, L);
	printf("位置%d上的元素为%d\n", pt, y);

	return 0;

}
