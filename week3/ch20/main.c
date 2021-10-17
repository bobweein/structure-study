#include <stdio.h>
#include <stdlib.h>
int main()
{
	void check(int* p);
	int* p1, i;
	p1 = (int*)malloc(5 * sizeof(int));//p1=malloc(5*sizeof(int ));
	for (i = 0; i < 5; i++)
		scanf_s("%d", p1 + i);
	check(p1);
	return 0;

}
void check(int* p)
{
	int i;
	printf("他们不及格：");
	for (i = 0; i < 5; i++)
		if (*(p + i) < 60) printf("%d  ", *(p + i));
	//for (i=0;i<5;i++)
	//if (p[i] < 60) printf("%d",p[i]);用下标的形式使用指针变量p
	printf("\n");
}
