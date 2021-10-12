#include <stdio.h>
int main()
{
	void paixu(int *p1, int *p2);
	void paixu1(int x, int y);
	int a = 599, b = 564;
	int* pointer_1, * pointer_2;
	pointer_1 = &a;
	pointer_2 = &b;
	/*printf("%o,%o", &a, &b);*/
	paixu( pointer_1,  pointer_2);
	printf("%d  %d\n",a,b);
	printf("%o,%o", &a, &b);
	printf("\n");
	printf("%d,%d",*pointer_1, *pointer_2);
	printf("\n");
	printf("%o  %o", pointer_1, pointer_2);
	/*paixu1(a, b);
	printf("%d,%d", a, b);
	return 0;*/

}
void paixu(int *p1, int *p2)
{
	int t;
	 t = *p1;
	*p1 = *p2;
	*p2 = t;
	/*int* t;
	t = p1; 
	p1 = p2;
	p2 = t;*/

}
//void paixu1(int x, int y)
//{
//	int temp;
//	temp = x;
//	x = y;
//	y = temp;
//}
