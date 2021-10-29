#include <stdio.h>
#define QueueSize 5
struct Queue
{
	int AQueue[QueueSize];
	int front;
	int rear;
	int flag;
};
typedef struct Queue SCQ, * SCQNext;
void Init(SCQNext Q)
{
	Q->front = Q->rear=0;
}
int IsEmpty(SCQNext Q)
{
	if (Q->front == Q->rear && Q->flag == 0)
		return 1;
	else return 0;
}
int RuiQueue(SCQNext Q,int x)
{
	if (Q->front == Q->rear && Q->flag == 1)
		return 0;
	else
	{
		if (x == 0) return 0;
		Q->AQueue[Q->rear] = x;
		Q->rear = (Q->rear + 1) % QueueSize;
		Q->flag = 1;
		return 1;
	}
}
int ChuQueue(SCQNext Q, int* e)
{
	if (Q->front == Q->rear && Q->flag == 0)
		return 0;
	else
	{
		*e = Q->AQueue[Q->front];
		Q->front= (Q->front + 1) % QueueSize;
		Q->flag = 0;
		return 1;
	}
}
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
}
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
