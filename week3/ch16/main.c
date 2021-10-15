#include <stdio.h>
int main()
{
	int fun(int x, int y, int (*p)(int, int));
	int max(int, int);
	int min(int, int);
	
	int a = 34, b = -21, n;
	printf("please chooose 1,2:");
	scanf_s("%d", &n);
	if (n == 1) fun(a, b, max);
	else
		if (n == 2) fun(a, b, min);
		
	return 0;
}
int fun(int x, int y, int (*p)(int, int))
{
	int result;
	result = (*p)(x, y);
	printf("%d\n", result);
}
int max(int x, int y)
{
	int z; if (x > y) z = x;
	else z = y;
	printf("max=");
	return z;
}
int min(int x, int y)
{
	int z; if (x < y) z = x;
	else z = y;
	printf("min=");
	return z;
}
