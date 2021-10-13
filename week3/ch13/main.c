#include<stdio.h>
#include <string.h>
int main()
{
	void copy(char* po1,char*po2);	
	//char a[] = "I love to be freedon";
	char a[] = "aaaab";
	char b[] = "ohmy gad!";
	char* p1 = a;
	char* p2 = b;
	copy(p1, p2);
	for (p1 = a; p1 <= a + strlen(p2)&&p1<=a+strlen(p1); p1++)
		printf("%c", *p1);
	return 0;
}
void copy(char* po1, char* po2)
{
	for (int i = 0; i<=strlen(po1)-1&& i <= strlen(po2); i++)
	{
		*(po1 + i )=* (po2 + i);
		/*if (*(po2 + i) == '\0')
		{ 
			*(po1 + i+1) = '\0';
			break;
		}*/
	}
}
