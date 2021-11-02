#include <stdio.h>
typedef  int ElementType;
shellsort(ElementType A[], int N)
{
	int i, j, increment;
	ElementType Tmp;
	for (increment = N / 2; increment > 0; increment /= 2)
	{
		for (i = increment; i < N; i++)
		{
			Tmp = A[i];
			for (j = i; j >= increment; j -= increment)
				if (Tmp < A[j - increment])
					A[j] = A[j - increment];
				else break;
			A[j] = Tmp;
		}
		printf("本趟希尔排序后的数组：\n");
		for (int j = 0; j <N; j++)
			printf("%4d", A[j]);
		printf("\n");
	}
}
int main()
{
	int i;
	printf("请输入需要排序的数组：\n");
	ElementType A[20];
	for (i = 0; i < 20; i++)
	{
		scanf_s("%d", &A[i]);
		if (A[i] == 0) break;
	}
	shellsort(A, i);
	
	return 0;

}
