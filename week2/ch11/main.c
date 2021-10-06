#include<stdio.h>
#include<math.h>
int main()
{
	int  m, zh;
	int i = 0;
	scanf_s("%d", &zh);
	m = zh;
	while (m > 0)
	{
		m = m / 10;
		i++;
	}
	printf("这个整数有%d位数\n", i);
	int  A[4];
	int j = i-1;
	int z=0;
	printf("这个整数中的数字从最高位到最低位依次为：");
	while (j >=0)
	{
		
		A[z] = zh /pow(10, j);
		zh = zh - (int)(zh / pow(10, j)) * pow(10, j);
		printf("%d  ", A[z]);
		z++;
		j--;
	}
	z = i - 1;
	while (z>=0)
	{
		printf("%d", A[z]);
		z--;
	}
	return 0;


}
