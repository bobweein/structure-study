#include <stdio.h>
#include <stdlib.h>
int main()
{
	void shuru(int *po, int n);
	void chuli(int *po, int n);
	void dayin(int *po, int n);
	int* p;
	p = malloc(10 * sizeof(int));
	shuru(p, 10);
	chuli(p, 10);
	dayin(p, 10);
	return 0;
}
void shuru(int* po,int n)
{
	int i;

	for (i = 0; i <= n - 1; i++)
		scanf_s("%d", po + i, 4);
	printf("\n");
}
void chuli(int* po, int n)
{
	int i;
	int temp;
	int* max=po+9;
	int* min=po; 
	for (i = 0; i <= n - 2; i++)
	{
		
		if (*(po + i) > *(po + 9))
		{
			temp = *(po + i);
			*(po + i) = *max;
			*max = temp;
		}
		
	}
	for (int j = n - 2; j >= 1; j--)
	{
		if (*(po + j) < *po)
		{
			temp = *(po+j);
			*(po+j) = *min;
			*min = temp;
		}
	}

			

}
void dayin(int* po, int n)
{
	for (int i = 0; i <= n - 1; i++)
		printf("%d  ", *(po + i));
}
