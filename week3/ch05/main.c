#include<stdio.h>
int main()
{
	int max_gys(int x, int y);
	int min_gbs(int x, int y);
	int a, b;
	scanf_s("%d%d", &a, &b);
	printf("最大公约数为：%d\n", max_gys(a, b));
	printf("最小公倍数为：%d\n", min_gbs(a, b));
	return 0;
}
int max_gys(int x, int y)
{
	int m,n,r=1;
	if (x > y) 
	{ m = x;
	n = y;
	}
	else
	{
		m = y;
		n = x;
	}
	while (r != 0)
	{
		r = m % n;
		if (r == 0) return n;
		else
		{
			m = n;
			n = r;
		}
	}

}
int min_gbs(int x, int y)
{
	int m;
	m = x * y / max_gys(x,y);
	return m;
}
