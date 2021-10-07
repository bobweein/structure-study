#include<stdio.h>
#include<math.h>
int main()
{
	float j, i;
	j = -1;
	double sum;
	sum = 0;
	for (i = 1; i <= 100000000000000000; i = i + 2)
	{
		j = -j;
		sum = sum + (j * 1 / i);
		if (fabs(1 / i) < 1e-6)   break;
	}
	printf("圆周率的四分之一约等于：%lf", sum);
	return 0;
}
