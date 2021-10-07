#include <stdio.h>
int main()
{
	int m1, m2, m3, sum;
	int i;
	m1 = 1;
	m2 = 1;
	sum = 0;
	for (i = 1; i <= 38; i++)
	{
		m3 = m1 + m2;
		sum = sum + m3;
		printf("第%d个月有%d只兔子\n", i + 2, m3);
		m1 = m2;
		m2 = m3;

	}
	printf("sum=%d", sum);
	return 0;
}
