#include<stdio.h>
int main ()
{
  int i,j;
  int a[10];
  for (i=0;i<=9;i++)
  scanf ("%d",&a[i]);
  for (j=0;j<=9;j++)
	  for (i=0;i<=8-j;i++)
	  {
		  if (a[i]>a[i+1]) 
		  {
		  
			  int t;
			  t=a[i+1];
			  a[i+1]=a[i];
			  a[i]=t;
		  }
	  }
	  for(i=0;i<=9;i++)
	  printf("%d  ",a[i]);
	  return 0;
}
