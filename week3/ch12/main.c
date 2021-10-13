#include <stdio.h>
int main()
{
	void search(int(* p)[4], int n,int m);
	int score[3][4] = { 65,57,70,60,58,87,90,81,90,99,100,98 };
	int(*pointer)[4];
	pointer = score;
	search(pointer, 3,4);
	return 0;
}
void search(int(* p)[4], int n,int m)
{
	int a[3];
	for (int i=0;i<=n-1;i++)
		for (int j = 0; j <= m-1; j++)
		{
			if (*(*(p + i) + j) < 60)
			{
				printf("第%d个同学有不及格的科目\n", i + 1);
				a[i] = 1;
				
			}
			if (a[i]==1) break;
			
		}
	int t = 2;
	for (int i = 0; i <= n - 1; i++)
	{
		t = a[i];
		if (t == 1)
		{
			for (int j = 0; j <= m - 1; j++)
				printf("%d ", *(*(p + i) + j));
			printf("\n");
		}
		
	}
}
