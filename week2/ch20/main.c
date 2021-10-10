#include<stdio.h>
int main()
{
	int max4(int a, int s, int d, int f);
	int max2(int x, int y);
	int a1, a2, a3, a4;
	scanf_s("%d%d%d%d", &a1, &a2, &a3, &a4);
	printf("四个数中的最大值为：%d\n", max4(a1, a2, a3, a4));
	return 0;
	
}
int max4(int a, int s, int d, int f)
{ 
	int m;
	if (a > s) m = a;
	else m = s;
	if (d > m) m = d;
	if (f > m) m = f;
	return m;


}
int max2(int x, int y)
{
	if (x > y) 
		return x;
	else
		return y;
}
