#include<stdio.h>
int main()
{
	int a, b;
	float x, y;
	char c1, c2;
	scanf_s("a=%d b=%d", &a, &b);
	scanf_s("%f %e", &x, &y);
	scanf_s("%c%c", &c1,1, &c2,1);
	//printf("a=%d,b=%d,x=%f,y=%f\n", a, b,x,y);
	printf("a=%d,b=%d,x=%f,y=%f,c1=%c,c2=%c\n", a, b, x, y,c1,c2);
	return 0;
}
//FAXIANQIKUAIDEDIFANG 
