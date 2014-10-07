#include <stdio.h>

char Name[1000];
char Age[1000];

double d[10000];

int main()
{
	int n,i,f=0,a6,a10,j;
	freopen("in.txt","r",stdin);
	while(scanf(" %[^*]* %[^*]* %lf",Name,Age,&d[0])==3)
	{
		if(f)puts("---");else f=1;
		puts(Name);puts(Age);
		n=1;
		while(scanf(" ,%lf",&d[n])==1)n++;
		for(i=0;i<n;i++)if(d[i]>35)break;
		if(i!=n)
		{
			puts("Triage PASS");
		}
		a6=a10=0;
		for(i=0;i<n-6;i++)
		{
			for(j=i;j<i+6;j++)if(d[j]<0)break;
			if(j==i+6){a6=1;break;}
		}
		for(i=0;i<n-11;i++)
		{
			for(j=i;j<i+10;j++)if(d[j]<0)break;
			if(j==i+11){a10=1;break;}
		}
		if(a6 && !a10)puts("Triage NO PASS");
		else puts("Triage PASS");
	}
	return 0;
}