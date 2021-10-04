#include <stdio.h>
int  main()
{
	char ch;
	int a = 15, b = 23;
	ch = getchar();
	switch (ch)
	{
	case'a':
	case'A':printf("%d\n", a + b); break;
	case'b':
	case'B':printf("%d\n", a * b); break;
	defult:putchar('\a');
	}
	return 0;
}
