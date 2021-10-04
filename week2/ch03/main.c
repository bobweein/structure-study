#include<stdio.h>
int main()
{
	float x, y;
	scanf_s("%f", &x);
	if (x < 0)
		y = -1;
	else
		if (x > 0)
			y = 1;
		else
			y = 0;
	printf("%f\n", y);
	return 0;
}
