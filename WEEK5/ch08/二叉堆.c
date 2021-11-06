#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )
#define MinPQSize 11
#define MinData 0
struct HeapStruct;
typedef struct HeapStruct* PriorityQueue;
PriorityQueue Initialize(int maxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(int x, PriorityQueue H);
int DeleteMin(PriorityQueue H);
int FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue pqueue);
struct HeapStruct
{
    int Capacity;
    int Size;
    int* Elements;
};
PriorityQueue Initialize(int maxElements)
{
    PriorityQueue H;
    if (maxElements < MinPQSize)
    {
        FatalError("Priority queue size is too small");
    }

    H = malloc(sizeof(struct HeapStruct));
    if (H == NULL)
        FatalError("Out of space");
    H->Elements = malloc((maxElements + 1) * sizeof(int));
    if (H->Elements == NULL)
        FatalError("Out of space");
    H->Size = 0;
    H->Capacity = maxElements;
    H->Elements[0] = MinData;

    return H;
}
void Insert(int x, PriorityQueue H)
{
    int i;
    if (isFull(H))
    {
        FatalError("Priority queue is full");
        return;
    }
    for (i = ++H->Size; H->Elements[i / 2] > x; i /= 2)
        H->Elements[i] = H->Elements[i / 2];
    H->Elements[i] = x;
}
int deleteMin(PriorityQueue H)
{
    int i, Child;
    int MinElement, LastElement;
    if (isEmpty(H))
    {
        FatalError("Priority queue is empty");
        return H->Elements[0];
    }
    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size--];
    for (i = 1; i * 2 <= H->Size; i = Child)
    {
        Child = i * 2;
        if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child])
            Child++;
        if (LastElement > H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else
            break;
    }
    H->Elements[i] = LastElement;
    return MinElement;
}
void printHeap(PriorityQueue H) {
    int i;
    if (!isEmpty(H)) {
        for (i = 1; i <= H->Size; i++)
            printf("%d\t", H->Elements[i]);
        printf("\n");
    }
}
int isEmpty(PriorityQueue H) 
{

    return H->Size == 0;
}

int isFull(PriorityQueue H)
{
    return H->Size == H->Capacity;
}
int main() 
{
    printf("初始化二叉堆：");
    PriorityQueue H = Initialize(11);
    if (isEmpty(H))
        printf("H empty\n");
    printf("请用插入函数来建立二叉堆：");
    int key;
    for (int i = 0; i <= 10; i++)
    {
        scanf_s("%d", &key);
        Insert(key, H);
    }
    printf("建立好的二叉堆为：\n");
    printHeap(H);
    printf("执行删除最小元素后的二叉堆为：\n");
    deleteMin(H);
    printHeap(H);

}
