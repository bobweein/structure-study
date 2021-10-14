#include<stdio.h>

int main()
{
	void copy(char* po1,char*po2);	

	char a[21];
	char b[21];
	printf("请输入小于等于20字节的字符串\n");
	int i;
	printf("输入的数组a[i]为：");
	for (i = 0; i <= 20;i++)
	{
		scanf_s("%c", &a[i], 1);
		int c = a[i];
		if (c == '\n')
		{
			a[i] = '\0';
		break;
		}
	}
	printf("输入的数组b[i]为：");
	for (i = 0; i <= 20; i++)
	{
		scanf_s("%c", &b[i], 1);
		int c = b[i];
		if (c == '\n')
		{
			b[i] = '\0';
			break;
		}
	}
	
	char* p1 = a;
	char* p2 = b;
	printf("把字符数组b[i]中的字符放到数组a[i]中去 ，如果a[i]数组长度不够则把一部分字符放在其中。\n");
	copy(p1, p2);
	printf("复制后数组为:\n");
	for (p1 = a; *p1!='\0'; p1++)
		printf("%c", *p1);
	return 0;
}
void copy(char* po1, char* po2)
{
	
	for (; *po1!='\0'&&*po2!='\0'; po1++,po2++)
		*po1 =* po2 ;
	*po1 = '\0';
}
