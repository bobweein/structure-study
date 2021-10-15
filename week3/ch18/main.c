#include <stdio.h>
#include <string.h>
int main()
{
	void sert (char *name[], int n);
	void print(char* name[], int n);
	char* arr[5] = { "Learn to play the guitar","Basic","Follow me","Good food","How to eat health" };
	int n = 5;
	sert(arr, n);
	print(arr, n);
	return 0;
}
void sert(char* name[], int n)
{
	int i, j, exc;
	for (i=0;i<=3;i++)
		for (j = 0; j <= 3 - i; j++)
		{
			if (strcmp(name[j], name[j+ 1]) > 0)
			{
				exc = name[j];
				name[j ] = name[j+1];
				name[j+1] = exc;
			}
		}

}
void print(char* name[], int n)
{
	for (int i = 0; i <= n - 1; i++)
		printf("%s\n", name[i]);
}
