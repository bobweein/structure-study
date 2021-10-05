#include<stdio.h>
int main()
{
	double p, w;
	int c, s;
	double d, f;
	scanf_s("%lf%lf%d", &p, &w, &s);
	if (s >= 3000)  c = 12;
	else c = s / 250;
	d = 0.00;
	switch (c)
	{
	case 0: d = 0.0; break;
	case 1:d = 0.02; break;
	case 2:d = 0.05; break;
	case 3: d = 0.05; break;
	case 4:d = 0.08; break;
	case 5:d = 0.08; break;
	case 6:d = 0.08; break;
	case 7: d = 0.08; break;
	case 8:d = 0.10; break;
	case 9:d = 0.10; break;
	case 10: d = 0.10; break;
	case 11: d = 0.10; break;
	case 12: d = 0.15; break;
	}
	f = p * w * s * (1 - d);
	printf("需要%16.4lf元\n", f);
	return 0;
}
