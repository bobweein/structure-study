//该链表为循环单链表！
#include <stdio.h>
typedef int ProToNode;
typedef ProToNode List;
typedef ProToNode Position;
#define SpaceSize 20
typedef  int  ElementType;
 typedef struct
{
	ElementType data;
	Position Next;
}CursorNode;
 typedef struct 
 {
	 CursorNode list[SpaceSize];
	 Position Kongwei;
	 int deldata;
 }CursorList;
 CursorList  Initlist(CursorList L)
{
	int i;
	for (i = 0; i < SpaceSize; i++)
		L.list[i].Next=i+1;
	L.list[SpaceSize - 1].Next = 0;
	L.Kongwei = 1;
	return L ;
}
 List CursorAlloc(CursorList L)
 {
	 int i;
	 i = L.Kongwei;
	 L.Kongwei = L.list[i].Next;
	 return i;
 }
 void CursorFree(CursorList L, Position pt)
 {
	 L.list[pt].Next = L.Kongwei;
	 L.Kongwei = pt;
 }
 
 CursorList Insert(CursorList L, Position pt,int x)
 {
	 int k, j;
	 k = L.Kongwei;
	 L.Kongwei = L.list[k].Next;
	 L.list[k].data = x;
	 j = L.list[0].Next;
	 for (int i = 1; i < pt - 1; i++)
		 j = L.list[j].Next;
	 L.list[k].Next = L.list[j].Next;
	 L.list[j].Next = k;
	 return L;
 }
 Position Islast(Position pt, CursorList L)
 {
	 if (pt == 0) 
	 { printf("大哥这里是表头！"); 
	 return 0;
	 }
	 return L.list[pt].Next == 1;
 }
 Position FindPrevious(int x, CursorList L)
 {
	 Position p;
	 p = L.list[0].Next;
	 while (p && L.list[L.list[p].Next].data != x)
	 {
		 p = L.list[p].Next;
		 if (p == 1)
		 {
			 return 0;
			 break;
		 }
	 }
	 return p;
 }
 CursorList DeleteList(Position pt, CursorList L)
{

	 int p,j;
	 j = L.list[pt].data;
	 if (pt == 0)
	 {
		 printf("表头删去无意义！");
		 return ;
	 }
	 p = FindPrevious(j, L);
	 L.list[p].Next = L.list[pt].Next;
	 L.deldata = L.list[pt].data;
	 CursorFree(L, pt);
	/* L.list[pt].Next = L.Kongwei;
	 L.Kongwei = pt;*/
	 return L;
}
 
 void PrintList(CursorList L,List len)
 {
	 int p;
	 p = L.list[0].Next; 
	 if (len != 0)
	 {
		 for (int i = 1; i <= len; i++)
		 {
			 printf("%4d", L.list[p].data);
			 p = L.list[p].Next;
		 }
	 }
	 else printf("这个链表为空！");
	 printf("\n");
 }
 Position Find(CursorList L, ElementType x)
 {
	 int n = 1;
	 Position p = L.list[0].Next;
	 while (p && L.list[p].data != x)
	 {
		 p = L.list[p].Next;
		 if (p == 1)
		    return 0;
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
 List ListLen(CursorList L)
 {
	 Position p;
	 int n = 1;
	 p= L.list[0].Next;
	 while (p)
	 {
		 p = L.list[p].Next;
		 if (p == 1) break;
		 n++;		 
	 }
	 return n;
 }
 CursorList DeleteAlist(CursorList L,List pt)
 {
	 Position p;
	 p = L.list[0].Next;
	 L.list[p].Next = p;
	 return L;
 }
 int main()
 {
	 CursorList L={ {0},0,0 };
	 int i, len,pt,x;
	 int arry[] = {1,2,3,4,5,6,7,8,9,11};
	 len = sizeof(arry) / sizeof(arry[0]);
	//链表初始化
	 L = Initlist(L);
	 //输入链表
	 for (i = 0; i < len; i++)
		 L=Insert(L, i+1, arry[i]);
	 printf("这个静态链表为： ");
	 PrintList(L, len);
	 //删去某个位置上的元素
	 printf("要删去的位置为：");
	 scanf_s("%d", &pt);
	 L=DeleteList(pt, L);//这里如果改成DeleteList(pt,L)并且该函数无返回值的话，就会出现错误，
	 printf("\n要删去的元素为%4d\n", L.deldata);//会导致L是上面循环之后链表的值不会显示有元素删去L.deldata是初始化时的值
	 printf("删去元素后的链表：");
	 PrintList(L,len-1);
	 //插入一个元素到某个位置
	 printf("请输入要插入的位置：");
	 scanf_s("%d", &pt);
	 printf("请输入要插入的元素：");
	 scanf_s("%d", &x);
	 printf("插入元素后链表为：");
	 L = Insert(L, pt, x);
	 PrintList(L, len);
	 //找到数值为x的元素，并返回他的位置！
	 printf("请输入一个你要查找的数：");
	 scanf_s("%d", &x);
	 pt=Find(L, x);
	 if (pt == 0)
	 {
		 printf("表中没有这个数！\n");
	 }
	 else
	 printf("这个数的在第%d位置上！", pt);
	 //通过位置找元素，并返回这个元素的值！
	 printf("\n请输入要查找的位置(请不要大于链表的长度！)：");
	 scanf_s("%d", &pt);
	 int y=0;
	 y = PFindX(pt, L);
	 printf("位置%d上的元素为%d\n", pt, y);
	 //链表当前的长度
	 List n;
	 n = ListLen(L);
	 printf("链表当前的长度为%d\n", n);
	 //删除表
	 L = DeleteAlist(L, n);
	 printf("如果进行DeleteAlist函数操作这是将清空后的链表长度减一（以后想办法解决这个问题）\n");
	 PrintList(L, ListLen(L)-1);

	 return 0;

 }
