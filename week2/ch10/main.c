#include<stdio.h>
int main()
{
	float hanshu1(float), hanshu2(float);
	float hanshu3(float);
	float x, y;
	y = 0;
	printf("请输入自变量的值：");
	scanf_s("%f", &x);
	int c;
	if (x < 1)
		c = 1;
	else
		if (x < 10)
			c = 2;
		else  c = 3;
	printf("这个函数的值为;");
	switch (c)
	{
	case 1:hanshu1(x); break;
	case 2:hanshu2(x); break;
	case 3:hanshu3(x); break;
	default:putchar('\a');
	}
	
	return 0;
}
float hanshu1(float x)
{ 
	float y;
	y = x;
	printf("%f\n", y);
	return y;

}
float hanshu2(float x)
{
	float y;
	y = 2 * x - 1;
	printf("%f\n", y);
	return y;

}
float hanshu3(float x)
{
	float y;
	y = 3 * x - 11;
	printf("%f\n", y);
	return y;

}
