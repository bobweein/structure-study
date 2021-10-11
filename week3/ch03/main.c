//输入十个数，要求输出其中之最大的元素和该数是第几个数。
#include <stdio.h>

int main()
{
	int i, m, n, a[10];
	int max(int x, int y);
	n = 0;
	m = a[0];
	for (i = 0; i <= 9; i++)
		scanf_s("%d", &a[i],4);
	
	for (i = 0; i < 10; i++)
	{
		if (max(m, a[i]) > m)
		{
			m = max(m, a[i]);
			n = i;
		}
	}
	printf("%d     %d\n", m, n + 1);
	return 0;
}
int max(int x, int y)
{
	return x > y ? x : y;
}
