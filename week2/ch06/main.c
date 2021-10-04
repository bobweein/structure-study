#include<stdio.h>
int main()
{
	int year;
	scanf_s("%d", &year);
	if (year % 4 ==0)
		if (year % 100 == 0)
			if (year % 400 ==0)
				printf("%d年是闰年\n", year);
			else
				printf("%d年不是闰年\n", year);
		else
			printf("%d年是闰年\n", year);
	else
		printf("%d年不是闰年\n", year);
	return 0;
}
