#include <stdio.h>
int main()
{
	int a[3][4] = { 1,3,5,7,9,11,13,15,17,19,21,23 };
	int(* p)[4] ;
	//int* p;

	p = a;
	for (int j=0; j<=2; j++)
	{
		for (int i = 0; i <= 3; i++)
			printf("%d  ",  *(*(p+j) + i));
		//printf("%d  ", *(p + j) );
	}
	printf("\n");
	return 0;
}
