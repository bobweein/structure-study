#include <stdio.h>
int main()
{
	int a[3][4] = { 1,2,3,55,777,0,12,36,15,18,19,555 };
	int i, j;
	int max = a[0][0];
    for (i=0;i<=2;i++)
		for (j = 0; j <= 3; j++)
		{
			if (a[i][j] > max) max = a[i][j];
		}
	printf("%d", max);
	return 0;
}//找出3*4的矩阵中的最大值，（打擂台算法）
