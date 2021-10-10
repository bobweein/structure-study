#include <stdio.h>
int main()
{
	int fan(int x);
	int n;
	scanf_s("%d", &n);
	printf("n的阶乘为：%d\n", fan(n));
	return 0;

}
int fan(int x)
{
	int sum = 0;
	if (x == 0 || x == 1)  sum = 1;
	else sum = x * fan(x - 1);
	return sum;
}
