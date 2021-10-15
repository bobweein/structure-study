#include <stdio.h>
int main()
{
	float* search(float(* pointer)[4], int n);
	float* p;
	int i, k;
	float score[][4] = { 60,70,80,90,56,89,67,88,34,78,90,66 };
	for (k = 0; k <= 2; k++)
	{
		p=search(score, k);
		for (i = 0; i <= 3; i++)
		{
			if (*(p + i) < 60)
			{
				printf("序号为%d的同学有不及格的科目", k);
				for (int j=0;j<=3;j++)
				printf("%f  ", *(p + j));
				printf("\n");

			}
		}
	}
	return 0;
}
float *search(float(* pointer)[4], int n)
{
	float* pt;
	pt = *(pointer + n);
	return(pt);
}
//注意指向float一维数组的指针定义形式时（*pointer）[4],记得留意括号，
//还需注意的地方是指向函数的指针和（*search)(float ,int )也要记得留意（*search）这一部分的括号
//如果要定义返回指针值的函数，则不需要括号，即*serach(float ,int );因为（）的优先级比*高
