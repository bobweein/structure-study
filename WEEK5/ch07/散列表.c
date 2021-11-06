#include <stdio.h>
#include<stdlib.h>
#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12//哈希表的长度
#define NULLKEY -32768
typedef struct
{
	int* elem;//为建立动态数组做准备
	int count;//元素个数，这个起没有太大的作用
}HashTable;
int m = 0;//全局变量，hash表的长度
//初始化hash表
int InitHashTable(HashTable* H)
{
	int i;
	m = HASHSIZE;
	H->count = m;
	H->elem = (int*)malloc(m * sizeof(int));
	for (i = 0; i < m; i++)
		H->elem[i] = NULLKEY;
	return 1;
}
//散列函数
int Hash(int key)
{
	return key % m;
}
//插入关键字进入散列
void InsertHash(HashTable* H, int key)
{
	int addr = Hash(key);
	//处理冲突！
	while (H->elem[addr] != NULLKEY)
		addr = (addr + 1) % m;
	H->elem[addr] = key;
}
//散列表查找元素
int SearchHash(HashTable H, int key, int addr)
{
	
	addr= Hash(key);
	
	while (H.elem[addr] != key)
	{
		addr = (addr + 1) % m;
		if (H.elem[addr] == NULLKEY || addr == Hash(key))
		{
			printf("这个元素不在表中!\n");
			return UNSUCCESS;
		}
	}
	printf("这个元素在HASH表中！\n");
	return SUCCESS;
}
void PrintHash(HashTable H)
{
	for (int i = 0; i < HASHSIZE; i++)
		printf("%4d", H.elem[i]);
}
int main()
{
	HashTable H;
	InitHashTable(&H);
	printf("请输入元素；\n");
	int key;
	for (int i = 0; i < HASHSIZE; i++)
	{
		scanf_s("%d", &key);
		InsertHash(&H, key);
	}
	printf("hash 表中的元素为：\n");
	PrintHash(H);
	printf("\n请输入要搜索的元素:");
	int addr=0 ;
	scanf_s("%d", &key);
	SearchHash(H, key, addr);
	return 0;
}
