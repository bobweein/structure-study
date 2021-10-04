#include <stdio.h>
char ch='a';
int main()
{
	
	scanf_s("%c",&ch,1);
	if (ch > 'A' && ch < 'Z')
		printf("这个字母是大写的！变为小写为：%c\n", ch+32);
		
	else
		printf("这个字母是小写！不转换。");
	return 0;

}
