#include <stdio.h>
int main()
{
	int a[2][3] = { 1,2,3,4,5,6 };
	int b[3][2] = { 4,1,5,2,6,3 };
	int i = 0;
	int j = 0;
	int t ;
	for (i = 0; i <= 1; i++)
	{
		for (j = 0; j <= 2; j++)
		{
			t = a[i][j];
			a[i][j] = b[j][i];
			b[j][i] = t;
		}
	}
	for (i = 0; i <= 1; i++)
	{
		for (j = 0; j <= 2; j++)
		{
			printf("%d  ", a[i][j]);
			if (j == 2)printf("\n");
		}
	}
	printf("\n");
		for (j = 0; j <= 2; j++)
		{   
			for (i = 0; i <= 1; i++)
			{
				printf("%d  ", b[j][i]);
				if (i == 1) printf("\n");
			}
			
		}
	
	return 0;
}
