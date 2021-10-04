#include <stdio.h>
int main()
{
	float x, y;
	scanf_s("%f", &x);
	if (x >= 0)
		if (x > 0)
			y = 1;
		else
			y = 0;
	else
		y = -1;
	printf("%f", y);
	return 0;
}
