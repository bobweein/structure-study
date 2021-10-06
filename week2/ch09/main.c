#include<stdio.h>
#include<math.h>
int main()
{
	int  ans, num;
	scanf_s("%d", &num);
	if (num <= 1000)
		printf("请输出他平方根的整数部分：");
	else
	{
		printf("请重新输入一个符合规定的整数：");
		scanf_s("%d", &num);
	}
	ans = sqrt(num);
	printf("%d\n", ans);
	return 0;


}
