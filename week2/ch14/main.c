#include<stdio.h>
int main()
{
	int i = 1;
	char c;
	c = 'a';
	while((c=getchar())!='\n')
	{
	if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
			if (c >= 'A' && c < 'W' || c >= 'a' && c < 'w')
				c = c + 4;
			else  c = c - 22;
	printf("%c", c);
	}
	
	return 0;
	
}
