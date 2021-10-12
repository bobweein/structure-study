#include <stdio.h>
int main()
{
	int a=1000, b=999;
	int* pointer_1, * pointer_2,*t;
	pointer_1=&a;
	pointer_2 = &b;
	t = pointer_1;
	pointer_1 = pointer_2;
	pointer_2 = t;
	//t = *pointer_1;
	//*pointer_1 = *pointer_2; 
	//*pointer_2 = t;
	printf("%d,%d\n", *pointer_1, *pointer_2);
	printf("%d,%d", a, b);
	return 0;
	
}
