#include <stdio.h>
#define QueueSize 5
struct Queue
{
	int AQueue[QueueSize];//设置队列数组
	int front;//队头指针
	int rear;//队尾指针
	int flag;//队满对空的标志,元素入队成功时为1，出队成功时为0
};
typedef struct Queue SCQ, * SCQNext;
//初始化
void Init(SCQNext Q)
{
	Q->front = Q->rear=0;
	Q->flag=0;
}//队列是否为空
int IsEmpty(SCQNext Q)
{
	if (Q->front == Q->rear && Q->flag == 0)//队空
		return 1;
	else return 0;
}
//入队
int RuiQueue(SCQNext Q,int x)
{
	if (Q->front == Q->rear && Q->flag == 1)//堆满的判断标准
		return 0;
	else
	{
		if (x == 0) return 0;
		Q->AQueue[Q->rear] = x;
		Q->rear = (Q->rear + 1) % QueueSize;//使数组在逻辑上是循环的，并且当队列没满时，指向空位
		Q->flag = 1;//表示元素入队成功
		return 1;
	}
}//元素出队
int ChuQueue(SCQNext Q, int* e)
{
	if (Q->front == Q->rear && Q->flag == 0)//队空的判断标准
		return 0;
	else
	{
		*e = Q->AQueue[Q->front];//把要出队的元素赋给指针变量
		Q->front= (Q->front + 1) % QueueSize;
		Q->flag = 0;//元素出队成功
		return 1;
	}
}//打印队列
void PrintQueue(SCQNext Q)
{
	if (Q->front == Q->rear && Q->flag == 0)
		return 0;
	else
	{
		int n = LenQueue(Q);
		int i = Q->front;
		for(int j=0;j<n;j++)
		 {
			 printf("%4d", Q->AQueue[i]);
			 i = (i + 1) % QueueSize;
		 }
		 printf("\n");
		 return 1;
	}
}//队列长度
int LenQueue(SCQNext Q)
{
	int n = 0;
	int i = Q->front;
	if (Q->front == Q->rear && Q->flag == 1)
		return	QueueSize;
	else
	{
		while (i != Q->rear)
		{
			i = (i + 1) % QueueSize;
			n++;	
		}
		return n;
	}

}
void main()
{
	SCQ queue = { {0},0,0,0 };
	SCQNext Q=&queue;
	int x = 0;

	printf("请输入要入队列的元素：(以0为队列输入结束的标志)\n");
	do 
	{
		scanf_s("%d", &x);
		RuiQueue(Q, x);
	} while (x);
	printf("元素入队后的队列；");
	PrintQueue(Q);

	printf("\n执行出队列操作,并打印出队的元素");
	int* e;
	e = &Q->AQueue[0];
	ChuQueue(Q, e);
	printf("\n出队列完毕，出队列的元素为：%d",*e);
	printf("\n元素出对后的队列：");
	PrintQueue(Q);

}
