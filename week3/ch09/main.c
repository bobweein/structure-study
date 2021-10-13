#include <stdio.h>
int main()
{
	void paixu(int* p, int n);
	int a[10];
	for (int i = 0; i <= 9; i++)
		scanf_s("%d", a + i, 4);
	int *pointer = a;
	paixu(pointer, 10);
	for (int i=0;i<=9;i++)
	printf("%d  ", *(pointer+i));
	return 0;
}
void paixu(int* p, int n)
{
	int i, j;
	for (i=n-1;i>=0;i--)
		for (j = 0 ; j <= i-1; j++)
		{
			if (*(p + j) < *(p + j + 1))
			{
				int t;
				t = *(p + j + 1);
				*(p + j + 1) = *(p + j);
				*(p + j) = t;
			}
		}
}
