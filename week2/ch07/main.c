#include <stdio.h>
#include<math.h>
int main()
{
	double a, b, c, x1, x2, disc;

	scanf_s("%lf%lf%lf", &a, &b, &c);
	printf("这个方程");
	if (fabs(a) <= 1e-6)
		printf("不是一元二次方程。\n");
	else
	{
		disc = b * b - 4 * a * c;
		x1 = (-b + sqrt(disc)) / (2 * a);
		x2 = (-b - sqrt(disc)) / (2 * a);
		if (disc > 0)
		{

			printf("有两个实根:\n%8.4lfn\n%8.4lf\n", x1, x2);

		}
		else
			if (fabs(disc) <= 1e-6)
				printf("有两个相同的实根:x1=x2\n%8.4lf\n", x1);
			else

			{
				printf("有两个复根：\n%8.4lf+%8.4lfi\n", -b / (2 * a), sqrt(-disc) / (2 * a));
				printf("%8.4lf-%8.4lfi\n", -b / (2 * a), sqrt(-disc) / (2 * a));
			}
	}
	return 0;
}
