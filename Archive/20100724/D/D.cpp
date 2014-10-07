#include <stdio.h>

int main()
{
	int T;
	double a,b,c;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf %lf %lf",&a,&b,&c);
		if((a*b-a-b)*(a*c-a-c)*(b*c-b-c)>a*b*c)
		{
			puts("Aha");
		}
		else
		{
			puts("No way");
		}
	}
	return 0;
}