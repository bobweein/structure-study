#include <stdio.h>
int main()
{
	void fanxu(int *fan, int n);
	int a[11] = {0,1,2,3,4,5,6,7,8,9,10};
	int* p = a;
	fanxu(p, 11);
	for (p = a; p < (a + 11); p++)
		printf("%d  ", *p);
	return 0;
}
void fanxu(int *fan, int n)
{
	/*int j = n - 1;
	int arry[11] = { 0 };
	int* pa=arry;
	int t;
	for (int i = 0, j = n - 1; i <= n - 1; i++, j--)
		*(pa+j) = *(fan+i);
	for (int i = 0; i <= n-1; i++)
		*(fan + i) = *(pa + i);
        */
	int temp, i, j, m = (n - 1) / 2;
	for (i = 0; i <= m; i++)
	{
		j = n - 1 - i;
		temp = *(fan + i);
		*(fan + i) = *(fan + j);
		*(fan + j) = temp;
	}
}
