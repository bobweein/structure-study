#include <stdio.h>
int main()
{
	int a[3][4] = { 1,3,5,7,9,11,13,15,17,19,21,23 };
	int n;
	printf("请从0，1，2这三个数中任选一个\n");
	scanf_s("%d", &n);
	int(*p)[4];
	p = a+n;
	printf("\n");
	for (int i = 0; i <= 3; i++)
		printf("%d ", *(*p + i));
	printf("\n");
	int* p1;
	p1 = *(a + n);
	int m = *(a + n) + 3;
	for ( p1=*(a+n);p1<=m;p1++)
		printf("%d ", *p1);
	printf("\n");
	return 0;
	
}
