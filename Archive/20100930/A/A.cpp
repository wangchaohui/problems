#include <stdio.h>

int d[10];

int main()
{
	int T,i;
	scanf("%d",&T);
	puts("Lumberjacks:");
	while(T--)
	{
		for(i=0;i<10;i++)scanf("%d",&d[i]);
		for(i=1;i<10;i++)if(d[i-1]>d[i])break;
		if(i<10)
		{
			for(i=1;i<10;i++)if(d[i-1]<d[i])break;
		}
		if(i<10)puts("Unordered");
		else puts("Ordered");
	}
	return 0;
}