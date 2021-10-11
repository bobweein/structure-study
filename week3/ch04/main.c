//阶乘的另外一种算法!!!!
#include <stdio.h>
int main()
{
	int fac(int n);
	int i;
	for (i = 1; i <= 5; i++)
		printf("%d!=%d\n", i, fac(i));
	return 0;
}
int fac(int n)
{
	static int f = 1;
	printf("f当前的值为：%d     ", f);
	f = f * n;
	return (f);
}
